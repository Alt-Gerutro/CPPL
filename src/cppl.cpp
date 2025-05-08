#include <iostream>
#include <fstream>
#include <cppl.hpp>

using namespace std;

cpair level_names[] = {
    {"FATAL", CPPL_FATAL},
    {"ALERT", CPPL_ALERT},
    {"CRIT", CPPL_CRIT},
    {"ERR", CPPL_ERR},
    {"WARN", CPPL_WARN},
    {"NOTICE", CPPL_NOTICE},
    {"INFO", CPPL_INFO},
    {"DEBUG", CPPL_DEBUG},
    {"UNDEF", CPPL_UNDEFINED}
};

class Formatting {
    public:
    static string format_string(const string &format, vector<pair <string, string>> &replacements) {
        string out = format;
        for (const auto &repl : replacements) {
            const string &target = repl.first;
            const string &value = repl.second;
            size_t pos = 0;
            while (true) {
                pos = out.find(target, pos);
                if (pos == string::npos) break;
                out.replace(pos, target.length(), value);
                pos += value.length();
            }
        }
        return out;
    }
};

Logger::Logger(const string format, string name) 
    : format(format), name(name) {}

Logger::Logger(const std::string format, std::string name, std::string log_file)
    : format(format), name(name), log_file(log_file) {
        is_file_logging = true;
    }

Logger::~Logger() {
    if (is_file_logging) log_file.close();
    if (log_file.is_open()) log_file.close();
}

void Logger::preplog(int level, int line, int col, const string &filename, const string &funcname, const string &msg) {
    if (level < 0 || line < 0 || col < 0) {
        invalid_argument("Invalid argument(level || line || col)");
        throw 1;
    }

    vector<pair<string, string>> replacements;
    replacements.push_back({"_FILE_", filename});
    replacements.push_back({"_LINE_", to_string(line)});
    replacements.push_back({"_COL_", to_string(col)});
    replacements.push_back({"_FUNC_", funcname});
    replacements.push_back({"_LOGGER_", name});
    replacements.push_back({"_LEVEL_", level_names[level].name});
    replacements.push_back({"_MSG_", msg});
    log_string = Formatting::format_string(format, replacements);
    
}

void Logger::log(int level, const string msg, const source_location &loc) {
    preplog(level, loc.line(), loc.column(), loc.file_name(), loc.function_name(), msg);
    if(is_file_logging) {
        
    } else {
        cout << log_string << endl;
    }
}

void Logger::log(int level, const string msg, string filename, const source_location &loc) {
    
    if (!log_file.is_open()) {
        cerr << "Error opening file" << endl;
        throw 1;
    }
    preplog(level, loc.line(), loc.column(), loc.file_name(), loc.function_name(), msg);

    log_file << log_string << endl;

    if (!is_file_logging) {
        log_file.close();
    }
}
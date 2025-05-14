#include <ios>
#include <iostream>
#include <fstream>
#include <vector>
#include <cppl.hpp>

using namespace std;

vector<string> level_names = {
    "FATAL",
    "ALERT",
    "CRIT",
    "ERR",
    "WARN",
    "NOTICE",
    "INFO",
    "DEBUG",
    "UNDEF"
};

/* Class for formatting string from template */
class Formatting {
public:
    static string format_string(const string &format, vector<pair <string, string>> &replacements) {
        string out = format;    // Out string
        for (const auto &repl : replacements) {
            const string &target = repl.first; // What needs to be replaced
            const string &value = repl.second; // To what it be replaced
            size_t pos = 0; // Position of cursor
            while (true) {
                pos = out.find(target, pos); // Overwrite position to what to be replaced
                if (pos == string::npos) break; // Break if string is ended
                out.replace(pos, target.length(), value); // Replace out string in position
                pos += value.length(); // Jump over replaced string
            }
        }
        return out;
    }
};

Logger::Logger(const string format, string name)
    : format(format), name(name) {}

Logger::Logger(const string format, string name, string log_file)
    : format(format), name(name) {
        log_file_stream.open(log_file, ios_base::app);
        is_file_logging = true;
    }

Logger::Logger(const string format, string name, int filter)
    : format(format), name(name), filter(filter) {}

Logger::Logger(const string format, string name, int filter, string log_file)
    : format(format), name(name), filter(filter) {
        log_file_stream.open(log_file, ios_base::app);
        is_file_logging = true;
    }

Logger::~Logger() {
    if (log_file_stream.is_open()) log_file_stream.close();
}

void Logger::preplog(int level, int line, int col, const string &filename, const string &funcname, const string &msg) {
    vector<pair<string, string>> replacements;
    replacements.push_back({"_FILE_", filename});
    replacements.push_back({"_LINE_", to_string(line)});
    replacements.push_back({"_COL_", to_string(col)});
    replacements.push_back({"_FUNC_", funcname});
    replacements.push_back({"_LOGGER_", name});
    replacements.push_back({"_LEVEL_", level_names[level]});
    replacements.push_back({"_MSG_", msg});
    log_string = Formatting::format_string(format, replacements);
}

void Logger::log(int level, const string msg, const string fmt, const source_location &loc) {
    if (level <= this->filter) {
        string old_fmt = "";
        if (!fmt.empty()) {
            string old_fmt = this->format;
            this->format = fmt;
        }
        preplog(level, loc.line(), loc.column(), loc.file_name(), loc.function_name(), msg);
        if (log_file_stream.is_open()) {
            this->log_file_stream << log_string << endl;
        } else {
            cout << log_string << endl;
        }

        if (!old_fmt.empty()) {
            this->format = old_fmt;
        }
    }
}

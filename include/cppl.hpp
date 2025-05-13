#ifndef _CPPL_H
#define _CPPL_H

#include <string>
#include <fstream>
#include <source_location>

class Logger {
private:
    std::string format;
    std::string name;
    std::string log_string;
    bool is_file_logging;
    std::ofstream log_file_stream;

    void preplog(int level, int line, int col, const std::string &filename, const std::string &funcname, const std::string &msg);

public:
    Logger(const std::string format, std::string name);
    Logger(const std::string format, std::string name, std::string log_file);

    ~Logger();

    void log(int level, const std::string msg, const std::source_location &loc = std::source_location::current());
};

enum cppl_level {
    CPPL_FATAL,
    CPPL_ALERT,
    CPPL_CRIT,
    CPPL_ERR,
    CPPL_WARN,
    CPPL_NOTICE,
    CPPL_INFO,
    CPPL_DEBUG,
    CPPL_UNDEFINED
};

#endif // _CPPL_H

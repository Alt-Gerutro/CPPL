#ifndef _CPPL_H
#define _CPPL_H

#include <string>
#include <vector>
#include <source_location>

class Logger {
private:
    std::string format;
    std::string name;
    std::string log_string;
    bool is_file_logging = false;
    std::ofstream log_file;
    void preplog(int level, int line, int col, const std::string &filename, const std::string &funcname, const std::string &msg);

public:
    Logger(const std::string format, std::string name);
    Logger(const std::string format, std::string name, std::string log_file);

    void log(int level, const std::string msg, const std::source_location &loc = std::source_location::current());
    void log(int level, const std::string msg, std::string filename, const std::source_location &loc = std::source_location::current());

    ~Logger();
};

typedef enum {
    CPPL_FATAL,
    CPPL_ALERT,
    CPPL_CRIT,
    CPPL_ERR,
    CPPL_WARN,
    CPPL_NOTICE,
    CPPL_INFO,
    CPPL_DEBUG,
    CPPL_UNDEFINED
} CPPL_Level_t;

extern struct cpair {
    std::string name;
    CPPL_Level_t value;
} level_names[];

#endif // _CPPL_H
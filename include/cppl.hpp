/*
Copyright (c) 2025 Maksim Dolgov(Gerutro, Alt-Gerutro)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. DEVELOPERS USING THIS CODE ARE RESPONSIBLE FOR THEIR OWN BUILD
PROCESSES.
*/

#ifndef _CPPL_H
#define _CPPL_H // v0.4.0

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
    int filter;
    void preplog(int level, int line, int col, const std::string &filename, const std::string &funcname, const std::string &msg);

public:
    Logger(const std::string format, std::string name);
    Logger(const std::string format, std::string name, std::string log_file);

    Logger(const std::string format, std::string name, int filter);
    Logger(const std::string format, std::string name, int filter, std::string log_file);

    ~Logger();

    void log(int level, const std::string msg, const std::string format = "", const std::source_location &loc = std::source_location::current());
};

enum cppl_level {
    // System is unusable. Immediate intervention required.
    // Example: Kernel panic, hardware failure in critical embedded system.
    CPPL_FATAL,

    // Action must be taken immediately (typically alerts for admins).
    // Example: Storage full, security breach detected.
    CPPL_ALERT,

    // Critical conditions, but application may continue (with degraded functionality).
    // Example: Primary database down, using backup.
    CPPL_CRIT,

    // Error conditions that should be investigated.
    // Example: Invalid user input, failed network request (retry possible).
    CPPL_ERR,

    // Warning about potentially harmful situations.
    // Example: Deprecated API usage, suspicious activity.
    CPPL_WARN,

    // Normal but significant events (positive confirmation logs).
    // Example: User login success, configuration loaded.
    CPPL_NOTICE,

    // Informational messages (normal operation).
    // Example: Service started, request received.
    CPPL_INFO,

    // Debug-level messages (development only).
    // Example: Variable values, function entry/exit.
    CPPL_DEBUG,

    // Undefined level (for parsing external logs or placeholders).
    CPPL_UNDEFINED
};

#endif // _CPPL_H

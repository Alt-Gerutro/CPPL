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
SOFTWARE.
*/

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

    void log(int level, const std::string msg, const std::string format = "", const std::source_location &loc = std::source_location::current());
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

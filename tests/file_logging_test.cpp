#include <cppl.hpp>
#include <string>

int main() {
    const std::string fmt = "[_LOGGER_] {_FILE_:_FUNC_:_LINE_:_COL_} _LEVEL_: _MSG_";
    Logger default_logger(fmt, "Default Logger", "file_test.log");

    default_logger.log(CPPL_FATAL, "fatal");
    default_logger.log(CPPL_ALERT, "alert");
    default_logger.log(CPPL_CRIT, "critical");
    default_logger.log(CPPL_ERR, "error");
    default_logger.log(CPPL_WARN, "warning");
    default_logger.log(CPPL_NOTICE, "notice");
    default_logger.log(CPPL_INFO, "info");
    default_logger.log(CPPL_DEBUG, "debug");
    default_logger.log(CPPL_UNDEFINED, "undefined");

    Logger format_logger(fmt, "Format Logger", "file_test.log");
    format_logger.log(CPPL_INFO, "Logger", "_MSG_: _LOGGER_");
    format_logger.log(CPPL_INFO, "File", "_MSG_: _FILE_");
    format_logger.log(CPPL_INFO, "Line", "_MSG_: _LINE_");
    format_logger.log(CPPL_INFO, "Column", "_MSG_: _COL_");
    format_logger.log(CPPL_INFO, "Function", "_MSG_: _FUNC_");
    format_logger.log(CPPL_INFO, "Level", "_MSG_: _LEVEL_");
    format_logger.log(CPPL_INFO, "Message", "_MSG_: _MSG_");

    Logger duplicate_format_macros_logger(fmt, "Duplicate format macros Logger", "file_test.log");
    duplicate_format_macros_logger.log(CPPL_INFO, "2 Levels in a row", "_LEVEL_, _LEVEL_");
    duplicate_format_macros_logger.log(CPPL_INFO, "2 Levels not in a row", "_LEVEL_ _MSG_, _MSG_, _LOGGER_ _LEVEL_");
    duplicate_format_macros_logger.log(CPPL_INFO, "MORE Levels in a row", "_LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_, _LEVEL_");

    return 0;
}

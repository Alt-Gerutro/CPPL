#include <cppl.hpp>
#include <string>

int main() {
    // Default test
    std::string format = "[_LOGGER_] {_FILE_:_FUNC_:_LINE_:_COL_} _LEVEL_: _MSG_";
    Logger default_logger(format, "Default Logger");

    default_logger.log(CPPL_FATAL, "fatal");
    default_logger.log(CPPL_ALERT, "alert");
    default_logger.log(CPPL_CRIT, "critical");
    default_logger.log(CPPL_ERR, "error");
    default_logger.log(CPPL_WARN, "warning");
    default_logger.log(CPPL_NOTICE, "notice");
    default_logger.log(CPPL_INFO, "info");
    default_logger.log(CPPL_DEBUG, "debug");
    default_logger.log(CPPL_UNDEFINED, "undefined");
}

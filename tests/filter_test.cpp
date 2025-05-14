#include <cppl.hpp>
#include <string>

void log_test() {
    std::string format = "[_LOGGER_] {_LEVEL_}";
    Logger logger1(format, "CPPL_UNDEFINED or above", CPPL_UNDEFINED);

    logger1.log(CPPL_FATAL, "");
    logger1.log(CPPL_ALERT, "");
    logger1.log(CPPL_CRIT, "");
    logger1.log(CPPL_ERR, "");
    logger1.log(CPPL_WARN, "");
    logger1.log(CPPL_NOTICE, "");
    logger1.log(CPPL_INFO, "");
    logger1.log(CPPL_DEBUG, "");
    logger1.log(CPPL_UNDEFINED, "");

    Logger logger2(format, "CPPL_DEBUG or above", CPPL_DEBUG);

    logger2.log(CPPL_FATAL, "");
    logger2.log(CPPL_ALERT, "");
    logger2.log(CPPL_CRIT, "");
    logger2.log(CPPL_ERR, "");
    logger2.log(CPPL_WARN, "");
    logger2.log(CPPL_NOTICE, "");
    logger2.log(CPPL_INFO, "");
    logger2.log(CPPL_DEBUG, "");
    logger2.log(CPPL_UNDEFINED, "");

    Logger logger3(format, "CPPL_INFO or above", CPPL_INFO);

    logger3.log(CPPL_FATAL, "");
    logger3.log(CPPL_ALERT, "");
    logger3.log(CPPL_CRIT, "");
    logger3.log(CPPL_ERR, "");
    logger3.log(CPPL_WARN, "");
    logger3.log(CPPL_NOTICE, "");
    logger3.log(CPPL_INFO, "");
    logger3.log(CPPL_DEBUG, "");
    logger3.log(CPPL_UNDEFINED, "");

    Logger logger4(format, "CPPL_NOTICE or above", CPPL_NOTICE);

    logger4.log(CPPL_FATAL, "");
    logger4.log(CPPL_ALERT, "");
    logger4.log(CPPL_CRIT, "");
    logger4.log(CPPL_ERR, "");
    logger4.log(CPPL_WARN, "");
    logger4.log(CPPL_NOTICE, "");
    logger4.log(CPPL_INFO, "");
    logger4.log(CPPL_DEBUG, "");
    logger4.log(CPPL_UNDEFINED, "");

    Logger logger5(format, "CPPL_WARN or above", CPPL_WARN);

    logger5.log(CPPL_FATAL, "");
    logger5.log(CPPL_ALERT, "");
    logger5.log(CPPL_CRIT, "");
    logger5.log(CPPL_ERR, "");
    logger5.log(CPPL_WARN, "");
    logger5.log(CPPL_NOTICE, "");
    logger5.log(CPPL_INFO, "");
    logger5.log(CPPL_DEBUG, "");
    logger5.log(CPPL_UNDEFINED, "");

    Logger logger6(format, "CPPL_ERR or above", CPPL_ERR);

    logger6.log(CPPL_FATAL, "");
    logger6.log(CPPL_ALERT, "");
    logger6.log(CPPL_CRIT, "");
    logger6.log(CPPL_ERR, "");
    logger6.log(CPPL_WARN, "");
    logger6.log(CPPL_NOTICE, "");
    logger6.log(CPPL_INFO, "");
    logger6.log(CPPL_DEBUG, "");
    logger6.log(CPPL_UNDEFINED, "");

    Logger logger7(format, "CPPL_CRIT or above", CPPL_CRIT);

    logger7.log(CPPL_FATAL, "");
    logger7.log(CPPL_ALERT, "");
    logger7.log(CPPL_CRIT, "");
    logger7.log(CPPL_ERR, "");
    logger7.log(CPPL_WARN, "");
    logger7.log(CPPL_NOTICE, "");
    logger7.log(CPPL_INFO, "");
    logger7.log(CPPL_DEBUG, "");
    logger7.log(CPPL_UNDEFINED, "");

    Logger logger8(format, "CPPL_ALERT or above", CPPL_ALERT);

    logger8.log(CPPL_FATAL, "");
    logger8.log(CPPL_ALERT, "");
    logger8.log(CPPL_CRIT, "");
    logger8.log(CPPL_ERR, "");
    logger8.log(CPPL_WARN, "");
    logger8.log(CPPL_NOTICE, "");
    logger8.log(CPPL_INFO, "");
    logger8.log(CPPL_DEBUG, "");
    logger8.log(CPPL_UNDEFINED, "");

    Logger logger9(format, "CPPL_FATAL only", CPPL_FATAL);

    logger9.log(CPPL_FATAL, "");
    logger9.log(CPPL_ALERT, "");
    logger9.log(CPPL_CRIT, "");
    logger9.log(CPPL_ERR, "");
    logger9.log(CPPL_WARN, "");
    logger9.log(CPPL_NOTICE, "");
    logger9.log(CPPL_INFO, "");
    logger9.log(CPPL_DEBUG, "");
    logger9.log(CPPL_UNDEFINED, "");
}

void log_to_file(std::string filename) {
    std::string format = "[_LOGGER_] {_LEVEL_}";

    Logger logger1(format, "CPPL_UNDEFINED or above", CPPL_UNDEFINED, filename);

    logger1.log(CPPL_FATAL, "");
    logger1.log(CPPL_ALERT, "");
    logger1.log(CPPL_CRIT, "");
    logger1.log(CPPL_ERR, "");
    logger1.log(CPPL_WARN, "");
    logger1.log(CPPL_NOTICE, "");
    logger1.log(CPPL_INFO, "");
    logger1.log(CPPL_DEBUG, "");
    logger1.log(CPPL_UNDEFINED, "");

    Logger logger2(format, "CPPL_DEBUG or above", CPPL_DEBUG, filename);

    logger2.log(CPPL_FATAL, "");
    logger2.log(CPPL_ALERT, "");
    logger2.log(CPPL_CRIT, "");
    logger2.log(CPPL_ERR, "");
    logger2.log(CPPL_WARN, "");
    logger2.log(CPPL_NOTICE, "");
    logger2.log(CPPL_INFO, "");
    logger2.log(CPPL_DEBUG, "");
    logger2.log(CPPL_UNDEFINED, "");

    Logger logger3(format, "CPPL_INFO or above", CPPL_INFO, filename);

    logger3.log(CPPL_FATAL, "");
    logger3.log(CPPL_ALERT, "");
    logger3.log(CPPL_CRIT, "");
    logger3.log(CPPL_ERR, "");
    logger3.log(CPPL_WARN, "");
    logger3.log(CPPL_NOTICE, "");
    logger3.log(CPPL_INFO, "");
    logger3.log(CPPL_DEBUG, "");
    logger3.log(CPPL_UNDEFINED, "");

    Logger logger4(format, "CPPL_NOTICE or above", CPPL_NOTICE, filename);

    logger4.log(CPPL_FATAL, "");
    logger4.log(CPPL_ALERT, "");
    logger4.log(CPPL_CRIT, "");
    logger4.log(CPPL_ERR, "");
    logger4.log(CPPL_WARN, "");
    logger4.log(CPPL_NOTICE, "");
    logger4.log(CPPL_INFO, "");
    logger4.log(CPPL_DEBUG, "");
    logger4.log(CPPL_UNDEFINED, "");

    Logger logger5(format, "CPPL_WARN or above", CPPL_WARN, filename);

    logger5.log(CPPL_FATAL, "");
    logger5.log(CPPL_ALERT, "");
    logger5.log(CPPL_CRIT, "");
    logger5.log(CPPL_ERR, "");
    logger5.log(CPPL_WARN, "");
    logger5.log(CPPL_NOTICE, "");
    logger5.log(CPPL_INFO, "");
    logger5.log(CPPL_DEBUG, "");
    logger5.log(CPPL_UNDEFINED, "");

    Logger logger6(format, "CPPL_ERR or above", CPPL_ERR, filename);

    logger6.log(CPPL_FATAL, "");
    logger6.log(CPPL_ALERT, "");
    logger6.log(CPPL_CRIT, "");
    logger6.log(CPPL_ERR, "");
    logger6.log(CPPL_WARN, "");
    logger6.log(CPPL_NOTICE, "");
    logger6.log(CPPL_INFO, "");
    logger6.log(CPPL_DEBUG, "");
    logger6.log(CPPL_UNDEFINED, "");

    Logger logger7(format, "CPPL_CRIT or above", CPPL_CRIT, filename);

    logger7.log(CPPL_FATAL, "");
    logger7.log(CPPL_ALERT, "");
    logger7.log(CPPL_CRIT, "");
    logger7.log(CPPL_ERR, "");
    logger7.log(CPPL_WARN, "");
    logger7.log(CPPL_NOTICE, "");
    logger7.log(CPPL_INFO, "");
    logger7.log(CPPL_DEBUG, "");
    logger7.log(CPPL_UNDEFINED, "");

    Logger logger8(format, "CPPL_ALERT or above", CPPL_ALERT, filename);

    logger8.log(CPPL_FATAL, "");
    logger8.log(CPPL_ALERT, "");
    logger8.log(CPPL_CRIT, "");
    logger8.log(CPPL_ERR, "");
    logger8.log(CPPL_WARN, "");
    logger8.log(CPPL_NOTICE, "");
    logger8.log(CPPL_INFO, "");
    logger8.log(CPPL_DEBUG, "");
    logger8.log(CPPL_UNDEFINED, "");

    Logger logger9(format, "CPPL_FATAL only", CPPL_FATAL, filename);

    logger9.log(CPPL_FATAL, "");
    logger9.log(CPPL_ALERT, "");
    logger9.log(CPPL_CRIT, "");
    logger9.log(CPPL_ERR, "");
    logger9.log(CPPL_WARN, "");
    logger9.log(CPPL_NOTICE, "");
    logger9.log(CPPL_INFO, "");
    logger9.log(CPPL_DEBUG, "");
    logger9.log(CPPL_UNDEFINED, "");
}

int main() {
    log_test();
    log_to_file("filter_test.log");
}

#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <sstream>
#include <cstring>
#include <string>
#include <ctime>
#include <chrono>

/**
 * @brief Current Epoch time (POSIX timestamp)
 * @return The current POSIX timestamp
 */
std::time_t currentEpoch()
{
    return std::time(NULL);
};

/**
 * @brief Convert date to POSIX timestamp
 * @param date Date to convert in yyyy-MM-dd format (ignore hour)
 * @return Date in epoch format
 */
std::time_t dateToEpoch(const char *date)
{
    char year[5] = {0};
    strncpy(year, date, 4);

    char month[3] = {0};
    strncpy(month, date + 5, 2);

    char day[3] = {0};
    strncpy(day, date + 8, 2);

    struct tm time = { 0 };  // Initalize to all 0's
    time.tm_year = std::atoi(year)-1900;  // This is year-1900, so 112 = 2012
    time.tm_mon = std::atoi(month)-1;
    time.tm_mday = std::atoi(day)+1;


    return std::mktime(&time); 
};

/**
 * @brief Convert POSIX timestamp in date
 * @param epoch POSIX timestamp
 * @return Date in yyyy-MM-dd format (ignore hour)
 */
std::string epochToDate(const std::time_t epoch)
{
    struct std::tm *ptm = std::gmtime(&epoch);
    std::stringstream osYear;
    osYear << ptm->tm_year + 1900;

    std::stringstream osMonth;
    if (ptm->tm_mon < 9)
    {
        osMonth << 0 << ptm->tm_mon + 1;
    }
    else
    {
        osMonth << ptm->tm_mon + 1;
    }

    std::stringstream osDay;
    if (ptm->tm_mday < 10)
    {
        osDay << 0 << ptm->tm_mday;
    }
    else
    {
        osDay << ptm->tm_mday;
    }

    std::string date = osYear.str() + "-" + osMonth.str() + "-" + osDay.str();
    return date;
};

/**
 * @brief Compare two dates in yyyy-MM-dd format
 * @param date1 First date
 * @param date2 Second date
 * @return True if date1 <= date2, False otherwise
 */
bool before(const char *date1, const char *date2)
{
    std::time_t epoch1 = dateToEpoch(date1);
    std::time_t epoch2 = dateToEpoch(date2);

    return epoch1 < epoch2;
};

#endif /* TIME_UTILS_H */
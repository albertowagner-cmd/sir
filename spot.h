#ifndef SPOT_H
#define SPOT_H

#include "time_utils.h"

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

/**
 * @brief Spot class
 */
class Spot
{

public:
    Spot(std::time_t date, long double open, long double high, long double low, long double close, long double adj_close, long int volume)
    {
        this->date = date;
        this->open = open;
        this->high = high;
        this->low = low;
        this->close = close;
        this->adj_close = adj_close;
        this->volume = volume;
    };


    Spot(std::string date, long double open, long double high, long double low, long double close, long double adj_close, long int volume)
    {
        this->date = dateToEpoch(date.c_str());
        this->open = open;
        this->high = high;
        this->low = low;
        this->close = close;
        this->adj_close = adj_close;
        this->volume = volume;
    };

    Spot(std::time_t date, long double price)
    {
        this->date = date;
        this->close = price;
        this->open = price;
        this->high = price;
        this->low = price;
        this->adj_close = price;
    };

    Spot(std::string date, long double price)
    {
        this->date = dateToEpoch(date.c_str());
        this->close = price;
        this->open = price;
        this->high = price;
        this->low = price;
        this->adj_close = price;
    };


    ~Spot(){};

    std::time_t getDate()
    {
        return date;
    };

    std::string getDateToString()
    {
        return epochToDate(date);
    };

    long double getOpen()
    {
        return open;
    };

    long double getHigh()
    {
        return high;
    };

    long double getLow()
    {
        return low;
    };

    long double getClose()
    {
        return close;
    };

    long double getAdjClose() 
    {
        return adj_close;
    }

    long int getVolume() 
    {
        return volume;
    }

    std::string toString()
    {
        std::ostringstream osOpen;
        osOpen << open;
        std::ostringstream osHigh;
        osHigh << high;
        std::ostringstream osLow;
        osLow << low;
        std::ostringstream osClose;
        osClose << close;
        std::ostringstream osAdjClose;
        osAdjClose << adj_close;
        std::ostringstream osVolume;
        osVolume << volume;
        return "{ date: " + getDateToString() + " open: " + osOpen.str() + " high: " + osHigh.str() + " low: " + osLow.str() + " close: " + osClose.str() + " adj close: " + osAdjClose.str() + " volume: " + osVolume.str() + " }";
    };

    void printSpot()
    {
        std::cout << toString() << std::endl;
    };

private:
    std::time_t date;
    long double open;
    long double high;
    long double low;
    long double close;
    long double adj_close;
    long int volume;
};

#endif /* SPOT_H */
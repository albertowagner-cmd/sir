#ifndef QUOTE_H
#define QUOTE_H

#include "spot.h"
#include "time_utils.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class Quote
{
public:
    Quote(std::string symbol) :symbol{ symbol } {}

    ~Quote(){};

    size_t nbSpots()
    {
        return spots.size();
    };

    Spot getSpot(size_t i)
    {
        if (i < nbSpots())
        {
            return spots[i];
        }
        std::stringstream ss;
        ss << spots.size();

        std::string error = "ERROR: getSpot(index) - Index must be smaller than " + ss.str();
        throw std::invalid_argument(error);
    };


    Spot getSpot(std::time_t date)
    {
        for (std::vector<Spot>::iterator it = spots.begin();
             it != spots.end();
             ++it)
        {
            if (it->getDate() == date)
            {
                return *it;
            }
        }
        std::string error = "ERROR getSpot(date) - There is not spot at " + date;
        throw std::invalid_argument(error);
    };

    Spot getSpot(std::string date)
    {
        for (std::vector<Spot>::iterator it = spots.begin();
             it != spots.end();
             ++it)
        {
            if (it->getDateToString() == date)
            {
                return *it;
            }
        }
        std::string error = "ERROR getSpot(date) - There is not spot at " + date;
        throw std::invalid_argument(error);
    };

    void printSpots()
    {
        for (std::vector<Spot>::iterator it = spots.begin(); it != spots.end();++it)
        {
            std::cout << it->toString() << std::endl;
        }
    };

    void clearSpots()
    {
        spots.clear();
    };


    void getHistoricalSpots()
    {
        std::string fileName = "output/" + symbol + ".csv";
        std::fstream csvStream(fileName);
        if (!csvStream.is_open()) {
            std::cerr << "Error: Unable to open the file." << std::endl;
        }

        std::string line;

        // Remove the header line
        std::getline(csvStream, line);

        while (std::getline(csvStream, line))
        {
            // Split line delimited by comma separator into a vector
            std::vector<std::string> spotVector;
            std::stringstream iss(line);
            std::string lineItem;
            while (std::getline(iss, lineItem, ','))
            {
                spotVector.push_back(lineItem);
            }

            if (spotVector[0] != "null" && spotVector[1] != "null")
            {
                Spot spot = Spot(
                    spotVector[0],                    // date
                    std::stold(spotVector[1].c_str()), // open
                    std::stold(spotVector[2].c_str()), // high
                    std::stold(spotVector[3].c_str()), // low
                    std::stold(spotVector[4].c_str()), // close
                    std::stold(spotVector[5].c_str()), // adj close
                    std::stol(spotVector[6].c_str())  // volume
                );
                spots.insert(spots.begin(), spot);
            }
        }
        csvStream.close();
    };


private:
    std::string symbol;
    std::vector<Spot> spots;
};

#endif /* QUOTE_H */
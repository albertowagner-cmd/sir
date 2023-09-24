#include "../headers/quote.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Quote*> quote_list;
    quote_list.push_back(new Quote("UCG.MI"));
    quote_list.push_back(new Quote("AAPL"));
    quote_list.push_back(new Quote("TSLA"));

    // Get the historical spots from CSV files, located in /output/ folder
    for (auto it: quote_list){
        it->getHistoricalSpots();
    }

    // Print the spots
    for (auto it: quote_list){
        std::cout<<"Symbol: "<<it->getSymbol()<<std::endl;
        it->printSpots();
        std::cout<<std::endl;
    }
    std::cout<< std::endl;
 

    // Print a spot
    // try {
    //     Spot spot = quote_list.at(0)->getSpot("2023-09-15");
    //     std::cout << "Spot at 2023-09-15: " << std::endl;
    //     spot.printSpot();
    // }
    // catch (const std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // Free memory
    for(auto it:quote_list){delete it;};
}
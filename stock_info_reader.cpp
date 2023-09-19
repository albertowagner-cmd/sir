#include "quote.h"
#include <iostream>

int main() {
    Quote* ftsemib = new Quote("UCG.MI");

    // Get the historical spots from CSV files, located in /output/ folder
    ftsemib->getHistoricalSpots();

    // Print the spots
    ftsemib->printSpots();
    std::cout<< std::endl;
 

    // Print a spot
    try {
        Spot spot = ftsemib->getSpot("2023-09-15");
        std::cout << "Spot at 2023-09-15: " << std::endl;
        spot.printSpot();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Free memory
    delete ftsemib;
}
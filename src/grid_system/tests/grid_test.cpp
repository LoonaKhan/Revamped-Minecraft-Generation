//
// Created by loona on 06/06/22.
//
#include "../grid.h"
#include <iostream>
#include <vector>

int main(){ // tests the grid methods

    std::vector<int> gridCoords = {0,1}; // gives a
    std::cout << convertCoords(gridCoords)[0]<< ", " << convertCoords(gridCoords)[1] << std::endl;
    std::cout << "Grid dimensions: " << getGridDimensions()[0]<<", "<<getGridDimensions()[1] << std::endl;

}
// Tests for grid.cpp
//
// Created by loona on 06/06/22.
//
#include "../grid.h"
#include <iostream>
#include <vector>

// useful for logging vectors
#define vectorLog(x) "[" << x[0] << ", " << x[1] << "]"

void convertCoordsTest(){
    // Tests grid::convertCoords.
    // convertCoords converts 1 vector to another vector
    // to test, we will set a number of key vectors and see if they convert properly
    // important edge cases are the center corners and edges of the screen
    //
    // for reference: 0,0 on drawCoords() is the top left corner

    std::vector<int> mid = {0,0}, // gets all out possible points
        topRightCorner = grid::getGridDimensions(),
        topLeftCorner = {-grid::getGridDimensions()[0], grid::getGridDimensions()[1]},
        botLeftCorner = {-grid::getGridDimensions()[0], -grid::getGridDimensions()[1]},
        botRightCorner = {grid::getGridDimensions()[0], -grid::getGridDimensions()[1]},
        topEdge = {0, grid::getGridDimensions()[1]},
        botEdge = {0, -grid::getGridDimensions()[1]},
        rightEdge = {grid::getGridDimensions()[0], 0},
        leftEdge = {-grid::getGridDimensions()[0], 0};

    // logs them
    std::cout << "mid: " << vectorLog(mid) << vectorLog(grid::convertCoords(mid)) <<std::endl;
    std::cout << "topRight" << vectorLog(topRightCorner) << vectorLog(grid::convertCoords(topRightCorner)) <<std::endl;
    std::cout << "topLeft" << vectorLog(topLeftCorner) << vectorLog(grid::convertCoords(topLeftCorner)) <<std::endl;
    std::cout << "botRight" << vectorLog(botRightCorner) << vectorLog(grid::convertCoords(botRightCorner)) <<std::endl;
    std::cout << "botLeft" << vectorLog(botLeftCorner) << vectorLog(grid::convertCoords(botLeftCorner)) <<std::endl;
    std::cout << "topEdge" << vectorLog(topEdge) << vectorLog(grid::convertCoords(topEdge)) <<std::endl;
    std::cout << "botEdge" << vectorLog(botEdge) << vectorLog(grid::convertCoords(botEdge)) <<std::endl;
    std::cout << "rightEdge" << vectorLog(rightEdge) << vectorLog(grid::convertCoords(rightEdge)) <<std::endl;
    std::cout << "leftEdge" << vectorLog(leftEdge) << vectorLog(grid::convertCoords(leftEdge)) <<std::endl;
}

void getGridDimensionsTest(){
    // tests grid dimensions
    // grid dimensions are just based off of block size and zoom.
    // block size is set to 32, so the only factor we want to modify is zoom
    // the zoom factor's range is [0.25, 4.0].
    for (zoomFactor = 0.25f; zoomFactor <=4.0f; zoomFactor+= 0.25f){
        std::cout << "zoom: " << zoomFactor << " "
        << "grid coords: " << vectorLog(grid::getGridDimensions())
        << std::endl;
    }
}

void setZoomTest(){
    // zoom has a range of [0.25, 4.0].
    // we also only change it by 0.25 every scroll.
    // we can just try to make zoom factor reach its limits

    // zooms out 4 times. on the last iteration, it should remain the same
    // 1->0.75->0.5->0.25->0.25
    for (int i=0; i<4; i++){
        grid::setZoom(-0.25);
        std::cout << "zoom: " << zoomFactor << std::endl;
    }

    std::cout <<std::endl;
    zoomFactor = 1.0f; // resets the zoom factor

    // zooms in 13 times. on the last iteration, it should remain the same
    //1->1.25->1.5->1.75->2.0->2.25->2.5->2.75->3.0->3.25->3.5->3.75->4->4
    for (int i=0; i<13; i++){
        grid::setZoom(0.25);
        std::cout << "zoom: " << zoomFactor << std::endl;
    }


}

int main(){ // tests the grid methods
    //convertCoordsTest();
    //getGridDimensionsTest();
    //setZoomTest();
}
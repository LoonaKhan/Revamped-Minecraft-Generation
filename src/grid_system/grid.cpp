//
// Created by loona on 06/06/22.
//

#include "grid.h"

#include <cmath>

std::vector<int> convertCoords(std::vector<int> gridCoords) {
    /*
     * Converts a pair of coordinates.
     *
     * The coordinates on the grid represent blocks. each block is blockSize(16px).
     * Therefore, we must convert our desired gridCoords, which represent the block's coordinates to
     * the drawCoords, which represents the coordinates on the screen that match the gridCoords.
     *
     * Example:
     *  // we want to draw the point 0,0. it is located on point: 960, 540.
     *  (0,0) -> (960, 540)
     * */
    return {
            midPoint[0] + (int)(gridCoords[0] * zoomFactor * blockSize),
            midPoint[1] + (int)(gridCoords[1] * zoomFactor * blockSize)
    };
}

std::vector<int> getGridDimensions(){
    /*
     * Determines the size of the grid given the zoom factor and block size.
     *
     * The grid is an abstraction. its points and the drawCoords are not one-to-one. so we dont know if a coordinate is
     * off-screen or not.
     * We want to render all points onscreen and not the ones off-screen.
     *
     * This function uses the blockSize, midPoint and zoomFactor to determine the dimensions of the grid.
     * this dimensions is how far the grid goes in the x and y directions. this is the number of blocks drawn.
     * All of these blocks will be visible.
     *
     * Example:
     *  blockSize = 16, zoomFactor = 1.0, midPoint = [960, 540]
     *  -> [60, 33]
     *  // 60 blocks can fit in the -x or +x direction.
     *  // 33 blocks can fit within the -y or +y direction.
     *
     * */
    return {
        midPoint[0] / (int)(blockSize * zoomFactor),
        midPoint[1] / (int)(blockSize * zoomFactor)
    };
}

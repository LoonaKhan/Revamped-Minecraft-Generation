//
// Created by loona on 22/06/22.
//

#include "vector_utils.h"
#include <iostream>

bool vtr::vectorContainsVector(std::vector<std::vector<int>> list1, std::vector<int> list2) {
    /*
     * Checks if a vector exists within a 2d vector.
     *
     * This just loops through the vector like normal.
     * I know that i could order the vectors and use a binary search
     * but i have no guarantee that these vectors are ordered
     * Additionally, this is just a dumb side project, so im just trying to get this done.
     *
     * This assumes list1[i] is the same size as list2, so it only checks the first 2 elements.
     * so:
     * {1,2,3} = {1,2}
     *
     * */
    // checks if the list1 contains list2
    for (auto & i : list1){
        if (i[0] == list2[0])
            if (i[1] == list2[1])
                return true;

    }

    return false;
}

bool vtr::blockListContainsVector(std::vector<Block> toDraw, std::vector<int> needed) {
    /*
     * Checks if a block list contains a block of the same vector.
     *
     * Just loops through the list.
     *
     * the vector is assumed to be the same size as block.position, so it only checks the first 2 elements.
     * Eg:
     * v = {1,2,3}, block.position = {1,2}
     * >>> true
     * */
    // checks if the block lists contains the given vector
    for (auto block : toDraw){
        if (block.position[0] == needed[0])
            if (block.position[1] == needed[1])
                return true;
    }
    return false;
}

std::vector<Block> vtr::rightMatch(std::vector<Block> toDraw, std::vector<std::vector<int>> needed) {
    /*
     * Fills toDraw with all the needed blocks.
     *
     * Performs a rightmatch. all the indexes of needed will be present in toDraw.
     * Additionally, any block toDraw that are not in needed, will be removed
     * */

    for (int i=toDraw.size()-1; i >= 0; i--) {

        // if a block in toDraw is not in needed, remove it
        if (!vtr::vectorContainsVector(needed, toDraw[i].position))
            toDraw.erase(toDraw.begin() + i);

    }
    for (int i=needed.size()-1; i>=0; i--){

        // if a block in needed is not in toDraw, add it to toDraw
        if (!vtr::blockListContainsVector(toDraw, needed[i]))
            toDraw.push_back(Block(needed[i]));

    }

    return toDraw;
}
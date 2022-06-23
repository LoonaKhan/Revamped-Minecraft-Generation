//
// Created by loona on 22/06/22.
//

#include "vector_utils.h"
#include <algorithm>

std::vector<Block> vtr::rightMatch(std::vector<Block> toDraw, std::vector<std::vector<int>> needed) {
    /*
     * Fills toDraw with all the needed blocks.
     *
     * Performs a rightmatch. all the indexes of needed will be present in toDraw.
     * Additionally, any block toDraw that are not in needed, will be removed
     * */

    for (int i=std::max(toDraw.size(), needed.size()); i >= 0; i--){

        // if a block in toDraw is in needed, remove it
        if (std::find(needed.begin(), needed.end(), toDraw[i].position) == needed.end())
            toDraw.erase(toDraw.begin() + i);


        // if a block in needed is not in toDraw, add it to toDraw
        if (std::find(toDraw.begin(), toDraw.end(), needed[i]) == toDraw.end())
            toDraw.push_back(Block(needed[i]));

        // pop the last value in needed.
        needed.erase(needed.begin() + i);

    }

    return toDraw;
}
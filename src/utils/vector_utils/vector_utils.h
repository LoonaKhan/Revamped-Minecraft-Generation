//
// Created by loona on 22/06/22.
//

#pragma once

#include <algorithm>
#include <vector>
#include "../../grid_system/Block.h"
// implement this into the lin-alg package


namespace vtr {
    std::vector<Block> rightMatch(std::vector<Block> toDraw, std::vector<std::vector<int>> needed);

    bool vectorContainsVector(std::vector<std::vector<int>> list1, std::vector<int> list2);

    bool blockListContainsVector(std::vector<Block> toDraw, std::vector<int> needed);
}


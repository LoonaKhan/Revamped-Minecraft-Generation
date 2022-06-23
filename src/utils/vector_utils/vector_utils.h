//
// Created by loona on 22/06/22.
//

#ifndef REVAMPED_MINECRAFT_GENERATION_VECTOR_UTILS_H
#define REVAMPED_MINECRAFT_GENERATION_VECTOR_UTILS_H

#include <vector>
#include "../../grid_system/Block.h"
// implement this into the lin-alg package


namespace vtr {
    std::vector<Block> rightMatch(std::vector<Block> toDraw, std::vector<std::vector<int>> needed);
}
#endif //REVAMPED_MINECRAFT_GENERATION_VECTOR_UTILS_H

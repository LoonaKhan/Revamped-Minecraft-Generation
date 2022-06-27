//
// Created by loona on 23/06/22.
//

#include "../vector_utils.h"
#include "../../../grid_system/Block.h"
#include <iostream>
#include <string>

void rightMatchTest(){
    /*
     * Tests the rightMatch.
     *
     * TODO: implement this
     *  test cases:
     *      no overlap          needed= {{1,2}, {0,1}} , toDraw={{0,2}, {0,0}}
     *      overlap             needed= {{1,2}, {0,1}} , toDraw={{1,2}, {0,0}}
     *      complete overlap    needed= {{1,2}, {0,0}} , toDraw={{1,2}, {0,0}}
     *      different size
     *      combinations with diff sizes
     * */

    std::vector<Block> blocksToDraw = {Block({1,2}), Block({0,1})};
    std::vector<std::vector<int>> needed = {{1,3}, {0,0}, {1,1}};

    blocksToDraw = vtr::rightMatch(blocksToDraw, needed);

    for (auto block : blocksToDraw)
        std::cout << "x: " << block.position[0] << " y: " << block.position[1] << std::endl;

}

void vectorContainsVectorTest(){
    /*
     * Test cases:
     *  1 vector: {1,2} , {{1,2}}
     *  multiple vectors: {1,2} , {{1,1}, {0,0}}
     *  no matching vectors: {1,2} , {{0,0}, {1,1}}
     * */
    std::vector<int> vector1 = {1,2, 3};
    std::vector<std::vector<int>> vector2 = {
            {1,1},
            {1},
            {1,2}
    };
    std::string msg = "false";

    if (vtr::vectorContainsVector(vector2, vector1))
        msg = "true ";

    std::cout << msg << std::endl;
}

void blockListContainsVectorTest(){
    /*
     * Test cases:
     *  1 block: needed= {1,2} , toDraw= {{1,2}}
     *  multiple blocks: needed= {1,2} , toDraw= {{1,2},{2,3}}
     *  no matching blocks: needed= {1,2} , toDraw= {{1,0},{2,3}}
     * */
    std::vector<Block> blockList = {Block({1,2}), Block({2,3})};
    std::vector<int> vec = {1,2, 3};
    std::string msg = "false";

    if (vtr::blockListContainsVector(blockList, vec))
        msg = "true";

    std::cout << msg << std::endl;
}

void diffSizedVectors(){
    /*
     * Loops through 2 differently sized vectors.
     * */
    std::vector<int> arr = {1,2,3,4}; // len of 4
    std::vector<int> arr2 = {1,2,3}; // len of 3

    int i=arr.size()-1, j=arr2.size()-1;
    int biggest;
    if (i > j)
        biggest = i;
    else biggest = j;

    for (; biggest >=0; biggest--){
        //std::cout << (i>=0 && j>=0) << std::endl;
        std::cout << "index " << biggest << " of arr: " << arr[biggest];
        std::cout << " index " << biggest << " of arr2: " << arr2[biggest] <<std::endl;
    }

}

void arrIndexes(){
    // confirms if v.begin()+ i = i
    std::vector<int> arr = {0,1,2,3};
    std::cout << *(arr.begin()+2) << std::endl;
}

int main(){
    //diffSizedVectors();
    //arrIndexes();
    rightMatchTest();

    //vectorContainsVectorTest();
    //blockListContainsVectorTest();
}
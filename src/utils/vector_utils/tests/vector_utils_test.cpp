//
// Created by loona on 23/06/22.
//

//#include "../vector_utils.h"
//#include "../../../grid_system/Block.h"
#include <iostream>
#include <vector>

void rightMatchTest(){
    /*
     * Tests the rightMatch.
     *
     * TODO: implement this
     * */
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
}
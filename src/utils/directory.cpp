// Directory utils
// TODO: make this better. able to use any filter
//
// Created by loona on 13/06/22.
//
#include "directory.h"
#include <iostream>
#include <cstddef>

std::vector<std::string> listDirContents(std::string path, std::string filter){
    // lists all files in a directory matching a certain filter
    DIR *dr;
    struct dirent *en;
    dr = opendir(path.c_str());
    std::vector<std::string> list;


    if (dr){
        while ((en = readdir(dr)) != nullptr){ // opens the directory
            auto index = static_cast<std::string>(en->d_name);

            // ensures it's extension matches the filter
            size_t dot = index.find_last_of(".");
            if (dot == std::string::npos); // if "." is not found in a file/dir, ignore it

            else { // otherwise process it
                // check if the extension matches
                std::string ext = index.substr(dot);
                std::cout << filter << " " << ext << " " << index << " " << dot << std::endl;

                if (ext.compare(filter) == 0) // if so, append it to the list
                    list.push_back((std::string) path+index);
            }
        }
        closedir(dr); // closes the directory
    }
    return list;
}

// TODO: make a test for this
/*int main(){
    std::string path = "../../assets/blocks/plains/";
    std::string filter = ".png";

    auto list = listDirContents(path, filter);
    for (auto i : list)
        std::cout <<i<<std::endl;
}*/
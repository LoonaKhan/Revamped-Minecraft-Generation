//
// Created by loona on 13/06/22.
//

#ifndef REVAMPED_MINECRAFT_GENERATION_DIRECTORY_H
#define REVAMPED_MINECRAFT_GENERATION_DIRECTORY_H

#include <dirent.h>
#include <sys/types.h>
#include <vector>
#include <string>

std::vector<std::string> listDirContents(std::string path, std::string filter);

#endif //REVAMPED_MINECRAFT_GENERATION_DIRECTORY_H

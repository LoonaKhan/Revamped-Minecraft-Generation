//
// Created by loona on 06/06/22.
//

#ifndef REVAMPED_MINECRAFT_GENERATION_GLOBVARS_H
#define REVAMPED_MINECRAFT_GENERATION_GLOBVARS_H
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>

// the grid data
extern const int screenRes[];
extern const int midPoint[];
extern float zoomFactor;
extern const int blockSize;
extern const int chunkSize;

// name of the app for the window
extern const char appName[];

// keeps track of all textures
extern std::unordered_map<std::string , sf::Texture> TEXTURES;

// FPS data
extern float frameTime;
extern float FPS;
extern int FPSLimit;

#endif //REVAMPED_MINECRAFT_GENERATION_GLOBVARS_H

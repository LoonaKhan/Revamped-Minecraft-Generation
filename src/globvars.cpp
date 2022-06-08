//
// Created by loona on 06/06/22.
//

#include "globvars.h"

const int screenRes[] = {1920, 1080};
const int midPoint[] = {screenRes[0]/2, screenRes[1]/2};
float zoomFactor = 2.0f; // min of 0.5? max of 4.0? test
const int blockSize = 16; // 32 seems like a nice sweet-spot.
const int chunkSize = 16;
const char appName[] = "Revamped Minecraft Generation";
#pragma once
#include "TwitterGraph.h"
#include <iostream>
#include <fstream>
#include <string>


void readData(TwitterGraph& g, std::string filename);

void outputBFS(TwitterGraph& g, std::string filename);

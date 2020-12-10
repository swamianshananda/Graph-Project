#pragma once
#include "TwitterGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void readData(TwitterGraph& g, std::string filename);

void outputBFS(TwitterGraph& g, std::string filename);

void outputDistances(TwitterGraph& g, std::string filename);

void outputC(TwitterGraph& g, std::string filename);

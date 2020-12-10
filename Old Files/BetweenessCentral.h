#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include "TwitterGraph.h"

void betweenessCentral(TwitterGraph &g, int** distanceArray);

int findLargestNumber(int* source);

void recursiveBetweenVal(int source, int current, int distance[], float (&betweenessCentralValues)[]);

void betweenessCentral(TwitterGraph &g);
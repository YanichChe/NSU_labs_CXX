#ifndef GAME_DATA_H
#define GAME_DATA_H

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#define POINTS_FILE "points.txt"
#define POINTS_NUMBER 6
#define PLAYERS_NUMBER 3
class GameData
{
public:
    
private:
    int points[POINTS_NUMBER];
    int steps;
    std::vector <std::string> strategiesNames;
};

#endif
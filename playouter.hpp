#pragma once

#include <functional>

#include "2048-cpp/board.hpp"

class Playouter{
public:
    Playouter(std::function<int(Board::Grid)> func) : staticEval(func){}
    int playout(Board::Grid);
    int iteration(int);
private:
    std::function<int(Board::Grid)> staticEval;
};

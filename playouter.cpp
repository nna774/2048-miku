#include "playouter.hpp"

#include "2048-cpp/koyone.hpp"
#include "2048-cpp/koyoneNext.hpp"

int Playouter::playout(Board::Grid grid){
    return toDead(grid, 0);
}

int Playouter::toDead(Board::Grid grid, int score){
    if(! Board::alive(grid)) return score;
    int const ITERATION = 10;
    Dir dir;
    {
        Koyone::GridMap top = KoyoneNext::iterarion(KoyoneNext::nextPossibleWorld(grid), ITERATION);
        dir = (std::max_element(std::begin(top), std::end(top), [this](std::pair<Board::Grid, Dir> a, std::pair<Board::Grid, Dir> b){ return staticEval(a.first) < staticEval(b.first); } ))->second;
    }
    Board::Grid moved = Board::moveAndBirth(grid, dir).second;
    return toDead(moved, score + Board::getScore(grid, dir));
}

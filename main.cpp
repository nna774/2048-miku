#include <iostream>

#include "playouter.hpp"

#include "2048-cpp/board.hpp"
#include "2048-cpp/koyone.hpp"

int main(int, char**){
    Playouter xLogx(Koyone::staticEval);

    auto grid = Playouter::getInitGrid();
    std::cout << xLogx.playout(grid) << std::endl;
    return 0;
}


// a, b, b, a
// c, d, d, c
// c, d, d, c
// a, b, b, a
std::function<int(Board::Grid)> maker4(int a, int b, int c, int d){
    // static tableA = maker4_impl(
}



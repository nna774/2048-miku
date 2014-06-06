#include <iostream>
#include <array>

#include "playouter.hpp"

#include "2048-cpp/board.hpp"
#include "2048-cpp/koyone.hpp"

static int const constexpr ITERATION = 100;

int main(int, char**){
    Playouter xLogx(Koyone::staticEval);

    std::array<int, ITERATION> scores;

    #ifdef _OPENMP
        #pragma omp parallel for
    #endif
    for(int i = 0; i < ITERATION; ++i){
	auto grid = Playouter::getInitGrid();
	scores[i] = xLogx.playout(grid);
    }

    for(int e:  scores)
	std::cout << e << std::endl;
    return 0;
}

// a, b, b, a
// c, d, d, c
// c, d, d, c
// a, b, b, a
std::function<int(Board::Grid)> maker4(int a, int b, int c, int d){
    // static tableA = maker4_impl(
}



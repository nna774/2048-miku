#pragma once

#include <functional>

#include "2048-cpp/board.hpp"

class Playouter{
public:
    Playouter(std::function<int(Board::Grid)> func) : staticEval(func){}
    int playout(Board::Grid);
    int iteration(int);
    static Board::Grid getInitGrid() {
	Board::Grid grid = 0;
	auto mt = mtInit();
	int i = mt() % 16;
	int j = mt() % 16;
	while(i == j) j = mt() % 16;
	int birth;
	if(mt() % 10) birth = 1;
	else birth = 2;
	grid = Board::set(grid, i / 4, i % 4, birth);

	if(mt() % 10) birth = 1;
	else birth = 2;
	grid = Board::set(grid, j / 4, j % 4, birth);

	return grid;
    }

private:
    std::function<int(Board::Grid)> staticEval;

    static std::mt19937 mtInit(){
        static std::random_device rnd;
        std::vector<std::uint_least32_t> v(10);
        for(auto& e: v) e = rnd();
        std::seed_seq seq(begin(v), end(v));
        std::mt19937 mt(seq);
        return mt;
    }

};

namespace{
    std::array<Board::Grid, 480> make_InitialGrid() {
	std::array<Board::Grid, 480> table;
	int cnt(0);
	for(int i(0); i < 16; ++i)
	    for(int j(0); j< i; ++j){
		table[cnt++] = Board::set(Board::set(0, i / 4, i % 4, 1), j / 4, j % 4, 1); // 2, 2
		table[cnt++] = Board::set(Board::set(0, i / 4, i % 4, 1), j / 4, j % 4, 2); // 2, 4
		table[cnt++] = Board::set(Board::set(0, i / 4, i % 4, 2), j / 4, j % 4, 1); // 4, 2
		table[cnt++] = Board::set(Board::set(0, i / 4, i % 4, 2), j / 4, j % 4, 2); // 4, 4
	    }
	return table;
    }
}

namespace BoardUtil{
    static std::array<Board::Grid, 480> const table = make_InitialGrid();
}

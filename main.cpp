#include <iostream>

#include "playouter.hpp"

#include "2048-cpp/koyone.hpp"

int main(int, char**){
    Playouter xLogx(Koyone::staticEval);
    std::cout << xLogx.playout(0x101) << std::endl;

    return 0;
}











CXX = g++
CXXFLAG = -std=c++11
OPT = -O3

SUBS = board.cpp koyone.cpp koyoneNext.cpp kihime.cpp kihimeNext.cpp nona7.cpp
SUBS_O = board.o koyone.o koyoneNext.o kihime.o kihimeNext.o nona7.o
SUBS_DIR = 2048-cpp
SRC = main.o playouter.o
OUTNAME = miku

.PHONY: test all clean subs $(patsubst %, $(SUBS_DIR)/%, $(SUBS_O))

all: $(SRC) $(patsubst %, $(SUBS_DIR)/%, $(SUBS_O))
	$(CXX) $(CXXFLAG) $(OPT) $^ -o $(OUTNAME)

main.o: main.cpp
	$(CXX) $(CXXFLAG) $(OPT) main.cpp -c

playouter.o: playouter.cpp playouter.hpp
	$(CXX) $(CXXFLAG) $(OPT) playouter.cpp -c

$(patsubst %, $(SUBS_DIR)/%, $(SUBS_O)):
	cd $(SUBS_DIR); make OPT=$(OPT)

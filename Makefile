CC := gcc
FLAGS := -lstdc++ -llua

all:
	$(CC) *.cc -lstdc++ $(FLAGS)

fmt:
	clang-format -i *.cc

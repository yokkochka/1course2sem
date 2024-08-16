CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic

BUILD_PATH = ./build

all : start goal_lab1 goal_lab2_d goal_lab2_s goal_lab3 goal_lab4_s goal_lab4_d goal_lab5

start :
	mkdir -p build 

goal_lab1 : start
	$(CC) $(CFLAGS) ./lab1/lab2_1.cpp -o $(BUILD_PATH)/lab1.out

goal_lab2_d : start
	$(CC) $(CFLAGS) ./lab2_d/lab2_2.cpp -o $(BUILD_PATH)/lab2_d.out

goal_lab2_s : start
	$(CC) $(CFLAGS) ./lab2_s/lab2_2.cpp -o $(BUILD_PATH)/lab2_s.out

goal_lab3 : start
	$(CC) $(CFLAGS) ./lab3/functions.cpp ./lab3/lab2_3.cpp -o $(BUILD_PATH)/lab3.out

goal_lab4_d : start
	$(CC) $(CFLAGS) ./lab4_d/lab2_4.cpp ./lab4_d/other_functions.cpp ./lab4_d/vvod_and_vivod.cpp -o $(BUILD_PATH)/lab4_d.out

goal_lab4_s : start
	$(CC) $(CFLAGS) ./lab4_s/dop_functions.cpp ./lab4_s/lab2_4.cpp ./lab4_s/vvod_vivod.cpp -o $(BUILD_PATH)/lab4_s.out

goal_lab5 : start
	$(CC) $(CFLAGS) ./lab5/lab2_5.cpp -o $(BUILD_PATH)/lab5.out

format : 
	clang-format -n ./*/*.cpp
	clang-format -i ./*/*.cpp

clean:
	rm -f $(BUILD_PATH)/*
	rm -rf ./build
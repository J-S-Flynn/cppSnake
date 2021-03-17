//
// Created by jason on 16/03/2021.
//
#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>


#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

struct Segment{

    int xPos, yPos;
    Segment(int x, int y);
    Segment();
};

class snakeClass{

    int width = 50;
    int height = 15;
    int points, speed, maxW, maxH;
    char sDirection, quit, segmentChar, foodChar;
    bool get;
    bool gameOver;
    Segment food;
    std::vector<Segment> snake;

public:
    snakeClass();
    ~snakeClass();

    WINDOW * setUp() ;
    void startGame();
    void draw(WINDOW * win);
    void input(WINDOW * win);
    void logic();
    void welcomeScreen();
private:
    void generateFood();
    bool collision();
    void move();

};

#endif //SNAKE_SNAKE_H

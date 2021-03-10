//
// Created by jason on 10/03/2021.
//

#ifndef CPPSNAKE_SNAKE_H
#define CPPSNAKE_SNAKE_H

#include <ncurses.h>

class snake{
public:

    void welcomeScreen();

    WINDOW * setUp();

    void draw(WINDOW * win);

    void input(WINDOW * win);
    void logic();

    void randomFood();


private:

    enum SnakeDirection {

        moveLeft,
        moveRight,
        moveUp,
        moveDown,
        quit,
    };

    SnakeDirection sDirection ;
    bool gameOver ;
    const int width = 50 ;
    const int height = 15 ;
    int coordinateX, coordinateY, foodX, foodY, pionts;

};


#endif //CPPSNAKE_SNAKE_H

#include <iostream>
#include <ncurses.h>

using namespace std ; 


//蛇　ゲーム　
//foray into game c++

enum SnakeDirection {

    moveLeft,
    moveRight,
    moveUp,
    moveDown,
};

SnakeDirection sDirection ;

void welcomeScreen() ;
void game() ;
void draw(WINDOW * win) ;
WINDOW * setUp() ;
void input(WINDOW * win) ;
void logic() ;

bool gameOver ; 
const int width = 50 ;
const int height = 15 ;
int coordinateX, coordinateY, foodX, foodY, pionts;

int main(){

    game() ; 
    
    return 0 ; 
}

void game(){

    initscr() ;
    welcomeScreen() ;
    WINDOW * win = setUp() ;

    while(!gameOver){

        draw(win) ;
        input(win) ;
        logic() ;
    }

    refresh() ;
    mvwprintw(win, height/2, width/2, "Game Over") ;
    endwin() ;
}

void welcomeScreen(){

    refresh() ;

    cout << "\n\n\n\t\tWelcome to snake press enter to continue \r " << endl  ;

    getch() ;
    refresh() ;

}

WINDOW * setUp(){


    WINDOW * win  = newwin(height, width, 5,5) ;

    gameOver = false ; 

    coordinateX = width / 2 ;
    coordinateY = height / 2  ; 

    foodX = rand() % width ;
    foodY = rand() % height ;  
    pionts = 0 ;

    sDirection = moveUp ;

    wmove(win, coordinateY, coordinateX) ;

    return win ;
}

void draw(WINDOW * win){

    wclear(win);

    refresh() ;

    box(win,0,0) ;
    mvwprintw(win, 0, 2," Snake ") ;
    mvwprintw(win, foodY, foodX, "*") ;
    mvwprintw(win, coordinateY, coordinateX, "[]") ;
    wrefresh(win) ;

    refresh() ;
}

void input(WINDOW * win){


    keypad(win, true) ;

    refresh() ;

    int keyStroke = wgetch(win) ;

    if(keyStroke == KEY_UP){
         sDirection = moveUp ;
    }
    if(keyStroke == KEY_DOWN){
        sDirection = moveDown ;
    }
    if(keyStroke == KEY_LEFT){
        sDirection = moveLeft ;
    }
    if(keyStroke == KEY_RIGHT){
        sDirection = moveRight ;
    }

    wrefresh(win) ;
}

void logic(){

    switch (sDirection){
        case moveUp: coordinateY -= 1 ;
        break ;
        case moveDown: coordinateY += 1 ;
        break ;
        case moveLeft: coordinateX -= 1 ;
        break ;
        case moveRight: coordinateX += 1 ;
        break ;
    }
}
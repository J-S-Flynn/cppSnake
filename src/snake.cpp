#include "snake.h"


using namespace std ; 

Segment::Segment(int xPos, int yPos) {
    this->xPos = xPos;
    this->yPos = yPos;
}

Segment::Segment() {

    xPos = 0;
    yPos = 0;
}

int main(){

    snakeClass();

    return 0;
}

snakeClass::snakeClass() {

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


void snakeClass::welcomeScreen() {

    refresh() ;

    cout << "\n\n\n\t\tWelcome to snake press enter to continue \r " << endl  ;

    getch() ;
    refresh() ;
}

WINDOW * snakeClass::setUp() {

    WINDOW * win  = newwin(height, width, 5,5) ;

    Segment * head = new Segment();
    head->xPos = width/2;
    head->yPos = height/2;

    gameOver = false ;
    points = 0 ;
    segmentChar = 'X';
    foodChar = 'O';

    wmove(win, head->yPos, head->xPos);
    generateFood();

    return win ;
}

void snakeClass::draw(WINDOW * win) {

    wclear(win);

    box(win,0,0) ;
    mvwprintw(win, 0, 2," Snake ");
    mvwprintw(win, 0, 10, "{points}");
    wrefresh(win) ;

    refresh() ;
}

void snakeClass::input(WINDOW * win){


    keypad(win, true) ;

    refresh() ;

    int keyStroke = wgetch(win) ;

    if(keyStroke == KEY_UP){

    }
    if(keyStroke == KEY_DOWN){

    }
    if(keyStroke == KEY_LEFT){

    }
    if(keyStroke == KEY_RIGHT){

    }
    if(keyStroke == 'q'){
        gameOver = true;
    }

    wrefresh(win) ;
}
/*
 * need to implaent the tail and
 * make the movment automatic in each draw phase
 */
void snakeClass::logic(){

//    switch (sDirection){
//        case moveUp: coordinateY-- ;
//            break ;
//        case moveDown: coordinateY++ ;
//            break ;
//        case moveLeft: coordinateX-- ;
//            break ;
//        case moveRight: coordinateX++;
//            break ;
//        case quit: gameOver = true;
//            break;
//    }
//
//    if(coordinateX == foodX && coordinateY == foodY){
//        pionts++ ;
//        randomFood() ;
//    }
//
//    if(coordinateX > width || coordinateX < 0 || coordinateX > width || coordinateX < 0){
//        gameOver = true ;
//    }
}

void snakeClass::generateFood() {

    food.xPos = rand() % (width - 2) ;
    food.yPos = rand() % (height - 2) ;

    if(food.xPos == 0 || food.yPos == width || food.yPos == 0 || food.yPos == height){

        generateFood();
    }
}

snakeClass::~snakeClass() {

}



//蛇　ゲーム　
//foray into src c++


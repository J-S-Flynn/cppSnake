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
    quit,
};

SnakeDirection sDirection ;

void welcomeScreen() ;
void game() ;
void draw(WINDOW * win) ;
void randomFood() ;
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

void welcomeScreen(){

    refresh() ;

    cout << "\n\n\n\t\tWelcome to snake press enter to continue \r " << endl  ;

    getch() ;
    refresh() ;

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

WINDOW * setUp(){


    WINDOW * win  = newwin(height, width, 5,5) ;

    gameOver = false ; 

    coordinateX = width / 2 ;
    coordinateY = height / 2  ; 

    pionts = 0 ;

    wmove(win, coordinateY, coordinateX) ;
    randomFood() ;
    return win ;
}

void draw(WINDOW * win){

    wclear(win);

    box(win,0,0) ;
    mvwprintw(win, 0, 2," Snake ") ;
    mvwprintw(win, foodY, foodX, "*") ;
    mvwprintw(win, coordinateY, coordinateX, "*") ;
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
    if(keyStroke == 'q'){
        sDirection = quit ;
    }


    wrefresh(win) ;
}
/*
 * need to implaent the tail and
 * make the movment automatic in each draw phase
 */
void logic(){

    switch (sDirection){
        case moveUp: coordinateY-- ;
        break ;
        case moveDown: coordinateY++ ;
        break ;
        case moveLeft: coordinateX-- ;
        break ;
        case moveRight: coordinateX++;
        break ;
        case quit: gameOver = true;
            break;
    }

    if(coordinateX == foodX && coordinateY == foodY){
        pionts++ ;
        randomFood() ;
    }

    if(coordinateX > width || coordinateX < 0 || coordinateX > width || coordinateX < 0){
        gameOver = true ;
    }
}

void randomFood(){

    foodX = rand() % (width - 2) ;
    foodY = rand() % (height - 2) ;

    if(foodX == 0 || foodX == width || foodY == 0 || foodY == height){
        randomFood() ;
    }

}
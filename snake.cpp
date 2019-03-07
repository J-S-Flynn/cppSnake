#include <iostream>
#include <curses.h>

using namespace std ; 


//蛇　ゲーム　
//foray into game c++

enum snakeDirection {
    stop = 0,
    left,
    right,
    up,
    down, 
};

snakeDirection sDir ;

void welcomeScreen() ;
void game() ;  
void setUp() ; 
void draw() ; 
void input() ; 
void logic() ;

bool gameOver ; 
const int width = 50 ;
const int height = 15 ;

int coordnateX, coordinateY, foodX, foodY, pionts;

int main(){

    game() ; 
    
    return 0 ; 
}

void game(){

    initscr() ;
    welcomeScreen() ;
    setUp() ;

    while(!gameOver){

        draw() ;
        input() ;
        logic() ;
    }

    endwin() ;
}

void welcomeScreen(){

    refresh() ;

    cout << "\n\n\n\t\tWelcome to snake press enter to continue \r " << endl  ;

    getch() ;

}

void setUp(){

    gameOver = false ; 

    coordnateX = width / 2 ;
    coordinateY = height / 2  ; 

    foodX = rand() % width ;
    foodY = rand() % height ;  
    pionts = 0 ;
}

//void verticalBorder(int width){
//
//    for(int i = 0 ; i < width+1  ; i++){
//
//        cout << "#" ;
//    }
//    cout << endl ;
//}
//
//void horizontalBorder(int width, int height){
//
//    for(int i = 0 ; i < height ; i++){
//
//        for(int j = 0 ; j < width ; j++){
//
//            if((j == 0) || (j == width-1)){
//
//                cout << "#" ;
//            }
//            if(i == foodY && j == foodX){
//
//                cout << "0" ;
//            }else if(i == coordinateY && j == coordnateX ){
//
//                    cout << "*" ;
//            }else {
//                cout << " ";
//            }
//        }
//
//        cout << endl  ;
//    }
//
//}

void draw(){


    clear();

    WINDOW * win  = newwin(height, width, 5,5) ;

    refresh() ;

    box(win,0,0) ;
    mvwprintw(win, 0, 2," Snake ") ;

    wrefresh(win) ;

    getch();
}

void input(){


}

void logic(){
     
}
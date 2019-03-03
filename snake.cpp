#include <iostream>
 


using namespace std ; 

enum direction {
    left,
    right,
    up,
    down, 
};

void game() ;  
void setUp() ; 
void draw() ; 
void input() ; 
void logic() ;
void clearScreen() ;

bool gameOver ; 
const int width = 20 ; 
const int height = 20 ; 

int coordnateX, coordinateY, foodX, foodY, pionts;

int main(){

    game() ; 
    
    return 0 ; 
}

void game(){

    setUp();

    while(!gameOver){

        draw() ;
        input() ;
        logic() ;
    }
}

void setUp(){

    gameOver = false ; 
    coordnateX = width / 2 ; 
    coordinateY = height / 2  ; 

    foodX = rand() % width ;
    foodY = rand() % height ;  
    pionts = 0 ; 

}

void verticalBorder(int width){

    for(int i = 0 ; i < width ; i++){

        cout << "*" ; 
    }
    cout << endl ;
}

void horizontalBorder(int width, int height){

    for(int i = 0 ; i < height ; i++){

        for(int j = 0 ; j < width ; j++){
            
            if((j == 0) || (j == width - 1)){
                cout << "*" ;
            }
            else {
                cout << " " ;
            }
        }

        cout << endl ;
    }
}

void draw(){

    system("clear") ;
    verticalBorder(width) ; 
    horizontalBorder(width, height) ;
    verticalBorder(width) ; 
}

void input(){


}

void logic(){
     
}
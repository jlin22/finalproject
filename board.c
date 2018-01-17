#include "chess.h"



char*** startgame(){
  char*** board = malloc(sizeof(char**));
  return board;


}

void printboard(char***board){
  char** board2 = *board;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("%c ", board2[i][j]);
    }
    printf("\n");
  }  
}


void makemove(char* move, char*** board){
  
  

}

void main(){

}

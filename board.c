#include "chess.h"
#include <stdio.h>
#include <string.h>

struct board {char a[8][8];};


struct board* startgame(){
  struct board b = malloc(sizeof(struct board));
  struct board* c = &b;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      *c.a[i][j] = 'B';
    }
  }
  
  return c;


}

void printboard(char***board){
   for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("%c ", *board[i][j]);
    }
    printf("\n");
  }  
}


void makemove(char* move, char*** board){


}

void main(){
  char*** board = startgame();
  //printboard(board);
  return;
}

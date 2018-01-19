#include "chess.h"
#include <stdio.h>
#include <string.h>

struct board {char a[8][8];};


struct board* startgame(){
  struct board* b = malloc(sizeof(struct board));
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      (*b).a[i][j] = 'B';
    }
  }
  
  return b;


}

void changespot(struct board* board, int i, int j, char n){
  (*board).a[i][j] = n;
}

void printboard(struct board* board){
   for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("%c ", (*board).a[i][j]);
    }
    printf("\n");
  }  
}


void main(){
  struct board* board = startgame();
  changespot(board, 4, 4, 'C');
  printboard(board);
  return;
}

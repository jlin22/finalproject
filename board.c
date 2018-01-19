#include "chess.h"
#include <stdio.h>
#include <string.h>

struct board {char a[8][8];};


struct board* startgame(){
  struct board* b = malloc(sizeof(struct board));


  (*b).a[0][0] = 'r';
  (*b).a[0][1] = 'n';
  (*b).a[0][2] = 'b';
  (*b).a[0][3] = 'q';
  (*b).a[0][4] = 'k';
  (*b).a[0][5] = 'b';
  (*b).a[0][6] = 'n';
  (*b).a[0][7] = 'r';

  
  (*b).a[7][0] = 'R';
  (*b).a[7][1] = 'N';
  (*b).a[7][2] = 'B';
  (*b).a[7][3] = 'Q';
  (*b).a[7][4] = 'K';
  (*b).a[7][5] = 'B';
  (*b).a[7][6] = 'N';
  (*b).a[7][7] = 'R';

  for(int n = 0; n < 8; n++){
    (*b).a[1][n] = 'p';
    (*b).a[6][n] = 'P';
  }

  for(int i = 2; i < 6; i++){
    for(int j = 0; j < 8; j++){
      (*b).a[i][j] = 'O';
    }
  }

  
  return b;


}

void movepiece(struct board* board, int i, int j, int m, int n){
  char a = (*board).a[i][j];
  (*board).a[i][j] = 'O';
  (*board).a[m][n] = a;
}

int movepieceWrap(struct board* board, int i, int j, int m, int n){
  char a = (*board).a[i][j];
  if(a == 'O'){
    return -1;
  }
  
  if(a == 'P'){

    if(m == i - 1 && n == j && (*board).a[i - 1][j] == 'O'){ //move one
      movepiece(board, i, j, m, n);
      return 0;
    }
       
    if(m == i - 2 && n == j && i == 6 && (*board).a[i - 1][j] == 'O' && (*board).a[i - 2][j] == 'O'){ //move two
      movepiece(board, i, j, m, n);
      return 0;
    }
    
    if(m == i - 1 && (n == j - 1 || n == j + 1) && (*board).a[m][n] != 'O'){ //capture
      movepiece(board, i, j, m, n);
      return 0;
    }

    return -1;
    
  }











  return -1;
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
  printboard(board);
  while(1){

    char line[4];
    fgets(line, 10, stdin);
    int i = line[0] - '0';
    int j = line[1] - '0';
    int m = line[2] - '0';
    int n = line[3] - '0';

    movepieceWrap(board, i, j, m, n);
    printboard(board);
      
   
  }
  return;
}

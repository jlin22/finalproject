#include "chess.c"
void addkings(struct board * board, int i, int j, char***movelist);
void addqueens(struct board * board, int i, int j, char***movelist);
void addbishops(struct board * board, int i, int j, char***movelist);
void addknights(struct board * board, int i, int j, char***movelist);
void addrooks(struct board * board, int i, int j, char***movelist);
void addpawns(struct board * board, int i, int j, char***movelist);
char *** findallmoves(struct board * board);
int main(){
}

char *** findallmoves(struct board * board){
  char *** movelist = malloc(sizeof(char[140][4]));
  int index = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      char p = (*board).a[i][j];
      if (p = 'k'/* && (*board).b == 1*/){
	addkings(board, i, j, movelist);
      }
      if (p = 'q' /*&& (*board).b== 1*/){
	addqueens(board, i, j, movelist);
      }
      if (p = 'b' /*&& (*board).b== 1*/){
	addbishops(board, i, j, movelist);
      }
      if (p = 'n'/* && (*board).b== 1*/){
	addknights(board, i, j, movelist);
      }
      if (p = 'r' /*&& (*board).b== 1*/){
	addrooks(board, i, j, movelist);
      }
      if (p = 'p' /*&& (*board).b== 1*/){
	addpawns(board, i, j, movelist);
      }
    }
  }
}


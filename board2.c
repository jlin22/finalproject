#include "chess.c"
//if > 90, its friendly
// if < 90, its enemy, so moveable

char * intstring(int a, int b, int c, int d){
  char *x = malloc(sizeof(char*));
  x[0] = a+'0';
  x[1] = b+'0';
  x[2] = c+'0';
  x[3] = d+'0';  
  return x;
}
  
void addkings(struct board * board, int m, int n,int *i, char***ml){
  if (m < 7 &&(*board).a[m+1][n] == 'O' ||(*board).a[m+1][n]<90){
    (*ml)[*i] = intstring(m,n,m+1,n);
    (*i)++;
  }
  if (m > 0 &&(*board).a[m-1][n] == 'O'||(*board).a[m-1][n]<90){
      (*ml)[*i] = intstring(m,n,m-1,n);
      (*i)++;
  }
  if (m < 7 && n < 7 && (*board).a[m+1][n+1] == 'O' || (*board).a[m+1][n+1] <90 ){
    (*ml)[*i] = intstring(m,n,m+1,n+1);
    (*i)++;
  }
  if (m < 7 && n > 0 &&(*board).a[m+1][n-1] == 'O' ||(*board).a[m+1][n-1] < 90){
    (*ml)[*i] = intstring(m,n,m+1,n-1);
    (*i)++;
  }
  if (m > 0 && n > 0 &&(*board).a[m-1][n-1] == 'O'||(*board).a[m-1][n-1]<90){
    (*ml)[*i] = intstring(m,n,m-1,n-1);
    (*i)++;
  }
  if (m > 0 && n < 7 &&(*board).a[m-1][n+1] == 'O'||(*board).a[m-1][n+1]<90){
    (*ml)[*i] = intstring(m,n,m-1,n+1);
   (*i)++;

  }
  if (n > 0 &&(*board).a[m][n-1] == 'O' || (*board).a[m][n-1] <90){
    (*ml)[*i] = intstring(m,n,m,n-1);
    (*i)++;
  }
  if (n < 7 &&(*board).a[m][n+1] == 'O'|| (*board).a[m][n+1]<90){
    (*ml)[*i] = intstring(m,n,m,n+1);
  (*i)++;

  }
}

void addbishops(struct board * board, int m, int n,int *i , char***ml){
  int in = 0;
  while (m + in < 7 && n + in < 7 && (*board).a[m+in][n+in] == 'O' || (*board).a[m+in][n+in] <90){
    (*ml)[*i] = intstring(m,n,m+in,n+in);
     (*i)++;
    if ((*board).a[m+in][n+in] < 90){
      in = 8;
    }
    in++;
  }
  in = 0;
  while (m - in > 0 && n + in < 7 && (*board).a[m-in][n+in] == 'O' || (*board).a[m-in][n+in] <90){
    (*ml)[*i] = intstring(m,n,m-in,n+in);
    (*i)++;
    if ((*board).a[m-in][n+in] < 90){
      in = 8;
    }
    in++; 
  }
  in = 0;
  while (m - in > 0 && n - in > 0  && (*board).a[m-in][n-in] == 'O' || (*board).a[m-in][n-in] <90){
    (*ml)[*i] = intstring(m,n,m-in,n-in);
    (*i)++;
    if ((*board).a[m-in][n-in] < 90){
      in = 8;
    }
    in++; 
  }
   in = 0;
  while (m + in < 7 && n - in > 0 && (*board).a[m+in][n-in] == 'O' || (*board).a[m+in][n-in] <90){
    (*ml)[*i] = intstring(m,n,m+in,n-in);
    (*i)++;
    if ((*board).a[m+in][n-in] < 90){
      in = 8;
    }
    in++; 
  } 
 
}
void addknights(struct board * board, int m, int n,int *i, char***ml){
   if (m < 6 && n < 7 && (*board).a[m+2][n+1]== 'O' ||(*board).a[m+2][n+1] <90){
    (*ml)[*i] = intstring(m,n,m+2,n+1);
    (*i)++;

  }
   if (m < 7 && n < 6 && (*board).a[m+1][n+2] == 'O'||(*board).a[m+1][n+2]<90){
    (*ml)[*i] = intstring(m,n,m+1,n+2);
    (*i)++;

  }
   if (m < 6 && n > 0  && (*board).a[m+2][n-1] == 'O'||(*board).a[m+2][n-1]<90){
    (*ml)[*i] = intstring(m,n,m+2,n-1);
   (*i)++;

  }
   if (m < 7 && n >1 && (*board).a[m+1][n-2] == 'O'||(*board).a[m+1][n-2]<90){
    (*ml)[*i] = intstring(m,n,m+1,n-2);
    (*i)++;

  }
   if (m >0 && n < 6 && (*board).a[m-1][n+2] == 'O'|| (*board).a[m-1][n+2]<90){
    (*ml)[*i] = intstring(m,n,m-1,n+2);
    (*i)++;
   }
   if (m>1 && n < 7 && (*board).a[m-2][n+1] == 'O'|| (*board).a[m-2][n+1]<90){
     (*ml)[*i] = intstring(m,n,m-2,n+1);
    (*i)++;
   }
   if (m > 0 && n > 1  && (*board).a[m-1][n-2] == 'O'||(*board).a[m-1][n-2]<90){
    (*ml)[*i] = intstring(m,n,m-1,n-2);
     (*i)++;
   }
   if (m > 1 && n > 0 && (*board).a[m-2][n-1] == 'O'||(*board).a[m-1][n-2]<90){
    (*ml)[*i] = intstring(m,n,m-2,n-1);
     (*i)++;
  }
  
}
void addrooks(struct board * board, int m, int n,int *i , char***ml){
  int in = 0;
  while (m + in < 7 && (*board).a[m+in][n] == 'O'|| (*board).a[m+in][n] < 90){
    (*ml)[*i] = intstring(m,n,m+in,n);
    (*i)++;
    if ((*board).a[m+in][n] <90){
      in = 8;
    }
    in++; 
  }
  in = 0;
  while (m - in > 0 &&(*board).a[m-in][n] == 'O'|| (*board).a[m-in][n] < 90){
    (*ml)[*i] = intstring(m,n,m-in,n);
   (*i)++;
     if ((*board).a[m-in][n] <90){
      in = 8;
    }
    in++; 
  }
  in = 0;
  while (n + in <7 &&(*board).a[m][n+in] == 'O'|| (*board).a[m][n+in] < 90){
    (*ml)[*i] = intstring(m,n,m,n+in);
     (*i)++;
     if ((*board).a[m][n+in] <90){
      in = 8;
    }
    in++; 
  }
   in = 0;
  while (n - in > 0&&(*board).a[m][n-in] == 'O'|| (*board).a[m][n-in] < 90){
    (*ml)[*i] = intstring(m,n,m,n-in);
     (*i)++;
     if ((*board).a[m][n-in] <90){
      in = 8;
    }
    in++; 
  } 
}
void addpawns(struct board * board, int m, int n,int *i, char***ml){
  if (m < 7 && (*board).a[m+1][n] == 'O'){
    (*ml)[*i] = intstring(m,n,m+1,n);
 (*i)++;  }
  if (m < 7 && n > 0&& (*board).a[m+1][n-1] <90){
      (*ml)[*i] = intstring(m,n,m+1,n-1);
       (*i)++;
    }
   if (m < 7 && n < 7&& (*board).a[m+1][n+1] <90){
      (*ml)[*i] = intstring(m,n,m+1,n+1);
      (*i)++;
    }
  if (m == 1 && (*board).a[m+2][n] == 'O'){
    (*ml)[*i] = intstring(m,n,m+2,n);
     (*i)++;
  }
  //case for nonfriends
}
void addqueens(struct board * board, int m, int n,int *i, char***ml){
  addrooks(board, m, n, i, ml);
  addbishops(board,m,n,i,ml);
  
}

char *** findallmoves(struct board * board){
  char *** movelist = malloc(sizeof(char[140][4]));
  int * index ;
  (*index) = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      char p = (*board).a[i][j];
      if (p = 'k'/* && (*board).b == 1*/){
	addkings(board, i, j,index, movelist);
      }
      if (p = 'q' /*&& (*board).b== 1*/){
	addqueens(board, i, j,index, movelist);
      }
      if (p = 'b' /*&& (*board).b== 1*/){
	addbishops(board, i, j, index,movelist);
      }
      if (p = 'n'/* && (*board).b== 1*/){
	addknights(board, i, j, index,movelist);
      }
      if (p = 'r' /*&& (*board).b== 1*/){
	addrooks(board, i, j, index,movelist);
      }
      if (p = 'p' /*&& (*board).b== 1*/){
	addpawns(board, i, j, index, movelist);
      }
    }
  }
  return movelist;
}

int main(){
  }

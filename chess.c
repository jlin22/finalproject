#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>


struct board {
  char a[8][8];
  int b;
  char storage[8][8];
};


struct board* startgame(){
  struct board* b = malloc(sizeof(struct board));
  (*b).b = 1;

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

  //MAKES PAWNS
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
  (*board).b *= -1;
}

int movepieceWrap(struct board* board, int i, int j, int m, int n){
  char a = (*board).a[i][j];
  if(a == 'O'){
    return -1;
  }
  //KING
  if(a == 'K'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( ((i - m) * (i - m) == 0 || (i - m) * (i - m) == 1) && ((j - n) * (j - n) == 0 || (j - n) * (j - n) == 1)){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }    
  }
  
  if(a == 'k'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( ((i - m) * (i - m) == 0 || (i - m) * (i - m) == 1) && ((j - n) * (j - n) == 0 || (j - n) * (j - n) == 1)){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }    
  }


  

  //Pawns///////////////////////////////////////////////////////////////////
  if(a == 'P'){

    if(m == i - 1 && n == j && (*board).a[i - 1][j] == 'O'){ //move one
      movepiece(board, i, j, m, n);
      if(m == 0){
	(*board).a[m][n] = 'Q';
      }
      return 0;
    }
       
    if(m == i - 2 && n == j && i == 6 && (*board).a[i - 1][j] == 'O' && (*board).a[i - 2][j] == 'O'){ //move two
      movepiece(board, i, j, m, n);
      return 0;
    }
    
    if(m == i - 1 && (n == j - 1 || n == j + 1) && (*board).a[m][n] != 'O' && (*board).a[m][n] > 90){ //capture
      movepiece(board, i, j, m, n);
      if(m == 0){
	(*board).a[m][n] = 'Q';
      }
      return 0;
    }

    return -1;
    
  }

  
  if(a == 'p'){

    if(m == i + 1 && n == j && (*board).a[i + 1][j] == 'O'){ //move one
      movepiece(board, i, j, m, n);
      if(m == 7){
	(*board).a[m][n] = 'q';
      }
      return 0;
    }
       
    if(m == i + 2 && n == j && i == 1 && (*board).a[i + 1][j] == 'O' && (*board).a[i + 2][j] == 'O'){ //move two
      movepiece(board, i, j, m, n);
      return 0;
    }
    
    if(m == i + 1 && (n == j - 1 || n == j + 1) && (*board).a[m][n] != 'O' && (*board).a[m][n] < 90){ //capture
      movepiece(board, i, j, m, n);
      if(m == 7){
	(*board).a[m][n] = 'q';
      }
      return 0;
    }

    return -1;
    
  }


  ////////////////////////////////////////////////////////////////////////////
  //Rooks//////////////////////////////////////////////////////////////////////


  if(a == 'R'){
   
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    
    if(i == m){ //horizontal move
      if( j < n ){ //move to the right
	int yes = 0;
	
	for(int count = j + 1; count < n; count++){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      else if( j > n ){ //move to the left
	int yes = 0;
	for(int count = j - 1; count > n; count--){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }



    }

    if(j == n){ //vertical move



      if(i < m){ //downward move
	int yes = 0;

	for(int count = i + 1; count < m; count++){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }




      else if(i > m){ //upward move
	int yes = 0;

	for(int count = i - 1; count > m; count--){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      



    }





    else{
      return -1;
    }
  }


  if(a == 'r'){
   
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    
    if(i == m){ //horizontal move
      if( j < n ){ //move to the right
	int yes = 0;
	
	for(int count = j + 1; count < n; count++){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      else if( j > n ){ //move to the left
	int yes = 0;
	for(int count = j - 1; count > n; count--){
	  if((*board).a[i][count] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }



    }

    if(j == n){ //vertical move



      if(i < m){ //downward move
	int yes = 0;

	for(int count = i + 1; count < m; count++){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }




      else if(i > m){ //upward move
	int yes = 0;

	for(int count = i - 1; count > m; count--){
	  if( (*board).a[count][j] != 'O'){
	    yes = -1;
	  }
	}

	if(yes == 0){
	  movepiece(board, i, j, m, n);
	  return 0;
	}
	else{
	  return -1;
	}
      }

      



    }





    else{
      return -1;
    }
  }
  
  //////////////////////////////////////////////////////////////////////////////////////
  //KNIGHT
  
  if(a == 'N'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( (i - m == 2 || i - m == -2) && (j - n == 1 || j - n == -1) ){
      movepiece(board, i, j, m, n);
      return 0;
    }

    if( (i - m == 1 || i - m == -1) && (j - n == 2 || j - n == -2) ){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
  }
  if(a == 'n'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( (i - m == 2 || i - m == -2) && (j - n == 1 || j - n == -1) ){
      movepiece(board, i, j, m, n);
      return 0;
    }

    if( (i - m == 1 || i - m == -1) && (j - n == 2 || j - n == -2) ){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
  }

  
  
  //////////////////////////////////////////////////////////////////////////////////////
  //BISHOP

  if(a == 'B'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( !( (i - m == j - n) || (i - m == n - j)) ){ //valid moves
      return -1;
    }

    int hor = 0;
    int ver = 0;
    if(i < m){ //going down
      ver = 1;
    }
    else{ //going up
      ver = -1;
    }

    if(j < n){ //going to the right
      hor = 1;
    }
    else{ //going to the left
      hor = -1;
    }

    int ci = i + ver;
    int cj = j + hor;
    int yes = 0;
    while(ci != m){
      if((*board).a[ci][cj] != 'O'){
	yes = -1;
      }
      ci += ver;
      cj += hor;
    }

    if(yes == 0){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
    

  }
  
  if(a == 'b'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    if( !( (i - m == j - n) || (i - m == n - j)) ){ //valid moves
      return -1;
    }

    int hor = 0;
    int ver = 0;
    if(i < m){ //going down
      ver = 1;
    }
    else{ //going up
      ver = -1;
    }

    if(j < n){ //going to the right
      hor = 1;
    }
    else{ //going to the left
      hor = -1;
    }

    int ci = i + ver;
    int cj = j + hor;
    int yes = 0;
    while(ci != m){
      if((*board).a[ci][cj] != 'O'){
	yes = -1;
      }
      ci += ver;
      cj += hor;
    }

    if(yes == 0){
      movepiece(board, i, j, m, n);
      return 0;
    }
    else{
      return -1;
    }
    

  }

  //////////////////////////////////////////////////////////////////////////////////////
  //QUEEN

  if( a == 'Q'){
    if((*board).a[m][n] < 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    //like a bishop
    if((i - m == j - n) || (i - m == n - j)){
      int hor = 0;
      int ver = 0;
      if(i < m){ //going down
	ver = 1;
      }
      else{ //going up
	ver = -1;
      }
      
      if(j < n){ //going to the right
	hor = 1;
      }
      else{ //going to the left
	hor = -1;
      }
      
      int ci = i + ver;
      int cj = j + hor;
      int yes = 0;
      while(ci != m){
	if((*board).a[ci][cj] != 'O'){
	  yes = -1;
	}
	ci += ver;
	cj += hor;
      }
      
      if(yes == 0){
	movepiece(board, i, j, m, n);
	return 0;
      }
      else{
	return -1;
      }    
    }
    //like a rook
    if(i == m || j == n){ 
      if(i == m){ //horizontal move
	if( j < n ){ //move to the right
	  int yes = 0;
	  
	  for(int count = j + 1; count < n; count++){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	else if( j > n ){ //move to the left
	  int yes = 0;
	  for(int count = j - 1; count > n; count--){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
      }
      
      if(j == n){ //vertical move
	
	
	
	if(i < m){ //downward move
	  int yes = 0;
	  
	  for(int count = i + 1; count < m; count++){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
	
	else if(i > m){ //upward move
	  int yes = 0;
	  
	  for(int count = i - 1; count > m; count--){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}	
      }
      
    }
    else{
      return -1;
    }   
  }

  if( a == 'q'){
    if((*board).a[m][n] > 90 && (*board).a[m][n] != 'O'){ //friendly piece
      return -1;
    }

    //like a bishop
    if((i - m == j - n) || (i - m == n - j)){
      int hor = 0;
      int ver = 0;
      if(i < m){ //going down
	ver = 1;
      }
      else{ //going up
	ver = -1;
      }
      
      if(j < n){ //going to the right
	hor = 1;
      }
      else{ //going to the left
	hor = -1;
      }
      
      int ci = i + ver;
      int cj = j + hor;
      int yes = 0;
      while(ci != m){
	if((*board).a[ci][cj] != 'O'){
	  yes = -1;
	}
	ci += ver;
	cj += hor;
      }
      
      if(yes == 0){
	movepiece(board, i, j, m, n);
	return 0;
      }
      else{
	return -1;
      }    
    }
    //like a rook
    if(i == m || j == n){ 
      if(i == m){ //horizontal move
	if( j < n ){ //move to the right
	  int yes = 0;
	  
	  for(int count = j + 1; count < n; count++){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	else if( j > n ){ //move to the left
	  int yes = 0;
	  for(int count = j - 1; count > n; count--){
	    if((*board).a[i][count] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
      }
      
      if(j == n){ //vertical move
	
	
	
	if(i < m){ //downward move
	  int yes = 0;
	  
	  for(int count = i + 1; count < m; count++){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}
	
	
	
	
	else if(i > m){ //upward move
	  int yes = 0;
	  
	  for(int count = i - 1; count > m; count--){
	    if( (*board).a[count][j] != 'O'){
	      yes = -1;
	    }
	  }
	  
	  if(yes == 0){
	    movepiece(board, i, j, m, n);
	    return 0;
	  }
	  else{
	    return -1;
	  }
	}	
      }
      
    }
    else{
      return -1;
    }   
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
/*char * boardstring(struct board* board){
  //puts boardstring in "string"
  int fd = open("string", O_WRONLY|O_CREAT, 0600);
  int in= dup(1);
  dup2(fd, 1);
  printboard(board);
  dup2(in, 1);
  close(fd);
  int file = open("string", O_RDONLY, 0600);
  char * buffer;
  read(file, buffer, 256);
  return buffer;
  }*/

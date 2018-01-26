#include "chess.c"





void main(){
  /*printf("insert command:");
  char command[256];
  fgets(command, sizeof(command), stdin);
  command[strlen(command)-1] = 0;
  if(strcmp(command, "ai")==0){
    char name[256];
    printf("choose file to write into:");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) -1] = 0;
    printf("initializing game\n");
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
      //write game states
      remove(name);
      int file = open(name, O_CREAT | O_WRONLY, 0600);
      write(file, board,4*8*8);
      
   
    }
  }
  else if (strcmp(command, "load")==0){*/
  printf("file to load:");
  char name[256];
  fgets(name, sizeof(name), stdin);
  name[strlen(name)-1]=0;
  int file = open(name, O_RDWR, 0600);
  if( file == -1){
    printf("file does not exist\n");
    exit(1);
  }
  struct board* b = malloc(sizeof(struct board));
  read(file, b,4*8*8);
  close(file);
  printboard(b);
  while(1){
    
    char line[4];
    fgets(line, 10, stdin);
    int i = line[0] - '0';
    int j = line[1] - '0';
    int m = line[2] - '0';
    int n = line[3] - '0';
    
    movepieceWrap(b, i, j, m, n);
    printboard(b);
    //write game states
    remove(name);
    int file = open(name, O_CREAT | O_WRONLY, 0600);
    write(file, b,4*8*8);
    
  }
  /* else{
    printf("invalid command");
    }*/
  return;
}

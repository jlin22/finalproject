#include "chess.h"
int main(){
  char command[256];
  menu(command);
  interpret(command);
}
void interpret(char *command){
  command[strlen(command)-1] = 0;
  if (strcmp(command,"ai")==0){
    ai();
  }
  else if (strcmp(command,"multiplayer")==0){
    multiplayer();
  }
  else if (strcmp(command,"load")==0){
    load();
  }
  else{
    printf("invalid arguments\n");
  }
}
void menu(char *command){
  printf("chess\n");
  printf("enter command('ai', 'multiplayer', or 'load')\n");
  fgets(command, sizeof(command), stdin);
}
void ai(){
  /*if (fork()!=0){
    execlp("clear", "clear", NULL);
  }
  else{
    printf("loading game with ai\n");
    }*/
}
void multiplayer(){
  printf("loading game with another player\n");
}
void load(){
  printf("loading game state\n");
}

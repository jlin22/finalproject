#include "chess.h"


int main(){
  char command[256];
  menu(command);
  interpret(command);
}
//menu commands
void interpret(char *command){
  //does stuff based on whether "ai", "multiplayer", or "load" is inputted
  command[strlen(command)-1] = 0;
  if (strcmp(command,"ai")==0){
    ai();
  }
  /*else if (strcmp(command,"multiplayer")==0){
   multiplayer();
   }*/
  else if (strcmp(command,"load")==0){
    load();
  }
  else{
    printf("invalid arguments\n");
  }
}

void menu(char *command){
  //prints out beginning statements and waits for input
  printf("chess\n");
  printf("enter command('ai', 'multiplayer', or 'load')\n");
  fgets(command, sizeof(command), stdin);
}
void ai(){
  printf("loading game with ai\n");
}
void multiplayer(){
  printf("loading game with another player\n");
}
void load(){
  printf("loading game state\n");
}
void save(){
}



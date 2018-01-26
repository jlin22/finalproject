#include "networking.h"
#include "chess.c"
void subserver(int from_client, struct board* board, int turn, int player[2]);
#define KEY1 1901
#define KEY2 1961

int main() {
  //player 0 is lowercase(the one on top)
  //player 1 is uppercase(the one on bottom)
  int player[2];
  int turn = 0;
  //turn starts at 0 (player 1's turn)
  //turn alternates between 0 and 1
  struct board* board = startgame();
  int listen_socket;
  int client_socket;
  int f;
  int subserver_count = 0;
  char buffer[BUFFER_SIZE];

  //set of file descriptors to read from
  fd_set read_fds;

  listen_socket = server_setup();
  printboard(board);
  printf("it is player %d's turn\n", turn);
  while (1) {
    //select() modifies read_fds
    //we must reset it at each iteration
    FD_ZERO(&read_fds); //0 out fd set
    FD_SET(STDIN_FILENO, &read_fds); //add stdin to fd set
    FD_SET(listen_socket, &read_fds); //add socket to fd set

    //select will block until either fd is ready
    select(listen_socket + 1, &read_fds, NULL, NULL, NULL);
  
    //if listen_socket triggered select
    if (FD_ISSET(listen_socket, &read_fds)) {
     client_socket = server_connect(listen_socket);

     f = fork();
     if (f == 0){
        if(subserver_count<2){
	 player[subserver_count] = getpid();
	 //printf("count : %d, pid : %d", subserver_count, getpid());
       }
	subserver(client_socket, board, turn, player);

     }
     else{
    
       subserver_count++;
      
       close(client_socket);
     }
    }//end listen_socket select

    //if stdin triggered select
    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
      //if you don't read from stdin, it will continue to trigger select()
      fgets(buffer, sizeof(buffer), stdin);
      printf("[server] subserver count: %d\n", subserver_count);
    }//end stdin select
  }
}

void subserver(int client_socket, struct board* board, int turn, int player[2]) {
  char buffer[BUFFER_SIZE];

  //for testing client select statement
  strncpy(buffer, "hello client", sizeof(buffer));
  write(client_socket, buffer, sizeof(buffer));

  while (read(client_socket, buffer, sizeof(buffer))) {
    printf("[subserver %d] received: [%s]\n", getpid(), buffer);
    if (strlen(buffer) != 4
	|| (buffer[0] > '7' || buffer[0] < '0')
	|| (buffer[1] > '7' || buffer[1] < '0')
	|| (buffer[2] > '7' || buffer[2] < '0')
	|| (buffer[3] > '7' || buffer[3] < '0')){
      strcat(buffer, " is an invalid command");
    }
    else{
      if (player[turn] = getpid()){
	strcat(buffer, " executed ");
	/*	char t[1];
	t[0] = '0' + turn;
	strcat(buffer, t);*/
	movepieceWrap(board, buffer[0]-'0', buffer[1]-'0', buffer[2]-'0', buffer[3]-'0');
	turn = (turn + 1) % 2;
      }
      printboard(board);
    }
    printf("it is player %d's turn\n", turn);
    
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  close(client_socket);
  exit(0);
}


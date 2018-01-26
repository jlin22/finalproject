#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
  int * x = malloc(sizeof(int*));
  *x = 2;
  printf("%d\n", *x);

  char *** list = malloc(sizeof(char[10][10]));
  (*list)[2][2] = 'a';
  printf("%c\n", (*list)[*x][2]);


}

#include <stdio.h>




void print_board(char* board, int* time) {
  int x,y;
  printf("---time: %d----\n", *time);
  for(y = 0; y < 4; y++) {
    for(x = 0; x < 4; x++) {
      switch(board[x+4*y]) {
      case 0:
	printf("#");
	break;
      case 1:
	printf("o");
	break;
      case 2:
	printf("x");
	break;
      }
    }
    printf("\n");
  }
  (*time)++;
}

//8 direction. right:0, up-right:1, up:2, up-left:3, left:4, down-left:5, down:6, down-rignt:7.

int counter(char* board, int base_x, int base_y, char base_color, int* count) {
  int x,y,dx,dy,i,count_temp,flag;
  if(board[base_x+4*base_y] != 0) return 0;
  flag = 0;
  for(i = 0; i < 8; i++) {
    switch(i) {
    case 0:
      dx = 1; dy = 0; break;
    case 1:
      dx = 1; dy = 1; break;
    case 2:
      dx = 0; dy = 1; break;
    case 3:
      dx = -1; dy = 1; break;
    case 4:
      dx = -1; dy = 0; break;
    case 5:
      dx = -1; dy = -1; break;
    case 6:
      dx = 0; dy = -1; break;
    case 7:
      dx = 1; dy = -1; break;
    }
    count[i] = 0;
    count_temp = 0;
    x = base_x + dx;
    y = base_y + dy;
    while(x>=0 && x<4 && y>=0 && y<4) {
      if(board[x+4*y] == 0) {
	break;
      }
      else if(board[x+4*y] != base_color) {
	count_temp++;
	x += dx;
	y += dy;
      }
      else if(board[x+4*y] == base_color) {
	if(count_temp > 0) {
	  flag = 1;
	  count[i] = count_temp;
	}
	break;
      }
    }
  }
  return flag;
}

void reverse(char* board, int base_x, int base_y, char base_color, int* count) {
  int x,y,dx,dy,i,t;
  for(i = 0; i < 8; i++) {
    if(count[i] > 0) {
      switch(i) {
      case 0:
	dx = 1; dy = 0; break;
      case 1:
	dx = 1; dy = 1; break;
      case 2:
	dx = 0; dy = 1; break;
      case 3:
	dx = -1; dy = 1; break;
      case 4:
	dx = -1; dy = 0; break;
      case 5:
	dx = -1; dy = -1; break;
      case 6:
	dx = 0; dy = -1; break;
      case 7:
	dx = 1; dy = -1; break;
      }
      x = base_x;
      y = base_y;
      for(t = 0; t < count[i]; t++) {
	x += dx;
	y += dy;
	board[x+4*y] = base_color;
      }
    }
  }
}

//none 0, white 1, black 2.
int main() {
  int i,t;
  char board[16];
  int x,y;
  int time;
  int count[8];
  int color;
  
  //initialize
  for(i = 0; i < 16; i++) board[i] = 0;
  board[5] = 1;
  board[6] = 2;
  board[9] = 2;
  board[10] = 1;
  time = 0;

  print_board(board,&time);
  while(time < 13) {
    color = 2-time%2;
    scanf("%d %d",&x,&y);
    if(counter(board,x,y,color,count)) {
      board[x+4*y] = color;
      reverse(board,x,y,color,count);
      print_board(board,&time);
    }
    else{
      printf("please retry.\n");
    }
  }
  
  t = 0;
  for(i = 0; i < 16; i++) {
    t += board[i];  
  }
  if(t-16 < 8) printf("white win\n");
  else if(t-16 == 8) printf("draw\n");
  else printf("black win\n");
  return 0;
}

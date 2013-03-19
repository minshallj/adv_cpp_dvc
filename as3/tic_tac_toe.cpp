// tic_tac_toe.c
// jacob minshall

// plays a game of tic tac toe
#include <iostream>
#define LENGTH 3
using namespace std;

// function prototypes
void display(const char board[][LENGTH]);
void input(char board[][LENGTH], char player);
int board_check(const char board[][LENGTH], char player);

int main()
{
  char p1 = 'X', p2 = 'O', board[LENGTH][LENGTH];
  int winner;

  for(int i = 0; i < LENGTH; i++)
    for(int j = 0; j < LENGTH; j++)
      board[i][j] = '_';

  int count = 0;
  while((winner = board_check(board, count % 2 != 0 ? p1 : p2)) == 0) {
    display(board);
    // increments count after checking for value
    input(board, (count++ % 2 == 0 ? p1 : p2));
  }
  display(board);

  switch(winner){
      case -1:
          cout << "The game was a tie" << endl;
          break;
      default:
          cout << "Congratulations player " << winner << "!!!" << endl;
  }
}

void display(const char board[][LENGTH])
{
  for(int i = 0; i < LENGTH; i++){
    for(int j = 0; j < LENGTH; j++)
      cout << board[i][j];
    cout << endl;
  }
}

void input(char board[][LENGTH], char player)
{
  int spot = -1;

  //checks if spot is free before moving on
  while (spot == -1){
    cout << "Please make a move player " << player << " with 1-9: ";
    cin >> spot;
    if (board[(spot-1) / LENGTH][(spot-1) % LENGTH] != '_')
      spot = -1;
  }
  // to index properley must subtract, 9 should be 2,2 which is
  // 8/3 && 8%3 respectivley
  spot--;

  board[spot/LENGTH][spot%LENGTH] = player;
}

int board_check(const char board[][LENGTH], char player)
{
  //top row
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player)
      return player == 'X' ? 1 : 2; // returns player number
  //middle row horizontaly
  if(board[1][0] == player && board[1][1] == player && board[1][2] == player)
      return player == 'X' ? 1 : 2;
  //bottom row
  if(board[2][0] == player && board[2][1] == player && board[2][2] == player)
      return player == 'X' ? 1 : 2;
  //left row
  if(board[0][0] == player && board[1][0] == player && board[2][0] == player)
      return player == 'X' ? 1 : 2;
  //middle verticaly
  if(board[0][1] == player && board[1][1] == player && board[2][1] == player)
      return player == 'X' ? 1 : 2;
  //right row
  if(board[0][2] == player && board[1][2] == player && board[2][2] == player)
      return player == 'X' ? 1 : 2;
  //diagonal
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
      return player == 'X' ? 1 : 2;
  if(board[2][0] == player && board[1][1] == player && board[0][2] == player)
      return player == 'X' ? 1 : 2;

  // check for full board
  int full = 0;
  for(int i = 0; i < LENGTH; i++)
      for(int j = 0; j < LENGTH; j++)
          if(board[i][j] != '_')
             full++;
  if(full == 9)
      return -1;

  return 0;
}

// Paul and Neer
// 2D Array Game
// 2/19/25
// Alblas

#include <iostream>
using namespace std;

void fillBoard(char (*board)[5])
{
  // randomly fill in board with 5 ships
  for (int i = 0; i < 4; i++)
  {
    int x = rand() % 5;
    int y = rand() % 5;
    if (!board[x][y] == 's')
    {
      board[x][y] = 's';
    }
    else
    {
      i--;
    }
  }
}
int main()
{
  char board[5][5];
  char hit = 'x';
  char miss = 'o';

  // cout << ".______        ___    .___________.___________. __       _______     _______. __    __   __  .______   ";
  // cout << "|   _  \\     /   \\  |           |           ||  |     |   ____|   /       ||  |  |  | |  | |   _  \\  ";
  // cout << "|  |_)  |    /  ^  \\ `---|  |----`---|  |----`|  |     |  |__     |   (----`|  |__|  | |  | |  |_)   | ";
  // cout << "|   _  <    /  /_\\ \\    |  |        |  |     |  |     |   __|     \\   \\  |      __  |  | |  | ___/  ";
  // cout << "|  |_)  |  /  _____  \\   |  |        |  |     |  `----.|  |____.----)   |   |  |  |  | |  | |  |      ";
  // cout << "|______/  /__/    \\__\\  |__|        |__|     |_______||_______|_______/    |__|  |__| |__| | _|      ";
  // cout << "──────────────────────────────────────────────────────────────────────────────────────────────────";

  char aiboard[5][5];
  char playerboard[5][5];
  fillBoard(aiboard);

  int choice = 0;

  while (!(choice == 1 || choice == 2))
  {
    cout
        << "Do you want to \n1. manually assign your ships\n2. randomly generate the placement" << endl;
    int choice;
    cin >> choice;
  }
  switch (choice)
  {
  case 1:
    for (int i = 0; i < 4; i++)
    {
      cout << "Enter the x and y coordinates for ship " << i + 1 << endl;
      int x, y;
      cin >> x >> y;

      if (playerboard[x][y] == 's')
      {
        cout << "you already have a ship there" << endl;
        i--;
      }
      else
      {
        playerboard[x][y] = 's';
      }
    }
    break;
  case 2:
    fillBoard(playerboard);
    break;
  default:
    cout << "thats not an option megatron";
    break;
  }
  return 0;
}
// Paul and Neer
// 2D Array Game
// 2/19/25
// Alblas

#include <iostream>
#include <ctime>
#include "main.h"

using namespace std;

int main()
{
  srand(time(0));
  char board[5][5];
  const char hit = 'x';
  const char miss = 'o';

  cout << ".______        ___    .___________.___________. __       _______     _______. __    __   __  .______   \n";
  cout << "|   _  \\     /   \\  |           |           ||  |     |   ____|   /       ||  |  |  | |  | |   _  \\  \n";
  cout << "|  |_)  |    /  ^  \\ `---|  |----`---|  |----`|  |     |  |__     |   (----`|  |__|  | |  | |  |_)   | \n";
  cout << "|   _  <    /  /_\\ \\    |  |        |  |     |  |     |   __|     \\   \\  |      __  |  | |  | ___/  \n";
  cout << "|  |_)  |  /  _____  \\   |  |        |  |     |  `----.|  |____.----)   |   |  |  |  | |  | |  |      \n";
  cout << "|______/  /__/    \\__\\  |__|        |__|     |_______||_______|_______/    |__|  |__| |__| | _|      \n";
  cout << "──────────────────────────────────────────────────────────────────────────────────────────────────\n";

  char aiboard[5][5];
  char playerboard[5][5];

  bool playerLost = false;
  bool aiLost = false;

  // Initialize the boards with underscores
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      aiboard[i][j] = '_';
      playerboard[i][j] = '_';
    }
  }
  int choice;

  fillBoard(aiboard);

  do
  {
    cout << "Do you want to \n1. manually assign your ships\n2. randomly generate the placement" << endl;
    cin >> choice;
  } while (choice != 1 && choice != 2);

  switch (choice)
  {
  case 1:
    for (int i = 0; i < 4; i++)
    {
      cout << "Enter the x and y coordinates for ship " << i + 1 << endl;
      int x, y;
      cin >> x >> y;
      x--;
      y--;

      // check if x and y are in range
      if (x < 0 || x > 4 || y < 0 || y > 4)
      {
        cout << "Invalid coordinates" << endl;
        i--;
      }
      else
      {
        if (playerboard[x][y] == 's')
        {
          cout << "you already have a ship there" << endl;
          i--;
        }
        else
        {
          playerboard[x][y] = 's';
        }
        printBoard(playerboard);
      }
    }

    break;
  case 2:
    fillBoard(playerboard);
    printBoard(playerboard);
    break;
  }

  // Game loop

  while (!playerLost && !aiLost)
  {
    playerGuess(aiboard);
    aiGuess(playerboard);

    playerLost = true;
    aiLost = true;

    // Check if player has lost

    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 5; j++)
      {
        // playerLost = playerboard[i][j] != 's';
        // aiLost = aiboard[i][j] != 's';
        if (playerboard[i][j] == 's')
        {
          playerLost = false;
        }
        if (aiboard[i][j] == 's')
        {
          aiLost = false;
        }
      }
    }
    if (playerLost || aiLost)
    {
      break;
    }
  }

  if (playerLost)
  {
    cout << "You lost!" << endl;
  }
  else
  {
    cout << "You won!" << endl;
  }

  return 0;
}

void fillBoard(char (*board)[5])
{
  // randomly fill in board with 5 ships
  for (int i = 0; i < 3; i++)
  {
    int x = rand() % 5;
    int y = rand() % 5;
    if (board[x][y] != 's')
    {
      board[x][y] = 's';
    }
    else
    {
      i--;
    }
  }
}

void printBoard(char playerboard[5][5])
{
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cout << playerboard[i][j] << " ";
    }
    cout << endl;
  }
}

void aiGuess(char playerboard[5][5])
{
  int x, y;
  do
  {
    x = rand() % 5;
    y = rand() % 5;
  } while (playerboard[x][y] == 'x' || playerboard[x][y] == 'o');

  if (playerboard[x][y] == 's')
  {
    cout << "AI hit!" << endl;
    playerboard[x][y] = 'x';
  }
  else
  {
    cout << "AI missed!" << endl;
    playerboard[x][y] = 'o';
  }

  cout << "This is how your board looks now: " << endl;
  printBoard(playerboard);
}

void playerGuess(char aiboard[5][5])
{
  int x, y;
  cout << "enter cords for your guess" << endl;
  cin >> x >> y;

  x--;
  y--;

  if (x < 0 || x >= 5 || y < 0 || y >= 5)
  {
    cout << "please enter values between 1 and 5." << endl;
    playerGuess(aiboard);
  }

  if (aiboard[x][y] == 's')
  {
    cout << "Hit!" << endl;
    aiboard[x][y] = 'x';
  }
  else if (aiboard[x][y] == '_')
  {
    cout << "Miss!" << endl;
    aiboard[x][y] = 'o';
  }

  cout << "This is how the Ai's board looks now: " << endl;
  viewBoard(aiboard);
}

void viewBoard(char aiboard[5][5])
{
  // print without showing location of ships
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (aiboard[i][j] == 's')
      {
        cout << "_ ";
      }
      else
      {
        cout << aiboard[i][j] << " ";
      }
    }
    cout << endl;
  }
}

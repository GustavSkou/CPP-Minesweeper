#include "input.cpp"
#include "genMines.cpp"
#include "streamMinefield.cpp"

int height = 5;
int width = 5;

int mines = 2;

bool boom = false;

int main()
{
      genMinefield(height, width);

      genMines(height, width, mines);
      coutMinefield(height, width);

      do
      {
            boom = playerAction(height, width);
            coutMinefield(height, width);
      } 
      while (boom == false);

      coutOpenMinefield(height, width);

      return 0;
}
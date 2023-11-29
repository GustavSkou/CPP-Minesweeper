#include "input.cpp"
#include "genMines.cpp"
#include "streamMinefield.cpp"

int height = 9;
int width = 9;

int mines = 20;

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
  } while (boom == false);

  return 0;
}
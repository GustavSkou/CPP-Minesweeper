#include "input.cpp"

int height = 9;
int width = 9;
int fieldSize = height * width;
int* fieldSizePtr = &fieldSize;

int mines = 5;

bool boom = false;

int main ( ) {
  
  genMinefield( height, width );
  genMines( mines, fieldSizePtr );
  coutMinefield( height, width );

  do {
    boom = playerAction ( height, width );
    coutMinefield( height, width );
  }
  while( boom == false );

  return 0;
}
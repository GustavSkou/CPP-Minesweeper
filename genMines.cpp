#include "minefield.cpp"
#include <time.h>

int genMines (int height, int width, int mines) 
{
  
  int mineRowIndex, mineColumnIndex;

  for ( int n = 0; n < mines; ++n) {

    srand( time ( NULL ) );
    mineRowIndex = rand() % height;
    mineColumnIndex = rand() % width;

    if (minefield[ mineRowIndex ][ mineColumnIndex ].is_mine == true) {

      while ( minefield [ mineRowIndex ][ mineColumnIndex ].is_mine ) {

        mineRowIndex = rand() % height;
        mineColumnIndex = rand() % width;
      }

      minefield[ mineRowIndex ][ mineColumnIndex ].is_mine = true;
    }
    else {
      
      minefield[ mineRowIndex ][ mineColumnIndex ].is_mine = true;
    }
  }
  return 0;
} 
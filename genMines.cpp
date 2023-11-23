#include "minefield.cpp"
#include <time.h>


void genMines ( int mines , int* fieldSize) {
  
  int mineIndex;

  for ( int n = 0; n < mines; ++n) {

    srand( time ( NULL ) );
    mineIndex = rand() % *fieldSize;

    if (minefield [ mineIndex ].is_mine == true) {

      while ( minefield [ mineIndex ].is_mine ) {

        mineIndex = rand() % *fieldSize;
      }

      minefield[ mineIndex ].is_mine = true;
    }
    else {
      
      minefield[ mineIndex ].is_mine = true;
    }
  }
}
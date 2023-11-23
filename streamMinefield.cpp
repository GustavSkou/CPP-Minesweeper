#include "genMines.cpp"
#include <iostream>

void coutMinefield ( int height, int width) {

    for (int n = 0; n < height * width; ++n) {

      std::cout << minefield[ n ].symbol;

      if ( minefield[n].x == width ) {

        std::cout << "\n";
      }
    }
}
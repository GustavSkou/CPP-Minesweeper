#ifndef MINEFIELD_HEADER
#define MINEFIELD_HEADER

#include "cell.cpp"
#include <vector>
#include <string>

std::vector<Cell> minefield;

void genMinefield( int height, int width ) {
  std::string unknownSymbol = " # ";

  for ( int y = 1; y <= height; ++y ) {

    for ( int x = 1; x <= width; ++x ) {

      Cell cell( x, y, unknownSymbol);
      minefield.push_back( cell );

    }
  }
}

#endif
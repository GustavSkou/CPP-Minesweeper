#ifndef MINEFIELD_HEADER
#define MINEFIELD_HEADER

#include "cell.cpp"
#include <vector>
#include <algorithm>
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


void sortMinefield(std::vector<Cell> minefield, int minefieldWidth) {
  std::vector<Cell> reversedMinefield;
  reversedMinefield.resize(minefield.size());
  std::vector<Cell> sortedMinefield;
  std::reverse_copy( minefield.begin(), minefield.end(), reversedMinefield.begin() );

  /*for ( int i = 0; i < reversedMinefield.size(); i = i + minefieldWidth ) {

    std::reverse_copy( reversedMinefield.begin() + i * minefieldWidth , reversedMinefield.begin() + i * minefieldWidth + (minefieldWidth - 1), sortedMinefield.begin() );
  }*/
  std::swap(minefield, reversedMinefield);
}

#endif
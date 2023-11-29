#ifndef MINEFIELD_HEADER
#define MINEFIELD_HEADER

#include "cell.cpp"
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::vector<Cell>> minefield;
void genMinefield(int height, int width)
{
      std::string unknownSymbol = " # ";

      for (int rowNumber = 1; rowNumber <= height; ++rowNumber)
      {
            std::vector<Cell> minefieldRow;

            for (int columnNumber = 1; columnNumber <= width; ++columnNumber)
            {
                  Cell cell(columnNumber, rowNumber, unknownSymbol);
                  minefieldRow.push_back( cell );
            }
            minefield.push_back( minefieldRow );
      }
}

#endif
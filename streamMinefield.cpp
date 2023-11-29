#include <iostream>
#include "minefield.cpp"

void coutMinefield(int height, int width)
{
      for (int rowNumber = height-1; rowNumber >= 0; --rowNumber)
      {
            for (int columnNumber = 0; columnNumber < width; ++columnNumber)
            {     
                  std::cout << minefield[rowNumber][columnNumber].symbol;

                  if (columnNumber == width - 1)
                  {
                        std::cout << "\n";
                  }
            }
      }
}
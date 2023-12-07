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
      for(int row = 0; row < SurroundingCells.size(); ++row) 
      {
            for (int column = 0; column < SurroundingCells.at(row).size(); ++column)
            {
                  std::cout
                  << "("
                  << SurroundingCells.at(row).at(column).x 
                  << "; "
                  << SurroundingCells.at(row).at(column).y
                  << ")"
                  << SurroundingCells.at(row).at(column).is_mine
                  << "\n";
            }
      }
}

void coutOpenMinefield(int height, int width)
{
      std::cout << "\n";

      for (int rowNumber = height-1; rowNumber >= 0; --rowNumber)
      {
            for (int columnNumber = 0; columnNumber < width; ++columnNumber)
            {     
                  if ( minefield[rowNumber][columnNumber].is_mine == true ) 
                  {
                        minefield[ rowNumber ][ columnNumber ].symbol = " ¤ ";
                  }
                  
                  if (columnNumber == width - 1)
                  {
                        std::cout 
                        << minefield[rowNumber][columnNumber].symbol
                        << "\n";
                        
                        continue;
                  }

                  std::cout << minefield[rowNumber][columnNumber].symbol;
            }
      }
}
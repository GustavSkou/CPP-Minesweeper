#include <iostream>
#include "minefield.cpp"

void coutMinefield(int height, int width)
{
      for (int rowNumber = height-1; rowNumber >= 0; --rowNumber)
      {
            std::cout << rowNumber + 1;
            for (int columnNumber = 0; columnNumber < width; ++columnNumber)
            {     
                  if ( minefield[rowNumber][columnNumber].is_cell_mine() && minefield[rowNumber][columnNumber].is_cell_open()) 
                  {
                        minefield[ rowNumber ][ columnNumber ].symbol = " ¤ ";
                  }

                  std::cout << minefield[rowNumber][columnNumber].symbol;

                  if (columnNumber == width - 1)
                  {
                        std::cout << "\n";
                  }
            }
      }
      std::cout << "X";
      for (int columnNumber = 1; columnNumber <= width; ++columnNumber)
      {
            std::cout << " " << columnNumber << " ";
      }

      std::cout << "\n";

      /*for(int row = 0; row < SurroundingCells.size(); ++row) 
      {
            for (int column = 0; column < SurroundingCells.at(row).size(); ++column)
            {
                  std::cout
                  << "("
                  << SurroundingCells.at(row).at(column).get_cell_pos().x 
                  << "; "
                  << SurroundingCells.at(row).at(column).get_cell_pos().y
                  << ")"
                  << SurroundingCells.at(row).at(column).is_cell_mine()
                  << "\n";
            }
      }*/
}

void coutOpenMinefield(int height, int width)
{
      std::cout << "\n";

      for (int rowNumber = height-1; rowNumber >= 0; --rowNumber)
      {
            for (int columnNumber = 0; columnNumber < width; ++columnNumber)
            {     
                  if ( minefield[rowNumber][columnNumber].is_cell_mine()) 
                  {
                        minefield[ rowNumber ][ columnNumber ].symbol = " ¤ ";
                  }
                  
                  if (columnNumber == width - 1)
                  {
                        std::cout 
                        << minefield[rowNumber][columnNumber].symbol
                        << "\n"
                        << rowNumber;
                        
                        continue;
                  }

                  std::cout << minefield[rowNumber][columnNumber].symbol;
            }
      }
}
#include <iostream>
#include "cell.cpp"

bool playerAction(int height, int width)
{
      int x, y; 

      int* rowPtr = nullptr;
      int* columnPtr = nullptr;

      do
      {
            std::cout << "x = ";
            std::cin >> x;

            std::cout << "y = ";
            std::cin >> y;
      } 
      while (x > width || y > height || x <= 0 || y <= 0);
      
      int row = y - 1;
      int column = x - 1;
      rowPtr = &row;
      columnPtr = &column;

      if (!openCell(height, width, rowPtr, columnPtr))
      {
            return false;
      }
      else
      {
            return true;
      }
}
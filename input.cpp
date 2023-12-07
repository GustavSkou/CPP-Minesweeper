#include <iostream>
#include "cell.cpp"

bool playerAction(int height, int width)
{
      int x; 
      int y;
      int* xPtr = NULL;
      int* yPtr = NULL;

      do
      {
            std::cout << "x = ";
            std::cin >> x;
            xPtr = &x;

            std::cout << "y = ";
            std::cin >> y;
            yPtr = &y; 
      } 
      while (x > width || y > height || x <= 0 || y <= 0);
      
      *xPtr = *xPtr - 1;
      *yPtr = *yPtr - 1;

      if (!openCell(height, width, xPtr, xPtr))
      {
            return false;
      }
      else
      {
            return true;
      }
}
#include <iostream>
#include "cell.cpp"

bool playerAction (int height, int width) {

  int x;
  int y;
  int index;

  std::cout << "x = ";
  std::cin >> x;

  std::cout << "y = ";
  std::cin >> y;

  if ( x > width || y > height ) {
    std::cout << "\n num to large\n";
    playerAction (height, width);
  }
  
  if ( x < 0 || y < 0 ) {
    std::cout << "\n num to small\n";
    playerAction (height, width);
  }

  x = x - 1;
  y = y - 1;

  if ( openCell(height, width, &y, &x) == true ) {
    
    return true;
  }
  else {

    return false;
  }
}
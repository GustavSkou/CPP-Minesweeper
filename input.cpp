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
  else {

    index = getCellIndex ( x , y );

    if ( openCell( index, width) == true ) {
      
      return true;
    }
    else {

      return false;
    }
  }

  return false;
}
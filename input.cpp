#include "streamMinefield.cpp"
#include "checkAround.cpp"

int findCellIndex (int x, int y ) {

  for ( int n = 0; n < minefield.size(); ++n ) {

    if ( minefield[ n ].x == x && minefield[ n ].y == y ) { 

      return n;
    }
  }

  return 0;
}

int checkCell(int cellIndex ) {

  if ( minefield[ cellIndex ].is_open == true ) { 

    return 0;
  }

  if ( minefield[ cellIndex ].is_flaged == true ) { 

    return 0;
  }

  if ( minefield[ cellIndex ].is_mine == true ) { 

    return 2;
  }

  else {

    return 1;
  }

  return 0;
}

int checkSurroundingsCells ( int cellIndex, int width) {
  std::vector<Cell> SurroundingsCells;
  int mineCount;

  SurroundingsCells.push_back(minefield[ cellIndex - width - 1 ] );
  SurroundingsCells.push_back(minefield[ cellIndex - width - 0 ]);
  SurroundingsCells.push_back(minefield[ cellIndex - width + 1 ]);

  SurroundingsCells.push_back(minefield[ cellIndex - 1 ]);
  SurroundingsCells.push_back(minefield[ cellIndex + 1 ]);
  
  SurroundingsCells.push_back(minefield[ cellIndex + width - 1 ]);
  SurroundingsCells.push_back(minefield[ cellIndex + width - 0 ]);
  SurroundingsCells.push_back(minefield[ cellIndex + width + 1 ]);
  
  for (int n = 0; n < SurroundingsCells.size(); ++n) {
    if (SurroundingsCells[n].is_mine) {
      ++mineCount;
    }
  }
  
  return mineCount;
}

bool openCell ( int cellIndex, int width) {
  switch ( checkCell ( cellIndex ) )
  {
  case 0:
    return false;
  
  case 1:
    {
      int SurroundingsCellsMines = checkSurroundingsCells( cellIndex, width);

      minefield[ cellIndex ].is_open = true;

      if ( SurroundingsCellsMines > 0 ) {

        minefield[ cellIndex ].symbol = " " + std::to_string( SurroundingsCellsMines ) + " ";
      }
      else {

        minefield[ cellIndex ].symbol = " . ";
      }
      
      return false;
    }

  case 2:
    minefield[ cellIndex ].symbol = " ¤ ";

    return true;
  }

  return false;
}

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

    index = findCellIndex ( x , y );

    if ( openCell( index, width) == true ) {
      
      return true;
    }
    else {

      return false;
    }
  }

  return false;
}
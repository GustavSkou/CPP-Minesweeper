#ifndef CELL_HEADER
#define CELL_HEADER

#include <string>

class Cell {

  public:
    int x;
    int y;
    std::string symbol;
    bool is_mine = false;
    bool is_open = false;
    bool is_flaged = false;

    Cell( int xKoordinat, int yKoordinat, std::string cellSymbol) {
      x = xKoordinat;
      y = yKoordinat;
      symbol = cellSymbol;
    }

};

#include "minefield.cpp"

int getCellIndex (int x, int y ) {

  for ( int n = 0; n < minefield.size(); ++n ) {

    if ( minefield[ n ].x == x && minefield[ n ].y == y ) { 

      return n;
    }
  }

  return 0;
}

// Returns 0 if cell cannot be opened
// Returns 1 if cell can be opened
// Returns 2 if cell is a mine
int checkCell( int cellIndex ) {    
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
  
  // The index for the cells in SurroundingsCells is stored like so // 0 1 2     
  for (int n = 0; n < SurroundingsCells.size(); ++n) {              // 3   4
    if (SurroundingsCells[n].is_mine) {                             // 5 6 7
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

#endif
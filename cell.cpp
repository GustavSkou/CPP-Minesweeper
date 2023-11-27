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

std::vector<Cell> SurroundingCells;
std::vector<Cell> SurroundingCellsToOpen;
int checkSurroundingCells ( int cellIndex, int width) {
  int mineCount = 0;
  int surroundingCellsIndex[8] = {
    cellIndex - width - 1, 
    cellIndex - width - 0, 
    cellIndex - width + 1, 
    cellIndex - 1,
    cellIndex + 1,
    cellIndex + width - 1,
    cellIndex + width - 0,
    cellIndex + width + 1
  };

  for (int index : surroundingCellsIndex) {
    if ( index < 0 || index > minefield.size() ) {
      continue;
    }
    if ( minefield[ index ].is_open ) {
      continue;
    }

    SurroundingCells.push_back( minefield[ index ] );
  }

  // The index for the cells in SurroundingCells is stored like so // 0 1 2 if possibel
  for (int n = 0; n < SurroundingCells.size(); ++n) {              // 3   4
    if (SurroundingCells[n].is_mine) {                             // 5 6 7
      ++mineCount;                                  
    }     
  }
  for (int n = 0; n < SurroundingCells.size(); ++n) {
    if (!SurroundingCells[n].is_mine && !SurroundingCells[n].is_flaged) {
      SurroundingCellsToOpen.push_back(SurroundingCells[n]);
    }
  }
  SurroundingCells.clear();
    
  return mineCount;
}

bool openCell ( int cellIndex, int width) {
  switch ( checkCell ( cellIndex ) )
  {
  case 0:
    return false;
  
  case 1:
    {
      int SurroundingCellsMines = 0;
      SurroundingCellsMines = checkSurroundingCells( cellIndex, width );

      minefield[ cellIndex ].is_open = true;

      if ( SurroundingCellsMines > 0 ) {

        minefield[ cellIndex ].symbol = " " + std::to_string( SurroundingCellsMines ) + " ";
      }
      else {

        minefield[ cellIndex ].symbol = " . ";
        
        while ( SurroundingCellsToOpen.size() > 0 ) {
          cellIndex = getCellIndex ( SurroundingCellsToOpen.back().x, SurroundingCellsToOpen.back().y );
          SurroundingCellsToOpen.pop_back();
          openCell ( cellIndex, width);
        }
        
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
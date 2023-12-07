#ifndef CELL_HEADER
#define CELL_HEADER

#include <string>

class Cell
{
      private:
            bool is_mine = false;
            bool is_open = false;
            bool is_flaged = false;
            
            struct Position
            {
                  int x;
                  int y;
            };
            Position cell_position;
            
      public:
            std::string symbol;
            
            Cell(int xKoordinat, int yKoordinat, std::string cellSymbol)
            {
                  cell_position.x = xKoordinat;
                  cell_position.y = yKoordinat;

                  symbol = cellSymbol;
            }

            void set_mine()
            {
                  is_mine = true;
            }

            void open_cell()
            {
                  is_open = true;
            }

            void change_flag_state()
            {
                  switch (is_flaged)
                  {
                        case false:
                              is_flaged = true;
                              break;
                        
                        case true:
                              is_flaged = false;
                              break;
                  }
            }

            bool is_cell_mine()
            {
                  return is_mine;
            }

            bool is_cell_flaged()
            {
                  return is_flaged;
            }

            bool is_cell_open()
            {
                  return is_open;
            }
            
            Position get_cell_pos() 
            {
                  return cell_position;
            }
};

#include "minefield.cpp"

// Returns 0 if cell cannot be opened
// Returns 1 if cell can be opened
// Returns 2 if cell is a mine
int checkCell(int *rowAddress, int *columnAddress)
{
      if (minefield[*rowAddress][*columnAddress].is_cell_open())
      {
            return 0;
      }

      if (minefield[*rowAddress][*columnAddress].is_cell_flaged())
      {
            return 0;
      }

      if (minefield[*rowAddress][*columnAddress].is_cell_mine())
      {
            return 2;
      }

      return 1;
}

std::vector<std::vector<Cell>> SurroundingCells;
std::vector<Cell> CellsToOpen;

int checkSurroundingCells(int height, int width, int *rowAddress, int *columnAddress)
{
      SurroundingCells.clear();
      int mineCount = 0;

      int rowNumber, columnNumber;
      rowNumber = *rowAddress - 1;
      columnNumber = *columnAddress - 1;

      for (int row = rowNumber; row < 2 + (*rowAddress); ++row)
      {
            try
            {
                  minefield.at(row);
            }
            catch (const std::out_of_range &e)
            {
                  continue;
            }
            std::vector<Cell> SurroundingCellsRow;
            for (int column = columnNumber; column < 2 + (*columnAddress); ++column)
            {
                  try
                  {
                        if (minefield.at(row).at(column).is_cell_open())
                        {
                              continue;
                        }

                        SurroundingCellsRow.push_back(minefield.at(row).at(column));
                  }
                  catch (const std::out_of_range &e)
                  {
                        continue;
                  }
            }

            SurroundingCells.push_back(SurroundingCellsRow);
      }
      
      for (int row = 0; row < SurroundingCells.size(); ++row)
      {
            for (int column = 0; column < SurroundingCells[row].size(); ++column)
            {
                  if (SurroundingCells[row][column].is_cell_mine())
                  {
                        ++mineCount;
                  }    
            }
      }
      return mineCount;
}

bool openCell(int height, int width, int *rowAddress, int *columnAddress)
{
      switch (checkCell(rowAddress, columnAddress)) // 0 = open/flaged,
      {                                             // 1 = unopened,
      case 0:                                       // 2 = mine
            return false;

      case 1:
      {
            int SurroundingCellsMines = 0;

            minefield[*rowAddress][*columnAddress].open_cell();

            SurroundingCellsMines = checkSurroundingCells(height, width, rowAddress, columnAddress);

            if (SurroundingCellsMines > 0)
            {
                  minefield[*rowAddress][*columnAddress].symbol = " " + std::to_string(SurroundingCellsMines) + " ";
            }
            else
            {
                  minefield[*rowAddress][*columnAddress].symbol = " . ";

                  for (int row = 0; row < SurroundingCells.size(); ++row)
                  {
                        for (int column = 0; column < SurroundingCells.at(row).size(); ++column)
                        {
                              CellsToOpen.push_back(SurroundingCells.at(row).at(column));
                        }
                  }

                  for (int cellIndex = 0; cellIndex < CellsToOpen.size(); cellIndex++)
                  {
                        int newRow = CellsToOpen[cellIndex].get_cell_pos().y - 1;
                        int newColumn = CellsToOpen[cellIndex].get_cell_pos().x - 1;

                        openCell(height, width, &newRow, &newColumn);
                  }
            }
            return false;
      }

      case 2:
            minefield[*rowAddress][*columnAddress].symbol = " ¤ ";
            return true;
      }

      return false;
}

#endif
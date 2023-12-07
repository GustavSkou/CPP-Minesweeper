#include <iostream>
#include "cell.cpp"
#include <string>

class Input
{
      private:
            bool inputType = false; /*false = open, true = flag*/

            struct UserXYInput
            {
                  int x, y;
            };
            UserXYInput xyInput;

            struct RowColumn
            {
                  int column, row;
            };
            RowColumn rowAndColumn;

      public:
            Input(int x, int y, bool type)
            {
                  xyInput.x = x; 
                  xyInput.y = y;
                  inputType = type;
                  rowAndColumn.column = xyInput.x - 1;
                  rowAndColumn.row = xyInput.y - 1;

            }

            UserXYInput getUserXYInput()
            {
                  return xyInput;
            }

            bool getUserInputType()
            {
                  return inputType;
            }

            RowColumn xyToRowColumn()
            {
                  return rowAndColumn;
            }
                        
};

bool playerAction(int height, int width)
{
      int x, y, row, column; 
      std::string typeAnswer;
      bool flag = false;

      do
      {
            std::cout << "x = ";
            std::cin >> x;

            std::cout << "y = ";
            std::cin >> y;
      } 
      while (x > width || y > height || x <= 0 || y <= 0);
      std::cout << "flag? yes/no : ";
      std::cin >> typeAnswer;
      if (typeAnswer == "yes") {
            flag = true;
      }

      Input userInput(x, y, flag);

      row = userInput.xyToRowColumn().row;
      column = userInput.xyToRowColumn().column;
      bool setFlag = userInput.getUserInputType();

      if (!openCell(height, width, &row, &column, &setFlag))
      {
            return false;
      }
      else
      {
            return true;
      }
}
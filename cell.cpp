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

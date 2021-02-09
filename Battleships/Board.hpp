#include <string>
using std::string;

class Board
{
private:
    int row;
    int col;
    char **grid;
    char **fake;
    string way;
    int x,y;

public:
    Board(int, int);
    ~Board();
    void fill();
    void fillFake();
    void setCoord();
    void setWay();
    void place(int shipLength);
    void attack(int &, int &);
    bool checkHit(int,int);
    bool checkLoss();
    void print();
    void printFake();

};

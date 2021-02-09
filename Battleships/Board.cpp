#include <iostream>
#include <string>
#include "Board.hpp"
using namespace std;

Board::Board(int rows, int cols)
{
    row = rows;
    col = cols;
    grid = new char *[row];
    for (int i = 0; i < row; i++)
    {
        grid[i] = new char[col];
    }
    fake = new char *[row];
    for (int j = 0; j < row; j++)
    {
        fake[j] = new char[col];
    }
}

Board::~Board()
{
    for (int i = 0; i < row; i++)
    {
        delete grid[i];
    }
    delete grid;
}

void Board::fill()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            grid[i][j] = '~';
        }
    }
}

void Board::fillFake()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            fake[i][j] = '~';
        }
    }
}

void Board::setCoord()
{
    do
    {
        cout << "Insert the position you want to place your ships:";
        cin >> x >> y;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        x -= 1;
        y -= 1;
        cout << endl
             << endl;
    } while ((x < 0 || x > row - 1) || (y < 0 || y > col - 1) || cin.fail());
}

void Board::setWay()
{
    do
    {
        cout << "Insert the way you want to position your ships(UP,DOWN,LEFT,RIGHT):";
        cin >> way;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cout << endl
             << endl;
    } while ((way != "UP") && (way != "DOWN") && (way != "LEFT") && (way != "RIGHT") || cin.fail());
}

void Board::place(int shipLength)
{
    grid[x][y] = '^';
    if (shipLength == 1)
        ;
    else
    {
        for (int i = 1; i < shipLength; i++)
        {

            if (way == "UP")
            {
                grid[x - (i)][y] = '^';
            }
            else if (way == "DOWN")
            {
                grid[x + (i)][y] = '^';
            }
            else if (way == "LEFT")
            {
                grid[x][y - (i)] = '^';
            }
            else if (way == "RIGHT")
            {
                grid[x][y + (i)] = '^';
            }
        }
    }
}
void Board::attack(int &attackX, int &attackY)
{
    do
    {
        cout << "Declare the position you want to attack:";
        cin >> attackX >> attackY;
        attackX -= 1;
        attackY -= 1;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cout << endl
             << endl;
    } while ((attackX < 0 || attackX > row - 1) || (attackY < 0 || attackY > col - 1) || cin.fail());
}

bool Board::checkHit(int x, int y)
{
    if (grid[x][y] == '^')
    {
        grid[x][y] = 'X';
        fake[x][y] = 'X';
        return true;
    }
    else
        return false;
}

void Board::print()
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

void Board::printFake()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << fake[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

bool Board::checkLoss()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == '^')
            {
                return false;
            }
        }
    }
    return true;
}
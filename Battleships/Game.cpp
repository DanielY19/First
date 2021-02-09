#include <iostream>
#include <string>
#include "Board.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

void declareMat(int &x, int &y)
{
    do
    {
        cout << "Insert the size of the playing mat:";
        cin >> x >> y;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cout << endl
             << endl;
    } while ((x < 10 || x > 20) || (y < 10 || y > 20) || cin.fail());
}

void setPieces(Board &set)
{
    int x, y;
    for (int i = 1; i <= 5; i++)
    {

        set.setCoord();
        set.setWay();
        set.place(i);
        set.print();
    }
}

void attackPhase(int &attackX, int &attackY, Board &set1, Board &set2, bool &end)
{
    bool condition;
    do
    {
        set2.printFake();
        set1.attack(attackX, attackY);
        condition = set2.checkHit(attackX, attackY);
        end = set2.checkLoss();
        if (end)
        {
            break;
        }
    } while (condition);
    if (end)
    {
        cout << "Congratulations,you win!!!!" << endl;
        set2.printFake();
    }
}

void turns(int &attackX, int &attackY, Board &set1, Board &set2)
{
    bool end;
    do
    {
        cout << "Player 1 turn:" << endl;
        attackPhase(attackX, attackY, set1, set2, end);
        if (end)
        {
            break;
        }
        cout << "Player 2 turn:" << endl;
        attackPhase(attackX, attackY, set2, set1, end);
    } while (!end);
}

int main()
{
    int row, col;
    int attackX, attackY;
    declareMat(row, col);
    Board Player1(row, col);
    Board Player2(row, col);
    system("cls");
    Player1.fill();
    Player1.fillFake();
    setPieces(Player1);
    system("pause");
    system("cls");
    Player2.fill();
    Player2.fillFake();
    setPieces(Player2);
    system("pause");
    system("CLS");
    turns(attackX, attackY, Player1, Player2);
}
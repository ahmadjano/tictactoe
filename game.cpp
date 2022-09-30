#include <iostream>
#include "game.h"
#include "main.h"

class game
{
private:
    int *m_grid[SIZE];
    const char getCellChar(int playerIndex);
    string getPlayerName(int playerIndex);
public:
    game();
    ~game();
    void print();
};

game::game()
{
    this->m_grid[SIZE][SIZE];
}

void game::print()
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            int i = (y * SIZE + x) + 1;
            int cell = this->m_grid[x][y];

            if (cell == EMPTY)
            {
                std::cout << i << " ";
            }
            else
            {
                std::cout << getCellChar(this->m_grid[x][y]) << " ";
            }
            
        }
        std::cout << std::endl;
    }
}

string game::getPlayerName(int playerIndex)
{
    return (playerIndex == PLAYER1 ? "Player 1" : (playerIndex == PLAYER2 ? "Player 2" : "-"));
}

const char game::getCellChar(int playerIndex)
{
    return playerIndex == EMPTY ? ' ' : (playerIndex == PLAYER1 ? 'X' : 'O');
}

game::~game()
{
    delete[] this->m_grid;
}

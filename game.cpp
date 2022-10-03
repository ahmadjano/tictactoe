#include <iostream>
#include "game.h"
#include "constants.h"

Game::Game()
{
    this->m_current_player = 0;
    this->m_grid = new int*[SIZE];
    
    for (int i = 0; i < SIZE; ++i)
        this->m_grid[i] = new int[SIZE];
}

void Game::start()
{
    this->m_current_player = PLAYER1;

    int winner = EMPTY;

    while (winner == EMPTY)
    {
        winner = getWinner();

        if (winner != EMPTY)
        {
            break;
        }

        // Print current player name.
        std::cout << "Current turn: " << getPlayerName(this->m_current_player) << std::endl;

        // Print the grid.
        this->print();

        // Prompt for input
        char input;

        std::cout << "Choose a cell (1-9) : ";

        std::cin >> input;

        if (!(input >= '1' && input <= '9'))
        {
            std::cout << "Wrong input. Please enter a value between 1-9." << std::endl;
            continue;
        }
        
        // Update the grid:
        // Convert input char to int in order to be able to perform arithmitic operations.
        // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
        int inputInt = input - '0';
        int x = (inputInt - 1) % 3;
        int y = (inputInt - 1) / 3;

        if (this->m_grid[x][y] != EMPTY)
        {
            std::cout << "You can't play on this cell!" << std::endl;
            continue;
        }
        
        this->m_grid[x][y] = this->m_current_player;

        // Switch turn to the next player.
        this->m_current_player = (this->m_current_player % 2) + 1;
    }

    std::cout << getPlayerName(winner) << " won!" << std::endl;
    
    this->print();
}

int Game::getWinner()
{
    int winner = EMPTY;
    int i = 0;

    // Diagonal line checking.
    int lineD = this->checkLine({0,0}, {1,1}, {2,2}) | this->checkLine({2,0}, {1,1}, {0,2});

    while (!winner && i < SIZE)
    {
        int lineV = this->checkLine({0,i}, {1,i}, {2,i});
        int lineH = this->checkLine({i,0}, {i,1}, {i,2});

        int potentialWinner = lineV | lineH | lineD;

        if (potentialWinner != EMPTY)
            return potentialWinner;

        i++;
    }

    return winner;
}

int Game::checkLine(const vector2 & pos1, const vector2 & pos2, const vector2 & pos3)
{
    return this->m_grid[pos1.x][pos1.y] & this->m_grid[pos2.x][pos2.y] & this->m_grid[pos3.x][pos3.y];
}

void Game::print()
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

string Game::getPlayerName(int playerIndex)
{
    return (playerIndex == PLAYER1 ? "Player 1" : (playerIndex == PLAYER2 ? "Player 2" : "-"));
}

const char Game::getCellChar(int playerIndex)
{
    return playerIndex == EMPTY ? ' ' : (playerIndex == PLAYER1 ? 'X' : 'O');
}

Game::~Game()
{
    delete[] this->m_grid;
}

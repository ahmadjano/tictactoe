#include <iostream>
#include "main.h"

int main(int argc, char** argv)
{
    const int grid[SIZE][SIZE] =
    {
        { EMPTY, EMPTY, PLAYER1 },
        { EMPTY, PLAYER1, EMPTY },
        { PLAYER1, EMPTY, PLAYER1 },
    };

    int winner = getWinner(grid);

    if (winner)
    {
        std::cout << "The winner is " << getPlayerName(winner) << std::endl;
    }
    else
    {
        std::cout << "No winner yet." << std::endl;
    }

    // Print grid
    printGrid(grid);    

    return 0;   
}

int getWinner(const int grid[][SIZE])
{
    int winner = EMPTY;
    int i = 0;

    while (!winner && i < SIZE)
    {
        int lineV = checkLine(grid, {0,i}, {1,i}, {2,i});
        int lineH = checkLine(grid, {i,0}, {i,1}, {i,2});
        int lineD = checkLine(grid, {0,0}, {1,1}, {2,2}) | checkLine(grid, {2,0}, {1,1}, {0,2});

        int potentialWinner = lineV | lineH | lineD;

        if (potentialWinner != EMPTY)
            return potentialWinner;

        i++;
    }

    return winner;

    // Check horizontal & vertical lines.
    // for (int l = 0; l < SIZE; ++l)
    // {
    //     winner = checkLine(grid, {0,l}, {1,l}, {2,l}) == PLAYER1 ? PLAYER1 :
    //              checkLine(grid, {l,0}, {l,1}, {l,2}) == PLAYER1 ? PLAYER1 :
    //              checkLine(grid, {0,l}, {1,l}, {2,l}) == PLAYER2 ? PLAYER2 : 
    //              checkLine(grid, {l,0}, {l,1}, {l,2}) == PLAYER2 ? PLAYER2 : false;
        
    //     if (winner)
    //         return winner;
    // }

    // // Check diagonal lines.
    // winner =  checkLine(grid, {0,0}, {1,1}, {2,2}) == PLAYER1 ? PLAYER1 :
    //           checkLine(grid, {0,2}, {1,1}, {2,0}) == PLAYER1 ? PLAYER1 :
    //           checkLine(grid, {0,0}, {1,1}, {2,2}) == PLAYER2 ? PLAYER2 :
    //           checkLine(grid, {0,2}, {1,1}, {2,0}) == PLAYER2 ? PLAYER2 : false;
    
    // return winner;
}


int checkLine(const int grid[][SIZE], const vector2 & pos1, const vector2 & pos2, const vector2 & pos3)
{
    return grid[pos1.x][pos1.y] & grid[pos2.x][pos2.y] & grid[pos3.x][pos3.y];
}

const char* getPlayerName(int playerIndex)
{
    return (playerIndex == PLAYER1 ? "Player 1" : (playerIndex == PLAYER2 ? "Player 2" : "-"));
}

void printGrid(const int grid[][SIZE])
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            std::cout << grid[x][y] << " ";
        }
        std::cout << std::endl;
    }
}
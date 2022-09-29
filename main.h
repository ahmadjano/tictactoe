/*
 *  HEIG-VD
 *  Description: TicTacToe game - PRG1
 *  Author(s): Ahmad & Bruno
 *  Date: 29.09.2022
*/
#define SIZE 3
#define EMPTY 0    // 0b0000
#define PLAYER1 1  // 0b0001
#define PLAYER2 2  // 0b0010

struct vector2
{
    int x;
    int y;
};

int getWinner(const int grid[][SIZE]);
int checkLine(const int grid[][SIZE], const vector2 & pos1, const vector2 & pos2, const vector2 & pos3);
void printGrid(const int grid[][SIZE]);
const char* getPlayerName(int playerIndex);
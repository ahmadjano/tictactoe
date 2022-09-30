#include "constants.h"

class Game
{
private:
    int m_current_player = 0;
    int **m_grid;
    const char getCellChar(int playerIndex);
    string getPlayerName(int playerIndex);
    int getWinner();
    int checkLine(const vector2 & pos1, const vector2 & pos2, const vector2 & pos3);
public:
    Game();
    ~Game();
    void start();
    void print();
};
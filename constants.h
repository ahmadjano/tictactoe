/*
 *  HEIG-VD
 *  Description: TicTacToe game - PRG1
 *  Author(s): Ahmad & Bruno
 *  Date: 29.09.2022
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define SIZE 3
#define EMPTY 0    // 0b0000
#define PLAYER1 1  // 0b0001
#define PLAYER2 2  // 0b0010

typedef const char* string;

struct vector2
{
    int x;
    int y;
};
#endif
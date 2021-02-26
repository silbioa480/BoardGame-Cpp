#ifndef __C_PRINT_WIDE_H__
#define __C_PRINT_WIDE_H__
#include "CPrintBoardGame.h"

class CPrintWide : public CPrintBoardGame
{
private:
	virtual void printUITop();
	virtual void printUIRight(int);
	virtual void printLine(int, int);
	virtual void printLineWide(int);
	virtual string getLine(string, int, int);
	
public:
	CPrintWide(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintBoardGame(a_dat, a_nRowSize + 1, a_nColSize + 1) {}

	virtual void printBoard();
};
#endif
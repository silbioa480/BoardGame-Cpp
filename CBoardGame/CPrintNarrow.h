#ifndef __C_PRINT_NARROW_H__
#define __C_PRINT_NARROW_H__
#include "CPrintBoardGame.h"

class CPrintNarrow : public CPrintBoardGame
{
private:
	virtual void printUITop();
	virtual void printUIRight(int);
	virtual void printLine(int, int);
	virtual void printLineWide(int);
	virtual string getLine(string, int, int);

public:
	CPrintNarrow(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintBoardGame(a_dat, a_nRowSize, a_nColSize) {};

	virtual void printBoard();
};
#endif
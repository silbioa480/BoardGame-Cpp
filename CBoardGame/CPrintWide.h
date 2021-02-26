#ifndef __C_PRINT_WIDE_H__
#define __C_PRINT_WIDE_H__
#include "CPrintBoardGame.h"

class CPrintWide : public CPrintBoardGame
{
private:
	
public:
	CPrintWide(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintBoardGame(a_dat, a_nRowSize, a_nColSize) {}

	virtual void printUITop();
	virtual void printUIRight(int);
	virtual void printLine(int, int);
	virtual void printLineWide(int);
	virtual string getLine(string, int, int);
	virtual void printBoard();
};
#endif
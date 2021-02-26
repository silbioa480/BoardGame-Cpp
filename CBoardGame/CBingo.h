#ifndef __C_BINGO_H__
#define __C_BINGO_H__
#define BINGO_ROW_SIZE 5
#define BINGO_COL_SIZE 10
#include "CBoardGame.h"
#include <iostream>
#include <ctime>
#include <string>

class CBingo : public CBoardGame
{
private:
	int m_nArrRandmNumber[25] = { 0, };
	int m_nBingoLineA = 0;
	int m_nBingoLineB = 0;

public:
	CBingo(int a_nRowSize, int a_nColSize) : CBoardGame(a_nRowSize, a_nColSize) 
	{
		setRandomNumberBoard(0, 5);
		setRandomNumberBoard(5, 10);
	}

	virtual bool isBreak(int, int, int, int&, bool&);
	virtual bool check(int, int, int);
	virtual void putStone();
	virtual bool isInvalidPosition(char, char, int);
	virtual bool countStone();
	virtual bool passCheck();

	void findNumber(int);
	void resetRandomNumber();
	void makeRandomNumber();
	void setRandomNumberBoard(int, int);
};
#endif
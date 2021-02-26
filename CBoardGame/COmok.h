#ifndef __C_OMOK_H__
#define __C_OMOK_H__
#define OMOK_SIZE 16
#include "CBoardGame.h"

class COmok : public CBoardGame
{
private:
	int m_nArrSameStone[8] = { 0, };

public:
	COmok(int a_nRowSize, int a_nColSize) : CBoardGame(a_nRowSize, a_nColSize) {}

	virtual bool isBreak(int, int, int, int&, bool&);
	virtual bool check(int _r, int _c, int dir) { return CBoardGame::check(_r, _c, dir); }
	virtual bool isInvalidPosition(char, char, int);
	virtual bool countStone();
};
#endif
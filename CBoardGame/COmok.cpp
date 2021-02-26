#include "COmok.h"

bool COmok::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
	if (CBoardGame::isBreak(_r, _c, dir, cnt, res)) return true;
	else if (getData(_r, _c) == getColor())
	{
		m_nArrSameStone[dir]++;
		return false;
	}
	else if (getData(_r, _c) == getColor() * -1) return true;
}

bool COmok::isInvalidPosition(char _y, char _x, int len)
{
	if (!CBoardGame::isInvalidPosition(_y, _x, len)) return false;
	if (getData(getR(), getC()) != 0) return false;
	canStone(getR(), getC());
	return true;
}

bool COmok::countStone()
{
	for (int i = 0; i < 4; i++) {
		if (m_nArrSameStone[i] + m_nArrSameStone[i + 4] >= 4) return true;
	}

	for (int i = 0; i < 8; i++) m_nArrSameStone[i] = 0;

	return false;
}
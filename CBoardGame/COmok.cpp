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
	canStone(getR(), getC());
	return false;
}

bool COmok::countStone()
{
	if (m_nArrSameStone[DownLeft] + m_nArrSameStone[UpRight] >= 4) return true;
	else if (m_nArrSameStone[Down] + m_nArrSameStone[Up] >= 4) return true;
	else if (m_nArrSameStone[DownRight] + m_nArrSameStone[UpLeft] >= 4) return true;
	else if (m_nArrSameStone[Left] + m_nArrSameStone[Right] >= 4) return true;

	for (int i = 0; i < 8; i++) m_nArrSameStone[i] = 0;

	return false;
}

bool COmok::passCheck()
{
	return true;
}

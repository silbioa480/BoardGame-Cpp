#include "CBoardGame.h"

bool CBoardGame::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
    if (_r >= m_nRowSize || _c >= m_nColSize || _r < 0 || _c < 0) return true;
    if (dat[_r][_c] == 0) return true;

    return false;
}

bool CBoardGame::check(int _r, int _c, int dir)
{
	bool res = false;
	int cnt = 0;

	for (int y = _r, x = _c;
		(0 <= y && y < m_nRowSize) && (0 <= x && x < m_nColSize);
		y += m_nARR_EIGHT_DIR[dir][0], x += m_nARR_EIGHT_DIR[dir][1])
	{
		if (y == _r && x == _c) continue;
		if (isBreak(y, x, dir, cnt, res)) break;
	}

	return res;
}

bool CBoardGame::canStone(int _r, int _c)
{
	bool res = false;

	for (int dir = 0; dir < 8; dir++) {
		if (check(_r, _c, dir)) res = true;
	}

	return res;
}

void CBoardGame::putStone()
{
	dat[r][c] = m_nColor;
	changeColor();
}

bool CBoardGame::isInvalidPosition(char _y, char _x, int len)
{
	if (len != 2) return false;

	if (_y >= 'a' && _y <= 'f') r = _y - 'a' + 10;
	else if (_y >= '0' && _y <= '9') r = _y - '0';
	else return false;

	if (_x >= 'a' && _x <= 'f') c = _x - 'a' + 10;
	else if (_x >= '0' && _x <= '9') c = _x - '0';
	else return false;

	if (dat[r][c] != 0) return false;

	return true;
}
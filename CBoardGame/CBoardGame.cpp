#include "CBoardGame.h"

bool CBoardGame::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
    if (_r >= m_nSize || _c >= m_nSize || _r < 0 || _c < 0) return true;
    if (dat[_r][_c] == 0) return true;

    return false;
}

bool CBoardGame::check(int _r, int _c, int dir)
{
	bool res = false;
	int cnt = 0;

	for (int i = 1; i < m_nSize - 1; i++) {
		if (isBreak(_r + (i * m_nARR_EIGHT_DIR[0][dir]), _c + (i * m_nARR_EIGHT_DIR[1][dir]), dir, cnt, res)) break;
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
	m_nColor *= -1;
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

	if (r >= m_nSize || c >= m_nSize || r < 0 || c < 0) return false;

	if (dat[r][c] != 0) return false;

	m_bPos = canStone(r, c);

	return true;
}

bool CBoardGame::countStone()
{
	return false;
}

bool CBoardGame::passCheck()
{
	return true;
}

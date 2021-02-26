#include "COthello.h"

bool COthello::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
	if (CBoardGame::isBreak(_r, _c, dir, cnt, res)) return true;
	else if (getData(_r, _c) == getColor())
	{
		if (m_VectorPairReversePoint.empty() == false) res = true;
		return true;
	}
	else if (getData(_r, _c) == getColor() * -1)
	{
		m_VectorPairReversePoint.emplace_back(make_pair(_r, _c));
		cnt++;
		return false;
	}
}

bool COthello::check(int _r, int _c, int dir)
{
	bool res = false;
	int cnt = 0;

	for (int y = _r, x = _c;
		(0 <= y && y < OTHELLO_SIZE) && (0 <= x && x < OTHELLO_SIZE);
		y += m_nARR_EIGHT_DIR[dir][0], x += m_nARR_EIGHT_DIR[dir][1])
	{
		if (y == _r && x == _c) continue;
		if (isBreak(y, x, dir, cnt, res)) break;
	}
	if (res == false && cnt != 0) {
		for (int j = 0; j < cnt; j++) m_VectorPairReversePoint.pop_back();
	}

	return res;
}

bool COthello::isInvalidPosition(char _y, char _x, int len)
{
	m_VectorPairReversePoint.clear();
	if (!CBoardGame::isInvalidPosition(_y, _x, len)) return false;
	if (getData(getR(), getC()) != 0) return false;
	setPos(canStone(getR(), getC()));
	if (getPos()) return true;
	return false;
}

bool COthello::countStone()
{
	for (int i = 0; i < OTHELLO_SIZE; i++) {
		for (int j = 0; j < OTHELLO_SIZE; j++) {
			if (getData(i, j) == 1) CBoardGame::setWhite(getWhite() + 1);
			else if (getData(i, j) == -1) CBoardGame::setBlack(getBlack() + 1);
		}
	}
	return true;
}

bool COthello::passCheck()
{
	int cnt = 0;

	for (int i = 0; i < OTHELLO_SIZE; i++) {
		for (int j = 0; j < OTHELLO_SIZE; j++) {
			if (getData(i, j) == 0) {
				if (canStone(i, j)) cnt++;
			}
		}
	}

	if (cnt == 0) return false;
	return true;
}
#include "COthello.h"

bool COthello::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
	if (CBoardGame::isBreak(_r, _c, dir, cnt, res)) return true;
	else if (getData(_r, _c) == getColor())
	{
		if (m_reverseStone.empty() == false) res = true;
		return true;
	}
	else if (getData(_r, _c) == getColor() * -1)
	{
		m_reverseStone.emplace_back(make_pair(_r, _c));
		cnt++;
		return false;
	}
}

bool COthello::check(int _r, int _c, int dir)
{
	bool res = false;
	int cnt = 0;

	for (int i = 1; i < getSize() - 1; i++) {
		if (isBreak(_r + (i * m_nARR_EIGHT_DIR[0][dir]), _c + (i * m_nARR_EIGHT_DIR[1][dir]), dir, cnt, res)) break;
	}
	if (res == false && cnt != 0) {
		for (int j = 0; j < cnt; j++) m_reverseStone.pop_back();
	}

	return res;
}

bool COthello::isInvalidPosition(char _y, char _x, int len)
{
	m_reverseStone.clear();
	if (CBoardGame::isInvalidPosition(_y, _x, len) == true && getPos() == true) return true;
	else return false;
}

bool COthello::countStone()
{
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			if (getData(i, j) == 1) CBoardGame::setWhite(getWhite() + 1);
			else if (getData(i, j) == -1) CBoardGame::setBlack(getBlack() + 1);
		}
	}
	return true;
}

bool COthello::passCheck()
{
	int cnt = 0;

	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			if (getData(i, j) == 0) {
				if (canStone(i, j)) cnt++;
			}
		}
	}

	if (cnt == 0) return false;
	return true;
}
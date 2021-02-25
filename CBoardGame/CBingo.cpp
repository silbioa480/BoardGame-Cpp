#include "CBingo.h"

bool CBingo::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
	if (CBoardGame::isBreak(_r, _c, dir, cnt, res)) return true;
	if (getData(_r, _c) == -1) {
		cnt++;
		return false;
	}
	return true;
}

bool CBingo::check(int _r, int _c, int dir)
{
	bool res = false;
	int cntA = 0;

	for (int y = _r, x = _c;
		(0 <= y && y < getRowSize()) && (0 <= x && x < 5);
		y += m_nARR_EIGHT_DIR[dir][0], x += m_nARR_EIGHT_DIR[dir][1])
	{
		if (y == _r && x == _c) continue;
		if (isBreak(y, x, dir, cntA, res)) break;
		if (cntA == 4) m_nBingoLineA++;
	}

	int cntB = 0;
	for (int y = _r, x = _c;
		(0 <= y && y < getRowSize()) && (5 <= x && x < 10);
		y += m_nARR_EIGHT_DIR[dir][0], x += m_nARR_EIGHT_DIR[dir][1])
	{
		if (y == _r && x == _c) continue;
		if (isBreak(y, x, dir, cntB, res)) break;
		if (cntB == 4) m_nBingoLineB++;
	}

	return res;
}

void CBingo::putStone()
{
}

bool CBingo::isInvalidPosition(char _y, char _x, int len)
{
	if (!CBoardGame::isInvalidPosition(_y, _x, len)) return false;
	int num = 0;
	const char* temp = _y + _x + "";
	try 
	{
		num = atoi(temp);
	}
	catch(exception e)
	{
		return false;
	}
	if (num > 24 || num < 0) return false;

	findNumber(num);
	canStone(getR(), getC());
	
	return true;
}

bool CBingo::countStone()
{
	if (m_nBingoLineA >= 5 || m_nBingoLineB >= 5) {
		setBingoLine(0, m_nBingoLineA);
		setBingoLine(1, m_nBingoLineB);
		return true;
	}
}

bool CBingo::passCheck()
{
	return false;
}

void CBingo::findNumber(int a_num)
{
	int cnt = 0;
	for (int i = 0; i < getRowSize(); i++) {
		for (int j = 0; j < getColSize(); j++) {
			if (getData(i, j) == a_num) {
				setData(i, j, -1);
				cnt++;
				if (cnt == 2) return;
			}
		}
	}
}

void CBingo::makeRandomNumber()
{
	srand(time(NULL));

	for (int i = 0; i < 25; i++) {
		m_nArrRandmNumber[i] = rand() % 25;
		for (int j = 0; j < i - 1; j++) {
			if (m_nArrRandmNumber[i] == m_nArrRandmNumber[j]) {
				i--;
				break;
			}
		}
	}
}

void CBingo::resetRandomNumber()
{
	for (int i = 0; i < 25; i++) m_nArrRandmNumber[i] = -1;
}

void CBingo::setRandomNumberBoard(int _startCol, int _endCol)
{
	resetRandomNumber();
	makeRandomNumber();
	int cnt = 0;
	for (int i = 0; i < getRowSize(); i++) {
		for (int j = _startCol; j < _endCol; j++) {
			setData(i, j, m_nArrRandmNumber[cnt]);
			cnt++;
		}
	}
}

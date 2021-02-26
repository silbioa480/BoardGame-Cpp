#include "CBingo.h"

bool CBingo::isBreak(int _r, int _c, int dir, int& cnt, bool& res)
{
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
		if (cntA == 4) {
			m_nBingoLineA++;
			return true;
		}
	}

	int cntB = 0;
	for (int y = _r, x = _c;
		(0 <= y && y < getRowSize()) && (5 <= x && x < 10);
		y += m_nARR_EIGHT_DIR[dir][0], x += m_nARR_EIGHT_DIR[dir][1])
	{
		if (y == _r && x == _c) continue;
		if (isBreak(y, x, dir, cntB, res)) break;
		if (cntB == 4) {
			m_nBingoLineB++;
			return true;
		}
	}

	return res;
}

void CBingo::putStone()
{
}

bool CBingo::isInvalidPosition(char _y, char _x, int len)
{
	if (!CBoardGame::isInvalidPosition(_y, _x, len)) return false;
	
	int num = -1;
	char temp[2];
	temp[0] = _y;
	temp[1] = _x;
	string str(temp);
	try 
	{
		num = stoi(str);
	}
	catch(exception e)
	{
		return false;
	}
	if (num > 24 || num < 0) return false;

	if (!findNumber(num)) return false;
	m_bBingo = lineCheck();
	changeColor();
	
	return true;
}

bool CBingo::countStone()
{
	if (m_bBingo) {
		setBingoLine(0, m_nBingoLineA);
		setBingoLine(1, m_nBingoLineB);
		return true;
	}
	return false;
}

bool CBingo::findNumber(int a_num)
{
	int cnt = 0;
	for (int i = 0; i < getRowSize(); i++) {
		for (int j = 0; j < getColSize(); j++) {
			if (getData(i, j) == a_num) {
				setData(i, j, -1);
				cnt++;
				if (cnt == 2) return true;
			}
		}
	}
	return false;
}

void CBingo::makeRandomNumber()
{
	srand(time(NULL));

	for (int i = 0; i < 25; i++) {
		m_nArrRandmNumber[i] = rand() % 25;
		for (int j = 0; j < i; j++) {
			if (m_nArrRandmNumber[i] == m_nArrRandmNumber[j]) {
				i--;
				break;
			}
		}
	}
}

void CBingo::resetRandomNumber()
{
	for (int i = 0; i < 25; i++) m_nArrRandmNumber[i] = -2;
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

bool CBingo::lineCheck()
{
	for (int i = 0; i < BINGO_ROW_SIZE; i++) {
		for (int j = 0; j < BINGO_COL_SIZE; j++) {
			if (getData(i, j) == -1) canStone(i, j);
			if (m_nBingoLineA >= 10 || m_nBingoLineB >= 10) return true;
		}
	}
	m_nBingoLineA = 0;
	m_nBingoLineB = 0;
	return false;
}

#include "CBingo.h"

bool CBingo::isBreak(int, int, int, int&, bool&)
{
	return false;
}

bool CBingo::check(int, int, int)
{
	return false;
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
	
	return true;
}

bool CBingo::countStone()
{
	return false;
}

bool CBingo::passCheck()
{
	return false;
}

int CBingo::findNumber(int a_num)
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

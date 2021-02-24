#ifndef __C_PRINT_BOARD_GAME_H__
#define __C_PRINT_BOARD_GAME_H__
#include <iostream>
using namespace std;

class CPrintBoardGame
{
private:
	int** dat;
	int m_nSize;

	virtual void printUITop() = 0;
	virtual void printUIRight(int) = 0;
	virtual void printLine(int, int) = 0;
	virtual void printLineWide(int) = 0;
	virtual string getLine(string, int, int) = 0;

public:
	CPrintBoardGame(int** a_dat, int a_nSize) : dat(a_dat), m_nSize(a_nSize) {}
	virtual void printBoard() = 0;

	int getData(int _r, int _c) { return dat[_r][_c]; }
	int getSize() { return m_nSize; }

	const string m_sLINE[11] = {
		"¦¡", "¦¢",
		"¦£", "¦¨", "¦¤",
		"¦§", "¦«", "¦©",
		"¦¦", "¦ª", "¦¥"
	};
	const string m_sSTONE[3] = { "¡Û", "", "¡Ü" };
};
#endif
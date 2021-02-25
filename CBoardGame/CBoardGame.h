
#ifndef __C_BOARD_GAME_H__
#define __C_BOARD_GAME_H__
using namespace std;

class CBoardGame
{
private:
	int** dat = 0;
	int m_nRowSize = 0, m_nColSize = 0;
	int m_nColor = 1;
	int r = 0, c = 0;
	int m_nWhite = 0, m_nBlack = 0;
	int m_nBingoLine[2] = { 0, };
	bool m_bPos = false;

public:
	CBoardGame(int a_nRowSize, int a_nColSize) : m_nRowSize(a_nRowSize), m_nColSize(a_nColSize)
	{
		dat = (int**) new int* [m_nRowSize];
		for (int r = 0; r < m_nRowSize; r++) dat[r] = (int*) new int[m_nColSize] {};
	}

	virtual bool isBreak(int, int, int, int&, bool&);
	virtual bool check(int, int, int);
	bool canStone(int, int);
	virtual void putStone();
	void changeColor() { m_nColor *= -1; }
	virtual bool isInvalidPosition(char, char, int);
	virtual bool countStone() = 0;
	virtual bool passCheck() = 0;

	int getData(int _r, int _c) { return dat[_r][_c]; }
	void setData(int _r, int _c, int _color) { dat[_r][_c] = _color; }

	int getColor() { return m_nColor; }
	void setColor(int _color) { m_nColor = _color; }

	int getRowSize() { return m_nRowSize; }
	int getColSize() { return m_nColSize; }

	bool getPos() { return m_bPos; }
	void setPos(bool a_bPos) { m_bPos = a_bPos; }

	int getR() { return r; }
	int getC() { return c; }

	int getWhite() { return m_nWhite; }
	void setWhite(int a_nWhite) { m_nWhite = a_nWhite; }
	int getBlack() { return m_nBlack; }
	void setBlack(int a_nBlack) { m_nBlack = a_nBlack; }

	int getBingoLine(int _player) { return m_nBingoLine[_player]; }
	void setBingoLine(int _player, int _line) { m_nBingoLine[_player] = _line; }

	int** getBoard() { return dat; }

	~CBoardGame()
	{
		for (int r = 0; r < m_nRowSize; r++) delete(dat[r]);
		delete(dat);
	}

	const int m_nARR_EIGHT_DIR[8][2] = {
		{1, -1},
		{1, 0},
		{1, 1},
		{0, -1},
		{0, 1},
		{-1, -1},
		{-1, 0},
		{-1, 1},
	};

	enum {
		DownLeft = 0,
		Down,
		DownRight,
		Left,
		Right,
		UpLeft,
		Up,
		UpRight
	};
};
#endif
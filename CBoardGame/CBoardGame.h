
#ifndef __C_BOARD_GAME_H__
#define __C_BOARD_GAME_H__

class CBoardGame
{
private:
	int** dat = 0;
	int m_nSize = 0;
	int m_nColor = 1;
	int r = 0, c = 0;
	int m_nWhite = 0, m_nBlack = 0;
	bool m_bPos = false;

public:
	CBoardGame(int a_size) : m_nSize(a_size)
	{
		dat = (int**) new int* [m_nSize];
		for (int r = 0; r < m_nSize; r++) dat[r] = (int*) new int[m_nSize] {};
	}

	virtual bool isBreak(int, int, int, int&, bool&);
	virtual bool check(int, int, int);
	bool canStone(int, int);
	virtual void putStone();
	virtual bool isInvalidPosition(char, char, int);
	virtual bool countStone() = 0;
	virtual bool passCheck() = 0;

	int getData(int _r, int _c) { return dat[_r][_c]; }
	void setData(int _r, int _c, int _color) { dat[_r][_c] = _color; }

	int getColor() { return m_nColor; }
	void setColor(int _color) { m_nColor = _color; }

	int getSize() { return m_nSize; }

	bool getPos() { return m_bPos; }

	int getWhite() { return m_nWhite; }
	void setWhite(int a_nWhite) { m_nWhite = a_nWhite; }
	int getBlack() { return m_nBlack; }
	void setBlack(int a_nBlack) { m_nBlack = a_nBlack; }

	int** getBoard() { return dat; }

	~CBoardGame()
	{
		for (int r = 0; r < m_nSize; r++) delete(dat[r]);
		delete(dat);
	}

	const int m_nARR_EIGHT_DIR[2][8] = { {1, 1, 1, 0, 0, -1, -1, -1}, {-1, 0, 1, -1, 1, -1, 0, 1} };

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
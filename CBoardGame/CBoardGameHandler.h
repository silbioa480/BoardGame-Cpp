#ifndef __C_BOARD_GAME_HANDLER_H__
#define __C_BOARD_GAME_HANDLER_H__
#include "COmok.h"
#include "COthello.h"
#include "CBingo.h"
#include "CPrintOmok.h"
#include "CPrintOthello.h"
#include "CPrintBingo.h"

class CBoardGameHandler
{
private:
	CBoardGame* BG;
	CPrintBoardGame* PG;

	int m_nGame = 0;
	char m_cPosition[10] = { 0, };

	enum {
		Omok = 1,
		Othello,
		Bingo
	};
	enum {
		WHITE = 1,
		BLACK = -1
	};

public:
	CPrintBoardGame* selectGame();
	void gameProgress(bool&);
	void gameResult();
};
#endif
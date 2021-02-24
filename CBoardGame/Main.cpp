#include "CBoardGameHandler.h"

int main() {
	bool bWinCheck = false;

	class CBoardGameHandler handler;
	class CPrintBoardGame* printBG = handler.selectGame();

	while (!bWinCheck)
	{
		printBG->printBoard();
		handler.gameProgress(bWinCheck);
	}
	printBG->printBoard();
	handler.gameResult();

	return 0;
}
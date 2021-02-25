#include "CBoardGameHandler.h"

CPrintBoardGame* CBoardGameHandler::selectGame()
{
	while (true) {
		printf("select game : 1) omok, 2) othello\n");
		scanf_s("%d", &m_nGame);

		if (m_nGame == Omok) {
			COmok* OM = new COmok(OMOK_SIZE, OMOK_SIZE);
			BG = OM;
			CPrintNarrow* PN = new CPrintNarrow(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PN;
			break;
		}
		else if (m_nGame == Othello) {
			COthello* OTH = new COthello(OTHELLO_SIZE, OTHELLO_SIZE);
			BG = OTH;
			CPrintWide* PW = new CPrintWide(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PW;
			break;
		}
		else if (m_nGame == Bingo) {
			CBingo* BINGO = new CBingo(BINGO_ROW_SIZE, BINGO_COL_SIZE);
			BG = BINGO;
			CPrintBingo* PBINGO = new CPrintBingo(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PBINGO;
		}
		else printf("잘못된 값입니다.\n\n");
	}

	return PG;
}

void CBoardGameHandler::gameProgress(bool& a_bWinCheck)
{
	int nPass = 0;

	printf("\n%s 차례입니다.\n", BG->getColor() == WHITE ? "●백돌" : "○흑돌");

	while (true) {
		if (BG->passCheck() == false) {
			nPass++;
			if (nPass == 2) {
				a_bWinCheck = BG->countStone();
				break;
			}
			printf("%s돌을 둘 자리가 없어 패스되었습니다.\n", BG->getColor() == WHITE ? "●백" : "○흑");
			BG->setColor(BG->getColor() * -1);
			printf("\n%s 차례입니다.\n", BG->getColor() == WHITE ? "●백돌" : "○흑돌");
			continue;
		}
		printf("Input Position: ");
		scanf_s("%s", m_cPosition, sizeof(m_cPosition));
		if (BG->isInvalidPosition(m_cPosition[0], m_cPosition[1], strlen(m_cPosition)) == false) {
			printf("\nINVALID POSITION\n");
		}
		else break;
	}
	BG->putStone();
	if (m_nGame == Omok) a_bWinCheck = BG->countStone();
}

void CBoardGameHandler::gameResult()
{
	if (m_nGame == Othello) {
		printf("●백: %d  ○흑: %d\n", BG->getWhite(), BG->getBlack());
		if (BG->getWhite() == BG->getBlack()) printf("무승부");
		else printf("%s이 승리하였습니다.", BG->getWhite() > BG->getBlack() ? "●백" : "○흑");
	}
	else printf("%s이 승리하였습니다.", BG->getColor() == BLACK ? "●백" : "○흑");
}

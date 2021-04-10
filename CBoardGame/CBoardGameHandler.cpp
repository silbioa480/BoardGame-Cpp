#include "CBoardGameHandler.h"

CPrintBoardGame* CBoardGameHandler::selectGame()
{
	printf("보드판이 제대로 출력되지 않는다면 콘솔창 제목줄을 우클릭 한 뒤\n속성 - 옵션 탭의 '레거시 콘솔 사용'을 체크한 뒤 다시 실행해주세요.\n\n");
	while (true) {
		printf("select game : 1) omok, 2) othello 3) bingo\n");
		scanf_s("%d", &m_nGame);

		if (m_nGame == Omok) {
			BG = new COmok(OMOK_SIZE, OMOK_SIZE);
			PG = new CPrintOmok(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			break;
		}
		else if (m_nGame == Othello) {
			BG = new COthello(OTHELLO_SIZE, OTHELLO_SIZE);
			PG = new CPrintOthello(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			break;
		}
		else if (m_nGame == Bingo) {
			BG = new CBingo(BINGO_ROW_SIZE, BINGO_COL_SIZE);
			PG = new CPrintBingo(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			break;
		}
		else printf("잘못된 값입니다.\n\n");
	}

	return PG;
}

void CBoardGameHandler::gameProgress(bool& a_bWinCheck)
{
	int nPass = 0;

	cout << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << " 차례입니다.\n";
	while (true) {
		if (BG->passCheck() == false) {
			nPass++;
			if (nPass == 2) {
				a_bWinCheck = BG->countStone();
				break;
			}
			cout << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "돌을 둘 자리가 없어 패스되었습니다.\n\n";
			BG->setColor(BG->getColor() * -1);
			cout << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << " 차례입니다.\n";
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
	if (m_nGame == Omok || m_nGame == Bingo) a_bWinCheck = BG->countStone();
}

void CBoardGameHandler::gameResult()
{
	if (m_nGame == Othello) {
		cout << PG->m_sPlayer[0] << ": " << BG->getWhite() << "  " << PG->m_sPlayer[1] << ": " << BG->getBlack() << "\n";
		if (BG->getWhite() == BG->getBlack()) printf("무승부");
		else cout << ((BG->getWhite() > BG->getBlack()) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "이 승리했습니다.";
	}
	else if (m_nGame == Bingo) {
		if (BG->getBingoLine(0) == BG->getBingoLine(1)) printf("무승부");
		else cout << ((BG->getBingoLine(0) > BG->getBingoLine(1)) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "이 승리했습니다.";
	}
	else cout << ((BG->getColor() == BLACK) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "이 승리했습니다.";
}

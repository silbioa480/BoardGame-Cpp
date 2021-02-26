#include "CBoardGameHandler.h"

CPrintBoardGame* CBoardGameHandler::selectGame()
{
	while (true) {
		printf("select game : 1) omok, 2) othello 3) bingo\n");
		scanf_s("%d", &m_nGame);

		if (m_nGame == Omok) {
			COmok* OM = new COmok(OMOK_SIZE, OMOK_SIZE);
			BG = OM;
			CPrintOmok* PN = new CPrintOmok(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PN;
			break;
		}
		else if (m_nGame == Othello) {
			COthello* OTH = new COthello(OTHELLO_SIZE, OTHELLO_SIZE);
			BG = OTH;
			CPrintOthello* PW = new CPrintOthello(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PW;
			break;
		}
		else if (m_nGame == Bingo) {
			CBingo* BINGO = new CBingo(BINGO_ROW_SIZE, BINGO_COL_SIZE);
			BG = BINGO;
			CPrintBingo* PBINGO = new CPrintBingo(BG->getBoard(), BG->getRowSize(), BG->getColSize());
			PG = PBINGO;
			break;
		}
		else printf("�߸��� ���Դϴ�.\n\n");
	}

	return PG;
}

void CBoardGameHandler::gameProgress(bool& a_bWinCheck)
{
	int nPass = 0;

	cout << "\n" << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << " �����Դϴ�.\n";
	while (true) {
		if (BG->passCheck() == false) {
			nPass++;
			if (nPass == 2) {
				a_bWinCheck = BG->countStone();
				break;
			}
			cout << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "���� �� �ڸ��� ���� �н��Ǿ����ϴ�.\n\n";
			BG->setColor(BG->getColor() * -1);
			cout << "\n" << ((BG->getColor() == WHITE) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << " �����Դϴ�.\n";
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
		if (BG->getWhite() == BG->getBlack()) printf("���º�");
		else cout << ((BG->getWhite() > BG->getBlack()) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "�� �¸��߽��ϴ�.";
	}
	else if (m_nGame == Bingo) {
		if (BG->getBingoLine(0) == BG->getBingoLine(1)) printf("���º�");
		else cout << ((BG->getBingoLine(0) > BG->getBingoLine(1)) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "�� �¸��߽��ϴ�.";
	}
	else cout << ((BG->getColor() == BLACK) ? PG->m_sPlayer[0] : PG->m_sPlayer[1]) << "�� �¸��߽��ϴ�.";
}

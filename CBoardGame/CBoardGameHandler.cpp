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
		else printf("�߸��� ���Դϴ�.\n\n");
	}

	return PG;
}

void CBoardGameHandler::gameProgress(bool& a_bWinCheck)
{
	int nPass = 0;

	printf("\n%s �����Դϴ�.\n", BG->getColor() == WHITE ? "�ܹ鵹" : "���浹");

	while (true) {
		if (BG->passCheck() == false) {
			nPass++;
			if (nPass == 2) {
				a_bWinCheck = BG->countStone();
				break;
			}
			printf("%s���� �� �ڸ��� ���� �н��Ǿ����ϴ�.\n", BG->getColor() == WHITE ? "�ܹ�" : "����");
			BG->setColor(BG->getColor() * -1);
			printf("\n%s �����Դϴ�.\n", BG->getColor() == WHITE ? "�ܹ鵹" : "���浹");
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
		printf("�ܹ�: %d  ����: %d\n", BG->getWhite(), BG->getBlack());
		if (BG->getWhite() == BG->getBlack()) printf("���º�");
		else printf("%s�� �¸��Ͽ����ϴ�.", BG->getWhite() > BG->getBlack() ? "�ܹ�" : "����");
	}
	else printf("%s�� �¸��Ͽ����ϴ�.", BG->getColor() == BLACK ? "�ܹ�" : "����");
}

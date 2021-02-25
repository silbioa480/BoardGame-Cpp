#include "CPrintWide.h"

void CPrintWide::printUITop()
{
	cout << "  0   1   2   3   4   5   6   7";
	cout << "\n";
}

void CPrintWide::printUIRight(int _r)
{
	cout << "\n";
}

void CPrintWide::printLine(int si, int _r)
{
	string s = m_sLINE[si];
	cout << getLine(s, _r, 0);

	s = m_sLINE[0] + m_sLINE[si + 1];
	for (int i = 1; i <= getColSize() - 2; i++) cout << getLine(s, _r, i);

	s = m_sLINE[0] + m_sLINE[si + 2];
	cout << getLine(s, _r, getColSize() - 1);
	printUIRight(_r);
}

void CPrintWide::printLineWide(int _r)
{
	string s = m_sLINE[1];
	cout << s;

	int data;
	for (int _c = 0; _c < getColSize() - 1; _c++)
	{
		data = getData(_r, _c);
		cout << ((data != 0) ? m_sSTONE[data + 1] : "  ") << s;
	}
	cout << _r << "\n";
}

string CPrintWide::getLine(string _line, int _r, int _c)
{
	return _line;
}

void CPrintWide::printBoard()
{
	system("cls");
	printUITop();

	printLine(2, 0);

	for (int m_sLINE = 1; m_sLINE < getRowSize() - 1; m_sLINE++)
	{
		printLineWide(m_sLINE - 1);
		printLine(5, m_sLINE);
	}
	printLineWide(getRowSize() - 2);
	printLine(8, getRowSize() - 1);
}

#include "CPrintBingo.h"

void CPrintBingo::printUITop()
{
    cout << " 1P                     2P\n";
}

void CPrintBingo::printLine(int si, int _r)
{
	string s = m_sLINE[si];

	cout << getLine(s, _r, 0);
	s = m_sLINE[0] + m_sLINE[si + 1];
	for (int i = 1; i <= (getColSize() / 2) - 2; i++) cout << getLine(s, _r, i);
	s = m_sLINE[0] + m_sLINE[si + 2];
	cout << getLine(s, _r, getColSize() - 1) << " ";

	s = m_sLINE[si];
	cout << getLine(s, _r, 0);
	s = m_sLINE[0] + m_sLINE[si + 1];
	for (int i = 1; i <= (getColSize() / 2) - 2; i++) cout << getLine(s, _r, i);
	s = m_sLINE[0] + m_sLINE[si + 2];
	cout << getLine(s, _r, getColSize() - 1);

	printUIRight(_r);
}

void CPrintBingo::printLineWide(int _r)
{
	string s = m_sLINE[Vert];
	cout << s;

	int data;
	for (int _c = 0; _c < (getColSize() / 2) - 1; _c++)
	{
		data = getData(_r, _c);
		if (data == -1) cout << m_sSTONE[2];
		else printf("%02d", getData(_r, _c));
		cout << s;
	}
	cout << " " << s;

	for (int _c = 5; _c < getColSize() - 2; _c++)
	{
		data = getData(_r, _c);
		if (data == -1) cout << m_sSTONE[2];
		else printf("%02d", getData(_r, _c));
		cout << s;
	}
	cout << "\n";
}
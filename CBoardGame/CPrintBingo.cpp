#include "CPrintBingo.h"

void CPrintBingo::printUITop()
{
    cout << " 1P                     2P\n";
}

void CPrintBingo::printLine(int si, int _r)
{
	int t = 0;
	while (t != 2)
	{
		string s = m_sLINE[si];
		cout << getLine(s, _r, 0);
		s = m_sLINE[0] + m_sLINE[si + 1];
		for (int i = 1; i <= (getColSize() / 2) - 2; i++) cout << getLine(s, _r, i);
		s = m_sLINE[0] + m_sLINE[si + 2];
		cout << getLine(s, _r, getColSize() - 1);

		if (t == 0) printf(" ");
		t++;
	}
	cout << "\n";
}

void CPrintBingo::printLineWide(int _r)
{
	string s = m_sLINE[Vert];
	cout << s;

	int data;
	for (int _c = 0; _c < getColSize() - 2; _c++)
	{
		data = getData(_r, _c);
		if (data == -1) cout << m_sSTONE[2];
		else printf("%02d", getData(_r, _c));
		cout << s;

		if (_c == 4) cout << " " << s;;
	}
	cout << "\n";
}
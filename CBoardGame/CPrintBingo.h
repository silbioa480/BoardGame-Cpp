#ifndef __C_PRINT_BINGO_H__
#define __C_PRINT_BINGO_H__
#include "CPrintWide.h"

class CPrintBingo : public CPrintWide
{
private:

public:
	CPrintBingo(int** a_dat, int a_nRowSize, int a_nColSize) : CPrintWide(a_dat, a_nRowSize, a_nColSize + 2) { 
		m_sSTONE[0] = "¡Ü"; 
		m_sPlayer[0] = "1P";
		m_sPlayer[1] = "2P";
	}
};
#endif
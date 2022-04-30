//---------------------------------------------------------------------------
#ifndef buracosH
#define buracosH

#include "buraco.h"


class BuracosTabuleiro
{
private:
	Buraco * First;

public:
	BuracosTabuleiro(Buraco *);

	Buraco * Find(int, int, int);
	void Insert(Buraco *);
	int Change(Buraco *);
};

//---------------------------------------------------------------------------
#endif

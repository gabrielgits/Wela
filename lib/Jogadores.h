//---------------------------------------------------------------------------

#ifndef JogadoresH
#define JogadoresH

#include "jogador.h"

class JogadoresTabuleiro
{
private:
	Jogador *First;

public:
	JogadoresTabuleiro(Jogador *);

	Jogador * Find(int Pos);
	void Insert(Jogador *);
	int Change(Jogador *);
};


//---------------------------------------------------------------------------
#endif

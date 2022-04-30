//---------------------------------------------------------------------------

#ifndef jogadorH
#define jogadorH
#include "buracos.h"
#include <stdio.h>

#define Texto char*

class Jogador
{
private:
	Texto Name;
	Texto Sexo;
	int Position;
	Jogador *Next;

public:
	Jogador(Jogador *Entrada);

	void SetName(Texto);
	void SetSexo(Texto);
	void SetPosition(int );

	Texto GetName();
	Texto GetSexo();
	int GetPosition();

	Jogador *GetNext();
	void SetNext(Jogador *);
};

//---------------------------------------------------------------------------
#endif

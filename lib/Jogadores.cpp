//---------------------------------------------------------------------------

#pragma hdrstop

#include "Jogadores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


JogadoresTabuleiro::JogadoresTabuleiro(Jogador * Entrada)
{
	First = Entrada;
}

Jogador * JogadoresTabuleiro::Find(int Pos)
{
	Jogador * aux = First;
	while(aux != NULL)
	{
		if (aux->GetPosition() == Pos)
			return aux;
		aux = aux->GetNext();
	}
	return NULL;
}

void JogadoresTabuleiro::Insert(Jogador *Entrada)
{
	if(First == NULL)
	{
		First = new Jogador(Entrada);
	}
	else
	{
		Jogador * aux = First;
		while(aux->GetNext() != NULL)
			aux = aux->GetNext();
		aux->SetNext(Entrada);
	}
}

int JogadoresTabuleiro::Change(Jogador *Entrada)
{
	if(Entrada != NULL)
	{
		Jogador *aux = Find(Entrada->GetPosition());
		if (aux != NULL)
		{
			aux = Entrada;
			return 1;
		}
	}
	return 0;
}

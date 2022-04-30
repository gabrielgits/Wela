//---------------------------------------------------------------------------

#pragma hdrstop

#include "buracos.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------


BuracosTabuleiro::BuracosTabuleiro(Buraco * Temp)
{
	First = Temp;
}

Buraco * BuracosTabuleiro::Find(int player, int line,int pos)
{
	Buraco * aux = First;
	while(aux != NULL)
	{
		if ((aux->GetPlayer() == player) && (aux->GetLine() == line) && (aux->GetPosition() == pos))
			return aux;
		aux = aux->GetNext();
	}
	return NULL;
}

void BuracosTabuleiro::Insert(Buraco *Temp)
{
	if(First == NULL)
	{
		First = new Buraco(Temp);
	}
	else
	{
		Buraco * aux = First;
		while(aux->GetNext() != NULL)
			aux = aux->GetNext();
		aux->SetNext(Temp);
	}
}

int BuracosTabuleiro::Change(Buraco *Temp)
{
	if(Temp != NULL)
	{
		Buraco *aux = Find(Temp->GetPlayer(),Temp->GetLine(),Temp->GetPosition());
		if (aux != NULL)
		{
			aux = Temp;
			return 1;
		}
	}
	return 0;
}


//---------------------------------------------------------------------------

#pragma hdrstop

#include "jogador.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)


Jogador::Jogador(Jogador * Entrada)
{
	Name = Entrada->Name;
	Sexo = Entrada->Sexo;
	Position = Entrada->Position;
	Next = NULL;
}

void Jogador::SetName(Texto name)
{
	Name = name;
}

Texto Jogador::GetName()
{
	return Name;
}

void Jogador::SetSexo(Texto sexo)
{
	Sexo = sexo;
}

Texto Jogador::GetSexo()
{
	return Sexo;
}


void Jogador::SetPosition(int position)
{
	Position = position;
}

int Jogador::GetPosition()
{
	return Position;
}

Jogador *Jogador::GetNext()
{
	return Next;
}

void Jogador::SetNext(Jogador * Entrada)
{
	Next = new Jogador(Entrada);
}



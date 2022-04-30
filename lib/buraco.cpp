//---------------------------------------------------------------------------
#pragma hdrstop

#include "buraco.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

Buraco::Buraco(Buraco* Temp)
{
	Position = Temp->Position;
	QuantPedra = Temp->QuantPedra;
	Line = Temp->Line;
	Player = Temp->Player;
	Next = NULL;
}

int Buraco::GetPosition()
{
	return Position;
}

int Buraco::GetQuantPedra()
{
	return QuantPedra;
}

int Buraco::GetLine()
{
	return Line;
}

int Buraco::GetPlayer()
{
	return Player;
}

void Buraco::SetPosition(int Temp)
{
	Position = Temp;
}

void Buraco::SetQuantPedra(int Temp)
{
	QuantPedra = Temp;
}

void Buraco::SetLine(int Temp)
{
	Line = Temp;
}

void Buraco::SetPlayer(int Temp)
{
	Player = Temp;
}


Buraco *Buraco::GetNext()
{
	return Next;
}

void Buraco::SetNext(Buraco * Temp)
{
	Next = new Buraco(Temp);
}




//---------------------------------------------------------------------------

#pragma hdrstop

#include "chandswela.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

Wela::Wela(Jogador * EntradaJ,Buraco * EntradaB)
{
	jogadores = new JogadoresTabuleiro(EntradaJ);
	buracos = new BuracosTabuleiro(EntradaB);
	QuantJogador = 0;
	QuantBuraco = 0;
}

int Wela::GetQuantJogador()
{
	return QuantJogador;
}

int Wela::GetQuantBuraco()
{
	return QuantBuraco;
}
void Wela::SetQuantBuraco(int Entrada)
{
	QuantBuraco = Entrada;
}

void Wela::StartBoard(Jogador *EntradaJ,int QPedra)
{
	Buraco *aux;
	int QBuraco = QuantBuraco;
	for (int i = 0; i < QBuraco; i++)
	{
		aux = new Buraco(aux);
		aux->SetPlayer(EntradaJ->GetPosition());
		aux->SetPosition(i);
		aux->SetQuantPedra(QPedra);
		aux->SetLine(0);
		buracos->Insert(aux);
		delete aux;
	}
	for (int i = 0; i < QBuraco; i++)
	{
		aux = new Buraco(aux);
		aux->SetPlayer(EntradaJ->GetPosition());
		aux->SetPosition(i);
		aux->SetQuantPedra(QPedra);
		aux->SetLine(1);
		if(QBuraco*0.25 < i)
			aux->SetQuantPedra(0);
		buracos->Insert(aux);
		delete aux;
	}
}

void Wela::StartGame(Jogador * Entrada,int ValorP)
{
	jogadores->Insert(Entrada);

	StartBoard(Entrada,ValorP);
	QuantJogador++;
}

void Wela::Movimet(Buraco * &Entrada, int Pedras)
{
	while (Pedras > 0)
	{
		if (Entrada->GetPosition() == QuantBuraco-1)
		{
			Entrada = buracos->Find(Entrada->GetPlayer(),!Entrada->GetLine(),0);
			Entrada->SetQuantPedra(Entrada->GetQuantPedra() + 1);
			Pedras--;
		}
		else if(Entrada->GetNext() != NULL)
		{
			Entrada = Entrada->GetNext();
			Entrada->SetQuantPedra(Entrada->GetQuantPedra() + 1);
			Pedras--;
		}
	}
}

void Wela::MovimetLines(Buraco * &Entrada,Jogador* JOG,Jogador* ADVER)
{
	int Pedras = ClickBuraco(Entrada);
	Movimet(Entrada,Pedras);
	if (Entrada->GetQuantPedra() > 1)
	{
		Pedras = VerifyPlayed(Entrada,JOG,ADVER);
		if (Pedras > 0)
			SpecialMovimet(Entrada,JOG,ADVER,Pedras);
		else
			MovimetLines(Entrada,JOG,ADVER);
	}
}

int Wela::ClickBuraco(Buraco * Temp)
{
	int Pedras = Temp->GetQuantPedra();
	Temp->SetQuantPedra(0);
	return Pedras;
}

int Wela::Play(int jogador,int adversario, int linha,int buraco)
{
	Jogador * Jaux = jogadores->Find(jogador);
	Jogador * Jaux2 = jogadores->Find(adversario);
	if ((Jaux != NULL) && (Jaux2 != NULL))
	{
		Buraco * Baux = buracos->Find(Jaux->GetPosition(),linha,buraco);
		MovimetLines(Baux,Jaux,Jaux2);
		return 1;
	}
	return 0;
}

int Wela::WinPedra(Buraco * Entrada,Buraco * Repro)
{
	int Pedras = Entrada->GetQuantPedra();
	Pedras += Repro->GetQuantPedra();
	Entrada->SetQuantPedra(0);
	Repro->SetQuantPedra(0);
	return Pedras;
}

int Wela::VerifyPlayed(Buraco * Entrada,Jogador * JOG,Jogador * ADVER)
{
	int Pedras = 0;
	if (Entrada->GetLine() == 1)
	{
		Buraco * BaxuJOG = buracos->Find(JOG->GetPosition(),1,Entrada->GetPosition());
		Buraco * BaxuADVER = buracos->Find(ADVER->GetPosition(),1,(QuantBuraco - BaxuJOG->GetPosition()-1));
		if (BaxuADVER->GetQuantPedra() > 0)
		{
			Buraco * Bcouj = buracos->Find(ADVER->GetPosition(),0,BaxuJOG->GetPosition());
			Pedras = WinPedra(BaxuADVER,Bcouj);
		}
	}
	return Pedras;
}

void Wela::SpecialMovimet(Buraco * &Entrada,Jogador* JOG,Jogador* ADVER, int Pedras)
{
	Movimet(Entrada,Pedras);
	if (Entrada->GetQuantPedra() > 1)
	{
		Pedras = VerifyPlayed(Entrada,JOG,ADVER);
		if (Pedras > 0)
			SpecialMovimet(Entrada,JOG,ADVER,Pedras);
		else
			MovimetLines(Entrada,JOG,ADVER);
	}
}

Jogador * Wela::FindJogador(int Pos)
{
	return jogadores->Find(Pos);
}

Buraco * Wela::FindBuraco(int jogad,int linha,int buraco)
{
	return buracos->Find(jogad,linha,buraco);
}

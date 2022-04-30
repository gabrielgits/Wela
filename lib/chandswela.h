//---------------------------------------------------------------------------

#ifndef chandswelaH
#define chandswelaH
#endif
#include <stdio.h>
#include "Jogadores.h"
#include "buracos.h"


class Wela
{
private:
	JogadoresTabuleiro *jogadores;
	BuracosTabuleiro *buracos;
	int QuantJogador;
	int QuantBuraco;

protected:
	int ClickBuraco(Buraco *);
	void Movimet(Buraco * &Entrada,int Pedras);
	int VerifyPlayed(Buraco * Entrada,Jogador * JOG,Jogador * ADVER);    // VerificarJogada
	int WinPedra(Buraco * Entrada,Buraco * Repro);
	void MovimetLines(Buraco * &Entrada,Jogador* JOG,Jogador* ADVER);
	void SpecialMovimet(Buraco * &Entrada,Jogador* JOG,Jogador* ADVER, int Pedras);
	void StartBoard(Jogador *EntradaJ,int QPedra);

public:
	Wela(Jogador * EntradaJ,Buraco * EntradaB);

	int GetQuantJogador();

	int GetQuantBuraco();
	void SetQuantBuraco(int);

	void StartGame(Jogador * Entrada,int ValorP);
	int Play(int jogador,int adversario, int linha,int buraco);

	Jogador * FindJogador(int Pos);
	Buraco * FindBuraco(int jogad,int linha,int buraco);
};


//---------------------------------------------------------------------------

 

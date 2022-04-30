//---------------------------------------------------------------------------

#ifndef buracoH
#define buracoH
#endif
//---------------------------------------------------------------------------

#include <stdio.h>

class Buraco
{
private:
	int Position;
	int QuantPedra;
	int Line;
	int Player;
	Buraco *Next;
public:
	Buraco(Buraco*);

	int GetPosition();
	int GetQuantPedra();
	int GetLine();
	int GetPlayer();

	void SetPosition(int);
	void SetQuantPedra(int);
	void SetLine(int);
	void SetPlayer(int);

	Buraco *GetNext();
	void SetNext(Buraco *);
};





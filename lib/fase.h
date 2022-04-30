#ifndef faseH
#define faseH

#endif

#include "figura.h"
#include "chandsfilelog.h"
#include "chandswela.h"
#include "jogador.h"
#include "sprite.h"

struct movimento
{
       int esquerda;
       int direita;
       int cima;
       int baixo;
       
};
class Fase
{
private:
        char* Nome;
        int Numero;
        SDL_Surface* Video;
        Figura Personagens;
        Figura Fundo;
        Figura Cursor;
        ArchiveLog LogFase;
        movimento fundo;
        Wela *Jogo;
        Animacao *Buracos;
        int QuantBuracos;
//protected:
public:
       Fase();
       void SetNome(char * nometemp);
       void SetQuantBuracos(int temp);
       int GetQuantBuracos();
       int IniciarLog(char *);
       int CarregarVideo(int Lar,int Alt);
       int CarregarPersonagens(char* nome, int Lar, int Alt);
       int CarregarFundo(char* nome, int Lar, int Alt);
       int CarregarCursor(char* nome, int Lar, int Alt);
       int CarregarAnimacao(char* nome, int Lar, int Alt, int Slar, int Salt);
       void CentrarPersonagem();
       int AtualizarPosicao();
       int Desenhar();
       int Iniciar();
       int Evento();
       int Rodar();
       int OrdenaTabu();
       int AtualizarBuracos();
       void Fechar();
};


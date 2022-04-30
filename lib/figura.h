#ifndef figuraH
#define figuraH
#include <SDL_image.h>


class Figura
{
protected:
        SDL_Surface *Image;
	    int TelaX;
        int TelaY;
	    int Largura; 
        int Altura;
	    char* Erro; 
public:
       Figura();
       
       SDL_Surface * GetImage();
       int GetTelaX();
       int GetTelaY();
       int GetLargura();
       int GetAltura();
       
       void SetImage(SDL_Surface *);
       void SetLargura(int);
       void SetAltura(int);
       void SetTelaX(int);
       void SetTelaY(int);
       
       int Abrir(char * Caminho,int largura,int altura);
       char * GetErro();
       void SetErro(char * erro);
       void Fechar();
};
#endif

#pragma hdrstop
#include "figura.h"
#pragma package(smart_init)




Figura::Figura()
{
        Image = NULL;
	    TelaX = 0;
        TelaY = 0; 
	    Largura = 0; 
        Altura = 0; 
}
int Figura::Abrir(char * Caminho,int largura,int altura)
{
        SDL_Surface* ImageTemp = NULL;
        ImageTemp = IMG_Load(Caminho);
        if (!ImageTemp)
        {
           SetErro("Erro ao Carregar Arquivo");
           return 0;
        }
        Image = SDL_DisplayFormat(ImageTemp);
        if (Image == NULL)
        {
            SetErro(SDL_GetError());
            return 0;      
        }
	    TelaX = 0;
        TelaY = 0; 
	    Largura = largura; 
        Altura = altura; 
        SDL_FreeSurface(ImageTemp);
        return 1;
}
char * Figura::GetErro()
{
         return Erro;  
}
void Figura::SetErro(char * erro)
{
     Erro = erro;  
}
SDL_Surface * Figura::GetImage()
{
         return Image;
}
int Figura::GetTelaX()
{
         return TelaX;  
}
int Figura::GetTelaY()
{
         return TelaY;  
}
int Figura::GetLargura()
{
         return Largura;  
}
int Figura::GetAltura()
{
         return Altura;  
}

void Figura::SetImage(SDL_Surface * Temp)
{
     Image = Temp;         
}
void Figura::SetTelaX(int Temp)
{
     TelaX = Temp;         
}
void Figura::SetTelaY(int Temp)
{
     TelaY = Temp;         
}
void Figura::SetLargura(int Temp)
{
     Largura = Temp;         
}
void Figura::SetAltura(int Temp)
{
     Altura = Temp;         
}
void Figura::Fechar()
{
    SDL_FreeSurface(Image); 
}

#pragma hdrstop
#include "sprite.h"
#pragma package(smart_init)



int Animacao::GetLarguraS()
{
    return LarguraS;  
}
int Animacao::GetAlturaS()
{
    return AlturaS;  
}
void Animacao::SetLarguraS(int Temp)
{
    LarguraS = Temp;         
}
void Animacao::SetAlturaS(int Temp)
{
    AlturaS = Temp;         
}

int Animacao::GetCordenadaX()
{
    return CordenadaX;  
}
int Animacao::GetCordenadaY()
{
    return CordenadaY;  
}
void Animacao::SetCordenadaX(int Temp)
{
    CordenadaX = Temp;         
}
void Animacao::SetCordenadaY(int Temp)
{
    CordenadaY = Temp;         
}

int Animacao::MudarCordenadas(int posX, int posY)
{
    SetCordenadaX(posX * GetLarguraS());
    SetCordenadaY(posY * GetAlturaS());
    return 1;
}

int Animacao::Abrir(char * Caminho,int largura,int altura, int larguraS, int alturaS)
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
        
        CordenadaX = 0;
        CordenadaY = 0; 
        LarguraS = larguraS;
        AlturaS = alturaS;
        
        SDL_FreeSurface(ImageTemp);
        return 1;
}


#ifndef spriteH
#define spriteH
#endif
#include "figura.h"


class Animacao : public Figura
{
protected: 
    int LarguraS;
    int AlturaS;
    int CordenadaX;
    int CordenadaY;  
public:
    void SetLarguraS(int);
    void SetAlturaS(int);
    int GetLarguraS();
    int GetAlturaS(); 
    
    void SetCordenadaX(int);
    void SetCordenadaY(int);
    int GetCordenadaX();
    int GetCordenadaY();
    int Abrir(char * Caminho,int largura,int altura, int larguraS, int alturaS);
    int MudarCordenadas(int,int);      
};

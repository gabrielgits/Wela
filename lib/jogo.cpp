#pragma hdrstop
#include "jogo.h"
#pragma package(smart_init)


int Jogo::StartGame(char * Name,int Init)
{
    if (Init == 1)
    {
          SDL_Init(SDL_INIT_VIDEO);
          SDL_WM_SetCaption(Name,0);
          return 1;
    }
    if (Init == 2)
    {
          SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
          SDL_WM_SetCaption(Name,0);
          return 1;
    }
    if (Init == 3) 
    {
          SDL_Init(SDL_INIT_EVERYTHING);
          SDL_WM_SetCaption(Name,0);
          return 1;
    }
    return 0;
}

int Jogo::StartStages()
{
    Stage1.SetNome("Fase Teste");
    if (Stage1.IniciarLog("wela.txt") == 0)
       return 0;
    if (Stage1.CarregarVideo(800,562) == 0)
       return 0;
    Stage1.SetQuantBuracos(6);
    if (Stage1.CarregarCursor("media\\image\\cursor.gif",82,56) == 0)
       return 0;
    if (Stage1.CarregarPersonagens("media\\image\\tabuleiro.gif",710,270) == 0)
       return 0;
    if (Stage1.CarregarFundo("media\\image\\fundo.png",800,562) == 0)
       return 0;
    if (Stage1.CarregarAnimacao("media\\image\\buracos.gif",900,35,75,35) == 0)
       return 0;

    if (Stage1.Iniciar() == 0)
       return 0;
    Stage1.CentrarPersonagem();  
    return 1;
}

int Jogo::RunStages()
{
    Stage1.Rodar();
    Stage1.Fechar();
    return 1;
}

void Jogo::EndGame()
{
     SDL_Quit();
}

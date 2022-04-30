#pragma hdrstop
#include "fase.h"
#pragma package(smart_init)


Fase::Fase()
{
    Numero = 0;
    Video = NULL;
    fundo.esquerda = 0;
    fundo.direita = 0;
}
int Fase::IniciarLog(char * Log)
{
    LogFase.SetName(Nome);
    LogFase.SetPath(Log);
    return LogFase.CreateLogFile();
}

void Fase::SetNome(char * nometemp)
{
     Nome = nometemp;   
}

void Fase::SetQuantBuracos(int temp)
{
     QuantBuracos = temp;
}
int Fase::GetQuantBuracos()
{
    return QuantBuracos;
}

int Fase::CarregarVideo(int Lar, int Alt)
{
    LogFase.AddLog("Iniciando Video");
    Video = SDL_SetVideoMode(Lar,Alt,0,SDL_SWSURFACE); //TELA CHEIA |SDL_FULLSCREEN
    if (Video != NULL)
    {
       LogFase.AddLog("Video Iniciado com Sucesso"); 
       return 1;
    }
    LogFase.AddLog(SDL_GetError());
    return 0;   
}
int Fase::CarregarPersonagens(char* nome, int Lar, int Alt)
{
    LogFase.AddLog("Carregando Personagem");
    if (Personagens.Abrir(nome,Lar,Alt))
    {
       LogFase.AddLog("Personagem Carregado com Sucesso");
       return 1;
    }
    LogFase.AddLog(Personagens.GetErro());
    return 0;
}
int Fase::CarregarFundo(char* nome, int Lar, int Alt)
{
    LogFase.AddLog("Carregando Fundo");
    if (Fundo.Abrir(nome,Lar,Alt))
    {
       LogFase.AddLog("Fundo Carregado com Sucesso");
       return 1;
    }
    LogFase.AddLog(Fundo.GetErro());
    return 0;
}

int Fase::CarregarCursor(char* nome, int Lar, int Alt)
{
    LogFase.AddLog("Carregando Cursor");
    if (Cursor.Abrir(nome,Lar,Alt))
    {
       LogFase.AddLog("Cursor Carregado com Sucesso");
       return 1;
    }
    LogFase.AddLog(Cursor.GetErro());
    return 0;
}

int Fase::CarregarAnimacao(char* nome, int Lar, int Alt, int Slar, int Salt)
{
    LogFase.AddLog("Carregando Animação");
    int QB = GetQuantBuracos()*4;
    Buracos = new Animacao[QB]; 
    for (int i = 0; i < QB; i++)
    {
        if (!Buracos[i].Abrir(nome,Lar,Alt,Slar,Salt)) 
        {
            LogFase.AddLog(Fundo.GetErro());
            return 0;
        }
    }
    LogFase.AddLog("Animação Carregado com Sucesso");
    return 1;
}

void Fase::CentrarPersonagem()
{
    Personagens.SetTelaX((Video->w - Personagens.GetLargura()) / 2);
    Personagens.SetTelaY(((Video->h - Personagens.GetAltura()) / 2)+100);
}
int Fase::Desenhar()
{
    
    SDL_Rect Desenha = {Fundo.GetTelaX(), Fundo.GetTelaY(), 0, 0};
    SDL_BlitSurface(Fundo.GetImage(),NULL, Video, &Desenha);
    
    SDL_Rect Desenha2 = {Personagens.GetTelaX(), Personagens.GetTelaY(), 0, 0};
    SDL_BlitSurface(Personagens.GetImage(), NULL, Video, &Desenha2);

    for (int i = 0; i < GetQuantBuracos()*4; i++)
    {
        SDL_Rect Pos = {Buracos[i].GetCordenadaX(),Buracos[i].GetCordenadaY(),Buracos[i].GetLarguraS(),Buracos[i].GetAlturaS()};
        SDL_Rect Desenha3 = {Buracos[i].GetTelaX(), Buracos[i].GetTelaY(), 0, 0};
        SDL_BlitSurface(Buracos[i].GetImage(), &Pos, Video, &Desenha3); 
    }
    SDL_Rect Desenha3 = {Cursor.GetTelaX(), Cursor.GetTelaY(), 0, 0};//500
    SDL_BlitSurface(Cursor.GetImage(), NULL, Video, &Desenha3);
    SDL_Flip(Video);
    return 1;
}
void Fase::Fechar()
{   
     LogFase.AddLog("Terminado o Sistema");
     Personagens.Fechar();
     Fundo.Fechar();
     SDL_FreeSurface(Video);
     
     for (int i = 0; i < GetQuantBuracos()*4; i++)
         Buracos[i].Fechar();
     delete []Buracos;
     LogFase.CloseLogFile();
     delete Jogo;    
}

int Fase::Evento() 
{
    SDL_Event event;
    int rodando = 1;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT: rodando = 0; break;
            
            case SDL_KEYDOWN: 
            {
                 if(event.key.keysym.sym == SDLK_ESCAPE) 
                     Video = SDL_SetVideoMode(800,576,0,SDL_SWSURFACE); 
                 if(event.key.keysym.sym == SDLK_RETURN) 
                     Video = SDL_SetVideoMode(800,576,0,SDL_SWSURFACE|SDL_FULLSCREEN);
                 if(event.key.keysym.sym == SDLK_LEFT) 
                     fundo.esquerda = 1;
                 if(event.key.keysym.sym == SDLK_RIGHT) 
                     fundo.direita = 1;
            }break;
            
            case SDL_KEYUP:
            {
                 if(event.key.keysym.sym == SDLK_LEFT) 
                     fundo.esquerda = 0;
                 if(event.key.keysym.sym == SDLK_RIGHT) 
                     fundo.direita = 0;  
            }break;
            
         /*   case SDL_MOUSEMOTION:
            {
                 if((event.motion.x > Personagens.GetTelaX()) && (event.motion.x < Personagens.GetTelaX() + Personagens.GetLargura()))
                     if((event.motion.y > Personagens.GetTelaY()) && (event.motion.y < Personagens.GetTelaY() + Personagens.GetAltura()))
                          rodando = 0;  
            }break;*/
            
            default: break;
        }

    }
    return rodando;
}
int Fase::AtualizarPosicao()
{
    if (fundo.esquerda)
    {
       Fundo.SetTelaX(Fundo.GetTelaX()+1);                
    }
    if (fundo.direita)
    {
       Fundo.SetTelaX(Fundo.GetTelaX()-1);                
    }
}
int Fase::Rodar()
{
    int rodando = 1;
    LogFase.AddLog("Rodando a Fase");
    while(rodando)
    {
        rodando = Evento();
        AtualizarBuracos();
        Desenhar();   
        AtualizarPosicao();
    }
    LogFase.AddLog("Fase Terminado");
    return rodando;
}

int Fase::Iniciar()
{
    LogFase.AddLog("Iniciando o Tabuleiro e Jogadores");
    Jogo = new Wela(NULL,NULL);
    Jogo->SetQuantBuraco(GetQuantBuracos());
    
    LogFase.AddLog("Iniciando o Jogadores 1");
    Jogador jogagor1 = Jogador(jogagor1);
    jogagor1.SetName("JOGODOR 1");
    jogagor1.SetSexo("masculino");
    jogagor1.SetPosition(0);
    Jogo->StartGame(&jogagor1,2);
    
    LogFase.AddLog("Jogadores 1 Iniciado");
    LogFase.AddLog("Iniciando o Jogadores 2");
    Jogador jogagor2 = Jogador(jogagor2);
    jogagor2.SetName("JOGODOR 2");
    jogagor2.SetSexo("masculino");
    jogagor2.SetPosition(1);
    Jogo->StartGame(&jogagor2,2);
    LogFase.AddLog("Jogadores 2 Iniciado");
    Jogo->Play(1,0,0,0);
    Jogo->Play(1,0,0,1);
    OrdenaTabu();
    Cursor.SetTelaX(Buracos[0].GetTelaX());
    Cursor.SetTelaY(Buracos[0].GetTelaY());
    LogFase.AddLog("Tabuleiro e Jogadores Iniciado com Sucesso");
    return 1;
}

int Fase::OrdenaTabu()
{
    int x = 107;
    int y = 0;
    for (int i = 0; i < 6; i++)
    {
        Buracos[i].SetTelaX(93+y); Buracos[i].SetTelaY(438);
        y += x;
    }    
    x = 100;
    y = 0;
    for (int i = 6; i < 12; i++)
    {
        Buracos[i].SetTelaX(108+y); Buracos[i].SetTelaY(380);
        y += x;
    }
    x = 94;
    y = 0;
    for (int i = 12; i < 28; i++)
    {
        Buracos[i].SetTelaX(123+y); Buracos[i].SetTelaY(328);
        y += x;
    }
    
    x = 88;
    y = 0;
    for (int i = 18; i < 24; i++)
    {
        Buracos[i].SetTelaX(140+y); Buracos[i].SetTelaY(277);
        y += x;
    }
    return 1;
}

int Fase::AtualizarBuracos()
{
    int QuantPedras = Jogo->GetQuantBuraco();
    int linha;
    linha = 0;
    Buraco * auxB = Jogo->FindBuraco(0,0,0);
    for (int i = 0; i < QuantPedras; i++)
    {
        Buracos[linha+i].MudarCordenadas(auxB->GetQuantPedra(),0);
        auxB = auxB->GetNext();
    }
    linha = 6;
    for (int i = QuantPedras; i > 0; i--)
    {
        Buracos[linha+(i-1)].MudarCordenadas(auxB->GetQuantPedra(),0);
        auxB = auxB->GetNext();
    }
    
    linha = 18;
    for (int i = QuantPedras; i > 0; i--)
    {
        Buracos[linha+(i-1)].MudarCordenadas(auxB->GetQuantPedra(),0);
        auxB = auxB->GetNext();
    }
    
    for (int i = QuantPedras; i > 0; i--)
    {
        Buracos[linha-(i)].MudarCordenadas(auxB->GetQuantPedra(),0);
        auxB = auxB->GetNext();
    }
}

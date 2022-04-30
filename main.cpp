#include "lib\jogo.h"


int main(int argc, char** argv) 
{	
    Jogo Wela;
    if (!Wela.StartGame("Wela Versão Teste",1))
       return 0;
    if (!Wela.StartStages())
       return 0;
    if (!Wela.RunStages())
       return 0;
    Wela.EndGame();
    return 0;
}

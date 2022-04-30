#ifndef jogoH
#define jogoH
#endif

#include <SDL.h>
#include "fase.h"


class Jogo
{
private:
       Fase Stage1;       
public:
      int StartGame(char * Name,int Init);
      int StartStages();
      int RunStages();
      void EndGame();
};

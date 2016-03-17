 #ifndef _SETTING_H
#define _SETTING_H

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>  

using namespace std;

enum MYKEYS
{
   KEY_F2, KEY_F3, KEY_F4,KEY_DOWN, KEY_LEFT, KEY_RIGHT;
};

typedef struct{
   string name;
   double score;
}player;

class Setting{
  public:
   Setting();
   ~Setting();
   void audioSetup(int, char);
   void keyboardSetup(int, char);
   void playerSetup(player);
   void scoreList(player, int);
   void sortList(player, int)
  private:
   int argc;
   char **argv;
   int numplayer;
};

#endif


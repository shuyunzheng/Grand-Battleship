#include "setting.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>  

void Setting::audioSetup(int argc, char **argv)
{
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_SAMPLE *sample=NULL;
   
   if(!al_init()){
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
   }

   if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
   }

   if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
   }

   sample = al_load_sample( "audio.wav" );

   if (!sample){
      printf( "Audio clip sample not loaded!\n" );
      return -1;
   }

   display = al_create_display(640, 480);

   if(!display){
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

   al_rest(10.0);

   al_destroy_display(display);
   al_destroy_sample(sample);
}

void Setting::keyboardSetup(int argc, char **argv)
{
   const float FPS = 60;
   const int SCREEN_W = 640;
   const int SCREEN_H = 480;
   const int BOUNCER_SIZE = 32;
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_BITMAP *bouncer = NULL;
   float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
   float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
   bool key[6] = { false, false, false, false, false, false };
   bool redraw = true;
   bool doexit = false;
   
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
   
   if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
   }
   
   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
   
   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }
   
   bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
   if(!bouncer) {
      fprintf(stderr, "failed to create bouncer bitmap!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
   
   al_set_target_bitmap(bouncer);
   
   al_clear_to_color(al_map_rgb(255, 0, 255));
   
   al_set_target_bitmap(al_get_backbuffer(display));
   
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_bitmap(bouncer);
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
   
   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_register_event_source(event_queue, al_get_keyboard_event_source());
      
   al_clear_to_color(al_map_rgb(0,0,0));
   
   al_flip_display();
   
   al_start_timer(timer);
   
   while(!doexit)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
      
      if(ev.type == ALLEGRO_EVENT_TIMER) {
	 if(key[KEY_F2] && bouncer_y >= 4.0) {
	    bouncer_y -= 4.0;
	 }

	 if(key[KEY_F3] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
	    bouncer_y += 4.0;
	 }  

	 if(key[KEY_F4] && bouncer_y >= 4.0) {
	    bouncer_y -= 4.0;
	 }    
	 
	 if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
	    bouncer_y += 4.0;
	 }
	 
	 if(key[KEY_LEFT] && bouncer_x >= 4.0) {
	    bouncer_x -= 4.0;
	 }
	 
	 if(key[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
	    bouncer_x += 4.0;
	 }
	 
	 redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
	 break;
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
	 switch(ev.keyboard.keycode) {
	    case ALLEGRO_KEY_DOWN:
	       key[KEY_DOWN] = true;
	       break;
	       
	    case ALLEGRO_KEY_LEFT:
	       key[KEY_LEFT] = true;
	       break;
	       
	    case ALLEGRO_KEY_RIGHT:
	       key[KEY_RIGHT] = true;
	       break;

	    case ALLEGRO_KEY_F2:
	       key[KEY_F2] = true;
	       break;

	    case ALLEGRO_KEY_F3:
	       key[KEY_F3] = true;
	       break;

	    case ALLEGRO_KEY_F4:
	       key[KEY_F4] = true;
	       break;     
	 }
      }
      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
	 switch(ev.keyboard.keycode) {
	    case ALLEGRO_KEY_DOWN:
	       key[KEY_DOWN] = false;
	       break;
	       
	    case ALLEGRO_KEY_LEFT:
	       key[KEY_LEFT] = false;
	       break;
	       
	    case ALLEGRO_KEY_RIGHT:
	       key[KEY_RIGHT] = false;
	       break;

	    case ALLEGRO_KEY_F2:
	       key[KEY_F2] = false;
	       break; 

	    case ALLEGRO_KEY_F3:
	       key[KEY_F3] = false;
	       break;

	    case ALLEGRO_KEY_F4:
	       key[KEY_F4] = false;
	       break;
	       
	    case ALLEGRO_KEY_ESCAPE:
	       doexit = true;
	       break;
	 }
      }
      
      if(redraw && al_is_event_queue_empty(event_queue)) {
	 redraw = false;
	 
	 al_clear_to_color(al_map_rgb(0,0,0));
	 
	 al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
	 
	 al_flip_display();
      }
   }
   
   al_destroy_bitmap(bouncer);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
}

void Setting::playerSetup(player p)
{
   char filename;
      
   cout << "Enter the player's name: ";
   getline(cin, p.name);c
   cout << "Enter the score of this player: ";
   cin >> p.score;
   cin.ignore();
   
   cout << "Enter the file's name: ";
   cin >> filename;
   ofstream ofs(filename);
   ofs<< p.name << "     " << p.score << endl;
   ofs.close();
}

void Setting::scoreList(player p[], int numplayer)
{
   char filename;
   ifstream fin;
   int counter;

   cout << "Enter the file's name: ";
   cin >> filename;
   fin.open(filename);
   fin >> numplayer;
   fin.ignore();

   for(counter=0; counter<numplayer; counter++)
   {
      getline(fin, p[counter.name]);
      fin >> p[counter].score;
      fin.ignore();
   }

   sortList(player p,int numplayer);

   cout << endl << "The High Score List" << endl;
   for(counter=0; counter<numplayer; counter++)
   {
      cout << p[counter].name << "     " << p[counter].score
	   <<endl;
   }
   cout << endl << endl;
}

void Setting::sortList(player p[], int numplayer)
{
   int x,y;
   player l;
   for(x=0; x<numplayer-1; x++)
   {
      for(y=x+1; y<numplayer; y++)
      {
	 if(player[y].score<player[x].score)
	 {
	    l = p[y];
	    p[y] = p[x];
	    p[x] = l;
	 }
      }
   }
}
   

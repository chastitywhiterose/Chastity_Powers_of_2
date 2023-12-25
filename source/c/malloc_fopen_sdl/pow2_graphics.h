/*
pow2_graphics.h

this header file is meant to contain all the functions which write things to the screen
*/



void ttf_title_screen()
{

strcpy(text,"I am Chastity White Rose, the Vegan Virgin! I am the creator of the video games Chaste Tris, Chaste Puyo, and Chaste Panel. I created this special 1989 edition of Chaste Tris to use only black and white to remind us of when Tetris was released in 1989 for the Game Boy.\n\n");

strcat(text,"This game and the original Chaste Tris are available on my programming Patreon account.\n\npatreon.com/ChastityWhiteRoseProgramming\n\nYou may also want to follow me on Twitch and YouTube where I frequently stream myself playing my own games or playing official Tetris games and sometimes playing online chess.\n\nhttps://www.twitch.tv/chastitywhiterose\n\nhttps://www.youtube.com/@chastitywhiterose");

ttf_print_wrapped(text,10,0);


 SDL_RenderPresent(renderer);

 loop=1;
 while(loop)
 {
  while(SDL_PollEvent(&e))
  {
   if(e.type == SDL_QUIT){loop=0;}
   if(e.type == SDL_KEYUP)
   {
    if(e.key.keysym.sym==SDLK_ESCAPE){loop=0;}
   }
  }
 }

}






void ttf_pow2_anim()
{

 ttf_print_wrapped(text,10,0);

 /*ttf_print_wrapped(a,10,0);*/


 SDL_RenderPresent(renderer);

 loop=1;
 while(loop)
 {
  while(SDL_PollEvent(&e))
  {
   if(e.type == SDL_QUIT){loop=0;}
   if(e.type == SDL_KEYUP)
   {
    if(e.key.keysym.sym==SDLK_ESCAPE){loop=0;}
   }
  }
 }

}

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

 /*ttf_print_wrapped(text,10,0);*/

 /*ttf_print_wrapped(a,10,0);*/

 /*this is a highly optimized routine for scrolling text*/

 x=16;y=0;

 text_surface=TTF_RenderText_Solid_Wrapped(font, a, font_color,width);

 w=text_surface->w;
 h=text_surface->h;

 /*printf("Actual surface size is w=%d,h=%d\n",w,h);*/

 if(text_surface != NULL)
 {
  text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
  SDL_FreeSurface(text_surface);
 }

 srcrect.x=0;
 srcrect.y=0;
 srcrect.w=w;
 srcrect.h=h;

 dstrect=srcrect;
 dstrect.x=x;
 dstrect.y=height;

 SDL_SetRenderDrawColor(renderer,255,255,255,255);

 delay=1000/fps;

 loop=1;
 while(loop)
 {
  sdl_time = SDL_GetTicks();
  sdl_time1 = sdl_time+delay;

 dstrect.y--;

 SDL_RenderClear(renderer);
 SDL_RenderCopy(renderer, text_texture, &srcrect, &dstrect);
 SDL_RenderPresent(renderer);

 /*time loop used to slow the game down so users can see it*/
 while(sdl_time<sdl_time1)
 {
  sdl_time=SDL_GetTicks();
 }

  while(SDL_PollEvent(&e))
  {
   if(e.type == SDL_QUIT){loop=0;}
   if(e.type == SDL_KEYUP)
   {
    if(e.key.keysym.sym==SDLK_ESCAPE){loop=0;}
   }
  }

 }

 /*free the memory and delete the texture*/
 SDL_DestroyTexture(text_texture);

}

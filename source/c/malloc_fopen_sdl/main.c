/* gcc -Wall -ansi -pedantic main.c -o main && ./main */
#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include "SDL_ttf.h"

/*variables that apply for any program I create that uses SDL2*/
int width=1280,height=720;
int loop=1;
int Window_Flags=0;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;

/*variables that are usually used for managing rectangles and error checking*/
int x,y,w,h;

/*variables for SDL_ttf features*/
char text[0x1000];
TTF_Font *font=NULL;
int font_size=40;
char font_filename[256];
int renderstyle=TTF_STYLE_NORMAL;
SDL_Color font_color= {0,0,0,255};
SDL_Surface *text_surface;
SDL_Texture *text_texture;
SDL_Rect srcrect,dstrect;

/*most of the variables specific to the powers of two program had to be moved to global scope so that other functions can see them*/

 int length=1000; 
 int length2=1;

 FILE *fp;
 char filename[256];
 
 char *a;

#include "pow2_ttf.h"
#include "pow2_graphics.h"


int main()
{
 int z;

 a=(char*)malloc(length*sizeof(*a));if(a==NULL){printf("memory allocation failed\n");return(1);}

 
 x=0;
 while(x<length)
 {
  a[x]=0;
  x++;
 }
 a[0]=1;

 sprintf(filename,"output.txt");
 fp=fopen(filename,"wb+");
 if(fp==NULL){printf("Failed to create file \"%s\".\n",filename);return 1;}
 
 z=0;
 while(z<=16)
 {

  x=length2;
  while(x>0)
  {
   x--;
   fprintf(fp,"%i",a[x]);
  }
  fprintf(fp,"\n");

  y=0;
  x=0;
  while(x<length2)
  {
   a[x]+=a[x];
   a[x]+=y;
   if(a[x]>9){y=1;a[x]-=10;}else{y=0;}
   x++;
  }
  if(y>0){a[length2]=y;length2++;}

  z++;
 }

 x=ftell(fp);
 printf("file '%s' writteon of %i bytes\n",filename,x);

 /*
  now that the file of text is generated, we will attempt to load the entire file into one big array
  this is achieved by freeing the memory of array 'a' and reallocating it with malloc at the new length.
  We will make it 1 byte bigger for the terminating 0 character at the end.
 */

 if(a!=NULL){free(a);}
 length=x;
 a=(char*)malloc(1+length*sizeof(*a));if(a==NULL){printf("memory allocation failed\n");return(1);}

 /*
  then we rewind the file already written back to the beginning and read all the bytes into the new array
  set the final byte to 0 because it will be passed as a null terminated string
 */

 fseek(fp,0,SEEK_SET);

 y=0;

while(y!=EOF)
{
 y=fgetc(fp);
 if(y!=EOF)
 {
  /*putchar(y);*/
  a[x]=y;
 }
}
a[x]=0;
/*printf("x==%d\n",length);*/


 /*the next step is to start an SDL Window and initialize the font with SDL_TTF*/
 if(SDL_Init(SDL_INIT_VIDEO))
 {
  printf( "SDL could not initialize! SDL_Error: %s\n",SDL_GetError());return -1;
 }
 window=SDL_CreateWindow("Powers of 2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_SHOWN );
 if(window==NULL){printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );return -1;}
 renderer = SDL_CreateRenderer(window,-1,0);
 if(renderer==NULL){printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );return -1;}

 printf("SDL Program Compiled Correctly\n");

 /*fill entire screen with current draw color*/
 SDL_SetRenderDrawColor(renderer,255,255,255,255);
 SDL_RenderClear(renderer);

/* Initialize the TTF library */
 if(TTF_Init() < 0)
 {
  SDL_Log("Couldn't initialize TTF: %s\n",SDL_GetError());
  SDL_Quit();
  return(2);
 }

 strcpy(font_filename,"font/editundo.ttf");

 font = TTF_OpenFont(font_filename, font_size);
 if (font == NULL)
 {
  SDL_Log("Couldn't load %d pt font from %s: %s\n",
                    font_size, font_filename, SDL_GetError());

 }
 else
 {
  printf("font file '%s'loaded\n",font_filename);
  TTF_SetFontStyle(font, renderstyle);
  TTF_SetFontKerning(font, 0);
 }

 font_color.r=0;
 font_color.g=0;
 font_color.b=0;

 /*ttf_test2();*/

 /*ttf_title_screen();*/

 strcpy(text,"Chastity White Rose");
 ttf_pow2_anim();

 if(fp!=NULL){fclose(fp);}
 if(a!=NULL){free(a);}
 return 0;
}


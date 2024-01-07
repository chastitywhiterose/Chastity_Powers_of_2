/* gcc -Wall -ansi -pedantic main.c -o main && ./main */
#include <stdio.h>
#include <stdlib.h>


#include <SDL.h>
#include <SDL_mixer.h>

#include "sdl_chaste_music.h"

/*how many sounds are allowed maximum*/
#define sounds 10

/*sound variables section*/
int sound_index=0,sound_is_on=0;
char *sound_files[]=
{
 "./tones/sine/440.00.wav",
 "./tones/sine/493.88.wav",
 "./tones/sine/554.37.wav",
 "./tones/sine/622.25.wav",
 "./tones/sine/698.46.wav",
 "./tones/sine/466.16.wav",
 "./tones/sine/523.25.wav",
 "./tones/sine/587.33.wav",
 "./tones/sine/659.25.wav",
 "./tones/sine/739.99.wav"
};

Mix_Chunk *sound[sounds]; /*chunks the music is loaded into*/


 int x,y,z;
 int length=1000; 
 int length2=1;
 char *a;

int main()
{


 chaste_audio_init(); /*get the audio device ready*/
 
 /*load all sounds*/
 x=0;
 while(x<sounds)
 {
  sound[x]=chaste_audio_load(sound_files[x]);
  x++;
 }

 a=(char*)malloc(length*sizeof(*a));if(a==NULL){printf("memory allocation failed\n");return(1);}
 
 x=0;
 while(x<length)
 {
  a[x]=0;
  x++;
 }
 a[0]=1;

 z=0;
 while(z<=64)
 {

 /*
  x=length2;
  while(x>0)
  {
   x--;
   printf("%i",a[x]);
  }
  printf("\n");
*/

  /*go through the loop but play a tone for each digit*/
  x=length2;
  while(x>0)
  {
   x--;

   sound_index=a[x];

   printf("%i %s\n",a[x],sound_files[sound_index]);

   chaste_audio_play(sound[sound_index]);
   SDL_Delay(400);
   chaste_audio_stop();
   SDL_Delay(100);

  }
  printf("\n");


 /*
  add the digits to themselves to double the number
  use variable y as carry in addition
 */

  y=0;
  x=0;
  while(x<=length2)
  {
   a[x]+=a[x];
   a[x]+=y;
   if(a[x]>9){y=1;a[x]-=10;}else{y=0;}
   x++;
  }
  if(a[length2]>0){length2++;}

  z++;
 }




 free(a);

 return 0;
}


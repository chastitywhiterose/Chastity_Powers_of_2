/* gcc -Wall -ansi -pedantic main.c -o main && ./main */
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int x,y,z;
 int length=1000; 
 int length2=1;

 FILE *fp;
 char filename[256];
 
 char *a=(char*)malloc(length*sizeof(*a));if(a==NULL){printf("memory allocation failed\n");return(1);}

 
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
 while(z<=256)
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

 if(fp!=NULL){fclose(fp);}
 free(a);
 return 0;
}


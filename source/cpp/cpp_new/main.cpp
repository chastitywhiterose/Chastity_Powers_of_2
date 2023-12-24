/* g++ -Wall -ansi -pedantic main.c -o main && ./main */
#include <stdio.h>
#include <stdlib.h>
int main()
{
 int x,y,z;
 int length=1000; 
 int length2=1;
 char *a=new char[length];
 
 x=0;
 while(x<length)
 {
  a[x]=0;
  x++;
 }
 a[0]=1;

 z=0;
 while(z<=256)
 {

  x=length2;
  while(x>0)
  {
   x--;
   printf("%i",a[x]);
  }
  printf("\n");

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

 delete[] a;
 return 0;
}


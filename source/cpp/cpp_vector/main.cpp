/* g++ -Wall -ansi -pedantic main.cpp -o main && ./main */
#include <stdio.h>
#include <vector>
int main()
{
 unsigned int x,y,z;

 std::vector<int> a;
 
 a.push_back(1);

 z=0;
 while(z<=256)
 {

  x=a.size();
  while(x>0)
  {
   x--;
   printf("%i",a[x]);
  }
  printf("\n");

  y=0;
  x=0;
  while(x<a.size())
  {
   a[x]+=a[x];
   a[x]+=y;
   if(a[x]>9){y=1;a[x]-=10;}else{y=0;}
   x++;
  }
  if(y>0){a.push_back(y);}

  z++;
 }

 return 0;
}

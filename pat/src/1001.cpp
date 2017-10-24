#include <stdio.h>

int sum = 0;

void fun(int n)
{
  if (n == 1) return;
  
  if (n%2 == 0) 
  {
    sum++;
    fun(n/2);
    return;
  }
  
  if (n%2 != 0) 
  {
    sum++;
    fun((3*n+1)/2);
    return;
  }
}

int main()
{
  int n = 0;
  while ( (scanf("%d", &n)) != EOF )
  {
    sum = 0;
    fun(n);
    printf("%d\n", sum);
  }
  return 0;
}

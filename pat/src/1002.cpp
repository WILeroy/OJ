#include <iostream>
#include <vector>
#include <string>

using namespace std;

int out_n = 0;
string in_n = "";

string s[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void out(int n)
{
  if (n/10 == 0)
  {
    cout << s[n];
    return;
  }

  out(n/10);

  cout << " " << s[n%10];
}

void fun()
{
  string::iterator at = in_n.begin();

  for (; at!=in_n.end(); at++)
  {
    out_n += int(*at) - 48;
  }

  out(out_n);
}

int main()
{
  while ( cin >> in_n )
  {
    fun();
    cout << endl;
    out_n = 0;
    in_n = "";
  }

  return 0;
}

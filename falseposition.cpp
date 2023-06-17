#include <bits/stdc++.h>
using namespace std;
//
double f(double x)
{
  return x * x * x + 2 * x * x - x + 1;
}

int main()
{
  double l, r;

  while (true)
  {
    cout << "The equation is : x^3 + 2x^2 - x+1" << '\n';
    cout << "Enter the interval for estimate root : ";
    cin >> l >> r;
    if (f(l) * f(r) > 0)
    {
      cout << "The root may not lie in this interval." << '\n';
    }
    else
      break;
  }

  double ans;
  int iteration = 1e6;

  while (iteration--)
  {
    ans = r - ((f(r) * (l - r)) / (f(l) - f(r)));
    if (!f(ans))
      break;

    if ((f(ans) * f(r)) < 0)
    {
      l = ans;
    }
    else
    {
      r = ans;
    }
  }

  cout << "Root : " << ans << '\n';

  return 0;
}

#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x * x + 2 * x * x - x + 1;
}

int main()
{
    double l, r, e;

    while (true)
    {
        cout << "The equation is : x^3 + 2x^2 - x+1" << '\n';
        cout << "Enter the interval for estimate root : ";
        cin >> l >> r >> e;
        if (f(l) * f(r) > 0)
        {
            cout << "The root may not lie in this interval." << '\n';
        }
        else
            break;
    }
    double ans, error = 100;
    int iteration = 1e6;
    double x;
    do
    {
        x = (l * f(r) - r * f(l)) / (f(r) - f(l));
        l = r;
        r = x;
        error = fabs((l - r) / r);
    } while (error > e);
    ans = x;
    cout << "Root : " << ans << '\n';
    return 0;
}
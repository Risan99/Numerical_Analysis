#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    return x * x * x + x * x + 2 * x - 4;
}
int main()
{
    double a, b, e;
    cout << "Enter doubleitial guess: ";
    cin >> a >> b;
    cout << "Enter precision: ";
    cin >> e;
    if (f(a) * f(b) > 0)
        cout << "Root maybe not in the range.\n";
    else
    {
        double mid;
        double error = 100;
        int i = 1;
        while (error > e)
        {
            mid = (a + b) / 2;
            cout << "Root after " << i++ << "th iteration :" << mid << '\n';
            if (f(mid) == 0.0)
                break;
            if (f(a) * f(mid) < 0)
            {
                b = mid;
            }
            else
            {
                a = mid;
            }
            error = abs(a - b) / mid;
        }
        cout << "Final root: " << mid << '\n';
    }
    return 0;
}

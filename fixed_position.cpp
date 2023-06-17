#include <bits/stdc++.h>
using namespace std;

double g(double x)
{
    return (-x * x * x * x + 3 * x * x * x - 5 * x * x + 5) / 5;
}

double fixedPos(double x0, double es, double &ea, int &iter)
{
    iter = 1e9;
    double xrold, xr = x0;
    while (iter--)
    {
        xrold = xr;
        xr = g(xrold);

        if (xr != 0)
        {
            ea = fabs((xr - xrold) / xr) * 100;
        }
        if (ea < es)
        {
            break;
        }
        cout << "After " << 1e9 - iter << "th step "
             << "Root= " << xr << " Error= " << ea << endl;
    }

    return xr;
}

int main()
{
    double low;
    cout << "The function x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Estimate root: ";
    cin >> low;

    double es, ea;
    int iter;
    cout << "Estimate error (0.0001): ";
    cin >> es;

    double root = fixedPos(low, es, ea, iter);

    cout << "Root of the function " << root << endl;
    cout << "Appoximate error: " << ea << endl;
    cout << "Number of iteration: " << 1e9 - iter << endl;

    return 0;
}
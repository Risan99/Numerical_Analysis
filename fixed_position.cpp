#include <bits/stdc++.h>
using namespace std;

// double f(double x) // Given polynomial
// {
//     return x * x * x + x * x + 2 * x - 4;
// }
double g(double x)
{
    return (-x * x * x * x + 3 * x * x * x - 5 * x * x + 5) / 5;
}
double fixedposition(double x, double er)
{
    double x2;
    double error = 10000000;
    for (int i = 1;; i++)
    {
        x = x2;
        x2 = g(x);

        if (x2 != 0)
        {
            error = fabs((x2 - x) / x2);
            // if(error<=-1) error*=(-1);
        }
        cout << "After " << i << "th step "
             << "Root= " << x2 << " Error= " << error << endl;
        if (error < er)
            break;
    }
    return x2;
}

int main()
{
    double x, er;
    cin >> x >> er;
    double root = fixedposition(x, er);
    cout << root << '\n';
    return 0;
}




// second way almost similar

// #include <bits/stdc++.h>
// using namespace std;

// double g(double x)
// {
//     return (-x * x * x * x + 3 * x * x * x - 5 * x * x + 5) / 5;
// }

// double fixedPos(double x0, double es, double &ea, int &iter)
// {
//     iter = 1e9;
//     double xrold, xr = x0;
//     while (iter--)
//     {
//         xrold = xr;
//         xr = g(xrold);

//         if (xr != 0)
//         {
//             ea = fabs((xr - xrold) / xr) * 100;
//         }
//         if (ea < es)
//         {
//             break;
//         }
//         cout << "After " << 1e9 - iter << "th step "
//              << "Root= " << xr << " Error= " << ea << endl;
//     }

//     return xr;
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

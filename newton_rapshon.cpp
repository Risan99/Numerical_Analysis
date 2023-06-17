#include <bits/stdc++.h>
using namespace std;
double f(double x)
{
    double a = pow(x, 3.0) - x - 11.0;
    return a;
}
double fprime(double x)
{
    double b = 3 * pow(x, 2.0) - 1.0;
    return b;
}
int main()
{
    double x, x1, e, fx, fx1, error;
    int itt = 1;
    cout.precision(4);
    cout.setf(ios::fixed);
    cout << "Enter the initial guess\n";
    cin >> x1;
    cout << "Enter accuracy\n";
    cin >> e;
    fx = f(x);
    fx1 = fprime(x);
    cout << "    x{i}"
         << "      "
         << "x{i+1}"
         << "          "
         << "Error" << endl;

    while (fabs(x1 - x) >= e)
    {
        x = x1;
        fx = f(x);
        fx1 = fprime(x);
        x1 = x - (fx / fx1);
        error = fabs((x1 - x) / x1) * 100;
        cout << "After " << itt++ << " eteratin " << x << "     " << x1 << "        " << error << endl;
    }
    cout << "The root of the equation is " << x1 << endl;
    return 0;
}
#include <iostream>
#include <cmath>
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
double fprime2(double x)
{
    double b = 6 * x;
    return b;
}
int main()
{
    double x, x1, e, fx, fx1, error;
    cout << "Enter the initial guess\n";
    cin >> x1;
    cout << "Enter desired accuracy\n";
    cin >> e;
    fx = f(x);
    fx1 = fprime(x);
    cout << "x{i}"
         << "    "
         << "x{i+1}"
         << "        "
         << "|x{i+1}-x{i}|"
         << "      "
         << "Error" << endl;
    double ff2;
    while (fabs(x1 - x) / x1 >= e)
    {
        x = x1;
        fx = f(x);
        fx1 = fprime(x);
        ff2 = fprime2(x);
        x1 = x - ((fx * fx1) / ((fx1 * fx1) - (fx * ff2)));
        error = fabs((x1 - x) / x1) * 100;
        cout << x << "     " << x1 << "           " << fabs(x1 - x) << "     " << error << endl;
    }
    cout << "The root of the equation is " << x1 << endl;
    return 0;
}

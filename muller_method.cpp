#include <iostream>
#include <cmath>

using namespace std;

// Function for which we want to find the root
double f(double x)
{
    return x * x * x + x * x - 3 * x - 5;
}

// Muller's method for finding the root of a function
double mullerMethod(double x0, double x1, double x2, double tolerance)
{
    double h1 = x1 - x0;
    double h2 = x2 - x1;

    double delta1 = (f(x1) - f(x0)) / h1;
    double delta2 = (f(x2) - f(x1)) / h2;

    double d = (delta2 - delta1) / (h2 + h1);
    double b = delta2 + h2 * d;
    double c = f(x2);

    double discriminant = sqrt(b * b - 4 * c * d);
    double x;
    if (b >= 0)
        x = x2 + (-2 * c) / (b + discriminant);
    else
        x = x2 + (-2 * c) / (b - discriminant);
    while (fabs(f(x)) > tolerance)
    {
        x0 = x1;
        x1 = x2;
        x2 = x;

        h1 = x1 - x0;
        h2 = x2 - x1;

        delta1 = (f(x1) - f(x0)) / h1;
        delta2 = (f(x2) - f(x1)) / h2;

        d = (delta2 - delta1) / (h2 + h1);
        b = delta2 + h2 * d;
        c = f(x2);

        discriminant = sqrt(b * b - 4 * c * d);
        if (b >= 0)
            x = x2 + (-2 * c) / (b + discriminant);
        else
            x = x2 + (-2 * c) / (b - discriminant);
    }

    return x;
}

int main()
{
    double x0, x1, x2, tolerance;
    cout << "Enter initial guesses x0, x1, and x2: ";
    cin >> x0 >> x1 >> x2;
    cout << "Enter tolerance: ";
    cin >> tolerance;

    double root = mullerMethod(x0, x1, x2, tolerance);

    cout << "Root: " << root << endl;

    return 0;
}

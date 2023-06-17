#include <bits/stdc++.h>
using namespace std;

double f(double x) //Given polynomial
{
    return x * x * x + x * x + 2 * x - 4;
}
int main()
{
    double a, b, e;
    cout << "Enter doubleitial guess: ";
    cin >> a >> b;   //Initial Guess
    cout << "Enter Error tolarence: ";
    cin >> e;       // Tolarble error  
    if (f(a) * f(b) > 0)  //Checking weather the root is in the bound
        cout << "Root maybe not in the range.\n";
    else
    {
        double mid;
        double error = 100;
        int i = 1;
        while (error > e)  // As long as error greater than tolarable error
         {                  // if precision is given then while((b-a)>=e)
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

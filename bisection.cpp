#include <iostream>
using namespace std;
#define EP 0.001


double f(double x) {
   return x*x*x - x*x + 2;
}

void bisection(double a, double b) {
   if (f(a) * f(b) >= 0) {
      cout << "You have not assumed right a and b\n";
      return;
   }
  double c ;
   while ((b-a) >= EP) {
   
      c = (a+b)/2;
     
      if (f(c) == 0.0)
         break;
      
      else if (f(c)*f(a) < 0)
         b = c;
      else
         a = c;
   }
   cout << "The value of root is : " << c;
}

int main() {
   double a, b;
   cin>>a>>b;
   bisection(a, b);
   return 0;
}
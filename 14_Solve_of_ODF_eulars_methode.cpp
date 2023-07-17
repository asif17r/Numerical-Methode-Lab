#include<bits/stdc++.h>
using namespace std;
#define double long double

/*
    Ques:
    You will be given an equation in this format:
    dy/dx = f(x, y) or
    dy/dx = x^2 + 2xy + y^2 or 
    f(x,y) = x^2 + 2xy + y^2

    and y(0) = 5, what is y(0.5) = ?

    Solve:
    We know that , y0 = 5
    So, y(0+h) = x0 + h*f(x0, y0)  [h is a small value]
    Let, h = 0.01
    Now, y(0+0.01) = 5 + 0.001*f(0, 5) = 5.05
        y(0.02) = 5.05 + 0.001*f(0.01, 5.05) = 5.101
        we will continue this to get y(0.5).
*/

// the function
double f(double x, double y){
    // Define the function f(x, y) in your ODE
    // Example: f(x, y) = x + y
    return x+y;
}

int main(){
    double x0, y0, xn;
    cin >> x0; // Initial value of x
    cin >> y0; // Initial value of y
    cin >> xn; // Final value of x
    // we have to get the value of y at xn

    double h = 0.01; // h is step size

    double x = x0, y = y0;
    while(x < xn){
        double newY = y + h*f(x, y);
        x += h;
        y = newY;
    }
    cout << setprecision(10) << y << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define double long double
/*
    Ques: 
    Give an equation f(x) = x^3 + 2x + 5
    Find the value of integral of f(x) from 2 to 4

    Solve:
    Trapezoidal Rule, if we divide the interval into n equal parts, then, 
    y' = h/2 ( y0 + yn + 2(y1+y2...+yn-1) )
    where, h = (b-a)/n
    We will find y0, y1, .. yn for each x0, x1, .. xn and put then in the formula.
*/
double f(double x){
    // let f(x) = x^3 + 2x + 5
    return x*x*x + 2*x + 5;
}
int main(){
    double lowerLimit, upperLimit;
    cin >> lowerLimit >> upperLimit;

    double n = 1000;
    double h = (upperLimit - lowerLimit)/n;

    double sum = f(lowerLimit) + f(upperLimit);
    double valueofX = lowerLimit;
    for(int i = 1; i < n; i++){
        valueofX += h;
        sum += 2*f(valueofX);
    }
    sum *= h*.5;
    cout << setprecision(5) << fixed << sum << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define double long double

/*
    Ques: 
    Give an equation f(x) = x^3 + 2x + 5
    Find the value of integral of f(x) from 2 to 4

    Solve:
    Simson's Rule, if we divide the interval into n equal parts, then, 
    y' = h/3 ( y0 + yn + 2(y2+y4...+yn-2) + 4(y1+y3...+yn-1) )
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

    // n = number of intervals , n must be even
    double n = 1000;
    
    double h = (upperLimit - lowerLimit)/n;

    double sum = f(lowerLimit) + f(upperLimit);
    double valueofX = lowerLimit;
    for(int i = 1; i < n; i++){
        valueofX += h;
        if(i%2 == 0){
            sum += 2*f(valueofX);
        }else{
            sum += 4*f(valueofX);
        }
    }
    sum *= (h/3.00);
    cout << "The value of integral is: " << sum << endl;
}
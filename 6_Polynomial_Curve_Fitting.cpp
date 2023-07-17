#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate the polynomial equation value P(x) for a given x and coefficients c
double polynomial(double x, const vector<double>& c) {
    double result = 0.0;
    int n = c.size();

    for (int i = 0; i < n; i++) {
        result += c[i] * pow(x, i);
    }

    return result;
}

// Function to perform curve fitting using the polynomial method
vector<double> curve_fitting(const vector<double>& x, const vector<double>& y, int degree) {
    int n = x.size();
    int m = degree + 1;

    // Create the matrix and vector for the linear system to be solved
    vector<vector<double>> matrix(m, vector<double>(m, 0.0));
    vector<double> vector(m, 0.0);

    for (int i = 0; i < n; i++) {
        double xi = x[i];
        double yi = y[i];

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                matrix[j][k] += pow(xi, j + k);
            }
            vector[j] += pow(xi, j) * yi;
        }
    }

    // Solve the linear system using any appropriate method (Gauss-Jordan, LU decomposition, etc.)
    // For simplicity, we will use Gauss-Jordan elimination in this example.

    for (int i = 0; i < m; i++) {
        // Make the diagonal element of the current row 1
        double div = matrix[i][i];
        for (int j = 0; j < m; j++) {
            matrix[i][j] /= div;
        }
        vector[i] /= div;

        // Eliminate non-diagonal elements in other rows
        for (int k = 0; k < m; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < m; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
                vector[k] -= factor * vector[i];
            }
        }
    }

    return vector; // Return the coefficients c0, c1, ..., cn
}

int main() {
    vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0}; // Input x values
    vector<double> y = {1.0, 3.0, 2.0, 5.0, 6.0}; // Input y values

    int degree = 2; // Choose the degree of the polynomial (degree = n)

    vector<double> coefficients = curve_fitting(x, y, degree);

    cout << "Polynomial equation: ";
    for (int i = 0; i < coefficients.size(); i++) {
        cout << coefficients[i] << " * x^" << i;
        if (i != coefficients.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;

    // Example of evaluating the polynomial equation at a specific value of x
    double x_value = 2.5;
    double result = polynomial(x_value, coefficients);
    cout << "P(" << x_value << ") = " << result << endl;

    return 0;
}

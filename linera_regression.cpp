/* C++ STL (Standard Template Library) for a basic machine learning task, 
specifically linear regression. */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Function to perform linear regression
void linearRegression(const std::vector<double>& X, const std::vector<double>& Y, double& slope, double& intercept) {
    int n = X.size();
    double sumX = std::accumulate(X.begin(), X.end(), 0.0);
    double sumY = std::accumulate(Y.begin(), Y.end(), 0.0);
    double sumXY = std::inner_product(X.begin(), X.end(), Y.begin(), 0.0);
    double sumXX = std::inner_product(X.begin(), X.end(), X.begin(), 0.0);

    slope = (n * sumXY - sumX * sumY) / (n * sumXX - sumX * sumX);
    intercept = (sumY - slope * sumX) / n;
}

int main() {
    // Sample dataset (X, Y pairs)
    std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> Y = {2.0, 4.0, 5.0, 4.0, 5.5};

    // Perform linear regression
    double slope, intercept;
    linearRegression(X, Y, slope, intercept);

    // Output the results
    std::cout << "Linear Regression Equation: Y = " << slope << " * X + " << intercept << std::endl;

    // Predict value for a new X
    double newX = 6.0;
    double predictedY = slope * newX + intercept;
    std::cout << "Predicted value for X = " << newX << ": " << predictedY << std::endl;

    return 0;
}


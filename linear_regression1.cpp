#include <iostream>
#include <vector>
#include <numeric> // For accumulate function
#include <algorithm> // For for_each function

// Function to perform linear regression
double linearRegression(const std::vector<double>& X, const std::vector<double>& Y) {
    // Calculate mean of X and Y
    double meanX = std::accumulate(X.begin(), X.end(), 0.0) / X.size();
    double meanY = std::accumulate(Y.begin(), Y.end(), 0.0) / Y.size();

    // Calculate slope (m) and intercept (c) for the line equation Y = m*X + c
    double numerator = 0, denominator = 0;
    for (size_t i = 0; i < X.size(); ++i) {
        numerator += (X[i] - meanX) * (Y[i] - meanY);
        denominator += (X[i] - meanX) * (X[i] - meanX);
    }

    double slope = numerator / denominator;
    double intercept = meanY - slope * meanX;

    return slope;
}

int main() {
    // Sample dataset
    std::vector<double> X = {1, 2, 3, 4, 5}; // Independent variable
    std::vector<double> Y = {2, 4, 6, 8, 10}; // Dependent variable

    // Perform linear regression
    double slope = linearRegression(X, Y);

    // Output the result
    std::cout << "Slope of the line: " << slope << std::endl;

    return 0;
}
/* 1. We define a function linearRegression that takes two vectors X and Y representing
 the independent and dependent variables, respectively.
2. Inside linearRegression, we calculate the mean of X and Y.
3. Then, we calculate the slope and intercept of the line using the least squares method.
4. In the main function, we define sample data for X and Y and call the linearRegression function to get the slope of the line.
5. Finally, we print out the slope.*/
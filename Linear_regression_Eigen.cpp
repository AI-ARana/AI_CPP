/*linear regression implemented in C++ using the Eigen library for linear algebra.*/
#include <iostream>
#include <Eigen/Dense> // Include the Eigen library

using namespace Eigen;

int main() {
    // Sample data (input features and corresponding target values)
    MatrixXd X(3, 1);
    VectorXd y(3);
    
    X << 1, 2, 3;
    y << 2, 4, 6;

    // Linear regression model parameters (slope and intercept)
    double slope, intercept;

    // Compute the coefficients using the normal equation (closed-form solution)
    VectorXd ones = VectorXd::Ones(X.rows()); // Vector of ones for the intercept term
    MatrixXd X_augmented(X.rows(), X.cols() + 1); // Augment X with a column of ones for the intercept term
    X_augmented << ones, X;
    
    VectorXd theta = (X_augmented.transpose() * X_augmented).ldlt().solve(X_augmented.transpose() * y);

    // Extract the slope and intercept from the computed parameters
    intercept = theta[0];
    slope = theta[1];

    // Predict using the linear regression model
    VectorXd y_pred = X_augmented * theta;

    // Output the computed parameters and predictions
    std::cout << "Intercept: " << intercept << std::endl;
    std::cout << "Slope: " << slope << std::endl;
    std::cout << "Predictions: " << std::endl << y_pred << std::endl;

    return 0;
}

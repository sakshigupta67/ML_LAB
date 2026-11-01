
#include <stdio.h>

int main() {
    int n, epochs;
    double learningRate;

    printf("Linear Regression using Gradient Descent\n");
    printf("-----------------------------------------\n");

    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];

    // Input X and Y values
    printf("\nEnter X and Y values:\n");

    for (int i = 0; i < n; i++) {
        printf("Data %d (X Y): ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Initialize weight and bias
    double w = 0.0;
    double b = 0.0;

    // Input learning rate and epochs
    printf("\nEnter Learning Rate: ");
    scanf("%lf", &learningRate);

    printf("Enter Number of Epochs: ");
    scanf("%d", &epochs);

    // Batch Gradient Descent
    for (int epoch = 1; epoch <= epochs; epoch++) {

        double dw = 0.0;
        double db = 0.0;
        double mse = 0.0;

        // Calculate gradients and MSE
        for (int i = 0; i < n; i++) {

            double yPred = w * x[i] + b;
            double error = yPred - y[i];

            dw += error * x[i];
            db += error;

            mse += error * error;
        }

        // Calculate average gradients
        dw = (2.0 / n) * dw;
        db = (2.0 / n) * db;

        // Calculate MSE before updating parameters
        mse = mse / n;

        printf("Epoch %d  MSE = %.6f\n", epoch, mse);

        // Update weight and bias
        w = w - learningRate * dw;
        b = b - learningRate * db;
    }

    printf("\n-----------------------------------------\n");
    printf("Training Completed Successfully\n");
    printf("-----------------------------------------\n");

    // Display final weight and bias
    printf("\nFinal Weight (Slope)     = %.4f\n", w);
    printf("Final Bias (Intercept)   = %.4f\n", b);

    // Display regression equation
    printf("\nRegression Equation:\n");
    printf("Y = %.4fX + %.4f\n", w, b);

    // Display predicted values
    printf("\n-----------------------------------------\n");
    printf("X\tActual Y\tPredicted Y\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < n; i++) {

        double yPred = w * x[i] + b;

        printf("%.2f\t%.2f\t\t%.2f\n",
               x[i], y[i], yPred);
    }

    // Calculate final MSE
    double finalMSE = 0.0;

    for (int i = 0; i < n; i++) {

        double yPred = w * x[i] + b;
        double error = y[i] - yPred;

        finalMSE += error * error;
    }

    finalMSE = finalMSE / n;

    printf("-----------------------------------------\n");
    printf("Final Mean Squared Error (MSE) = %.6f\n",
           finalMSE);

    return 0;
}

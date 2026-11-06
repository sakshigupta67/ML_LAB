
#include <stdio.h>

int main()
{
    int n, epochs, i, j;
    float x[100], y[100], weight[100];
    float w = 0.0, b = 0.0, lr;
    float dw, db, prediction, error, wmse;

    printf("Weighted Linear Regression using Gradient Descent\n");
    printf("--------------------------------------------------\n");

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter X, Y and Weight values:\n");

    for (i = 0; i < n; i++)
    {
        printf("Data %d (X Y Weight): ", i + 1);
        scanf("%f %f %f", &x[i], &y[i], &weight[i]);
    }

    printf("Enter Learning Rate: ");
    scanf("%f", &lr);

    printf("Enter Number of Epochs: ");
    scanf("%d", &epochs);

    printf("Training Started...\n");

    for (i= 1; i <= epochs; i++)
    {
        dw = 0.0;
        db = 0.0;
        wmse = 0.0;

        for (j = 0; j < n; j++)
        {
            prediction = w * x[j] + b;
             error = prediction - y[j];

            dw += weight[j] * error * x[j];
            db += weight[j] * error;
            wmse += weight[j] * error * error;
        }

        dw = (2.0 / n) * dw;
        db = (2.0 / n) * db;
        wmse = wmse / n;

        w = w - lr * dw;
        b = b - lr * db;

        printf("Epoch %d WMSE = %.6f\n", i, wmse);
    }

    printf("----------------------------------------\n");
    printf("Training Completed Successfully\n");
    printf("----------------------------------------\n");

    printf("Final Weight (Slope) = %.4f\n", w);
    printf("Final Bias (Intercept) = %.4f\n", b);

    printf("Regression Equation:\n");
    printf("Y = %.4fX + %.4f\n", w, b);

    printf("--------------------------------------------------\n");
    printf("X\tActual Y\tWeight\tPredicted Y\n");
    printf("--------------------------------------------------\n");

    wmse = 0.0;

    for (i = 0; i < n; i++)
    {
        prediction = w * x[i] + b;
        error = prediction - y[i];

        wmse += weight[i] * error * error;

        printf("%.2f\t%.2f\t\t%.2f\t%.2f\n",
               x[i], y[i], weight[i], prediction);
    }

    wmse = wmse / n;

    printf("--------------------------------------------------\n");
    printf("Final Weighted Mean Squared Error (WMSE) = %.6f\n",
           wmse);

    return 0;
}

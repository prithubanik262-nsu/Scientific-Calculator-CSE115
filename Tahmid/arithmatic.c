#include <stdio.h>

// Function declaration of arithmatic modules
void addition();
void subtraction();
void multiplication();
void division();
void modulus();

int main()
{

    printf("|------------------------|\n");
    printf("|                        |\n");
    printf("|  Arithmetic operations |\n");
    printf("|                        |\n");
    printf("|------------------------|\n");

    int option;

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("0. Return to the main menu\n");

    printf("Enter your desired option:");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        addition();
        break;

    case 2:
        subtraction();
        break;

    case 3:
        multiplication();
        break;

    case 4:
        division();
        break;

    case 5:
        modulus();
        break;

    case 0:
        printf("Returing to the main menu\n");
        break;
    }

    return 0;
}

// starting the funtion defination.

// This is the addition module

void addition()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf + %lf = %.2lf\n", number1, number2, number1 + number2);
}

// This is the subtraction module

void subtraction()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf - %lf = %.2lf\n", number1, number2, number1 - number2);
}

// This is the multiplication module

void multiplication()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf * %lf = %.2lf\n", number1, number2, number1 * number2);
}

// This is the division module

void division()
{
    double number1, number2;

    printf("Enter the dividend: ");
    scanf("%lf", &number1);

    printf("Enter the divisor: ");
    scanf("%lf", &number2);

    if (number2 == 0)
    {
        printf("Invalid.Dividing by zero is undefined");
    }
    else
    {
        printf("The result is: %lf / %lf = %.2lf", number1, number2, number1 / number2);
    }
}

// This is the modulus module

void modulus()
{

    double number1, number2;

    printf("Enter the first integer: ");
    scanf("%lf", &number1);

    printf("Enter the second integer: ");
    scanf("%lf", &number2);

    if (number2 == 0)
    {
        printf("Invalid.Cannot divide by 0.");
    }
    else
    { // fmod is a function is [math.h] which does the same thing as a%b

        printf("\nThe result is:%lf %% %lf =%.2lf, number1, number2, fmod(number1, number2)");
    }
}
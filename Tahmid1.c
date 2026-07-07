#include <stdio.h>
#include <math.h>

// These are function prototypes. They tell the compiler that these functions exist.
void log_menu();
void natural_log();
void common_log();
void log_base_n();

int main()
{
    log_menu();
    return 0;
}

// This shall be displayed when log mode is chosen
    void log_menu()
{
    printf("|----------------------------------------------|\n");
    printf("|       This is the logarithm part             |\n");
    printf("|                                              |\n");
    printf("|----------------------------------------------|\n");

    int option;

    //the user has to choose the number of the desired option.
    
    printf("1. Natural log (ln)\n");
    printf("2. Common Log\n");
    printf("3. Log with any chosen base number\n");
    printf("0. Return to the main menu\n");

    printf("Enter your desired option: \n");

    if (scanf("%d", &option) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (option) // this checks which option is chosen by the user.
    {
        case 1:
        natural_log();
        break;

        case 2:
        common_log();
        break;

        case 3:
        log_base_n();
        break;

    // This exits the log menu and returns to the main menu.
        case 0:
        printf("Going back to the menu...\n");
        break;

    // This runs when the user inputs an invalid option.
        default:
        printf("Choose a valid option.\n");
        break;
    }
}

// These codes are for Natural Log.
void natural_log()
{
    double num;

    printf("\nEnter number: ");
    if (scanf("%lf", &num) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (num <= 0)
    {
        printf("Invalid number. Input a positive number.\n");
    }
    else
    {
        printf("ln(%.2lf) = %.4lf\n", num, log(num));
    }
}

// These codes are for common log.
void common_log()
{
    double num;

    printf("\nEnter number: ");
    if (scanf("%lf", &num) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (num <= 0)
    {
        printf("Invalid number. Input a positive number.\n");
    }
    else
    {
        printf("log10(%.2lf) = %.4lf\n", num, log10(num));
    }
}

// These codes are for log with any base.
void log_base_n()
{
    double num, base;

    printf("Enter number: ");
    if (scanf("%lf", &num) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    printf("Now enter the base: ");
    if (scanf("%lf", &base) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (num <= 0)
    {
        printf("Error! Number must be positive.\n");
    }
    else if (base <= 0 || base == 1)
    {
        printf("Error! Base must be positive and not equal to 1.\n");
    }
    else
    {
        printf("log base %.2lf of %.2lf = %.4lf\n", base, num, log(num) / log(base));
    }
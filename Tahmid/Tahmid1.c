#include <stdio.h>
#include <math.h>
#include <string.h>

void main_menu();

// These are function prototypes.
void log_menu();
void natural_log();
void common_log();
void log_base_n();

// These are the prototypes of the conversion part.
void conversion_menu();
void decimal_to_binary();
void binary_to_decimal();
void decimal_to_hexadecimal();
void hexadecimal_to_decimal();

int main()
{
    main_menu();
    return 0;
}

void main_menu()
{
    printf("|----------------------------------------------|\n");
    printf("|            Scientific Calculator             |\n");
    printf("|                                              |\n");
    printf("|----------------------------------------------|\n");

    int option;

    printf("1. Logarithm\n");
    printf("2. Number conversion\n");
    printf("0. Exit\n");

    printf("Enter your desired option: \n");

    if (scanf("%d", &option) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    switch (option)
    {
    case 1:
        log_menu();
        break;

    case 2:
        conversion_menu();
        break;

    case 0:
        printf("Closing the calculator...\n");
        break;

    default:
        printf("Choose a valid option.\n");
        break;
    }
}

// This shall be displayed when log mode is chosen
void log_menu()
{
    printf("|----------------------------------------------|\n");
    printf("|       This is the logarithm part             |\n");
    printf("|                                              |\n");
    printf("|----------------------------------------------|\n");

    int option;

    // the user has to choose the number of the desired option.

    printf("1. Natural log (ln)\n");
    printf("2. Common Log\n");
    printf("3. Log with any chosen base number\n");
    printf("0. Return to the main menu\n");

    printf("Enter your desired option: \n");

    if (scanf("%d", &option) != 1)

    
    // !=1 is used to check if user entered a valid integer.
    // scanf returning 1 if it successfully reads one number, of it doesnt return 1, the input is invalid.
    // why not !=2? becuz i asked it to read one 1 item only.
   
   
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
}

// This shall be displayed when conversion mode is chosen
void conversion_menu()
{
    printf("|----------------------------------------------|\n");
    printf("|      This is the number conversion part      |\n");
    printf("|                                              |\n");
    printf("|----------------------------------------------|\n");

    int option;

    // the user has to choose the number of the desired option.

    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    printf("3. Decimal to Hexadecimal\n");
    printf("4. Hexadecimal to Decimal\n");
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
        decimal_to_binary();
        break;

    case 2:
        binary_to_decimal();
        break;

    case 3:
        decimal_to_hexadecimal();
        break;

    case 4:
        hexadecimal_to_decimal();
        break;

        //  exitint the conversion menu and returns to the main menu.
    case 0:
        printf("Going back to the menu...\n");
        break;

        // This runs when the user inputs an invalid option.
    default:
        printf("Choose a valid option.\n");
        break;
    }
}

/* These codes are for decimal to binary.
 keep dividing the number by 2 and keep the remainders. those remainders are the binary digits.
 but they come out backwards, so they are kept in an array first and printed from the last one.
 */


void decimal_to_binary()
{
    int num, temp, i, j;
    int digits[40]; // an int never needs more than 32 binary digits, so this is enough

    printf("\nEnter a decimal number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (num < 0)
    {
        printf("Error! Enter a positive number.\n");
        return;
    }

    if (num == 0) // the loop below never runs for 0, so 0 is done separately
    {
        printf("0 in binary = 0\n");
        return;
    }

    temp = num; // num is kept safe so it can be printed at the end
    i = 0;

    while (temp > 0)
    {
        digits[i] = temp % 2; // the remainder is either 0 or 1
        temp = temp / 2;
        i++;
    }

    printf("%d in binary = ", num);

    for (j = i - 1; j >= 0; j--) // printing from the last digit to the first
    {
        printf("%d", digits[j]);
    }

    printf("\n");
}

/*
 These codes are for binary to decimal.
 the binary number is taken as text, not as a number.
 then every digit is added to the answer like this: answer = answer * 2 + digit.
*/

void binary_to_decimal()
{
    char binary[50];
    int decimal = 0;
    int i, length;

    printf("\nEnter a binary number: ");
    if (scanf("%s", binary) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    length = strlen(binary); // strlen counts how many characters were typed

    if (length > 31)
    {
        printf("Error! The number is too big.\n");
        return;
    }

    for (i = 0; i < length; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Error! A binary number can only have 0 and 1.\n");
            return;
        }

        decimal = decimal * 2 + (binary[i] - '0'); // '0' is taken away to turn the character into a number
    }

    printf("%s in decimal = %d\n", binary, decimal);
}

// These codes are for decimal to hexadecimal.
// same idea as binary, only the dividing is by 16.
// the remainders 10 to 15 have no single digit, so they are shown as A B C D E F.
void decimal_to_hexadecimal()
{
    int num, temp, i, j, remainder;
    char digits[20];

    printf("\nEnter a decimal number: ");
    if (scanf("%d", &num) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    if (num < 0)
    {
        printf("Error! Enter a positive number.\n");
        return;
    }

    if (num == 0)
    {
        printf("0 in hexadecimal = 0\n");
        return;
    }

    temp = num;
    i = 0;

    while (temp > 0)
    {
        remainder = temp % 16;

        if (remainder < 10)
        {
            digits[i] = remainder + '0'; // 0 to 9 stay as the digits 0 to 9
        }
        else
        {
            digits[i] = remainder - 10 + 'A'; // 10 becomes A, 11 becomes B, and so on
        }

        temp = temp / 16;
        i++;
    }

    printf("%d in hexadecimal = ", num);

    for (j = i - 1; j >= 0; j--)
    {
        printf("%c", digits[j]);
    }

    printf("\n");
}

/*
These codes are for hexadecimal to decimal.
the hexadecimal number is taken as text because of the letters A to F.
every character is turned into a number from 0 to 15,
then it is added to the answer like this: answer = answer * 16 + digit.
*/
void hexadecimal_to_decimal()
{
    char hex[20];
    int decimal = 0;
    int i, length, value;

    printf("\nEnter a hexadecimal number: ");
    if (scanf("%s", hex) != 1)
    {
        printf("Invalid input.\n");
        return;
    }

    length = strlen(hex);

    if (length > 7)
    {
        printf("Error! The number is too big.\n");
        return;
    }

    for (i = 0; i < length; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            value = hex[i] - '0';
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            value = hex[i] - 'A' + 10;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            value = hex[i] - 'a' + 10; // small letters are accepted too
        }
        else
        {
            printf("Error! A hexadecimal number can only have 0 to 9 and A to F.\n");
            return;
        }

        decimal = decimal * 16 + value;
    }

    printf("%s in decimal = %d\n", hex, decimal);
}
#include <stdio.h>
#include <math.h>

const double PI = 3.14159265;

double calculate_sin(double degree);
double calculate_cos(double degree);
double calculate_tan(double degree);
double calculate_sec(double degree);
double calculate_cosec(double degree);
double calculate_cot(double degree);

double calculate_arcsin(double value);
double calculate_arccos(double value);
double calculate_arctan(double value);
double calculate_arcsec(double value);
double calculate_arccosec(double value);
double calculate_arccot(double value);

void display_menu();

int main() {
    int user_choice;
    double input_value, final_result;

    display_menu();
    scanf("%d", &user_choice);

    if (user_choice == 1 || user_choice == 3 || user_choice == 5 ||
        user_choice == 7 || user_choice == 9 || user_choice == 11) {
        printf("Enter the angle in degrees: ");
    } else if (user_choice >= 2 && user_choice <= 12) {
        printf("Enter the value (number): ");
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    scanf("%lf", &input_value);

    switch (user_choice) {
        case 1:
            final_result = calculate_sin(input_value);
            printf("sin(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 2:
            final_result = calculate_arcsin(input_value);
            printf("arcsin(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
        case 3:
            final_result = calculate_cos(input_value);
            printf("cos(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 4:
            final_result = calculate_arccos(input_value);
            printf("arccos(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
        case 5:
            final_result = calculate_tan(input_value);
            printf("tan(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 6:
            final_result = calculate_arctan(input_value);
            printf("arctan(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
        case 7:
            final_result = calculate_sec(input_value);
            printf("sec(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 8:
            final_result = calculate_arcsec(input_value);
            printf("arcsec(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
        case 9:
            final_result = calculate_cosec(input_value);
            printf("cosec(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 10:
            final_result = calculate_arccosec(input_value);
            printf("arccosec(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
        case 11:
            final_result = calculate_cot(input_value);
            printf("cot(%.2lf deg) = %.4lf\n", input_value, final_result);
            break;
        case 12:
            final_result = calculate_arccot(input_value);
            printf("arccot(%.2lf) = %.4lf degrees\n", input_value, final_result);
            break;
    }

    return 0;
}

double calculate_sin(double degree) {
    double radian = degree * (PI / 180.0);
    return sin(radian);
}

double calculate_cos(double degree) {
    double radian = degree * (PI / 180.0);
    return cos(radian);
}

double calculate_tan(double degree) {
    double radian = degree * (PI / 180.0);
    return tan(radian);
}

double calculate_sec(double degree) {
    return 1.0 / calculate_cos(degree);
}

double calculate_cosec(double degree) {
    return 1.0 / calculate_sin(degree);
}

double calculate_cot(double degree) {
    return 1.0 / calculate_tan(degree);
}

double calculate_arcsin(double value) {
    double radian = asin(value);
    return radian * (180.0 / PI);
}

double calculate_arccos(double value) {
    double radian = acos(value);
    return radian * (180.0 / PI);
}

double calculate_arctan(double value) {
    double radian = atan(value);
    return radian * (180.0 / PI);
}

double calculate_arcsec(double value) {
    return calculate_arccos(1.0 / value);
}

double calculate_arccosec(double value) {
    return calculate_arcsin(1.0 / value);
}

double calculate_arccot(double value) {
    return calculate_arctan(1.0 / value);
}

void display_menu() {
    printf("=== Trigonometric Calculator (Degrees) ===\n");
    printf("1. sin(x)\t2. arcsin(x)\n");
    printf("3. cos(x)\t4. arccos(x)\n");
    printf("5. tan(x)\t6. arctan(x)\n");
    printf("7. sec(x)\t8. arcsec(x)\n");
    printf("9. cosec(x)\t10. arccosec(x)\n");
    printf("11. cot(x)\t12. arccot(x)\n");
    printf("Enter your choice: ");
}

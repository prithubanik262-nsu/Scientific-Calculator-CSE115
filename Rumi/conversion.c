#include <stdio.h>

const double KM_TO_MILE = 0.621371;
const double METER_TO_FEET = 3.28084;
const double CM_TO_INCH = 0.393701;
const double METER_TO_YARD = 1.09361;
const double KM_TO_NAUTICAL_MILE = 0.539957;

const double KG_TO_POUND = 2.20462;
const double GRAM_TO_OUNCE = 0.035274;

const double LITER_TO_GALLON = 0.264172;

double kilometer_to_mile(double km);
double mile_to_kilometer(double mile);
double meter_to_feet(double m);
double feet_to_meter(double ft);
double centimeter_to_inch(double cm);
double inch_to_centimeter(double inch);
double meter_to_yard(double m);
double yard_to_meter(double yd);
double kilometer_to_nautical_mile(double km);
double nautical_mile_to_kilometer(double nm);

double kilogram_to_pound(double kg);
double pound_to_kilogram(double lb);
double gram_to_ounce(double g);
double ounce_to_gram(double oz);

double liter_to_gallon(double l);
double gallon_to_liter(double gal);

double celsius_to_fahrenheit(double c);
double fahrenheit_to_celsius(double f);
double celsius_to_kelvin(double c);
double kelvin_to_celsius(double k);
double fahrenheit_to_kelvin(double f);
double kelvin_to_fahrenheit(double k);

void display_menu();

int main() {
    int user_choice;
    double input_value, final_result;

    display_menu();
    scanf("%d", &user_choice);

    printf("Enter the value: ");
    scanf("%lf", &input_value);

    switch (user_choice) {
        case 1:
            final_result = kilometer_to_mile(input_value);
            printf("%.2lf km = %.4lf miles\n", input_value, final_result);
            break;
        case 2:
            final_result = mile_to_kilometer(input_value);
            printf("%.2lf miles = %.4lf km\n", input_value, final_result);
            break;
        case 3:
            final_result = meter_to_feet(input_value);
            printf("%.2lf meters = %.4lf feet\n", input_value, final_result);
            break;
        case 4:
            final_result = feet_to_meter(input_value);
            printf("%.2lf feet = %.4lf meters\n", input_value, final_result);
            break;
        case 5:
            final_result = centimeter_to_inch(input_value);
            printf("%.2lf cm = %.4lf inches\n", input_value, final_result);
            break;
        case 6:
            final_result = inch_to_centimeter(input_value);
            printf("%.2lf inches = %.4lf cm\n", input_value, final_result);
            break;
        case 7:
            final_result = meter_to_yard(input_value);
            printf("%.2lf meters = %.4lf yards\n", input_value, final_result);
            break;
        case 8:
            final_result = yard_to_meter(input_value);
            printf("%.2lf yards = %.4lf meters\n", input_value, final_result);
            break;
        case 9:
            final_result = kilometer_to_nautical_mile(input_value);
            printf("%.2lf km = %.4lf nautical miles\n", input_value, final_result);
            break;
        case 10:
            final_result = nautical_mile_to_kilometer(input_value);
            printf("%.2lf nautical miles = %.4lf km\n", input_value, final_result);
            break;
        case 11:
            final_result = kilogram_to_pound(input_value);
            printf("%.2lf kg = %.4lf lbs\n", input_value, final_result);
            break;
        case 12:
            final_result = pound_to_kilogram(input_value);
            printf("%.2lf lbs = %.4lf kg\n", input_value, final_result);
            break;
        case 13:
            final_result = gram_to_ounce(input_value);
            printf("%.2lf grams = %.4lf oz\n", input_value, final_result);
            break;
        case 14:
            final_result = ounce_to_gram(input_value);
            printf("%.2lf oz = %.4lf grams\n", input_value, final_result);
            break;
        case 15:
            final_result = liter_to_gallon(input_value);
            printf("%.2lf liters = %.4lf gallons\n", input_value, final_result);
            break;
        case 16:
            final_result = gallon_to_liter(input_value);
            printf("%.2lf gallons = %.4lf liters\n", input_value, final_result);
            break;
        case 17:
            final_result = celsius_to_fahrenheit(input_value);
            printf("%.2lf C = %.4lf F\n", input_value, final_result);
            break;
        case 18:
            final_result = fahrenheit_to_celsius(input_value);
            printf("%.2lf F = %.4lf C\n", input_value, final_result);
            break;
        case 19:
            final_result = celsius_to_kelvin(input_value);
            printf("%.2lf C = %.4lf K\n", input_value, final_result);
            break;
        case 20:
            final_result = kelvin_to_celsius(input_value);
            printf("%.2lf K = %.4lf C\n", input_value, final_result);
            break;
        case 21:
            final_result = fahrenheit_to_kelvin(input_value);
            printf("%.2lf F = %.4lf K\n", input_value, final_result);
            break;
        case 22:
            final_result = kelvin_to_fahrenheit(input_value);
            printf("%.2lf K = %.4lf F\n", input_value, final_result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

double kilometer_to_mile(double km) {
    return km * KM_TO_MILE;
}

double mile_to_kilometer(double mile) {
    return mile / KM_TO_MILE;
}

double meter_to_feet(double m) {
    return m * METER_TO_FEET;
}

double feet_to_meter(double ft) {
    return ft / METER_TO_FEET;
}

double centimeter_to_inch(double cm) {
    return cm * CM_TO_INCH;
}

double inch_to_centimeter(double inch) {
    return inch / CM_TO_INCH;
}

double meter_to_yard(double m) {
    return m * METER_TO_YARD;
}

double yard_to_meter(double yd) {
    return yd / METER_TO_YARD;
}

double kilometer_to_nautical_mile(double km) {
    return km * KM_TO_NAUTICAL_MILE;
}

double nautical_mile_to_kilometer(double nm) {
    return nm / KM_TO_NAUTICAL_MILE;
}

double kilogram_to_pound(double kg) {
    return kg * KG_TO_POUND;
}

double pound_to_kilogram(double lb) {
    return lb / KG_TO_POUND;
}

double gram_to_ounce(double g) {
    return g * GRAM_TO_OUNCE;
}

double ounce_to_gram(double oz) {
    return oz / GRAM_TO_OUNCE;
}

double liter_to_gallon(double l) {
    return l * LITER_TO_GALLON;
}

double gallon_to_liter(double gal) {
    return gal / LITER_TO_GALLON;
}

double celsius_to_fahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double celsius_to_kelvin(double c) {
    return c + 273.15;
}

double kelvin_to_celsius(double k) {
    return k - 273.15;
}

double fahrenheit_to_kelvin(double f) {
    double celsius = fahrenheit_to_celsius(f);
    return celsius_to_kelvin(celsius);
}

double kelvin_to_fahrenheit(double k) {
    double celsius = kelvin_to_celsius(k);
    return celsius_to_fahrenheit(celsius);
}

void display_menu() {
    printf("=== Multi-Unit Converter ===\n");
    printf("--- Distance Conversions ---\n");
    printf("1. Km to Mile            2. Mile to Km\n");
    printf("3. Meter to Feet         4. Feet to Meter\n");
    printf("5. Cm to Inch            6. Inch to Cm\n");
    printf("7. Meter to Yard         8. Yard to Meter\n");
    printf("9. Km to Nautical Mile   10. Nautical Mile to Km\n");
    printf("--- Weight Conversions ---\n");
    printf("11. Kg to Pound          12. Pound to Kg\n");
    printf("13. Gram to Ounce        14. Ounce to Gram\n");
    printf("--- Volume Conversions ---\n");
    printf("15. Liter to Gallon      16. Gallon to Liter\n");
    printf("--- Temperature Conversions ---\n");
    printf("17. Celsius to Fahrenheit 18. Fahrenheit to Celsius\n");
    printf("19. Celsius to Kelvin    20. Kelvin to Celsius\n");
    printf("21. Fahrenheit to Kelvin 22. Kelvin to Fahrenheit\n");
    printf("\nEnter your choice: ");
}

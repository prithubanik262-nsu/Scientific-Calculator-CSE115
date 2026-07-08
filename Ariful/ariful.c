 /*
 * ______________________________________________________________
 * |        SCIENTIFIC CALCULATOR - CSE115 Project 1st semister |
 * |        Language  : C                                       |
 * |        Features  : Arithmetic, Trigonometry, Logarithm,    | 
 * |                    Power/Root, Factorial,  Permutation     |
 * |                    And Combination.                        |
 * |                                                            |
 * |                    Permutation And Combination , Factorial |
 * _____________________________________________________________|
 */



 /* This is the permutaion and combination  and Factorial part of the scientific calculator project. */



 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>




// FACTORIAL OPRATION


 long long factorial(int n) // ----------------Function to calculate factorial. We use long long to handle larger results.
 {
    if (n < 0) return -1;  // ---------------- it returns -1 for negative numbers as factorial is not defined for them.
    if (n == 0 || n == 1) return 1;// --------Factorial of 0 and 1 is 1.
    long long result = 1;// ------------------Initialize result to 1.
    for (int i = 2; i <= n; i++)// -----------the loop starts from 2 to n, multiplying each integer to the result.
        result *= i;// -----------------------Multiply result by i for each iteration.
    return result;// -------------------------Return the final factorial value.
}

// PERMUTATION OPERATION
//P(n, r) = n! / (n-r)!



long long permutation(int n, int r) {       //---Function to calculate permutation. We use long long to handle larger results.
    if (r > n || n < 0 || r < 0) return -1; //---It will return -1: Permutation is not defined for r > n or negative values.
    return factorial(n) / factorial(n - r); //---Calculate permutation using the formula P(n, r) = n! / (n-r)!
}

// COMBINATION OPERATION 
//C(n, r) = n! / (r! * (n-r)!)



long long combination(int n, int r) { // ---------Function to calculate combination. We use long long to handle larger results.
    if (r > n || n < 0 || r < 0) return -1; // ---It will return -1: Combination is not defined for r > n or negative values.
    return factorial(n) / (factorial(r) * factorial(n - r)); // Calculate combination using the formula C(n, r) = n! / (r! * (n-r)!)
}

int main() {
    int choice, n, r;

    printf("=== Calculator: Factorial, Permutation & Combination ===\n");// ----Display the menu for the user to choose an operation.
    printf("1. Factorial (n!)\n");// --------------Option for calculating factorial.
    printf("2. Permutation P(n, r)\n");// ---------Option for calculating permutation.
    printf("3. Combination C(n, r)\n");// ---------Option for calculating combination.
    printf("Enter choice: ");// -------------------Prompt the user to enter their choice of operation.
    scanf("%d", &choice); // ----------------------Read the user's choice.

    switch (choice) {                       // Switch statement is used to execute the corresponding case based on the user's choice.
        case 1:                            // If the user chooses 1, calculate factorial.
            printf("Enter n: ");          // Prompt the user to enter a value for n.
            scanf("%d", &n);             // Read the value of n from the user.
            long long f = factorial(n); // Call the factorial function and store the result in f.
            if (f == -1) printf("Error: n must be >= 0\n");     // If the result is -1, print an error message indicating that n must be non-negative.
            else printf("%d! = %lld\n", n, f);                 // Otherwise, print the calculated factorial value.
            break;                                            // Break out of the switch statement after executing case 1


        case 2:
            printf("Enter n and r: ");          // Prompt the user to enter values for n and r.
            scanf("%d %d", &n, &r);            // Read the values of n and r from the user.
            long long p = permutation(n, r);  // Call the permutation function and store the result in p.
            if (p == -1) printf("Error: invalid n or r\n");    // If the result is -1, print an error message indicating that n or r is invalid (e.g., r > n or negative values).  
            else printf("P(%d, %d) = %lld\n", n, r, p);       // Otherwise, print the calculated permutation value.
            break;                                           // Break out of the switch statement after executing case 2.



        case 3:
            printf("Enter n and r: ");               // Prompt the user to enter values for n and r.
            scanf("%d %d", &n, &r);                 // Read the values of n and r from the user.
            long long c = combination(n, r);       // ---Call the combination function and store the result in c.
            if (c == -1) printf("Error: invalid n or r\n"); // If the result is -1, print an error message indicating that n or r is invalid (e.g., r > n or negative values).
            else printf("C(%d, %d) = %lld\n", n, r, c);    // Otherwise, print the calculated combination value.
            break;                                        // Break out of the switch statement after executing case 3.
            
            


            default:// -----------------------If the user enters a choice that is not 1, 2, or 3, print an error message indicating that the choice is invalid.
            printf("Invalid choice\n");// ----Print an error message for invalid choice.
    }

    return 0;
}








#include <stdio.h>
#include <math.h>
#include <stdlib.h>




int main() {
    float a, b, c, discriminant, root1, root2;// ------Declare variables for coefficients, discriminant, and roots.
    
    printf("Enter coefficients  a (..can not be 0..) ,b and c: ");// ------Prompt the user to enter the coefficients of the quadratic equation.
    scanf("%f %f %f", &a, &b, &c);// ------------------Read the coefficients a, b, and c from the user.
    
    // Calculate discriminant
    discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) { // -----------------It will calculate the roots if the discriminant is positive, indicating two distinct real roots.
        root1 = (-b + sqrt(discriminant)) / (2 * a);// ---Calculate the first root using the quadratic formula.
        root2 = (-b - sqrt(discriminant)) / (2 * a);// ---Calculate the second root using the quadratic formula.
        printf("Two distinct real roots: %.2f and %.2f", root1, root2); // Print the two distinct real roots.
    }
    else if (discriminant == 0) { // ------Two equal real roots
        root1 = root2 = -b / (2 * a);// ---Calculate the equal root when the discriminant is zero.
        printf("Two equal real roots: %.2f and %.2f", root1, root2);// Print the two equal real roots.
    }
    else {
        // ---------Complex roots
        float realPart = -b / (2 * a);// ---Calculate the real part of the complex roots
        float imagPart = sqrt(-discriminant) / (2 * a);// ---Calculate the imaginary part of the complex roots
        printf("Complex roots: %.2f + %.2fi and %.2f - %.2fi", realPart, imagPart, realPart, imagPart);
    } // ---------Print the complex roots in the form of a + bi and a - bi.
    
    return 0;
}

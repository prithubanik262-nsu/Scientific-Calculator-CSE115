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



void quadratic_roots(int a, int b, int c) { // Function to calculate and display the roots of a quadratic equation ax^2 + bx + c = 0.
    if (a == 0) { // Check if 'a' is 0, which would make it not a quadratic equation.
        printf("Error: 'a' cannot be 0 (not a quadratic equation)\n");
        return ;
                }
 
    double discriminant = (b * b) - (4 * a * c);// Calculate the discriminant (b^2 - 4ac) to determine the nature of the roots.
    
    if (discriminant > 0) {
        // Two real roots
        double root1 = (-b + sqrt(discriminant)) / (2 * a);// Calculate the first root using the quadratic formula.
        double root2 = (-b - sqrt(discriminant)) / (2 * a);// Calculate the second root using the quadratic formula.
        printf("Two real roots:\n");
        printf("Root 1: %.3f\n", root1);
        printf("Root 2: %.3f\n", root2);
    }
    else if (discriminant == 0) {
        // One real root
        double root = -b / (2 * a);
        printf("One real root:\n");
        printf("Root: %.3f\n", root);
    } else {
        // Complex roots
        double realPart = -b / (2 * a);// Calculate the real part of the complex roots.
        double imaginaryPart = sqrt(-discriminant) / (2 * a);// Calculate the imaginary part of the complex roots.
        printf("Complex roots:\n");// Print a message indicating that the roots are complex.
        printf("Root 1: %.2f + %.2fi\n", realPart, imaginaryPart);
        printf("Root 2: %.2f - %.2fi\n", realPart, imaginaryPart);
    }



}

int main() {
    int choice, n, r, a, b, c;

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


     
        case 4:
            printf("Enter coefficients a, b, c for ax^2 + bx + c = 0:\n");// Prompt the user to enter coefficients for the quadratic equation.
            printf("Enter a: ");// Prompt the user to enter the coefficient a.
            scanf("%d", &a);   // Read the value of a from the user.
            printf("Enter b: ");// Prompt the user to enter the coefficient b.
            scanf("%d", &b);   // Read the value of b from the user.
            printf("Enter c: ");// Prompt the user to enter the coefficient c.
            scanf("%d", &c);   // Read the value of c from the user.
            quadratic_roots(a, b, c); // Call the function to calculate and display the roots of the quadratic equation.
            break;    


            default:// -----------------------If the user enters a choice that is not 1, 2, or 3, print an error message indicating that the choice is invalid.
            printf("Invalid choice\n");// ----Print an error message for invalid choice.
    }

    return 0;
}











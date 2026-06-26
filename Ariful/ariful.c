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




// FACTORIAL OPRATION //



int main(){

            int num;// Declaring the variable for factorial operation
            unsigned long long int fact = 1; // We use long long because factorials can grow very large .


            printf("Enter a positive integer: ");// Displaying message to the user to enter a positive integer.
            scanf("%d", &num); // Taking input from the user and storing it in the variable num.

            if (num < 0){// Checking if the number is negative.

                          printf("Error! Factorial of a negative number doesn't exist.\n");

                          // If the number is negative, we display an error message and exit the program.
                       }

            else {
                          for(int i = 1; i <= num; ++i) { // Multiplies the current value of i with factorial and stores the result in factorial.
                              fact *= i;//this is working as fact = fact * i
                          }

                        }
            printf("Factorial of %d = %lld\n", num, fact);
            //%d is used to print the integer value of num, and %lld is used to print the long long value of fact.




  return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max_matrix_size 10 //setting the maximum size that a matrix can have

//creating a new matrix datatype
typedef int matrix[max_matrix_size][max_matrix_size];

//function prototypes
void Welcome_screen();
void programs_names();
void power_root();
void matrices();
void vector();




int main(void){
    printf("hello world\nthis is the scientific calculator project\n\n");
    Welcome_screen();
    int command;//taking the value for whether the calculator will continue running or just terminate
    int program_option;//this takes the value of option of a program to run

    while(1){
        printf(">>> press 1 to continue or 0 to exit: ");
        scanf("%d", &command);
        if(command == 1){
            programs_names();
            // printf("\t>>>Choose your program.\n");
            // printf("\t  1.Power_Rootover");
            scanf(" %d", &program_option);
            switch(program_option){
                case 1:
                    power_root();
                    continue;

                case 2:
                    matrices();
                    continue;

                case 3:
                    vector();
                    continue;

                default:
                    printf("\n\t \"INVALID OUTPUT\" \n\n");

            }


        }
        else{
            printf("\n\t>>> Thank you for using the calculator.\n\n");
            break;
        }

    }

    return 0;



}

//this will be printed at the very beginning
void Welcome_screen(){
    printf("\t\t ____________________________________ \n");
    printf("\t\t|                                    |\n");
    printf("\t\t|               WELCOME              |\n");
    printf("\t\t|        1st Semester Project        |\n");
    printf("\t\t|        SCIENTIFIC CALCULATOR       |\n");
    printf("\t\t|                                    |\n");
    printf("\t\t|____________________________________|\n");
    printf("\n\n");
}
void programs_names(){
    printf("\t>>>The programs are: \n\n");
    printf("\t  1.Power_Rootover\n");
    printf("\t  2.Matrix\n");
    printf("\t  3.Vector\n\n");
    printf("\t >>>Choose your program: ");
}

void power_root(){
    printf("\n\t>>> This is power-root program\n");

    double a;//this is local variable exclusive to the power_root function
    int choice;//this variable stores the choice of user of what operation the user wants to use and this variable is used in switch-case
    double n;//this is for using n-th root and n-th power
    int rerun_program = 1;//this is variable to control whether the program will rerun or not
                         //I used a if-statement in the while-loop to update this variable and break out of this loop

    while(rerun_program){
        if(rerun_program == 1){
            printf("\n\n\t Press 0 to exit...\n\n");
            printf("\t >>> Available operations: \n");
            printf("\t 1. square\n");
            printf("\t 2. square-root\n");
            printf("\t 3. n-th power\n");
            printf("\t 4. n-th root\n");

            printf("\t >>> Choose your operation: ");
            scanf("%d", &choice);

            if(choice == 0){
                break;
            }

            printf("\t >>> Enter number you want to operate on: ");
            scanf("%lf", &a);

            switch(choice){
                case 1:
                    printf("\t The square is: %.2lf", a*a);
                    break;
                case 2:
                    printf("\t The square-root is: %.2lf", sqrt(a));
                    break;
                case 3:
                    printf("\t >> Enter n:");
                    scanf("%lf", &n);
                    printf("The %.3lf th power of %.0lf is: ", n, pow(a, n));
                    break;
                case 4:
                    printf("\t >> Enter n:");
                    scanf("%lf", &n);
                    printf("The %lf th root of %lf is: ", n, pow(a, 1.0/n));
                    break;
                default:
                    printf("\t\n Invalid Input!");
                    break;

            }
        }

        else{
            break;
        }
    }

    printf("\n\n");

}

void matrices(){
    printf("\n\t>>>this is matrix program\n");
    printf("\n\n");

}

void vector(){
    printf("\n\t>>>this vector program\n");
    printf("\n\n");
}


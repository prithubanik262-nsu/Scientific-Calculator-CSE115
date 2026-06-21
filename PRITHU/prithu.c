#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max_matrix_size 10 //setting the maximum size that a matrix can have

//creating a new matrix datatype
typedef int matrix[max_matrix_size][max_matrix_size];

//function prototypes
void heading();
void power_root();
void matrices();
void vector();




int main(void){
    printf("hello world\nthis is the scientific calculator project\n\n");

    int command;//taking the value for whether the calculator will continue running or just terminate
    int program_option;//this takes the value of option of a program to run

    while(1){
        printf(">>> press 1 to continue or 0 to exit: ");
        scanf("%d", &command);
        if(command == 1){
            heading();
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
void heading(){
    printf("\t\t ____________________________________ \n");
    printf("\t\t|                                    |\n");
    printf("\t\t|               WELCOME              |\n");
    printf("\t\t|        1st Semester Project        |\n");
    printf("\t\t|        SCIENTIFIC CALCULATOR       |\n");
    printf("\t\t|                                    |\n");
    printf("\t\t|____________________________________|\n");
    printf("\n\n");
    printf("\t>>>The programs are: \n\n");
    printf("\t  1.Power_Rootover\n");
    printf("\t  2.Matrix\n");
    printf("\t  3.Vector\n\n");
    printf("\t >>>Choose your program: ");
}

void power_root(){
    printf("\n\t>>>this is power-root program\n");
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


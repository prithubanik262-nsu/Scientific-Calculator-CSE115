#include <stdio.h>
#include<math.h>

// This are function prototypes which tells the compiler that these mentioned funtios exist.

void natural_log();
void common_log();
void log_base_n();


int main()

// This shall be displayed when log mode is chosen
{
       printf("|----------------------------------------------|\n");
       printf("|       This is the logarithm part             |\n "); 
       printf("|                                              |\n ");
       printf("|----------------------------------------------|\n");

       int option;

       printf("1. Natural log (ln)\n");
       printf("2. Common Log\n");
       printf("3. Log with any chosen base number\n");
       printf("0. Return to the main menu\n");

       printf("Enter your desired option: \n");
       scanf("%d", &option);


       switch(option) //this checks which option is chosen by the user.
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


         //This exists from the log menu and return to the main menu.
        case 0: 
        printf("Going back to the menu...\n");
        break;



        // this one executes when the user inputs an invalid option.
        default:
        printf("Choose a valid option.\n");  



       }

    return 0;
}



    
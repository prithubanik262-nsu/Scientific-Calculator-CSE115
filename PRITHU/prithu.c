#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define max_matrix_size 10 //setting the maximum size that a matrix can have

//creating a new matrix datatype
typedef double matrix[max_matrix_size][max_matrix_size];

//function prototypes
void Welcome_screen();
void programs_names();
//all functions of power_root
void power_root();
//all functions of matrix
int valid_dimension_to_multiply(int row, int col);
int validate_matrix(int rows, int cols);
void input_matrix(matrix mat, int rows, int cols);
void print_matrix(matrix mat, int rows, int cols, char name);
void matrix_addition();
void matrix_subtraction();
void matrix_multiplication();
void matrices();
//all functions of vector
void vector();




int main(void){
    printf("hello world\nthis is the scientific calculator project\n\n");
    Welcome_screen();
    int command;//taking the value for whether the calculator will continue running or just terminate
    int program_option;//this takes the value of option of a program to run
    int running = 1;//this indicated whether the full calculator is running or not

    while(running){
        printf(">>> press 1 to continue or 0 to exit: ");
        scanf("%d", &command);
        if(command == 1){
            programs_names();

            scanf(" %d", &program_option);
            switch(program_option){
                case 1:
                    power_root();
                    break;

                case 2:
                    matrices();
                    break;

                case 3:
                    vector();
                    break;

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

//this is a dedicated function to print out the names of the program
void programs_names(){
    printf("\t>>>The programs are: \n\n");
    printf("\t  1.Power_Rootover\n");
    printf("\t  2.Matrix\n");
    printf("\t  3.Vector\n\n");
    printf("\t >>>Choose your program: ");
}

// ---- EVERYTHING OF POWER-ROOT FUNCTION IS IN HERE ----------
void power_root(){
    printf("\n\t>>> This is power-root program\n");

    double a;//this is local variable exclusive to the power_root function

    int choice;/*this variable stores the choice of user of what operation the user wants to use and this variable is used in switch-case
                if choice is 0, then the while-loop will break and the calculator will go to the main menu
                    */
    double n;//this is for using n-th root and n-th power

    int rerun_program = 1;/*this is variable to control whether the program will rerun or not
                            A if-statement has been used in the while-loop to update this variable and break out of this loop
                            this helps the user to stay at the current program without restarting the calculator after a task is finished
                          */

    double positive_part_of_number;//this variable handles the test-case where the user input negative value in square-root or n-th root

    char imaginary ; /*this helps to see if the user has typed 'i' or 'I' in the terminal,
                       so that imaginary functionality can be applied accordingly in the square function
                     */

    while(rerun_program){
        //whole functionality of this power_root program is in this if statement
        if(rerun_program == 1){
            printf("\n\n\t Press 0 to exit...\n\n");

            printf("\t >>> Available operations: \n");
            printf("\t 1. square\n");
            printf("\t 2. square-root\n");
            printf("\t 3. n-th power\n");
            printf("\t 4. n-th root\n");

            printf("\t >>> Choose your operation: ");
            scanf("%d", &choice);

            //this will make the program shut down and restart the calculator if the user types '0'
            if(choice == 0){
                printf("\n\t exiting to main menu \n\n");
                break;
            }

            printf("\t >>> Enter number you want to operate on: ");
            scanf("%lf%c", &a, &imaginary);//using the "imaginary" variable to handle the imaginary test cases

            switch(choice){
                case 1:
                    //this handles the test-case when the user types 'i' or 'I' in the terminal
                    if(imaginary == 'i' || imaginary == 'I'){
                        printf("\t The square of is: - %.2lf", a*a);
                        break;
                    }

                    else{
                        printf("\t The square is: %.2lf", a*a);
                        break;
                    }
                case 2:
                    //this handles the the test-case where the user inputs negative number
                    if(a<0){
                        positive_part_of_number = fabs(a);
                        printf("\t The square-root is: %.2lf i", sqrt(positive_part_of_number));
                        break;
                    }

                    else{
                        printf("\t The square-root is: %.2lf", sqrt(a));
                        break;
                    }
                case 3:
                    printf("\t >> Enter n:");
                    scanf("%lf", &n);
                    //handling the imaginary number case
                    if(imaginary == 'i' || imaginary == 'I'){
                        int n1 =  (int)n;//converting the datatype
                        int remain = n1%4;//this is to determine the multiplication of i or I

                        switch(remain){
                            case 0:
                                printf("\t The %.0lf th power of %.0lf%c is: %.0lf%c \n", n,a,imaginary, pow(a, n),imaginary);
                                break;
                            case 1:
                                printf("\t The %.0lf th power of %.0lf%c is: %.0lf%c \n", n,a,imaginary, pow(a, n), imaginary);
                                break;
                            case 2:
                                printf("\t The %.0lf th power of %.0lf%c is: -%.0lf%c \n", n,a,imaginary, pow(a, n), imaginary);
                                break;
                            case 3:
                                printf("\t The %.0lf th power of %.0lf%c is: -%.0lf%c \n", n,a,imaginary, pow(a, n), imaginary);
                                break;
                            default:
                                printf("INVALID INPUT");
                                break;
                        }
                    }
                    else{
                        printf("The %.3lf th power of %.0lf is: ", n, pow(a, n));
                        break;
                    }
                    break;//this is the break of case 3
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


// ------- EVERYTHING OF MATRICES IS HERE ---------

//the function which originally controls the matrix function
void matrices(){
    printf("\n\t>>>this is matrix program\n");
    printf("\t matrix size is maximum 10 rows and 10 columns\n\n");

    matrix A, B, C; /* matrix A & B will be the matrices that will be operated on
                       the matrix C stores the solution after operation
                    */

    int choice;//this variable stores the choice of user of what operation the user wants to use and this variable is used in switch-case

    int rerun = 1; /*this is variable to control whether the program will rerun or not
                       A if-statement has been used in the while-loop to update this variable and break out of this loop
                       this helps the user to stay at the current program without restarting the calculator after a task is finished
                      */

    int rows, cols;

    while(rerun){

        //whole functionality of this program is in this if statement
        if(rerun == 1){

            //asking for operations

            printf("\n\t press 0 to exit\n");
            printf("\n\t available operators......\n\n");
            printf("\t 1. matrix addition \n");
            printf("\t 2. matrix subtraction \n");
            printf("\t 3. matrix multiplication \n");
            printf("\t 4. determinant\n");
            printf("\t 5. inverse of matrix\n");
            printf("\t 6. transpose matrix\n");

            printf("\n\t choose your operation: ");

            scanf("%d", &choice);

            if(choice == 0){
                printf("\n\t exiting to main menu\n\n");
                break;
            }


            printf("\n");


            switch(choice){
                case 1:
                    matrix_addition();
                    break;

                case 2:
                    matrix_subtraction();
                    break;

                case 3:
                    matrix_multiplication();
                    break;

                case 4:
                    printf("\n\t this is matrix determinant\n");
                    break;

                case 5:
                    printf("\n\t this is matrix inversion\n");
                    break;

                case 6:
                    printf("\n\t this is matrix transpose\n");
                    break;

                default:
                    printf("\n\tINVALID INPUT");
                    break;

            }

        }

        else{
            break;
        }
    }

    printf("\n\n");

}


 //  valid_dimension_to_multiply(), validate_matrix(), matrix_input() and print_matrix() functions are the backbone for the rest of the functions of matrix

//this function is used in multiply_matrix function to check if the matrices are multiplyable
int valid_dimension_to_multiply(int col, int row){

    if(col == row){
        return 1;
    }
    else{
        return 0;
    }

}

//this checks if the matrix exists or the matrix's size is bigger than the maximum size
int validate_matrix(int rows, int cols){

    if(rows > max_matrix_size || cols > max_matrix_size || rows <= 0 || cols <= 0){
        return 0;
    }
    else{
        return 1;
    }

}

//making a matrix of desired row and column by taking input from the user for each data on each row and column
void input_matrix(matrix mat, int rows, int cols){

    //firstly validating if the matrix's syntax is correct or not
    if((validate_matrix(rows, cols)) == 0){
        printf("\n\t INVALID MATRIX \n");
    }

    //taking input
    //i and j could have been initialized with value 1, but an array is 0 indexed so there could be trouble later
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            printf("\n\t enter for row: %d and col: %d for matrix ", i+1, j+1);
            scanf("%lf", &mat[i][j]);
        }
    }

}

//printing the matrix in a grid format
void print_matrix(matrix mat, int rows, int cols, char name){

    if((validate_matrix(rows, cols)) == 0){
        printf("INVALID MATRIX");
    }

    printf("\n\t Printing for matrix %c\n", name);

    for(int i = 0; i<rows; i++){
        printf("\t| ");
        for(int j = 0; j<cols; j++){
            printf(" %.2lf ", mat[i][j]);
        }
        printf(" |\n");
    }

    printf("\n");


}


//now working on the core 6 functions of the matrix

//addition between two functions
void matrix_addition(){
    printf("\n\t This is matrix addition \n");
    printf("\t  Addition between two matrices \n");

    matrix A, B, C;  /* matrix A & B will be the matrices that will be operated on
                       the matrix C stores the solution after operation
                     */

    int rowA, rowB, colA, colB;  //user will input these values

    int rowC, colC; //the result for each data in a specific row-column block will be stored here

    //////////// taking data for matrix A ////////////////

    printf("\t Input for matrix A \n");
    printf("\t row of A: ");
    scanf("%d", &rowA);
    printf("\t column of A: ");
    scanf("%d", &colA);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowA, colA)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    input_matrix(A, rowA, colA);

    //////////// taking data for matrix B ////////////////

    printf("\t Input for matrix B \n");
    printf("\t row of B: ");
    scanf("%d", &rowB);
    printf("\t column of B: ");
    scanf("%d", &colB);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowB, colB)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    //checking if the dimensions are valid
    if( (rowA != rowB) || (colA !=colB) ){
        printf("\n\t the rows and the columns of the matrices should be equal in order to operate addition between them\n");
    }

    input_matrix(B, rowB, colB);

    //as rowA = rowB and colA = colB, rowC and colC can be equaled to either ones
    rowC = rowA;
    colC = colA;

    print_matrix(A, rowA, colA, 'A');
    print_matrix(B, rowB, colB,  'B');

    //working on matrix C now
    //adding the elements of the two matrices into the 3rd matrix
    for(int i = 0; i< rowA; i++){
        for(int j = 0; j< colA; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\n\t The sum of the two matrices is given below \n");
    print_matrix(C, rowC, colC, 'C');

}

void matrix_subtraction(){

 printf("\n\t This is matrix subtraction \n");
    printf("\t  Subtraction between two matrices \n");

    matrix A, B, C;  /* matrix A & B will be the matrices that will be operated on
                       the matrix C stores the solution after operation
                     */

    int rowA, rowB, colA, colB;  //user will input these values

    int rowC, colC; //the result for each data in a specific row-column block will be stored here

    //////////// taking data for matrix A ////////////////

    printf("\t Input for matrix A \n");
    printf("\t row of A: ");
    scanf("%d", &rowA);
    printf("\t column of A: ");
    scanf("%d", &colA);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowA, colA)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    input_matrix(A, rowA, colA);

    //////////// taking data for matrix B ////////////////

    printf("\t Input for matrix B \n");
    printf("\t row of B: ");
    scanf("%d", &rowB);
    printf("\t column of B: ");
    scanf("%d", &colB);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowB, colB)) == 0 ){
        printf("\n\t INVALID rows or cols \n");
    }

    //checking if the dimensions are valid
    if( (rowA != rowB) || (colA !=colB) ){
        printf("\n\t the rows and the columns of the matrices should be equal in order to operate addition between them\n");
    }

    input_matrix(B, rowB, colB);

    //as rowA = rowB and colA = colB, rowC and colC can be equaled to either ones
    rowC = rowA;
    colC = colA;

    print_matrix(A, rowA, colA, 'A');
    print_matrix(B, rowB, colB,  'B');


    //working on matrix C now
    //subtracting the elements of the two matrices into the 3rd matrix

    int choose_how_to_subtract;//this is used to let the user choose whether he/she wants to do A-B or B-A

    printf("\n\t What do you want to do?");
    printf("\n\t type 1 to choose A-B or type 2 to choose B-A : ");
    scanf("%d", &choose_how_to_subtract);

    if(choose_how_to_subtract == 1){
        for(int i = 0; i< rowA; i++){
            for(int j = 0; j< colA; j++){
                C[i][j] = A[i][j] - B[i][j];
            }
        }
    }

    else{
         for(int i = 0; i< rowA; i++){
            for(int j = 0; j< colA; j++){
                C[i][j] = B[i][j] - A[i][j];
            }
        }
    }

    printf("\n\t The subtraction of the two matrices is given below \n");
    print_matrix(C, rowC, colC, 'C');

}

void matrix_multiplication(){

    printf("\n\t This is matrix multiplication \n");
    printf("\t  Multiply between two matrices \n");

    matrix A, B, C;  /* matrix A & B will be the matrices that will be operated on
                       the matrix C stores the solution after operation
                     */

    int rowA, rowB, colA, colB;  //user will input these values

    int rowC, colC; //the result for each data in a specific row-column block will be stored here

    //////////// taking data for matrix A ////////////////

    printf("\t Input for matrix A \n");
    printf("\t row of A: ");
    scanf("%d", &rowA);
    printf("\t column of A: ");
    scanf("%d", &colA);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowA, colA)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    input_matrix(A, rowA, colA);

    //////////// taking data for matrix B ////////////////

    printf("\t Input for matrix B \n");
    printf("\t row of B: ");
    scanf("%d", &rowB);
    printf("\t column of B: ");
    scanf("%d", &colB);

    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(rowB, colB)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }


    input_matrix(B, rowB, colB);

    //taking input for how the user wants to multiply
    int choose_how_to_multiply;
    printf("\n\t Choose how to multiply... \n");
    printf("\n\t type 1 to AxB or type 2 to BxA: ");
    scanf("")

    // AxB
    if(choose_how_to_multiply == 1){
        if(valid_dimension_to_multiply(colA, rowB)){
             for(int i = 0; i< rowA; i++){
                for(int j = 0; j< colB; j++){
                    C[i][j] = 0; //initializing the value for C matrix's one cell
                    for(int k = 0; k < colA; k++){ // k<colA and k<rowB are identical
                        C[i][j] += A[i][k] * B[k][j];//k transverses through A's row and B's column
                    }
                }
            }
        }
        else{
            printf("\n\t Dimensions are invalid!!\n");
            printf("Column of A must be equal to Row of B");
        }
    }

     // BxA
     if(choose_how_to_multiply == 2){
        if(valid_dimension_to_multiply(colB, rowA)){
             for(int i = 0; i< rowB; i++){
                for(int j = 0; j< colA; j++){
                    C[i][j] = 0; //initializing the value for C matrix's one cell
                    for(int k = 0; k < colB; k++){ // k<colB and k<rowA are identical
                        C[i][j] += B[i][k] * A[k][j];//k transverses through A's row and B's column
                    }
                }
            }
        }
        else{
            printf("\n\t Dimensions are invalid!!\n");
            printf("Column of A must be equal to Row of B");
        }
    }

    print_matrix(A, rowA, colA, 'A');
    print_matrix(B, rowB, colB,  'B');

    //working on matrix C now
    //adding the elements of the two matrices into the 3rd matrix
    for(int i = 0; i< rowA; i++){
        for(int j = 0; j< colA; j++){
            C[i][j] = 0; //initializing the value for C matrix's one cell
            for(int k = 0; k < )
        }
    }

    printf("\n\t The sum of the two matrices is given below \n");
    print_matrix(C, rowC, colC, 'C');



}

void vector(){
    printf("\n\t>>>this vector program\n");
    printf("\n\n");
}


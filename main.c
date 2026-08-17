/*    important header files    */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//========================================================================
/*   constants and user defined data types   */

#define max_matrix_size 10 //setting the maximum size that a matrix can have
#define max_vector_size 3 //setting maximum dimensions a vector can have
//creating a new matrix data type
typedef double matrix[max_matrix_size][max_matrix_size];
//creating a new vector data type
typedef double vector[max_vector_size];
//creating a constant for PI
const double PI = 3.14159265;

/*       constants for unit_conversion(RUMI)    */
//distance
const double KM_TO_MILE = 0.621371;
const double METER_TO_FEET = 3.28084;
const double CM_TO_INCH = 0.393701;
const double METER_TO_YARD = 1.09361;
const double KM_TO_NAUTICAL_MILE = 0.539957;

//weight
const double KG_TO_POUND = 2.20462;
const double GRAM_TO_OUNCE = 0.035274;

//liquid
const double LITER_TO_GALLON = 0.264172;



//==============================================================================
/*   function prototypes    */


void Welcome_screen();
void programs_names();


/*                         PRITHU                            */
//=============================================================

/*    main programs prototypes    */
void power_root();
void matrices();
void vectors();

/*   peripheral functions prototypes   */

/* |||||||||       matrices         ||||||||||| */

int valid_dimension_to_multiply(int row, int col);
int validate_matrix(int rows, int cols);
void input_matrix(matrix mat, int rows, int cols);
void print_matrix(matrix mat, int rows, int cols, char name);
void matrix_addition();
void matrix_subtraction();
void matrix_multiplication();
void matrix_determinant();
double calculate_determinant(matrix mat, int size);
void get_submatrix(matrix mat, matrix sub_mat, int skip_row, int skip_col, int size);
void matrix_inverse();

/* |||||||||       vectors          ||||||||||| */

void vector_input(vector v);
void vector_print(vector v);
void vector_addition();
void vector_subtraction();
void vector_dot();
void vector_cross();




/*                         TAHMID                            */
//============================================================

/*       main programs prototypes        */
void logarithms();
void arithmetic_operations();
void base_conversion();

/*    periferal funcitons      */

/*  |||||||||      logarithms       ||||||||| */
void log_menu();
void natural_log();
void common_log();
void log_base_n();

/*  |||||||    arithmetic operations  ||||||| */
void addition();
void subtraction();
void multiplication();
void division();
void modulus();

/*  |||||||||   base unit_conversion  ||||||||| */

void conversion_menu();
void decimal_to_binary();
void binary_to_decimal();
void decimal_to_hexadecimal();
void hexadecimal_to_decimal();


/*                          RUMI                             */
//============================================================

/*       main programs prototypes        */
void trigonometry();
void unit_conversion();

/*         periferal programs   */

/*  |||||||||   trigonometry   ||||||||| */
/*  ---- normal ----    */
double calculate_sin(double degree);
double calculate_cos(double degree);
double calculate_tan(double degree);
double calculate_sec(double degree);
double calculate_cosec(double degree);
double calculate_cot(double degree);
/*    ---- inverse ----    */
double calculate_arcsin(double value);
double calculate_arccos(double value);
double calculate_arctan(double value);
double calculate_arcsec(double value);
double calculate_arccosec(double value);
double calculate_arccot(double value);


/*  |||||||||   unit_conversion   ||||||||| */
//distance
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

//distance
double kilogram_to_pound(double kg);
double pound_to_kilogram(double lb);
double gram_to_ounce(double g);
double ounce_to_gram(double oz);

//liquid
double liter_to_gallon(double l);
double gallon_to_liter(double gal);

//temparature
double celsius_to_fahrenheit(double c);
double fahrenheit_to_celsius(double f);
double celsius_to_kelvin(double c);
double kelvin_to_celsius(double k);
double fahrenheit_to_kelvin(double f);
double kelvin_to_fahrenheit(double k);



/*                          ARIF                             */
//============================================================

/*    main programs prototypes    */
void factorials();
void permutations();
void combinations();
void polynomial_roots_solving();

/*   peripheral functions prototypes   */

/* |||||||||       factorials         ||||||||||| */
double factorial(int n);
/* |||||||||       permutations      ||||||||||| */
long long permutation(int n, int r);
/* |||||||||       combinations      |||||||||| */
long long combination(int n, int r);
/* |||||||||       polynomial roots  ||||||||||| */
void polynomiyal_roots(int a, int b, int c);




int main(){

    printf("hello world...\nthis is the scientific calculator project\n\n");
    Welcome_screen();
    int command;//taking the value for whether the calculator will continue running or just terminate
    int program_option;//this takes the value of option of a program to run
    int running = 1;//this indicated whether the full calculator is running or not

    while(running){
        printf(">>> press 1 to continue or 0 to exit: ");
        scanf("%d", &command);

        if(command){
            programs_names();

            scanf(" %d", &program_option);
            switch(program_option){

                case 1:
                    arithmetic_operations();
                    break;

                case 2:
                    logarithms();
                    break;

                case 3:
                    power_root();
                    break;

                case 4:
                    trigonometry();
                    break;

                case 5:
                    matrices();
                    break;

                case 6:
                    vectors();
                    break;

                case 7:
                    factorials();
                    break;

                case 8:
                    permutations();
                    break;

                case 9:
                    combinations();
                    break;

                case 10:
                    polynomial_roots_solving();
                    break;

                case 11:
                    unit_conversion();
                    break;

                case 12:
                    base_conversion();
                    break;


                default:
                    printf("\n\t \"INVALID OUTPUT\" \n\n");
                    break;

            }
        }
        else{
            printf("\n\t>>> Thank you for using the calculator.\n\n");
            break;
        }
    }

    return 0;

}


int choice;/*this is a global variable
            it stores the choice of user of what operation the user wants to use and this variable is used in switch-case of matrices()
            it is also used in the  general_input_for_every_function() function
            */

int rerun_program = 1;/*this is variable to control whether the program will rerun or not
                        A if-statement has been used in the while-loop to update this variable and break out of this loop
                        this helps the user to stay at the current program without restarting the calculator after a task is finished
                       */

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

//the names are in cronological order of the project ideas
void programs_names(){

    printf("\t>>>The programs are: \n\n");
    printf("\t   1. Arithmatic operation \n\n");
    printf("\t   2. Logarithm \n\n");
    printf("\t   3. Power_root \n\n");
    printf("\t   4. Trigonometry \n\n");
    printf("\t   5. Matrix \n\n");
    printf("\t   6. Vector \n\n");
    printf("\t   7. Factorial \n\n");
    printf("\t   8. Permutation \n\n");
    printf("\t   9. Combination \n\n");
    printf("\t  10. Polynomial roots solving \n\n");
    printf("\t  11. Conversion \n\n");
    printf("\t >>>  Choose your program: ");
}

// _________________________________________________________
/*|                 function definations                    | */ 
//|_________________________________________________________|

//=================================================
/*                    PRITHU                     */
//=================================================

/*           main functions       */

void power_root(){

    printf("\n\t>>> This is power-root program\n");

    double a;//this is local variable exclusive to the power_root function

    double n;//this is for using n-th root and n-th power

    double positive_part_of_number;//this variable handles the test-case where the user input negative value in square-root or n-th root
    
    char imaginary ; /*this helps to see if the user has typed 'i' or 'I' in the terminal,
                       so that imaginary functionality can be applied accordingly in the square function
                     */

    while(rerun_program){
        //whole functionality of this power_root program is in this if statement
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
                        printf("The %.3lf th power of %.0lf is: %0lf", n, a, pow(a, n));
                        break;
                    }
                    break;//this is the break of case 3
                case 4:
                    if(a<0){
                        printf("n-th root of imaginary number or negative number is not available \n");
                    }
                    else{
                        printf("\t >> Enter n:");
                        scanf("%lf", &n);
                        printf("The %.1lf th root of %lf is: %.0lf", n, a, pow(a, 1.0/n));
                    }
                    break;
                default:
                    printf("\t\n Invalid Input!");
                    break;

            }
        }

    printf("\n\n");

}

void matrices(){
    printf("\n\t>>>this is matrix program\n");
    printf("\t matrix size is maximum 10 rows and 10 columns\n\n");


    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operators......\n\n");
        printf("\t 1. matrix addition \n");
        printf("\t 2. matrix subtraction \n");
        printf("\t 3. matrix multiplication \n");
        printf("\t 4. determinant\n");
        printf("\t 5. inverse of matrix\n");

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
                matrix_determinant();
                break;

            case 5:
                matrix_inverse();
                break;

            default:
                printf("\n\tINVALID INPUT");
                break;
        }
    }

    printf("\n\n");

}

void vectors(){

    printf("\n\t>>>this vector program\n");
    printf("\n\n");

    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operators......\n\n");
        printf("\t 1. Vector addition \n");
        printf("\t 2. Vector substraction \n");
        printf("\t 3. Vector dot multiplication \n");
        printf("\t 4. Vector cross multiplication \n");

        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        printf("\n");


        switch(choice){
            case 1:
                vector_addition();
                break;

            case 2:
                vector_subtraction();
                break;

            case 3:
                vector_dot();
                break;

            case 4:
                vector_cross();
                break;

            default:
                printf("\n\tINVALID INPUT");
                break;
        }
    }

}


/*        periferal functions    */

/* |||||||||       matrices         ||||||||||| */

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
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            printf("\n\t enter for row: %d and col: %d >>> ", i+1, j+1);
            scanf("%lf", &mat[i][j]);
        }
    }

}

//printing the matrix in a grid format
void print_matrix(matrix mat, int rows, int cols, char matrix_name){

    if((validate_matrix(rows, cols)) == 0){
        printf("INVALID MATRIX");
    }

    printf("\n\t Printing for matrix %c\n", matrix_name);

    for(int i = 0; i<rows; i++){
        printf("\t| ");
        for(int j = 0; j<cols; j++){
            printf(" %7.2lf ", mat[i][j]);
        }
        printf(" |\n");
    }

    printf("\n");


}

//now working on the core 5 functions of the matrix
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

    matrix A, B, C;  /*
                        matrix A & B will be the matrices that will be operated on
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
    scanf("%d", &choose_how_to_multiply);

    // AxB
    if(choose_how_to_multiply == 1){

        rowC = rowA;
        colC = colB;

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

        rowC = rowB;
        colC = colA;

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


    printf("\n\t The multiplication of the two matrices is given below \n");
    print_matrix(C, rowC, colC, 'C');



}

//all functions below are for solving matrix determinant

void matrix_determinant(){

    printf("\n\t This is matrix determinant\n");
    printf("\n\t put input for the matrix\n");
    printf("\n\t it must be a square matrix to find its determinant\n");

    matrix A;// this is the matrix whose determinant will be solved

    int row, col;

    printf("\n\t enter rows: ");
    scanf("%d", &row);
    printf("\n\t enter columns: ");
    scanf("%d", &col);


    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(row, col)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    input_matrix(A, row, col);


    //---------------------------------------------------------------------

    int size = row; //as row and col are same

    double det = calculate_determinant(A, size);

    printf("\n\t the determinant is : %.2lf \n", det);
}

/*
this is a helper matrix to store the matrix after removing the items in the row and column 
of previous matrix this will be used in the recursive function of determinant
this is basically a new matrix after removing the first row and j-th column
*/
void get_submatrix(matrix mat, matrix sub_mat, int skip_row, int skip_col, int size) {//the size argument is the size of matrix mat, not sub-matrix

    int sub_matrix_row , sub_matrix_col;//this is the rows and cols of the new smaller matrix

    sub_matrix_row = 0;
    for (int i = 0; i < size; i++) {
        if (i == skip_row){
                continue; // Skip the specified row
        }

        sub_matrix_col = 0;//it is set to 0 after each iteration so that the loop again starts from the beginning without skipping any column

        for (int j = 0; j < size; j++) {
            if (j == skip_col){
                    continue; // Skip the specified column
            }

            sub_mat[sub_matrix_row][sub_matrix_col] = mat[i][j];
            sub_matrix_col++;
        }
        sub_matrix_row++;
    }
}


/*
    this is a recursive function just to calculate the determinant
    this is why the function has a data-type so that it can return a value
*/
double calculate_determinant(matrix mat, int size) {

    //Base case for 1x1 matrix
    if (size == 1) {
        return mat[0][0];
    }

    // Base case for 2x2 matrix
    if (size == 2) {
        return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }

    double det = 0;
    matrix sub_mat; // Temporary workspace matrix for sub-calculations
    int sign = 1;   // To handle the alternating signs (+1, -1, +1...)


    // Loop through the first row (row 0)
    for (int j = 0; j < size; j++) {
        //  Generate the smaller sub-matrix by skipping row 0 and column j
        get_submatrix(mat, sub_mat, 0, j, size);

        int sign = (j % 2 == 0) ? 1 : -1; //ternary operator

        // Recursively solving determinant of the smaller sub-matrix
        // Multiplying it by the current element and the sign, adding it to the total
        det += sign * mat[0][j] * calculate_determinant(sub_mat, size - 1);


    }

    return det;
}

//all functions above are for solving matrix determinant

void matrix_inverse(){

    printf("\n\t This is matrix inversion\n");
    printf("\n\t put input for the matrix\n");
    printf("\n\t it must be a square matrix to find its inverse\n");

    matrix inverse_mat;// this is the matrix whose inverse will be solved

    int row, col;

    printf("\n\t enter rows: ");
    scanf("%d", &row);
    printf("\n\t enter columns: ");
    scanf("%d", &col);


    //at first going to check if the user has entered the right number of rows and cols
    if((validate_matrix(row, col)) == 0 ){
        printf("\n\t INVALID rows or cols\n");
    }

    else{


        //getting the matrix which is to be inverted
        input_matrix(inverse_mat, row, col);


        //---------------------------------------------------------------------

        int size = row; //as row and col are same

        double det = calculate_determinant(inverse_mat, size);

        //when determinant is 0, inverse cannot be calculated
        if(det == 0){
            printf("\n\t There is no inverse of this matrix \n");
        }

        else{

            //test-case for 1x1 matrix
            if(size == 1){
                inverse_mat[0][0] == inverse_mat[0][0]/det;
                printf("\n\t inverse is [%7.2lf] ", inverse_mat[0][0]);
            }


            matrix cofactor;

            //getiing the cofactor matrix by using the sub-matrix system
            for(int i = 0; i <size; i++){
                for(int j = 0; j<size; j++){
                    matrix sub_mat; // this is the matrix whose determinant will be added in the i-th row and j-th column of cofactor matrix
                    get_submatrix(inverse_mat, sub_mat, i, j, size);//this will store the matrix in the sub_mat matrix skipping i-th row and j-th column
                    double sub_matrix_det = calculate_determinant(sub_mat, size-1);
                    int sign = ((i + j) % 2 == 0) ? 1 : -1; //ternary operator
                    cofactor[i][j] = sign * sub_matrix_det;
                }
            }

            //getting the transpose and dividing it with determinan
            for(int i = 0; i<size; i++){
                for(int j = 0; j<size; j++){
                    inverse_mat[i][j] = cofactor[j][i]/det;
                }
            }

            print_matrix(inverse_mat, row, col, 'I');

        }

    }
}


/* |||||||||       vectors          ||||||||||| */

void vector_input(vector v){
    char dimension[3] = {'i', 'j', 'k'};

    for(int i = 0; i<max_vector_size; i++){
        printf("\t enter for [%c]: ", dimension[i]);
        scanf("%lf", &v[i]);
    }

}

void vector_print(vector v){
    char dimension[3] = {'i', 'j', 'k'};

    for(int i = 0; i<max_vector_size; i++){
        printf("%.2lf%c ", v[i], dimension[i]);
            //this is to print '+' between the numbers
        if(i>=0 && i<(max_vector_size-1)){
                printf("+ ");
        }
    }

}

//primary vector functions

void vector_addition(){

    printf("\n\t THIS IS VECTOR ADDITION \n");
    vector a,b, result;


    printf("\n\t Enter dimensions....\n");

    //taking input for vector a;
    printf("\t For vector A: \n");
    vector_input(a);

    //taking input for vector b;
    printf("\t For vector B: \n");
    vector_input(b);

    //adding vectors
    for(int i = 0; i< max_vector_size; i++){
        result[i] = a[i] + b[i];
    }

    printf("\n\t Addition of two vectors is: ");
    vector_print(result);

}

void vector_subtraction(){

    printf("\n\t THIS IS VECTOR SUBTRACTION \n");
    vector a,b, result;


    printf("\n\t Enter dimensions....\n");

    //taking input for vector a;
    printf("\t For vector A: \n");
    vector_input(a);

    //taking input for vector b;
    printf("\t For vector B: \n");
    vector_input(b);

    //subtracting vectors
    for(int i = 0; i< max_vector_size; i++){
        result[i] = a[i] - b[i];
    }

    printf("\n\t Subtraction of two vectors is: ");
    vector_print(result);


}

void vector_dot(){

    printf("\n\t THIS IS VECTOR DOT MULTIPLICATION \n");
    vector a,b, result;


    printf("\n\t Enter dimensions....\n");

    //taking input for vector a;
    printf("\t For vector A: \n");
    vector_input(a);

    //taking input for vector b;
    printf("\t For vector B: \n");
    vector_input(b);

    //dot multiplying vectors
    for(int i = 0; i< max_vector_size; i++){
        result[i] = a[i] * b[i];
    }

    printf("\n\t Dot multiplication of two vectors is: ");
    vector_print(result);


}

void vector_cross(){

    printf("\n\t THIS IS VECTOR DOT MULTIPLICATION \n");
    vector a,b, result;

    printf("\n\t Enter dimensions....\n");

    //taking input for vector a;
    printf("\t For vector A: \n");
    vector_input(a);

    //taking input for vector b;
    printf("\t For vector B: \n");
    vector_input(b);

    result[0] = (a[1]*b[2]) - (a[2]*b[1]);
    result[1] = (a[2]*b[0]) - (a[0]*b[2]);
    result[2] = (a[0]*b[1]) - (a[1]*b[0]);

    printf("\n\t Cross multiplication of A and B vector: ");
    vector_print(result);
}


//================================================
/*                    TAHMID                     */
//================================================

/*                main programs          */
void arithmetic_operations(){
    printf("\n\t>>>this arithmatic operations program\n");
    printf("\n\n");

    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operators......\n\n");
        printf("\t 1.  addition \n");
        printf("\t 2.  substraction \n");
        printf("\t 3.  multiplication \n");
        printf("\t 4.  division \n");
        printf("\t 5.  modulus \n");

        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        printf("\n");


        switch(choice){
            case 1:
                addition();
                break;

            case 2:
                subtraction();
                break;

            case 3:
                multiplication();
                break;

            case 4:
                division();
                break;

            case 5:
                modulus();
                break;

            default:
                printf("\n\tINVALID INPUT");
                break;
        }
    }


}

void logarithms(){

    printf("\n\t>>>this logarithms program\n");
    printf("\n\n");

    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operators......\n\n");
        printf("\t 1. Natural log (ln) \n");
        printf("\t 2. Common log \n");
        printf("\t 3. Log with any chosen base number \n");
        
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        printf("\n");


        switch(choice){
            case 1:
                natural_log();
                break;

            case 2:
                common_log();
                break;

            case 3:
                log_base_n();
                break;

            default:
                printf("\n\tINVALID INPUT");
                break;
        }
    }
}

void base_conversion(){
    printf("\n\t>>>this vector program\n");
    printf("\n\n");

    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operators......\n\n");
        printf("\t 1. Vector addition \n");
        printf("\t 2. Vector substraction \n");
        printf("\t 3. Vector dot multiplication \n");
        printf("\t 4. Vector cross multiplication \n");

        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        printf("\n");


        switch(choice){
            case 1:
                vector_addition();
                break;

            case 2:
                vector_subtraction();
                break;

            case 3:
                vector_dot();
                break;

            case 4:
                vector_cross();
                break;

            default:
                printf("\n\tINVALID INPUT");
                break;
        }
    }

}

/*      periferal functions               */

/*    ---- arithmatic operation ----*/

// This is the addition module

void addition()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf + %lf = %.2lf\n", number1, number2, number1 + number2);
}

// This is the subtraction module

void subtraction()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf - %lf = %.2lf\n", number1, number2, number1 - number2);
}

// This is the multiplication module

void multiplication()
{
    double number1, number2;

    printf("Enter the first number: ");
    scanf("%lf", &number1);

    printf("Enter the second number: ");
    scanf("%lf", &number2);

    printf("The result is: %lf * %lf = %.2lf\n", number1, number2, number1 * number2);
}

// This is the division module

void division()
{
    double number1, number2;

    printf("Enter the dividend: ");
    scanf("%lf", &number1);

    printf("Enter the divisor: ");
    scanf("%lf", &number2);

    if (number2 == 0)
    {
        printf("Invalid.Dividing by zero is undefined");
    }
    else
    {
        printf("The result is: %lf / %lf = %.2lf", number1, number2, number1 / number2);
    }
}

// This is the modulus module

void modulus()
{

    double number1, number2;

    printf("Enter the first integer: ");
    scanf("%lf", &number1);

    printf("Enter the second integer: ");
    scanf("%lf", &number2);

    if (number2 == 0)
    {
        printf("Invalid.Cannot divide by 0.");
    }
    else
    { // fmod is a function is [math.h] which does the same thing as a%b

        printf("\nThe result is:%lf %% %lf =%.2lf, number1, number2, fmod(number1, number2)");
    }
}



/* ---- logarithms  ------*/
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

/*  ----- base conversion -------*/

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


//=================================================
/*                     RUMI                      */
//================================================

/*        main programs         */

void trigonometry(){

    printf("\n\t>>>this is trigonometry program\n");

    double input_value, final_result;

    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operations......\n\n");
        printf("1. sin(x)\t2. arcsin(x)\n");
        printf("3. cos(x)\t4. arccos(x)\n");
        printf("5. tan(x)\t6. arctan(x)\n");
        printf("7. sec(x)\t8. arcsec(x)\n");
        printf("9. cosec(x)\t10. arccosec(x)\n");
        printf("11. cot(x)\t12. arccot(x)\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);
        
        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        //taking input to operate
        printf("Enter the value: ");
        scanf("%lf", &input_value);

        

        printf("\n");

        switch(choice){

            case 1:
            final_result = calculate_sin(input_value);
            printf("sin(%.2lf) = %.4lf\n", input_value, final_result);
            break;

            case 2:
                final_result = calculate_arcsin(input_value);
                printf("arcsin(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            case 3:
                final_result = calculate_cos(input_value);
                printf("cos(%.2lf) = %.4lf\n", input_value, final_result);
                break;

            case 4:
                final_result = calculate_arccos(input_value);
                printf("arccos(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            case 5:
                final_result = calculate_tan(input_value);
                printf("tan(%.2lf) = %.4lf\n", input_value, final_result);
                break;

            case 6:
                final_result = calculate_arctan(input_value);
                printf("arctan(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            case 7:
                final_result = calculate_sec(input_value);
                printf("sec(%.2lf) = %.4lf\n", input_value, final_result);
                break;

            case 8:
                final_result = calculate_arcsec(input_value);
                printf("arcsec(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            case 9:
                final_result = calculate_cosec(input_value);
                printf("cosec(%.2lf) = %.4lf\n", input_value, final_result);
                break;

            case 10:
                final_result = calculate_arccosec(input_value);
                printf("arccosec(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            case 11:
                final_result = calculate_cot(input_value);
                printf("cot(%.2lf) = %.4lf\n", input_value, final_result);
                break;

            case 12:    
                final_result = calculate_arccot(input_value);
                printf("arccot(%.2lf) = %.4lf degrees\n", input_value, final_result);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    printf("\n\n");

}

void unit_conversion(){

    printf("\n\t>>>this is unit_conversion program\n");


    double input_value, final_result;

    
    while(rerun_program){

        //asking for operations

        printf("\n\t press 0 to exit\n");
        printf("\n\t available operations......\n\n");
        printf("--- Distance Conversions ---\n\n");
        printf("1. Km to Mile            2. Mile to Km\n");
        printf("3. Meter to Feet         4. Feet to Meter\n");
        printf("5. Cm to Inch            6. Inch to Cm\n");
        printf("7. Meter to Yard         8. Yard to Meter\n");
        printf("9. Km to Nautical Mile   10. Nautical Mile to Km\n");
        printf("\n--- Weight Conversions ---\n\n");
        printf("11. Kg to Pound          12. Pound to Kg\n");
        printf("13. Gram to Ounce        14. Ounce to Gram\n");
        printf("\n--- Volume Conversions ---\n\n");
        printf("15. Liter to Gallon      16. Gallon to Liter\n");
        printf("\n--- Temperature Conversions ---\n\n");
        printf("17. Celsius to Fahrenheit 18. Fahrenheit to Celsius\n");
        printf("19. Celsius to Kelvin    20. Kelvin to Celsius\n");
        printf("21. Fahrenheit to Kelvin 22. Kelvin to Fahrenheit\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);
        
        if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }


        //taking input to operate
        printf("Enter the value: ");
        scanf("%lf", &input_value);

        

        printf("\n");


        switch (choice) {
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

    }

    printf("\n\n");

}



/*        periferal functions      */

/*  |||||||||   trigonometry   ||||||||| */
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

/*  |||||||||   unit_conversion   ||||||||| */


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


//=================================================
/*                     ARIF                      */
//=================================================

/*         main programs     */

void factorials(){

    printf("\n\t>>>this is factorials program\n");

    while(rerun_program){

        printf("\n\t press 0 to exit and 1 to continue\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 1){
            int n;
            printf("Enter n: ");          // Prompt the user to enter a value for n.
            scanf("%d", &n);             // Read the value of n from the user.
            double f = factorial(n); // Call the factorial function and store the result in f.
            if (f == -1) printf("Error: n must be >= 0\n");     // If the result is -1, print an error message indicating that n must be non-negative.
            else printf("%d! = %lf\n", n, f);                 // Otherwise, print the calculated factorial value.  

        }

        else if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }

        
    }
}

void permutations(){

    printf("\n\t>>>this is permutations program\n");

    while(rerun_program){

        printf("\n\t press 0 to exit and 1 to continue\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        int n, r;

        if(choice == 1){
            printf("Enter n and r: ");          // Prompt the user to enter values for n and r.
            scanf("%d %d", &n, &r);            // Read the values of n and r from the user.
            long long p = permutation(n, r);  // Call the permutation function and store the result in p.
            if (p == -1) printf("Error: invalid n or r\n");    // If the result is -1, print an error message indicating that n or r is invalid (e.g., r > n or negative values).  
            else printf("P(%d, %d) = %lld\n", n, r, p);       // Otherwise, print the calculated permutation value.
            
        }

        else if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }

        
    }

}

void combinations(){

    printf("\n\t>>>this is combinations program\n");

    while(rerun_program){

        printf("\n\t press 0 to exit and 1 to continue\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        int n, r;

        if(choice == 1){
            printf("Enter n and r: ");               // Prompt the user to enter values for n and r.
            scanf("%d %d", &n, &r);                 // Read the values of n and r from the user.
            long long c = combination(n, r);       // ---Call the combination function and store the result in c.
            if (c == -1) printf("Error: invalid n or r\n"); // If the result is -1, print an error message indicating that n or r is invalid (e.g., r > n or negative values).
            else printf("C(%d, %d) = %lld\n", n, r, c);    // Otherwise, print the calculated combination value.       
        }

        else if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }

        
    }

}

void polynomial_roots_solving(){

    printf("\n\t>>>this is polynomial roots solving program\n");

    while(rerun_program){

        printf("\n\t press 0 to exit and 1 to continue\n");
        printf("\n\t choose your operation: ");

        scanf("%d", &choice);

        if(choice == 1){
            int a, b, c;
            printf("Enter coefficients a, b, c for ax^2 + bx + c = 0:\n");// Prompt the user to enter coefficients for the quadratic equation.
            printf("Enter a: ");// Prompt the user to enter the coefficient a.
            scanf("%d", &a);   // Read the value of a from the user.
            printf("Enter b: ");// Prompt the user to enter the coefficient b.
            scanf("%d", &b);   // Read the value of b from the user.
            printf("Enter c: ");// Prompt the user to enter the coefficient c.
            scanf("%d", &c);   // Read the value of c from the user.
            polynomiyal_roots(a, b, c); // Call the function to calculate and display the roots of the quadratic equation.        

        }

        else if(choice == 0){
            printf("\n\t exiting to main menu\n\n");
            break;
        }

        
    }

    
}


/*        periferal functions      */

/* |||||||||       factorial         ||||||||||| */
double factorial(int n) // ----------------Function to calculate factorial. We use long long to handle larger results.
 {
    if (n < 0) return -1;  // ---------------- it returns -1 for negative numbers as factorial is not defined for them.
    if (n == 0 || n == 1) return 1;// --------Factorial of 0 and 1 is 1.
    double result = 1;// ------------------Initialize result to 1.
    for (int i = 2; i <= n; i++)// -----------the loop starts from 2 to n, multiplying each integer to the result.
        result *= i;// -----------------------Multiply result by i for each iteration.
    return result;// -------------------------Return the final factorial value.
}

/* |||||||||       permutation      ||||||||||| */
long long permutation(int n, int r) {       //---Function to calculate permutation. We use long long to handle larger results.
    if (r > n || n < 0 || r < 0) return -1; //---It will return -1: Permutation is not defined for r > n or negative values.
    return factorial(n) / factorial(n - r); //---Calculate permutation using the formula P(n, r) = n! / (n-r)!
}

/* |||||||||       combination      ||||||||||| */
long long combination(int n, int r) { // ---------Function to calculate combination. We use long long to handle larger results.
    if (r > n || n < 0 || r < 0) return -1; // ---It will return -1: Combination is not defined for r > n or negative values.
    return factorial(n) / (factorial(r) * factorial(n - r)); // Calculate combination using the formula C(n, r) = n! / (r! * (n-r)!)
}

/* |||||||||       polynomial roots  ||||||||||*/
void polynomiyal_roots(int a, int b, int c) { // Function to calculate and display the roots of a quadratic equation ax^2 + bx + c = 0.
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


/*     ---------------END OF FILE-----------------------    */




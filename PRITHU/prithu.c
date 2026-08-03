#include <stdio.h>
#include <math.h>
#include <stdlib.h>



#define max_matrix_size 10 //setting the maximum size that a matrix can have
#define max_vector_size 3 //setting maximum dimensions a vector can have


//creating a new matrix datatype
typedef double matrix[max_matrix_size][max_matrix_size];
//creating a new vector datatype
typedef double vector[max_vector_size];


//function prototypes
//===================
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
void matrix_determinant();
double calculate_determinant(matrix mat, int size);
void get_submatrix(matrix mat, matrix sub_mat, int skip_row, int skip_col, int size);
void matrix_inverse();
void matrices();
//all functions of vector
void vectors();
void vector_input(vector v);
void vector_print(vector v);
void vector_addition();
void vector_subtraction();
void vector_dot();
void vector_cross();


int main(){
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
                    vectors();
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

int choice;/*this is a global variable
            it stores the choice of user of what operation the user wants to use and this variable is used in switch-case of matrices()
            it is also used in the  general_input_for_every_function() function
            */
//the function which originally controls the matrix function
void matrices(){
    printf("\n\t>>>this is matrix program\n");
    printf("\t matrix size is maximum 10 rows and 10 columns\n\n");

    int rerun = 1; /*this is variable to control whether the program will rerun or not
                       A if-statement has been used in the while-loop to update this variable and break out of this loop
                       this helps the user to stay at the current program without restarting the calculator after a task is finished
                      */


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

void general_input_for_every_function(matrix A, matrix B, matrix C){

     switch(choice){
        case 1:
            printf("\n\t This is matrix addition \n");
            printf("\t  Addition between two matrices \n");
            break;

        case 2:
            printf("\n\t This is matrix subtraction \n");
            printf("\t  subtraction between two matrices \n");
            break;

        case 3:
            printf("\n\t This is matrix multiplication \n");
            printf("\t  multiplication between two matrices \n");
            break;

        case 4:
            printf("\n\t This is matrix determinant \n");
            break;

        case 5:
            printf("\n\t This is matrix addition \n");
            break;

        default:
            printf("\n\tINVALID INPUT");
            break;

            }

}

//now working on the core 5 functions of the matrix

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

//===============================================================================================
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
this is a helper matrix to store the matrix after removing the items in the row and column of previous matrix
this will be used in the recursive function of determinant
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

//all functions above are for solving matrix determinan
//===============================================================================================


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

    //getting the matrix which is to be inverted
    input_matrix(inverse_mat, row, col);


    //---------------------------------------------------------------------

    int size = row; //as row and col are same

    double det = calculate_determinant(inverse_mat, size);

    //when determinant is 0, inverse cannot be calculated
    if(det == 0){
        printf("\n\t There is no inverse of this matrix \n");
    }

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


//all funtions for vector
//===========================================================

void vectors(){
    printf("\n\t>>>this vector program\n");
    printf("\n\n");

    int rerun = 1; /*this is variable to control whether the program will rerun or not
                       A if-statement has been used in the while-loop to update this variable and break out of this loop
                       this helps the user to stay at the current program without restarting the calculator after a task is finished
                      */

    while(rerun){
        if(rerun == 1){

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

        else{
            break;
        }
    }



}

//periferal functions///////////
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

//primary functions////////////

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








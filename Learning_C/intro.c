#include <stdio.h>
// Data types
/*
int             (4 bytes)  ~  %d for printing
double          (8 bytes)  ~  %lf for printing
float           (4 bytes)  ~  %f for printing
char            (14 bytes)  ~  %c for printing
*/

int main()
{

    // Variable integer
    int num = 25;
    printf("\nInteger value: %d", num);
    //___________________________________________________________________________________________

    // Assigning two variables on same line
    int variable1 = 1, variable2 = 2;
    printf("\nvariable1: %d", variable1);
    printf("\nvariable2: %d", variable2);
    //___________________________________________________________________________________________

    // Variable double (store larger decimal numbers) vs float (smaller decimal numbers)

    double doublenum = 3.1;
    float floatnum = 4.1f;
    printf("\ndouble value: %.4lf", doublenum); // decmial + number infront changes decimal places (default 6)
    printf("\nfloat value: %.8f", floatnum);

    double doublenum2 = 5.0e2; // exponential numbers by base 10
    float floatnum2 = 3.5e4;
    printf("\ndouble exponent value: %lf", doublenum2);
    printf("\nfloat exponent value: %f", floatnum2);
    //___________________________________________________________________________________________

    // Variable character
    char character = 'M'; // use single quotes
    printf("\nCharacter value: %c", character);
    printf("\n Character %c stored as: %d", character); // characters stored as integers
    //___________________________________________________________________________________________

    // User Input
    // Scan function to take input from the user to store in a variable

    int age; // creating a variable to store input

    printf("\n\nHow old are you?: ");
    scanf("%d", &age); // two parameters: (type of input data, &variable name to be stored)
    printf("You are %d years old", age);
    //___________________________________________________________________________________________

    // Double input

    double userdouble;
    char userchar;

    printf("\n\nEnter double input: ");
    scanf("\n%lf", &userdouble);

    printf("Enter character input: ");
    scanf("\n%c", &userchar);

    printf("userdouble: %lf", userdouble);
    printf("\nuserchar: %c", userchar);
    //___________________________________________________________________________________________

    // Multiple input

    double userdouble2;
    char userchar2;

    printf("\n\nEnter input values(double character): ");
    scanf("\n%lf %c", &userdouble2, &userchar2); // user expected to type both inputs on same line

    printf("userdouble2: %lf", userdouble2);
    printf("\nuserchar2: %c", userchar2);

    //___________________________________________________________________________________________

    // Example1: Integer and Float input from the user

    int intex1;
    float floatex1;

    printf("\n\nEnter input values(int float): ");
    scanf("\n%d %f", &intex1, &floatex1);

    printf("Integer example 1: %d", intex1);
    printf("\nFloat example 1: %f", floatex1);

    return 0;
}
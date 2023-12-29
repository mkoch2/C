#include <stdio.h>

int main()
{

    // Arithmetic Operators

    //        +       Addition
    //        -       Subtraction
    //        *       Multiplication
    //        /       Division
    //        %       Remainder
    //        ++      Increment (increments by 1)
    //        --      Decrement (decrements by 1)

    int x = 5;
    int y = 8;

    printf("\nIncrement by 1: %d", ++x);
    printf("\nDecrement by 1: %d", --y);
    //___________________________________________________________________________________________

    // Converting data types

    // Data types Hierarchy
    //          Long Double
    //          Double
    //          Float
    //          Long
    //          Int
    //          Short
    //          Char

    double a = 5.67;
    int b = 9;
    char c = '7';
    float result1 = a + b; // output depends on the result data type

    printf("\n\nResult: %f", result1);
    //___________________________________________________________________________________________

    // Boolean Operators

#include <stdbool.h> //MUST INCLUDE IN ORDER TO USE BOOLEAN OPERATORS

    bool value1 = true; // Boolean values represented by integers (False: 0, True: 1)
    bool value2 = false;

    printf("\n\nTrue value: %d", value1);
    printf("\nFalse value: %d", value2);

    // Comparison Operators - Used to create boolean expressions that return boolean values

    /*
            Greater than            >
            Less than               <
            Equal to                ==
            Greater or equal to     >=
            Less or equal to        <=
            Not equal               !=
    */

    // Logical Operators

    /*
            AND                     &&
            OR                      ||
            NOT                     !
    */

    int num1 = 18;
    double num2 = 6.3;

    // AND
    bool result2 = (num1 >= 18) && (num2 > 6.0);
    printf("\n\nAND Value: %d", result2);

    // OR
    bool result3 = (num1 > 18) || (num2 < 6.0);
    printf("\n\nOR Value: %d", result3);

    // NOT
    bool result4 = !(num1 == 18); // Reverses the value
    printf("\n\nNOT Value: %d", result4);

    return 0;
}
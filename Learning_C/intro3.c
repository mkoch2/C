#include <stdio.h>

int main()
{
    // If Else Statements
    int age;
    printf("\nEnter your age: ");
    scanf("%d", &age); // scanf("%d", &num) --> instructing the compiler to store the input value
                       // at the memory address using the '&' symbol

    if (age < 0 || age > 120)
    {
        printf("Age is invalid");
    }
    else if (age >= 18)
    {
        printf("You are eligible to vote");
    }
    else
    {
        printf("Sorry you are not eligible to vote");
    }

    // Example 1: Check positive, negative or zero

    double numex1;
    printf("\n\nEnter a number (ex1): ");
    scanf("%lf", &numex1);

    if (numex1 > 0)
    {
        printf("The number is positive");
    }
    else if (numex1 < 0)
    {
        printf("The number is negative");
    }
    else
    {
        printf("The number is zero");
    }
    //___________________________________________________________________________________________

    // Ternary Operators - used to replace If Else statements in certain situations for cleaner code

    // Syntax               True          False
    // test_condition ? expression1 : expression2;

    // ex
    int num = 25;
    (num >= 18) ? printf("\n\nTernary, You can vote") : printf("\n\nTernary, You cannot vote");

    // Can be used to store value to variables to be used later

    char operator= '+';
    int num1 = 2;
    int num2 = 5;

    int result = (operator== '-') ? (num1 + num2) : (num2 - num1);
    printf("\n\nTernary Variable: %d", result);
    //___________________________________________________________________________________________

    // Switch Statements - used when we have to choose from multiple options (ex: menu)
    /* Syntax

    switch(variable/expression){        variable or expression is matched with one of the cases
        case value1:
            // body of case 1
            break;

        case value2:
            // body of case 2
            break;

        case valueN:
            // body of case N
            break;

        default:
            // body of default
    }
    */

    // ex

    int day;
    printf("\n\nFind out day of week (1 to 7): ");
    scanf("%d", &day);

    switch (day)
    {
    case 1:
        printf("Sunday");
        break; // exits the switch statement, otherwise the expression will match the other cases

    case 2:
        printf("Monday");
        break;

    case 3:
        printf("Tuesday");
        break;

    case 4:
        printf("Wednesday");
        break;

    case 5:
        printf("Thursday");
        break;

    case 6:
        printf("Friday");
        break;

    case 7:
        printf("Saturday");
        break;

    default:
        printf("Invalid Number");
        break;
    }
    //___________________________________________________________________________________________

    // Switch Statements with multiple cases

    int day2;
    printf("\n\nFind out week day/end (1 to 7): ");
    scanf("%d", &day2);

    switch (day2)
    {
    case 1:
    case 7:
        printf("Weekend");
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        printf("Weekday");
        break;

    default:
        printf("Invalid Number");
        break;
    }
    //___________________________________________________________________________________________

    // Switch Statement - Calculator

    double num3, num4;
    char calculator;
    double result2;

    printf("\nChoose Operator (+ - * /): ");
    scanf("%c", &calculator);

    printf("\n\nEnter first number: ");
    scanf("%lf", &num3);

    printf("\nEnter second number: ");
    scanf("%lf", &num4);

    switch (calculator)
    {
    case '+':
        result2 = num3 + num4;
        break;

    case '-':
        result2 = num3 - num4;
        break;

    case '*':
        result2 = num3 * num4;
        break;

    case '/':
        result2 = num3 / num4;
        break;
    }
    // printf("Calculator result: %lf", result2);

    return 0;
}

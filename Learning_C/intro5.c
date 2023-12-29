#include <stdio.h>

// Function - a group of related statements that perform a specific task
// parameter - value accepted by the function
/* Syntax

returnType functionName(parameter)
{
    ...
    ...
}
*/
void simpleFunction() // Void if none is returned
{
    printf("Simple Function");
}

void calculateSquare(int num)
{
    int square = num * num;
    printf("\n\nThe square of %d is: %d", num, square);
}
//___________________________________________________________________________________________

// Function Prototype - declaration of a function (info i.e. name, parameters, return types) excluding the body
//      --> provides info to the compiler, used when functions are called before they are defined

int addNumbers(int num1, int num2);
int sum(int n);
//___________________________________________________________________________________________

int main()
{

    simpleFunction();
    calculateSquare(8);
    int result = addNumbers(7, 8);
    printf("\n\nThe sum of addNumbers function is: %d", result);

    int number, result2;
    printf("\n\nEnter positive integer: ");
    scanf("%d", &number);
    result2 = sum(number);
    printf("Sum = %d", result2);

    int number2, result3;
    printf("\n\nEnter positive integer(factorial): ");
    scanf("%d", &number2);
    result3 = recurse(number2);
    printf("Factorial = %d", result3);

    return 0;
}

int addNumbers(int num1, int num2)
{
    int sum = num1 + num2;
    // printf("\n\nThe sum of %d and %d is: %d", num1, num2, sum);
    return sum;
}
//___________________________________________________________________________________________

// Recursion - a function type that calls itself
/* Syntax,              --> if else condition to prevent infinite recursive call

void recurse() {
    ...
    if (condition) {
        ....
    }
    else {
        recurse()
    }
    ...
}
*/
int sum(int n)
{
    if (n != 0)
    {
        // sum() function calls itself
        return n + sum(n - 1);
    }
    else
    {
        return n;
    }
}
//___________________________________________________________________________________________

// Recursion Practice
int recurse(int n2)
{
    if (n2 > 1)
    {
        return n2 * recurse(n2 - 1);
    }
}
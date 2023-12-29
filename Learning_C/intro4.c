#include <stdio.h>

int main()
{
    // While Loop
    /* Syntax

    while (condition) {
        // statements inside while loop
    }
    */
    int count = 0;
    while (count < 5)
    {
        printf("while loop in C\n");
        count += 1;
    }
    //___________________________________________________________________________________________

    // Create Multiplication table

    int number;
    printf("\nEnter a number: ");
    scanf("%d", &number);
    int count2 = 1;

    while (count2 <= 12)
    {
        printf("%d*%d = %d\n", count2, number, count2 * number);
        count2 += 1;
    }
    //___________________________________________________________________________________________

    // Do While Loop - body of loop is executed once no matter what... only then the test expression is evaluated
    /* Syntax

    do {
        // body of loop
    } while condition;
     */
    int count3 = 1;

    do
    {
        printf("\n%d", count3);
        count3 += 1;
    } while (count3 < 5);
    //___________________________________________________________________________________________

    // For Loop
    /*Syntax

    Initialization Expression - declares an initialized variable, executed only once
    Test Expression - boolean expression that evaluates to True or False
    Update Expression - changes the value of a variable if Test is true

    for (initializationExpression; testExpression; updateExpression) {
        // statements inside for loop
    }
    */
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {

        printf("%d ", i);
    }
    //___________________________________________________________________________________________

    // Sum of numbers from 1 - 100

    int sum = 0;
    for (int num = 1; num <= 100; num++)
    {
        sum += num;
    }
    printf("\n\nThe sum of 1-100 is: %d", sum);

    //___________________________________________________________________________________________

    // Sum of Even Numbers

    int sum2 = 0;
    for (int num2 = 2; num2 <= 100; num2 += 2)
    {
        sum2 += num2;
    }
    printf("\n\nThe sum of 1-100 is: %d", sum2);
    //___________________________________________________________________________________________

    // Break statement - immediately terminates the loop when encountered

    // Continue statement - skips the current iteration of the loop and starts the loop with the next iteration
    return 0;
}
#include <stdio.h>
#include <string.h> // For string functions

int main()
{
    // Arrays - a collection of similar type of data
    /* Syntax
    arraySize - number of elements stored inside the array, connot change size or name once declared
            --> if arraySize is not declared, c compiler automatically determines size of array by counting elements
            --> allowed to assign less than what was declared in brackets

    dataType arrayName[arraySize];
    */
    int numList[5] = {21, 29, 25, 19, 17};
    printf("First element: %d\n\n", numList[0]);

    numList[5] = 2;  // adding elements
    numList[2] = 40; // changing elements

    int numList2[5];

    for (int i2 = 0; i2 < 5; i2++)
    {
        printf("Insert number to list: ");
        scanf("%d", &numList2[i2]);
    }
    printf("UserList: ");
    for (int i2 = 0; i2 < 5; i2++)
    {
        printf("%d ", numList2[i2]);
    }
    //___________________________________________________________________________________________

    // Ex: Create a program, that computes the average marks of a student
    printf("\n\n");
    int studentMarks[5];
    int totalGrade = 0;
    int averageGrade;

    for (int marki = 0; marki < 5; marki++) // marki --> mark index
    {
        printf("Enter a grade: ");
        scanf("%d", &studentMarks[marki]);
    }
    for (int marki = 0; marki < 5; marki++)
    {
        totalGrade = totalGrade + studentMarks[marki];
    }
    averageGrade = totalGrade / 5;
    printf("Your Average Grade is: %d", averageGrade);
    //___________________________________________________________________________________________

    // Multidimensional Arrays - Stores multiple elements however each element is an array

    /* Syntax

    // first bracket: how many arrays inside multidimensional array (row)
    // second bracket: each array will have x amount of elements (column)
    int arr[2][3]   --> 2 arrays each with 3 elements { {x,x,x} , {y,y,y} }
    */

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("\n\nFirst list, first index: %d", arr[0][0]);    //| [0][0] | [0][1] | [0][2] |
    printf("\nSecond list, third index: %d\n\n", arr[1][2]); //| [1][0] | [1][1] | [1][2] |

    // accessing elements with loop

    for (int row = 0; row < 2; row++)
    {
        for (int column = 0; column < 3; column++)
        {
            printf("%d  ", arr[row][column]);
        }
        printf("\n"); // new line once the entire row is displayed...loop back to first loop to access new row
    }
    //___________________________________________________________________________________________

    // Strings - collection of characters used to represent textual data        **every string is terminated by a
    // similar to arrays                                      non-character represented by \0

    char str[] = "Programiz"; // --> char str[] = {'P','r','o','g','r','a','m','i','z'};
    printf("\n%s", str);

    printf("\nFirst character of string: %c", str[0]);

    char str2[20];
    printf("\n\nEnter Name2: ");
    scanf("%s", str2); // omit '&' since str is an array and already points to the address of the first element of str
    //  --> scanf method only takes the input unitl it encounters a white space
    //  --> if you want to take more... fgets() function

    // fgets(str2, sizeof(str2), stdin); // instead of scanf
    printf("Your name is: %s", str2);
    //___________________________________________________________________________________________

    // String Functions

    char language[] = "C Programming";
    printf("\n\n%s", language);

    // strlen() - Length of string
    printf("\nLength of String: %zu", strlen(language)); // %zu - format specifier to print value of strlen()
                                                         // --> includes space in counter

    // strcpy() - used to copy one string to another
    char food[] = "Pizza";
    char bestFood[strlen(food)];
    strcpy(bestFood, food); // --> takes two values (Destination string, copied string)
    printf("\n\nString Copy: %s", bestFood);

    // strcat() - used to join two strings together
    char text1[] = "Hello";
    char text2[] = "Matthew";
    strcat(text1, text2);
    printf("\n\nString Concatenate: %s", text1);

    // strcmp() - used to compare two strings --> returns 0 if both the strings are equal
    // if not equal, returns a random non-zero value
    char text3[] = "abcd";
    char text4[] = "efgh";
    char text5[] = "abcd";
    int result1 = strcmp(text3, text4);
    int result2 = strcmp(text3, text5);
    printf("\n\nString comparison (not equal): %d", result1);
    printf("\nString comparison (equal): %d", result2);

    return 0;
}
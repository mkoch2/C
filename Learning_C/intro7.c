#include <stdio.h>

void findValue(int *num);
int *findSquare(int *num);
int *addNumbers(int *num1, int *num2, int *sum);

int main()
{
    // Pointers - allow us to work directly with the computer memory

    // Address - whenever a variable is declared, a space will be located in the memory for the variable,
    // and c allows us to access the ADDRESS of the variable
    // Amperand symbol to access the memory adress of the variable (&num)

    int num = 25;
    printf("%p", &num); // %p - format specifier to print the address

    // Pointer - are variables however, they store the MEMORY ADDRESS of the variable (not the value)
    int *pointer = &num; // '*' for pointers

    // access the address of the variable
    printf("\nAddress: %p", pointer);

    // access the value of a variable using the pointer
    printf("\nValue: %d", *pointer);

    // change value using Pointer
    *pointer = 31; // assigns a new value to the memory adddress pointed by the pointer variable
    printf("\n\nNew value changed by pointer: %d", num);

    /* Common Errors;

    int* ptr;

    ptr = number;           Invalid

    *ptr = &number;         Invalid

    ptr = &number;          Valid

    *ptr = number;          Valid
    */
    //___________________________________________________________________________________________

    // Ex 1: Create a program to change the value of a variable using a pointer

    double salary;
    printf("\n\nEnter your salary: ");
    scanf("%lf", &salary);

    double *ptr1 = &salary;            // Pointer equal to the memory address of num
    printf("Your salary: %lf", *ptr1); // Prints  actual value
    double double_salary = *ptr1 * 2;
    printf("\nDoubled Salary: %lf\n", double_salary);
    //___________________________________________________________________________________________

    // Pointer and Arrays
    int numbers[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        printf("\nValue: %d --> Address: %p", numbers[i], &numbers[i]);
        printf("\nValue: %d --> Address: %p", *(numbers + i), numbers + i); // Same thing
    }
    printf("\nArray address: %p", numbers); // Address of first element and the array are the same
                                            //          **array address always points to the first element

    // Change array elements using pointers
    *numbers = 2;        // changing first element value since address in array points to the first element
    *(numbers + 4) = 11; // changing last element value... count the increments 01234

    printf("\n\nNew First element: %d", *numbers);
    printf("\nNew Last element: %d", *(numbers + 4));
    //___________________________________________________________________________________________

    // Ex 2: Create a program to find the largest element of an array using pointers

    int arr[] = {34, 12, 21, 54, 48};

    int largest_num = *arr;

    for (int i = 1; i < 5; i++) // starts at secodn element since first element is decalred as "Largest"
    {

        if (largest_num < *(arr + i)) // *(arr + i) = arr[i], using pointers
        {
            largest_num = *(arr + i);
        }
    }
    printf("\n\nThe largest number is: %d", largest_num);
    //___________________________________________________________________________________________

    // Pointers and Functions
    //      --> able to pass a pointer variable as an argument

    int number = 21;
    findValue(&number); // argument is the address of 'number'
    printf("\n\nNumber: %d", number);
    //___________________________________________________________________________________________

    // Find the sqaure of a number returning pointer
    int number1 = 21;
    int *result = findSquare(&number1);
    printf("\n\nSquared Number: %d", *result);
    //___________________________________________________________________________________________

    // Add Numbers
    int number2 = 32;
    int number3 = 18;
    int sum;

    int *result1 = addNumbers(&number2, &number3, &sum);
    printf("\n\nSum is: %d", *result1);
    return 0;
}

void findValue(int *num) // pointer variable inside the function is assigned with the address of the number
{
    *num = 39; // Change the value of the pointer varaible
}

int *findSquare(int *num)
{
    int square = *num * *num;
    *num = square; // value = squared num
    return num;
}

int *addNumbers(int *num1, int *num2, int *sum)
{
    *sum = *num1 + *num2;
    return sum;
}
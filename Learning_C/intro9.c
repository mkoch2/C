#include <stdio.h>

int main()
{

    // Opening a file
    FILE *fptr;
    fptr = fopen("file.txt", "r"); // Open

    char content[1000]; // Create an array to store the contents of the file

    if (fptr != NULL)
    {
        while (fgets(content, 1000, fptr))
        {
            // fgets() - Reads the content of the file... only reads one line, while loop to read all
            //      --> fgets(file read, size of file thats read, pointer used to read the file)
            printf("%s", content);
        }
    }
    else
    {
        printf("Unsuccessful");
    }

    fptr = fopen("newFile.txt", "w");    // Creating a new file
    fputs("I Love C Programming", fptr); // Adding to file

    // Close the file
    fclose(fptr);
    return 0;
}
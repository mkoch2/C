// ********* main.c ********

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "facebook_nodes.h"
#include "facebook_functions.h"

int main()
{
    /******** DONT MODIFY THIS PART OF THE CODE ********/
    /* THIS CODE WILL LOAD THE DATABASE OF USERS FROM THE FILE
       AND GENERATE THE STARTING LINKED LIST.
    */
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);
    /******** DONT MODIFY THIS PART OF THE CODE ********/

    /* IMPORTANT: You must use the users linked list created in the code above.
                  Any new users should be added to that linked list.
    */

    // Your solution goes here
    print_menu();
    char manage_username[30];
    int menu_choice;
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    while (menu_choice < 1 || menu_choice > 6)
    {
        printf("Invalid choice. Please try again.\n\n");
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);
    }
    while (menu_choice != 6)
    {
        switch (menu_choice)
        {
        case 1:
            char username[30];
            char password[15];

            printf("\nEnter a username: ");
            scanf("%s", username);
            printf("Enter an up to 15 characters password: ");
            scanf("%s", password);

            users = add_user(users, username, password);
            printf("\n**** User Added! ****\n\n");
            print_menu();
            printf("Enter your choice: ");
            scanf("%d", &menu_choice);
            while (menu_choice < 1 || menu_choice > 6)
            {
                printf("Invalid choice. Please try again.\n\n");
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
            }
            break;
        case 2:
            char new_username[30];
            printf("\nEnter username to update their password: ");
            scanf("%s", new_username);

            user_t *found_user_2 = find_user(users, new_username);
            if (found_user_2 == NULL)
            {
                print_user_not_found();
            }
            else
            {
                char new_password[15];
                printf("\nEnter a new password that is up to 15 characters: ");
                scanf("%s", new_password);
                strcpy(found_user_2->password, new_password);
                printf("\n**** Password Changed! ****\n\n");
            }
            print_menu();
            printf("Enter your choice: ");
            scanf("%d", &menu_choice);
            while (menu_choice < 1 || menu_choice > 6)
            {
                printf("Invalid choice. Please try again\n\n");
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
            }
            break;
        case 3:
            printf("\nEnter username to manage their posts: ");
            scanf("%s", manage_username);
            user_t *found_user_3 = find_user(users, manage_username);
            if (found_user_3 == NULL)
            {
                print_user_not_found();
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
                while (menu_choice < 1 || menu_choice > 6)
                {
                    printf("Invalid choice. Please try again.\n\n");
                    print_menu();
                    printf("Enter your choice: ");
                    scanf("%d", &menu_choice);
                }
                break;
            }
            else
            {
                display_user_posts(found_user_3);
                manage_post_menu();

                int manage_posts_choice;
                printf("Your choice: ");
                scanf("%d", &manage_posts_choice);
                while (manage_posts_choice < 1 || manage_posts_choice > 3)
                {
                    printf("Invalid choice. Please try again: ");
                    scanf("%d", &manage_posts_choice);
                }

                while (manage_posts_choice != 3)
                {
                    switch (manage_posts_choice)
                    {
                    case 1:
                        char post_content[250];
                        printf("Enter your post content: ");
                        scanf(" %[^\n]s", post_content);
                        add_post(found_user_3, post_content);
                        printf("Post added to your profile.\n");
                        display_user_posts(found_user_3);
                        manage_post_menu();
                        printf("Your choice: ");
                        scanf("%d", &manage_posts_choice);
                        while (manage_posts_choice < 1 || manage_posts_choice > 3)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_posts_choice);
                        }

                        break;
                    case 2:
                        int deleted_post_choice;
                        printf("Which post you want to delete: ");
                        scanf("%d", &deleted_post_choice);

                        _Bool successful_delete_post = delete_post(found_user_3, deleted_post_choice);
                        if (successful_delete_post == 0)
                        {
                            printf("Invalid post's number");
                        }
                        else
                        {
                            printf("Post %d was deleted successfully!", deleted_post_choice);
                        }
                        display_user_posts(found_user_3);
                        manage_post_menu();
                        printf("Your choice: ");
                        scanf("%d", &manage_posts_choice);
                        while (manage_posts_choice < 1 || manage_posts_choice > 3)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_posts_choice);
                        }
                        break;
                    }
                }
            }
            print_menu();
            printf("Enter your choice: ");
            scanf("%d", &menu_choice);
            while (menu_choice < 1 || menu_choice > 6)
            {
                printf("Invalid choice. Please try again.\n\n");
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
            }
            break;

        case 4:
            printf("\nEnter username to manage their friends: ");
            scanf("%s", manage_username);
            user_t *found_user_4 = find_user(users, manage_username);
            if (found_user_4 == NULL)
            {
                print_user_not_found();
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
                while (menu_choice < 1 || menu_choice > 6)
                {
                    printf("Invalid choice. Please try again.\n\n");
                    print_menu();
                    printf("Enter your choice: ");
                    scanf("%d", &menu_choice);
                }
                break;
            }
            else
            {
                manage_friends_menu(found_user_4);
                int manage_friends_choice;
                printf("Your choice: ");
                scanf("%d", &manage_friends_choice);
                while (manage_friends_choice < 1 || manage_friends_choice > 4)
                {
                    printf("Invalid choice. Please try again: ");
                    scanf("%d", &manage_friends_choice);
                }
                while (manage_friends_choice != 4)
                {
                    switch (manage_friends_choice)
                    {
                    case 1:
                        display_user_friends(found_user_4);
                        manage_friends_menu(found_user_4);
                        printf("Your choice: ");
                        scanf("%d", &manage_friends_choice);
                        while (manage_friends_choice < 1 || manage_friends_choice > 4)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_friends_choice);
                        }
                        break;
                    case 2:
                        char new_friend[30];
                        printf("\nEnter a new friends' name: ");
                        scanf("%s", new_friend);
                        add_friend(found_user_4, new_friend);
                        printf("Friend added to the list.\n");
                        manage_friends_menu(found_user_4);
                        printf("Your choice: ");
                        scanf("%d", &manage_friends_choice);
                        while (manage_friends_choice < 1 || manage_friends_choice > 4)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_friends_choice);
                        }
                        break;
                    case 3:
                        display_user_friends(found_user_4);
                        char delete_friend_choice[30];
                        printf("\nEnter a friend's name to delete: ");
                        scanf("%s", delete_friend_choice);

                        _Bool successful_delete_friend = delete_friend(found_user_4, delete_friend_choice);
                        if (successful_delete_friend == 0)
                        {
                            printf("Invalid friend's name\n");
                            display_user_friends(found_user_4);
                        }
                        else
                        {
                            display_user_friends(found_user_4);
                        }
                        manage_friends_menu(found_user_4);
                        printf("Your choice: ");
                        scanf("%d", &manage_friends_choice);
                        while (manage_friends_choice < 1 || manage_friends_choice > 4)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_friends_choice);
                        }
                        break;
                    }
                }
            }
            print_menu();
            printf("Enter your choice: ");
            scanf("%d", &menu_choice);
            while (menu_choice < 1 || menu_choice > 6)
            {
                printf("Invalid choice. Please try again.\n\n");
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
            }
            break;
        case 5:
            display_all_posts(users);
            print_menu();
            printf("Enter your choice: ");
            scanf("%d", &menu_choice);
            while (menu_choice < 1 || menu_choice > 6)
            {
                printf("Invalid choice. Please try again.\n\n");
                print_menu();
                printf("Enter your choice: ");
                scanf("%d", &menu_choice);
            }
            break;
        }
    }
    teardown(users);
    printf("**************************************************\n");
    printf("  Thank you for using Text-Based Facebook         \n");
    printf("                Goodbye!                          \n");
    printf("**************************************************\n");
    return 0;
}
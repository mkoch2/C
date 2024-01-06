// ********* main.c ********

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "fbook_updated_nodes.h"
#include "fbook_updated_functions.h"

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

    // Linking friends posts
    for (user_t *current_user = users; current_user != NULL; current_user = current_user->next)
    {
        for (friend_t *current_friend = current_user->friends; current_friend != NULL; current_friend = current_friend->next)
        {
            user_t *linking_friend = find_user(users, current_friend->username);
            current_friend->posts = linking_friend->posts;
        }
    }

    login_menu();
    int login_choice;
    printf("\nEnter your choice: ");
    scanf("%d", &login_choice);
    while (login_choice < 1 || login_choice > 3)
    {
        printf("Invalid choice. Please try again.\n\n");
        login_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &login_choice);
    }

    while (login_choice != 3)
    {
        switch (login_choice)
        {
        case 1:
            char new_username[30];
            printf("\nEnter a username: ");
            scanf("%s", new_username);
            user_t *found_user = find_user(users, new_username);
            if (found_user != NULL)
            {
                printf("User already exists.\n");
            }
            else
            {
                char new_password[15];
                printf("\nEnter an up to 15 characters password: ");
                scanf("%s", new_password);
                users = add_user(users, new_username, new_password);
                printf("\n**** User Added! ****\n\n");
            }
            login_menu();
            printf("\nEnter your choice: ");
            scanf("%d", &login_choice);
            while (login_choice < 1 || login_choice > 3)
            {
                printf("Invalid choice. Please try again.\n\n");
                login_menu();
                printf("\nEnter your choice: ");
                scanf("%d", &login_choice);
            }
            break;
        case 2:
            char username[30];
            char password[15];
            printf("Enter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);
            user_t *found_user_login = find_user(users, username);
            if (found_user_login == NULL || strcmp(password, found_user_login->password) != 0)
            {
                printf("Invalid username or password\n");
                login_menu();
                printf("\nEnter your choice: ");
                scanf("%d", &login_choice);
                while (login_choice < 1 || login_choice > 3)
                {
                    printf("Invalid choice. Please try again.\n\n");
                    login_menu();
                    printf("\nEnter your choice: ");
                    scanf("%d", &login_choice);
                }
                break;
            }
            else
            {
                print_menu(found_user_login);
                int menu_choice;
                printf("\nEnter your choice: ");
                scanf("%d", &menu_choice);
                while (menu_choice < 1 || menu_choice > 5)
                {
                    printf("Invalid choice. Please try again.\n\n");
                    print_menu(found_user_login);
                    printf("\nEnter your choice: ");
                    scanf("%d", &menu_choice);
                }
                while (menu_choice != 5)
                {
                    switch (menu_choice)
                    {
                    case 1:
                        char change_password[15];
                        printf("\nEnter a new password that is up to 15 characters: ");
                        scanf("%s", change_password);
                        strcpy(found_user_login->password, change_password);
                        printf("\n**** Password Changed! ****\n\n");
                        print_menu(found_user_login);
                        printf("\nEnter your choice: ");
                        scanf("%d", &menu_choice);
                        while (menu_choice < 1 || menu_choice > 5)
                        {
                            printf("Invalid choice. Please try again.\n\n");
                            print_menu(found_user_login);
                            printf("\nEnter your choice: ");
                            scanf("%d", &menu_choice);
                        }
                        break;
                    case 2:
                        display_user_posts(found_user_login);
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
                                add_post(found_user_login, post_content);
                                printf("Post added to your profile.\n");
                                display_user_posts(found_user_login);
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

                                _Bool successful_delete_post = delete_post(found_user_login, deleted_post_choice);
                                if (successful_delete_post == 0)
                                {
                                    printf("Invalid post's number");
                                }
                                else
                                {
                                    printf("Post %d was deleted successfully!", deleted_post_choice);
                                }
                                display_user_posts(found_user_login);
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
                        print_menu(found_user_login);
                        printf("\nEnter your choice: ");
                        scanf("%d", &menu_choice);
                        while (menu_choice < 1 || menu_choice > 5)
                        {
                            printf("Invalid choice. Please try again.\n\n");
                            print_menu(found_user_login);
                            printf("\nEnter your choice: ");
                            scanf("%d", &menu_choice);
                        }
                        break;
                    case 3:
                        manage_friends_menu(found_user_login);
                        int manage_friends_choice;
                        printf("Your choice: ");
                        scanf("%d", &manage_friends_choice);
                        while (manage_friends_choice < 1 || manage_friends_choice > 5)
                        {
                            printf("Invalid choice. Please try again: ");
                            scanf("%d", &manage_friends_choice);
                        }
                        while (manage_friends_choice != 5)
                        {
                            switch (manage_friends_choice)
                            {
                            case 1:
                                display_user_friends(found_user_login);
                                manage_friends_menu(found_user_login);
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
                                user_t *found_friend = find_user(users, new_friend);
                                if (found_friend == NULL)
                                {
                                    printf("User does not exist.\n");
                                }
                                else
                                {
                                    add_friend(found_user_login, new_friend);
                                    printf("Friend added to the list.\n");
                                }

                                manage_friends_menu(found_user_login);
                                printf("Your choice: ");
                                scanf("%d", &manage_friends_choice);
                                while (manage_friends_choice < 1 || manage_friends_choice > 4)
                                {
                                    printf("Invalid choice. Please try again: ");
                                    scanf("%d", &manage_friends_choice);
                                }
                                break;
                            case 3:
                                display_user_friends(found_user_login);
                                char delete_friend_choice[30];
                                printf("\nEnter a friend's name to delete: ");
                                scanf("%s", delete_friend_choice);

                                _Bool successful_delete_friend = delete_friend(found_user_login, delete_friend_choice);
                                if (successful_delete_friend == 0)
                                {
                                    printf("Invalid friend's name\n");
                                    display_user_friends(found_user_login);
                                }
                                else
                                {
                                    display_user_friends(found_user_login);
                                }
                                manage_friends_menu(found_user_login);
                                printf("Your choice: ");
                                scanf("%d", &manage_friends_choice);
                                while (manage_friends_choice < 1 || manage_friends_choice > 4)
                                {
                                    printf("Invalid choice. Please try again: ");
                                    scanf("%d", &manage_friends_choice);
                                }
                                break;
                            case 4:
                                display_user_friends(found_user_login);
                                char display_friend_post[30];
                                printf("\nEnter a friend's name to display their posts: ");
                                scanf("%s", display_friend_post);

                                for (friend_t *current_friend = found_user_login->friends; current_friend != NULL; current_friend = current_friend->next)
                                {
                                    if (strcmp(display_friend_post, current_friend->username) == 0)
                                    {
                                        int post_number = 1;
                                        for (post_t *current_post = current_friend->posts; current_post != NULL; current_post = current_post->next)
                                        {
                                            printf("%d- %s: %s\n", post_number, display_friend_post, current_post->content);
                                            post_number++;
                                        }
                                    }
                                }
                                manage_friends_menu(found_user_login);
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
                        print_menu(found_user_login);
                        printf("\nEnter your choice: ");
                        scanf("%d", &menu_choice);
                        while (menu_choice < 1 || menu_choice > 5)
                        {
                            printf("Invalid choice. Please try again.\n\n");
                            print_menu(found_user_login);
                            printf("\nEnter your choice: ");
                            scanf("%d", &menu_choice);
                        }
                        break;
                    case 4:
                        display_all_posts(users);
                        print_menu(found_user_login);
                        printf("\nEnter your choice: ");
                        scanf("%d", &menu_choice);
                        while (menu_choice < 1 || menu_choice > 5)
                        {
                            printf("Invalid choice. Please try again.\n\n");
                            print_menu(found_user_login);
                            printf("\nEnter your choice: ");
                            scanf("%d", &menu_choice);
                        }
                        break;
                    }
                }
                login_menu();
                printf("\nEnter your choice: ");
                scanf("%d", &login_choice);
                while (login_choice < 1 || login_choice > 3)
                {
                    printf("Invalid choice. Please try again.\n\n");
                    login_menu();
                    printf("\nEnter your choice: ");
                    scanf("%d", &login_choice);
                }
                break;
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
//     print_menu();
//     char manage_username[30];
//     int menu_choice;
//     printf("Enter your choice: ");
//     scanf("%d", &menu_choice);

//     while (menu_choice < 1 || menu_choice > 6)
//     {
//         printf("Invalid choice. Please try again.\n\n");
//         print_menu();
//         printf("Enter your choice: ");
//         scanf("%d", &menu_choice);
//     }
//     while (menu_choice != 6)
//     {
//         switch (menu_choice)
//         {
//         case 1:
//             char username[30];
//             char password[15];

//             printf("\nEnter a username: ");
//             scanf("%s", username);
//             printf("Enter an up to 15 characters password: ");
//             scanf("%s", password);

//             users = add_user(users, username, password);
//             printf("\n**** User Added! ****\n\n");
//             print_menu();
//             printf("Enter your choice: ");
//             scanf("%d", &menu_choice);
//             while (menu_choice < 1 || menu_choice > 6)
//             {
//                 printf("Invalid choice. Please try again.\n\n");
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//             }
//             break;
//         case 2:
//             char new_username[30];
//             printf("\nEnter username to update their password: ");
//             scanf("%s", new_username);

//             user_t *found_user_2 = find_user(users, new_username);
//             if (found_user_2 == NULL)
//             {
//                 print_user_not_found();
//             }
//             else
//             {
//                 char new_password[15];
//                 printf("\nEnter a new password that is up to 15 characters: ");
//                 scanf("%s", new_password);
//                 strcpy(found_user_2->password, new_password);
//                 printf("\n**** Password Changed! ****\n\n");
//             }
//             print_menu();
//             printf("Enter your choice: ");
//             scanf("%d", &menu_choice);
//             while (menu_choice < 1 || menu_choice > 6)
//             {
//                 printf("Invalid choice. Please try again\n\n");
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//             }
//             break;
//         case 3:
//             printf("\nEnter username to manage their posts: ");
//             scanf("%s", manage_username);
//             user_t *found_user_3 = find_user(users, manage_username);
//             if (found_user_3 == NULL)
//             {
//                 print_user_not_found();
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//                 while (menu_choice < 1 || menu_choice > 6)
//                 {
//                     printf("Invalid choice. Please try again.\n\n");
//                     print_menu();
//                     printf("Enter your choice: ");
//                     scanf("%d", &menu_choice);
//                 }
//                 break;
//             }
//             else
//             {
//                 display_user_posts(found_user_3);
//                 manage_post_menu();

//                 int manage_posts_choice;
//                 printf("Your choice: ");
//                 scanf("%d", &manage_posts_choice);
//                 while (manage_posts_choice < 1 || manage_posts_choice > 3)
//                 {
//                     printf("Invalid choice. Please try again: ");
//                     scanf("%d", &manage_posts_choice);
//                 }

//                 while (manage_posts_choice != 3)
//                 {
//                     switch (manage_posts_choice)
//                     {
//                     case 1:
//                         char post_content[250];
//                         printf("Enter your post content: ");
//                         scanf(" %[^\n]s", post_content);
//                         add_post(found_user_3, post_content);
//                         printf("Post added to your profile.\n");
//                         display_user_posts(found_user_3);
//                         manage_post_menu();
//                         printf("Your choice: ");
//                         scanf("%d", &manage_posts_choice);
//                         while (manage_posts_choice < 1 || manage_posts_choice > 3)
//                         {
//                             printf("Invalid choice. Please try again: ");
//                             scanf("%d", &manage_posts_choice);
//                         }

//                         break;
//                     case 2:
//                         int deleted_post_choice;
//                         printf("Which post you want to delete: ");
//                         scanf("%d", &deleted_post_choice);

//                         _Bool successful_delete_post = delete_post(found_user_3, deleted_post_choice);
//                         if (successful_delete_post == 0)
//                         {
//                             printf("Invalid post's number");
//                         }
//                         else
//                         {
//                             printf("Post %d was deleted successfully!", deleted_post_choice);
//                         }
//                         display_user_posts(found_user_3);
//                         manage_post_menu();
//                         printf("Your choice: ");
//                         scanf("%d", &manage_posts_choice);
//                         while (manage_posts_choice < 1 || manage_posts_choice > 3)
//                         {
//                             printf("Invalid choice. Please try again: ");
//                             scanf("%d", &manage_posts_choice);
//                         }
//                         break;
//                     }
//                 }
//             }
//             print_menu();
//             printf("Enter your choice: ");
//             scanf("%d", &menu_choice);
//             while (menu_choice < 1 || menu_choice > 6)
//             {
//                 printf("Invalid choice. Please try again.\n\n");
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//             }
//             break;

//         case 4:
//             printf("\nEnter username to manage their friends: ");
//             scanf("%s", manage_username);
//             user_t *found_user_4 = find_user(users, manage_username);
//             if (found_user_4 == NULL)
//             {
//                 print_user_not_found();
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//                 while (menu_choice < 1 || menu_choice > 6)
//                 {
//                     printf("Invalid choice. Please try again.\n\n");
//                     print_menu();
//                     printf("Enter your choice: ");
//                     scanf("%d", &menu_choice);
//                 }
//                 break;
//             }
//             else
//             {
//                 manage_friends_menu(found_user_4);
//                 int manage_friends_choice;
//                 printf("Your choice: ");
//                 scanf("%d", &manage_friends_choice);
//                 while (manage_friends_choice < 1 || manage_friends_choice > 4)
//                 {
//                     printf("Invalid choice. Please try again: ");
//                     scanf("%d", &manage_friends_choice);
//                 }
//                 while (manage_friends_choice != 4)
//                 {
//                     switch (manage_friends_choice)
//                     {
//                     case 1:
//                         display_user_friends(found_user_4);
//                         manage_friends_menu(found_user_4);
//                         printf("Your choice: ");
//                         scanf("%d", &manage_friends_choice);
//                         while (manage_friends_choice < 1 || manage_friends_choice > 4)
//                         {
//                             printf("Invalid choice. Please try again: ");
//                             scanf("%d", &manage_friends_choice);
//                         }
//                         break;
//                     case 2:
//                         char new_friend[30];
//                         printf("\nEnter a new friends' name: ");
//                         scanf("%s", new_friend);
//                         add_friend(found_user_4, new_friend);
//                         printf("Friend added to the list.\n");
//                         manage_friends_menu(found_user_4);
//                         printf("Your choice: ");
//                         scanf("%d", &manage_friends_choice);
//                         while (manage_friends_choice < 1 || manage_friends_choice > 4)
//                         {
//                             printf("Invalid choice. Please try again: ");
//                             scanf("%d", &manage_friends_choice);
//                         }
//                         break;
//                     case 3:
//                         display_user_friends(found_user_4);
//                         char delete_friend_choice[30];
//                         printf("\nEnter a friend's name to delete: ");
//                         scanf("%s", delete_friend_choice);

//                         _Bool successful_delete_friend = delete_friend(found_user_4, delete_friend_choice);
//                         if (successful_delete_friend == 0)
//                         {
//                             printf("Invalid friend's name\n");
//                             display_user_friends(found_user_4);
//                         }
//                         else
//                         {
//                             display_user_friends(found_user_4);
//                         }
//                         manage_friends_menu(found_user_4);
//                         printf("Your choice: ");
//                         scanf("%d", &manage_friends_choice);
//                         while (manage_friends_choice < 1 || manage_friends_choice > 4)
//                         {
//                             printf("Invalid choice. Please try again: ");
//                             scanf("%d", &manage_friends_choice);
//                         }
//                         break;
//                     }
//                 }
//             }
//             print_menu();
//             printf("Enter your choice: ");
//             scanf("%d", &menu_choice);
//             while (menu_choice < 1 || menu_choice > 6)
//             {
//                 printf("Invalid choice. Please try again.\n\n");
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//             }
//             break;
//         case 5:
//             display_all_posts(users);
//             print_menu();
//             printf("Enter your choice: ");
//             scanf("%d", &menu_choice);
//             while (menu_choice < 1 || menu_choice > 6)
//             {
//                 printf("Invalid choice. Please try again.\n\n");
//                 print_menu();
//                 printf("Enter your choice: ");
//                 scanf("%d", &menu_choice);
//             }
//             break;
//         }
//     }
//     teardown(users);
//     printf("**************************************************\n");
//     printf("  Thank you for using Text-Based Facebook         \n");
//     printf("                Goodbye!                          \n");
//     printf("**************************************************\n");
//     return 0;
// }
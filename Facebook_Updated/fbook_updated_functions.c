// ********* definitions.c ********

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fbook_updated_nodes.h"
#include "fbook_updated_functions.h"

// Your solution goes here

/*
   Function that creates a new user and adds it to a sorted (ascending order) linked list at
   the proper sorted location. Return the head of the list.
*/
user_t *add_user(user_t *users, const char *username, const char *password)
{
   // Creates user and adds to heap
   user_t *new_user = malloc(sizeof(user_t));
   assert(new_user != NULL);
   strcpy(new_user->username, username);
   strcpy(new_user->password, password);
   new_user->friends = NULL;
   new_user->posts = NULL;
   new_user->next = NULL;

   if (users == NULL)
   {
      return new_user;
   }
   else
   {
      // Linking new user to sorted linked list
      for (user_t *current = users; current != NULL; current = current->next)
      {

         if (current->next == NULL)
         {
            if ((strcmp(username, current->username) > 0))
            {
               current->next = new_user;
               return users;
            }
            else
            {
               new_user->next = current;
               return new_user;
            }
         }
         else if ((strcmp(username, current->username) > 0) &&
                  (strcmp(username, current->next->username) < 0))

         {

            new_user->next = current->next;
            current->next = new_user;
            return users;
         }
      }
   }

   // return users;
}
/*
   Function that searches if the user is available in the database
   Return a pointer to the user if found and NULL if not found.
*/
user_t *find_user(user_t *users, const char *username)
{

   user_t *found_user = NULL;
   assert(users != NULL);

   for (user_t *current = users; current != NULL; current = current->next)
   {

      if (strcmp(username, current->username) == 0)
      {

         found_user = current;
      }
   }

   return found_user;
}
/*
   Function that creates a new friend's node.
   Return the newly created node.
*/
friend_t *create_friend(const char *username)
{
   friend_t *new_friend = malloc(sizeof(friend_t));
   assert(new_friend != NULL);
   strcpy(new_friend->username, username);
   new_friend->next = NULL;
   return new_friend;
}

/*
   Function that links a friend to a user. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friend(user_t *user, const char *friend)
{
   friend_t *new_friend = create_friend(friend);
   if (user->friends == NULL)
   {
      user->friends = new_friend;
      return;
   }
   else
   {
      for (friend_t *current = user->friends; current != NULL; current = current->next)
      {

         if (current->next == NULL)
         {
            if (strcmp(friend, current->username) > 0)
            {
               current->next = new_friend;
               return;
            }
            else
            {

               new_friend->next = current;
               user->friends = new_friend;
               return;
            }
         }
         else if (strcmp(friend, current->username) < 0)
         {
            new_friend->next = current;
            user->friends = new_friend;
            return;
         }
         else if ((strcmp(friend, current->username) > 0) && (strcmp(friend, current->next->username) < 0))
         {
            new_friend->next = current->next;
            current->next = new_friend;
            return;
         }
      }
   }

   // printf("friend: %s user: %s\n", user->friends->username, user->username);
}

/*
   Function that removes a friend from a user's friend list.
   Return true of the friend was deleted and false otherwise.
*/
_Bool delete_friend(user_t *user, char *friend_name)
{
   friend_t *delete_friend = NULL;
   if (strcmp(friend_name, user->friends->username) == 0)
   {
      delete_friend = user->friends;
      user->friends = user->friends->next;
      free(delete_friend);
      delete_friend = NULL;
      return 1;
   }
   else
   {

      for (friend_t *current = user->friends; current != NULL; current = current->next)
      {
         if (current->next == NULL)
         {
            return 0;
         }
         if (strcmp(friend_name, current->next->username) == 0)
         {
            delete_friend = current->next;
            current->next = current->next->next;
            free(delete_friend);
            delete_friend = NULL;
            return 1;
         }
      }
   }
}

/*
   Function that creates a new user's post.
   Return the newly created post.
*/
post_t *create_post(const char *text)
{
   post_t *new_post = malloc(sizeof(post_t));
   assert(new_post != NULL);
   strcpy(new_post->content, text);
   new_post->next = NULL;

   return new_post;
}

/*
   Function that adds a post to a user's timeline. New posts should be added following
   the stack convention (LIFO) (i.e., to the beginning of the Posts linked list).
*/
void add_post(user_t *user, const char *text)
{
   post_t *new_post = create_post(text);
   new_post->next = user->posts;
   user->posts = new_post;
}

/*
   Function that removes a post from a user's list of posts.
   Return true if the post was deleted and false otherwise.
*/
_Bool delete_post(user_t *user, int number)
{
   post_t *temp = user->posts;
   if (number == 1)
   {

      user->posts = user->posts->next;
      free(temp);
      temp = NULL;
      return 1;
   }
   else
   {
      int index = 1;
      for (post_t *current = user->posts; index <= number; current = current->next)
      {
         if (current->next == NULL)
         {
            return 0;
         }

         if ((index + 1) == number)
         {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
            temp = NULL;
            return 1;
         }
         index += 1;
      }
   }
}

/*
   Function that  displays a specific user's posts
*/
void display_user_posts(user_t *user)
{
   printf("\n--------------------------------------------------\n");
   printf("               %s's posts                         \n", user->username);
   if (user->posts == NULL)
   {

      printf("No posts available for %s.                        \n", user->username);
   }
   else
   {
      int post_num = 1;

      for (post_t *current = user->posts; current != NULL; current = current->next)
      {
         printf("%d- %s: %s\n", post_num, user->username, current->content);
         post_num += 1;
      }
   }
   printf("--------------------------------------------------\n\n");
}

/*
   Function that displays a specific user's friends
*/
void display_user_friends(user_t *user)
{
   printf("\nList of %s's friends:\n", user->username);
   if (user->friends == NULL)
   {

      printf("No friends available for %s\n", user->username);
   }
   else
   {
      int friend_num = 1;
      for (friend_t *current = user->friends; current != NULL; current = current->next)
      {
         printf("%d- %s\n", friend_num, current->username);
         friend_num += 1;
      }
   }
}
/*
   Function that displays all the posts of 2 users at a time from the database.
   After displaying 2 users' posts, it prompts if you want to display
   posts of the next 2 users.
   If there are no more post or the user types “n” or “N”, the function returns.
*/
void display_all_posts(user_t *users)
{

   int display_two = 0;
   user_t *last_user = users;
   while (display_two < 2)
   {
      if (last_user == NULL)
      {
         printf("\nAll posts have been disaplyed\n");
         return;
      }
      else
      {
         for (user_t *current_user = last_user; current_user != NULL && display_two < 2; current_user = current_user->next)
         {
            int post_num = 1;
            for (post_t *current_post = current_user->posts; current_post != NULL; current_post = current_post->next)
            {
               printf("%d- %s: %s\n", post_num, current_user->username, current_post->content);
               post_num++;
            }
            last_user = current_user->next;
            display_two++;
         }

         char display_more[2];
         printf("\n\nDo you want to display the next 2 users posts? (Y/N): ");
         scanf("%s", display_more);

         if (strcmp(display_more, "Y") == 0 || strcmp(display_more, "y") == 0)
         {
            display_two = 0;
         }
         else if (strcmp(display_more, "N") == 0 || strcmp(display_more, "n") == 0)
         {
            return;
         }
      }
   }

   //
}

/*
   Fucntion that free all users from the database before quitting the application.
*/
void teardown(user_t *users)
{
   for (user_t *current_user = users; current_user != NULL; current_user = users)
   {
      for (friend_t *current_friend = users->friends; current_friend != NULL; current_friend = users->friends)
      {
         users->friends = current_friend->next;
         free(current_friend);
         current_friend = NULL;
      }
      for (post_t *current_post = users->posts; current_post != NULL; current_post = users->posts)
      {
         users->posts = current_post->next;
         free(current_post);
         current_post = NULL;
      }
      users = current_user->next;
      free(current_user);
      current_user = NULL;
   }
}

/*
   Function that prints the main menu with a list of options for the user to choose from
*/
void print_menu(user_t *user)
{
   printf("\n**************************************************\n");
   printf("             Welcome %s:                            \n", user->username);
   printf("**************************************************\n");
   printf("1. Manage a user's profile (change password)\n");
   printf("2. Manage a user's posts (display/add/remove)\n");
   printf("3. Manage a user's friends (display/add/remove/see friend's posts)\n");
   printf("4. Display All Posts\n");
   printf("5. Logout\n");
}

/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
   user_t *users = NULL;
   char buffer[500];
   fgets(buffer, sizeof(buffer), file); // Read and discard the header line
   int count = 0;
   for (int i = 0; i < num_users; i++)
   {
      fgets(buffer, sizeof(buffer), file);
      buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

      char *token = strtok(buffer, ",");
      char *token2 = strtok(NULL, ",");
      users = add_user(users, token, token2);
      char *username = token;

      token = strtok(NULL, ",");

      user_t *current_user = users;
      for (; current_user != NULL && strcmp(current_user->username, username) != 0; current_user = current_user->next)
         ;

      while (token != NULL && strcmp(token, ",") != 0 && count < 3)
      {
         if (strcmp(token, " ") != 0)
         {
            add_friend(current_user, token);
         }
         token = strtok(NULL, ",");
         count++;
      }
      count = 0;

      // token = strtok(NULL, ",");
      while (token != NULL && strcmp(token, ",") != 0)
      {
         add_post(current_user, token);
         token = strtok(NULL, ",");
      }
   }
   return users;
}

// Extra functions' Prototypes/Declarations go here

void print_user_not_found()
{
   printf("\n--------------------------------------------------\n");
   printf("                     User not found.                  \n");
   printf("--------------------------------------------------\n\n");
}
void manage_post_menu()
{
   printf("1. Add a new user post\n");
   printf("2. Remove a users post\n");
   printf("3. Return to main menu\n\n");
}

int number_of_posts(user_t *user)
{
   int count = 0;
   for (post_t *current = user->posts; current != NULL; current = current->next)
   {
      count += 1;
   }
   return count;
}

void manage_friends_menu(user_t *user)
{
   printf("\n--------------------------------------------------\n");
   printf("             %s's friends                         \n", user->username);
   printf("--------------------------------------------------\n\n");
   printf("1. Display all user's friends\n");
   printf("2. Add a new friend\n");
   printf("3. Delete a friend\n");
   printf("4. Display a friend's posts\n");
   printf("5. Return to main menu\n\n");
}

void login_menu()
{
   printf("\n**************************************************\n");
   printf("           Welcome to Text-Based Facebook           \n");
   printf("**************************************************\n\n\n");
   printf("**************************************************\n");
   printf("                    MAIN MENU:                    \n");
   printf("**************************************************\n");
   printf("1. Register a new user\n");
   printf("2. Login with existing user's information\n");
   printf("3. Exit\n");
}
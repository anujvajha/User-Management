#include<stdio.h>
#include<string.h>
# define MAX 10

struct details 
{
    char username[50];
    int password;
};
struct details array[MAX];
int user_count =0;

void register_user ()
{
    if(user_count >= MAX)
    { 
       printf("Max 10 users are supported \n");
       return;
    }
    printf("Register a new user \n");
    printf("Enter username :- ");
    gets(array[user_count].username);

    printf("Enter passcode :- ");
    scanf("%d", &array[user_count].password);
    user_count++;
    printf("Registration Successful!! \n");
}


int login_user ()
{
    char user[50];
    int pass;
    printf("Enter username:- ");
    gets(user);

    printf("Enter passcode:- ");
    scanf("%d", &pass);

    for(int i = 0; i < user_count; i++)
    {
        if(strcmp(user, array[i].username) == 0 && array[i].password == pass)
        {
            printf("Login successful!! \n");
            return 1;
        }
    }
    printf("Login Failed! Enter correct username or password \n");
    return 0;
}

int main () 
{
    printf("WELCOME TO USER MANAGEMENT!! \n");
    int n;
    while(1)
    {
        printf("1. Register \n"); 
        printf("2. Login \n"); 
        printf("3. Exit \n"); 

        printf("Enter your choice:- ");
        scanf("%d", &n);
        getchar();

        switch(n)
        {
            case 1:
            register_user();
            break;
            
            case 2:
            login_user();
            break;

            case 3:
            printf("Exiting the program \n");
            return 0;
            break;

            default:
            printf("Enter a valid choice \n");
            break;
        }
    }
}
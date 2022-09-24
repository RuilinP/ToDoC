#include <stdio.h>
#include <stdlib.h>

typedef struct Process process;

struct Process {
        
        char buffer[101];

        
        process* next;

        
        
        int count;
};

process* start = NULL;

int main()
{
        int choice;
        interface();
        printf("\n");
        while (1) {

                printf("\n \n");
                printf("1. To see today's ToDo list\n");
                printf("2. To create a new ToDo\n");
                printf("3. To delete a ToDo\n");
                printf("4. Exit");
                printf("\n\n\nEnter your choice\t:\t");

                scanf("%d", &choice);

                switch (choice) {

                case 1:
                        seetodo();
                        break;
                case 2:
                        createtodo();
                        break;
                case 3:
                        //deletetodo();
                        break;
                case 4:
                        exit(1);
                        break;
                default:
                        printf("\nInvalid Choice :-(\n");
                        break;
                }
        }
        return 0;
}

void interface()
{   
    printf("~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("Welcome to \n \n");
    printf("\n");
    printf("#######        ######          #####  \n");
    printf("   #     ####  #     #  ####  #     # \n");
    printf("   #    #    # #     # #    # #       \n");
    printf("   #    #    # #     # #    # #       \n");
    printf("   #    #    # #     # #    # #     # \n");
    printf("   #     ####  ######   ####   #####  V 0.1\n");
    printf(" \n \n");
    printf("\t \t \t by RuilinP\n");
    printf("\n \n ");
}

void seetodo(){
     process* temp;
     temp = start;
     if(start == NULL){
        printf("Your todo List is empty! Cheer!\n");
     }

     while (temp != NULL){
           printf("%d.", temp->count);
           printf(temp->buffer);
           temp = temp->next;
     }
     printf("\n \n \n ");
}

void createtodo(){
     process* add, temp;
  
     if(start == NULL){
        add = (process*)malloc(sizeof(process));
        start = add;
        printf("\n input your first task:");
        scanf("%50s", add->buffer);         
        add->count = 1;
        start->next = NULL;
     }
}

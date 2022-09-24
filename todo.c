#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void flush(){
     int c;
     do{
        c = getchar();
     }while(c != EOF && c != '\n');
}

void createtodo(){
     process *add, *temp;
     FILE * fptr;
     
     
     char line[101];
     
  
     if(start == NULL){
        fptr = fopen("todo.txt", "w");
        add = (process*)malloc(sizeof(process));
        start = add;
        printf("\n \n input your first task: \n");
        flush();
        fgets(add->buffer, 256, stdin);
        //printf("%s", name);      
        add->count = 1;
        fprintf(fptr, "%d %s", add->count, add->buffer);
        start->next = NULL;
        fclose(fptr);
     } else {
       fptr = fopen("todo.txt", "a");
       temp = (process*)malloc(sizeof(process));
       printf("\n \n input your next task: \n");
       //scanf("%100s", temp->buffer);
       flush();
       fgets(temp->buffer, 256, stdin);
       temp->next = NULL;
       fprintf(fptr, "%d %s", temp->count, temp->buffer);
       add = start;
       while(add->next != NULL){
            add = add->next;
       }
       add->next = temp;
       fclose(fptr);
     }
     updatecount();
}

void updatecount(){
     process* temp;
     int i = 1;
     temp = start;

     while(temp != NULL){
          temp->count = i;
          i++;
          temp = temp->next;
     }
}

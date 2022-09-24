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

        while (1) {

   
                printf("1. To see your ToDo list\n");
                printf("2. To create new ToDo\n");
                printf("3. To delete your ToDo\n");
                printf("4. Exit");
                printf("\n\n\nEnter your choice\t:\t");

                scanf("%d", &choice);

                switch (choice) {

                case 1:
                        //seetodo();
                        break;
                case 2:
                        //createtodo();
                        break;
                case 3:
                        //deletetodo();
                        break;
                case 4:
                        exit(1);
                        break;
                default:
                        printf("\nInvalid Choice :-(\n");
                        //system("pause");
                }
        }
        return 0;
}

void interface()
{
    printf("Welcome to \n \n");
    printf("\n");
    printf("#######        ######          #####  \n");
    printf("   #     ####  #     #  ####  #     # \n");
    printf("   #    #    # #     # #    # #       \n");
    printf("   #    #    # #     # #    # #       \n");
    printf("   #    #    # #     # #    # #     # \n");
    printf("   #     ####  ######   ####   ##### \n");
    printf(" \n \n");
    printf("\t \t \t by RuilinP\n");
    printf("\n \n ");
}

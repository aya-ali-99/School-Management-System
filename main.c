/* School Management System Project */
#include "header.h"

int main()
{
    lst l;
    int x;
    /*========= Creating list ============*/
    CreateList(&l);

/*=== Loop to keep choosing the activity from the menu =====*/
    while(1)
    {
        MAIN_MENU();                //Displaying main menu for user
        fflush(stdin);
        scanf("%d",&x);             //User choosing the activity he wants from the main menu
        printf("=========================================== \n");
    /*========= Target only the activity that user chose ============*/
        switch(x){
        /*=== Adding new student to the list =====*/
        case 1:
            if(!ListFull(&l)){              //Can't add new student if the list is already full
                NEW_STUDENT(&l);
            }
            else{
                printf("List is full.\n");
            }
            break;
        /*=== Deleting a student from the list =====*/
        case 2:
            if(!ListEmpty(&l)){             //Can't delete a student from an empty list
                DELETE_STUDENT(&l);
            }
            else{
                printf("List is empty.\n");
            }
            break;
        /*=== Editing an existing student account in the list =====*/
        case 3:
            if(!ListEmpty(&l)){             //Can't edit a student in an empty list
                STUDENT_EDIT(&l);
            }
            else{
                printf("List is empty.\n");
            }
            break;
        /*=== Updating scores for all students =====*/
        case 4:
            if(!ListEmpty(&l)){             //Can't update scores for an empty list
                STUDENT_SCORE(&l);
            }
            else{
                printf("List is empty.\n");
            }
            break;
        /*=== Sorting the list alphabetically and printing it =====*/
        case 5:
            if(!ListEmpty(&l)){             //Can't print an empty list
                STUDENT_LIST(&l);
            }
            else{
                printf("List is empty.\n");
            }
            break;
        /*=== Sorting the list according to scores and printing it =====*/
        case 6:
            if(!ListEmpty(&l)){             //Can't print an empty list
                RANK_STUDENT(&l);
            }
            else{
                printf("List is empty.\n");
            }
            break;
        default:
            printf("Wrong Entry.\n");       //If user did choose any of the targeted activities
        }
    }

    return 0;
}

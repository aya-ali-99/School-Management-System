#include "header.h"

/*===== This function creates the list =====*/
void CreateList(lst *Pl){
    Pl->top = NULL;
    Pl->siz = 0;
}

/*===== This function displays the welcome screen and targeted activates =====*/
void MAIN_MENU(){
    printf("===============================================\n");
    printf("Welcome to the Management System!\n Enter:\n 1 For adding new student \n 2 For deleting a student \n 3 For editing a student\n 4 For updating scores\n 5 For displaying students' list alphabetically\n 6 for displaying students' list according to scores\n");
    printf("===============================================\n");
}

/*===== This function creates a new student account =====*/
void NEW_STUDENT(lst *Pl){
    lstNode *Pn = (lstNode *) malloc(sizeof(lstNode));    //making new list node
    fflush(stdin);
    printf("Enter student's name: \n");                   //putting new student's data in the new node
    gets(Pn->entry.name);
    printf("Enter student's address: \n");
    gets(Pn->entry.address);
    printf("Enter student's phone number: \n");
    gets(Pn->entry.phoneNo);
    printf("Enter student's ID: \n");
    scanf("%d", &Pn->entry.ID);
    printf("Enter student's birthday (day/month/year): \n");
    scanf("%d %d %d", &Pn->entry.birthday.day,&Pn->entry.birthday.month, &Pn->entry.birthday.year);
    Pn->next = Pl->top;
    Pn->pre =NULL;                                      //inserting the new node in last place in the list
    Pl->top = Pn;
    Pl->siz++;                                          //number of students in the list = list size
    printf("%s \t %d \t %s \t %d/%d/%d \t %s \n", Pn->entry.name, Pn->entry.ID, Pn->entry.phoneNo, Pn->entry.birthday.day, Pn->entry.birthday.month, Pn->entry.birthday.year, Pn->entry.address);
    printf("List size = %d\n", Pl->siz);
}

/*===== This function is for deleting a customer account =====*/
void DELETE_STUDENT(lst *Pl){
    int id;
    printf("Enter student's ID you want to delete:\n");
    scanf("%d", &id);
    lstNode *Pn = Pl->top;
    lstNode *tmp = Pn;
    while(Pn->entry.ID != id){                     //searching for the student by his ID
        tmp = Pn;
        Pn = Pn->next;
    }
    if(Pn==Pl->top)                                //if the student is last one in the list
    {
        Pl->top = Pn->next;
    }
    if(Pn->next == NULL){
        Pn->pre->next = NULL;
    }
    else{
        tmp->next = Pn->next;                       //deleting the node containing the student
        Pn->next->pre = tmp;
    }
    free(Pn);
    Pl->siz--;                                      //decrement number of students in the list
    printf("Student with id %d was deleted successfully. \n", id);
}

/*===== This function print student's list in table form (alphabetically ascending) =====*/
void STUDENT_LIST(lst *Pl){

    lstNode *tmp , *tmp2;

    int i;
    printf("Now Sorting\n");
    /*====== Bubble sort to sort list alphabetically ======*/
    for(i=0 ; i< (Pl->siz) ; i++){

        tmp = Pl->top;
        while(tmp->next != NULL){

            tmp2 = tmp->next;

            if(strcasecmp(tmp->entry.name , tmp2->entry.name)>0){
                SwapN(Pl, tmp , tmp2);

            }
            else{
            tmp = tmp->next;
            }
        }

    }

    /*====== Printing list after sorting it alphabetically ======*/
    printf("List is sorted. Now printing\n");

    lstNode *Pnn = Pl->top;
    printf("Name \t\t ID \t Phone No. \t Birthday \t Address\n");
    for(i=0 ; i< (Pl->siz) ; i++){
        printf("%s \t %d \t %s \t %d/%d/%d \t\t %s \n", Pnn->entry.name, Pnn->entry.ID, Pnn->entry.phoneNo, Pnn->entry.birthday.day, Pnn->entry.birthday.month, Pnn->entry.birthday.year, Pnn->entry.address);
        Pnn = Pnn->next;
    }
}

/*===== This function swaps two nodes within the list =====*/
void SwapN(lst *Pl, lstNode *tmp , lstNode *tmp2){

    /*===== If the swapped element is the last element in the list =====*/
    if(tmp->pre != NULL){
        tmp->pre->next = tmp2;
        tmp2->pre =tmp->pre;
    }
    else{
        tmp2->pre = NULL;
        Pl->top = tmp2;
    }
    tmp->pre = tmp2;
    /*===== If the swapped element is the first element in the list =====*/
    if(tmp2->next != NULL){
        tmp->next = tmp2->next;
        tmp2->next->pre = tmp;
    }
    else{
        tmp->next = NULL;
    }
    tmp2->next = tmp;


}

/*===== This function is used for updating a particular student account =====*/
void STUDENT_EDIT(lst *Pl){
    unsigned int id, i=0;
    printf("Enter student's ID you want to edit:\n");
    scanf("%d", &id);
    lstNode *Pn = Pl->top;
    while(Pn->entry.ID != id){                        //Finding the student's node by his ID
        Pn = Pn->next;
    }

    /*======= Choose the exact data you want to update in the student's account =======*/
    while(i!=6){
        printf("Enter:\n 1 to edit student name\n 2 to edit ID\n 3 to edit phone number\n 4 to edit birthday\n 5 to edit address\n 6 to finish editing\n");
        scanf("%d" , &i);
        fflush(stdin);
        switch(i){
            case 1:
                printf("Enter student's new name: \n");
                gets(Pn->entry.name);
                break;
            case 2:
                printf("Enter student's new ID: \n");
                scanf("%d", &Pn->entry.ID);
                break;
            case 3:
                printf("Enter student's new phone number: \n");
                gets(Pn->entry.phoneNo);
                break;
            case 4:
                printf("Enter student's new birthday (day/month/year): \n");
                scanf("%d %d %d", &Pn->entry.birthday.day,&Pn->entry.birthday.month, &Pn->entry.birthday.year);
                break;
            case 5:
                printf("Enter student's new address: \n");
                gets(Pn->entry.address);
                break;
            default:
                printf("Wrong entry\n");
        }
    printf("Done.\n");
    }
}

/*===== This function can sort all students according to computer science score and print it =====*/
void RANK_STUDENT(lst *Pl){
    lstNode *tmp , *tmp2;

    int i;
    printf("Now Sorting\n");
    /*====== Bubble sort to sort list according to scores ======*/
    for(i=0 ; i< (Pl->siz) ; i++){

        tmp = Pl->top;
        while(tmp->next != NULL){

            tmp2 = tmp->next;

            if(tmp->entry.score < tmp2->entry.score){
                SwapN(Pl, tmp , tmp2);

            }
            else{
            tmp = tmp->next;
            }
        }

    }

    /*====== Printing list after sorting it ======*/
    printf("List is sorted. Now printing\n");

    lstNode *Pnn = Pl->top;
    printf("Name \t\t Score \t ID \t Phone No. \t Birthday \t Address\n");
    for(i=0 ; i< (Pl->siz) ; i++){
        printf("%s \t %d \t %d \t %s \t %d/%d/%d \t\t %s \n", Pnn->entry.name, Pnn->entry.score, Pnn->entry.ID, Pnn->entry.phoneNo, Pnn->entry.birthday.day, Pnn->entry.birthday.month, Pnn->entry.birthday.year, Pnn->entry.address);
        Pnn = Pnn->next;
    }
}

/*===== This function is used for updating score for all students =====*/
void STUDENT_SCORE(lst *Pl){
    lstNode *Pn = Pl->top;
    while(Pn != NULL){
        printf("Student name: %s , Student ID: %d \nEnter the score:\n",Pn->entry.name, Pn->entry.ID);
        scanf("%d", &Pn->entry.score);          //stopping at each student to update his score
        Pn = Pn->next;
    }
    printf("Scores added to all students.\n");
}

/*===== This function is used to check if the list is empty =====*/
char ListEmpty(lst *Pl){
    return Pl->top == NULL;             //first element is NULL -> list is empty
}

/*===== This function is used to check if the list is full =====*/
char ListFull(lst *Pl){
    return NULL == malloc(sizeof(lstNode));
}


/*
    /*
    ~~~ I Wayan Bagus Ari Mantara ~~~
    ~~~ Program : Student ID List ~~~
    ~~~ Language : C ~~~
    ~~~ Github username : aratnamirasugab ~~~

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[100];
    char NIM[100]; // NIM is student ID number
}Student[1000];

int total_std=0; //total student
char temp_name[100];
char temp_nim[100];

void sorting_NIM_increasing(); // function prototype
void sorting_NIM_decreasing();
void view()
{
    for(int i=0;i<total_std;i++){
        printf("%s %s\n", Student[i].name, Student[i].NIM);
    }

    getchar();
}

int main(void)
{
    int initial_std = 0;
    printf("Initial Student ? : "); //Total number of student that we want to sort
    scanf("%d", &initial_std);

    char in_name[100];
    char in_NIM[100];

    while(initial_std >= 0){
        printf("Input Student name : ");
        scanf("%[^\n]", in_name); fflush(stdin);

        printf("Input Student NIM : ");
        scanf("%s", in_NIM); fflush(stdin);

        printf("\n");

        strcpy(Student[total_std].name, in_name);
        strcpy(Student[total_std].NIM, in_NIM);

        total_std++;
        initial_std--;
    };

    int option;

    do
    {
        printf("1.Sorting in Ascending order\n");
        printf("2.Sorting in Descending order\n");
        printf("3.View Student List\n");
        printf("4.Exit\n");
        printf("Choose : ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            system("cls");
            sorting_NIM_increasing();
            printf("Successfully sorted..\n");
            getchar();
            break;
        case 2:
            system("cls");
            sorting_NIM_decreasing();
            printf("Successfully sorted..\n");
            getchar();
            break;
        case 3:
            system("cls");
            view();
            getchar();
            break;
        }


    }while(option != 4);
}

void sorting_NIM_increasing()
{
    for(int i=0;i<total_std;i++){
        for(int j=0;j<total_std;j++){

            if(strcmp(Student[j].NIM,Student[j+1].NIM) > 0 ){
                strcpy(temp_name, Student[j].name);
                strcpy(temp_nim, Student[j].NIM);

                strcpy(Student[j].NIM, Student[j+1].NIM);
                strcpy(Student[j].name, Student[j+1].name);

                strcpy(Student[j+1].NIM, temp_nim);
                strcpy(Student[j+1].name, temp_name);
            }
        }
    }
}

void sorting_NIM_decreasing()
{
    for(int i=0;i<total_std;i++){
        for(int j=0;j<total_std;j++){

            if(strcmp(Student[j].NIM,Student[j+1].NIM) < 0 ){
                strcpy(temp_name, Student[j].name);
                strcpy(temp_nim, Student[j].NIM);

                strcpy(Student[j].NIM, Student[j+1].NIM);
                strcpy(Student[j].name, Student[j+1].name);

                strcpy(Student[j+1].NIM, temp_nim);
                strcpy(Student[j+1].name, temp_name);
            }
        }
    }
}


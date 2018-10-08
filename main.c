#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char nama[100];
    char NIM[100];
}Mahasiswa[1000];

int total_mhs=0;
char temp_name[100];
char temp_nim[100];

void sorting_NIM_terkecil()
{
    for(int i=0;i<total_mhs;i++){
        for(int j=0;j<total_mhs;j++){

            if(strcmp(Mahasiswa[j].NIM,Mahasiswa[j+1].NIM) > 0 ){
                strcpy(temp_name, Mahasiswa[j].nama);
                strcpy(temp_nim, Mahasiswa[j].NIM);

                strcpy(Mahasiswa[j].NIM, Mahasiswa[j+1].NIM);
                strcpy(Mahasiswa[j].nama, Mahasiswa[j+1].nama);

                strcpy(Mahasiswa[j+1].NIM, temp_nim);
                strcpy(Mahasiswa[j+1].nama, temp_name);
            }
        }
    }
}

void sorting_NIM_terbesar()
{
    for(int i=0;i<total_mhs;i++){
        for(int j=0;j<total_mhs;j++){

            if(strcmp(Mahasiswa[j].NIM,Mahasiswa[j+1].NIM) < 0 ){
                strcpy(temp_name, Mahasiswa[j].nama);
                strcpy(temp_nim, Mahasiswa[j].NIM);

                strcpy(Mahasiswa[j].NIM, Mahasiswa[j+1].NIM);
                strcpy(Mahasiswa[j].nama, Mahasiswa[j+1].nama);

                strcpy(Mahasiswa[j+1].NIM, temp_nim);
                strcpy(Mahasiswa[j+1].nama, temp_name);
            }
        }
    }
}

void view()
{
    for(int i=0;i<total_mhs;i++){
        printf("%s %s\n", Mahasiswa[i].nama, Mahasiswa[i].NIM);
    }

    getchar();
}

int main(void)
{
    int jml_mahasiswa = 0;
    printf("Jumlah mahasiswa ? : ");
    scanf("%d", &jml_mahasiswa);

    char in_nama[100];
    char in_NIM[100];

    while(jml_mahasiswa >= 0){
        printf("Input nama mahasiswa : ");
        scanf("%[^\n]", in_nama); fflush(stdin);

        printf("Input NIM mahasiswa : ");
        scanf("%s", in_NIM); fflush(stdin);

        strcpy(Mahasiswa[total_mhs].nama, in_nama);
        strcpy(Mahasiswa[total_mhs].NIM, in_NIM);

        total_mhs++;
        jml_mahasiswa--;
    };

    int option;

    do
    {
        printf("1.Sorting sesuai NIM dari terkecil\n");
        printf("2.Sorting sesuai NIM dari terbesar\n");
        printf("3.View list\n");
        printf("4. exit\n");
        printf("Choose : ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            system("cls");
            sorting_NIM_terkecil();
            printf("Successfully sorted..\n");
            getchar();
            break;
        case 2:
            system("cls");
            sorting_NIM_terbesar();
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



#include <stdio.h>
int counter=1;
int choice;
int length[14]={0};




int main()
{
    char array[counter][400];

//Δημιουργία πίνακα
    do
    {
        printf("Hi there, gimme a string\n");
        fgetc(stdin);
        gets(array[counter-1]);

        printf("Cool, do you wanna give me more;\n 1.Yes \t 2.No\n");
        scanf("%d",&choice);

        if (choice==1) counter++;
    } while(choice!=2);



    //Καταμέτριση
    int i;
    int j;
    int temp;
    for (i=0;i<=(counter-1);i++)
    {
        int temp=0;
        for (j=0;array[i][j]!='\0';j++)
        {
            if ( ( array[i][j]>='a' && array[i][j]<='z') || ( array[i][j]>='A' && array[i][j]<='Z' ) ) temp++;
          else
            {
                length[temp]++;
                temp=0;

            }
        }
     length[temp]++;
    }

    //Τελική εκτύπωση
    system("clear");
    printf("\n\n\n\nWorld Length\t | Number of Occurrences\n============================================\n");
    for(i=1;i<=13;i++)
    {
        printf("%i           \t |",i);
        for(j=1;j<=length[i];j++) printf("*");
        printf("\n");

    }
    printf("\n============================================\n");


}

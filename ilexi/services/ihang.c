#include <stdio.h>
char lexi[100];
int choice;
int length;
int counter;
int victory=1;
char try;
char tried[27];
int t=0;
int i;
int exist(char,char array[]);
int main()
{

  printf("Welcome...\n To the most addictive and original game ever...\n\n\n Before we begin... tell me the magic word:");
  fflush(stdin);
  gets(lexi);

//O παίκτης επιλέγει την λέξη της κρεμάλας
  do
  {
  printf("Wow, what a marvelous word...  %s \n Are you ready to play ?\n 1. Yes \t 2. No, I wanna change my word\n",lexi);

  do{
    scanf("%d",&choice);
    if ((choice!=1)&&(choice!=2))printf("You have to choose something between 1 and 2 dear\n");
  }while((choice!=1)&&(choice!=2));


if (choice==2)
{
  printf("Then the word shall be...\n");
  fflush(stdin);
    gets(lexi);

}

}while(choice!=1);
    
//Επιλέγονται οι φορές που επιτρέπεται να γίνει λάθος
printf("\nGreat,how many times is the player allowed to try?\n ");
scanf("%d",&counter);

//καθορισμός μεγέθους λέξης και μετατροπή της σε μικρά γράμματα για διευκόλινση της διαχείρισης της
    for(i=0; lexi[i]!='\0';i++) if( (lexi[i]>='A') && (lexi[i]<='Z') ) lexi[i]=(int)lexi[i]+(int)32;
length=i-1;

    
//Εκκίνηση κρεμάλας
system("clear");

printf("Let the games begin...\n\n\n\n");


char game[length];
    for(i=0;i<=length;i++)game[i]='_';

int firsttry=0;

do
{
fflush(stdin);
fflush(stdout);
  //Αυτό που βλέπει ο χρήστης σε κάθε clear
printf("\n\n\n");
victory=1;
for (i=0;i<=length;i++) printf("%c  ",game[i]);
if (firsttry!=0)
{
    printf("\n\n You have already tried:");
for (i=0;i!=t;i++) printf("%c ",tried[i]);
}
printf("\nGimme a character dear\n %d tries left\n",counter);

//Εισαγωγή προσπάθειας
do
{
scanf("%s",&try);
if( (try<='A') && (try>='Z') ) try=(int)try+32;
if (exist(try,tried)==1) printf("\n You already tried that hun\n");
}while(exist(try,tried)==1);
    
    
system("clear");
if ((int)try<=90) try=(int)try+32;

//Αν δεν έχεις προσπαθήσει ξανά το ίδιο γράμμα, προστήθεται στην λίστα με τις προσπάθειες
if ((exist(try,tried)==0)&&(exist(try,lexi)==0))
{
  tried[t]=try; t++;
}
//Έλεγχος προσπάθειας
for (i=0;i<=length;i++) if (lexi[i]==try)  game[i]=lexi[i];

if (exist(try,lexi)==0)
{
    printf("\nThere is no such character in the magic word\n");
    counter--;
}

firsttry=1;
if (exist('_',game)==1) victory=0;
}while((counter>=0)&&(victory!=1));

if (exist('_',game)==1) printf("\nToo bad, you are a loser\n");
else printf("\nYayyyy, you just wasted your time <3\n");
}


int exist(char a, char lexi[])
{
  int result=0;
  for(i = 0; lexi[i] != '\0'; ++i)if (a==lexi[i]) result=1;
  return (result);
}

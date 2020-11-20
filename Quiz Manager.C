/*Quiz Program By Vaibhav Tandon in C*/
//CODED IN DEVC++
/*HEADER FILES*/
#include<time.h>
#include <stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
int arr[30],att[6],n=1,n2=1,n1=1,n4=1;
int score=0,cat1=0,cat2=0,cat3=0,cat4=0,cat5=0,k=0;
char uch[10];
FILE *fin,*fout;
void init(int arr[30])
{
int i;
for(i=0;i<30;i++)
arr[i]=i+1;
}
struct questions
{
char q[150],a1[25],a2[25],a3[25],a4[25],r,ch,cat[25];
}ques;

void play();        //Play the quiz
void display();     //Display quiz questions
void show_data();   //Show quiz questions in display function
void get_ques();    //Show quiz questions in display function
void get_results(); //Displays User's Input against the stored answers
void show_result(); //Shows Category Wise Results
void Randomize(int*);   //Randomize quiz questions

void main_menu()
{

 int choice;
 n=1,n2=1,n1=1,n4=1,
 score=0,cat1=0,cat2=0,cat3=0,cat4=0,cat5=0,k=0;

 system("cls");
 printf("\t\t\tWELCOME TO THE QUIZ GAME!!!!!!");
 printf("\n\n\n\n\n\t\t\t\t  MAIN MENU");
 printf("\n\n\n\t\t\t\t  1.Play game");
 printf("\n\n\n\t\t\t\t  2.Display all questions");
 printf("\n\n\n\t\t\t\t  3.Exit");
 printf("\n\n\n\t\t\t\t  Enter your choice ");
 scanf("%d",&choice);
  switch(choice)
  {
   case 1:play();break;
   case 2:display();break;
   case 3:exit(0);
  }
}

void play()
{
 int i=0,pos;
 fin=fopen("Ques.txt","r");
 fseek(fin,0,SEEK_SET);
 fread(&ques,sizeof(struct questions),1,fin);
 init(arr);
 Randomize(arr);

 for(i=0;i<10;i++)
 { system("cls");
   pos=(arr[i]-1)*sizeof(struct questions);
   fseek(fin,pos,SEEK_SET);
   fread(&ques,sizeof(struct questions),1,fin);
   get_ques();
   system("pause");
 }

system("cls");
printf("Congratulations.You have completed the quiz\n\nYou have got %d answers correct out of 10 questions",score);
printf("\n\n\n\nPress any key to know your answers against the correct answers\n\n");
system("pause");

system("cls");
fseek(fin,0,SEEK_SET);
fread(&ques,sizeof(struct questions),1,fin);

 for(i=0;i<10;i++)
 { system("cls");
   pos=(arr[i]-1)*sizeof(struct questions);
   fseek(fin,pos,SEEK_SET);
   fread(&ques,sizeof(struct questions),1,fin);
   get_results();
   printf("\n\n Your choice ");
   printf("%c",uch[i]);
   if(ques.r==uch[i])
   printf("\n\n Marks awarded = 2\n");
   else
   printf("\n\n Marks awarded = 0\n");
   system("pause");
 }

system("cls");
show_result();
system("pause");

main_menu();
}

void display()
{ int i=0;
 fin=fopen("Ques.txt","r");

 fread(&ques,sizeof(struct questions),1,fin);
  for(i=0;i<30;i++)
 { system("cls");
   fread(&ques,sizeof(struct questions),1,fin);
   show_data();
   system("pause");
 }
main_menu();
}



void show_data()  //Show questions in display() functions
{
printf("\n\n  The category of question is ") ;
puts(ques.cat);
printf("Q%d ",n1);n1++;
puts(ques.q);
printf("\n   Options : \n");
printf("\n   a) ");
puts(ques.a1);
printf("\n   b) ");
puts(ques.a2);
printf("\n   c) ");
puts(ques.a3);
printf("\n   d) ");
puts(ques.a4);

}
void get_ques()  //Get questions for the quiz
{
printf("\n\n  The category of question is ") ;
puts(ques.cat);
printf("Q%d ",n);n++;
puts(ques.q);
printf("\n   Options : \n");
printf("\n   a) ");
puts(ques.a1);
printf("\n   b) ");
puts(ques.a2);
printf("\n   c) ");
puts(ques.a3);
printf("\n   d) ");
puts(ques.a4);
printf("\n\n Enter your choice ");
scanf("%c",&ques.ch);
ques.ch=getchar();
ques.ch=tolower(ques.ch);
uch[k]=ques.ch;
k++;
if(ques.ch>='a'&&ques.ch<='d')
{

 if(ques.ch==ques.r)
{ printf("\n Correct Answer!!!\n");
  score++;
  if(strcmp(ques.cat,"Politics")==0)
  { cat1++;

  }
  else if(strcmp(ques.cat,"Music")==0)
  { cat2++;

  }
  else if(strcmp(ques.cat,"General knowledge")==0)
  { cat3++;

  }
  else if(strcmp(ques.cat,"Space")==0)
  { cat4++;

  }
  else if(strcmp(ques.cat,"Sports")==0)
  { cat5++;

  }
}
  else
  printf("\n Wrong Answer\n");
}
  else
  {
  printf("\n Invalid choice\n");
  if(strcmp(ques.cat,"Politics")==0)
  {
    att[1]=1;
  }
  else if(strcmp(ques.cat,"Music")==0)
  {
    att[2]=1;
  }
  else if(strcmp(ques.cat,"General knowledge")==0)
  {
    att[3]=1;
  }
  else if(strcmp(ques.cat,"Space")==0)
  {
    att[4]=1;
  }
  else if(strcmp(ques.cat,"Sports")==0)
  {
    att[5]=1;
  }
}

}
void show_result()     //Shows Category Wise Results
{

printf("Category wise marks.....");

printf("\n\nCategory : Politics marks %d ",cat1*2);

printf("\n\nCategory : Music marks %d ",cat2*2);

printf("\n\nCategory : General knowledge marks %d ",cat3*2);

printf("\n\nCategory : Space marks %d ",cat4*2);

printf("\n\nCategory : Sports marks %d ",cat5*2);

printf("\n\n\n Your final total score out of 20 is %d ",score*2);
printf("\n\n\nPress any key to return to main menu\n");

}
void get_results()  //Displays User's Input against the stored answers
{
printf("\n\n  The category of question is ") ;
puts(ques.cat);
printf("Q%d",n4);n4++;
puts(ques.q);
printf("\n   Options : \n");
printf("\n   a) ");
puts(ques.a1);
printf("\n   b) ");
puts(ques.a2);
printf("\n   c) ");
puts(ques.a3);
printf("\n   d) ");
puts(ques.a4);

printf("\n\n Correct choice ");
printf("%c",ques.r);
}


void Randomize ( int arr[30] ) //Randomizes the questions
{       int temp,n=30,i;

    srand ( time(NULL) );

    for ( i = n-1; i > 0; i--)
    {

    int j = rand() % (i+1);


	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;

    }
}
int main(void)
 {
  system("cls");
  main_menu();
  system("pause");
 }










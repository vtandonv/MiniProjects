/*Quiz Program By Vaibhav Tandon in C++*/
//CODED IN DEVC++
/*HEADER FILES*/
#include<ctime>
#include <cstdlib>
#include<fstream>
#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
using namespace std;

int arr[30],att[6],n=1,n2=1,n1=1,n4=1;
int score=0,cat1=0,cat2=0,cat3=0,cat4=0,cat5=0,k=0;
char uch[10];
void init(int arr[30])
{
int i;
for(i=0;i<30;i++)
arr[i]=i+1;
}
class questions
{

char q[150],a1[25],a2[25],a3[25],a4[25],r,ch,cat[25];


public:

void upload();    // Upload New Questions

void play();      // Play the Game

void display();   // Display Questions

void main_menu(); //Display Main Menu

void get_data()  //Input questions from admin
{
cout<<"\n\n Enter the category of question";
gets(cat);
cout<<"\n\n       Enter the new question to be uploaded"<<endl;
cout<<"Q"<<n2++<<" ";
gets(q);
cout<<"\n  Enter Options : \n";
cout<<"\n   a) ";
gets(a1);
cout<<"\n   b) ";
gets(a2);
cout<<"\n   c) ";
gets(a3);
cout<<"\n   d) ";
gets(a4);
cout<<"\n  Enter correct option ";
cin>>r;
}
void show_data()  //Show questions in display() functions
{
cout<<"\n\n  The category of question is " ;
puts(cat);
cout<<"Q"<<n1++<<" ";
puts(q);
cout<<"\n   Options : \n";
cout<<"\n   a) ";
puts(a1);
cout<<"\n   b) ";
puts(a2);
cout<<"\n   c) ";
puts(a3);
cout<<"\n   d) ";
puts(a4);

}
void get_ques()  //Get questions for the quiz
{
cout<<"\n\n  The category of question is " ;
puts(cat);
cout<<"Q"<<n<<" ";n++;
puts(q);
cout<<"\n   Options : \n";
cout<<"\n   a) ";
puts(a1);
cout<<"\n   b) ";
puts(a2);
cout<<"\n   c) ";

puts(a3);
cout<<"\n   d) ";
puts(a4);
cout<<"\n\n Enter ur choice ";
cin>>ch;
ch=tolower(ch);
uch[k]=ch;
k++;
if(ch>='a'&&ch<='d')
{ 
  if(ch==r)
  {cout<<"\n Correct Answer!!!"<<endl;
  score++;
  if(strcmp(cat,"Politics")==0)
  { cat1++;

  }
  else if(strcmp(cat,"Music")==0)
  { cat2++;

  }
  else if(strcmp(cat,"General knowledge")==0)
  { cat3++;

  }
  else if(strcmp(cat,"Space")==0)
  { cat4++;

  }
  else if(strcmp(cat,"Sports")==0)
  { cat5++;

  }
}
else
cout<<"\n Wrong Answer"<<endl;

}
  else
  {
  cout<<"\n Invalid choice"<<endl;
  if(strcmp(cat,"Politics")==0)
  {
    att[1]=1;
  }
  else if(strcmp(cat,"Music")==0)
  {
    att[2]=1;
  }
  else if(strcmp(cat,"General knowledge")==0)
  {
    att[3]=1;
  }
  else if(strcmp(cat,"Space")==0)
  {
    att[4]=1;
  }
  else if(strcmp(cat,"Sports")==0)
  {
    att[5]=1;
  }
 }
}
void show_result()     //Shows Category Wise Results
{

cout<<"Category wise marks.....";

cout<<"\n\nCategory : Politics marks "<<cat1*2;

cout<<"\n\nCategory : Music marks "<<cat2*2;

cout<<"\n\nCategory : General knowledge marks "<<cat3*2;

cout<<"\n\nCategory : Space marks "<<cat4*2;

cout<<"\n\nCategory : Sports marks "<<cat5*2;

cout<<"\n\n\n Your final total score out of 20 is "<<score*2;
cout<<"\n\n\nPress any key to return to main menu"<<endl;

}
void get_results()  //Displays User's Input against the stored answers
{
cout<<"\n\n  The category of question is " ;
puts(cat);
cout<<"Q"<<n4++<" ";
puts(q);
cout<<"\n   Options : \n";
cout<<"\n   a) ";
puts(a1);
cout<<"\n   b) ";
puts(a2);
cout<<"\n   c) ";
puts(a3);
cout<<"\n   d) ";
puts(a4);

cout<<"\n\n Correct choice ";
cout<<r;
}
}ques;

void Randomize ( int arr[30], int n=30 ) //Randomizes the questions
{       int temp;

    srand ( time(NULL) );

    for (int i = n-1; i > 0; i--)
    {

    int j = rand() % (i+1);


	 temp=arr[i];
	 arr[i]=arr[j];
	 arr[j]=temp;

    }
}

void questions:: upload() //Uploads questions to the file
{
 int i;
 ofstream fout("Ques.txt" ,ios::binary);
 for(i=0;i<30;i++)
 {
  system("cls");
  ques.get_data();
  fout.write((char*)&ques,sizeof(ques));
  system("pause");
 }
 fout.close();
 system("pause");
}

void questions:: display() //Displays Questions from the file
{
 int i=0;
 ifstream fin("Ques.txt",ios::binary);
 fin.seekg(0);
 fin.read((char*)&ques,sizeof(ques));
 for(i=0;i<30;i++)
 { system("cls");
   fin.read((char*)&ques,sizeof(ques));
   ques.show_data();
   system("pause");
 }
main_menu();
}
void questions:: play() //Plays the quiz
{
 int i=0;
 ifstream fin("Ques.txt",ios::binary);
 fin.seekg(0);
 fin.read((char*)&ques,sizeof(ques));
 init(arr);
 Randomize(arr);

 for(i=0;i<10;i++)
 { system("cls");
   int pos=(arr[i]-1)*sizeof(ques);
   fin.seekg(pos);
   fin.read((char*)&ques,sizeof(ques));
   ques.get_ques();
   system("pause");
 }

system("cls");
cout<<"Congratulations.You have completed the quiz\n\nYou have got "<<score<<" answers correct out of 10 questions";
cout<<"\n\n\n\nPress any key to know your answers against the correct answers"<<endl;
system("pause");

system("cls");
fin.seekg(0);
fin.read((char*)&ques,sizeof(ques));

 for(i=0;i<10;i++)
 { system("cls");
   int pos=(arr[i]-1)*sizeof(ques);
   fin.seekg(pos);
   fin.read((char*)&ques,sizeof(ques));
   ques.get_results();
   cout<<"\n\n Your choice ";
   cout<<uch[i];
   if(r==uch[i])
   cout<<"\n\n Marks awarded = 2"<<endl;
   else
   cout<<"\n\n Marks awarded = 0"<<endl;
   system("pause");
 }

system("cls");
show_result();
system("pause");

main_menu();
}


void questions:: main_menu()
{
 system("cls");
 n=1,n2=1,n1=1,n4=1,
score=0,cat1=0,cat2=0,cat3=0,cat4=0,cat5=0,k=0;
 int choice;
 cout<<"\t\t\tWELCOME TO THE QUIZ GAME!!!!!!";
 cout<<"\n\n\n\n\n\t\t\t\t  MAIN MENU";
 cout<<"\n\n\n\t\t\t\t  1.Play game";
 cout<<"\n\n\n\t\t\t\t  2.Display all questions";
 cout<<"\n\n\n\t\t\t\t  3.Exit";
 cout<<"\n\n\n\t\t\t\t  Enter your choice ";
 cin>>choice;
  switch(choice)
  {
   case 1:ques.play();break;
   case 2:ques.display();break;
   case 3:exit(0);
  }
}
int main(void)
 {
  system("cls");
  ques.main_menu();
//ques.upload();
  system("pause");
 }










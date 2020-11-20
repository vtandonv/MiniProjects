#include<iostream>
using namespace std;
struct patient
{
 int p_id;
 string p_name;
 char gender;
 patient *next;
};
patient *start=NULL,*temp=NULL,*temp1,*t;

void insert(int id,string name,char g)
{
 patient *p1=new patient;
 p1->p_id=id;
 p1->p_name=name;
 p1->gender=g;
 p1->next=NULL;
 if(start==NULL)
 {
  start=p1;
 
 }
 else
 {
  patient *t=new patient;
  t=start;
  while(t->next!=NULL)
  {
   t=t->next;
   
  }
  t->next=p1;
  
 }
 
 }
 
 void del(int id)
 {
  temp=start;int f=0;
  if(temp==NULL)
  {
   f=1;
   cout<<"List is empty"<<endl;
  }
  else
  {
  
  while(temp!=NULL)
  {
   if(temp->p_id==id)
   {   f=1;
    if(temp==start)
    {
     cout<<"\n"<<id<<" deleted"<<endl;
     start=temp->next;
     temp=t;
    delete t;
     break;
    }
    else 
    {
     cout<<"\n"<<id<<" deleted"<<endl;
     temp1=start;
     while(temp1->next!=temp)
     {
      temp1=temp1->next;
     }
     temp1->next=temp->next;
     temp=t;
     delete t;
     break;
    }
   }
   temp=temp->next;
  }
   }
   if(f==0)
   cout<<"Not found"<<endl;
  } 
  
void search(int id)
{
 temp=start;int f=0;
 if(temp==NULL)
 {
  cout<<"List is empty"<<endl;
  f=1;
 }
 else
 {
 
 while(temp!=NULL)
 {
  if(temp->p_id==id)
  {
   cout<<"\nPatient id is "<<temp->p_id;
   cout<<"\nPatient name is "<<temp->p_name;
   cout<<"\nPatient gender is "<<temp->gender<<endl;
   f=1;
  }
 
  
  temp=temp->next;
 
 }
    }
  if(f==0)
  cout<<"Not found"<<endl;
}
void display(patient *start)
{
 temp=start;
 if(temp==NULL)
 cout<<"List is empty"<<endl;
 else
 {
  while(temp!=NULL)
 {
  cout<<"\nPatient id is "<<temp->p_id;
  cout<<"\nPatient name is "<<temp->p_name;
  cout<<"\nPatient gender is "<<temp->gender<<endl;
  temp=temp->next;
 }
 }
 
}
int main(void)
{
 int pid,n,i,choice;
 char sex,co;
 string name;
 while(1)
 {
 cout<<"1. Add n patients"<<endl;
 cout<<"2. Add a single patient"<<endl;
 cout<<"3. Delete a patient"<<endl;
 cout<<"4. Search a patient"<<endl;
 cout<<"5. Display all patients"<<endl;
 cout<<"6. Exit"<<endl;
 cout<<"\nEnter your choice";
 cin>>choice;
 
 
 switch(choice)
 {
  case 1: cout<<"Enter no. of patients"<<endl;
             cin>>n;
             cout<<"\nEnter patients details"<<endl;
             for(i=0;i<n;i++)
             {
            cout<<"Enter patient id (to be unique)"<<endl;
      cin>>pid;
      cout<<"Enter patient name"<<endl;
            cin>>name;
            cout<<"Enter patient gender"<<endl;
               cin>>sex;
            insert(pid,name,sex);
             }
    break;
     
  case 2: cout<<"\nEnter patient details"<<endl;
               cout<<"Enter patient id (to be unique)"<<endl;
      cin>>pid;
      cout<<"Enter patient name"<<endl;
            cin>>name;
            cout<<"Enter patient gender"<<endl;
               cin>>sex;
            insert(pid,name,sex);
            break;
            
     case 3: cout<<"\nEnter the pid to be deleted";
             cin>>pid;
             del(pid);       
          break;
  
  case 4:cout<<"\nEnter the pid to be searched";
            cin>>pid;
            search(pid);
      break;
      
  case 5:cout<<"\nDisplaying patients infomation.....";  
         display(start);
         break;
         
     case 6:break;      
     
     default:cout<<"\nInvalid choice";
             break;
 }
 cout<<"\n\nDo you to continue (Press Y/N)";
 cin>>co;
 if(co=='N'||co=='n')
 break;
    }
}

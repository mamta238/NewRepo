#include<stdio.h>
#include<malloc.h>

#define INPUT stdin
#define OUTPUT stdout

void create(int);
void insert(void);
void display1(void);
void display2(void);
void display3(void);
void delete(int);
int delete2(int);

typedef struct tll
{
 int info;
 struct tll *prev,*next,*big;
}
TLL;

TLL *head,*tail,*new1,*begin;



void insert()
{
 TLL  *temp;
 tail->next=new1;
 new1->prev=tail;
 tail=new1;
 tail->next=NULL;
 if(tail->info<=begin->info)
 { 
   tail->big=begin;
   begin=tail;
 }
 else
 {
  for(temp=begin;temp!=NULL;temp=temp->big)
 { 
     if(tail->info<=temp->info)
     { 
       tail->big=temp;break;
     }
    else if(tail->info>temp->info && (temp->big==NULL || temp->big->info>=tail->info))
     {
         tail->big=temp->big;
         temp->big=tail;break;
     }
       
     }
  }
}

 


void create(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	 new1=(TLL*)malloc(sizeof(TLL));
         new1->prev=new1->next=new1->big=NULL;
         printf("\nEnter info:");
         scanf("%d",&new1->info);
         if(head==NULL)
         {
	   head=tail=begin=new1;
	 }
         else
	  insert();
	 }
}

void display1(void)
 {	TLL *temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
	  fprintf(OUTPUT,"\n%d",temp->info);
	}
 } 

void display2(void)
 { 	TLL *temp;
        for(temp=tail;temp!=NULL;temp=temp->prev)
        {
          fprintf(OUTPUT,"\n%d",temp->info);
        }
 } 


void display3(void)
 {      TLL *temp;
	
	for(temp=begin;temp!=NULL;temp=temp->big)
        {
          fprintf(OUTPUT,"\n%d",temp->info);
        }
 }


void delete(int ele)
{	
	
	TLL *temp,*temp1,*temp2;
        for(temp=begin;temp!=NULL;temp=temp->big)
       {        
	     if(begin->info==ele)
         { temp1=begin;
         for(;(temp1!=NULL && temp1->info==ele);)
         {
           temp2=temp1->big;
           begin=temp2;
	     if(temp1==head && temp1==tail)
         {
          free(temp1);
          begin=head=tail=NULL;
	     }         
 
	     else if(temp1!=head && temp1!=tail)
 	    {
          temp1->prev->next=temp1->next;
	      temp1->next->prev=temp1->prev;
          free(temp1);
	    }
	     else if(temp1==head)
	     { 
	      head=head->next;
	      head->prev=NULL;
          free(temp1);
	     }
         else if(temp1==tail)
	      {
          tail=tail->prev;
          tail->next=NULL;
          free(temp1);  
	      }
           temp1=begin;}
         break;
       }
        else if(temp->big!=NULL && temp->big->info==ele)
        {
            for(temp1=temp->big;(temp1!=NULL && temp1->info==ele);)
            { 
            temp2=temp1->big;
            temp->big=temp1->big;
            if(temp1==head)
            {
             head=head->next;
             head->prev=NULL;
             free(temp1);
            }
            else if(temp1==tail)
            { tail=tail->prev;
              tail->next=NULL;
              free(temp1);
            }
            else
            {
	         temp1->prev->next=temp1->next;
	         temp1->next->prev=temp1->prev;
             free(temp1);
	        }
            temp1=temp2;
          } break;}   
        } 
}

int delete2(int pos)
{
 int i;
 TLL *temp,*temp1,*small; 
 for(i=1,temp=head;i<pos && temp!=NULL;i++,temp=temp->next);
  if(temp==NULL)
     return 1;
  else
  { 
   small=NULL;
   for(temp1=begin;temp1!=NULL;temp1=temp1->big)
  {
   if(temp1==temp)
   {
	if(temp1==begin && temp1==head && temp1==tail)
 	{
	 head=begin=tail=NULL;
 	 free(temp1);break;
	}
	else if(temp1==begin && temp1==head)
	{
	 head=head->next;
	 head->prev=NULL;
	 begin=begin->big;
	 free(temp1);break;
	}
	else if(temp1==begin && temp1==tail)
	{
	 tail=tail->prev;
	 tail->next=NULL;
	 begin=begin->big;
	 free(temp1);break;
	}
	else if(temp1==begin)
 	{
	 begin=begin->big;
	 free(temp1);break;
	}
	else if(temp1==head)
	{
	 head=head->next;
	 head->prev=NULL;
	 small->big=temp1->big;
	 free(temp1);break;
	}
	else if(temp1==tail)
 	{
	 tail=tail->prev;
	 tail->next=NULL;
	 small->big=temp1->big;
	 free(temp1);break;
	}
	else
	{
	 temp1->prev->next=temp1->next;
	 temp1->next->prev=temp1->prev;
	 small->big=temp1->big;
	}
   }
   else
   {
	small=temp1;
   } 
  }
 }
 return 0;
}

int main(void)
{
int ch,data,n,pos,res,ele;

do
{
fprintf(OUTPUT,"\n\nMENU:\n1)Create\n2)Insert\n3)Display using Next\n4)Display using Prev\n5)Display using Big\n6)Delete\n7)Delete by Position\n\nEnter Choice:");
scanf("%d",&ch);
switch(ch)
{       
case 1:	fprintf(OUTPUT,"\nEnter number of nodes:");
	    fscanf(INPUT,"%d",&n);
	    create(n);
	    break;
case 2:	fprintf(OUTPUT,"\nEnter information:");
       	fscanf(INPUT,"%d",&data);
	    new1=(TLL*)malloc(sizeof(TLL));
        new1->info=data;
	    new1->next=new1->prev=new1->big=NULL;
        if(head==NULL)
        {
       	head=tail=begin=new1;
        }
	    else
	    insert();
	    break;
case 3:	fprintf(OUTPUT,"\nDisplay using Next:\n");
		display1();
	    break;
case 4:	fprintf(OUTPUT,"\nDisplay using Prev:\n");
		display2();
	    break;
case 5:	fprintf(OUTPUT,"\nDisplay using Big:\n");
		display3();
   	    break;
case 6:	fprintf(OUTPUT,"\nEnter element to delete:");
	    fscanf(INPUT,"%d",&ele);
		delete(ele);
	    break;
case 7:	fprintf(OUTPUT,"\nPosition:");
     	fscanf(INPUT,"%d",&pos);
 		res=delete2(pos);
 		if(res==1)
 		fprintf(OUTPUT,"\nPosition out of bound.");
	    break;
}}
while(ch<=7);
return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
struct node{
char data[N];
struct node *link;
}*start;

void create();
void disp();
void count();
void ser();
void add();

void main()
{
    int ch,n,i,a,pos;
    char m[20];
    start=NULL;
    do{
        printf("\n****MENU****");
        printf("\n1.CREATE LIBRARY");
        printf("\n2.DISPLAY BOOKS");
        printf("\n3.COUNT BOOK");
        printf("\n4.SEARCH BOOK");
        printf("\n5.ADD BOOK");
        printf("\n6.EXIT");
        printf("\nENTER UR CHOICE : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :
                    printf("\n\nHOW MANY BOOKS DO U WANT TO ADD : ");
                    scanf("%d",&n); 
                    for(i=0;i<n;i++)
                    {
                        create();
                    }
                    printf("\nLibrary Created");
                    break;
            case 2:
                    disp();
                    break;
            case 3:
                    count();
                    break;
            case 4:
                    ser();
                    break;
            case 5:
                    printf("\n\nHOW MANY NEW BOOKS DO U WANT TO ADD : ");
                    scanf("%d",&n); 
                    for(i=0;i<n;i++)
                    {
                        add();
                    }
                    break;
        }
    }while(ch!=6);
}
void create()
{
    struct node *q,*tmp;
    char data[50];
    tmp=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER BOOK NAME : ");
    scanf("%s",data);
    strcpy(tmp->data,data);
    tmp->link=NULL;
    if(start==NULL)
    {
        start=tmp;
    }
    else
    {
        q=start;
        while(q->link!=NULL)
        q=q->link;
        q->link=tmp;
    }
    printf("Book Added");
}
void disp()
{
    struct node *q;
    if(start==NULL)
    {
            printf("\n\nLibrary IS EMPTY");
    }
    else
    {
        printf("Book Names : ");
        q=start;
        while(q!=NULL)
        {
            printf("\t %s\t",q->data);
            q=q->link;
        }
    }
}
void ser()
{
    struct node *q,*tmp;
    char data[20];
    q=start;
    printf("\nENTER THE BOOK NAME FOR SEARCH : ");
    scanf("%s",data);
    while(q!=NULL)
    {
        if(strcmp(q->data,data) == 0)
        {
            printf("\n%s Is Available",data);
            break;
        }
        else
        {
            q=q->link;
        }
    }
    if(q==NULL)
    {
        printf("\n%s is Not Available",data);
    }
}

void count()
{
    struct node *q;
    int cnt=0;
    q=start;
    while(q!=NULL)
    {
        cnt++;
        q=q->link;
    }
    printf("\n No Of Books Are\t %d",cnt);
}

void add()
{
    struct node *q,*tmp;
    char data[50];
    tmp=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER BOOK NAME : ");
    scanf("%s",data);
    strcpy(tmp->data,data);
    tmp->link=NULL;
    if(start==NULL)
    {
        start=tmp;
    }
    else
    {
        q=start;
        while(q->link!=NULL)
        q=q->link;
        q->link=tmp;
    }
    printf("New Book Added");
}

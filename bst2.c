#include<stdio.h>
#include<malloc.h>
struct node
{
   int info;
   int degree;
    struct node *next;
};
struct node *start=NULL;
struct node* createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return n;
};
void insert()
{
    struct node *temp;
    temp=createnode();
    printf("enter the number and degree");
    scanf("%d%d",&temp->info,&temp->degree);
    temp->next=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        struct node *t;
        t=start;
        while(t->next!=NULL)
            t=t->next;
            t->next=temp;

    }
}
void sort()
{ int r,op;
    struct node *t;
    struct node *s=NULL;
do{
    op=0;
    t=start;
    while(t->next!=s)
            {
                if(t->degree <= (t->next)->degree)
                   {r=t->degree;
                    t->degree=(t->next)->degree;
                    (t->next)->degree=r;
                    r=t->info;
                    t->info=(t->next)->info;
                    (t->next)->info=r;
                    op=1;
                   }
                   t=t->next;
            }
                   s=t;
    } while(op);

}
void display()
{
    struct node *t;
    t=start;
    while(t!=NULL)
     {printf("%dx^%d\n",t->info,t->degree);
      t=t->next;
     }
}
int main()
{int i,c;
    do{printf("1:insert\n2:sort\n3:display");
    scanf("%d",&i);
    switch(i)
    {
        case 1:insert();
            break;
        case 2:sort();
            break;
        case 3:display();
            break;
    }
    printf("\nu want operate again:");
    scanf("%d",&c);
}while(c);
return 0;
}

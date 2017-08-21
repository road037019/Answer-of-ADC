#include <stdio.h>
#include <stdlib.h>
#define NULL 0

struct node
{
	int data;
	struct node *next;
} ;

struct node *creatlist(int n)
{
	struct node *head,*p,*r;
	int i,d;
	if(n==0)
		head=NULL;
	else
	{
		r=(struct node*)malloc(sizeof(struct node));
		head=r;
		printf("\ninput data:");
		scanf("%d",&d);
		r->data=d;
		r->next=NULL;
		for(i=1;i<n;i++)
		{
			printf("\ninput data:");
			scanf("%d",&d);
			p=(struct node *)malloc(sizeof(struct node));
			p->data=d;
			r->next=p;
			//p->next=NULL;
			r=p;
			r->next=NULL;
		}
	}
	return head;
}

struct node *insert(struct node *head,int x,int y)
{
	struct node *n,*p,*q;                                                                             
	n=(struct node*)malloc(sizeof(struct node));
	n->data=y;
	if(head=NULL)
	{
		n->next=NULL;
		head=n;
	}
	else
	{
		p=head;
		while((p->next!=NULL)&&(p->data!=x))
		{
			q=p;
			p=p->next;
		}
		if(p->next==NULL)
		{
			p->next=n;
			n->next=NULL;
		}
		else
		{
			if(p==head)
			{
				n->next=p;
				head=n;	
			}
			else
			{
				q->next=n;
				n->next=p;	
			}
		
		}
	} 
	return head;
} 

struct node *delete(struct node *head,int y)
{
	struct node *p,*q;
	if(head==NULL)
	printf("This list is Null!");
	else
	{
		p=head;
		while((p->next!=NULL)&&(p->data!=y))
		{
			q=p;
			p=p->next;
		}
		if(p->data==y)
		{
			if(p==head)
			head=p->next;
			else
			q->next=p->next;
			free(p);
			printf("\nnode%d is deleted!",y);
		}
		else
		printf("\nnode%d not found!",y);
	}
	return head;
}

void print(struct node *head)
{
	struct node *p;
	if(head==NULL)
	printf("This is a NULL!");
	else
	{
		p=head;
		printf("\nhead");
		do
		{
			printf("->%d",p->data);
			p=p->next;
		}while(p!=NULL);
		printf("->end");
	}
}

int main()
{	
	struct node *head,*headd;
	head=creatlist(5);
	print(head);
	
	head=insert(head,3,6);
	print(head);
}

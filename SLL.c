#include<stdio.h>

struct node{
          int data;
	struct node *next;
}*f;

struct node * create(int size){
          
          if(size!=0){
	
	struct node *first,*q;

	int i=1,x;
	
	first=(struct node *)malloc(sizeof(struct node));
		q=first;
	printf("\nEnter Data for %d LL ",i);
	scanf("%d",&x);
	first->data=x;
	i++;
	
	while(i<=size){
		
		struct node *b=(struct node*)malloc(sizeof(struct node));
		q->next=b;
		printf("\nEnter Data for %d LL ",i);
		scanf("%d",&x);
		b->data=x;
		q=b;
		i++;
	}
	
	q->next=NULL;
	
	return first;
	
          }else{
                    f=NULL;
                    return f;
          }
}

void display(struct node *g){
          
          if(g==NULL){
                    printf("\n****** Empty Linked List!!!!! ****** ");
          }else{
	printf("\nLL DATA's' : ");
	do{
		printf(" %d",g->data);
		g=g->next;
	}while(g!=NULL);
          }
}

void deleteall(struct node *del){
          int x=0;
          struct node *temp;
          while(del!=NULL){
                    temp=del;
                    del=del->next;
                    free(temp);
                    printf("\n\n**** %d Linked List deleted ****",++x);
                    }
          if(del==NULL){
                    f=del;
                    if(f==NULL)
          printf("\n\n\n\n\n\n\n\n ****** All Linked List deleted from Memory ******\n");

          }
}

void delpos(struct node *del,int pos){
          int i=1;
          struct node *ptr,*temp=del;
          if(pos==1){
                    
                 ptr=temp;
                 temp=temp->next;
                 free(ptr);
                 f= temp;
                     
          }
          else{
          
          while(i!=pos){
                    ptr=temp;
                    temp=temp->next;
                    i++;   
          }
          ptr->next=temp->next;
          free(temp);
          }
}

void insert(struct node * st,int data,int pos){
          
          int i=1;
          struct node *ptr,*temp=st;
          struct node *n=(struct node*)malloc(sizeof(struct node));
          if(pos==1){
                    
          
                  n->data=data;
                  n->next=f;  
                  f= n;
                     
          }
          else{
          
          while(i!=pos){
                    ptr=temp;
                    temp=temp->next;
                    i++;   
          }
          n->next=temp;
          ptr->next=n;
          n->data=data;
          }
}

int main(){
          
          int x=0;
	
	printf("Enter the Size of Linked List\n");
	
	scanf("%d",&x);
	
	if(x!=0){
	
	f=create(x);
	
	display(f);
	
	int pos;
	
	printf("\n\nEnter the position for deletion (1-%d) \n",x);
	
	scanf("%d",&pos);
	
	if(pos<=x && pos>0){
	          delpos(f,pos);
	          printf("\n\nLL after deletion ");
	          display(f);
	}else
	printf("\n!!!!!!!! Position Error !!!!!!!!\n  \n*** deletion Canceled ***");

	int idata,ipos;
          
          printf("\n\nEnter Data for insertion \n");
	scanf("%d",&idata);
	printf("\n\nEnter the position  for Given Data \n");
	scanf("%d",&ipos);


          if(ipos<=x && ipos>0){
	          insert(f,idata,ipos);
	          printf("\n\nLL After Insertion ");
	          display(f);
	}else
	printf("\n!!!!!!!! Position Error !!!!!!!!\n  \n*** Insertion Canceled ***");
          
          deleteall(f);
	display(f);
	}
          else{
                    printf(" \nYou Cannot Create Linked list Size of 0 ");
          }
	
          return 0;
	
}

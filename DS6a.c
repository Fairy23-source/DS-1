#include<stdio.h>
struct node{
int info;
struct node*next;
};
struct node*first=NULL;

struct node*create_node(int x){
struct node*t;
t=(struct node*)malloc(sizeof(struct node));
t->info=x;
t->next=NULL;
return t;
}

void insert_first(){
int x;
struct node*t;
printf("Enter value: ");
scanf("%d",&x);
t=create_node(x);
if(first==NULL)
first=t;
else{
t->next=first;
first=t;
}
}

void insert_last(){
int x;
struct node*t,*temp;
printf("Enter value: ");
scanf("%d",&x);
t=create_node(x);
if(first==NULL)
first=t;
else{
temp=first;
while(temp->next!=NULL)
temp=temp->next;
temp->next=t;
}
}

void insert_any(){
int x,pos,i;
struct node*t,*temp;
printf("Enter value: ");
scanf("%d",&x);
printf("Enter position: ");
scanf("%d",&pos);
t=create_node(x);
if(pos==1){
t->next=first;
first=t;
return;
}
temp=first;
for(i=1;i<pos-1&&temp!=NULL;i++)
temp=temp->next;
if(temp==NULL){
printf("Invalid position\n");
free(t);
return;
}
t->next=temp->next;
temp->next=t;
}

void display(){
struct node*temp;
if(first==NULL){
printf("Linked List is empty\n");
return;
}
temp=first;
while(temp!=NULL){
printf("%d->",temp->info);
temp=temp->next;
}
printf("NULL\n");
}

int main(){
int choice;
while(1){
printf("\n1.Insert First\n2.Insert Last\n3.Insert Any\n4.Display\n5.Exit\n");
printf("Enter choice: ");
scanf("%d",&choice);
switch(choice){
case 1:
insert_first();
break;
case 2:
insert_last();
break;
case 3:
insert_any();
break;
case 4:
display();
break;
case 5:
return 0;
default:
printf("Invalid choice\n");
}
}
}

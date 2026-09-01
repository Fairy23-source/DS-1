#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *next;
};

struct node *first=NULL;

struct node *create_node(int x){
struct node *t;
t=(struct node*)malloc(sizeof(struct node));
t->info=x;
t->next=NULL;
return t;
}

void insert_first(){
int x;
struct node *t;
printf("Enter value: ");
scanf("%d",&x);
t=create_node(x);
t->next=first;
first=t;
}

void insert_last(){
int x;
struct node *t,*temp;
printf("Enter value: ");
scanf("%d",&x);
t=create_node(x);
if(first==NULL){
first=t;
return;
}
temp=first;
while(temp->next!=NULL)
temp=temp->next;
temp->next=t;
}

void insert_any(){
int x,pos,i;
struct node *t,*temp;
printf("Enter value: ");
scanf("%d",&x);
printf("Enter position: ");
scanf("%d",&pos);
if(pos<1){
printf("Invalid position\n");
return;
}
if(pos==1){
insert_first();
return;
}
temp=first;
for(i=1;i<pos-1&&temp!=NULL;i++)
temp=temp->next;
if(temp==NULL){
printf("Invalid position\n");
return;
}
t=create_node(x);
t->next=temp->next;
temp->next=t;
}

void delete_first(){
struct node *temp;
if(first==NULL){
printf("Linked List is empty\n");
return;
}
temp=first;
first=first->next;
free(temp);
}

void delete_last(){
struct node *temp,*prev;
if(first==NULL){
printf("Linked List is empty\n");
return;
}
if(first->next==NULL){
free(first);
first=NULL;
return;
}
temp=first;
while(temp->next!=NULL){
prev=temp;
temp=temp->next;
}
prev->next=NULL;
free(temp);
}

void delete_any(){
int pos,i;
struct node *temp,*prev;
if(first==NULL){
printf("Linked List is empty\n");
return;
}
printf("Enter position: ");
scanf("%d",&pos);
if(pos<1){
printf("Invalid position\n");
return;
}
if(pos==1){
delete_first();
return;
}
temp=first;
for(i=1;i<pos&&temp!=NULL;i++){
prev=temp;
temp=temp->next;
}
if(temp==NULL){
printf("Invalid position\n");
return;
}
prev->next=temp->next;
free(temp);
}

void display(){
struct node *temp;
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
printf("\n1.Insert First\n2.Insert Last\n3.Insert Any\n4.Delete First\n5.Delete Last\n6.Delete Any\n7.Display\n8.Exit\n");
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
delete_first();
break;
case 5:
delete_last();
break;
case 6:
delete_any();
break;
case 7:
display();
break;
case 8:
return 0;
default:
printf("Invalid choice\n");
}
}
}

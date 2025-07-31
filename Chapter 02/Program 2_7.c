#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 10
int queue[MAX], int front = -1, rear = -1;
int main(){
int option, val;
do{
printf(“\n\n ***** MAIN MENU *****\n1. Insert \n2. Delete \n3. Peek \n3. Display \n5. Exit”);
printf(“\n Enter your option : “);
scanf(“%d”, &option);
switch(option)
{	case 1:   insert();
break;
case 2:   val = delete_element();
if (val != -1)
printf(“\n The number deleted is : %d”, val);
break;
case 3:   val = peek();
if (val != -1)
printf(“\n The first value in queue is : %d”, val);
break;
case 4:   display();
break;
}
}while(option != 5);
return 0;
}
void insert(){
int num;
printf(“\n Enter the number to be inserted in the queue: “);
scanf(“%d”, &num);
if(rear == MAX-1)
printf(“\n OVERFLOW”);
else if(front == -1 && rear == -1)
front = rear = 0;
else
rear++;
queue[rear] = num;
}
int delete_element(){
int val;
if(front == -1 || front>rear){
printf(“\n UNDERFLOW”);
return -1;
}
else{
val = queue[front];
front++;
if(front > rear)
front = rear = -1;
return val;
}
}
int peek(){
if(front==-1 || front>rear){
printf(“\n QUEUE IS EMPTY”);
return -1;
}
else
return queue[front];
}
void display(){
int i;
printf(“\n”);
if(front == -1 || front > rear)
printf(“\n QUEUE IS EMPTY”);
else{
for(i = front;i <= rear;i++)
printf(“\t %d”, queue[i]);
}
}

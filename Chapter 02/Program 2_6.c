#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 3 // Altering this value changes size of stack created
int st[MAX], top=-1;
int main(int argc, char *argv[]) {
int val, option;
do
{
printf (“\n *****MAIN MENU*****\n 1. PUSH \n 2. POP \n 3. PEEK \n 4. DISPLAY\n 5. EXIT “);
printf("\n Enter your option: ");
scanf("%d", &option);
switch(option)
{
case 1: printf("\n Enter the number to be pushed on stack: ");
scanf("%d", &val);
push(st, val);
break;
case 2: val = pop(st);
if(val != -1)
printf("\n The value deleted from stack is: %d", val);
break;
case 3: val = peek(st);
if(val != -1)
printf("\n Value stored at top of stack is: %d", val);
break;
case 4: display(st);
break;
} while(option != 5);
return 0;
}
void push(int st[], int val){
if(top == MAX-1)
printf("\n STACK OVERFLOW");
else{
top++;
st[top] = val;
}
}
int pop(int st[]){
int val;
if(top == -1){
printf("\n STACK UNDERFLOW");
return -1;
}
else{
val = st[top];
top--;
return val;
}
}
void display(int st[]){
int i;
if(top == -1)
printf("\n STACK IS EMPTY");
else
{
for(i=top;i>=0;i--)
printf("\n %d",st[i]);
printf("\n"); // Added for formatting purposes
}
}
int peek(int st[])
{
if(top == -1)
{
printf("\n STACK IS EMPTY");
return -1;
}
else
return (st[top]);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
   int data;
   struct Node* next;
};
struct Node *newNode(int key){
   struct Node *val = (struct Node*)malloc(sizeof(struct Node));;
   val-> data= key;
   val->next = NULL;
   return val;
}
bool sublist_search(struct Node* list_ptr, struct Node* sub_ptr){
   struct Node* ptr1 = list_ptr, *ptr2 = sub_ptr;
   if (list_ptr == NULL && sub_ptr == NULL)
      return true;
   if ( sub_ptr == NULL || (sub_ptr != NULL && list_ptr == NULL))
      return false;
   while (list_ptr != NULL) {
      ptr1 = list_ptr;
      while (ptr2 != NULL) {
         if (ptr1 == NULL)
            return false;
         else if (ptr2->data == ptr1->data) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
         } else
            break;
      }
      if (ptr2 == NULL)
         return true;
      ptr2 = sub_ptr;
      list_ptr = list_ptr->next;
   }
   return false;
}
int main(){
   struct Node *list = newNode(2);
   list->next = newNode(5);
   list->next->next = newNode(3);
   list->next->next->next = newNode(3);
   list->next->next->next->next = newNode(6);
   list->next->next->next->next->next = newNode(7);
   list->next->next->next->next->next->next = newNode(0);
   struct Node *sub_list = newNode(3);
   sub_list->next = newNode(6);
   sub_list->next->next = newNode(7);
   bool res = sublist_search(list, sub_list);
   if (res)
      printf("Is the sublist present in the list? %d" , res);
}

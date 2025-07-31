#include <stdio.h>
int min(int, int);
int fibonacci_search(int[], int, int);
int min(int a, int b){
    return (a > b) ? b : a;
}
int fibonacci_search(int arr[], int n, int key){
    int offset = -1;
    int Fm2 = 0;
    int Fm1 = 1;
    int Fm = Fm2 + Fm1;
    while (Fm < n) {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm2 + Fm1;
    }
    while (Fm > 1) {
        int i = min(offset + Fm2, n - 1);
        if (arr[i] < key) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        } else if (arr[i] > key) {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        } else
            return i;
    }
    if (Fm1 && arr[offset + 1] == key)
        return offset + 1;
    return -1;
}
int main(){
   int i, n, key, pos;
   int arr[10] = {6, 11, 19, 24, 33, 54, 67, 81, 94, 99};
   printf("Array elements are: ");
   int len = sizeof(arr) / sizeof(arr[0]);
   for(int j = 0; j<len; j++){
      printf("%d ", arr[j]);
   }
   n = 10;
   key = 67;
   printf("\nThe element to be searched: %d", key);
   pos = fibonacci_search(arr, n, key);
    if(pos >= 0)
        printf("\nThe element is found at index %d", pos);
    else
        printf("\nUnsuccessful Search");
}

#include <stdio.h>
#include "isort.h"
#define LEN 50

void shift_element(int* arr, int i){
    for(int j=1; j<=i; j++){
        swap(arr, (arr+j));
    }
}

void swap(int* p, int* z){
    int tmp= *p;
    *p= *z;
    *z= tmp;
}

void insertion_sort(int* arr, int len) {
    int counter;
    for (int j = 1; j < len; j++) {
        counter = 0;
        int* tmp;
        for (int i = j - 1; i >= 0; i--) {
            if (*(arr + i) > *(arr + j)) {
                tmp = ((arr +i)) ;
                counter++;
            }
        }
        if(counter > 0) {
            shift_element(tmp, counter);
        }
    }
}


int main(){

    printf("Please enter 50 integers: \n");
    int arr[LEN];
    for (int i= 0; i < LEN ; i++) {
        scanf("%d",&arr[i]);
    }

    insertion_sort(arr,LEN);
    for(int j=0; j<LEN; j++){
        printf("%d",arr[j]);
        if (j<LEN-1) printf(",");
    }
    
    printf("\n");
    return 0;
}

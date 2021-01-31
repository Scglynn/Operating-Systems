#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int Compare(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}
void sort(const char* arr[], int n) {
    qsort(arr,n,sizeof(const char*), Compare);
}

int main() {
    const char* arr[] = {"zzzz","abradacabra","kazamm","POW!","Zap!","bibbity bobbity boo","Bam!"};
    
    //(sizeof(arr))the number of bytes the array will occupy; sizeof(arr[0])size of one element; 
    //this will give the total number of elements

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The array given: \n");

    for (int i = 0; i < n; i++)
        printf("%s \n",arr[i]);

    sort(arr, n);


    printf("The array new: \n");
    for (int i = 0; i < n; i++)
        printf("%s \n",arr[i]);

    return 0;
    
}
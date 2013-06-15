#include <stdio.h>

typedef unsigned long long int ulli;

ulli mod = 1000000007;

int partition(ulli a[], int first, int last)
{

    int pIndex = (first+last)/2;
    ulli p = a[pIndex];//pivot

    int sIndex = first; //stores the location of current smallest index placed at right position
    int currIndex = first;
    ulli temp = a[last];
    a[last] = p;
    a[pIndex] = temp;
    int i;

    while(currIndex <= last)
    {

        if(a[currIndex] <= p)
        {

            temp = a[currIndex];
            a[currIndex] = a[sIndex];
            a[sIndex] = temp;
            sIndex++;

        }
        currIndex++;

    }
    return --sIndex;

}

int main(void){
    ulli a[] = {3,512,1,8,4,9,90,12,2,529,86,799};
    int start = 3;
    int last = 10;
    int pIndex = partition(a,start,last);
    int i;
    printf("pIndex is %d and Pivot is %d\n\n", pIndex, a[pIndex]);
    for (i = start; i<=last;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

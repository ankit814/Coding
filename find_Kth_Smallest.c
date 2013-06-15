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

int main(void)
{
    ulli a[] = {4,3,8,7,6,9,11,10,31};
    int len = 9;
    int start = 0;
    int last = len-1;
    int pIndex;
    int k = len/2+1;

    while(1)
    {
        pIndex = partition(a,start,last);
        if(pIndex == k-1)
        {
            printf("%dth small is %d",k,a[pIndex]);
            break;
        }
        else if(pIndex > k-1)
        {
            last = pIndex-1;
        }
        else
        {
            start = pIndex + 1;
        }

    }
    return 0;
}
//http://42bits.wordpress.com/2010/04/17/find-kth-minimum-in-a-unsorted-array/

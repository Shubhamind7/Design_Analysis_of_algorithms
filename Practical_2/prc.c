#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int binarySearch_recursive(int *a,int l,int h,int e);
int binarySearch_non_recursive(int *arr, int l, int r, int x);
int main()
{
    int a[50],n,x,result;
    clock_t t1,t2;
    printf("enter number of elements :- ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%n;
        //printf("%d\n",a[i]);
    }
    printf("enter element to be found :- ");
    scanf("%d",&x);
    t1=clock();
    result = binarySearch_recursive(a, 0, n-1, x);
    t1=clock()-t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("result of recursive binary search :-\n");
    (result == -1)? printf("Element is not present in array\n")
    : printf("Element is present at index %d\n", result);

    t2=clock();
    result = binarySearch_non_recursive(a, 0, n-1, x);
    t2=clock()-t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("result of non-recursive binary search :-\n");
    (result == -1)? printf("Element is not present in array\n")
    : printf("Element is present at index %d\n", result);

    printf("\nrecursive binary search took %f seconds to execute \n", time_taken1);
    printf("non-recursive binary search took %f seconds to execute \n", time_taken2);
    return 0;
    }

int binarySearch_recursive(int *a,int l,int h,int e)
{
    int mid,high;
    high=h;
    mid=(l+h)/2;
    if(mid==0 || mid==high)
    {
        if(mid!=e)
        {
            return -1;
        }
    }
    else
    {
        if(a[mid]==e)
        {
        return mid;
        }
        else if(a[mid]<e)
        {
            l=mid+1;
            binarySearch_recursive(a,l,h,e);
        }
        else
        {
            h=mid-1;
            binarySearch_recursive(a,l,h,e);
        }
        
    }
}
int binarySearch_non_recursive(int *arr, int l, int r, int x)
{
    
    while (l <= r)
    {
    
        int m = l + (r-l)/2;
        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}





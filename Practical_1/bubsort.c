#include <stdio.h>
#include<time.h>
#define n 10000
int main()
{
    int a[n],i,j,temp,time_t,n1;
    //t1,t2,t;
    int t1,t2;
    //n=sizeof(a)/sizeof(a[0]);
    //printf("N:%d",n);

    srand(time(0));
    //Assigning the values to array
    for(i=0;i<n;i++)
    {
        a[i]=rand()%n;
    }

    t1=time(NULL);
    //Bubble Sort
    n1=n;
    i=j=0;
    while(i<(n1-1))
    {
        //i=k;
        j=i+1;
        while(j<n1)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            i=i+1;
            j=j+1;
        }
        n1=n1-1;
        i=0;
        //printf("K:%d\n",k);

    }
    t2=time(NULL);
    //printf("\n");
    //printf("Selection Sort:\n");
    /*for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }*/
    printf("T1:%d T2:%d",t1,t2);
    printf("\n");
    printf("Time Difference:%d",(t2-t1));
    return 0;
}

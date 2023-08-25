#include <stdio.h>
#include<time.h>
#define n 100000
int main()
{
    int a[n],i,j,temp,time_t;
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


    //Selection Sorting
    t1=time(NULL);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
           if(a[i]>a[j])
           {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
           }
        }
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

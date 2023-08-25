#include<stdio.h>
#include<math.h>
#include<time.h>
void queen(int row, int p);
FILE *fptr;
int chess[8],count=1;
int main()
{
     srand(time(NULL));
     int p = 8;
     //FILE *fptr;
     // use appropriate location if you are using MacOS or Linux
     fptr = fopen("D:\\Shubhamclassroom\\6th_Sem\\DAA_LAB\\prc7\\program.txt","w");
     if(fptr == NULL)
     {
         printf("Error!");
         exit(1);
     }
     clock_t start = clock();
     queen(1,p);
     clock_t end = clock();
     double timeTaken = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the time taken
     printf("Time taken: %f seconds\n",timeTaken);
     fprintf(fptr,"\n\n\nThere are total %d solutions for 8-queens problem.",count-1);
     fclose(fptr);
     return 0;
}
void print(int p)
{
     int i,j;
     //count=0;
     fprintf(fptr,"\nThis is Solution no. %d:\n",count);
     for(i=1;i<=p;++i)
         fprintf(fptr,"\t%d",i);

     for(i=1;i<=p;++i){
          fprintf(fptr,"\n\n%d",i);
          for(j=1;j<=p;++j){
               if(chess[i]==j)
                    fprintf(fptr,"\tQ");
               else
                    fprintf(fptr,"\t-");
          }
     }
     count=count+1;
     printf("\n");
}
int place(int row,int column)
{
     int i;
     for(i=1;i<=row-1;++i)
     {
          if(chess[i]==column)
               return 0;
          else
           if(abs(chess[i]-column)==abs(i-row))
                return 0;
     }

     return 1;
}

void queen(int row,int p)
{
     int column;
     for(column=1;column<=p;++column)
     {
          if(place(row,column))
          {
               chess[row]=column;
               if(row==p)
                    print(p);
               else
                    queen(row+1,p);
          }
     }
}

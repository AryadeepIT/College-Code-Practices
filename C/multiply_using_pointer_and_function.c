
#include <stdio.h>
#include <stdlib.h>
int *a,*b,*c,i,j,k,r1,c1,r2,c2,s[20][20];
void input(int*,int,int);
void multiply(void);
void display(int*,int,int);
int main()
    {
        printf("Enter the number of rows and columns of the first matrix: \n");
        scanf("%d %d",&r1,&c1);
        printf("Enter the number of rows and columns of the second matrix: \n");
        scanf("%d %d",&r2,&c2);
        if(c1!=r2)
            printf("\nThe matrices of the given dimensions are not multipliable..!!\n");
        else
            {
                a=(int*)(malloc((r1*c1)*sizeof(int)));
                b=(int*)(malloc((r2*c2)*sizeof(int)));
                c=(int*)(malloc((r1*c2)*sizeof(int)));
                if(a==NULL||b==NULL||c==NULL)
                 {
                     printf("Memory not allocated..!!");
                     exit(0);
                 }
                printf("Enter the elements of the first matrix: \n");
                input(a,r1,c1);
                printf("Enter the elements of the second matrix: \n");
                input(b,r2,c2);
                multiply();
                printf("The Third Matrix: \n");
                display(c,r1,c2);
            }
        free(a);
        free(b);
        free(c);
        return 0;
    }

void input(int *ar,int r,int c)
    {
        for(i=0;i<r;i++)
        {
           printf("Enter the elements of row %d: ",i+1);
           for(j=0;j<c;j++)
                scanf("%d",(ar+(i*c1)+j));
        }
        printf("\n");
        for(i=0;i<r;i++)
        {
           for(j=0;j<c;j++)
                printf("%d ",*(ar+(i*c1)+j));
            printf("\n");
        }
        printf("\n");
    }

void multiply()
    {
        int x,y;
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                //*(c+(i*c2)+j)=0;
                x=*((a+(i*c1)+j));
                y=*((b+(i*c2)+j));
                    s[i][j]=x*y;
            }
        }
    }

void display(int *a,int r,int c)
    {
        for(i=0;i<r;i++)
        {
           for(j=0;j<c;j++)
                printf("%d ",s[i][j]);
           printf("\n");
        }
    }

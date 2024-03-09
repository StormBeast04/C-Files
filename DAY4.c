#include <stdio.h>
#include <math.h>
#define iter=1000
void aug_mat(float mat[10][10],int n)
{
    int i,j;
    printf("Enter the Values of the Augmented matrix:\n");
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
        {
            if (j==n)
            {
                printf("b%d= ",i+1);
                scanf("%f",&mat[i][j]);
            }
            else
            {
                printf("x%d= ",j+1);
                scanf("%f",&mat[i][j]);
            }
        }
}
void display(float mat[10][10],int n)
{
    int i,j;
    printf("The Augmented Matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<=n;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
}
void gauss_seidal(float mat[10][10],float x[10],int n)
{
    int i,j,f=1,k,iter;
    float sum,flag[10];
    double t,error;
    printf("Enter the Tolerance level: ");
    scanf("%lf",&t);
    for (k=0;k<iter;k++)
    {
        error=0.0;
        for (i=0;i<n;i++)
        {
            sum=0.0;
            flag[i]=x[i];
            for (j=0;j<n;j++)
            {
                if (j!=i)
                    sum=sum+(x[j]*mat[i][j]);
            }
            x[i]=(mat[i][n]-sum)/mat[i][i];
            error=error+(fabs(x[i]-flag[i]));
        }
        if (error<t)
            break;
    }
    for (i=0;i<n;i++)
    {
        printf("x%d= %f",i+1,x[i]);
        printf("\n");
    }
}
int main()
{
    float mat[10][10],x[10];
    int n,i;
    printf("Enter the No. of unknowns: ");
    scanf("%d",&n);
    aug_mat(mat,n);
    display(mat,n);
    for (i=0;i<n;i++)
        x[i]=0.0;
    gauss_seidal(mat,x,n);
    return 0;
}

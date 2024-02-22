#include <stdio.h>
int main()
{
    float mat1[20][20],d,x[20],sum,m;
    int n,i,j,k;
    printf("Enter the no. of variables in the system of equations: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Row %d:\n",i+1);
        for (j=0;j<n+1;j++)
        {
            printf("Column %d:",j+1);
            scanf("%f",&mat1[i][j]);
        }
    }
    printf("The Augmented matrix is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n+1;j++)
            printf("%.2f\t",mat1[i][j]);
        printf("\n");
    }
    for (k=0;k<n-1;k++)
        for (i=k+1;i<=n;i++)
        {
            d=mat1[i][k]/mat1[k][k];
            for (j=0;j<n+1;j++)
                mat1[i][j]=mat1[i][j]-(d*mat1[k][j]);
        }
    printf("The Row reduced matrix is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<n+1;j++)
            printf("%.2f\t",mat1[i][j]);
        printf("\n");
    }
    for (i=n-1;i>=0;i--)
    {
        x[i]=mat1[i][n];
        for (j=i+1;j<n;j++)
            x[i]-=mat1[i][j]*x[j];
        x[i]/=mat1[i][i];
    }
    for (i=0;i<n;i++)
        printf("x%d=%.2f\t",i+1,x[i]);
    printf("\n");
    return 0;
}

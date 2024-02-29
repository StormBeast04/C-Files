#include<stdio.h>
int fact(int n)
{
    if (n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}
float pattern(float u,int n)
{
    int i;
    float prod=1;
    for (i=0;i<n;i++)
    {
        prod=prod*u;
        u=u-1;
    }
    return prod;
}
int main()
{
    float mat[20][20],sum,u,h,a;
    int i,j,n;
    printf("Enter the No of data sets: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
        for (j=0;j<2;j++)
        {
            if (j==0)
            {
                printf("x%d= ",i);
                scanf("%f",&mat[i][j]);
            }
            if (j==1)
            {
                printf("f(x%d)= ",i);
                scanf("%f",&mat[i][j]);
            }
        }
    for (j=2;j<n+1;j++)
        for (i=0;i<(n+1)-j;i++)
        {
            mat[i][j]=mat[i+1][j-1]-mat[i][j-1];
        }
    printf("The Forward Difference Table is:\n");
    for (i=0;i<n;i++)
    {
        for (j=0;j<=n-i;j++)
            printf("%.2f\t",mat[i][j]);
        printf("\n");
    }
    printf("Enter the value of Interpolating point: ");
    scanf("%f",&a);
    h=(mat[1][0]-mat[0][0]);
    u=(a-mat[0][0])/h;
    sum=mat[0][1];
    for (i=2;i<n;i++)
        sum=sum+((pattern(u,i-1)*mat[0][i])/fact(i-1));
    printf("f(%.2f)=%.2f\n",a,sum);
    return 0;
}

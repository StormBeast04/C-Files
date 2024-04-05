#include<stdio.h>
float func(float x)
{
    return (1/x);
}
int main()
{
    float a,b,n,h,fx=0;
    int i;
    printf("Enter the Lower Limit of the given function: ");
    scanf("%f",&a);
    printf("Enter the Upper Limit of the given function: ");
    scanf("%f",&b);
    printf("Enter the no. of steps: ");
    scanf("%f",&n);
    h=(b-a)/n;
    for (i=0;i<=n;i++)
    {
        if (i==0 || i==n)
            fx=fx+func(a+(i*h));
        else
            fx=fx+2*func(a+(i*h));
    }
    fx=(h*fx)/2;
    printf("f(x)= %f\n",fx);
    return 0;
}

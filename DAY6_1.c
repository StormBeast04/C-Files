#include<stdio.h>
float func(float x)
{
    return (1/x);
}
int main()
{
    float a,b,h,n,oddsum=0,evensum=0,fx;
    int i;
    printf("Enter the Lower and Upper limits of the given function: ");
    scanf("%f%f",&a,&b);
    printf("Enter the No. of intervals: ");
    scanf("%f",&n);
    h=(b-a)/n;
    for (i=1;i<n;i++)
    {
        if ((i%2!=0))
            oddsum+=func(a+(i*h));
        else
            evensum+=func(a+(i*h));
    }
    fx=(h/3)*((func(a)+func(b))+(4*oddsum)+(2*evensum));
    printf("f(x)= %f",fx);
    return 0;
}

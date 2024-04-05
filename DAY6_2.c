#include<stdio.h>
float func(float x0,float y0)
{
    return x0*y0;
}
int main()
{
    float x0,y0,y,h,xn,n;
    int flag=0;
    printf("Enter the value of x0: ");
    scanf("%f",&x0);
    printf("Enter the value of y0: ");
    scanf("%f",&y0);
    printf("Enter the step size: ");
    scanf("%f",&h);
    printf("Enter the value of x in f(x): ");
    scanf("%f",&xn);
    n=(xn-x0)/h;
    while (flag<n)
    {
        y=y0+(h*func(x0,y0));
        x0=x0+h;
        y0=y;
        flag++;
    }
    printf("The value of y at %.3f= %.4f\n",x0,y);
    return 0;
}

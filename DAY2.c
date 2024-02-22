#include<stdio.h>
int main()
{
	float x[20],y[20],sum=0,a=1.0,b=1.0,X,s=0;
	int n,i,j;
	printf("Enter the No of Data Sets: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("x%d= ",i);
		scanf("%f",&x[i]);
		printf("f(x%d)= ",i);
		scanf("%f",&y[i]);
	}
	printf("Enter the Value of the interpolated point: ");
	scanf("%f",&X);
	for (i=0;i<n;i++)
	{
		sum=0;
		a=1;
		b=1;
		for (j=0;j<n;j++)
		{
			if(j!=i)
			{
				a*=(X-x[j]);
				b*=(x[i]-x[j]);
			}
		}
		s+=sum+((a/b)*y[i]);
	}
	printf("f(%.2f)= %.2f",X,s);
	printf("\n");
	return 0;
}

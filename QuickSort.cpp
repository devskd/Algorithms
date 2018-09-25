#include<stdio.h>
int partition(int *a,int p,int r)
{
	int x=a[r];
	int i=p-1;
	int temp;
	for(int j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
void quicksort(int *a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int main()
{
	int n,a[20];
	printf("Enter the number of elements :");
	scanf("%d",&n);
	printf("Enter the elements :");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	return 0;
}

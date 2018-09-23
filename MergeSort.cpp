#include<stdio.h>
int temp[20],k;
void merge(int *a,int s,int e)
{
	int mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	int temp[10000];
	while(i<=mid && j<=e)
		{
			if(a[i]<a[j])
				temp[k++]=a[i++];
			else
				temp[k++]=a[j++];
		}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=e)
		temp[k++]=a[j++];
	for(i=s;i<=e;i++)
		a[i]=temp[i];
}
void mergeSort(int a[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid=(l+h)/2;
		mergeSort(a,l,mid);
		mergeSort(a,mid+1,h);
		merge(a,l,h);
	}
}
int main()
{
	int a[20],n;
	printf("Enter the size of the array :");
	scanf("%d",&n);
	printf("Enter the array elements :\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}	
	mergeSort(a,0,n-1);
	printf("After sorting :\n");
	for(int i =0;i<n;i++)
		printf("%d\n",a[i]);
	return 0;
}

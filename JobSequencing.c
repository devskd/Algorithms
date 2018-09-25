#include<stdio.h>
struct job
{
	int jid;
	int jd;
	int jp;
};
int n,max,k,profit=0;
struct job jv[10];
void jobin()
{
	int i;
	printf("Enter the number of Jobs :");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		jv[i].jid=i;
		printf("Enter the profit : \n");
		scanf("%d",&jv[i].jp);
		printf("Enter the deadline : \n");
		scanf("%d",&jv[i].jd);		
	}
}
int sort()
{
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(jv[j].jp<=jv[j+1].jp)
			{
				temp=jv[j].jp;
				jv[j].jp=jv[j+1].jp;
				jv[j+1].jp=temp;
				
				temp=jv[j].jd;
				jv[j].jd=jv[j+1].jd;
				jv[j+1].jd=temp;
				
				temp=jv[j].jid;
				jv[j].jid=jv[j+1].jid;
				jv[j+1].jid=temp;
			}
		}
	}
	max=jv[1].jd;
	for(i=2;i<=n;i++)
	{
		if(max<=jv[i].jd)
			max=jv[i].jd;
	}
	return max;
}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\n",jv[i].jid,jv[i].jp,jv[i].jd);
	}
}
void js()
{
	int slot[10],i,j,result[10];
	for(i=1;i<=n;i++)
		slot[i]=0;
	for(i=1;i<=n;i++)
	{
		k=(max>=jv[i].jd?jv[i].jd:max);
		for(j=k;j>=1;j--)
		{
			if(slot[j]==0)
			{
				profit=profit+jv[i].jp;
				slot[j]=1;
				printf("%d\n",jv[i].jid);
				break;
			}
		}
	}
	printf("Total profit : %d",profit);
	
}
int main()
{
	jobin();
	max=sort();
	display();
	js();
	return 0;
}

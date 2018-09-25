#include<stdio.h>
#include<limits.h>
int n,time=0;
int a[20][20];
int color[20],p[20],d[20],q[20];
int f=0;
int r=-1;
void makegraph()
{
	FILE *fp;
	fp=fopen("abc.txt","r");
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fscanf(fp,"%d",&a[i][j]);
		}
	}
}
void showgraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void bfs(int s)
{
	int u;
	for(int i=0;i<n;i++)
	{
		color[i]=0;
		d[i]=9999;
		p[i]=-1;
	}
	d[s]=0;
	color[s]=1;
	p[s]=-1;
	q[++r]=s;
	while(r>=f)
	{
		u=q[f++];
		for(int v=0;v<n;v++)
		{
			if(a[u][v]==1 && color[v]==0)
			{
				color[v]=1;
				d[v]=d[u]+1;
				p[v]=u;
				q[++r]=v;
			}
			
		}
		color[u]=2;
	}
	
}
void output1()
{
	printf("White =0, Gray=1, Black=2\n");
	for(int i=0;i<n;i++)
		printf("%d\t",color[i]);
	printf("\n");
	printf("Parent\n");	
	for(int i=0;i<n;i++)
		printf("%d\t",p[i]);
	printf("\n");
	printf("Initial Time.");
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d\t",d[i]);
	printf("\n");
	printf("BFS Tree.");
	printf("\n");

	for(int i=0;i<n;i++)
	{
		if(p[i]!=-1)
			printf("%c->%c\t",p[i]+82,i+82);
	}
	printf("\n");
}
int main()
{
	makegraph();
	showgraph();
	bfs(1);
	output1();
	return 0;
}











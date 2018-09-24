#include<stdio.h>
int n,time=0;
int a[20][20];
int color[20],p[20],d[20],f[20];
void makegraph()
{
	FILE *fp;
	fp=fopen("b.txt","r");
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
void dfs_visit(int u)
{
	time =time+1;
	d[u]=time;
	color[u]=1;
	for(int v=0;v<n;v++)
	{
		if(a[u][v]==1 && color[v]==0)
		{
			p[v]=u;
			dfs_visit(v);
		}
	}
	color[u]=2;
	time=time+1;
	f[u]=time;
}
void dfs()
{
	for(int i=0;i<n;i++)
	{
		color[i]=0;
		p[i]=-1;
		d[i]=0;
		f[i]=0;
	}
	time=0;
	for(int i=0;i<n;i++)
	{
		if(color[i]==0)
			dfs_visit(i);
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
	printf("Final Time.");
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d\t",f[i]);
	printf("\n");
	printf("DFS Tree.");
	printf("\n");

	for(int i=0;i<n;i++)
	{
		if(i!=0 && p[i]!=-1)
			printf("%c->%c\t",p[i]+85,i+85);
	}
	printf("\n");
}
int main()
{
	makegraph();
	showgraph();
	dfs();
	output1();
	return 0;
}











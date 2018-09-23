#include<stdio.h>
double p[10],w[10];
double r[10];
int n,m,tp=0;
void userin()
{
    printf("Enter the number of objects :");
    scanf("%d",&n);
    printf("Enter the total capacity of the Knapsack :");
    scanf("%d",&m);
    for(int i=0;i<n;i++)
    {
        printf("Enter the weight of the object %d :",i+1);
        scanf("%lf",&w[i]);
        printf("Enter the profit of the object %d:",i+1);
        scanf("%lf",&p[i]);
        r[i]=(p[i]/w[i]);        
        
    }
}
void sort()
{
    double temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(r[j]<r[j+1])
            {
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
                
            }
        }
    }
}
void kout()
{
    for(int i=0;i<n;i++)
    {
        printf("%lf\n",r[i]);
    }
}
double knapsack()
{
    int i;
    for(i=0;i<n;i++)
    {
        if(m>0 && w[i]<=m)
        {
            m=m-w[i];
            tp=tp+p[i];
        }
        else
        {
            break;
        }
    }
    if(m>0)
    {
     tp=tp+(p[i]/w[i])*m;  
    }
    return tp;
}
int main()
{
    userin();
    sort();
    kout();
    double s=knapsack();
    printf("Total profit is %lf.",s); 
    return 0;
}

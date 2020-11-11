#include<stdio.h>
int main()
{
int p,i,st[10],ft[10],bt[10];
float sum=0.0,avg,s=0.0,a;
printf("enter the no of processes\n");
scanf("%d",&p);
printf("enter the burst time\n");
for(i=0;i<p;i++)
{
scanf("%d",&bt[i]);
}
st[0]=0;
for(i=0;i<p;i++)
{
ft[i]=st[i]+bt[i];
st[i+1]=ft[i];
}
for(i=0;i<p;i++)
{
sum=sum+st[i];
}
avg=sum/p;
printf("Waiting time=%f\n",avg);
for(i=0;i<p;i++)
{
s=s+ft[i];
}
a=s/p;
printf("Turnaround time=%f\n",a);
return 0;
}


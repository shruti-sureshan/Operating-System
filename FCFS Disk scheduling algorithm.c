#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{   clrscr();
int s=0,diff,j,i,n,h,d,q[10];
printf("enter the no of cylinders\n");
scanf("%d",&n);
printf("enter the FIFO queue\n");
for(i=1;i<=n;i++)
{
scanf("%d",&q[i]);
}
printf("enter the head position\n");
scanf("%d",&h);
q[0]=h;
for(j=0;j<n;j++)
{
diff=abs(q[j+1]-q[j]);
s=s+diff;
printf("move from %d to %d\n",q[j],q[j+1]);
}
printf("Access time is %d",s);
getch();
}


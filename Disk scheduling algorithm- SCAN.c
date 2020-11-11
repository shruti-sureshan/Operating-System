#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	int max,s=0,i,j,n,q[10],temp,h,l,direction;
	clrscr();
	printf("Enter no. of cylinders\n");
	scanf("%d",&n);
	printf("Enter the queue\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&q[i]);
	}
	printf("Enter head position\n");
	scanf("%d",&h);
	q[n]=h;
	n++;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(q[j+1]<q[j])
			{
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
	printf("After sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",q[i]);
	}
	for(i=0;i<n;i++)
	{
		if(q[i]==h)
			l=i;
	}
	printf("\nEnter max:   ");
	scanf("%d",&max);
	printf("\nEnter direction\n1.Towards min\n2.Towards max\n");
	scanf("%d",&direction);
	if(direction==1)
	{       printf("\nSequence is:");
		for(i=l;i>0;i--)
		{       printf("%d,",q[i]);
			s=s+abs(q[i]-q[i-1]);
		}
		printf("%d,0",q[0]);
		s=s+q[0];
		s=s+h;
		for(i=l;i<n-1;i++)
		{
			printf(",%d",q[i+1]);
			s=s+abs(q[i+1]-q[i]);
		}
	}
	else if(direction==2)
	{
		s=0;
		printf("Sequence is:");
		for(i=l;i<n-1;i++)
		{
			printf("%d,",q[i]);
			s=s+abs(q[i+1]-q[i]);
		}
		printf("%d,%d",q[n-1],max);
		s=s+abs(max-q[n-1]);
		s=s+abs(max-h);
		for(i=l;i>0;i--)
		{
			printf(",%d",q[i-1]);
			s=s+abs(q[i]-q[i-1]);
		}
	}
	printf("\nAccess time=%d",s);
	getch();
}

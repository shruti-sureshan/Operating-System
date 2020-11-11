#include<stdio.h>
#include<conio.h>
int available[10],p,r,k,count=0,max[10][10],allocation[10][10],finish[10],need[10][10],i,j,work[10],safe[10],flag=1,n=0;
void main()
{  
clrscr();
printf("enter the no of proceeses\n");
scanf("%d",&p);
printf("enter the no of resources\n");
scanf("%d",&r);
printf("enter value of available\n");
for(i=0;i<r;i++)
{
scanf("%d",&available[i]);
}
printf("enter value of allocation\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&allocation[i][j]);
}
}
printf("enter value of max\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("the need matrix is\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
need[i][j]=max[i][j]-allocation[i][j];
printf("%d\t",need[i][j]);
}
printf("\n");
}
for(i=0;i<r;i++)
{
work[i]=available[i];
finish[i]=0;
}
    for(i = 0 ; i<p; i++){
	for(j=0;j<r;j++){
	    if(need[i][j] > work[j] || finish[i] == 1){
		flag = 0;
		break;
	    }
	    else{
		flag = 1;  }
	}
	if(flag == 1){
	    finish[i] = 1;
	    safe[n++] = i;
	    for(k = 0 ; k<r ; k++){
		work[k]+= allocation[i][k];
	    }    	}
  if(count == (p*p)){
	    printf("ERROR: Processes Not in Safe State\n");
	    break;
	}
	if(i==p-1)
	    for(k = 0 ; k<p; k++)
		if(finish[k] == 0){
		    i = -1;
		    count++;
		}
    }
printf("Safe Order:\n");
    for(i = 0 ; i<n;i++)
	printf("P%d\t" , safe[i]);
	getch();
}

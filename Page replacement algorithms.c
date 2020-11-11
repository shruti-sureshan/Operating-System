#include <stdio.h>
#include <conio.h>
int ch,fra[10],ref[20],vis[10],c,n,i,j,h,bits,page=0,index=0,found=0,k=0,count=0,max=0,pos=0,temp[10],
flag1=0,flag2=0,flag3=0,faults=0;
void main()
{    
    clrscr();
    printf("Enter the no. of frames\n");
    scanf("%d",&n);
    printf("Enter the no. of pages\n");
    scanf("%d",&bits);
    printf("Enter the reference string\n");
    for(i=0;i<bits;i++)
    {
	scanf("%d",&ref[i]);
    }
    for(i=0;i<n;i++)
    {
	fra[i]=-1;
    }
    do
    {
    printf("1.FIFO\n2.Optimal\n3.LRU\nEnter your choice\n");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    for(i=0;i<bits;i++)
    {
	count=0;
	for(j=0;j<n;j++)
	{
	    if(fra[j]==-1)
	    {

		page++;
		fra[index]=ref[i];
		if(index!=n-1)
		    index=(index+1)%(n);
		break;
	    }
	    else
	    {
		if(fra[j] != ref[i])
		{
		    count++;
		    if(count == n)
		    {
			  index=(index+1)%(n);
			fra[index] = ref[i];
			page++;
			found=1;
		    }
		}
	    }
	    if(found==1)
		continue;
	}   
    }

    printf("The no. of Page Faults for FIFO = %d", page);
	   break;
    case 2:
    for(i=0;i<n;i++)
    {
	fra[i]=-1;
    }

    for(i = 0; i < bits; ++i)
    {
	flag1 = flag2 = 0;

	for(j = 0; j < n; ++j)  
	{
	    if(fra[j] == ref[i])
	    {
		   flag1 = flag2 = 1;
		   break;
	    }
	}     

	if(flag1 == 0)   
	{
	    for(j = 0; j < n; ++j)
	    {
		if(fra[j] == -1)
		{
		    faults++;
		    fra[j] = ref[i];
		    flag2 = 1;    
		    break;
		}
	    }    
	}

	if(flag2 == 0)
	{
	    flag3 =0;

	    for(j = 0; j < n; ++j)
	    {
		temp[j] = -1;
		count=0;
		k=i+1;
		while( k < bits)     
		{
		    count++;
		    if(fra[j] == ref[k])
		    {
			temp[j]=count;//temp[j] = k;
			break;
		    }
		    ++k;
		}
	    }

	    for(j = 0; j < n; ++j){
		if(temp[j] == -1){
		    pos = j;
		    flag3 = 1;
		    break;
		}
	    }

	    if(flag3 ==0){
		max = temp[0];
		pos = 0;

		for(j = 1; j < n; ++j){
		    if(temp[j] > max){
			max = temp[j];
			pos = j;
		    }
		}
	    }

	    fra[pos] = ref[i];
	    faults++;
	}               


    }        

    printf("The no. of Page Faults for OPTIMAL = %d", faults);
    break;
    case 3:
    faults=0;
    for(i=0;i<n;i++)
    {
	fra[i]=-1;
    }


    for(i = 0; i < bits; ++i)
    {
	flag1 = flag2 = 0;

	for(j = 0; j < n; ++j)   
	{
	    if(fra[j] == ref[i])
	    {
		   flag1 = flag2 = 1;
		   break;
	    }
	}     

	if(flag1 == 0)   
	{
	    for(j = 0; j < n; ++j)
	    {
		if(fra[j] == -1)
		{
		    faults++;
		    fra[j] = ref[i];
		    flag2 = 1;    
		    break;
		}
	    }   
	}

	if(flag2 == 0)
	{
	    flag3 =0;

	    for(j = 0; j < n; ++j)
	    {
		temp[j] = -1;
		count=0;
		k=i-1;
		while( k >= 0)     
		{
		    count++;
		    if(fra[j] == ref[k])
		    {
			temp[j]=count;//temp[j] = k;
			break;
		    }
		    --k;
		}
	    }

	    for(j = 0; j < n; ++j){
		if(temp[j] == -1){
		    pos = j;
		    flag3 = 1;
		    break;
		}
	    }

	    if(flag3 ==0){
		max = temp[0];
		pos = 0;

		for(j = 1; j < n; ++j){
		    if(temp[j] > max){
			max = temp[j];
			pos = j;
		    }
		}
	    }

	    fra[pos] = ref[i];
	    faults++;
	}               


    }        

    printf("The no. of Page Faults for LRU = %d", faults);
	   }
	    printf("\nEnter 1 to continue\n");

	    scanf("%d",&ch);
	    }while(ch==1);
	    getch();
}


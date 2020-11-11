#include<stdio.h>
#include<conio.h>
int i,j,p,c,ch,h,b[10],r[10],sort[10],temp,k;
void main()
{            
      clrscr();
       printf("Enter the number of holes\n");
      scanf("%d",&h);
      printf("Enter the number of processes\n");
      scanf("%d",&p);
      printf("Enter the size for each block\n");
      for(i=0;i<h;i++)
	{
	  scanf("%d",&b[i]);
	}
      printf("Enter the request for each process\n");
      for(i=0;i<p;i++)
	{
	  scanf("%d",&r[i]);
	}
	 for(i=0;i<p;i++)
	 {
	 printf("Process no %d: %d\n",i,r[i]);
	 }

      printf("\n1.FIRST FIT\n2.BEST FIT\n3.WORST FIT\nEnter choice\n");
      scanf("%d",&ch);
 //     i=0;
      switch(ch)
      {
      case 1:     for(i=0;i<h;i++)
		      {
		      printf("Block no %d: %d\n",i,b[i]);
		      }
		 printf("\nRESULT:\n");
		 for(k=0;k<p;k++)
		{
		for(i=0;i<h;i++)
		{
		if(b[i]>=r[k])
		{
		b[i]=b[i]-r[k];
		printf("process no %d is in %d block\n",k,i);
		break;
	}
	}
	}
	break;
   case 2:  for(i=0;i<h;i++)
			{
			    sort[i]=b[i];
			 }
		    for(i=0;i<h-1;i++)
			{
			   for(j=0;j<(h-i-1);j++)
			       {
				  if(sort[j]>sort[j+1])
				     {
					temp=sort[j];
					sort[j]=sort[j+1];
					sort[j+1]=temp;
				     }
			       }
			 }
		      for(i=0;i<h;i++)
		      {
		       	printf("Block no %d: %d\n",i,sort[i]);
		      }
		     printf("\nRESULT:\n");
		     i=0;
		     while(i<p)
		     {
		       c=0;
		       for(j=0;j<h;j++)
			{
			  if(r[i]<=sort[j])
			     {
				sort[j]=sort[j]-r[i];
				printf("Process no %d goes in block %d\n",i,j);
				c++;
				break;
			     }

		       }
			 if(c==0)
			   {
			      printf("\nProcess %d is waiting",i);
			   }
		       i++;
		    }
		     break;
      case 3:
		    for(i=0;i<h;i++)
			{
			    sort[i]=b[i];
			 }
		    for(i=0;i<h-1;i++)
			{
			   for(j=0;j<(h-i-1);j++)
			       {
				  if(sort[j]<sort[j+1])
				     {
					temp=sort[j];
					sort[j]=sort[j+1];
					sort[j+1]=temp;
				     }
			       }
			 }
		       for(i=0;i<h;i++)
		      {
		      printf("Block no %d: %d\n",i,sort[i]);
		      }
			 printf("\nRESULT:\n");

		     i=0;
		     while(i<p)
		     {
		       c=0;
		       for(j=0;j<h;j++)
			{
			  if(r[i]<=sort[j])
			     {
				sort[j]=sort[j]-r[i];
				printf("Process no %d goes in block %d\n",i,j);
				c++;
				break;
			     }

		       }
			 if(c==0)
			   {
			      printf("\nProcess %d is waiting",i);
			   }
		       i++;
		    }
		     break;
	   }
	   getch();
      }

import java.util.*;
import java.lang.*;
import java.io.*;
class LRU {
	static int li[]=new int[100];
	static int a[][]=new int[100][2];
	public static int isPresent(int p,int fs)
	{
		for(int i=0;i<fs;i++)
		{
			if(a[i][0]==p)
				return i;
		}
		return -1;
	}
	
	public static int min(int fs)
	{
		int min=a[0][1],j=0;
		for(int i=0;i<fs;i++)
		{
			if(a[i][1]<min){
				min=a[i][1];
				j=i;
			}
		}
		return j;
	}

	public static void main(String[] args) {
		int n,i,k=0,c=0,hit=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of pages:");
		n=sc.nextInt();
		//int list[]=new int[n];
		//int a[][]=new int[n][2];
		System.out.println("Enter reference string:");
		for(i=0;i<n;i++)
		{
			li[i]=sc.nextInt();
			a[i][0]=0;
		}
		System.out.println("Enter the size of the frame");
		int fs=sc.nextInt();
		for(i=0;i<n;i++)
		{
			if((c<fs)&&(isPresent(li[i],fs)==-1))
			{
				a[k][0]=li[i];
				c++;
				a[k][1]=i;
			    	k++;
			
			}
			else if(isPresent(li[i],fs)!=-1)
			{
				a[isPresent(li[i],fs)][1]=i;
				hit++;
				for(int j=0;j<fs;j++)
				{
					System.out.print(" "+a[j][0]);
				}
			System.out.println(" HIT "+hit);
			continue;
			}
			else{
				k=min(fs);
				a[k][0]=li[i];
				a[k][1]=i;

			}
			for(int j=0;j<fs;j++)
			{
				System.out.print(" "+a[j][0]);
			}
			System.out.println();
		}
		double g=hit/(double)n;
		System.out.println("\nHit ratio: "+g);
		System.out.println("\nPage Fault Ratio: "+(1-g));
		
	}

}

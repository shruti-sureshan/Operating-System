import java.util.*;
class Optimal
 {
 
   static int ref[];
   
   public static void main(String[] args)
    {
      Scanner sc=new Scanner(System.in);
      
      int num_of_frames;
      double hit_ratio;
      int hit = 0;
      System.out.println("Enter the number of pages:");
      int n=sc.nextInt();
      
      int ref[]=new int[n];	
      
      System.out.println("Enter the reference string:");
       
       for(int i=0;i<n;i++)
          ref[i]=sc.nextInt();
          
          System.out.println("Enter the number of frames:");
          num_of_frames=sc.nextInt();
			
	int frames[][]=new int[num_of_frames][2];
				          
          for(int i=0;i<n;i++)
          {
          	int curr_Process = ref[i];
          	int added = 0;
          	for(int j=0;j<num_of_frames;j++)
          	{
          		if(frames[j][0]==0 || frames[j][0] == curr_Process)
          		{
          			frames[j][0] = curr_Process;
          			frames[j][1] = 0;
          			added =1;
          			hit++;
          			break;
          		}
          		else
          		{
          			if(frames[j][1]==0)
          			{
          				int z;
          				for(z=i+1;z<ref.length;z++)
           				{
             					if(ref[z]==frames[j][0])
             					{
              						frames[j][1] = z-i;
              						break;
              					}
           				}
           				if(z==ref.length) // if element not found
           					frames[j][1] = -1;
          			}
         		}
         		    
         	}
         	
         	if(added == 0)
         	{
         		int max =0;
         		for(int j=0;j<num_of_frames;j++)
         		{
         			if(frames[j][1]==-1)
         			{
         				max = j;
         				break;
         			}	
         			if(frames[max][1]<frames[j][1])
         				max=j;
         		}
         		frames[max][0] = curr_Process;
         		frames[max][1] = 0;
         	}
         	for(int d=0;d<num_of_frames;d++)
         	 {
         	   System.out.print("\t"+frames[d][0]);

         	 }
         	 System.out.println("\n");

         	 
         }
         
         hit_ratio= (double)(hit-num_of_frames)/n;
         
         System.out.println("The number of hits: "+(hit-num_of_frames));
         System.out.println("Hit Ratio: "+hit_ratio);
         System.out.println("Page faults: "+ (n-hit+num_of_frames));
         
         
     }
    }
    

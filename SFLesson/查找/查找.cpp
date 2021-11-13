#include <stdio.h>
//’€∞Î≤È’“
int Bsearch(int R[],int low,int high,int k)
{
        int mid;
        while(low<=high)
        {
               mid=(low+high)/2;   
               if(R[mid]==k) 
               {
                   printf("mid\n");
                   return mid;
               }   
                     
               else if(R[mid]>k)     
               {
                   high=mid-1;  
                   printf("high+%d\n",high);
               }   //‘⁄◊Û∞Î±ﬂ≤È’“
               else    
               {
                   low=mid+1; 
                   printf("low+%d\n",low);

               }      //‘⁄”“∞Î±ﬂ≤È’“
        }
        return -1;
}
int main()
{
    int k[10]={0,1,3,5,8,9,10,22,44,55};
    int count = Bsearch(k,0,9,8);
    printf("%d",count);
}
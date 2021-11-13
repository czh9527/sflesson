#include "stdio.h"
void swap(int k[],int i,int j)
{
    int temp =k[i];
    k[i]=k[j];
    k[j]=temp;
}
void heapAdjust(int k[],int s,int n)
{
    int i,j;
    int temp = k[s];
    for(i=s*2;i<=n;i*=2)
    {
        if(i<n && k[i+1]>k[i])
        {
            i++;
        }
        if(temp>=k[i])
        {
            break;
        }
        k[s]=k[i];
        s=i;
    }
    k[s]=temp;
}
void heapSort(int k[],int n)
{
    int i,j;
    for(i = n/2;i>0;i--)
    {
        heapAdjust(k,i,n);
    }

    for(j=n;j>1;j--)
    {
        swap(k,1,j);
        heapAdjust(k,1,j-1);
    }
}
int Partition(int k[],int low,int high)
{
    int i,j,temp;
    int point = k[low];
    while(low<high)
    {
        while(k[high]>=point && low<high)
        {
            high--;
        }
        k[low]=k[high];
        while(k[low]<=point && low<high)
        {
            low++;
        }
        k[high]=k[low];

    }
    k[high]=point;
    return high;
    
}
void qSort(int k[],int low,int high)
{
    if(low<high)
    {
        int point = Partition(k,low,high);
        qSort(k,low,point-1);
        qSort(k,point+1,high);
    }

}
void quickSort(int k[],int n)
{
    int i,j;
    qSort(k,0,n-1);
}
void merging(int *list1,int list1_size,int *list2,int list2_size)
{
    int i,j,k,m;
    i=j=k=0;
    int temp[100];
    while(i<list1_size && j<list2_size)
    {
        if(list1[i]<list2[j])
        {
            temp[k++]=list1[i++];
        }
        else
        {
            temp[k++]=list2[j++];
        }
    }
    while(i<list1_size)
    {
        temp[k++]=list1[i++];
    }
    while(j<list2_size)
    {
        temp[k++]=list2[j++];
    }
    for(m=0;m<(list1_size+list2_size);m++)
    {
        list1[m]=temp[m];
    }
}
void mergeSort(int k[],int n)
{
    if(n>1)
    {
        int *list1= k;
        int list1_size =n/2;
        int *list2=k+n/2;
        int list2_size = n-list1_size;
        mergeSort(list1,list1_size);
        mergeSort(list2,list2_size);
        merging(list1,list1_size,list2,list2_size);
    }
}
void shellSort(int k[],int n)
{
    int i,j,temp,dk;
    for(dk=n/2;dk>=1;dk=dk/2)
    {
        for(i=dk;i<n;i+=dk)
        {
            if(k[i]<k[i-dk])
            {
                temp = k[i];
                for(j=i-dk;j>=0 && k[j]>temp;j-=dk)
                {
                    k[j+dk]=k[j];
                }
                k[j+dk]=temp;
            }
        }
    }

}
void BinsertSort(int k[],int n)
{
    int i,j,temp,mid,low,high;
    for(i=1;i<n;i++)
    {
        low=0;
        high=i-1;
        temp = k[i];
        while(low<=high)
        {
            mid = (low+high)/2;
            if(temp<k[mid])
            {
                high = mid-1;
            }
            else
            {
                low= mid+1;
            }
        }
        for(j=i-1;j>=0 && j>=high+1;j--)
        {
            k[j+1]=k[j];
        }
        k[high+1]=temp;
    }
}
void insertSort(int k[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        if(k[i]<k[i-1])
        {
            temp = k[i];
            for(j= i-1;j>=0 && k[j]>temp;j--)
            {
                k[j+1]=k[j];
            }
            k[j+1]=temp;
        }
        
    }
}
void selectSort(int k[],int n)
{
    int i,j,temp,min;
    for(i= 0;i<n-1;i++)
    {
        min=i;
        for(j = i;j<n;j++)
        {
            if(k[j]<k[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp = k[min];
            k[min]=k[i];
            k[i]=temp;
        }
    }
}
void BubbleShort(int k[],int n)
{
    int i,j,temp,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j = n-1;j>i;j--)
        {
            if(k[j]<k[j-1])
            {
                temp = k[j-1];
                k[j-1]=k[j];
                k[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
        {
            return;
        }
    }
}
int main()
{
    int k[10]={2,5,1,9,4,6,7,3,0,8};
    int heap[11]={-1,2,5,1,9,4,6,7,3,0,8};
    // quickSort(k,10);
    heapSort(heap,10);
    for (int i =0;i<11;i++)
    {
        printf("%d ",heap[i]);
    }
}
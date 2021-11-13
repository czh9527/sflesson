#include "stdio.h"
#include<string.h>
#define N 10	//数组长度
#define D 10	//最大位数
//基数排序
int GetDigit(int M, int i) //取整数M的第i位数
{
	while(i > 1)
	{
		M /= 10;
		i--;
	}
	return M % 10;
}

void RadixSort(int num[], int len)
{
	int i, j, k, l, digit;
	int allot[10][N];	//

	memset(allot, 0, sizeof(allot));//初始化桶

	for(i = 1; i <= D; i++)//循环数字是几位数
	{
		int flag = 0;//标记位
		//分配相应位数的数据，并存入桶
		for(j = 0; j < len; j++)	
		{			
			digit = GetDigit(num[j], i);//获取j的i位数数值
			k = 0;
			while(allot[digit][k])//移动位置
				k++;
			allot[digit][k] = num[j];//赋值
			if(digit) //说明该位数该有值
				flag = 1;
		}
		if(!flag)	//如果数组每个数的第i位都为零
			break;	//即可直接退出循环

		//将《分配数组》的数据依次收集到原数组中
		l = 0; 
		for(j = 0; j < 10; j++)	
		{	
			k = 0;
			while(allot[j][k] > 0)
			{
				num[l++] = allot[j][k];
				k++;
			}
		}
		//每次分配，收集后初始化《分配数组》，用于下一位数的分配和收集
		memset(allot, 0, sizeof(allot));
	}
}

//快速排序
void mswap(int k[],int low,int high)
{
    int temp=k[low];
    k[low]=k[high];
    k[high]=temp;
}
int Partition(int k[],int low,int high)
{
    int point;
    point= k[low];//基准点赋值数值-后面始终不变
    while(low<high)
    {
        while(low<high && k[high] >= point)//在循环里的不换元素-一定要先比较high
        {
            high--;
        }
        // mswap(k,low,high);
        k[low]=k[high];
        while(low<high && k[low] <= point)
        {
            low++;
        }
        k[high]=k[low];

        // mswap(k,low,high);
    }
    k[low]=point;//point没放，前面都是放其他元素
    // printf("%d-%d\n",point,k[low]);//是一样的
    return low;//此时low跟high是一个位置


}
void QSort(int k[],int low,int high)
{
    int point;//中间点-关键字位置
    if(low < high)//这是递归判断条件
    {
        point=Partition(k,low,high);
        QSort(k,low,point-1);
        QSort(k,point+1,high);
    }
}
void QuickSort(int k[],int n)
{
    QSort(k,0,n-1);
}
// //归并排序-迭代---不用掌握
// void mergeSortDd(int k[],int n)
// {
//     int i,left_min,left_max,right_min,right_max;
//     int *temp = (int *)malloc(n*sizeof(int));
//     for(i=1;i<n;i*=2)
//     {
//         for(left_min=0;left_min <n-i;left_min = right_max)
//         {
//             right_min = left_max = left_min+1;
//             right_max= left_max+i;
//             if(right_max>n)
//             {
//                 right_max=n;
//             }    
//             int next=0;
//             while(left_min<left_max && right_min<right_max)
//             {
//                 if(k[left_min] < k[right_min])
//                 {
//                     temp[next++]=k[left_min];
//                 }
//                 else{
//                     temp[next++]=k[right_min];
//                 }
//             }
//             while (left_min<left_max)
//             {
//                 k[--right_max]= k[--left_max];
//             }
//             while (next>0)
//             {
//                 k[--right_min]=temp[--next];
//             }      
//         }
//     }
// }

//归并排序-递归
#define MAXSIZE 10
void merging(int *list1,int list1_size,int *list2,int list2_size)
{
    int i , j , k,m;
    int temp[MAXSIZE];
    i=j=k=0;
    while(i<list1_size&&j<list2_size)//i和j同步部分进行排序
    {
        if(list1[i]<list2[j])
        {
            temp[k++] = list1[i++];
        }
        else{
            temp[k++]=list2[j++];
        }
    }
    while(i<list1_size)//加上剩下的i
    {
        temp[k++]=list1[i++];
    }
    while (j<list2_size)//加上剩下的j
    {
        temp[k++]=list2[j++];
    }
    for(m=0;m<(list1_size+list2_size);m++)//赋值回原list1=k
    {
        list1[m]=temp[m];
    }
    
}
void mergeSort(int k[],int n)
{
    if(n>1)
    {
        int *list1 = k;
        int list1_size = n/2;//左边部分
        int *list2= k+n/2;
        int list2_size = n-list1_size;//右边部分

        mergeSort(list1,list1_size);
        mergeSort(list2,list2_size);

        merging(list1,list1_size,list2,list2_size);
        
    }
}
//堆排序
void heapAdjust(int k[],int s, int n)//构建大顶堆
{
    int i,temp;
    temp =k[s];
    for(i = 2*s;i<=n;i*=2)
    {
        if(i<n && k[i]<k[i+1])//i<n的条件,排除i=n的情况
        {
            i++;
        }
        if(temp >=k[i])
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
    int i,j,temp;
    for(i=n/2;i>0;i--)//从最左边的点开始构造二叉树
    {
        heapAdjust(k,i,n);//
    }
    for(j=n;j>1;j--)
    {
        mswap(k,1,j);//将第一个和最后一个互换，确定好最大数位置
        heapAdjust(k,1,j-1);//剩下的数继续构造大顶堆
    }
}
//希尔排序
void ShellSort(int S[],int n)   
{
    int i ,j,temp;
    for (int dk= n/2;dk>=1;dk=dk/2)
    {
        for(i=dk;i<n;i+=dk)
        {
            if(S[i]<S[i-dk])
            {
                temp=S[i];
                for(j=i-dk;S[j]>temp&&j>=0;j-=dk)
                {
                    S[j+dk]=S[j];//找到位置，并向后移动
                }
                S[j+dk]=temp;//上面循环跳出来就是S[j]<=temp，所以是j+1
            }
        
        }
    }
}
//折半插入排序
void BinsertSort(int k[],int n)
{
    int i,j,temp;
    int low,high,mid;
    for(i=1;i<n;i++)
    {
        low=0;
        high=i-1;
        temp=k[i];
        while(low<=high)
        {
            mid = (high+low)/2;
            if(k[i]<k[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;--j)  //后移位置，此时high都比temp小
                 k[j+1]=k[j];      
        k[high+1]=temp;                 
    }
}
//直接插入排序
void insertSort(int S[],int n)
{
    int i ,j ,temp;
    for(i=1;i<n;i++)//i从第二个元素开始找插
    {
        if(S[i]<S[i-1])//判断是否需要向前找插
        {
            temp=S[i];
            for(j=i-1;S[j]>temp&&j>=0;j--)
            {
                S[j+1]=S[j];//找到位置，并向后移动，边后移，边找位置-需要把i也覆盖了
            }
            S[j+1]=temp;//上面循环跳出来就是S[j]<=temp，所以是j+1
        }
        
    }
}
//选择排序
void SelectSort(int S[],int n)
{
    int i ,j,min ,temp;
    for(i = 0;i<n-1;i++)//同样边界为n-1，前面已经确定好了
    {
        min = i;
        for(j = i+1;j<n;j++)
        {
            if(S[j]<S[min])
            {
                min=j;
            }
        }//每次取出最小的
        if(min!=i)
        {
            temp = S[i];
            S[i]=S[min];
            S[min]=temp;
        }
    }
}
//冒泡排序
void BubbleSort(int S[],int n)
{
    int i,j,temp,flag;
    for(i=0;i<n-1;i++)//边界倒数第二个就行
    {
        flag=0;
        for(j=n-1;j>i;j--)//从后往前冒,这里的>i，由于下面是j-1必须是>i
        {
            if(S[j]<S[j-1])//附近两两比较
            {
                temp=S[j];
                S[j]=S[j-1];
                S[j-1]=temp;
                flag=1;//看有没交换，没交换就直接退出
            }
            
            
        }
        if(flag==0)
            {
                return ;
            }
    }
}
int main(){
    int a[9]={2,13,1,45,57,24,12,67,42};
    int heap[10]={-1,4,2,6,3,9,1,8,5,7};

    // BubbleSort(a,9);
    // SelectSort(a,9);
    // insertSort(a,9);
    // ShellSort(a,9);
    // HeapSort(heap,9);
    RadixSort(a,9);
    for(int i=0;i<9;i++) 
    {
        printf("%d,",a[i]);
    }
}
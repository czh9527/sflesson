/*
这是一个常用算法总结的程序
包括
1.冒泡排序（Bubble Sort）
2.选择排序（Selection Sort）
3.插入排序（Insertion Sort）
4.希尔排序（Shell Sort）
5.归并排序（Merge Sort）
6.堆排序（Heap Sort）
7.快速排序（Quick Sort）
以上七种算法对数组int A[] = { 6, 5, 3, 1, 8, 7, 2, 4 ,10}的排序 
 */

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
//函数声明 
void bubbleSort(int a[],int len);
void selectionSort(int a[],int len);
void insertionSort(int a[],int len);
void shellSort(int a[],int len);
void mergeSort(int a[], int len);
void Merge(int A[], int left, int mid, int right);
void heapSort(int a[],int len);
void quickSort(int a[], int left, int right);

int main(void){
	//A为要排序的数组 
	int A[] = { 6, 5, 3, 1, 8, 7, 2, 4,10 };
	printf("原始数组为：\n");
	int lengthA = 9;
	for(int i = 0 ; i<lengthA;i++){
		printf("%d ",A[i]);
	}
	printf("\n\n");
	//以下执行各种排序 
	bubbleSort(A,lengthA);
//	selectionSort(A,lengthA);
//	insertionSort(A,lengthA);
//	shellSort(A,lengthA);
//	mergeSort(A,lengthA);
//	heapSort(A,lengthA);
	// quickSort(A,0,lengthA-1);
	// printf("快速排序的结果：\n");
	// for(int i = 0 ; i< lengthA; i++){
	// printf("%d ",A[i]);
	// }
	// printf("\n\n");
	
	return 0;
}

/*
冒泡排序
基本思想：相邻两两比较，较大的下沉，较小的上升
第一轮之后，最小的数就被放到第一个位置
...... 
优化：
若某一次完了之后已经排好序，则没必要进行到
len-1次，
可用一个flag，没有交换之后就没必要再进行下去了 
*/
void bubbleSort(int a[],int length){
	int len =length;
	int temp;//中间变量 
	bool flag;//优化的标志 ,是否有交换 
	for(int i = 0; i<len; i++){//
		flag = false;//没有经过下面这个就说明排好了
		for(int j = len - 1; j>i;j--){
			if(a[j]<a[j-1]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				flag = true;
			}
		}
		if(!flag) break;
	}
	printf("冒泡排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	
}

/*
选择排序
基本思想：一开始从原始序列中找到最小的元素，放到序列的起始位置作为已
		排序序列；然后，在从剩下的未排列的元素中继续寻找最小元素，放到已
		排序的序列末尾....直到所有元素排列完毕
 */
void selectionSort(int a[],int length){
	int len = length;
	int minIndex;
	int temp;
	for(int i = 0;i<len;i++){
	//i是已排列的序列的末尾
		minIndex = i;
		for(int j = i+1;j<len;j++){
			if(a[j]<a[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex != i){
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		} 	
	}
	printf("选择排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
}

/*
插入排序
基本思想：
在要排序的一组数中，假定前n-1个数已经排好序，现在将第n个数插到前面的有序数列中，
使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。 
插入排序在实现上，
常采用in-place排序，因而在从后向前扫描过程中，
需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
　　具体算法描述如下：
从第一个元素开始，该元素可以认为已经被排序
取出下一个元素，在已经排序的元素序列中从后向前扫描
如果该元素（已排序）大于新元素，将该元素移到下一位置
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
将新元素插入到该位置后
重复步骤2~5 
*/
void insertionSort(int a[], int length){
	int len = length;
	int temp;
	int i;//已排好序的序列的下一个元素（待插元素）的下标 
	int j;//有序序列的末尾下标 
	for(i = 1;i<len;i++){
		temp = a[i];//中间变量 
		j=i-1;
		while(j >= 0&&a[j]>temp){//遍历有序序列，与要插入的元素比较 
			a[j+1] = a[j];//将元素后移，满足条件后移一个位置
			j--; 
		}
		a[j+1] = temp; //插入  
	}
	printf("插入排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");
	
}

/*
希尔排序：
将无序数组分割为若干个子序列，子序列不是逐段分割的，
而是相隔特定的增量的子序列，对各个子序列进行插入排序；
然后再选择一个更小的增量，再将数组分割为多个子序列进行排序
......最后选择增量为1，即使用直接插入排序，使最终数组成为有序。
增量的选择：在每趟的排序过程都有一个增量，
至少满足一个规则 增量关系 d[1] > d[2] > d[3] >..> d[t] = 1 (t趟排序)；
本文采用首选增量为n/2,以此递推，每次增量为原先的1/2，直到增量为1； 
希尔排序类似于分组插入排序
example：
49，38，65，97，76，13，27，49，55，04。
增量序列的取值依次为：
5，3，1
第一趟排序后：
|                    | 
--------------------- 
    |                   |
	-------------------- 
。。。。。 
13，27，49，55，04，49，38，65，97，76
第二趟排序后：
|           |           |           | 
-------------------------------------
    |           |           |
	------------------------
。。。。。。
13，04，49，38，27，49，55，65，97，76 
*/
void shellSort(int a[],int len){
	int incre=len;//设置增量
	int temp;
	while(true){
		incre /=2;
		for(int k=0;k<incre;k++){
			for(int i = k+incre;i<len;i+=incre){
				//按增量循环序列 
				for(int j = i;j>k;j-=incre){
					if(a[j]<a[j-incre]){
						temp = a[j-incre];
						a[j-incre]=a[j];
						a[j]=temp;
					}
				} 
			}
		}
		if(incre == 1)
			break;
	}
	printf("希尔排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");	
}

/*
归并排序：
归并排序的实现分为递归实现与非递归(迭代)实现。
递归实现的归并排序是算法设计中分治策略的典型应用，
我们将一个大问题分割成小问题分别解决，然后用所有小问题的答案来解决整个大问题。
非递归(迭代)实现的归并排序首先进行是两两归并，
然后四四归并，然后是八八归并，一直下去直到归并了整个数组。
归并操作步骤如下：
申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
设定两个指针，最初位置分别为两个已经排序序列的起始位置
比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
重复步骤3直到某一指针到达序列尾
将另一序列剩下的所有元素直接复制到合并序列尾 
*/
void mergeSort(int a[],int len){
	int left,mid,right;//前一个数组为a[left...mid],后一个...
	for(int i=1;i<len;i*=2){
		left = 0;
		while(left+i<len){//若后一个子数组存在，需要归并 
			mid=left+i-1;
			right = mid +i<len?mid+i:len-1;//后一个子数组可能不够
			Merge(a,left,mid,right);
			left = right +1;//前一个子数组索引向后移动 
		}
	} 
	printf("归并排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");	
	
}

// 合并两个已排好序的数组A[left...mid]和A[mid+1...right]
void Merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *temp = new int[len];       // 辅助空间O(n)
    int index = 0;
    int i = left;                   // 前一数组的起始元素
    int j = mid + 1;                // 后一数组的起始元素
    while (i <= mid && j <= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];  // 带等号保证归并排序的稳定性
    }
    while (i <= mid)
    {
        temp[index++] = A[i++];
    }
    while (j <= right)
    {
        temp[index++] = A[j++];
    }
    for (int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

/*
堆排序
堆是一种近似完全二叉树的结构（通常堆是通过一维数组来实现的），
并满足性质：以最大堆（也叫大根堆、大顶堆）为例，
其中父结点的值总是大于它的孩子节点。
堆排序的过程：
由输入的无序数组构造一个最大堆，作为初始的无序区
把堆顶元素（最大值）和堆尾元素互换
把堆（无序区）的尺寸缩小1，并调用heapify(A, 0)从新的堆顶元素开始进行堆调整
重复步骤2，直到堆的尺寸为1
*/

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void Heapify(int A[], int i, int size)  // 从A[i]向下进行堆调整
{
    int left_child = 2 * i + 1;         // 左孩子索引
    int right_child = 2 * i + 2;        // 右孩子索引
    int max = i;                        // 选出当前结点与其左右孩子三者之中的最大值
    if (left_child < size && A[left_child] > A[max])
        max = left_child;
    if (right_child < size && A[right_child] > A[max])
        max = right_child;
    if (max != i)
    {
        Swap(A, i, max);                // 把当前结点和它的最大(直接)子节点进行交换
        Heapify(A, max, size);          // 递归调用，继续从当前结点向下进行堆调整
    }
}

int BuildHeap(int A[], int n)           // 建堆，时间复杂度O(n)
{
    int heap_size = n;
    for (int i = heap_size / 2 - 1; i >= 0; i--) // 从每一个非叶结点开始向下进行堆调整
        Heapify(A, i, heap_size);
    return heap_size;
}


void heapSort(int a[],int len){
	int heap_size = BuildHeap(a, len);    // 建立一个最大堆
	while (heap_size > 1) // 堆（无序区）元素个数大于1，未完成排序
    {
        // 将堆顶元素与堆的最后一个元素互换，并从堆中去掉最后一个元素
        // 此处交换操作很有可能把后面元素的稳定性打乱，所以堆排序是不稳定的排序算法
        Swap(a, 0, --heap_size);
        Heapify(a, 0, heap_size);     // 从新的堆顶元素开始向下进行堆调整，时间复杂度O(logn)
    }
    printf("堆排序的结果：\n");
	for(int i = 0 ; i< len; i++){
		printf("%d ",a[i]);
	}
	printf("\n\n");	
}

/*
快速排序
使用分治策略来把一个序列分为两个子序列。
步骤为：
从序列中挑出一个元素，作为"基准"(pivot).
把所有比基准值小的元素放在基准前面，
所有比基准值大的元素放在基准的后面（相同的数可以到任一边），
这个称为分区(partition)操作。
对每个分区递归地进行步骤1~2，递归的结束条件是序列的大小是0或1，
这时整体已经被排好序了。
*/
int Partition(int A[], int left, int right)  // 划分函数
{
    int pivot = A[right];               // 这里每次都选择最后一个元素作为基准
    int tail = left - 1;                // tail为小于基准的子数组最后一个元素的索引
    for (int i = left; i < right; i++)  // 遍历基准以外的其他元素
    {
        if (A[i] <= pivot)              // 把小于等于基准的元素放到前一个子数组末尾
        {
            Swap(A, ++tail, i);
        }
    }
    Swap(A, tail + 1, right);           // 最后把基准放到前一个子数组的后边，剩下的子数组既是大于基准的子数组
                                        // 该操作很有可能把后面元素的稳定性打乱，所以快速排序是不稳定的排序算法
    return tail + 1;                    // 返回基准的索引
}

void quickSort(int a[],int left,int right){
	if (left >= right)
		return;
    int pivot_index = Partition(a, left, right); // 基准的索引
    quickSort(a, left, pivot_index - 1);
    quickSort(a, pivot_index + 1, right);
}

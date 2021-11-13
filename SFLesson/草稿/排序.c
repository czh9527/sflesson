#include <stdio.h>
#include <string.h>

int main()
{
    int heap[11]={-1,2,13,1,45,57,24,34,12,67,42};
    int k[10]={2,13,1,45,57,24,34,12,67,42};
    heapSort(heap,10);
    for(int i=0;i<11;i++)
    {
        printf("%d ",heap[i]);
    }
    return 0;
}
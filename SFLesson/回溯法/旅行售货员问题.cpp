// // n:图G的顶点数
// // x[]:当前解
// // bestx[]:当前最优解
// // a[][]:图G的邻接矩阵
// // cc:当前费用
// // bestc:当前最优值
// // NoEdga:无边标记

// void Backtrack(int i)
// {  if(i==n)
//    {  if(a[x[n-1]][x[n]]!=NoEdge&&a[x[n]][1]!=NoEdge&&(cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc||bestc==NoEdge))
//        {  for(int j=i;j<=n;j++)    bestx[j]+=x[j];
//            bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];
//         }
//     }
//     else
//     {  for(int j=i;j<=n;j++)
//         if(a[x[i-1]][x[j]]!=NoEdge&&(cc+a[x[i-1]][x[j]]<bestc||bestc==NoEdge))
//         {   swap(x[i],x[j]);
//              cc+=a[x[i-1]][x[i]];
//              Backtrack(i+1);
//              cc-=a[x[i-1]][x[i]];
//              swap(x[i],x[j]);
//         }
//     }
// }
#include <iostream>
#include <string.h>
using namespace std;
const int max_ = 0x3f3f3f;   //定义一个最大值
const int NoEdge = -1;      //两个点之间没有边
int citynum;                //城市数
int edgenum;                //边数
int currentcost;            //记录当前的路程
int bestcost;               //记录最小的路程(最优)
int Graph[100][100];        //图的边距记录
int x[100];                 //记录行走顺序
int bestx[100];             //记录最优行走顺序

void InPut()
{
    int pos1, pos2, len;     //点1 点2 距离

    cout<<"请输入城市数和边数(c e)：";
    cin>>citynum>>edgenum;

    memset(Graph, NoEdge, sizeof(Graph));

    cout<<"请输入两座城市之间的距离(p1 p2 l)："<<endl;
    for(int i = 1; i <= edgenum; ++i)
    {
        cin>>pos1>>pos2>>len;
        Graph[pos1][pos2] = Graph[pos2][pos1] = len;
    }
}

//初始化
void Initilize()
{
    currentcost = 0;
    bestcost = max_;
    for(int i = 1; i <= citynum; ++i)
    {
        x[i] = i;
    }
}


void Swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void BackTrack(int i) //这里的i代表第i步去的城市而不是代号为i的城市
{
    if(i == citynum)//处理最后一步
    {
        //进行一系列判断，注意的是进入此步骤的层数应是叶子节点的父节点，而不是叶子节点
        if(Graph[x[i - 1]][x[i]] != NoEdge && Graph[x[i]][x[1]] != NoEdge && (currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]] < bestcost || bestcost == max_))
        {
            //最小(优)距离=当前的距离+当前城市到叶子城市的距离+叶子城市到初始城市的距离
            bestcost = currentcost + Graph[x[i - 1]][x[i]] + Graph[x[i]][x[1]];
            for(int j = 1; j <= citynum; ++j)
                bestx[j] = x[j];
        }
    }
    else//处理中间城市
    {
        for(int j =  i; j <= citynum; ++j)
        {
            if(Graph[x[i - 1]][x[j]] != NoEdge && (currentcost + Graph[x[i - 1]][x[j]] < bestcost || bestcost == max_))
            {
                Swap(x[i], x[j]);  //这里i 和 j的位置交换了, 所以下面的是currentcost += Graph[x[i - 1]][x[i]];
                currentcost += Graph[x[i - 1]][x[i]];
                BackTrack(i + 1);   //递归进入下一个城市
                currentcost -= Graph[x[i - 1]][x[i]];
                Swap(x[i], x[j]);
            }
        }
    }
}

void OutPut()
{
    cout<<"最短路程为："<<bestcost<<endl;
    cout << "路线为:" << endl;
    for(int i = 1; i <= citynum; ++i)
        cout << bestx[i] << " ";
    cout << "1" << endl;
}


int main()
{
    InPut();
    Initilize();
    BackTrack(2);
    OutPut();
}
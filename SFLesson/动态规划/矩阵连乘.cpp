#include<iostream>
using namespace std;
 
const int N=7;

// void MatrixChain(int p[N],int n,int m[N][N],int s[N][N])//p为矩阵链，n为矩阵多少，m为存储最优结果的二维矩阵,s为存储选择最优结果路线的
// {    for(int i=1;i<=n;i++)  m[i][i]=0;//自己乘自己赋值0
//       for(int r=2;r<=n;r++)//r代表几个矩阵相乘,自底向上求
//           for(int i=1;i<=n-r+1;i++)//这是赋值ij范围,i
//           {    int j=i+r-1;
//                 m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
//                 s[i][j]=i;
//                 for(int k=i+1;k<j;k++)
//                 {    int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//
//                       if(t<m[i][j])//比较找出最小的取括号
//                       {  
//                            m[i][j]=t;
//                            s[i][j]=k;//确定数组该位置的值,决定括号包含那个
                          
//                       }
//                       printf("\n");
//                 }
//           }
// }


//p为矩阵链，p[0],p[1]代表第一个矩阵的行数和列数，p[1],p[2]代表第二个矩阵的行数和列数......length为p的长度
//所以如果有六个矩阵，length=7，m为存储最优结果的二维矩阵，s为存储选择最优结果路线的
//二维矩阵
void MatrixChainOrder(int *p,int m[N][N],int s[N][N],int length)
{
    int n=length-1;
    int l,i,j,k,q=0;
    //m[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;
    for(i=1;i<length;i++)
    {
        m[i][i]=0;
    }
    //l表示矩阵链的长度
    // l=2时，计算 m[i,i+1],i=1,2,...,n-1 (长度l=2的链的最小代价)
    for(l=2;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1; //以i为起始位置，j为长度为l的链的末位，
            m[i][j]=0x7fffffff;
            //k从i到j-1,以k为位置划分
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    cout << m[1][N-1] << endl;
}
void PrintAnswer(int s[N][N],int i,int j)//输出i到j的式子
{
    if(i==j)//此时已经到都头
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j]+1,j);
        cout<<")";
    }
}
void print(int s[N][N])
{
    for(int i=0;i<N;i++)
    {
        printf("\n");
        for(int j=0;j<N;j++)
        {
            if(s[i][j]>10)
            {
                printf("--");
            }
            else{
                printf("%d-",s[i][j]);
            }
            
        }
    }
    printf("\n");
}
int main()
{
    int p[N]={30,35,15,5,10,20,25};
    int m[N][N],s[N][N];
    MatrixChainOrder(p,m,s,N);
    // MatrixChain(p,N-1,m,s);
    print(s);
    PrintAnswer(s,1,N-1);

    return 0;
}


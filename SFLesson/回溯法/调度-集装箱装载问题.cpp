
 
using namespace std;
 
#include <iostream>
 
// 集装箱数
int n = 6;
// 当前解：0表示不装入第一艘船，1表示装入第一艘船。
int x[7] = {0,0,0,0,0,0,0};
// 当前最优解
int bestx[7];
// 集装箱重量数组（集装箱编号从1开始）
int w[7] = {0,25,20,40,10,20,30};
// 第一艘轮船的载重量
int c1 = 80;
// 第二艘轮船的载重量
int c2 = 80;
// 当前载重量
int cw=0;
// 当前最优载重量
int bestw=0;
// 剩余集装箱重量
int r = 145; // 问题开始时，所有集装箱都还没有装船，都算剩余重量
 
/**
 * 访问子集树的第i层的某个节点。
 */
void backtrack(int i) {
	// 到达叶节点：该路径上每个集装箱都已处理
	if (i > n) {
		// 当前解的装载量，比当前最优载重量大
		if (cw > bestw) {
			// 更新最优解
			for (int i = 1; i <= n; i++) {
				bestx[i] = x[i];
			}
			bestw = cw;
		}
		return;
	}
	// 未到达叶节点
 
	// 先将当前集装箱从剩余重量中除去。
	r -= w[i];
 
	// 将当前集装箱装船，不会超过船的载重量
	if (cw + w[i] <= c1) {
		// 将第i个集装箱装船
		x[i] = 1;
		cw += w[i];
		// 遍历当前节点的左子树
		backtrack(i + 1);
		cw -= w[i];
	}
 
 //剪枝-只有剩下会有比最优值大的才继续
	// 当前集装箱不装船，但剩余的所有集装箱如果都装船，也会超过当前最优解的载重量-此情况才考虑不能
	if (cw+r>bestw) { 
		
		// 当前集装箱不装船
		x[i] = 0;
		// 遍历当前节点的右子树
		backtrack(i + 1);
	}
 
	// 将当前集装箱，加入到剩余重量中
	r += w[i];
}
 
void print()
{
    int m1= 0;
    int m2=0;
    printf("instruction of the boats :\n");
    for(int i=1;i<=n;i++)
    {
        if(bestx[i] == 0)
        {
            m2+=w[i];
            printf("\n%d(the 2)\n",w[i]);
        }
        else
        {
            m1+w[i];
            printf("\n%d(the 1)\n",w[i]);
        }
    }
    printf("the 1 weight is %d\n",m1);
    printf("the 2 weight is %d\n",m2);

}
 
int main() {
	cout << "集装箱装载问题" << endl;
	backtrack(0);
	print();
}




#include<stdio.h>
int main()
{
    double app = 0.8;           //苹果单价
    int cnt = 2;                //每天购买的苹果数量
    int sum = 0;                //苹果总数
    int day = 0;                //天数
    double mey = 0;             //总金额
    while (sum <= 100)
    {
        sum += cnt;
        // if (sum > 100)
        // {
        //     break;
        // }
        day++;
        mey += (app * cnt);
        printf("%d,%f,%d\n",day,mey,cnt);
        cnt *= 2;
    
        
    }
    printf("%f",mey/day);
    return 0;
}
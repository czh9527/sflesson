#include "stdio.h"
#include <Windows.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;
int numberOfday(Date date)
{
    if (date.month <= 2)//小于2分开算
    {
        return date.day + (date.month - 1) * 31;
    }
    int num = 0;
    if (date.month % 2 == 0) //偶数月
    {
        num = (date.month / 2 - 1) * 30 + (date.month / 2) * 31;
    }
    else //奇数月
    {
        num = (date.month / 2 - 1) * 30 + (date.month / 2 + 1) * 31;
    }
    //判断是否是闰年
    if (date.year / 400 == 0 || (date.year / 4 == 0 && date.year / 100 != 0))
    {
        num += 29;
    }
    else
    {
        num += 28;
    }
    num += date.day;
    return num;
}
int main()
{

    Date date;
    printf("请输入年月日");
    scanf("%d", &date.year);
    scanf("%d", &date.month);

    scanf("%d", &date.day);

    int num = numberOfday(date);
    printf("%d\n", num);
    system("pause");
    return 0;
}

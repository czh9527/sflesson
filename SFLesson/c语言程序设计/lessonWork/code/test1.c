#include <stdio.h>
double getEqual(int * score)
{
    int sum = 0;
    for(int i = 0;i<5;i++)
    {
        
        sum+=*(score+i);
    }
    double equal = sum/5.0;
    return equal;
}

void func(int * score,double equal)
{
     printf("低于平均分的分数有:");
     int number = 0;
     for(int i =0;i<5;i++)
    {

        if(*(score+i) < equal)
        {
            printf("%d,",*(score+i));
           number+=1;
        }
    }
     printf("\n低于平均分的人数为:%d\n",number);
   
}
int main(){

    int score[5]={85,66,87,57,61};

    int equal = getEqual(score);
    func(score,equal);
    return 0;
}
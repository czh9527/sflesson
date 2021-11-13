#include <stdio.h>
int abs(int a)
{  return a>0?a:-a;
}
int Queens[8]={0};//8���ʺ�Ӧ�÷��Ķ�������
int counts=0;
int Check(int ch,int cl)
{//��������֮ǰ��������
    for(int fh=0;fh<ch;fh++)
    {//����ȡ��ǰ�����лʺ�����λ�õ�������
          int fl=Queens[fh];
          //�����ͬһ�У���λ�ò��ܷ�
          if(cl==fl)    return 0;
          //ǰ������꣺��index,data��  ��ǰ�е����꣨ch,cl��
          if(abs(ch-fh)==abs(cl-fl))   return 0; //ͬһб��  
    }
 return 1;   //���������������ǣ���λ�þͿ��Է�
}
//������
void Print()
{   for(int line=0;line<8;line++)
     {   int list;
          for(list=0;list<Queens[line];list++)
                     printf("0");
          printf("#");
          for(list=Queens[line]+1;list<8;list++)
                     printf("0");
          printf("\n");
      }
      printf("=============\n");
}
void EightQueen(int current_line)
{    if(current_line==8)   return;
      int list;
      for(list=0;list<8;list++)  //�ж�ÿһ���Ƿ����
      {
             Queens[current_line]=list;
             if(Check(current_line,list))
             { 
                    if(current_line==7)//��
                    {     
                        counts++;
                        Print(); //��ӡ�ڷŷ���
                     }
                     EightQueen(current_line+1);
             }
       }
}


int main()
{     
      EightQueen(0);
      printf("�ڷŵķ�ʽ��%d��",counts);
      return 0;
}

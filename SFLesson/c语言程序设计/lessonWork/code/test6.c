#include "stdio.h"
#include <Windows.h>


int main()
{
    char name[20]={""};
    char sex[20]={""};
    int zgh=0;
    int wage=0;
    FILE *fp;
    FILE *mfp;
    if((fp=fopen("C:\\Users\\czh\\Desktop\\SFLesson\\lesson1\\lessonWork\\code\\employee.txt","r")) !=NULL
    &&(mfp=fopen("C:\\Users\\czh\\Desktop\\SFLesson\\lesson1\\lessonWork\\code\\data.txt","w"))!=NULL)

    {
        while(!feof(fp))
        {
          fscanf(fp,"zgname:%s zgh:%d sex:%s wage:%d\n",name,&zgh,sex,&wage);
          fprintf(mfp,"zgname:%s wage:%d\n",name,wage);
        }
    }
    fclose(fp);
    fclose(mfp);
    system("pause");
    return 0;
}

#include <stdio.h>
#include<Windows.h>
struct std
{
    long xh;
    char name[7];
    char sex[3];
    int nl;
};

int main()
{
    FILE *fp;
    struct std a;
    int i;
    if((fp=fopen("test.txt","w+"))==NULL)
    {
        printf("磁盘不够\n");
    }
    for(i=0;i<2;i++)
    {
        scanf("%d%s%d\n",&a.xh,a.sex,&a.nl);
        fprintf(fp,"%d %s %d\n\n",a.xh,a.sex,a.nl);
        gets(a.name);
        

        fputs(a.name,fp);
        rewind(fp);

        while (!feof(fp))
        {
            /* code */
            fscanf(fp,"info:%d%s%d\n",&a.xh,a.sex,&a.nl);
            fgets(a.name,7,fp);
            printf("read:%d--%s---%d\n",a.xh,a.sex,a.nl);
            puts(a.name);
            
        }

        
    }
    fclose(fp);
    system("pause");
    

    
}
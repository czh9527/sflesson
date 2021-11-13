#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main()
{
    //构建哈夫曼树
	htTree *codeTree = buildTree((char *)"beep boop beer!");
    hlTable *codeTable = buildTable(codeTree);

    

    return 0;
}
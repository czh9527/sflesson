#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main()
{
	
	//构建哈夫曼树
	htTree *codeTree = buildTree((char *)"beep boop beer!");
	
	//构建哈夫曼表
	hlTable *codeTable = buildTable(codeTree);

	//译码

	encode(codeTable,(char *)"beep boop beer!");


	//解码
	decode(codeTree,(char *)"0011111000111");

	return 0;
}
#include "myas.h"

int is_valid(char *op, char *args)
{
	//case1 : first String is not mov
	if(strcmp(op,"mov")!=0){
		printf("Instruction is not mov!!\n");
		return 0;
	}
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");
	return 1;
}

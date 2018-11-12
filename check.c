#include "myas.h"

int is_valid(char *op, char *args)
{
    char seps[]=",";//delimit
    char *token,*token1,*token2;
    //make token
    token=strtok(args,seps);
    token1=token;
    token=strtok(NULL,seps);
    token2=token;

    //case1 : first String is not mov
    if(strcmp(op,"mov")!=0){
	    printf("Error: Instruction is not mov!!\n");
	    return 0;
    }
    //No register
    if((strchr(token1,"%")==NULL)&&(strchr(token2,"%")==NULL)){
	//mem to mem
	if(strchr(strchr(token1,"(")!=NULL)&&(strchr(token2,"(")!=NULL)){
	printf("Error: mem to mem\n");
	return 0;
	}
	else if((strchr(token1,"(")!=NULL)&&(strchr(token2,"x")!=NULL)){
	printf("Error: mem to mem\n");
	return 0;
	}
	else if((strchr(token1,"x")!=NULL)&&(strchr(token2,"(")!=NULL)){
	print("Error: mem to mem\n");
	return 0;
	}
	else if((strchr(token1,"x")!=NULL)&&(strchr(token2,"x")!=NULL)){
	printf("Error: mem to mem\n");
	return 0;
	}
	//somethihg to immediate
	if(strchr(token2,"$")!=NULL){
	printf("Error: Destination is immediate\n");
	return 0;
	}
    }
    //printf("if valid, return 1\n");
    //printf("otherwise, return 0\n");
    return 1;
}

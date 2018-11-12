#include "myas.h"

int is_valid(char *op, char *args)
{
    char seps[]=",";//delimit
    char *ctoken1,*ctoken2;
    char *n;
    n=(char *)malloc(sizeof(char)*50);
    ctoken1=(char *)malloc(sizeof(char)*50);
    ctoken2=(char *)malloc(sizeof(char)*50);
    strcpy(n,args);

    //make token
    strcpy(ctoken1,strtok(n,seps));
    strcpy(ctoken2,strtok(NULL,seps));
   
    //case1 : first String is not mov
    if(strcmp(op,"mov")!=0){
	    printf("Error: Instruction is not mov!!\n");
	    return 0;
    }
    //destination is immediate
    if(strchr(ctoken2,'$')!=NULL){
    printf("Error: Destination is immediate\n");
    return 0;
    }
    else{
    //mem to mem
    if(ctoken1[0]!='%'&&ctoken2[0]!='%'){
    printf("Error: mem to mem\n");
    return 0;
    }
    }
    //printf("if valid, return 1\n");
    //printf("otherwise, return 0\n");
    return 1;
}

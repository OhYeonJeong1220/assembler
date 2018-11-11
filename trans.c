#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{//op:mov , args: next string, mcode: Opcode
    char seps[]=",";//delimit
    char *token;

    // check syntax
    //is_vaild() is in check.c 
    if(!is_valid(op, args)){
    	printf("Error: %s %s is not valid\n", op, args);
    	return 0;
    }

    strcpy(mcode, "AB CD EF");
    
    token = strtok(args, seps);
    while(token != NULL){
	if(strcmp(token,"%eax")==0){
	//reg(eax) to mem
	    strcpy(mcode,"a3");
	    break;
	}
	else{
	   //immediate to reg
	    if(strchr(token,'$')!=NULL){
		strcpy(mcode,"b8");
		break;
	    }	
	}
    }
    return 1;	
}

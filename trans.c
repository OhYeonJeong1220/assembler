#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{//op:mov , args: next string, mcode: Opcode
    char seps[]=",";//delimit
    char *token,*token1,*token2;

    // check syntax
    //is_vaild() is in check.c 
    if(!is_valid(op, args)){
    	printf("Error: %s %s is not valid\n", op, args);
    	return 0;
    }

    strcpy(mcode, "AB CD EF");
    
    token=strtok(args, seps);
    token1=token;//save first token
    token=strtok(NULL, seps);
    token2=token;//save second token
    
    if(strcmp(token1,"%eax")==0){
    //reg(eax) to mem
	strcpy(mcode,"a3");
    }
    else if(strcmp(token2,"%eax")==0){
    //mem to reg(eax)
	strcpy(mcode,"a1");
    }
    else{
	else if(strchr(token1,"$")!=NULL){
	//immediate to reg
	    strcpy(mcode,"b8");
	}
	else if(strchr(token1,"%")!=NULL){
	
	}
    }
    return 1;	
}

#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{//op:mov , args: next string, mcode: Opcode
    char seps[]=",";//delimit
    char *token1,*token2;
    char *m;


    m=(char *)malloc(sizeof(char)*50);
    strcpy(m,args);
    token1=(char *)malloc(sizeof(char)*50);
    token2=(char *)malloc(sizeof(char)*50);
    // check syntax
    //is_vaild() is in check.c 
    if(!is_valid(op, args)){
    	printf("Error: %s %s is not valid\n", op, args);
    	return 0;
    }


    strcpy(token1,strtok(m,seps));
    strcpy(token2,strtok(NULL,seps));
    if(strcmp(token1,"%eax")==0 && (strchr(token2,'x')!=NULL || strchr(token2,'(')!=NULL)){
    //reg(eax) to mem
	strcpy(mcode,"a3");
    }   
    else if((strchr(token1,'$')==NULL)&&(strchr(token1,')')==NULL)&&(strchr(token1,'x')!=NULL)&&(strcmp(token2,"%eax")==0)){
    //mem to reg(eax)
	strcpy(mcode,"a1");
    }
    else{
	if(strchr(token1,'$')!=NULL){
	//immediate to reg
	    if(strcmp(token2,"%eax")==0){
	    strcpy(mcode,"b8");
	    }
	    else if(strcmp(token2,"%ecx")==0){
	    strcpy(mcode,"b9");
	    }
	    else if(strcmp(token2,"%edx")==0){
	    strcpy(mcode,"ba");
	    }
	    else if(strcmp(token2,"%ebx")==0){
	    strcpy(mcode,"bb");
	    }
	    else if(strcmp(token2,"%esp")==0){
	    strcpy(mcode,"bc");
	    }
	    else if(strcmp(token2,"%ebp")==0){
	    strcpy(mcode,"bd");
	    }
	    else if(strcmp(token2,"%esi")==0){
	    strcpy(mcode,"be");
	    }
	    else if(strcmp(token2,"%edi")==0){
	    strcpy(mcode,"bf");
	    }
	}
	else if(strchr(token1,'%')!=NULL){
	    //mem to reg(disp) 
	    if(strchr(token1,'(')!=NULL){
		strcpy(mcode,"8b");
	    }
	    //reg to reg
	    else{
		strcpy(mcode,"89");
	    }
	}
	else{
	//no case
	    printf("This sytax is not match to mov-format\n");
	}
    }
    return 1;	
}

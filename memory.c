#include <stdio.h>
#include "memorylib.h"

int binCode(int address){ 
	int z;
	sc_memoryGet(address,&z);
	int i;
	printf("\n");
	for(i = 14; i >= 0; i--){
		int temp = (z>>i)&0x1;
		printf("%d",temp);
	}
	printf("\n");
}

int main(){
	int  value, ch1, ch2, address;
	char buf[10],name[10]="file.bin";
	sc_memoryInit();
	//write(1,"Set address and value:\n",24);
	scanf("%d %d",&address,&value);
	sc_memorySet(address, value);
	sc_memoryPrint();
	sc_memoryGet(address, &value);
	printf("%d\n",value);
	sc_memorySave(name);

	sc_memoryInit();
	sc_memoryLoad(name);
	printf("\nIn file:\n");
	sc_memoryPrint();

	int reg;
	sc_regSet(P,0);
	sc_regSet(T,0);
	sc_regSet(O,0);
	sc_regSet(M,0);
	sc_regSet(E,0);

	sc_regGet(P,&reg);
	if (reg)
	     printf("Flag P\n");
	sc_regGet(T,&reg);
	if (reg)
             printf("Flag T\n");
	sc_regGet(O,&reg);
	if (reg)
	     printf("Flag O\n");
	sc_regGet(M,&reg);
	if (reg)
	     printf("Flag M\n");
	sc_regGet(E,&reg);
	if (reg)
	     printf("Flag E\n");

	int value1;
	sc_commandEncode(0x15,0x22,&value1);
	//printf("%d",value1);
	int com, operand;
	sc_commandDecode(value1,&com,&operand);
	//printf("%d %d",com,operand);
	return 0;
}

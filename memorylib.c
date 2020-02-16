#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define operation overflow 1 // переполнение при выполнении операции  
#define division error by 2 // ошибка деления на ноль (0)
#define error beyond memory boundaries 3 // ошибка выхода заграницы памяти
#define ignore 4 // игнорирование тактовых импульсов
#define decree invalid command 5 // указана неверная команда

using namespace std;

const int size = 100;;
int mass[size];
short int reg;

int sc_memoryInit() {
  for (int i = 0; i < size; i++) {
    mass[i] = 0;
  }
  return 0;
}

int sc_memoryPrint(){ // фукнция для вывода значений из оперативной памяти на экран
    for(int i = 0; i<100; i++)
	printf("0x%x ", mass[i]);
    return 0;
}

int sc_memorySet(int address, int value) {
  if ((address > 0) || (address <= size)) {
    mass[address] = value;
    return 0;
  } else {
    cout << "Error" << endl;
    exit(-1);
    return 0;
  }
}

int sc_memoryGet(int address, int *value) {
  if ((address > 0) || (address <= size)) {
    *value = mass[address];
    return 0;
  } else {
    cout << "Error" << endl;
    exit(-1);
    return 0;
  }
}

int sc_memorySave(char *filename) {
  FILE *f;
  f = fopen(filename, "wb");
  fwrite(mass, sizeof(mass), size, f);
  fclose(f);
  return 0;
}

int sc_memoryLoad(char *filename) {
  FILE *f;
  f = fopen(filename, "rb");
  fread(mass, sizeof(mass), size, f);
  fclose(f);
  return 0;
}

int sc_regInit(void){ 
    flag = 0; 
    return 0;
}

int sc_regSet (int reg, int value) { 
    if((reg>4) || (reg<0)){ 
        printf("Error!\n");
        return 1;
    }
    if(value!=1 && value!=0){ 
   	printf("Error!\n");
        return 1;
    }
    if(value){
        flags=flags|(1<<(reg-1));  
    } else {
        flags=flags&(~(1<<(reg-1)));  
    }
    return 0;
}

int sc_regGet(int reg,int *value) {
    if((reg>4) || (reg<0)) { 
        printf("Error! Invalid register number\n");
        return 1;
    }
    *value=(flags>>(reg-1))&0x1;  
    return 0;
}

int sc_commandEncode(int command, int operand, int *value){ 
	*value = command * 128 + operand;
	return 0;
}

int sc_commandDecode(int value,int *command,int *operand){ 
	*command = value/128;
	*operand = value%128;
	return 0;
}


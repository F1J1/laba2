#define P 0 
#define O 1
#define M 2
#define T 3
#define E 4
int sc_memoryInit();
int sc_memoryPrint();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address,int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
int sc_regInit(void);
int sc_regSet (int reg, int value);
int sc_regGet(int reg,int *value);
int sc_commandEncode(int command, int operand, int *value);
int sc_commandDecode(int value,int *command,int *operand);

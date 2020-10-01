#ifndef ___IntStack
#define	___IntStack

typedef struct
{
	int nMaxCapacity;
	int nStackPointer;
	int *pnStack;
}IntStack;

int InitStack(IntStack* s, int nMaxCapacity);
int PushStack(IntStack* s, int nData);
int PopStack(IntStack* s, int* pnData);
int PeekStack(IntStack* s, int* pnData);
void ClearStack(IntStack* s);
void PrintStack(const IntStack* s);

int StackCapacity(const IntStack* s);
int StackPointerIdx(const IntStack* s);
int IsStackEmpty(const IntStack* s);
int IsStackFull(const IntStack* s);

void DestroyStack(IntStack* s);
#endif
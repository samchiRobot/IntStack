#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int InitStack(IntStack* s, int nMaxCapacity)
{
	s->nStackPointer = 0;
	s->pnStack = calloc(nMaxCapacity, sizeof(int));
	if (s->pnStack == NULL)		// memory allocation failed
	{
		s->nMaxCapacity = 0;
		return -1;
	}
	s->nMaxCapacity = nMaxCapacity;
	return 0;
}

int PushStack(IntStack* s, int nData)
{
	if (IsStackFull(s))	// stack is full
		return 1;
	s->pnStack[s->nStackPointer++] = nData;
	return 0;
}

int PopStack(IntStack* s, int *pnData)
{
	if (IsStackEmpty(s))
		return 1;
	*pnData = s->pnStack[--s->nStackPointer];
	return 0;
}

int PeekStack(IntStack* s, int* pnData)
{
	if (IsStackEmpty(s))
		return 1;
	*pnData = s->pnStack[s->nStackPointer-1];
	return 0;
}

void PrintStack(const IntStack* s)
{
	printf("Stack max capacity : %d, Stack Pointer : %d\n", s->nMaxCapacity, s->nStackPointer);
	if (s->nStackPointer > 0) 
	{
		for (int i = 0; i < s->nStackPointer; i++)
		{
			printf("[%d] : %d ", i, s->pnStack[i]);
		}
		printf("\n");
	}
}

void ClearStack(IntStack* s)
{
	for (int i = 0; i < s->nStackPointer; i++)
	{
		s->pnStack[i] = 0;
	}
	s->nStackPointer = 0;
}

int StackCapacity(const IntStack* s)
{
	return s->nMaxCapacity;
}

int StackPointerIdx(const IntStack* s)
{
	return s->nStackPointer;
}

// Empty : 1, not empty : 0
int IsStackEmpty(const IntStack* s)
{
	return s->nStackPointer <= 0;
}

// Full : 1, not full : 0
int IsStackFull(const IntStack* s)
{
	return s->nStackPointer >= s->nMaxCapacity;
}

void DestroyStack(IntStack* s)
{
	s->nMaxCapacity = 0;
	s->nStackPointer = 0;
	if(s->pnStack != NULL)
		free(s->pnStack);
}
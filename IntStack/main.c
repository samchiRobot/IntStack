#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntStack.h"

#define MAX_STACK_SIZE (32)

int Menu(const IntStack* s);
enum eMenuTable
{
	kMenuExit,
	kMenuPush,
	kMenuPop,
	kMenuPeek,
	kMenuPrint
};

int main(void)
{
	IntStack s;
	IntStack* sp=&s;
	int ret = 0;
	int nMenu = 0;
	int temp = 0;

	if (InitStack(sp, MAX_STACK_SIZE) == 1)
	{
		perror("Failed to initailize stack!\n");
		return 1;
	}
	printf("Initialized!\n");
	PrintStack(sp);

	while (1)
	{
		nMenu = Menu(sp);
		if (nMenu == kMenuExit)
		{
			printf("Exiting....\n");
			break;
		}
		
		switch (nMenu)
		{
			case kMenuPush:
				printf("Push Data: ");
				scanf("%d", &temp);
				if (PushStack(sp, temp))
					printf("Push Failed! (stack is full)\n");
				else
					printf("Push OK\n");
				break;
			case kMenuPop:
				if (PopStack(sp, &temp))
					printf("Pop Failed! (stack is empty)\n");
				else
					printf("Pop OK, Data: %d\n", temp);
				break;
			case kMenuPeek:
				if (PeekStack(sp, &temp))
					printf("Peek Failed! (stack is empty)\n");
				else
					printf("Peek OK, Data: %d\n", temp);
				break;
			case kMenuPrint:
				PrintStack(sp);
				break;
			default:
				break;
		}
	}
	DestroyStack(sp);
	return 0;
}

int Menu(const IntStack *s)
{
	int nMenu = 0;
	while (1)
	{
		printf("\nStack Status : %d/%d\n",s->nStackPointer,s->nMaxCapacity);
		printf("1.Push 2.Pop 3.Peek 4.Print 0.Exit: ");
		scanf("%d", &nMenu);
		if (nMenu >= kMenuExit && nMenu <= kMenuPrint)
			break;
		else
			printf("Invalid menu!\n");
	}
	return nMenu;
}

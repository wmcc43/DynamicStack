/*
 * main.c
 *
 *  Created on: 2013/11/5
 *      Author: cart
 */
#include<stdio.h>
#include<string.h>
#include"stack/stack.h"

int main(void)
{
	Stack *stack=newStack("test");
	stack->push(stack,"test2");
	stack->push(stack,"test3");
	char buff[MAXBUFF];
	memset(buff,'\0',MAXBUFF);
	int i;
	for(i=0;i<10;i++)
	{
		sprintf(buff,"%d",i+10);
		stack->push(stack,buff);
		memset(buff,'\0',MAXBUFF);
	}
	while(stack!=NULL)
	{
		strcat(buff,stack->pop(&stack));
		printf("%s,",buff);
		memset(buff,'\0',MAXBUFF);
	}
	return 0;
}

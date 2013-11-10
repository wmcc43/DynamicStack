/*
 * stack.c
 *
 *  Created on: 2013/11/5
 *      Author: cart
 */
#include<stdio.h>
#include<string.h>
#include"stack.h"
static char *popFunc(Stack **stack);
static int pushFunc(Stack *stack,char *string);

static int pushFunc(Stack *stack,char *string)
{
	Stack **new=&stack;
	Stack *pointer=stack;
	Stack *newitem=(Stack *)malloc(sizeof(Stack));
	if(stack==NULL)
		(*new)=newStack(string);
	while(pointer->next!=NULL)
		pointer=pointer->next;
	memset((newitem->string),'\0',MAXBUFF);
	strcat((newitem->string),string);
	newitem->pop=popFunc;
	newitem->push=pushFunc;
	newitem->next=NULL;
	pointer->next=newitem;
	return 0;
}

static char *popFunc(Stack **stack)
{
	Stack **pointer=stack;
	Stack *temp;
	Stack *previous=NULL;
	char string[MAXBUFF];
	memset(string,'\0',MAXBUFF);
	while((*pointer)->next!=NULL)
	{
		if((*pointer)->next->next==NULL)
			previous=(*pointer);
		pointer=&((*pointer)->next);
	}
	temp=(*pointer);
	strcat(string,(*pointer)->string);
	if(previous!=NULL)
		previous->next=NULL;
	if(pointer!=stack)
		free(temp);
	else
	{
		free((*stack));
		(*stack)=NULL;
	}
	return string;
}

Stack *newStack(char *string)
{
	Stack *newStack=(Stack *)malloc(sizeof(Stack));
	memset((newStack->string),'\0',MAXBUFF);
	strcat((newStack->string),string);
	newStack->pop=popFunc;
	newStack->push=pushFunc;
	newStack->next=NULL;
	return newStack;
}

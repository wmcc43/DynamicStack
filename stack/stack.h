/*
 * stack.h
 *
 *  Created on: 2013/11/5
 *      Author: cart
 */
#ifndef STACK_H_
#define STACK_H_
#endif /* STACK_H_ */

#define MAXBUFF 256

typedef int (*pushFuncPnt)(void *,char *);
typedef char *(*popFuncPnt)(void **);

struct Stack
{
	char string[MAXBUFF];
	pushFuncPnt push;//int func(Stack *stack,char *string)
	popFuncPnt pop;//char func(Stack **stack)
	struct Stack *next;

}typedef Stack;

Stack *newStack(char *string);

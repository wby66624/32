#ifndef  _stack_H
#define  _stack_H
#include <stdio.h>
#include "menu.h"
typedef Mycourse Var;//�����������
typedef struct _stack
{
	Var data[10];//����ռ�Ĵ�С
	int top;//ջָ��
}MyStack;

int StackIsEmpty(MyStack stack);//�ж�ջ�Ƿ�Ϊ��
int Push(MyStack *stack, Var data);//��ջ����
int Pop(MyStack *stack, Var *data);//��ջ����

#endif 


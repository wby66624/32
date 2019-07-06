#include "stack.h"
int StackIsEmpty(MyStack stack)//�ж�ջ�Ƿ�Ϊ��
{
	return stack.top == -1;
}
int Push(MyStack *stack, Var data)//��ջ����
{
	int size = sizeof(stack->data) / sizeof(stack->data[0]);//�õ�����ĳ���
	if (stack->top < 9)
	{
		stack->top++;
		stack->data[stack->top].all_Line = data.all_Line;//���ݽ�ջ
		stack->data[stack->top].page_skewing = data.page_skewing;//���ݽ�ջ
		stack->data[stack->top].set_y = data.set_y;//���ݽ�ջ
		return 1;//��ջ�ɹ�
	}
	else
	{
		return 0;//��ջʧ��
	}
}
int Pop(MyStack *stack, Var *data)//��ջ����
{
	if (!StackIsEmpty(*stack))//�ж�ջ�Ƿ�Ϊ��
	{
		data->all_Line = stack->data[stack->top].all_Line;
		data->set_y = stack->data[stack->top].set_y;
		data->page_skewing = stack->data[stack->top--].page_skewing;
		return 1;//��ջ�ɹ�
	}
	else
	{
		return 0;//��ջ�ɹ�
	}
}












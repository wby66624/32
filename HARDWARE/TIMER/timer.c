#include "timer.h"
#include "main.h"

void TIM2_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef PWM_OUT;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);	//ʹ�ܶ�ʱ��2ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��

	
	PWM_OUT.GPIO_Mode = GPIO_Mode_AF_PP;
	PWM_OUT.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;
	PWM_OUT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&PWM_OUT);
	


	//��ʼ��TIM2	
	TIM_TimeBaseInitStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStrue.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStrue.TIM_Period = arr;
	TIM_TimeBaseInitStrue.TIM_Prescaler = psc;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStrue);
	
	//��ʼ��TIM2 Channel1 PWMģʽ	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC1
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR2�ϵ�Ԥװ�ؼĴ���

 	//��ʼ��TIM2 Channel2 PWMģʽ	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC2
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);  //ʹ��TIM2��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM2 OC2
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);  
	
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
	TIM_Cmd(TIM2, ENABLE);  //ʹ��TIM2
}

void TIM4_PWM_Init(u16 arr,u16 psc)
{
	GPIO_InitTypeDef PWM_OUT;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	//NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	//ʹ�ܶ�ʱ��2ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��

	
	PWM_OUT.GPIO_Mode = GPIO_Mode_AF_PP;
	PWM_OUT.GPIO_Pin = GPIO_Pin_6;
	PWM_OUT.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&PWM_OUT);

	//��ʼ��TIM4	
	TIM_TimeBaseInitStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStrue.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStrue.TIM_Period = arr;
	TIM_TimeBaseInitStrue.TIM_Prescaler = psc;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStrue);
	
	//��ʼ��TIM4 Channel1 PWMģʽ	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM4 OC1
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);  //ʹ��TIM4��CCR2�ϵ�Ԥװ�ؼĴ���
 

	
//TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
	
//	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4�ж�
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
//	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���
	
	TIM_Cmd(TIM4, ENABLE);  //ʹ��TIM4
}

//void TIM4_IRQHandler(void)
//{
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET)

//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//}

void TIM3_Int_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStrue;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitStrue.TIM_Period = arr;
	TIM_TimeBaseInitStrue.TIM_Prescaler = psc;
	TIM_TimeBaseInitStrue.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStrue.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStrue);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx					 
}

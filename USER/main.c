//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//All rights reserved
//******************************************************************************/
#include "stm32f10x.h"
#include "delay.h"
#include "menu.h"
#include "OLED.H"
#include "Queue.h"
#include "stack.h"
#include "stdio.h" 
#include "key.h"
#include "math.h"
#include "spwm.h"
#include "adc.h"
#include "dma.h"
#include "main.h"
#include "feedback.h"
#include "sys.h"
#include "stm32f10x.h" 

#define FLASH_SAVE_ADDR  0X08070000		//����FLASH �����ַ(����Ϊż��������ֵҪ���ڱ�������ռ��FLASH�Ĵ�С+0X08000000)

u16 DMA_ADC[ADC_NUM][3] = {0};
//ADC����������ȡ����
int ADC_1[NUM_SIZE] = {0};
int ADC_2[NUM_SIZE] = {0};
int ADC_3[NUM_SIZE] = {0};
float validity_i1[NUM_SIZE] = {0};
float validity_i2[NUM_SIZE] = {0};
u16 rrr;//rrr��װֵ
u16 percent_w,percent_r,rrrr;	
float a=0;//��Ƶ�����
float ADC_I=0;	u16 ADC_I0=0;	
float ADC_I1=0;
int ADC_FACTI;
float rr;//��������1  **���յ���   ��ʼ����   ʵ��ad
float sin_p,youxiaozhi=0,shurudianliu=0.260*35,shuchudianliu=81/20;;//���Ұٷֱ�
int Hz = 50,sss=1;//��·Ƶ�� 4420  657
int pp=1,p=0,sin_f=0,b=1,c=0,ppp=0,V=9,cc=1,pppp=1;//398--80  524-60   760-40
extern MenuPage firstPage;
int jingdu=10;
u16 adcx;

int main(void)
{
   rrr =1599;
	delay_init();	    	 //��ʱ������ʼ��	 
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	TIM2_PWM_Init(rrr,0);
   //TIM4_PWM_Init(8999,0);
	TIM3_Int_Init(4999,10);
	Init_Menue(&firstPage);
	Adc_Init();		  		//ADC��ʼ��	  
	MYDMA_Config(DMA1_Channel1,(u32)&ADC1->DR,(u32)DMA_ADC[0],ADC_NUM*3);
   OLED_Init();
	KEY_Init();  
	sin_max = rrr/2+300;// 339-15// 491-12 363-9   613-15  743-18 30v
   //TIM4->CCR1 = 4499;
	while(1)
	{
//		adcx=Get_Adc_Average(ADC_Channel_8,10);
	   Menue_Show();
	   KeyNumGet(KEY_Scan());
//      TIM_SetAutoreload(TIM2,rrr-1);
//	   youxiaozhi = Filter_Init(validity_i1,NUM_SIZE);
	}
}

//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
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

#define FLASH_SAVE_ADDR  0X08070000		//设置FLASH 保存地址(必须为偶数，且其值要大于本代码所占用FLASH的大小+0X08000000)

u16 DMA_ADC[ADC_NUM][3] = {0};
//ADC采样数据提取数组
int ADC_1[NUM_SIZE] = {0};
int ADC_2[NUM_SIZE] = {0};
int ADC_3[NUM_SIZE] = {0};
float validity_i1[NUM_SIZE] = {0};
float validity_i2[NUM_SIZE] = {0};
u16 rrr;//rrr重装值
u16 percent_w,percent_r,rrrr;	
float a=0;//变频不变幅
float ADC_I=0;	u16 ADC_I0=0;	
float ADC_I1=0;
int ADC_FACTI;
float rr;//操作电流1  **最终电流   初始电流   实际ad
float sin_p,youxiaozhi=0,shurudianliu=0.260*35,shuchudianliu=81/20;;//正弦百分比
int Hz = 50,sss=1;//电路频率 4420  657
int pp=1,p=0,sin_f=0,b=1,c=0,ppp=0,V=9,cc=1,pppp=1;//398--80  524-60   760-40
extern MenuPage firstPage;
int jingdu=10;
u16 adcx;

int main(void)
{
   rrr =1599;
	delay_init();	    	 //延时函数初始化	 
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	TIM2_PWM_Init(rrr,0);
   //TIM4_PWM_Init(8999,0);
	TIM3_Int_Init(4999,10);
	Init_Menue(&firstPage);
	Adc_Init();		  		//ADC初始化	  
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

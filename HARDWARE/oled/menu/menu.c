#include "menu.h"
#include "OLED.H"
#include "Queue.h"
#include "stack.h"

#include "main.h"
#include "feedback.h"
Queue KeyQueue;//¼üÖµ¶ÓÁĞ
MyStack DataStack;//Êı¾İÕ»
char KeyNum = 0;//È«¾ÖµÄ¼üÖµ
Mycourse cour = { 0,1 ,0 };//³õÊ¼»¯¹â±ê
Mycourse *course = &cour;//¶¨ÒåÈ«¾Ö¹â±ê²¢³õÊ¼»¯
MenuPage *nowPage;//µ±Ç°µÄÒ³Ãæ
MenuPage firstPage;//Ò³ÃæÒ»

int sequence=6;

MenuPage Servo_1;//Ò³Ãæ1
MenuPage Servo_2;//Ò³Ãæ2
MenuPage Servo_3;//Ò³Ãæ3
MenuPage Servo_4;//Ò³Ãæ4
MenuPage Servo_5;//Ò³Ãæ5
MenuPage Sequence;
MenuPage Width;
int target_v,sheng,jiang;


extern int sin_max,pp,p,c,V;
extern  float  youxiaozhi,shurudianliu,shuchudianliu;
extern u16 rrr;
extern u16 adcx;
/**
 * http://www.flvcd.com/
 *  .--,       .--,
 * ( (  \.---./  ) )
 *  '.__/o   o\__.'
 *     {=  ^  =}
 *      >  -  <
 *     /       \
 *    //       \\
 *   //|   .   |\\
 *   "'\       /'"_.-~^`'-.
 *      \  _  /--'         `
 *    ___)( )(___
 *   (((__) (__)))   ¸ßÉ½ÑöÖ¹£¬¾°ĞĞĞĞÖ¹£¬Ëä²»ÄÜÖÁ£¬ĞÄÍùÏòÖ®
 */



//-----------------------²Ëµ¥Ê×Ò³--------------------------------
_Menue(firstPage, "MENU", PAGE_NULL,
{
	Set_Courese(8);
	//1ĞĞ Ğ§ÂÊ
	Show_Text(1,"efficiency:%f",	shuchudianliu/shurudianliu);
	Change_Page(1,&Servo_1);
	//2ĞĞ µçÑ¹
	Show_Text(2,"V:%d",V);
	Change_Data3(2,&V);
	if(V<0) V=0;
	Change_Page(2,&Servo_2);
	//3ĞĞ ÆµÂÊ
	Show_Text(3,"Hz:%d",Hz);
	Change_Data4(3,&Hz);
	if(Hz>80) Hz=80;
	if(Hz<0) Hz=0;
	Change_Page(3,&Servo_3);
	//4ĞĞ Ä£Ê½
	Show_Text(4,"MODE:%d",p);
	Change_Data(4,&p);
	if(p>2)p=2;if(p<0)p=0;
	Change_Page(4,&Servo_4);
	//5ĞĞ ÊäÈëµçÁ÷
	Show_Text(5,"P_in(w):%f",shurudianliu);
	Change_Page(5,&Servo_5);
	//6ĞĞ Êä³öµçÁ÷
	Show_Text(6,"P_out(w):%f",shuchudianliu);
	Change_Page(6,&Sequence);
	//7ĞĞ Õ¼¿Õ±È
	Show_Text(7,"PWM_duty:%d",sin_max);
	Change_Page(7,&Width);
	Change_Data(7,&sin_max);
	if(sin_max<0) sin_max=0;
	//8ĞĞ adcÖµ
	Show_Text(8,"ADC:%d",adcx);
})
//Servo_1Ò³Ãæ
_Menue(Servo_1, "sin_max", &firstPage,
{
	Set_Courese(1);
	Show_Text(1,"sin_max:%d",sin_max);
	Change_Data3(1,&sin_max);
})
//Servo_2Ò³Ãæ
_Menue(Servo_2, "target_v", &firstPage,
{
	Set_Courese(1);
	Show_Text(1,"target_v:%d",target_v);
	Change_Data(1,&target_v);
	if(target_v>1250)target_v=1250;
	else if(target_v<2)target_v=2;
})
//Servo_3Ò³Ãæ
_Menue(Servo_3, "Hz", &firstPage,
{
	Set_Courese(1);
	Show_Text(1,"Hz:%d",Hz);
	Change_Data4(1,&Hz);	
})
//Servo_4Ò³Ãæ
_Menue(Servo_4, "p", &firstPage,
{
	Set_Courese(1);
	Show_Text(1,"p:%d",p);
	Change_Data(1,&p);
//		if(Servo4.target>1250)Servo4.target=1250;else if(Servo4.target<250)Servo4.target=250;
})
	
//_Menue(Servo_5, "Servo5", &firstPage,
//	{
//		Set_Courese(1);
//		Show_Text(1,"Servo5_angele:%d",Servo5.target);
//		 Change_Data(1,&Servo5.target);
//		if(Servo5.target>1250)Servo5.target=1250;else if(Servo5.target<250)Servo5.target=250;
//	})
//	
//_Menue(Sequence, "Sequence", &firstPage,
//	{
//		Set_Courese(1);
//		Show_Text(1,"Sequence:%d",sequence);
//		 Change_Data(1,&sequence);                //0 ºìÂÌÀ¶ 1 ºìÀ¶ÂÌ 2 ÂÌºìÀ¶ 3 ÂÌÀ¶ºì 4 À¶ºìÂÌ 5 À¶ÂÌºì
//	})
//	
//_Menue(Width, "Width", &firstPage,
//	{
//		Set_Courese(1);
//		Show_Text(1,"Width:%f",camere_distance);
//		 Change_Data1(1,&camere_distance);              
//	})	
//-------------------------²Ëµ¥ÏÔÊ¾º¯Êı-------------------------------------
		void Menue_Show()//ÏÔÊ¾µ±Ç°Ò³Ãæ
	{
		OLED_Fill();
		nowPage->nowPage();
		OLED_Refresh_Gram();
	}
//-------------------------²Ëµ¥³õÊ¼»¯º¯Êı-----------------------------------
	void Init_Menue(MenuPage *page)
	{
		OLED_Init();//³õÊ¼»¯LED
		OLED_Clear();//¶ÔLEDÇëÆÁ
		KeyQueue.first = 0;//³õÊ¼»¯¼üÖµ¶ÓÁĞ
		KeyQueue.last = 0;
		DataStack.top = -1;//³õÊ¼»¯Êı¾İÕ»
		nowPage = page;//µÃµ½³õÊ¼»¯Ò³Ãæ
	}
//-------------------------½«°´¼üµÄ¼üÖµ´æÈë¶ÓÁĞ-----------------------------
	void KeyNumGet(int key)
	{
		IQueue(&KeyQueue, key);
	}
	void StringCopy(char *desition, char *source, char length)//copyÒ»¸ö×Ö·û´®ÖĞµÄÒ»¶¨³¤¶ÈµÄÊı¾İµ½ÁíÒ»×Ö·û´®
	{
		int i = 0;
		for (i = 0; i < length; i++)
		{
			*(desition++) = *(source++);
		}
	}
//------------------------¼ÆËãµ±Ç°Ó¦¸ÃÏÔÊ¾µÄĞĞ------------------------------
	int CountLine(int location)
	{
		return location - course->page_skewing;
	}
//------------------------ÅĞ¶ÏÊÇ·ñÔÚ¿ÉÏÔÊ¾µÄĞĞ------------------------------
	int CanShow(int location)
	{
		int cm = location - course->page_skewing;
		return cm > 0 && cm < MAX_LINE + 1;
	}
//------------------------»­Ïßº¯Êı-----------------------------------------
	void Draw_line(float X1, float Y1, float X2, float Y2)
	{
		int i = 0;
		if ((X2 - X1) != 0)//ÅĞ¶ÏĞ±ÂÊÊÇ·ñ´æÔÚ
		{
			float k = (Y2 - Y1) / (X2 - X1);//µÃµ½Ö±ÏßµÄĞ±ÂÊ
			float d = Y1 - k * X1;//µÃµ½ÓëYÖáµÄ¼Ğ½Ç
			unsigned char length = abs((int)(X1 - X2)) + 1;//µÃµ½XÖá·½Ïò»æÖÆµÄ³¤¶È
			for (i = 0; i < length; i++)
			{
				OLED_DrawPoint(X1 + i, k*(X1 + i) + d, 1);
			}
		}
		else
		{
			for (i = 0; i < Y2 - Y1 + 1; i++)
			{
				OLED_DrawPoint(X1, Y1 + i, 1);
			}
		}
	}
//-------------------------------»­¾ØĞÎ-----------------------------------------
	void Draw_Rectangle(char x, char y, char width, char height)
	{
		Draw_line(x, y, x + width, y);
		Draw_line(x, y, x, y + height);
		Draw_line(x, y + height, x + width, y + height);
		Draw_line(x + width, y, x + width, y + height);
	}
//---------------------------------»­Ô²-----------------------------------------
	void Draw_Circle(float x, float y, float R)
	{
		float angle = 0;//³õÊ¼½Ç¶È
		for (angle = 0; angle < 360; angle += 1)
		{
			OLED_DrawPoint(R*sin(angle*3.14 / 180) + x, y + R * cos(angle*3.14 / 180), 1);
		}
	}
//---------------------------------»­¹â±ê--------------------------------------
	void Draw_course(char x, char y)
	{
		if (y > 7)
		{
			y = 7;
		}
		OLED_ShowString(x, y, ">");
	}
//--------------------------------µÃµ½¼üÖµ-------------------------------------
	void Get_key(int allLine)
	{
		KeyNum = OQueue(&KeyQueue);
		if (KeyNum == KEY_DOWN)
		{
			course->set_y += 1;//¹â±êÖ¸Õë¼ÓÒ»
			if (allLine > MAX_LINE)
			{
				if (course->set_y > MAX_LINE)
				{
					course->set_y = MAX_LINE;
					course->page_skewing += 1;//Ò³ÃæÖ¸ÕëÆ«ÒÆÁ¿¼ÓÒ»
					if (course->page_skewing > (allLine - MAX_LINE))//ÏŞÖÆÒ³ÃæÖ¸ÕëÆ«ÒÆÁ¿µÄÔö¼Ó
					{
						course->page_skewing = allLine - MAX_LINE;
					}
				}
			}
			else
			{
				if (course->set_y > allLine)
				{
					course->set_y = allLine;
				}
			}
		}
		else if (KeyNum == KEY_UP)
		{
			course->set_y -= 1;
			if (course->set_y < 1)
			{
				course->set_y = 1;
				if (course->page_skewing > 0)
				{
					course->page_skewing -= 1;//Ò³ÃæÆ«ÒÆÁ¿¼õÒ»
				}
			}
		}
		else if (KeyNum == kEY_BANK)//Èç¹ûÊÇ·µ»Ø¼ü
		{
			if (nowPage->fatherPage != NULL)//Èç¹ûÓĞ¸¸Ò³Ãæ
			{
				nowPage = nowPage->fatherPage;//¸Ä±äÒ³Ãæ
				Pop(&DataStack, course);//Í¬Ê±È¡³öÊı¾İÕ»ÀïÃæµÄÊı¾İ
			}
		}
	}
//--------------------------------ÏÔÊ¾ÎÄ±¾----------------------------------------
	void Show_Text(char location, char *name, ...)
	{
		va_list vp;
		int d = 0; float f = 0;
		char *p;
		char ap[BUFF_LENGTH] = { 0 };
		char data[10] = { 0 };//ÓÃÓÚ´¢´æÊı¾İ
		if (!CanShow(location))return;//²»ÔÚ¿ÉÏÔÊ¾µÄĞĞÖ±½ÓÍË³ö
		va_start(vp, name);
		p = strstr(name, "%");
		if (p)
		{
			StringCopy(ap, name, p - name);//µÃµ½%Ç°ÃæµÄÖµ
			p++;
			switch (*p)
			{
			case 'd':
			{d = va_arg(vp, int);//µÃµ½Êı¾İ
			sprintf(data, "%d", d);//½«Êı¾İ×ª»»³É×Ö·û´®
			break; }
			case 'f':
			{
				f = va_arg(vp, double);//µÃµ½Êı¾İ
				sprintf(data, "%.2f", f);//½²Êı¾İ×ª»»³É×Ö·û´®
				break; }
			default:break;
			}
			strcat(ap, data);//Á¬½ÓÁ½¸ö×Ö·û´®
			OLED_ShowString(10, CountLine(location), ap);//ÏÔÊ¾
		}
		else
		{
			OLED_ShowString(10, CountLine(location), name);//ÏÔÊ¾
		}
		va_end(vp);
	}
//---------------------------------ÊıÖµ¸Ä±äº¯Êı-------------------------------------------
	
		void Change_Data2(char location, int *data)
	{
		if ((course->page_skewing + course->set_y) == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
		{
			if (KeyNum == KEY_RIGHT)//Èç¹û¼üÖµÊÇRIGHTÔòÊı¾İ¼Ó
			{
				*data += STEPNUM;//Êı¾İ¼
				pp=1;
			}
			if (KeyNum == kEY_LEFT)
			{
				*data -= STEPNUM;
				pp=2;
			}
		}
	
	}
	
	
			void Change_Data3(char location, int *data)
	{
		if ((course->page_skewing + course->set_y) == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
		{
			if (KeyNum == KEY_RIGHT)//Èç¹û¼üÖµÊÇRIGHTÔòÊı¾İ¼Ó
			{
				*data += STEPNUM1;//Êı¾İ¼
	
			}
			if (KeyNum == kEY_LEFT)
			{
				*data -= STEPNUM1;

			}
		}
	
	}
				void Change_Data4(char location, int *data)
	{
		if ((course->page_skewing + course->set_y) == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
		{
			if (KeyNum == KEY_RIGHT)//Èç¹û¼üÖµÊÇRIGHTÔòÊı¾İ¼Ó
			{
				*data += STEPNUM2;//Êı¾İ¼
	
			}
			if (KeyNum == kEY_LEFT)
			{
				*data -= STEPNUM2;

			}
		}
	
	}
	
	
	
	
	
	
	
	void Change_Data(char location, int *data)
	{
		if ((course->page_skewing + course->set_y) == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
		{
			if (KeyNum == KEY_RIGHT)//Èç¹û¼üÖµÊÇRIGHTÔòÊı¾İ¼Ó
			{
				*data += STEPNUM;//Êı¾İ¼
			
			}
			if (KeyNum == kEY_LEFT)
			{
				*data -= STEPNUM;
			
			}
		}
	}
//---------------------------------ÊıÖµ¸Ä±äº¯Êı-------------------------------------------
		void Change_Data1(char location, float *data)
		{
			if ((course->page_skewing + course->set_y) == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
			{
				if (KeyNum == KEY_RIGHT)//Èç¹û¼üÖµÊÇRIGHTÔòÊı¾İ¼Ó
				{
					*data += STEPNUM1;//Êı¾İ¼Ó
				}
				if (KeyNum == kEY_LEFT)
				{
					*data -= STEPNUM1;
				}
			}
		}	
	
//-----------------------------Ò³Ãæ¸Ä±äº¯Êı--------------------------------------------
	void Change_Page(char location, MenuPage *Page)
	{
		if (course->page_skewing + course->set_y == location)//ÅĞ¶ÏÊÇ·ñÑ¡ÖĞµ±Ç°ĞĞ
		{
			if (KeyNum == kEY_OK)//ÊÇÈ·¶¨¼ü
			{
				if (Page != NULL)
				{
					Push(&DataStack, *course);//½øÕ»
					nowPage = Page;//¸Ä±äÒ³Ãæ
					course->page_skewing = 0;//¹â±ê³õÊ¼»¯
					course->set_y = 1;
				}
			}
		}
	}
//---------------------------------»æÖÆÒ³Ãæ-----------------------------------------------
	void Set_Courese(int allLine)//»æÖÆÒ³Ãæ²¢ÇÒÉèÖÃ¹â±êµÄÎ»ÖÃ,Èë¿ÚÎª¸ÃÒ³ÃæËùÓĞµÄShow_Text()µÄĞĞÊı
	{
		int set = 0;
		float sa = 0;
		Get_key(allLine);//µÃµ½¼üÖµ
		set = strlen(nowPage->page);//µÃµ½±êÌâµÄ³¤¶È
		sa = (127 - (set-1) * 6) / 2;
		Draw_line(0, 60, sa - 6, 60);
		OLED_ShowString(sa - 6, 0, "<");
		OLED_ShowString(sa + set * 6, 0, ">");
		OLED_ShowString(sa, 0, nowPage->page);//»æÖÆ±êÌâ
		Draw_line(sa + set * 6 + 6, 60, 128, 60);
		Draw_line(8, 0, 8, 63);
		Draw_course(0, course->set_y);
	}


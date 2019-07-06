#ifndef _menu_H
#define _menu_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>


#define PAGE_NULL NULL//��ҳ�� 
#define MAX_LINE 7//��Ļ��ʾ����������
#define BUFF_LENGTH 20//��������ĳ���

#define KEY_UP 1
#define KEY_DOWN 2
#define kEY_LEFT 3
#define KEY_RIGHT 4
#define kEY_OK 5
#define kEY_BANK 6


#define STEPNUM 2 //���ݵĵ�ǰ����ֵ
#define STEPNUM1 30 //���ݵĵ�ǰ����ֵ
#define STEPNUM2 20
typedef struct Course//������
{
	int all_Line;//������
	int set_y;//����y����
	int page_skewing;//ҳ��ƫ����
}Mycourse;
typedef struct Menus
{
	char *page;//��ǰҳ�������
	struct Menus *fatherPage;//��ҳ��
	void(*nowPage) (void);//��ҳ�������
}MenuPage;

#define _Menue(name,pageName,fatherPage,program)\
void _##name(){program}                         \
MenuPage name ={pageName,fatherPage,_##name};


void Menue_Show(void);//��ʾ��ǰҳ��
void Draw_line(float X1, float Y1, float X2, float Y2);
void Init_Menue(MenuPage *page);//��ʼ���˵�
void StringCopy(char *desition, char *source, char length);
int CountLine(int location);//���㵱ǰӦ����ʾ����
int CanShow(int location);//�ж��Ƿ��ڿ���ʾ����
void Show_Text(char location, char *name, ...);
void Set_Courese(int allLine);//��ʾ����
void Draw_Rectangle(char x, char y, char width, char height);
void Draw_Circle(float x, float y, float R);
void Draw_course(char x, char y);
void KeyNumGet(int key);
void Get_key(int allLine);
void Change_Data4(char location, int *data);
void Change_Data3(char location, int *data);
void Change_Data2(char location, int *data);
void Change_Data(char location, int *data);
void Change_Data1(char location, float *data);
void Change_Page(char location, MenuPage *Page);
#endif

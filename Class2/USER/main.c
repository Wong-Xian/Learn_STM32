#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "key.h"
#include "24cxx.h"
#include "w25qxx.h"
#include "touch.h"

#include "timer.h"
#include "lvgl.h"
#include "lv_port_indev_template.h"
#include "lv_port_disp_template.h"

int main(void)
{
    HAL_Init();                    	 	//��ʼ��HAL��    
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//����ʱ��,72M
	delay_init(72);               		//��ʼ����ʱ����
	uart_init(115200);					//��ʼ������
	LED_Init();							//��ʼ��LED	
	KEY_Init();							//��ʼ������
//	LCD_Init();							//��ʼ��LCD
//	tp_dev.init();				   		//��������ʼ�� 
	
  	TIM3_Init(1000-1, 72-1);			// ��ʼ����ʱ��
	lv_init();							// ��ʼ��lvgl
	lv_port_disp_init();				// ��ʼ����ʾ��
	lv_port_indev_init();				// ��ʼ��������
	
	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj, 120, 60);
	lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);
	
	while (1)
	{
		delay_ms(5);
		lv_timer_handler();
	}
}


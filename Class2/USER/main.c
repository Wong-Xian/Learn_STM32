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

//#include "lv_demo_stress.h"
//#include "lv_demo_music.h"

int main(void)
{
    HAL_Init();                    	 	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函数
	uart_init(115200);					//初始化串口
	LED_Init();							//初始化LED	
	KEY_Init();							//初始化按键
//	LCD_Init();							//初始化LCD
//	tp_dev.init();				   		//触摸屏初始化 
	
  	TIM3_Init(1000-1, 72-1);			// 初始化定时器
	lv_init();							// 初始化lvgl
	lv_port_disp_init();				// 初始化显示屏
	lv_port_indev_init();				// 初始化触摸屏
	
	lv_obj_t* switch_obj1 = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj1, 120, 60);
	lv_obj_align(switch_obj1, LV_ALIGN_TOP_LEFT, 10, 10);
	
	lv_obj_t* switch_obj2 = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj2, 120, 60);
	lv_obj_align(switch_obj2, LV_ALIGN_TOP_MID, 0, 10);
	
	lv_obj_t* switch_obj3 = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj3, 120, 60);
	lv_obj_align(switch_obj3, LV_ALIGN_TOP_LEFT, 10, 80);

	
//	lv_demo_stress();
//	lv_demo_music();
	
	while (1)
	{
		delay_ms(5);
		lv_timer_handler();
	}
}


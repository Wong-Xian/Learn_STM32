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
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"


int main(void)
{
    HAL_Init();                    	 	//初始化HAL库    
    Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函数
	uart_init(115200);					//初始化串口
	LED_Init();							//初始化LED	
	KEY_Init();							//初始化按键

	TIM3_Init(71, 999);					// 初始化定时器中断
	lv_init();							// lvgl初始化
	lv_port_disp_init();				// 显示初始化
	lv_port_indev_init();				// 触摸初始化
	
	lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
	lv_obj_set_size(switch_obj, 120, 60);
	lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);
	
	while (1)
	{
		delay_ms(5);
		lv_timer_handler();
	}
}


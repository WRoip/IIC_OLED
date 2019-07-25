#include "stm32f4xx.h"
#include "systick.h"
#include "uart.h"
#include "chinese.h"
#include "oled.h"

int main(void)
{
	int ret;	
	
	/****************** 硬件初始化 ********************/
	Systick_Init();
	UART1_Init(115200); 
	Led_Init();
	OLED_Clear();
	printf("HardWare Init Success!\r\n");
	
/****************** 实现的功能 ********************/
	
/****************** 测试用例 **************************/
#if 0
	
	/*
	*		用例号: test1
	*	用例说明: 屏幕水平滚动显示“今晚吃鸡”
	*	测试结果: true
	*/
	Out_Oled(0x2F,MOC_Commend);//激活滚动
	for(ret = 0; ret < 4; ret++){
			Show_Zh( ret*16, 0, Chinese, ret);
	}
	
	while(1)
	{
		
	}
#elif 1
	
	/*
	*		用例号: test2
	*	用例说明: 屏幕显示5-4-3-2-1-0倒计时
	*	测试结果: true
	*/
	Out_Oled(0xD6,MOC_Commend); //放大
	Out_Oled(0x01,MOC_Commend); 
	
	for(ret = 0; ret <= 6; ret++){
		ret %= 6;
		Show_Zh( 48, 1, Chinese_Num, ret);
		delay_ms(500);
		OLED_Clear();
		delay_ms(500);
		
	}
	
#endif
	

	
		
	
}

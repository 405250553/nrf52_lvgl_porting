#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "nrf.h"
#include "nrf_drv_saadc.h"
#include "nrf_drv_ppi.h"
#include "nrf_drv_timer.h"
#include "boards.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "app_util_platform.h"
#include "nrf_pwr_mgmt.h"

#include "nrf_log.h"
#include "nrf_log_ctrl.h"
#include "nrf_log_default_backends.h"

#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"
#include "nrf_drv_gpiote.h"
#include "nrf_drv_spi.h"

#if defined (UART_PRESENT)
#include "nrf_uart.h"
#endif
#if defined (UARTE_PRESENT)
#include "nrf_uarte.h"
#endif

#include "ili9341.h"
#include "lv_conf.h"
#include "lv_port_disp.h"
#include "lv_examples.h"

#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

extern const nrf_lcd_t nrf_lcd_ili9341;

void uart_event_handle(app_uart_evt_t * p_event)
{
    static uint8_t data_array[20];
    //static uint8_t index = 0;
    //uint32_t       err_code;
 
    switch (p_event->evt_type)
    {
        case APP_UART_DATA_READY:
            UNUSED_VARIABLE(app_uart_get(data_array));
              //for (uint32_t i = 0; i < 20; i++)
              //printf("input: %c",data_array[i]);              
            break;
 
        case APP_UART_COMMUNICATION_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_communication);
            break;
 
        case APP_UART_FIFO_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_code);
            break;
 
        default:
            break;
    }
}

void uart_init()
{
    uint32_t err_code;

    const app_uart_comm_params_t comm_params =
      {
          RX_PIN_NUMBER,
          TX_PIN_NUMBER,
          NULL,
          NULL,
          APP_UART_FLOW_CONTROL_ENABLED,
          false,
#if defined (UART_PRESENT)
          NRF_UART_BAUDRATE_115200
#else
          NRF_UARTE_BAUDRATE_115200
#endif
      };

    APP_UART_FIFO_INIT(&comm_params,
                         UART_RX_BUF_SIZE,
                         UART_TX_BUF_SIZE,
                         uart_event_handle,
                         APP_IRQ_PRIORITY_LOWEST,
                         err_code);

    APP_ERROR_CHECK(err_code);
}

/**
 * @brief Function for main application entry.
 */
int main(void)
{
    uart_init();
    //ili9341_init();
   
    //nrf_lcd_ili9341.lcd_init();
    //nrf_lcd_ili9341.lcd_rect_draw(ILI9341_HEIGHT/4,ILI9341_WIDTH/4,ILI9341_HEIGHT/2,ILI9341_WIDTH/2,0);
    //nrf_lcd_ili9341.lcd_display_invert(1);
		lv_init();
		lv_port_disp_init();
		lv_example_calendar_1();
		//lv_example_label_1();
	
    /* Configure LED-pins as outputs */
    bsp_board_init(BSP_INIT_LEDS);

    while(1){
        //printf("print!!!!!!\r\n");
        //nrf_delay_ms(500);
				lv_task_handler();
				__WFE();
    }
}


/** @} */

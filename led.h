/*
 * led.h
 *
 *  Created on: Apr 6, 2022
 *      Author: poli
 */

#ifndef INC_LED_H_
#define INC_LED_H_
#include "main.h"
#include "stm32f1xx_hal.h"

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define Led_F_Pin GPIO_PIN_0
#define Led_F_GPIO_Port GPIOC
#define Led_E_Pin GPIO_PIN_1
#define Led_E_GPIO_Port GPIOC
#define Led_A_Pin GPIO_PIN_0
#define Led_A_GPIO_Port GPIOA
#define Led_B_Pin GPIO_PIN_1
#define Led_B_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define Led_C_Pin GPIO_PIN_4
#define Led_C_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define Led_G_Pin GPIO_PIN_6
#define Led_G_GPIO_Port GPIOA
#define Led_D_Pin GPIO_PIN_0
#define Led_D_GPIO_Port GPIOB
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define Seg_1_Pin GPIO_PIN_8
#define Seg_1_GPIO_Port GPIOB
#define Seg_2_Pin GPIO_PIN_9
#define Seg_2_GPIO_Port GPIOB

#endif /* INC_LED_H_ */

void setnumber (uint8_t number);
void ledprint (uint8_t number);

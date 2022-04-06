/*
 * led.c
 *
 *  Created on: Apr 6, 2022
 *      Author: poli
 */
#include "main.h"
#include "led.h"
uint8_t R1 = 0, R2 = 0;

void ledprint (uint8_t number){
	R1 = number/10;
	R2 = number%10;

}

void setnumber (uint8_t number)
{
	switch (number)
	{
		case 0:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
	  			HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_RESET);  //G
				break;
			}

		case 1:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_RESET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_RESET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_RESET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_RESET);  //G
				break;
			}

		case 2:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_RESET); //C
			  	HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_RESET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 3:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_RESET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 4:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_RESET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_RESET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 5:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_RESET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 6:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_RESET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 7:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_RESET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_RESET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_RESET);  //G
				break;
			}

		case 8:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

		case 9:
			{
				HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
				HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
				HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
				HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
				HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_RESET); //E
				HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
				HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G
				break;
			}

	}
}

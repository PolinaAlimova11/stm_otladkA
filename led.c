#include "main.h"
#include "led.h"
uint8_t R1 = 0, R2 = 0;
extern uint8_t n_count;

void ledprint (uint8_t number, uint8_t n_count){
	R1 = number/10;
	R2 = number%10;
	if (number > 31){
	if (number == 100){
		if (n_count == 0){
					HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, RESET);
					HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, SET);
					setnumber(111);
				}

				if (n_count == 1){
					HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, RESET);
					HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, SET);
					setnumber(1);
				}

	}
	if (number == 77){
			if (n_count == 0){
								HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, RESET);
								HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, SET);
								setnumber(120);
							}

							if (n_count == 1){
								HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, RESET);
								HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, SET);
								setnumber(0);
							}

		}
	if (number == 88){
					if (n_count == 0){
						HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, RESET);
						HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, SET);
						setnumber(130);
					}

					if (n_count == 1){
						HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, RESET);
						HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, SET);
						setnumber(1);
					}

				}
	}
		else {
		if (n_count == 0){
			HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, RESET);
			HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, SET);
			setnumber(R1);
		}

		if (n_count == 1){
			HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, RESET);
			HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, SET);
			setnumber(R2);
		}
		}
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
		case 111:
		{
			HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_SET); //A
			HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_RESET); //B
			HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_RESET); //C
			HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
			HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
			HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
			HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_RESET);  //G

			break;
		}
		case 120:
				{
					HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_RESET); //A
					HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_RESET); //B
					HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_RESET); //C
					HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_SET); //D
					HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
					HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
					HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_RESET);  //G

					break;
				}
		case 130:
						{
							HAL_GPIO_WritePin(Led_A_GPIO_Port, Led_A_Pin, GPIO_PIN_RESET); //A
							HAL_GPIO_WritePin(Led_B_GPIO_Port, Led_B_Pin, GPIO_PIN_SET); //B
							HAL_GPIO_WritePin(Led_C_GPIO_Port, Led_C_Pin, GPIO_PIN_SET); //C
							HAL_GPIO_WritePin(Led_D_GPIO_Port, Led_D_Pin, GPIO_PIN_RESET); //D
							HAL_GPIO_WritePin(Led_E_GPIO_Port, Led_E_Pin, GPIO_PIN_SET); //E
							HAL_GPIO_WritePin(Led_F_GPIO_Port, Led_F_Pin, GPIO_PIN_SET);	//F
							HAL_GPIO_WritePin(Led_G_GPIO_Port, Led_G_Pin, GPIO_PIN_SET);  //G

							break;
						}

	}
}

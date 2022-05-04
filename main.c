/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "led.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int timer, sec, otschot;
int flag_red = -1;
uint8_t flag_game = 10, flag_start = 1, game_over = 1; flag_but1, flag_but2, flag_but3, flag_but4;
//extern uint8_t n_count;
uint8_t n_count;
extern uint8_t R1, R2;
int notes1[] = {61185, 57761, 54514, 51446, 48558, 45845, 43243, 40816, 38554, 36363};


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {

		timer++;

		if (timer == otschot){
			sec--;
			timer = 0;
		}

		if (sec<0){
			sec = 30;
		}

		if (n_count == 0){
			//HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, RESET);
			//HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, SET);
			setnumber(R1);
		}

		if (n_count == 1){
			//HAL_GPIO_WritePin(Seg_1_GPIO_Port, Seg_1_Pin, RESET);
			//HAL_GPIO_WritePin(Seg_2_GPIO_Port, Seg_2_Pin, SET);
			setnumber(R2);
		}

		n_count++;

		if (n_count>1){
			n_count = 0;
		}

		if (flag_red > -1){
			flag_red--;
		}
		if (flag_red == 0){
			HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
			flag_red = -1;
		}
	}
	/*if (htim->Instance == TIM4) {
		timer_buz++;
		if (timer_buz == 1000){
			timer_buz = 0;
		}
		if (flag_red > -1){
					flag_red--;
				}
		if (flag_red == 0){
			HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
			flag_red = -1;
			flag_lose = 5;
		}

	}*/

}

void buzzer_red(){
	HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
	TIM3->PSC = notes1[0];//9
	TIM3->ARR = 2;
	TIM3->CCR1 =TIM3->ARR / 2;
	flag_red = 10;
	//HAL_Delay(300);
	//HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);

}


void buzzer_lose(){
	HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
	TIM3->ARR = 2;
	TIM3->CCR1 =TIM3->ARR / 2;
	TIM3->PSC = notes1[1];//10
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[2];//11
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[3];//12
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[1];//10
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[2];//11
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[3];//12
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[1];//10
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[2];//11
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[3];//12
	HAL_Delay(300);
	TIM3->PSC = 0;
	HAL_Delay(40);
	TIM3->PSC = notes1[0];//9
	HAL_Delay(800);
	HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);

}

void buzzer_win(){
	HAL_TIM_PWM_Start_IT(&htim3, TIM_CHANNEL_1);
		  TIM3->ARR = 2;
		  TIM3->CCR1 =TIM3->ARR / 2;
		  TIM3->PSC = notes1[4]; //13
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[4];//13
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[4];//13
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[0];//9
		  HAL_Delay(350);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[8];//16
		  HAL_Delay(150);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[4];//13
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(150);
		  TIM3->PSC = notes1[0];//9
		  HAL_Delay(350);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[8];//16
		  HAL_Delay(150);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[4];//13
		  HAL_Delay(650);
		  TIM3->PSC = 0;
		  HAL_Delay(200);
		  //--------------
		  TIM3->PSC = notes1[5];//14
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[5];//14
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[5];//14
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[1];//10
		  HAL_Delay(350);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[10];//18
		  HAL_Delay(150);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[5];//14
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[0];//9
		  HAL_Delay(350);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[8];//16
		  HAL_Delay(500);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  TIM3->PSC = notes1[4];//13
		  HAL_Delay(650);
		  TIM3->PSC = 0;
		  HAL_Delay(40);
		  HAL_TIM_PWM_Stop_IT(&htim3, TIM_CHANNEL_1);
		  HAL_Delay(1000);
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	flag_start = 1;
	uint8_t flag_otschet = 0;
	uint8_t but1 = 5, but2 = 5, but3 = 5, but4 = 5;



  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  HAL_TIM_Base_Start_IT(&htim4);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */


  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  flag_start = 1;

	  if (flag_start != 0){
		  ledprint(100, n_count); // режим ожидания
		  flag_but1 = 0;
		  flag_but2 = 0;
		  flag_but3 = 0;
		  flag_but4 = 0;
	  }


	  if( HAL_GPIO_ReadPin(BUT_START_GPIO_Port, BUT_START_Pin) == GPIO_PIN_RESET ){
		  flag_start = 0; //при единичном нажатии начинается игра
		  game_over = 1;

	  }
	  //but1 = timer % 4; //значение от 0 до 3
	  			  // 0 - выигрышная кнопка
	  			  // 1 и 2 - увеличение скорости
	  			  // 3 - сразу проигрыш
	  //but2 = timer % 4;
	  //but3 = timer % 4;
	  //but4 = timer % 4;

	  while (flag_start == 0){//цикл игры

		  if (flag_otschet == 0){//если это первая проверка, то есть при нажатии кнопки старта начинается отчет
			  sec = 30;
			  timer = 0;
			  flag_but1 = 0;
			  flag_but2 = 0;
			  flag_but3 = 0;
			  flag_but4 = 0;
			  otschot = 100;
			  flag_otschet = 1;//отчет больше не будет сбиваться
			  HAL_UART_Transmit(&huart2, "Game start\r\n", 11, 100);//мнется на одной строке, хз пока
		  }

		  ledprint(sec, n_count);

		  if( HAL_GPIO_ReadPin(BUT1_GPIO_Port, BUT1_Pin) == GPIO_PIN_RESET && flag_but1 == 0){
		  		  flag_but1 = 1; //сделаю flag_but = but1
		  	  }

		  if( HAL_GPIO_ReadPin(BUT2_GPIO_Port, BUT2_Pin) == GPIO_PIN_RESET && flag_but2 == 0){
		  		  		  flag_but2 = 1; //сделаю flag_but = but1
		  		  	  }

		  if( HAL_GPIO_ReadPin(BUT3_GPIO_Port, BUT3_Pin) == GPIO_PIN_RESET && flag_but3 == 0){
		  		  		  flag_but3 = 1; //сделаю flag_but = but1
		  		  	  }

		  if (flag_but1 == 1 && flag_start == 0){//тут в чём-то проблема
			  buzzer_red();
			  flag_but1 = 2;
		  }

		  if (flag_but1 == 2 && otschot == 100)
			  otschot = 50;

		  if (flag_but3 == 1){ //может пойти повторно по проигрышу, надо пофиксить
			  buzzer_win();
			  flag_but3 = 2;
			  flag_start = 1;
			  flag_otschet = 0;
			  break;
		  }
		  if (flag_but4 == 1 && flag_start == 0){
			  buzzer_lose();
			  flag_but4 = 2;
			  flag_start = 1;
			  flag_otschet = 0;
			  break;
		  }

		  if( HAL_GPIO_ReadPin(BUT4_GPIO_Port, BUT4_Pin) == GPIO_PIN_RESET && flag_but4 == 0){
			  flag_but4 = 1; //сделаю flag_but = but1
		  }



		  /*if (flag_but2 == 1){
			  buzzer_red();
			  flag_but2 = 2;
		  }*/

		  if (sec == 0){// если не успеем разминировать бомбу
		  	led_lose();//хз почему не отображаются циферки, пока что просто два 0
		  	HAL_UART_Transmit(&huart2, "Game over. Timer is over. You lose\r\n", 35, 100);
		  	buzzer_lose();
		  	flag_start = 1;
		  	flag_otschet = 0;
		  	break;

		  }


	  }

	  //ledprint(sec, n_count);
	  //if (sec == 27){
		//  buzzer_red();
	  //}


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 64000-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 64000-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 10;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 64000-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 0;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, Led_F_Pin|Led_E_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, Led_A_Pin|Led_B_Pin|Led_C_Pin|LED_Pin
                          |Led_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Led_D_Pin|Seg_1_Pin|Seg_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : Led_F_Pin Led_E_Pin */
  GPIO_InitStruct.Pin = Led_F_Pin|Led_E_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : Led_A_Pin Led_B_Pin Led_C_Pin LED_Pin
                           Led_G_Pin */
  GPIO_InitStruct.Pin = Led_A_Pin|Led_B_Pin|Led_C_Pin|LED_Pin
                          |Led_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : Led_D_Pin Seg_1_Pin Seg_2_Pin */
  GPIO_InitStruct.Pin = Led_D_Pin|Seg_1_Pin|Seg_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUT2_Pin BUT3_Pin BUT4_Pin */
  GPIO_InitStruct.Pin = BUT2_Pin|BUT3_Pin|BUT4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUT1_Pin BUT_START_Pin */
  GPIO_InitStruct.Pin = BUT1_Pin|BUT_START_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */




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
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "utility.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define TICKS_PER_SEC		1000U

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void red_blinky(void);
void blue_blinky(void);


uint32_t stack_blinkyRed[40] = {RESET};
uint32_t *sp_LEDred = &stack_blinkyRed[40];
uint32_t stack_blinkyBlue[40] = {RESET};
uint32_t *sp_LEDblue = &stack_blinkyBlue[40];

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_2);

  /* SysTick_IRQn interrupt configuration */
  NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1, 0));

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  utility_init();
  LL_SYSTICK_EnableIT();

  /* stack init of red blinky */
  *(--sp_LEDred) = (1U << 24U);				// xPSR core register
  *(--sp_LEDred) = (uint32_t)&red_blinky;	// PC core register
  *(--sp_LEDred) = 0x0000000EU; 			// LR core register
  *(--sp_LEDred) = 0x0000000CU;				// R12 core register
  *(--sp_LEDred) = 0x00000003U;				// R3 core register
  *(--sp_LEDred) = 0x00000002U;				// R2 core register
  *(--sp_LEDred) = 0x00000001U;				// R1 core register
  *(--sp_LEDred) = 0x00000000U;				// R0 core register
  /* R4 - R11 Stack core register stack frame */
  *(--sp_LEDred) = 0x0000000BU;				// R11 core register
  *(--sp_LEDred) = 0x0000000AU;				// R10 core register
  *(--sp_LEDred) = 0x00000009U;				// R9 core register
  *(--sp_LEDred) = 0x00000008U;				// R8 core register
  *(--sp_LEDred) = 0x00000007U;				// R7 core register
  *(--sp_LEDred) = 0x00000006U;				// R6 core register
  *(--sp_LEDred) = 0x00000005U;				// R5 core register
  *(--sp_LEDred) = 0x00000004U;				// R4 core register


  /* Stack init of blue blinky */
  *(--sp_LEDblue) = (1U << 24U);				// xPSR core register
  *(--sp_LEDblue) = (uint32_t)&blue_blinky;		// PC core register
  *(--sp_LEDblue) = 0x0000000EU; 				// LR core register
  *(--sp_LEDblue) = 0x0000000CU;				// R12 core register
  *(--sp_LEDblue) = 0x00000003U;				// R3 core register
  *(--sp_LEDblue) = 0x00000002U;				// R2 core register
  *(--sp_LEDblue) = 0x00000001U;				// R1 core register
  *(--sp_LEDblue) = 0x00000000U;				// R0 core register
  /* R4 - R11 Stack core register stack frame */
  *(--sp_LEDblue) = 0x0000000BU;				// R11 core register
  *(--sp_LEDblue) = 0x0000000AU;				// R10 core register
  *(--sp_LEDblue) = 0x00000009U;				// R9 core register
  *(--sp_LEDblue) = 0x00000008U;				// R8 core register
  *(--sp_LEDblue) = 0x00000007U;				// R7 core register
  *(--sp_LEDblue) = 0x00000006U;				// R6 core register
  *(--sp_LEDblue) = 0x00000005U;				// R5 core register
  *(--sp_LEDblue) = 0x00000004U;				// R4 core register

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_5)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 168, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_Init1msTick(168000000);
  LL_SetSystemCoreClock(168000000);
}

/* USER CODE BEGIN 4 */

void red_blinky(void)
{
	while(1)
	{
		LL_GPIO_SetOutputPin(LED_Red_GPIO_Port, LED_Red_Pin);
		delayTicks(1000U);
		LL_GPIO_ResetOutputPin(LED_Red_GPIO_Port, LED_Red_Pin);
		delayTicks(500U);
	}
}

void blue_blinky(void)
{
	while(1)
	{
		LL_GPIO_SetOutputPin(LED_Blue_GPIO_Port, LED_Blue_Pin);
		delayTicks(2000U);
		LL_GPIO_ResetOutputPin(LED_Blue_GPIO_Port, LED_Blue_Pin);
		delayTicks(1000U);
	}
}


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

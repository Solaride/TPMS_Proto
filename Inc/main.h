/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define STMOD__SPI1_NSS_Pin GPIO_PIN_4
#define STMOD__SPI1_NSS_GPIO_Port GPIOA
#define ISM330DLC_INT1_Pin GPIO_PIN_8
#define ISM330DLC_INT1_GPIO_Port GPIOA
#define STMOD__RESET_Pin GPIO_PIN_1
#define STMOD__RESET_GPIO_Port GPIOA
#define STMOD__SPI1_MISOP_Pin GPIO_PIN_6
#define STMOD__SPI1_MISOP_GPIO_Port GPIOA
#define STMOD__GPIO4_Pin GPIO_PIN_2
#define STMOD__GPIO4_GPIO_Port GPIOA
#define STMOD__INT_Pin GPIO_PIN_8
#define STMOD__INT_GPIO_Port GPIOB
#define STMOD__GPIO2_Pin GPIO_PIN_5
#define STMOD__GPIO2_GPIO_Port GPIOB
#define STMOD__ADC_Pin GPIO_PIN_3
#define STMOD__ADC_GPIO_Port GPIOA
#define STMOD__SPI1_MOSIP_Pin GPIO_PIN_7
#define STMOD__SPI1_MOSIP_GPIO_Port GPIOA
#define STMOD__UART1_RTS_Pin GPIO_PIN_12
#define STMOD__UART1_RTS_GPIO_Port GPIOA
#define STMOD__UART1_CTS_Pin GPIO_PIN_11
#define STMOD__UART1_CTS_GPIO_Port GPIOA
#define STMOD__GPIO3_Pin GPIO_PIN_4
#define STMOD__GPIO3_GPIO_Port GPIOB
#define STMOD__UART1_RX_Pin GPIO_PIN_10
#define STMOD__UART1_RX_GPIO_Port GPIOA
#define STTS22H_INT_Pin GPIO_PIN_0
#define STTS22H_INT_GPIO_Port GPIOA
#define STMOD__UART1_TX_Pin GPIO_PIN_9
#define STMOD__UART1_TX_GPIO_Port GPIOA
#define STMOD__SPI1_SCK_Pin GPIO_PIN_5
#define STMOD__SPI1_SCK_GPIO_Port GPIOA
#define BUTTON_USER1_Pin GPIO_PIN_1
#define BUTTON_USER1_GPIO_Port GPIOB
#define USER_LED_Pin GPIO_PIN_0
#define USER_LED_GPIO_Port GPIOB
#define STMOD__GPIO1_Pin GPIO_PIN_2
#define STMOD__GPIO1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

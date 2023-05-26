#ifndef INC_RTG_H_
#define INC_RTG_H_
#include "main.h"
#include "stm32f7xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define PADDING 46

#pragma pack(push,1)
typedef struct pocket{
	uint32_t m_id;
	char m_padding[PADDING];
}pocket_t;
#pragma pack(pop)

void rtg_main();
// UART HANDLES:
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart6;

// UARAT AND GPIO DEFINITIONS:
#define UART_DEBUG &huart3			//Debug UART
#define UART_MASTER &huart4			//Transmit UART
#define UART_SLAVE &huart6			//Receive UART

// GENERAL DEFINITIONS:

// BOOLS:
#define TRUE 1
#define BYTE 1
#define FALSE 0
#define ZERO 0
#define ERROR 0xff


#endif /* INC_RTG_H_ */

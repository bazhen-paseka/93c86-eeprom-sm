/**
* \version 1.0
* \author bazhen.levkovets
* \date 2020-November-12
*************************************************************************************
* \copyright	Bazhen Levkovets
* \copyright	Brovary
* \copyright	Ukraine
*************************************************************************************
*/

/*
**************************************************************************
*							INCLUDE FILES
**************************************************************************
*/

	#include "93c86-eeprom-sm.h"
	#include "usart.h"

/*
**************************************************************************
*							LOCAL DEFINES
**************************************************************************
*/


/*
**************************************************************************
*							LOCAL CONSTANTS
**************************************************************************
*/


/*
**************************************************************************
*						    LOCAL DATA TYPES
**************************************************************************
*/


/*
**************************************************************************
*							  LOCAL TABLES
**************************************************************************
*/

/*
**************************************************************************
*								 MACRO'S
**************************************************************************
*/


/*
**************************************************************************
*						 LOCAL GLOBAL VARIABLES
**************************************************************************
*/

/*
**************************************************************************
*                        LOCAL FUNCTION PROTOTYPES
**************************************************************************
*/

	void delaydd(uint32_t kd) ;

/*
**************************************************************************
*                           GLOBAL FUNCTIONS
**************************************************************************
*/

//** EWEN *******************************************************
void EVEN (void) {
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,  SET) ;
	delaydd(1000);
	uint8_t read_u8 = 0b00011001 ;
	for (int pos = 0; pos<13; pos++) {
		if ( CHECK_BIT(read_u8, pos) == 0 ) {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;
		}
		else {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, SET ) ;
		}

		delaydd(500);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(500);
	}
	delaydd(500);

	for (int pos = 0; pos<35; pos++) {
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(1000);
	}

	delaydd(1000);
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, RESET ) ;
}
//*** EWEN *******************************************************


//*** WRITE *******************************************************
void WRITE (void) 	{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,  SET) ;
	delaydd(1000);
	uint16_t write_u16 = 0b0000000000000101 ;
	for (int pos = 0; pos<13; pos++) {
		if ( CHECK_BIT(write_u16, pos) == 0 ) {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;
		}
		else {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, SET ) ;
		}

		delaydd(500);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(500);
	}
	delaydd(500);

	write_u16 = 0x5b9e ;
	for (int pos = 0; pos<16; pos++) {
		if ( CHECK_BIT(write_u16, pos) == 0 ) {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;
		}
		else {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, SET ) ;
		}

		delaydd(500);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(500);
	}

	HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;

	delaydd(1000);
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, RESET ) ;
}
//*** WRITE *******************************************************


//** EWDS *******************************************************
void EWDS (void) 	{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,  SET) ;
	delaydd(1000);
	uint8_t read_u8 = 0b00000001 ;
	for (int pos = 0; pos<13; pos++) {
		if ( CHECK_BIT(read_u8, pos) == 0 ) {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;
		}
		else {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, SET ) ;
		}

		delaydd(500);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(500);
	}
	delaydd(500);

	for (int pos = 0; pos<35; pos++) {
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(1000);
	}

	delaydd(1000);
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, RESET ) ;
}
//*** EWDS *******************************************************


//** READ *******************************************************
void READ (void)	{
	HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin,  SET) ;
	delaydd(1000);
	uint8_t read_u8 = 0b00000011 ;
	for (int pos = 0; pos<13; pos++) {
		if ( CHECK_BIT(read_u8, pos) == 0 ) {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, RESET ) ;
		}
		else {
			HAL_GPIO_WritePin(DI_GPIO_Port, DI_Pin, SET ) ;
		}

		delaydd(500);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);

		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(500);
	}
	delaydd(1500);

	#define BITS_QNT	15
	GPIO_PinState memory_bit_ps[BITS_QNT];

	for (int pos = BITS_QNT; pos >= 0 ; pos--) {
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		memory_bit_ps[pos] =  HAL_GPIO_ReadPin(DO_GPIO_Port, DO_Pin);
		delaydd(1000);
	}

	delaydd(1000);
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, RESET ) ;

	#define	DEBUG_STRING_SIZE2		100
    char DebugString2[DEBUG_STRING_SIZE2];

	for (int pos = 0; pos < BITS_QNT ; pos++) {
	sprintf(DebugString2," %d", (int)memory_bit_ps[pos]);
	HAL_UART_Transmit(&huart2, (uint8_t *)DebugString2, strlen(DebugString2), 100);
	}
}
//*** READ *******************************************************


/*
**************************************************************************
*                           LOCAL FUNCTIONS
**************************************************************************
*/

void delaydd(uint32_t kd)
{
	for (int jd=0; jd < kd; jd++)
	{
		__asm("nop");
	}
}

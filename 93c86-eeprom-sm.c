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

	write_u16 = 0x6666 ;
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
	delaydd(500);

	for (int pos = 0; pos<20; pos++) {
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin,   SET ) ;
		delaydd(1000);
		HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, RESET ) ;
		delaydd(1000);
	}

	delaydd(1000);
    HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, RESET ) ;
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

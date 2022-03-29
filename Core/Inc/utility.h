/*      
*	Utility Functions
*
*	Created by: Roland R.
*	Last Update: September 06, 2019
* 	Copywrite: South East Dynamics
*/

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "main.h"


#define CIRC_BUFF_CMD_W			0U
#define CIRC_BUFF_CMD_R			1U
#define CIRC_BUFF_CMD_RST		2U
#define CIRC_BUFF_FULL_FLG		0x01
#define CIRC_BUFF_WTRMRK_FLG	(CIRC_BUFF_FULL_FLG << 1U)
#define CIRC_WATER_MRK_SET		(CIRC_BUFF_FULL_FLG << 2U)


typedef union{
	float floatVar;
	uint8_t	byteArray[4];
	uint32_t uint32Var;
	int32_t int32Var;
}UPrim_Dtype_32bit_t;


/**
  * @brief  Initialize Utility 
  * @param  None
  * @retval None
*/
void utility_init(void);


/**
  * @brief  Delay in Microseconds 
  * @param  microSec: set delay in Microseconds
  * @retval None
*/
void delayUs(uint32_t microSec);


/**
  * @brief  Delay in Milliseconds
  * @param  miliSec: set delay in Milliseconds
  * @retval None
*/
void delayMs(uint32_t miliSec);


/**
  * @brief  Delay in Nanoseconds
  * @param  nanoSec: set delay in Nanosecond
  * @retval None
*/
void delayNs(uint32_t nanoSec);


/**
  * @brief  Convert Integer to character array
  * @param  integr: integer value to be converted
  * @param	charArr: pointer to character array to store
  * 					then converted value
  * @param	stringSize: size of the output string
  * @retval number of characters converted
*/
uint16_t int32_to_char_Arr(int32_t integr, char* charArr, uint16_t stringSize);


/**
  * @brief  Convert Integer to character array
  * @param  floatVal: floating point value to be converted
  * @param	charArr: pointer to character array to store
  * 					then converted value
  * @param	pointLoc: location of the point in the char array
  * @retval None
*/
void float_to_char_Arr(float const floatVal, char* charArr, uint16_t pointLoc);


/**
  * @brief  Calculate CRC8
  * @param  ptrBuffer: pointer to data buffer
  * @param	bufferSize: size of the data buffer
  * @retval calculated CRC8 value
*/
uint8_t calculate_crc8(uint8_t const* ptrBuffer, uint32_t bufferSize);


/**
  * @brief  delay using systick timer
  * @param  delayMs: delay in milliseconds
  * @retval none
*/
void delayTicksMs(uint32_t delayMs);


/**
  * @brief  increment the systick counter
  * @param  none
  * @retval none
*/
void ticks_increment(void);


/**
  * @brief  Get the program counter 
  * @param  none
  * @retval return the current program counter value
*/
__STATIC_INLINE uint32_t get_prog_counterVal(void)
{
	return DWT->CYCCNT;
}		// end of get_prog_counterVal

#endif

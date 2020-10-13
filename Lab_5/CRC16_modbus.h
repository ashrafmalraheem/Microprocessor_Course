//================= CRC 16 for modbus checksum  ============================//

/**
 * @file CRC16_modbus.h
 * @brief CRC calculator
 *
 * This interface CRC calculation function. It will compute the CRC for 16 bit data.
 * Also it validate the CRC for a given string of data
 *
 * @author 
 * @date 
 *
 */
#ifndef __CRC16_MODBUS_H__
#define __CRC16_MODBUS_H__
#include "stdint.h"

#define true 1
#define false 0
/*
 * @brief reflected CRC 16 Algorithm
 *
 * This function will return a 1 byte from the PC port in UART by moving the byte in UART
 * hardware rx buffer.
 *
 * @param data pointer
 * @param dataLength
 * @return CRC16
 */
uint16_t CRC16(uint8_t *data,uint8_t data_length);

/*
 * @brief CRC validation function
 *
 * This function will validate a CRC for a stream of data
 *
 * @param  data pointer
 * @param  data length
 * @return validate result
 */
uint8_t valid_CRC(uint8_t *data, uint8_t data_length);
#endif // __CRC16_MODBUS_H__


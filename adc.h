/*
===========================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc.h
Date Created : Oct 9, 2022
Description  : Header file for the AVR ADC peripheral driver.
===========================================================================================================
*/


#ifndef ADC_H_
#define ADC_H_

/*===========================================================================================================
                                               < Includes >
===========================================================================================================*/

#include "std_types.h"

/*===========================================================================================================
                                < Definitions and Static Configurations >
===========================================================================================================*/

#define ADC_MAX_VALUE               (1023u)
#define ADC_REF_VOLT_VALUE          (5u)

#define ADC_CHANNEL_0               (0u)
#define ADC_CHANNEL_1               (1u)
#define ADC_CHANNEL_2               (2u)
#define ADC_CHANNEL_3               (3u)
#define ADC_CHANNEL_4               (4u)
#define ADC_CHANNEL_5               (5u)
#define ADC_CHANNEL_6               (6u)
#define ADC_CHANNEL_7               (7u)

/*===========================================================================================================
                                       < User-defined Data Types >
===========================================================================================================*/

typedef enum
{
	/* Work with Vref = AREF which is connected with AREF pin */
	ADC_REF_AREF,
	/* Work with Vref = Vcc = 5v */
	ADC_REF_AVCC,
	/* Work with the internal Vref = 2.56v */
	ADC_INTERNAL=0X03,
}ADC_voltageReferenceSelection;

typedef enum
{
	DIVISION_FACTOR_1,
	DIVISION_FACTOR_2,
	DIVISION_FACTOR_4,
	DIVISION_FACTOR_8,
	DIVISION_FACTOR_16,
	DIVISION_FACTOR_32,
	DIVISION_FACTOR_64,
	DIVISION_FACTOR_128,
}ADC_prescalerSelection;

typedef struct
{
	/* Indicates to the required voltage reference (AREF-AVCC-Internal) */
	ADC_voltageReferenceSelection s_voltageReference;
	/* Indicates to the required prescaler divisin factor */
	ADC_prescalerSelection s_prescalerValue;
}ADC_configurations;

/*===========================================================================================================
                                         < Functions Prototypes >
===========================================================================================================*/


/*===========================================================================================================
 * [Function Name] : ADC_init
 * [Description]   : Initialize the ADC peripheral with specific configurations.
 * [Arguments]     : <a_configurations>      -> Pointer to structure.
 *                                              This structure have the required configurations.
 * [return]        : The function returns void.
 ==========================================================================================================*/
void ADC_init(const ADC_configurations* a_configurations);


/*===========================================================================================================
 * [Function Name] : ADC_readChannel
 * [Description]   : Read the analog value of a specific channel and convert it to corresponding digital
 *                   value using the ADC peripheral then return the digital value.
 * [Arguments]     : <a_channelNumber>      -> Indicates to the required channel.
 * [return]        : The function returns the digital value which stored in ADC register.
 ==========================================================================================================*/
uint16 ADC_readChannel(uint8 a_channelNumber);

#endif /* ADC_H_ */

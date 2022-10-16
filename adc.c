/*
===========================================================================================================
Author       : Mamoun
Module       : ADC
File Name    : adc.c
Date Created : Oct 9, 2022
Description  : Source file for the AVR ADC peripheral driver.
===========================================================================================================
*/


/*===========================================================================================================
                                               < Includes >
===========================================================================================================*/

#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>

/*===========================================================================================================
                                          < Functions Definitions >
===========================================================================================================*/

/*===========================================================================================================
 * [Function Name] : ADC_init
 * [Description]   : Initialize the ADC peripheral with specific configurations.
 * [Arguments]     : <a_configurations>      -> Pointer to structure.
 *                                              This structure have the required configurations.
 * [return]        : The function returns void.
 ==========================================================================================================*/
void ADC_init(const ADC_configurations* a_configurations)
{
	ADMUX = (ADMUX&0X3F) | ((a_configurations->s_voltageReference)<<0X06);
	ADCSRA = (ADCSRA&0XF8) | ((a_configurations->s_prescalerValue)&0X07);
	SET_BIT(ADCSRA,ADEN);
}

/*===========================================================================================================
 * [Function Name] : ADC_readChannel
 * [Description]   : Read the analog value of a specific channel and convert it to corresponding digital
 *                   value using the ADC peripheral then return the digital value.
 * [Arguments]     : <a_channelNumber>      -> Indicates to the required channel.
 * [return]        : The function returns the digital value which stored in ADC register.
 ==========================================================================================================*/
uint16 ADC_readChannel(uint8 a_channelNumber)
{
	ADMUX = (ADMUX&0XE0) | (a_channelNumber&0X1F);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}

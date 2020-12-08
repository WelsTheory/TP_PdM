/*
 * App_mef.c
 *
 *  Created on: Dec 3, 2020
 *      Author: wels
 */
#include "main.h"
#include "sapi.h"
#include "App_Mef.h"
#include "led.h"
#include "App_Uart.h"

extern delay_t MEF_Boton;
extern delay_t MEF_Normal;
extern delay_t MEF_Lento;
extern delay_t MEF_Rapido;

const char dato1[15] = "MODO NORMAL\n\r";
const char dato2[14] = "MODO LENTO\n\r";
const char dato3[15] = "MODO RAPIDO\n\r";

void MEFEstadoInit(void){
	OffLED(VERDE);
	OffLED(ROJO);
	OffLED(AMARILLO);
	estadoActual = ESTADO_NORMAL;
	UART_String(dato1,15);
}

void MEFEstadoActualizar(void){

	switch(estadoActual){

	case ESTADO_NORMAL:
		OffLED(VERDE);
		OnLED(ROJO);
		if(delayRead(&MEF_Normal)){
			//
			UART_String(dato1,15);
		}

		if(GPIO_Read(TEC1)){
			//
			if(delayRead(&MEF_Boton)){
				//
				if(GPIO_Read(TEC1)){
					//
					UART_String(dato2,14);
					estadoActual = ESTADO_LENTO;
				}
			}
		}

		break;

	case ESTADO_LENTO:
		OffLED(ROJO);
		OnLED(AMARILLO);
		if(delayRead(&MEF_Lento)){
			//
			UART_String(dato2,14);
		}

		if(GPIO_Read(TEC2))
		{
			if(delayRead(&MEF_Boton)){
				//
				if(GPIO_Read(TEC2)){
					//
					UART_String(dato3,15);
					estadoActual = ESTADO_RAPIDO;
				}
			}
		}

		break;

	case ESTADO_RAPIDO:
		OffLED(AMARILLO);
		OnLED(VERDE);
		if(delayRead(&MEF_Rapido)){
			//
			UART_String(dato3,15);
		}

		if(GPIO_Read(TEC3)){
			//
			if(delayRead(&MEF_Boton)){
				//
				if(GPIO_Read(TEC3)){
					//
					UART_String(dato1,15);
					estadoActual = ESTADO_NORMAL;
				}
			}
		}

		break;

	default:
		MEFEstadoInit();
		break;
	}
}

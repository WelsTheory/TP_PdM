#include "main.h"
#include "sapi.h"
#include "App_uart.h"

#define TIEMPO_NORMAL     		500    // ms
#define TIEMPO_LENTO			    2000  // ms
#define TIEMPO_RAPIDO			    100    // ms
#define TIEMPO_BOTON			    40    // ms

delay_t MEF_Normal;
delay_t MEF_Lento;
delay_t MEF_Rapido;
delay_t MEF_Boton;

int main(void)
{
	boardInit();
	delay_ms(&MEF_Normal,TIEMPO_NORMAL);
	delay_ms(&MEF_Lento,TIEMPO_LENTO);
	delay_ms(&MEF_Rapido,TIEMPO_RAPIDO);
	delay_ms(&MEF_Boton,TIEMPO_BOTON);
	MEFEstadoInit();
	while (1)
	{
		MEFEstadoActualizar();
	}

}

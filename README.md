
## Trabajo Practico - Programaci�n de Microprocesadores

###Aplicaci�n:
  
  El sistema empieza a ejecutar en el modo de operaci�n **Normal**, cuando el usuario presiona la tecla B1 el sistema cambia el modo de operaci�n **Lento**, cuando el usuario presiona la tecla B2 el sistema cambia el modo de operaci�n **R�pido** y cuando el usuario presiona la tecla B3 el sistema cambia el modo de operaci�n **Normal**.

  **Modos de operaci�n** 
	*Normal: Se env�a el mensaje "Estado Normal" a trav�s de la UART cada 500ms.
	*Lento: Se env�a el mensaje "Estado Lento" a trav�s de la UART cada 2 segundos.
	*R�pido: Se env�a el mensaje "Estado R�pido" a trav�s de la UART cada 100ms.


**M�dulos de software** 
	App_Uart.c y App_Uart.h

	App_Mef.c y App_Mef.h

**App_uart.c** 
```c
void UART_String(const char* str, uint16_t sz);//Funci�n para enviar una cadena de datos a trav�s de la UART
/*
 * str = cadena 
 * sz = tama�o de la cadena
*/
```

**App_mef.c** 
```c
//Estados de operaci�n
typedef enum{ESTDO_NORMAL, ESTADO_LENTO, ESTADO_RAPIDO} MEFEstado_t;

MEFEstado_t estadoActual;

void MEFEstadoInit(void); // Funci�n para iniciar el Primer Estado

void MEFEstadoActualizar(void); //Funci�n de lectura de pulsadores y cambio de estado.

```



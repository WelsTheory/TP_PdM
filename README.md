
## Trabajo Practico - Programación de Microprocesadores

###Aplicación:
  
  El sistema empieza a ejecutar en el modo de operación **Normal**, cuando el usuario presiona la tecla B1 el sistema cambia el modo de operación **Lento**, cuando el usuario presiona la tecla B2 el sistema cambia el modo de operación **Rápido** y cuando el usuario presiona la tecla B3 el sistema cambia el modo de operación **Normal**.

  **Modos de operación** 
	*Normal: Se envía el mensaje "Estado Normal" a través de la UART cada 500ms.
	*Lento: Se envía el mensaje "Estado Lento" a través de la UART cada 2 segundos.
	*Rápido: Se envía el mensaje "Estado Rápido" a través de la UART cada 100ms.


**Módulos de software** 
	App_Uart.c y App_Uart.h

	App_Mef.c y App_Mef.h

**App_uart.c** 
```c
void UART_String(const char* str, uint16_t sz);//Función para enviar una cadena de datos a través de la UART
/*
 * str = cadena 
 * sz = tamaño de la cadena
*/
```

**App_mef.c** 
```c
//Estados de operación
typedef enum{ESTDO_NORMAL, ESTADO_LENTO, ESTADO_RAPIDO} MEFEstado_t;

MEFEstado_t estadoActual;

void MEFEstadoInit(void); // Función para iniciar el Primer Estado

void MEFEstadoActualizar(void); //Función de lectura de pulsadores y cambio de estado.

```



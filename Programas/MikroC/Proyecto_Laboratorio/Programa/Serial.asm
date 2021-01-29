
_Serial_writeInit:

;Serial.c,3 :: 		void Serial_writeInit(void)
;Serial.c,5 :: 		UART1_Write_Text("Programa: Control de Reles y Salidas");
	MOVLW       ?lstr1_Serial+0
	MOVWF       FARG_UART1_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr1_Serial+0)
	MOVWF       FARG_UART1_Write_Text_uart_text+1 
	CALL        _UART1_Write_Text+0, 0
;Serial.c,6 :: 		UART1_Write_Text("Autor: Zuliani,Agustin");
	MOVLW       ?lstr2_Serial+0
	MOVWF       FARG_UART1_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr2_Serial+0)
	MOVWF       FARG_UART1_Write_Text_uart_text+1 
	CALL        _UART1_Write_Text+0, 0
;Serial.c,7 :: 		UART1_Write_Text("Fecha Inicio: 11/1/2021");
	MOVLW       ?lstr3_Serial+0
	MOVWF       FARG_UART1_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr3_Serial+0)
	MOVWF       FARG_UART1_Write_Text_uart_text+1 
	CALL        _UART1_Write_Text+0, 0
;Serial.c,8 :: 		UART1_Write_Text("Descripcion: Controla salida a Reles, una salida a Triac y demas");
	MOVLW       ?lstr4_Serial+0
	MOVWF       FARG_UART1_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr4_Serial+0)
	MOVWF       FARG_UART1_Write_Text_uart_text+1 
	CALL        _UART1_Write_Text+0, 0
;Serial.c,10 :: 		return;
;Serial.c,11 :: 		}
L_end_Serial_writeInit:
	RETURN      0
; end of _Serial_writeInit

_Reception:

;Serial.c,13 :: 		void Reception(void)
;Serial.c,15 :: 		Rx = UART1_Read();
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _Rx+0 
;Serial.c,16 :: 		echo = 1;      // Echo
	BSF         _echo+0, BitPos(_echo+0) 
;Serial.c,18 :: 		return;
;Serial.c,19 :: 		}
L_end_Reception:
	RETURN      0
; end of _Reception

_Echo_Tx:

;Serial.c,21 :: 		void Echo_Tx(void)
;Serial.c,23 :: 		UART1_Write(Rx);
	MOVF        _Rx+0, 0 
	MOVWF       FARG_UART1_Write_data_+0 
	CALL        _UART1_Write+0, 0
;Serial.c,25 :: 		return;
;Serial.c,26 :: 		}
L_end_Echo_Tx:
	RETURN      0
; end of _Echo_Tx

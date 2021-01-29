
_Serial_writeInit:

;serial.h,9 :: 		void Serial_writeInit(void)
;serial.h,11 :: 		UART_Write_Text("Programa: Control de Reles y Salidas");
	MOVLW       ?lstr1_MyProject+0
	MOVWF       FARG_UART_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr1_MyProject+0)
	MOVWF       FARG_UART_Write_Text_uart_text+1 
	CALL        _UART_Write_Text+0, 0
;serial.h,12 :: 		UART_Write_Text("Autor: Zuliani,Agustin");
	MOVLW       ?lstr2_MyProject+0
	MOVWF       FARG_UART_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr2_MyProject+0)
	MOVWF       FARG_UART_Write_Text_uart_text+1 
	CALL        _UART_Write_Text+0, 0
;serial.h,13 :: 		UART_Write_Text("Fecha Inicio: 11/1/2021");
	MOVLW       ?lstr3_MyProject+0
	MOVWF       FARG_UART_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr3_MyProject+0)
	MOVWF       FARG_UART_Write_Text_uart_text+1 
	CALL        _UART_Write_Text+0, 0
;serial.h,14 :: 		UART_Write_Text("Descripcion: Controla salida a Reles, una salida a Triac y demas");
	MOVLW       ?lstr4_MyProject+0
	MOVWF       FARG_UART_Write_Text_uart_text+0 
	MOVLW       hi_addr(?lstr4_MyProject+0)
	MOVWF       FARG_UART_Write_Text_uart_text+1 
	CALL        _UART_Write_Text+0, 0
;serial.h,16 :: 		return;
;serial.h,17 :: 		}
L_end_Serial_writeInit:
	RETURN      0
; end of _Serial_writeInit

_Reception:

;serial.h,19 :: 		void Reception(void)
;serial.h,21 :: 		Rx = UART_Read();
	CALL        _UART_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _Rx+0 
;serial.h,22 :: 		UART_Write(Rx);      // Echo
	MOVF        _Rx+0, 0 
	MOVWF       FARG_UART_Write__data+0 
	CALL        _UART_Write+0, 0
;serial.h,24 :: 		return;
;serial.h,25 :: 		}
L_end_Reception:
	RETURN      0
; end of _Reception

_main:

;MyProject.c,7 :: 		void main()
;MyProject.c,9 :: 		ADCON1 = 0x0F;
	MOVLW       15
	MOVWF       ADCON1+0 
;MyProject.c,11 :: 		UART1_Init(56800);
	BSF         BAUDCON+0, 3, 0
	CLRF        SPBRGH+0 
	MOVLW       210
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;MyProject.c,12 :: 		Mef_init();
	CALL        _Mef_init+0, 0
;MyProject.c,15 :: 		while(1)
L_main0:
;MyProject.c,17 :: 		Mef_Updated();
	CALL        _Mef_Updated+0, 0
;MyProject.c,18 :: 		}
	GOTO        L_main0
;MyProject.c,19 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_Interrupt_init:

;MyProject.c,21 :: 		void Interrupt_init(void)
;MyProject.c,23 :: 		GIE_bit = 1;
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
;MyProject.c,24 :: 		IPEN_bit = 1;
	BSF         IPEN_bit+0, BitPos(IPEN_bit+0) 
;MyProject.c,25 :: 		PEIE_bit = 1;
	BSF         PEIE_bit+0, BitPos(PEIE_bit+0) 
;MyProject.c,28 :: 		RCIF_bit = 0;
	BCF         RCIF_bit+0, BitPos(RCIF_bit+0) 
;MyProject.c,29 :: 		RCIE_bit = 1;
	BSF         RCIE_bit+0, BitPos(RCIE_bit+0) 
;MyProject.c,30 :: 		RCIP_bit = 1;  // High priority with uart
	BSF         RCIP_bit+0, BitPos(RCIP_bit+0) 
;MyProject.c,33 :: 		return;
;MyProject.c,34 :: 		}
L_end_Interrupt_init:
	RETURN      0
; end of _Interrupt_init

_ISR_HP:

;MyProject.c,36 :: 		void ISR_HP() iv 0x0008 ics ICS_AUTO
;MyProject.c,38 :: 		if(RCIF_bit==1)
	BTFSS       RCIF_bit+0, BitPos(RCIF_bit+0) 
	GOTO        L_ISR_HP2
;MyProject.c,40 :: 		RCIF_bit = 0;
	BCF         RCIF_bit+0, BitPos(RCIF_bit+0) 
;MyProject.c,41 :: 		Reception();
	CALL        _Reception+0, 0
;MyProject.c,43 :: 		}
L_ISR_HP2:
;MyProject.c,45 :: 		return;
;MyProject.c,46 :: 		}
L_end_ISR_HP:
L__ISR_HP8:
	RETFIE      1
; end of _ISR_HP

_ISR_LP:
	MOVWF       ___Low_saveWREG+0 
	MOVF        STATUS+0, 0 
	MOVWF       ___Low_saveSTATUS+0 
	MOVF        BSR+0, 0 
	MOVWF       ___Low_saveBSR+0 

;MyProject.c,48 :: 		void ISR_LP() iv 0x0018 ics ICS_AUTO
;MyProject.c,51 :: 		}
L_end_ISR_LP:
L__ISR_LP10:
	MOVF        ___Low_saveBSR+0, 0 
	MOVWF       BSR+0 
	MOVF        ___Low_saveSTATUS+0, 0 
	MOVWF       STATUS+0 
	SWAPF       ___Low_saveWREG+0, 1 
	SWAPF       ___Low_saveWREG+0, 0 
	RETFIE      0
; end of _ISR_LP

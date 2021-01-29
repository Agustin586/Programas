
_main:

;MiniLaboratorio.c,78 :: 		void main()
;MiniLaboratorio.c,80 :: 		ADCON1 = 0x0D;       // AN0 and AN1 Enable and others how to digital I/O
	MOVLW       13
	MOVWF       ADCON1+0 
;MiniLaboratorio.c,81 :: 		UCON &= 0b11110111;
	MOVLW       247
	ANDWF       UCON+0, 1 
;MiniLaboratorio.c,82 :: 		UCFG |= 0b00001000;
	BSF         UCFG+0, 3 
;MiniLaboratorio.c,84 :: 		echo = 0;
	BCF         _echo+0, BitPos(_echo+0) 
;MiniLaboratorio.c,85 :: 		Encoder_E = 0;
	BCF         _Encoder_E+0, BitPos(_Encoder_E+0) 
;MiniLaboratorio.c,87 :: 		IO_Config();
	CALL        _IO_Config+0, 0
;MiniLaboratorio.c,88 :: 		Interrupt_init();
	CALL        _Interrupt_init+0, 0
;MiniLaboratorio.c,89 :: 		Timer0_init();
	CALL        _Timer0_init+0, 0
;MiniLaboratorio.c,90 :: 		UART1_Init(56000);
	BSF         BAUDCON+0, 3, 0
	CLRF        SPBRGH+0 
	MOVLW       213
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;MiniLaboratorio.c,91 :: 		TFT_Init_ILI9341_8bit(320,240);
	MOVLW       64
	MOVWF       FARG_TFT_Init_ILI9341_8bit_display_width+0 
	MOVLW       1
	MOVWF       FARG_TFT_Init_ILI9341_8bit_display_width+1 
	MOVLW       240
	MOVWF       FARG_TFT_Init_ILI9341_8bit_display_height+0 
	MOVLW       0
	MOVWF       FARG_TFT_Init_ILI9341_8bit_display_height+1 
	CALL        _TFT_Init_ILI9341_8bit+0, 0
;MiniLaboratorio.c,92 :: 		I2C_Clock_Init();
	CALL        _I2C_Clock_Init+0, 0
;MiniLaboratorio.c,93 :: 		Mef_init();
	CALL        _Mef_init+0, 0
;MiniLaboratorio.c,95 :: 		TFT_Write_Command(0x36);
	MOVLW       54
	MOVWF       FARG_TFT_Write_Command_cmd+0 
	CALL        _TFT_Write_Command+0, 0
;MiniLaboratorio.c,96 :: 		TFT_Write_Data(0x20|0x08);    // 90°
	MOVLW       40
	MOVWF       FARG_TFT_Write_Data__data+0 
	MOVLW       0
	MOVWF       FARG_TFT_Write_Data__data+1 
	CALL        _TFT_Write_Data+0, 0
;MiniLaboratorio.c,100 :: 		while(1)
L_main0:
;MiniLaboratorio.c,102 :: 		Mef_Updated();
	CALL        _Mef_Updated+0, 0
;MiniLaboratorio.c,103 :: 		}
	GOTO        L_main0
;MiniLaboratorio.c,105 :: 		}
L_end_main:
	GOTO        $+0
; end of _main

_IO_Config:

;MiniLaboratorio.c,107 :: 		void IO_Config(void)
;MiniLaboratorio.c,110 :: 		RELE1_TRIS = 0;
	BCF         TRISA5_bit+0, BitPos(TRISA5_bit+0) 
;MiniLaboratorio.c,111 :: 		RELE1_LOW;
	BCF         LATA5_bit+0, BitPos(LATA5_bit+0) 
;MiniLaboratorio.c,112 :: 		RELE2_TRIS = 0;
	BCF         TRISE0_bit+0, BitPos(TRISE0_bit+0) 
;MiniLaboratorio.c,113 :: 		RELE2_LOW;
	BCF         LATE0_bit+0, BitPos(LATE0_bit+0) 
;MiniLaboratorio.c,114 :: 		RELE3_TRIS = 0;
	BCF         TRISE1_bit+0, BitPos(TRISE1_bit+0) 
;MiniLaboratorio.c,115 :: 		RELE3_LOW;
	BCF         LATE1_bit+0, BitPos(LATE1_bit+0) 
;MiniLaboratorio.c,116 :: 		RELE4_TRIS = 0;
	BCF         TRISE2_bit+0, BitPos(TRISE2_bit+0) 
;MiniLaboratorio.c,117 :: 		RELE4_LOW;
	BCF         LATE2_bit+0, BitPos(LATE2_bit+0) 
;MiniLaboratorio.c,121 :: 		ENCODER_A_TRIS = 1;
	BSF         TRISB0_bit+0, BitPos(TRISB0_bit+0) 
;MiniLaboratorio.c,122 :: 		ENCODER_PUSH_TRIS = 1;
	BSF         TRISC1_bit+0, BitPos(TRISC1_bit+0) 
;MiniLaboratorio.c,123 :: 		ENCODER_B_TRIS = 1;
	BSF         TRISC0_bit+0, BitPos(TRISC0_bit+0) 
;MiniLaboratorio.c,127 :: 		BUZZER_TRIS = 0;
	BCF         TRISC0_bit+0, BitPos(TRISC0_bit+0) 
;MiniLaboratorio.c,128 :: 		BUZZER_LOW;
	BCF         LATC0_bit+0, BitPos(LATC0_bit+0) 
;MiniLaboratorio.c,132 :: 		AN0_TRIS = 1;       // Input channel 0
	BSF         TRISA0_bit+0, BitPos(TRISA0_bit+0) 
;MiniLaboratorio.c,133 :: 		AN1_TRIS = 1;       // Input channel 1
	BSF         TRISA1_bit+0, BitPos(TRISA1_bit+0) 
;MiniLaboratorio.c,136 :: 		return;
;MiniLaboratorio.c,137 :: 		}
L_end_IO_Config:
	RETURN      0
; end of _IO_Config

_Interrupt_init:

;MiniLaboratorio.c,139 :: 		void Interrupt_init(void)
;MiniLaboratorio.c,142 :: 		GIE_bit = 1;
	BSF         GIE_bit+0, BitPos(GIE_bit+0) 
;MiniLaboratorio.c,143 :: 		IPEN_bit = 1;
	BSF         IPEN_bit+0, BitPos(IPEN_bit+0) 
;MiniLaboratorio.c,144 :: 		PEIE_bit = 1;
	BSF         PEIE_bit+0, BitPos(PEIE_bit+0) 
;MiniLaboratorio.c,148 :: 		GIEL_bit = 1;
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
;MiniLaboratorio.c,152 :: 		RCIF_bit = 0;
	BCF         RCIF_bit+0, BitPos(RCIF_bit+0) 
;MiniLaboratorio.c,153 :: 		RCIE_bit = 1;
	BSF         RCIE_bit+0, BitPos(RCIE_bit+0) 
;MiniLaboratorio.c,154 :: 		RCIP_bit = 1;     // High priority with uart
	BSF         RCIP_bit+0, BitPos(RCIP_bit+0) 
;MiniLaboratorio.c,158 :: 		TMR0IE_bit = 1;
	BSF         TMR0IE_bit+0, BitPos(TMR0IE_bit+0) 
;MiniLaboratorio.c,159 :: 		TMR0IF_bit = 0;
	BCF         TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
;MiniLaboratorio.c,160 :: 		TMR0IP_bit = 0;   // Low priority
	BCF         TMR0IP_bit+0, BitPos(TMR0IP_bit+0) 
;MiniLaboratorio.c,164 :: 		INT0IE_bit = 1;
	BSF         INT0IE_bit+0, BitPos(INT0IE_bit+0) 
;MiniLaboratorio.c,165 :: 		INT0IF_bit = 0;
	BCF         INT0IF_bit+0, BitPos(INT0IF_bit+0) 
;MiniLaboratorio.c,166 :: 		INTEDG0_bit = 0;  // Falling edge
	BCF         INTEDG0_bit+0, BitPos(INTEDG0_bit+0) 
;MiniLaboratorio.c,170 :: 		INT2E_bit = 1;
	BSF         INT2E_bit+0, BitPos(INT2E_bit+0) 
;MiniLaboratorio.c,171 :: 		INT2IF_bit = 0;
	BCF         INT2IF_bit+0, BitPos(INT2IF_bit+0) 
;MiniLaboratorio.c,172 :: 		INT2IP_bit = 0;   // Low Priority
	BCF         INT2IP_bit+0, BitPos(INT2IP_bit+0) 
;MiniLaboratorio.c,173 :: 		INTEDG2_bit = 1;  // Rising edge
	BSF         INTEDG2_bit+0, BitPos(INTEDG2_bit+0) 
;MiniLaboratorio.c,176 :: 		return;
;MiniLaboratorio.c,177 :: 		}
L_end_Interrupt_init:
	RETURN      0
; end of _Interrupt_init

_Timer0_init:

;MiniLaboratorio.c,179 :: 		void Timer0_init(void)
;MiniLaboratorio.c,182 :: 		T08BIT_bit = 0;   // 16bits counter
	BCF         T08BIT_bit+0, BitPos(T08BIT_bit+0) 
;MiniLaboratorio.c,183 :: 		T0CS_bit = 0;     // Internal clock
	BCF         T0CS_bit+0, BitPos(T0CS_bit+0) 
;MiniLaboratorio.c,184 :: 		T0SE_bit = 0;
	BCF         T0SE_bit+0, BitPos(T0SE_bit+0) 
;MiniLaboratorio.c,185 :: 		PSA_bit = 0;      // Prescaler assinged
	BCF         PSA_bit+0, BitPos(PSA_bit+0) 
;MiniLaboratorio.c,186 :: 		T0PS0_bit = 0;
	BCF         T0PS0_bit+0, BitPos(T0PS0_bit+0) 
;MiniLaboratorio.c,187 :: 		T0PS1_bit = 0;    // 1:2 prescaler
	BCF         T0PS1_bit+0, BitPos(T0PS1_bit+0) 
;MiniLaboratorio.c,188 :: 		T0PS2_bit = 0;
	BCF         T0PS2_bit+0, BitPos(T0PS2_bit+0) 
;MiniLaboratorio.c,189 :: 		TMR0ON_bit = 1;   // Enable timer0
	BSF         TMR0ON_bit+0, BitPos(TMR0ON_bit+0) 
;MiniLaboratorio.c,191 :: 		TMR0L = 0X90;     // 59536 = 1ms para 48MHz
	MOVLW       144
	MOVWF       TMR0L+0 
;MiniLaboratorio.c,192 :: 		TMR0H = 0xE8;
	MOVLW       232
	MOVWF       TMR0H+0 
;MiniLaboratorio.c,195 :: 		return;
;MiniLaboratorio.c,196 :: 		}
L_end_Timer0_init:
	RETURN      0
; end of _Timer0_init

_milis:

;MiniLaboratorio.c,198 :: 		unsigned long long milis(void)
;MiniLaboratorio.c,200 :: 		unsigned long long milis=ms;
	MOVF        _ms+0, 0 
	MOVWF       R4 
	MOVF        _ms+1, 0 
	MOVWF       R5 
	MOVF        _ms+2, 0 
	MOVWF       R6 
	MOVF        _ms+3, 0 
	MOVWF       R7 
;MiniLaboratorio.c,202 :: 		return milis;
	MOVF        R4, 0 
	MOVWF       R0 
	MOVF        R5, 0 
	MOVWF       R1 
	MOVF        R6, 0 
	MOVWF       R2 
	MOVF        R7, 0 
	MOVWF       R3 
;MiniLaboratorio.c,203 :: 		}
L_end_milis:
	RETURN      0
; end of _milis

_Antirrebote_Encoder:

;MiniLaboratorio.c,205 :: 		void Antirrebote_Encoder(void)
;MiniLaboratorio.c,207 :: 		INT0IE_bit = 0;   // Disabled Interrupt
	BCF         INT0IE_bit+0, BitPos(INT0IE_bit+0) 
;MiniLaboratorio.c,208 :: 		Encoder_E = 1;    // Delay for Encoder
	BSF         _Encoder_E+0, BitPos(_Encoder_E+0) 
;MiniLaboratorio.c,211 :: 		BUZZER_HIGH;
	BSF         LATC0_bit+0, BitPos(LATC0_bit+0) 
;MiniLaboratorio.c,214 :: 		return;
;MiniLaboratorio.c,215 :: 		}
L_end_Antirrebote_Encoder:
	RETURN      0
; end of _Antirrebote_Encoder

_Task_Detected:

;MiniLaboratorio.c,217 :: 		void Task_Detected(void)
;MiniLaboratorio.c,219 :: 		if(!_Delay_Encoder)
	MOVF        __Delay_Encoder+0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_Task_Detected2
;MiniLaboratorio.c,222 :: 		_Delay_Encoder = DELAY_ENCODER;
	MOVLW       50
	MOVWF       __Delay_Encoder+0 
;MiniLaboratorio.c,223 :: 		Encoder_E = 0;
	BCF         _Encoder_E+0, BitPos(_Encoder_E+0) 
;MiniLaboratorio.c,224 :: 		INT0IF_bit = 0;
	BCF         INT0IF_bit+0, BitPos(INT0IF_bit+0) 
;MiniLaboratorio.c,225 :: 		INT0IE_bit = 1;   // Enable Interrupt
	BSF         INT0IE_bit+0, BitPos(INT0IE_bit+0) 
;MiniLaboratorio.c,229 :: 		BUZZER_LOW;
	BCF         LATC0_bit+0, BitPos(LATC0_bit+0) 
;MiniLaboratorio.c,231 :: 		}
L_Task_Detected2:
;MiniLaboratorio.c,233 :: 		return;
;MiniLaboratorio.c,234 :: 		}
L_end_Task_Detected:
	RETURN      0
; end of _Task_Detected

_ISR_HP:

;MiniLaboratorio.c,236 :: 		void ISR_HP() iv 0x0008 ics ICS_AUTO
;MiniLaboratorio.c,238 :: 		if(RCIF_bit==1)
	BTFSS       RCIF_bit+0, BitPos(RCIF_bit+0) 
	GOTO        L_ISR_HP3
;MiniLaboratorio.c,240 :: 		RCIF_bit = 0;
	BCF         RCIF_bit+0, BitPos(RCIF_bit+0) 
;MiniLaboratorio.c,241 :: 		Reception();
	CALL        _Reception+0, 0
;MiniLaboratorio.c,242 :: 		}
L_ISR_HP3:
;MiniLaboratorio.c,243 :: 		if(INT0IF_bit==1)
	BTFSS       INT0IF_bit+0, BitPos(INT0IF_bit+0) 
	GOTO        L_ISR_HP4
;MiniLaboratorio.c,245 :: 		INT0IF_bit = 0;
	BCF         INT0IF_bit+0, BitPos(INT0IF_bit+0) 
;MiniLaboratorio.c,247 :: 		if(ENCODER_B_READ)         Pos++;
	BTFSS       RC0_bit+0, BitPos(RC0_bit+0) 
	GOTO        L_ISR_HP5
	MOVF        _Pos+0, 0 
	ADDLW       1
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       _Pos+0 
	GOTO        L_ISR_HP6
L_ISR_HP5:
;MiniLaboratorio.c,248 :: 		else if(!ENCODER_B_READ)   Pos--;
	BTFSC       RC0_bit+0, BitPos(RC0_bit+0) 
	GOTO        L_ISR_HP7
	DECF        _Pos+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       _Pos+0 
L_ISR_HP7:
L_ISR_HP6:
;MiniLaboratorio.c,250 :: 		Antirrebote_Encoder();
	CALL        _Antirrebote_Encoder+0, 0
;MiniLaboratorio.c,251 :: 		}
L_ISR_HP4:
;MiniLaboratorio.c,253 :: 		return;
;MiniLaboratorio.c,254 :: 		}
L_end_ISR_HP:
L__ISR_HP19:
	RETFIE      1
; end of _ISR_HP

_ISR_LP:
	MOVWF       ___Low_saveWREG+0 
	MOVF        STATUS+0, 0 
	MOVWF       ___Low_saveSTATUS+0 
	MOVF        BSR+0, 0 
	MOVWF       ___Low_saveBSR+0 

;MiniLaboratorio.c,256 :: 		void ISR_LP() iv 0x0018 ics ICS_AUTO
;MiniLaboratorio.c,258 :: 		if(TMR0IF_bit==1)
	BTFSS       TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
	GOTO        L_ISR_LP8
;MiniLaboratorio.c,260 :: 		TMR0IF_bit = 0;
	BCF         TMR0IF_bit+0, BitPos(TMR0IF_bit+0) 
;MiniLaboratorio.c,261 :: 		TMR0L = 0X90;
	MOVLW       144
	MOVWF       TMR0L+0 
;MiniLaboratorio.c,262 :: 		TMR0H = 0xE8;
	MOVLW       232
	MOVWF       TMR0H+0 
;MiniLaboratorio.c,264 :: 		ms++;
	MOVLW       1
	ADDWF       _ms+0, 0 
	MOVWF       R0 
	MOVLW       0
	ADDWFC      _ms+1, 0 
	MOVWF       R1 
	MOVLW       0
	ADDWFC      _ms+2, 0 
	MOVWF       R2 
	MOVLW       0
	ADDWFC      _ms+3, 0 
	MOVWF       R3 
	MOVF        R0, 0 
	MOVWF       _ms+0 
	MOVF        R1, 0 
	MOVWF       _ms+1 
	MOVF        R2, 0 
	MOVWF       _ms+2 
	MOVF        R3, 0 
	MOVWF       _ms+3 
;MiniLaboratorio.c,266 :: 		if(Encoder_E)  _Delay_Encoder--;
	BTFSS       _Encoder_E+0, BitPos(_Encoder_E+0) 
	GOTO        L_ISR_LP9
	DECF        __Delay_Encoder+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       __Delay_Encoder+0 
L_ISR_LP9:
;MiniLaboratorio.c,267 :: 		Task_Detected();  // Verified if a task has finished
	CALL        _Task_Detected+0, 0
;MiniLaboratorio.c,268 :: 		}
L_ISR_LP8:
;MiniLaboratorio.c,269 :: 		if(INT2IF_bit==1)
	BTFSS       INT2IF_bit+0, BitPos(INT2IF_bit+0) 
	GOTO        L_ISR_LP10
;MiniLaboratorio.c,271 :: 		INT2IF_bit = 0;
	BCF         INT2IF_bit+0, BitPos(INT2IF_bit+0) 
;MiniLaboratorio.c,273 :: 		}
L_ISR_LP10:
;MiniLaboratorio.c,275 :: 		return;
;MiniLaboratorio.c,276 :: 		}
L_end_ISR_LP:
L__ISR_LP21:
	MOVF        ___Low_saveBSR+0, 0 
	MOVWF       BSR+0 
	MOVF        ___Low_saveSTATUS+0, 0 
	MOVWF       STATUS+0 
	SWAPF       ___Low_saveWREG+0, 1 
	SWAPF       ___Low_saveWREG+0, 0 
	RETFIE      0
; end of _ISR_LP

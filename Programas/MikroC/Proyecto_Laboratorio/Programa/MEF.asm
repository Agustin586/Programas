
_Mef_init:

;MEF.c,3 :: 		void Mef_init(void)
;MEF.c,5 :: 		Estado_Actual = ESTATE_INIT;
	CLRF        MEF_Estado_Actual+0 
;MEF.c,6 :: 		SubEst_Menu = SUBM_MENU_INIT;
	CLRF        MEF_SubEst_Menu+0 
;MEF.c,8 :: 		return;
;MEF.c,9 :: 		}
L_end_Mef_init:
	RETURN      0
; end of _Mef_init

_Mef_Updated:

;MEF.c,11 :: 		void Mef_Updated(void)
;MEF.c,13 :: 		switch(Estado_Actual)
	GOTO        L_Mef_Updated0
;MEF.c,15 :: 		case ESTATE_INIT:
L_Mef_Updated2:
;MEF.c,17 :: 		Serial_writeInit();  // Send Initicial info
	CALL        _Serial_writeInit+0, 0
;MEF.c,18 :: 		Display_init();      // Initializacion on lcd tft
	CALL        _Display_init+0, 0
;MEF.c,20 :: 		Estado_Actual = ESTATE_MENU;
	MOVLW       1
	MOVWF       MEF_Estado_Actual+0 
;MEF.c,21 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,23 :: 		case ESTATE_MENU:
L_Mef_Updated3:
;MEF.c,25 :: 		SubEst_MENU_Updated();
	CALL        _SubEst_MENU_Updated+0, 0
;MEF.c,27 :: 		if(echo) Estado_Actual = ESTATE_UART;
	BTFSS       _echo+0, BitPos(_echo+0) 
	GOTO        L_Mef_Updated4
	MOVLW       5
	MOVWF       MEF_Estado_Actual+0 
L_Mef_Updated4:
;MEF.c,28 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,30 :: 		case ESTATE_OUTPUT:
L_Mef_Updated5:
;MEF.c,32 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,34 :: 		case ESTATE_RTC:
L_Mef_Updated6:
;MEF.c,36 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,38 :: 		case ESTATE_TESTING:
L_Mef_Updated7:
;MEF.c,40 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,42 :: 		case ESTATE_UART:
L_Mef_Updated8:
;MEF.c,44 :: 		if(echo) Echo_Tx(),echo=0;
	BTFSS       _echo+0, BitPos(_echo+0) 
	GOTO        L_Mef_Updated9
	CALL        _Echo_Tx+0, 0
	BCF         _echo+0, BitPos(_echo+0) 
L_Mef_Updated9:
;MEF.c,46 :: 		Estado_Actual = ESTATE_MENU;
	MOVLW       1
	MOVWF       MEF_Estado_Actual+0 
;MEF.c,47 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,49 :: 		case ESTATE_THEME:
L_Mef_Updated10:
;MEF.c,52 :: 		break;
	GOTO        L_Mef_Updated1
;MEF.c,54 :: 		}
L_Mef_Updated0:
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated2
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated3
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       2
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated5
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       3
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated6
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       4
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated7
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       5
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated8
	MOVF        MEF_Estado_Actual+0, 0 
	XORLW       6
	BTFSC       STATUS+0, 2 
	GOTO        L_Mef_Updated10
L_Mef_Updated1:
;MEF.c,56 :: 		return;
;MEF.c,57 :: 		}
L_end_Mef_Updated:
	RETURN      0
; end of _Mef_Updated

_SubEst_MENU_Updated:

;MEF.c,59 :: 		void SubEst_MENU_Updated(void)
;MEF.c,61 :: 		switch(SubEst_Menu)
	GOTO        L_SubEst_MENU_Updated11
;MEF.c,63 :: 		case SUBM_MENU_INIT:
L_SubEst_MENU_Updated13:
;MEF.c,65 :: 		Pos = 1;
	MOVLW       1
	MOVWF       _Pos+0 
;MEF.c,66 :: 		ChangeTheme();
	CALL        _ChangeTheme+0, 0
;MEF.c,67 :: 		SubmMenu_DisplayInit();
	CALL        _SubmMenu_DisplayInit+0, 0
;MEF.c,68 :: 		Pos = 0;
	CLRF        _Pos+0 
;MEF.c,70 :: 		SubEst_Menu = SUBM_MENU_SELECT;
	MOVLW       1
	MOVWF       MEF_SubEst_Menu+0 
;MEF.c,71 :: 		break;
	GOTO        L_SubEst_MENU_Updated12
;MEF.c,73 :: 		case SUBM_MENU_SELECT:
L_SubEst_MENU_Updated14:
;MEF.c,76 :: 		break;
	GOTO        L_SubEst_MENU_Updated12
;MEF.c,78 :: 		}
L_SubEst_MENU_Updated11:
	MOVF        MEF_SubEst_Menu+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_SubEst_MENU_Updated13
	MOVF        MEF_SubEst_Menu+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_SubEst_MENU_Updated14
L_SubEst_MENU_Updated12:
;MEF.c,80 :: 		return;
;MEF.c,81 :: 		}
L_end_SubEst_MENU_Updated:
	RETURN      0
; end of _SubEst_MENU_Updated

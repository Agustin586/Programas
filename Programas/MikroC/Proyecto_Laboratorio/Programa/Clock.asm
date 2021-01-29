
_Get_Dates:

;Clock.c,3 :: 		void Get_Dates(void)
;Clock.c,5 :: 		rtc2_getDate(&week,&day,&month,&year);
	MOVLW       Clock_week+0
	MOVWF       FARG_rtc2_getDate_dayOfTheWeek+0 
	MOVLW       hi_addr(Clock_week+0)
	MOVWF       FARG_rtc2_getDate_dayOfTheWeek+1 
	MOVLW       Clock_day+0
	MOVWF       FARG_rtc2_getDate_dateDay+0 
	MOVLW       hi_addr(Clock_day+0)
	MOVWF       FARG_rtc2_getDate_dateDay+1 
	MOVLW       Clock_month+0
	MOVWF       FARG_rtc2_getDate_dateMonth+0 
	MOVLW       hi_addr(Clock_month+0)
	MOVWF       FARG_rtc2_getDate_dateMonth+1 
	MOVLW       Clock_year+0
	MOVWF       FARG_rtc2_getDate_dateYear+0 
	MOVLW       hi_addr(Clock_year+0)
	MOVWF       FARG_rtc2_getDate_dateYear+1 
	CALL        _rtc2_getDate+0, 0
;Clock.c,6 :: 		rtc2_getTime(&hour,&minute,&second);
	MOVLW       Clock_hour+0
	MOVWF       FARG_rtc2_getTime_timeHours+0 
	MOVLW       hi_addr(Clock_hour+0)
	MOVWF       FARG_rtc2_getTime_timeHours+1 
	MOVLW       Clock_minute+0
	MOVWF       FARG_rtc2_getTime_timeMinutes+0 
	MOVLW       hi_addr(Clock_minute+0)
	MOVWF       FARG_rtc2_getTime_timeMinutes+1 
	MOVLW       Clock_second+0
	MOVWF       FARG_rtc2_getTime_timeSeconds+0 
	MOVLW       hi_addr(Clock_second+0)
	MOVWF       FARG_rtc2_getTime_timeSeconds+1 
	CALL        _rtc2_getTime+0, 0
;Clock.c,8 :: 		return;
;Clock.c,9 :: 		}
L_end_Get_Dates:
	RETURN      0
; end of _Get_Dates

_I2C_Clock_Init:

;Clock.c,11 :: 		void I2C_Clock_Init(void)
;Clock.c,13 :: 		GIEH_bit = 0;
	BCF         GIEH_bit+0, BitPos(GIEH_bit+0) 
;Clock.c,14 :: 		GIEL_bit = 0;
	BCF         GIEL_bit+0, BitPos(GIEL_bit+0) 
;Clock.c,15 :: 		Soft_I2C_Init();
	CALL        _Soft_I2C_Init+0, 0
;Clock.c,17 :: 		GIEH_bit = 1;
	BSF         GIEH_bit+0, BitPos(GIEH_bit+0) 
;Clock.c,18 :: 		GIEL_bit = 1;
	BSF         GIEL_bit+0, BitPos(GIEL_bit+0) 
;Clock.c,20 :: 		return;
;Clock.c,21 :: 		}
L_end_I2C_Clock_Init:
	RETURN      0
; end of _I2C_Clock_Init


_Display_init:

;Display.c,5 :: 		void Display_init(void)
;Display.c,7 :: 		unsigned int _load=0;
	CLRF        Display_init__load_L0+0 
	CLRF        Display_init__load_L0+1 
	MOVLW       5
	MOVWF       Display_init_load_L0+0 
	MOVLW       0
	MOVWF       Display_init_load_L0+1 
	MOVLW       44
	MOVWF       Display_init_load_L0+2 
	MOVLW       1
	MOVWF       Display_init_load_L0+3 
	MOVLW       213
	MOVWF       Display_init_load_L0+4 
	MOVLW       238
	MOVWF       Display_init_load_L0+5 
	MOVLW       31
	MOVWF       Display_init_load_L0+6 
	MOVLW       0
	MOVWF       Display_init_load_L0+7 
	CLRF        Display_init_load_L0+8 
	CLRF        Display_init_load_L0+9 
	CLRF        Display_init_load_L0+10 
;Display.c,15 :: 		TFT_Fill_Screen(CL_WHITE);
	MOVLW       255
	MOVWF       FARG_TFT_Fill_Screen_color+0 
	MOVLW       255
	MOVWF       FARG_TFT_Fill_Screen_color+1 
	CALL        _TFT_Fill_Screen+0, 0
;Display.c,16 :: 		x=2,y=2;
	MOVLW       2
	MOVWF       Display_x+0 
	MOVLW       0
	MOVWF       Display_x+1 
	MOVLW       2
	MOVWF       Display_y+0 
;Display.c,17 :: 		TFT_Set_Pen(CL_BLACK, 2);
	CLRF        FARG_TFT_Set_Pen_pen_color+0 
	CLRF        FARG_TFT_Set_Pen_pen_color+1 
	MOVLW       2
	MOVWF       FARG_TFT_Set_Pen_pen_width+0 
	CALL        _TFT_Set_Pen+0, 0
;Display.c,18 :: 		TFT_Rectangle(x,y,x+298,y+60);
	MOVF        Display_x+0, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+0 
	MOVF        Display_x+1, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+1 
	MOVF        Display_y+0, 0 
	MOVWF       FARG_TFT_Rectangle_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_upper_left+1 
	MOVLW       42
	ADDWF       Display_x+0, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+0 
	MOVLW       1
	ADDWFC      Display_x+1, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+1 
	MOVLW       60
	ADDWF       Display_y+0, 0 
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+0 
	CLRF        FARG_TFT_Rectangle_y_bottom_right+1 
	MOVLW       0
	ADDWFC      FARG_TFT_Rectangle_y_bottom_right+1, 1 
	CALL        _TFT_Rectangle+0, 0
;Display.c,20 :: 		x=5,y=5;
	MOVLW       5
	MOVWF       Display_x+0 
	MOVLW       0
	MOVWF       Display_x+1 
	MOVLW       5
	MOVWF       Display_y+0 
;Display.c,21 :: 		TFT_Set_Font(TFT_defaultFont, CL_RED, FO_HORIZONTAL);
	MOVLW       _TFT_defaultFont+0
	MOVWF       FARG_TFT_Set_Font_activeFont+0 
	MOVLW       hi_addr(_TFT_defaultFont+0)
	MOVWF       FARG_TFT_Set_Font_activeFont+1 
	MOVLW       higher_addr(_TFT_defaultFont+0)
	MOVWF       FARG_TFT_Set_Font_activeFont+2 
	MOVLW       0
	MOVWF       FARG_TFT_Set_Font_font_color+0 
	MOVLW       248
	MOVWF       FARG_TFT_Set_Font_font_color+1 
	CLRF        FARG_TFT_Set_Font_font_orientation+0 
	CALL        _TFT_Set_Font+0, 0
;Display.c,22 :: 		TFT_Write_Const_Text(autor,x,y);
	MOVLW       Display_autor+0
	MOVWF       FARG_TFT_Write_Const_Text_text+0 
	MOVLW       hi_addr(Display_autor+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+1 
	MOVLW       higher_addr(Display_autor+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+2 
	MOVF        Display_x+0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+0 
	MOVF        Display_x+1, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+1 
	MOVF        Display_y+0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_y+0 
	MOVLW       0
	MOVWF       FARG_TFT_Write_Const_Text_y+1 
	CALL        _TFT_Write_Const_Text+0, 0
;Display.c,23 :: 		y+=20;
	MOVLW       20
	ADDWF       Display_y+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       Display_y+0 
;Display.c,24 :: 		TFT_Write_Const_Text(fecha,x,y);
	MOVLW       Display_fecha+0
	MOVWF       FARG_TFT_Write_Const_Text_text+0 
	MOVLW       hi_addr(Display_fecha+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+1 
	MOVLW       higher_addr(Display_fecha+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+2 
	MOVF        Display_x+0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+0 
	MOVF        Display_x+1, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+1 
	MOVF        R0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_y+0 
	MOVLW       0
	MOVWF       FARG_TFT_Write_Const_Text_y+1 
	CALL        _TFT_Write_Const_Text+0, 0
;Display.c,25 :: 		y+=20;
	MOVLW       20
	ADDWF       Display_y+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       Display_y+0 
;Display.c,26 :: 		TFT_Write_Const_Text(progm,x,y);
	MOVLW       Display_progm+0
	MOVWF       FARG_TFT_Write_Const_Text_text+0 
	MOVLW       hi_addr(Display_progm+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+1 
	MOVLW       higher_addr(Display_progm+0)
	MOVWF       FARG_TFT_Write_Const_Text_text+2 
	MOVF        Display_x+0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+0 
	MOVF        Display_x+1, 0 
	MOVWF       FARG_TFT_Write_Const_Text_x+1 
	MOVF        R0, 0 
	MOVWF       FARG_TFT_Write_Const_Text_y+0 
	MOVLW       0
	MOVWF       FARG_TFT_Write_Const_Text_y+1 
	CALL        _TFT_Write_Const_Text+0, 0
;Display.c,29 :: 		x=2;
	MOVLW       2
	MOVWF       Display_x+0 
	MOVLW       0
	MOVWF       Display_x+1 
;Display.c,30 :: 		TFT_Set_Pen(CL_BLUE, 2);
	MOVLW       31
	MOVWF       FARG_TFT_Set_Pen_pen_color+0 
	MOVLW       0
	MOVWF       FARG_TFT_Set_Pen_pen_color+1 
	MOVLW       2
	MOVWF       FARG_TFT_Set_Pen_pen_width+0 
	CALL        _TFT_Set_Pen+0, 0
;Display.c,31 :: 		TFT_Rectangle(load.Xs,load.Ys,load.Xe+3,load.Ye);
	MOVF        Display_init_load_L0+0, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+0 
	MOVF        Display_init_load_L0+1, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+1 
	MOVF        Display_init_load_L0+4, 0 
	MOVWF       FARG_TFT_Rectangle_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_upper_left+1 
	MOVLW       3
	ADDWF       Display_init_load_L0+2, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+0 
	MOVLW       0
	ADDWFC      Display_init_load_L0+3, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+1 
	MOVF        Display_init_load_L0+5, 0 
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+1 
	CALL        _TFT_Rectangle+0, 0
;Display.c,32 :: 		Delay_ms(30);
	MOVLW       2
	MOVWF       R11, 0
	MOVLW       212
	MOVWF       R12, 0
	MOVLW       133
	MOVWF       R13, 0
L_Display_init0:
	DECFSZ      R13, 1, 1
	BRA         L_Display_init0
	DECFSZ      R12, 1, 1
	BRA         L_Display_init0
	DECFSZ      R11, 1, 1
	BRA         L_Display_init0
;Display.c,34 :: 		TFT_Set_Brush(1,load.backgroundColour,0,0,0,0);
	MOVLW       1
	MOVWF       FARG_TFT_Set_Brush_brush_enabled+0 
	MOVF        Display_init_load_L0+8, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+0 
	MOVF        Display_init_load_L0+9, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+1 
	CLRF        FARG_TFT_Set_Brush_gradient_enabled+0 
	CLRF        FARG_TFT_Set_Brush_gradient_orientation+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+1 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+1 
	CALL        _TFT_Set_Brush+0, 0
;Display.c,37 :: 		for(_load=5;_load<301;_load++)
	MOVLW       5
	MOVWF       Display_init__load_L0+0 
	MOVLW       0
	MOVWF       Display_init__load_L0+1 
L_Display_init1:
	MOVLW       1
	SUBWF       Display_init__load_L0+1, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__Display_init26
	MOVLW       45
	SUBWF       Display_init__load_L0+0, 0 
L__Display_init26:
	BTFSC       STATUS+0, 0 
	GOTO        L_Display_init2
;Display.c,39 :: 		TFT_Rectangle(_load,load.Ys,(load.Xs-2)+_load,load.Ye);
	MOVF        Display_init__load_L0+0, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+0 
	MOVF        Display_init__load_L0+1, 0 
	MOVWF       FARG_TFT_Rectangle_x_upper_left+1 
	MOVF        Display_init_load_L0+4, 0 
	MOVWF       FARG_TFT_Rectangle_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_upper_left+1 
	MOVLW       2
	SUBWF       Display_init_load_L0+0, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+0 
	MOVLW       0
	SUBWFB      Display_init_load_L0+1, 0 
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+1 
	MOVF        Display_init__load_L0+0, 0 
	ADDWF       FARG_TFT_Rectangle_x_bottom_right+0, 1 
	MOVF        Display_init__load_L0+1, 0 
	ADDWFC      FARG_TFT_Rectangle_x_bottom_right+1, 1 
	MOVF        Display_init_load_L0+5, 0 
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+1 
	CALL        _TFT_Rectangle+0, 0
;Display.c,40 :: 		Delay_ms(10);
	MOVLW       156
	MOVWF       R12, 0
	MOVLW       215
	MOVWF       R13, 0
L_Display_init4:
	DECFSZ      R13, 1, 1
	BRA         L_Display_init4
	DECFSZ      R12, 1, 1
	BRA         L_Display_init4
;Display.c,37 :: 		for(_load=5;_load<301;_load++)
	INFSNZ      Display_init__load_L0+0, 1 
	INCF        Display_init__load_L0+1, 1 
;Display.c,41 :: 		}
	GOTO        L_Display_init1
L_Display_init2:
;Display.c,42 :: 		Delay_ms(1500);
	MOVLW       92
	MOVWF       R11, 0
	MOVLW       81
	MOVWF       R12, 0
	MOVLW       96
	MOVWF       R13, 0
L_Display_init5:
	DECFSZ      R13, 1, 1
	BRA         L_Display_init5
	DECFSZ      R12, 1, 1
	BRA         L_Display_init5
	DECFSZ      R11, 1, 1
	BRA         L_Display_init5
	NOP
;Display.c,45 :: 		return;
;Display.c,46 :: 		}
L_end_Display_init:
	RETURN      0
; end of _Display_init

_SubmMenu_DisplayInit:

;Display.c,52 :: 		void SubmMenu_DisplayInit(void)
;Display.c,54 :: 		StaticDisplay();
	CALL        _StaticDisplay+0, 0
;Display.c,55 :: 		MenuGenerator(4,10,2);
	MOVLW       4
	MOVWF       FARG_MenuGenerator_menu_cant+0 
	MOVLW       10
	MOVWF       FARG_MenuGenerator_separacion+0 
	MOVLW       2
	MOVWF       FARG_MenuGenerator__widthEdge+0 
	CALL        _MenuGenerator+0, 0
;Display.c,57 :: 		return;
;Display.c,58 :: 		}
L_end_SubmMenu_DisplayInit:
	RETURN      0
; end of _SubmMenu_DisplayInit

_ChangeTheme:

;Display.c,62 :: 		void ChangeTheme(void)
;Display.c,64 :: 		struct theme dark_green = {CL_BLACK,CL_WHITE,CL_LIME,CL_GREEN};
	MOVLW       ?ICSChangeTheme_dark_green_L0+0
	MOVWF       TBLPTRL 
	MOVLW       hi_addr(?ICSChangeTheme_dark_green_L0+0)
	MOVWF       TBLPTRH 
	MOVLW       higher_addr(?ICSChangeTheme_dark_green_L0+0)
	MOVWF       TBLPTRU 
	MOVLW       ChangeTheme_dark_green_L0+0
	MOVWF       FSR1 
	MOVLW       hi_addr(ChangeTheme_dark_green_L0+0)
	MOVWF       FSR1H 
	MOVLW       32
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        ___CC2DW+0, 0
;Display.c,69 :: 		if(Pos==1)        actual_theme = dark_green;
	MOVF        _Pos+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme6
	MOVLW       8
	MOVWF       R0 
	MOVLW       Display_actual_theme+0
	MOVWF       FSR1 
	MOVLW       hi_addr(Display_actual_theme+0)
	MOVWF       FSR1H 
	MOVLW       ChangeTheme_dark_green_L0+0
	MOVWF       FSR0 
	MOVLW       hi_addr(ChangeTheme_dark_green_L0+0)
	MOVWF       FSR0H 
L_ChangeTheme7:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme7
	GOTO        L_ChangeTheme8
L_ChangeTheme6:
;Display.c,70 :: 		else if(Pos==2)   actual_theme = fuchsia_black;
	MOVF        _Pos+0, 0 
	XORLW       2
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme9
	MOVLW       8
	MOVWF       R0 
	MOVLW       Display_actual_theme+0
	MOVWF       FSR1 
	MOVLW       hi_addr(Display_actual_theme+0)
	MOVWF       FSR1H 
	MOVLW       ChangeTheme_fuchsia_black_L0+0
	MOVWF       FSR0 
	MOVLW       hi_addr(ChangeTheme_fuchsia_black_L0+0)
	MOVWF       FSR0H 
L_ChangeTheme10:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme10
	GOTO        L_ChangeTheme11
L_ChangeTheme9:
;Display.c,71 :: 		else if(Pos==3)   actual_theme = blue_white;
	MOVF        _Pos+0, 0 
	XORLW       3
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme12
	MOVLW       8
	MOVWF       R0 
	MOVLW       Display_actual_theme+0
	MOVWF       FSR1 
	MOVLW       hi_addr(Display_actual_theme+0)
	MOVWF       FSR1H 
	MOVLW       ChangeTheme_blue_white_L0+0
	MOVWF       FSR0 
	MOVLW       hi_addr(ChangeTheme_blue_white_L0+0)
	MOVWF       FSR0H 
L_ChangeTheme13:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme13
	GOTO        L_ChangeTheme14
L_ChangeTheme12:
;Display.c,72 :: 		else if(Pos==4)   actual_theme = white_blue;
	MOVF        _Pos+0, 0 
	XORLW       4
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme15
	MOVLW       8
	MOVWF       R0 
	MOVLW       Display_actual_theme+0
	MOVWF       FSR1 
	MOVLW       hi_addr(Display_actual_theme+0)
	MOVWF       FSR1H 
	MOVLW       ChangeTheme_white_blue_L0+0
	MOVWF       FSR0 
	MOVLW       hi_addr(ChangeTheme_white_blue_L0+0)
	MOVWF       FSR0H 
L_ChangeTheme16:
	MOVF        POSTINC0+0, 0 
	MOVWF       POSTINC1+0 
	DECF        R0, 1 
	BTFSS       STATUS+0, 2 
	GOTO        L_ChangeTheme16
L_ChangeTheme15:
L_ChangeTheme14:
L_ChangeTheme11:
L_ChangeTheme8:
;Display.c,74 :: 		ThemeUpdated();
	CALL        _ThemeUpdated+0, 0
;Display.c,76 :: 		return;
;Display.c,77 :: 		}
L_end_ChangeTheme:
	RETURN      0
; end of _ChangeTheme

_MenuGenerator:

;Display.c,81 :: 		void MenuGenerator(unsigned char menu_cant,unsigned char separacion,unsigned char _widthEdge)
;Display.c,83 :: 		char i=1;
	MOVLW       1
	MOVWF       MenuGenerator_i_L0+0 
;Display.c,84 :: 		unsigned char width=((316/(menu_cant/2))-(separacion*2));
	MOVF        FARG_MenuGenerator_menu_cant+0, 0 
	MOVWF       FLOC__MenuGenerator+4 
	RRCF        FLOC__MenuGenerator+4, 1 
	BCF         FLOC__MenuGenerator+4, 7 
	MOVF        FLOC__MenuGenerator+4, 0 
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	MOVLW       60
	MOVWF       R0 
	MOVLW       1
	MOVWF       R1 
	CALL        _Div_16x16_S+0, 0
	MOVF        FARG_MenuGenerator_separacion+0, 0 
	MOVWF       FLOC__MenuGenerator+2 
	MOVLW       0
	MOVWF       FLOC__MenuGenerator+3 
	RLCF        FLOC__MenuGenerator+2, 1 
	RLCF        FLOC__MenuGenerator+3, 1 
	BCF         FLOC__MenuGenerator+2, 0 
	MOVF        FLOC__MenuGenerator+2, 0 
	SUBWF       R0, 0 
	MOVWF       FLOC__MenuGenerator+0 
	MOVF        FLOC__MenuGenerator+3, 0 
	SUBWFB      R1, 0 
	MOVWF       FLOC__MenuGenerator+1 
	MOVF        FLOC__MenuGenerator+0, 0 
	MOVWF       MenuGenerator_width_L0+0 
;Display.c,85 :: 		unsigned char high=((213/(menu_cant/2))-(separacion*2));
	MOVF        FLOC__MenuGenerator+4, 0 
	MOVWF       R4 
	MOVLW       213
	MOVWF       R0 
	CALL        _Div_8X8_U+0, 0
	MOVF        FLOC__MenuGenerator+2, 0 
	SUBWF       R0, 0 
	MOVWF       R2 
	MOVF        FLOC__MenuGenerator+3, 0 
	MOVWF       R3 
	MOVLW       0
	SUBFWB      R3, 1 
	MOVF        R2, 0 
	MOVWF       MenuGenerator_high_L0+0 
;Display.c,89 :: 		button1.Xs = 2;
	MOVLW       2
	MOVWF       MenuGenerator_button1_L0+0 
	MOVLW       0
	MOVWF       MenuGenerator_button1_L0+1 
;Display.c,90 :: 		button1.Ys = 25;
	MOVLW       25
	MOVWF       MenuGenerator_button1_L0+4 
;Display.c,91 :: 		button1.Xe = button1.Xs + width;
	MOVLW       2
	MOVWF       R0 
	MOVLW       0
	MOVWF       R1 
	MOVF        FLOC__MenuGenerator+0, 0 
	ADDWF       R0, 1 
	BTFSC       STATUS+0, 0 
	INCF        R1, 1 
	MOVF        R0, 0 
	MOVWF       MenuGenerator_button1_L0+2 
	MOVF        R1, 0 
	MOVWF       MenuGenerator_button1_L0+3 
;Display.c,92 :: 		button1.Ye = button1.Ys + high;
	MOVF        R2, 0 
	ADDLW       25
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       MenuGenerator_button1_L0+5 
;Display.c,93 :: 		button1.backgroundColour = actual_theme.backgroundletterColour;
	MOVF        Display_actual_theme+4, 0 
	MOVWF       MenuGenerator_button1_L0+8 
	MOVF        Display_actual_theme+5, 0 
	MOVWF       MenuGenerator_button1_L0+9 
;Display.c,94 :: 		button1.edgeColour = actual_theme.edgeColour;
	MOVF        Display_actual_theme+6, 0 
	MOVWF       MenuGenerator_button1_L0+6 
	MOVF        Display_actual_theme+7, 0 
	MOVWF       MenuGenerator_button1_L0+7 
;Display.c,95 :: 		button1.width = _widthEdge;
	MOVF        FARG_MenuGenerator__widthEdge+0, 0 
	MOVWF       MenuGenerator_button1_L0+10 
;Display.c,99 :: 		TFT_Set_Pen(button1.edgeColour,button1.width);
	MOVF        MenuGenerator_button1_L0+6, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+0 
	MOVF        MenuGenerator_button1_L0+7, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+1 
	MOVF        FARG_MenuGenerator__widthEdge+0, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_width+0 
	CALL        _TFT_Set_Pen+0, 0
;Display.c,100 :: 		TFT_Set_Brush(1,button1.backgroundColour,0,0,0,0);
	MOVLW       1
	MOVWF       FARG_TFT_Set_Brush_brush_enabled+0 
	MOVF        MenuGenerator_button1_L0+8, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+0 
	MOVF        MenuGenerator_button1_L0+9, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+1 
	CLRF        FARG_TFT_Set_Brush_gradient_enabled+0 
	CLRF        FARG_TFT_Set_Brush_gradient_orientation+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+1 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+1 
	CALL        _TFT_Set_Brush+0, 0
;Display.c,104 :: 		for(i=1;i<=menu_cant;i++)
	MOVLW       1
	MOVWF       MenuGenerator_i_L0+0 
L_MenuGenerator17:
	MOVF        MenuGenerator_i_L0+0, 0 
	SUBWF       FARG_MenuGenerator_menu_cant+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_MenuGenerator18
;Display.c,106 :: 		TFT_Rectangle_Round_Edges(button1.Xs+separacion,button1.Ys+separacion,button1.Xe,button1.Ye,12);
	MOVF        FARG_MenuGenerator_separacion+0, 0 
	ADDWF       MenuGenerator_button1_L0+0, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_x_upper_left+0 
	MOVLW       0
	ADDWFC      MenuGenerator_button1_L0+1, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_x_upper_left+1 
	MOVF        FARG_MenuGenerator_separacion+0, 0 
	ADDWF       MenuGenerator_button1_L0+4, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_y_upper_left+0 
	CLRF        FARG_TFT_Rectangle_Round_Edges_y_upper_left+1 
	MOVLW       0
	ADDWFC      FARG_TFT_Rectangle_Round_Edges_y_upper_left+1, 1 
	MOVF        MenuGenerator_button1_L0+2, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_x_bottom_right+0 
	MOVF        MenuGenerator_button1_L0+3, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_x_bottom_right+1 
	MOVF        MenuGenerator_button1_L0+5, 0 
	MOVWF       FARG_TFT_Rectangle_Round_Edges_y_bottom_right+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_Round_Edges_y_bottom_right+1 
	MOVLW       12
	MOVWF       FARG_TFT_Rectangle_Round_Edges_round_radius+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_Round_Edges_round_radius+1 
	CALL        _TFT_Rectangle_Round_Edges+0, 0
;Display.c,107 :: 		button1.Xs = button1.Xe;
	MOVF        MenuGenerator_button1_L0+2, 0 
	MOVWF       MenuGenerator_button1_L0+0 
	MOVF        MenuGenerator_button1_L0+3, 0 
	MOVWF       MenuGenerator_button1_L0+1 
;Display.c,108 :: 		button1.Xe = separacion + width;
	MOVF        MenuGenerator_width_L0+0, 0 
	ADDWF       FARG_MenuGenerator_separacion+0, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	ADDWFC      R1, 1 
	MOVF        R0, 0 
	MOVWF       MenuGenerator_button1_L0+2 
	MOVF        R1, 0 
	MOVWF       MenuGenerator_button1_L0+3 
;Display.c,109 :: 		button1.Ys = button1.Ye;
	MOVF        MenuGenerator_button1_L0+5, 0 
	MOVWF       MenuGenerator_button1_L0+4 
;Display.c,110 :: 		button1.Ye = separacion + high;
	MOVF        MenuGenerator_high_L0+0, 0 
	ADDWF       FARG_MenuGenerator_separacion+0, 0 
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       MenuGenerator_button1_L0+5 
;Display.c,104 :: 		for(i=1;i<=menu_cant;i++)
	INCF        MenuGenerator_i_L0+0, 1 
;Display.c,111 :: 		}
	GOTO        L_MenuGenerator17
L_MenuGenerator18:
;Display.c,113 :: 		ThemeUpdated();
	CALL        _ThemeUpdated+0, 0
;Display.c,115 :: 		return;
;Display.c,116 :: 		}
L_end_MenuGenerator:
	RETURN      0
; end of _MenuGenerator

_Selector:

;Display.c,118 :: 		void Selector(unsigned char estate)
;Display.c,120 :: 		if(estate==_ESTATE_MENU)
	MOVF        FARG_Selector_estate+0, 0 
	XORLW       1
	BTFSS       STATUS+0, 2 
	GOTO        L_Selector20
;Display.c,123 :: 		}
	GOTO        L_Selector21
L_Selector20:
;Display.c,124 :: 		else if(estate==_ESTATE_OUTPUT)
	MOVF        FARG_Selector_estate+0, 0 
	XORLW       2
	BTFSS       STATUS+0, 2 
	GOTO        L_Selector22
;Display.c,127 :: 		}
	GOTO        L_Selector23
L_Selector22:
;Display.c,128 :: 		else if(estate==_ESTATE_THEME)
	MOVF        FARG_Selector_estate+0, 0 
	XORLW       6
	BTFSS       STATUS+0, 2 
	GOTO        L_Selector24
;Display.c,131 :: 		}
L_Selector24:
L_Selector23:
L_Selector21:
;Display.c,133 :: 		return;
;Display.c,134 :: 		}
L_end_Selector:
	RETURN      0
; end of _Selector

_StaticDisplay:

;Display.c,136 :: 		void StaticDisplay(void)
;Display.c,138 :: 		TFT_Fill_Screen(actual_theme.screenColour);
	MOVF        Display_actual_theme+0, 0 
	MOVWF       FARG_TFT_Fill_Screen_color+0 
	MOVF        Display_actual_theme+1, 0 
	MOVWF       FARG_TFT_Fill_Screen_color+1 
	CALL        _TFT_Fill_Screen+0, 0
;Display.c,141 :: 		TFT_Rectangle(1,1,319,239);
	MOVLW       1
	MOVWF       FARG_TFT_Rectangle_x_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_x_upper_left+1 
	MOVLW       1
	MOVWF       FARG_TFT_Rectangle_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_upper_left+1 
	MOVLW       63
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+0 
	MOVLW       1
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+1 
	MOVLW       239
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+1 
	CALL        _TFT_Rectangle+0, 0
;Display.c,142 :: 		TFT_H_Line(10,310,25);
	MOVLW       10
	MOVWF       FARG_TFT_H_Line_x_start+0 
	MOVLW       0
	MOVWF       FARG_TFT_H_Line_x_start+1 
	MOVLW       54
	MOVWF       FARG_TFT_H_Line_x_end+0 
	MOVLW       1
	MOVWF       FARG_TFT_H_Line_x_end+1 
	MOVLW       25
	MOVWF       FARG_TFT_H_Line_y_pos+0 
	MOVLW       0
	MOVWF       FARG_TFT_H_Line_y_pos+1 
	CALL        _TFT_H_Line+0, 0
;Display.c,144 :: 		DateUpdated();
	CALL        _DateUpdated+0, 0
;Display.c,146 :: 		return;
;Display.c,147 :: 		}
L_end_StaticDisplay:
	RETURN      0
; end of _StaticDisplay

_DateUpdated:

;Display.c,149 :: 		void DateUpdated(void)
;Display.c,154 :: 		TFT_Set_Brush(1,actual_theme.screenColour,0,0,0,0);
	MOVLW       1
	MOVWF       FARG_TFT_Set_Brush_brush_enabled+0 
	MOVF        Display_actual_theme+0, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+0 
	MOVF        Display_actual_theme+1, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+1 
	CLRF        FARG_TFT_Set_Brush_gradient_enabled+0 
	CLRF        FARG_TFT_Set_Brush_gradient_orientation+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+1 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+1 
	CALL        _TFT_Set_Brush+0, 0
;Display.c,155 :: 		TFT_Set_Pen(actual_theme.screenColour, 3);
	MOVF        Display_actual_theme+0, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+0 
	MOVF        Display_actual_theme+1, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+1 
	MOVLW       3
	MOVWF       FARG_TFT_Set_Pen_pen_width+0 
	CALL        _TFT_Set_Pen+0, 0
;Display.c,156 :: 		TFT_Rectangle(200,4,316,22);
	MOVLW       200
	MOVWF       FARG_TFT_Rectangle_x_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_x_upper_left+1 
	MOVLW       4
	MOVWF       FARG_TFT_Rectangle_y_upper_left+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_upper_left+1 
	MOVLW       60
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+0 
	MOVLW       1
	MOVWF       FARG_TFT_Rectangle_x_bottom_right+1 
	MOVLW       22
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+0 
	MOVLW       0
	MOVWF       FARG_TFT_Rectangle_y_bottom_right+1 
	CALL        _TFT_Rectangle+0, 0
;Display.c,157 :: 		ThemeUpdated();
	CALL        _ThemeUpdated+0, 0
;Display.c,161 :: 		x=210;
	MOVLW       210
	MOVWF       Display_x+0 
	MOVLW       0
	MOVWF       Display_x+1 
;Display.c,162 :: 		y=4;
	MOVLW       4
	MOVWF       Display_y+0 
;Display.c,163 :: 		IntToStr(day,buffer1),TFT_Write_Text("11/11/11   12:12",x,y);
	MOVF        Display_day+0, 0 
	MOVWF       FARG_IntToStr_input+0 
	MOVLW       0
	MOVWF       FARG_IntToStr_input+1 
	MOVLW       DateUpdated_buffer1_L0+0
	MOVWF       FARG_IntToStr_output+0 
	MOVLW       hi_addr(DateUpdated_buffer1_L0+0)
	MOVWF       FARG_IntToStr_output+1 
	CALL        _IntToStr+0, 0
	MOVLW       ?lstr1_Display+0
	MOVWF       FARG_TFT_Write_Text_text+0 
	MOVLW       hi_addr(?lstr1_Display+0)
	MOVWF       FARG_TFT_Write_Text_text+1 
	MOVF        Display_x+0, 0 
	MOVWF       FARG_TFT_Write_Text_x+0 
	MOVF        Display_x+1, 0 
	MOVWF       FARG_TFT_Write_Text_x+1 
	MOVF        Display_y+0, 0 
	MOVWF       FARG_TFT_Write_Text_y+0 
	MOVLW       0
	MOVWF       FARG_TFT_Write_Text_y+1 
	CALL        _TFT_Write_Text+0, 0
;Display.c,187 :: 		return;
;Display.c,188 :: 		}
L_end_DateUpdated:
	RETURN      0
; end of _DateUpdated

_ThemeUpdated:

;Display.c,190 :: 		void ThemeUpdated(void)
;Display.c,192 :: 		TFT_Set_Font(TFT_defaultFont,actual_theme.letterColour,FO_HORIZONTAL);
	MOVLW       _TFT_defaultFont+0
	MOVWF       FARG_TFT_Set_Font_activeFont+0 
	MOVLW       hi_addr(_TFT_defaultFont+0)
	MOVWF       FARG_TFT_Set_Font_activeFont+1 
	MOVLW       higher_addr(_TFT_defaultFont+0)
	MOVWF       FARG_TFT_Set_Font_activeFont+2 
	MOVF        Display_actual_theme+2, 0 
	MOVWF       FARG_TFT_Set_Font_font_color+0 
	MOVF        Display_actual_theme+3, 0 
	MOVWF       FARG_TFT_Set_Font_font_color+1 
	CLRF        FARG_TFT_Set_Font_font_orientation+0 
	CALL        _TFT_Set_Font+0, 0
;Display.c,193 :: 		TFT_Set_Brush(0,actual_theme.backgroundletterColour,0,0,0,0);
	CLRF        FARG_TFT_Set_Brush_brush_enabled+0 
	MOVF        Display_actual_theme+4, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+0 
	MOVF        Display_actual_theme+5, 0 
	MOVWF       FARG_TFT_Set_Brush_brush_color+1 
	CLRF        FARG_TFT_Set_Brush_gradient_enabled+0 
	CLRF        FARG_TFT_Set_Brush_gradient_orientation+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_from+1 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+0 
	CLRF        FARG_TFT_Set_Brush_gradient_color_to+1 
	CALL        _TFT_Set_Brush+0, 0
;Display.c,194 :: 		TFT_Set_Pen(actual_theme.edgeColour, 1);
	MOVF        Display_actual_theme+6, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+0 
	MOVF        Display_actual_theme+7, 0 
	MOVWF       FARG_TFT_Set_Pen_pen_color+1 
	MOVLW       1
	MOVWF       FARG_TFT_Set_Pen_pen_width+0 
	CALL        _TFT_Set_Pen+0, 0
;Display.c,196 :: 		return;
;Display.c,197 :: 		}
L_end_ThemeUpdated:
	RETURN      0
; end of _ThemeUpdated

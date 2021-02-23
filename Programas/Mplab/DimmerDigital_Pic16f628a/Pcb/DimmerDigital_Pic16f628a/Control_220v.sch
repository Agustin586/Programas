EESchema Schematic File Version 4
LIBS:DimmerDigital_Pic16f628a-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Screw_Terminal_01x03 J1
U 1 1 602C152D
P 6300 2800
F 0 "J1" V 6264 2612 50  0000 R CNN
F 1 "Entrada_220v" V 6173 2612 50  0000 R CNN
F 2 "Borneras con tornillos:bornera_tornillos_1x03" H 6300 2800 50  0001 C CNN
F 3 "~" H 6300 2800 50  0001 C CNN
	1    6300 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Bridge_+A-A D1
U 1 1 602C3CDB
P 6800 3900
F 0 "D1" H 6456 3854 50  0000 R CNN
F 1 "D_Bridge_+A-A" H 6456 3945 50  0000 R CNN
F 2 "Diode_THT:Diode_Bridge_Round_D9.0mm" H 6800 3900 50  0001 C CNN
F 3 "~" H 6800 3900 50  0001 C CNN
	1    6800 3900
	-1   0    0    1   
$EndComp
Text Label 6200 3050 3    50   ~ 0
Ac1
Wire Wire Line
	6200 3050 6200 3000
Text Label 6400 3050 3    50   ~ 0
Ac2
Wire Wire Line
	6400 3050 6400 3000
NoConn ~ 6300 3000
Text Label 6800 3500 2    50   ~ 0
Ac1
Wire Wire Line
	6800 3500 6800 3600
Text Label 6800 4300 2    50   ~ 0
Ac2
Wire Wire Line
	6800 4300 6800 4200
$Comp
L Device:R R5
U 1 1 602C70E6
P 8000 3900
F 0 "R5" V 7793 3900 50  0000 C CNN
F 1 "22k" V 7884 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7930 3900 50  0001 C CNN
F 3 "~" H 8000 3900 50  0001 C CNN
	1    8000 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	7850 3900 7850 3400
Wire Wire Line
	7850 3400 7550 3400
Wire Wire Line
	6500 3400 6500 3900
$Comp
L Device:R R6
U 1 1 602C8143
P 8300 3900
F 0 "R6" V 8093 3900 50  0000 C CNN
F 1 "10k" V 8184 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8230 3900 50  0001 C CNN
F 3 "~" H 8300 3900 50  0001 C CNN
	1    8300 3900
	0    1    1    0   
$EndComp
$Comp
L Isolator:PC817 U2
U 1 1 602C836C
P 8850 4000
F 0 "U2" H 8850 4325 50  0000 C CNN
F 1 "PC817" H 8850 4234 50  0000 C CNN
F 2 "Package_DIP:DIP-4_W7.62mm_LongPads" H 8650 3800 50  0001 L CIN
F 3 "http://www.soselectronic.cz/a_info/resource/d/pc817.pdf" H 8850 4000 50  0001 L CNN
	1    8850 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 3900 8450 3900
Wire Wire Line
	7100 3900 7100 4100
Wire Wire Line
	7100 4100 7550 4100
$Comp
L Device:R R4
U 1 1 602C9256
P 9300 3650
F 0 "R4" H 9370 3696 50  0000 L CNN
F 1 "10k" H 9370 3605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 9230 3650 50  0001 C CNN
F 3 "~" H 9300 3650 50  0001 C CNN
	1    9300 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3800 9300 3900
Wire Wire Line
	9300 3900 9150 3900
Text GLabel 9300 3350 0    50   Input ~ 0
5V
Wire Wire Line
	9300 3350 9300 3500
Text GLabel 9550 3900 2    50   Input ~ 0
CrucexCero
Wire Wire Line
	9550 3900 9300 3900
Connection ~ 9300 3900
Text GLabel 9300 4100 2    50   Input ~ 0
GND_5V
Wire Wire Line
	9300 4100 9150 4100
$Comp
L Triac_Thyristor:BT136-500 Q1
U 1 1 602CE4A7
P 4350 3750
F 0 "Q1" H 4478 3796 50  0000 L CNN
F 1 "BT136-500" H 4478 3705 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Horizontal_TabDown" H 4550 3675 50  0001 L CIN
F 3 "http://www.micropik.com/PDF/BT136-600.pdf" H 4350 3750 50  0001 L CNN
	1    4350 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 602D095C
P 5050 3900
F 0 "C1" H 5165 3946 50  0000 L CNN
F 1 "0.01uf 400V" H 5165 3855 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L31.5mm_W9.0mm_P27.50mm_MKS4" H 5088 3750 50  0001 C CNN
F 3 "~" H 5050 3900 50  0001 C CNN
	1    5050 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 602D0FFC
P 5050 3600
F 0 "R2" H 4980 3554 50  0000 R CNN
F 1 "39" H 4980 3645 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4980 3600 50  0001 C CNN
F 3 "~" H 5050 3600 50  0001 C CNN
	1    5050 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	5050 3450 4350 3450
Wire Wire Line
	4350 3450 4350 3600
Wire Wire Line
	4350 4050 4350 3900
Text Label 6000 3450 0    50   ~ 0
Ac1
Wire Wire Line
	6000 3450 5050 3450
Connection ~ 5050 3450
$Comp
L Device:R R1
U 1 1 602D9F5E
P 3950 3450
F 0 "R1" V 4157 3450 50  0000 C CNN
F 1 "33k" V 4066 3450 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 3880 3450 50  0001 C CNN
F 3 "~" H 3950 3450 50  0001 C CNN
	1    3950 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4100 3450 4350 3450
Connection ~ 4350 3450
$Comp
L Relay_SolidState:MOC3021M U1
U 1 1 602DAABE
P 3150 3750
F 0 "U1" H 3150 4075 50  0000 C CNN
F 1 "MOC3021M" H 3150 3984 50  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm_LongPads" H 2950 3550 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/MO/MOC3020M.pdf" H 3125 3750 50  0001 L CNN
	1    3150 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 3650 3450 3450
Wire Wire Line
	3450 3450 3800 3450
Wire Wire Line
	3450 3850 3800 3850
$Comp
L Device:R R3
U 1 1 602DC84D
P 2600 3650
F 0 "R3" V 2807 3650 50  0000 C CNN
F 1 "180" V 2716 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2530 3650 50  0001 C CNN
F 3 "~" H 2600 3650 50  0001 C CNN
	1    2600 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2750 3650 2850 3650
Text GLabel 2350 3650 0    50   Input ~ 0
Habilitacion_Triac
Wire Wire Line
	2350 3650 2450 3650
Text GLabel 2750 3850 0    50   Input ~ 0
GND_5V
Wire Wire Line
	2750 3850 2850 3850
Wire Wire Line
	5050 4050 4350 4050
NoConn ~ 5550 4050
Wire Wire Line
	6000 4050 5650 4050
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 602D40F1
P 5550 4250
F 0 "J2" V 5650 4300 50  0000 R CNN
F 1 "Salida_Triac" V 5750 4450 50  0000 R CNN
F 2 "Borneras con tornillos:bornera_tornillos_1x03" H 5550 4250 50  0001 C CNN
F 3 "~" H 5550 4250 50  0001 C CNN
	1    5550 4250
	0    -1   1    0   
$EndComp
Text Label 6000 4050 0    50   ~ 0
Ac2
Connection ~ 5050 4050
Wire Wire Line
	5450 4050 5050 4050
Text Label 4350 3350 0    50   ~ 0
MT2
Wire Wire Line
	4350 3350 4350 3450
Text Label 4350 4150 0    50   ~ 0
MT1
Wire Wire Line
	4350 4150 4350 4050
Connection ~ 4350 4050
Text Label 3800 3950 0    50   ~ 0
GATE
Wire Wire Line
	3800 3950 3800 3850
Connection ~ 3800 3850
Wire Wire Line
	3800 3850 4200 3850
Text Label 7550 3300 0    50   ~ 0
PUENTE+
Wire Wire Line
	7550 3300 7550 3400
Connection ~ 7550 3400
Wire Wire Line
	7550 3400 6500 3400
Text Label 7550 4200 0    50   ~ 0
PUENTE-
Wire Wire Line
	7550 4200 7550 4100
Connection ~ 7550 4100
Wire Wire Line
	7550 4100 8550 4100
Text Label 5050 4150 0    50   ~ 0
CARGA1
Wire Wire Line
	5050 4150 5050 4050
Text Label 6000 4150 2    50   ~ 0
CARGA2
Wire Wire Line
	6000 4150 6000 4050
$EndSCHEMATC

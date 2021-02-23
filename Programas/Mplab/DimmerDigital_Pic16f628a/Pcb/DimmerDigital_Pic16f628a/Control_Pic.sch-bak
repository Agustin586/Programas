EESchema Schematic File Version 4
LIBS:DimmerDigital_Pic16f628a-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
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
L MCU_Microchip_PIC16:PIC16F628A-IP U4
U 1 1 602E70CF
P 5700 2600
F 0 "U4" H 5700 3481 50  0000 C CNN
F 1 "PIC16F628A-IP" H 5700 3390 50  0000 C CNN
F 2 "Package_DIP:DIP-18_W7.62mm_LongPads" H 5700 2600 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40300c.pdf" H 5700 2600 50  0001 C CNN
	1    5700 2600
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U3
U 1 1 602EAE60
P 2000 2250
F 0 "U3" H 2000 2492 50  0000 C CNN
F 1 "L7805" H 2000 2401 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2025 2100 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2000 2200 50  0001 C CNN
	1    2000 2250
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4007 D2
U 1 1 602ED0A7
P 2000 1900
F 0 "D2" H 2000 2116 50  0000 C CNN
F 1 "1N4007" H 2000 2025 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 2000 1725 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 2000 1900 50  0001 C CNN
	1    2000 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1900 2300 1900
Wire Wire Line
	2300 1900 2300 2250
Wire Wire Line
	1850 1900 1700 1900
Wire Wire Line
	1700 1900 1700 2250
$Comp
L Device:C C2
U 1 1 602ED79D
P 1500 2400
F 0 "C2" H 1615 2446 50  0000 L CNN
F 1 "330nf" H 1615 2355 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L10.0mm_W3.0mm_P7.50mm_FKS3_FKP3" H 1538 2250 50  0001 C CNN
F 3 "~" H 1500 2400 50  0001 C CNN
	1    1500 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2250 1700 2250
Connection ~ 1700 2250
$Comp
L Device:C C3
U 1 1 602EDAFC
P 2450 2400
F 0 "C3" H 2565 2446 50  0000 L CNN
F 1 "100nf" H 2565 2355 50  0000 L CNN
F 2 "Capacitor_THT:C_Rect_L10.0mm_W3.0mm_P7.50mm_FKS3_FKP3" H 2488 2250 50  0001 C CNN
F 3 "~" H 2450 2400 50  0001 C CNN
	1    2450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2250 2300 2250
Connection ~ 2300 2250
Wire Wire Line
	1500 2550 2000 2550
Wire Wire Line
	2000 2550 2450 2550
Connection ~ 2000 2550
Text GLabel 2000 2700 3    50   Input ~ 0
GND_5V
Wire Wire Line
	2000 2700 2000 2550
Wire Wire Line
	1000 2250 1050 2250
Text GLabel 3300 2250 2    50   Input ~ 0
5V
Wire Wire Line
	3300 2250 2900 2250
Connection ~ 2450 2250
Text GLabel 5800 1900 2    50   Input ~ 0
5V
Wire Wire Line
	5800 1900 5700 1900
Text GLabel 5850 3300 2    50   Input ~ 0
GND_5V
Wire Wire Line
	5850 3300 5700 3300
$Comp
L Switch:SW_Push SW4
U 1 1 602F0FAD
P 5000 4350
F 0 "SW4" V 5046 4302 50  0000 R CNN
F 1 "RESET" V 4955 4302 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5000 4550 50  0001 C CNN
F 3 "~" H 5000 4550 50  0001 C CNN
	1    5000 4350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R10
U 1 1 602F1931
P 5000 3950
F 0 "R10" H 5070 3996 50  0000 L CNN
F 1 "10k" H 5070 3905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4930 3950 50  0001 C CNN
F 3 "~" H 5000 3950 50  0001 C CNN
	1    5000 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4100 5000 4150
Text GLabel 5000 4650 0    50   Input ~ 0
GND_5V
Wire Wire Line
	5000 4650 5000 4550
Text GLabel 5000 3700 0    50   Input ~ 0
5V
Wire Wire Line
	5000 3700 5000 3800
Text Label 5200 4150 0    50   ~ 0
RESET
Wire Wire Line
	5200 4150 5000 4150
Connection ~ 5000 4150
Text GLabel 5650 3700 0    50   Input ~ 0
5V
$Comp
L Switch:SW_Push SW1
U 1 1 602F2D62
P 5650 3900
F 0 "SW1" V 5696 3852 50  0000 R CNN
F 1 "SS" V 5605 3852 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 5650 4100 50  0001 C CNN
F 3 "~" H 5650 4100 50  0001 C CNN
	1    5650 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R15
U 1 1 602F3831
P 5650 4350
F 0 "R15" H 5720 4396 50  0000 L CNN
F 1 "10k" H 5720 4305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5580 4350 50  0001 C CNN
F 3 "~" H 5650 4350 50  0001 C CNN
	1    5650 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4500 5650 4550
Wire Wire Line
	5650 4550 5000 4550
Connection ~ 5000 4550
Text GLabel 6100 3700 0    50   Input ~ 0
5V
$Comp
L Switch:SW_Push SW2
U 1 1 602F4B18
P 6100 3900
F 0 "SW2" V 6146 3852 50  0000 R CNN
F 1 "UP" V 6055 3852 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6100 4100 50  0001 C CNN
F 3 "~" H 6100 4100 50  0001 C CNN
	1    6100 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R16
U 1 1 602F4B1E
P 6100 4350
F 0 "R16" H 6170 4396 50  0000 L CNN
F 1 "10k" H 6170 4305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6030 4350 50  0001 C CNN
F 3 "~" H 6100 4350 50  0001 C CNN
	1    6100 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4200 6100 4150
Wire Wire Line
	6100 4500 6100 4550
Wire Wire Line
	6100 4550 5650 4550
Connection ~ 5650 4550
Text GLabel 6550 3700 0    50   Input ~ 0
5V
$Comp
L Switch:SW_Push SW3
U 1 1 602F55ED
P 6550 3900
F 0 "SW3" V 6596 3852 50  0000 R CNN
F 1 "DOWN" V 6505 3852 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 6550 4100 50  0001 C CNN
F 3 "~" H 6550 4100 50  0001 C CNN
	1    6550 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R17
U 1 1 602F55F3
P 6550 4350
F 0 "R17" H 6620 4396 50  0000 L CNN
F 1 "10k" H 6620 4305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6480 4350 50  0001 C CNN
F 3 "~" H 6550 4350 50  0001 C CNN
	1    6550 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 4200 6550 4150
Wire Wire Line
	6550 4500 6550 4550
Wire Wire Line
	6550 4550 6100 4550
Connection ~ 6100 4550
Text Label 5750 4150 0    50   ~ 0
START_S
Wire Wire Line
	5650 4200 5650 4150
Wire Wire Line
	5750 4150 5650 4150
Connection ~ 5650 4150
Wire Wire Line
	5650 4150 5650 4100
Text Label 6200 4150 0    50   ~ 0
UP
Wire Wire Line
	6200 4150 6100 4150
Connection ~ 6100 4150
Wire Wire Line
	6100 4150 6100 4100
Text Label 6650 4150 0    50   ~ 0
DOWN
Wire Wire Line
	6650 4150 6550 4150
Connection ~ 6550 4150
Wire Wire Line
	6550 4150 6550 4100
Text Label 6850 2700 0    50   ~ 0
MCLR
Wire Wire Line
	6850 2700 6800 2700
Text Label 4550 2500 2    50   ~ 0
START_S
Wire Wire Line
	4550 2500 4600 2500
Text Label 4550 2400 2    50   ~ 0
UP
Wire Wire Line
	4550 2400 4600 2400
Text Label 4550 2600 2    50   ~ 0
DOWN
Wire Wire Line
	4550 2600 4600 2600
Text Label 6900 2900 0    50   ~ 0
BLINK
Wire Wire Line
	6900 2900 6800 2900
Text Label 6850 2200 0    50   ~ 0
A
Wire Wire Line
	6850 2200 6800 2200
Text Label 6850 2300 0    50   ~ 0
B
Wire Wire Line
	6850 2300 6800 2300
Text Label 6850 2400 0    50   ~ 0
C
Wire Wire Line
	6850 2400 6800 2400
Text Label 6850 2500 0    50   ~ 0
D
Wire Wire Line
	6850 2500 6800 2500
Text GLabel 4550 2200 0    50   Input ~ 0
CrucexCero
Wire Wire Line
	4550 2200 4600 2200
Text GLabel 4550 2300 0    50   Input ~ 0
Habilitacion_Triac
Wire Wire Line
	4550 2300 4600 2300
Text Label 4550 2700 2    50   ~ 0
D1
Wire Wire Line
	4550 2700 4600 2700
Text Label 4550 2800 2    50   ~ 0
D2
Wire Wire Line
	4550 2800 4600 2800
Text Label 4550 2900 2    50   ~ 0
D3
Wire Wire Line
	4550 2900 4600 2900
NoConn ~ 6800 2600
$Comp
L Display_Character:LTS-6980HR AFF1
U 1 1 60303EF2
P 8100 2600
F 0 "AFF1" H 8100 3267 50  0000 C CNN
F 1 "LTS-6980HR" H 8100 3176 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 8100 2000 50  0001 C CNN
F 3 "http://datasheet.octopart.com/LTS-6960HR-Lite-On-datasheet-11803242.pdf" H 8100 2600 50  0001 C CNN
	1    8100 2600
	1    0    0    -1  
$EndComp
$Comp
L Display_Character:LTS-6980HR AFF2
U 1 1 6030467C
P 9300 2600
F 0 "AFF2" H 9300 3267 50  0000 C CNN
F 1 "LTS-6980HR" H 9300 3176 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 9300 2000 50  0001 C CNN
F 3 "http://datasheet.octopart.com/LTS-6960HR-Lite-On-datasheet-11803242.pdf" H 9300 2600 50  0001 C CNN
	1    9300 2600
	1    0    0    -1  
$EndComp
Text Label 7550 2200 2    50   ~ 0
Qa
Wire Wire Line
	7550 2200 7600 2200
Text Label 7550 2300 2    50   ~ 0
Qb
Wire Wire Line
	7550 2300 7600 2300
Text Label 7550 2400 2    50   ~ 0
Qc
Wire Wire Line
	7550 2400 7600 2400
Text Label 7550 2500 2    50   ~ 0
Qd
Wire Wire Line
	7550 2500 7600 2500
Text Label 7550 2600 2    50   ~ 0
Qe
Wire Wire Line
	7550 2600 7600 2600
Text Label 7550 2700 2    50   ~ 0
Qf
Wire Wire Line
	7550 2700 7600 2700
Text Label 7550 2800 2    50   ~ 0
Qg
Wire Wire Line
	7550 2800 7600 2800
Text Label 8750 2200 2    50   ~ 0
Qa
Wire Wire Line
	8750 2200 8800 2200
Text Label 8750 2300 2    50   ~ 0
Qb
Wire Wire Line
	8750 2300 8800 2300
Text Label 8750 2400 2    50   ~ 0
Qc
Wire Wire Line
	8750 2400 8800 2400
Text Label 8750 2500 2    50   ~ 0
Qd
Wire Wire Line
	8750 2500 8800 2500
Text Label 8750 2600 2    50   ~ 0
Qe
Wire Wire Line
	8750 2600 8800 2600
Text Label 8750 2700 2    50   ~ 0
Qf
Wire Wire Line
	8750 2700 8800 2700
Text Label 8750 2800 2    50   ~ 0
Qg
Wire Wire Line
	8750 2800 8800 2800
$Comp
L Display_Character:LTS-6980HR AFF3
U 1 1 60313F25
P 10500 2600
F 0 "AFF3" H 10500 3267 50  0000 C CNN
F 1 "LTS-6980HR" H 10500 3176 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_LTS6760_LTS6780" H 10500 2000 50  0001 C CNN
F 3 "http://datasheet.octopart.com/LTS-6960HR-Lite-On-datasheet-11803242.pdf" H 10500 2600 50  0001 C CNN
	1    10500 2600
	1    0    0    -1  
$EndComp
Text Label 9950 2200 2    50   ~ 0
Qa
Wire Wire Line
	9950 2200 10000 2200
Text Label 9950 2300 2    50   ~ 0
Qb
Wire Wire Line
	9950 2300 10000 2300
Text Label 9950 2400 2    50   ~ 0
Qc
Wire Wire Line
	9950 2400 10000 2400
Text Label 9950 2500 2    50   ~ 0
Qd
Wire Wire Line
	9950 2500 10000 2500
Text Label 9950 2600 2    50   ~ 0
Qe
Wire Wire Line
	9950 2600 10000 2600
Text Label 9950 2700 2    50   ~ 0
Qf
Wire Wire Line
	9950 2700 10000 2700
Text Label 9950 2800 2    50   ~ 0
Qg
Wire Wire Line
	9950 2800 10000 2800
Wire Wire Line
	9250 4050 9300 4050
Text Label 9250 4050 2    50   ~ 0
D
Wire Wire Line
	9250 3950 9300 3950
Text Label 9250 3950 2    50   ~ 0
C
Wire Wire Line
	9250 3850 9300 3850
Text Label 9250 3850 2    50   ~ 0
B
Wire Wire Line
	9250 3750 9300 3750
Text Label 9250 3750 2    50   ~ 0
A
Wire Wire Line
	8500 3600 8400 3600
Text GLabel 8500 3600 2    50   Input ~ 0
GND_5V
Wire Wire Line
	8500 4050 8400 4050
Text GLabel 8500 4050 2    50   Input ~ 0
GND_5V
Wire Wire Line
	8500 4500 8400 4500
Text GLabel 8500 4500 2    50   Input ~ 0
GND_5V
Wire Wire Line
	7800 4500 7900 4500
Text GLabel 7800 4500 0    50   Input ~ 0
5V
Wire Wire Line
	7800 4050 7900 4050
Text GLabel 7800 4050 0    50   Input ~ 0
5V
Wire Wire Line
	7800 3600 7900 3600
Text GLabel 7800 3600 0    50   Input ~ 0
5V
Wire Wire Line
	8100 4650 8150 4650
Text Label 8100 4650 2    50   ~ 0
BT
Wire Wire Line
	8100 4200 8150 4200
Text Label 8100 4200 2    50   ~ 0
LT
Wire Wire Line
	8100 3750 8150 3750
Text Label 8100 3750 2    50   ~ 0
LE
Wire Wire Line
	9250 4250 9300 4250
Text Label 9250 4250 2    50   ~ 0
BT
Wire Wire Line
	9250 4150 9300 4150
Text Label 9250 4150 2    50   ~ 0
LT
Wire Wire Line
	9250 3650 9300 3650
Text Label 9250 3650 2    50   ~ 0
LE
$Comp
L Jumper:Jumper_3_Bridged12 JP3
U 1 1 6032C796
P 8150 4500
F 0 "JP3" H 8150 4704 50  0000 C CNN
F 1 "4511_BT" H 8150 4613 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8150 4500 50  0001 C CNN
F 3 "~" H 8150 4500 50  0001 C CNN
	1    8150 4500
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_3_Bridged12 JP2
U 1 1 6032C25B
P 8150 4050
F 0 "JP2" H 8150 4254 50  0000 C CNN
F 1 "4511_LT" H 8150 4163 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8150 4050 50  0001 C CNN
F 3 "~" H 8150 4050 50  0001 C CNN
	1    8150 4050
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_3_Bridged12 JP1
U 1 1 603231BB
P 8150 3600
F 0 "JP1" H 8150 3804 50  0000 C CNN
F 1 "4511_LE" H 8150 3713 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8150 3600 50  0001 C CNN
F 3 "~" H 8150 3600 50  0001 C CNN
	1    8150 3600
	1    0    0    -1  
$EndComp
Text GLabel 10000 3550 2    50   Input ~ 0
5V
Wire Wire Line
	10000 3550 9850 3550
Wire Wire Line
	9850 3550 9850 3600
Text GLabel 9950 4350 2    50   Input ~ 0
GND_5V
$Comp
L Device:R R14
U 1 1 6030B034
P 10550 4250
F 0 "R14" V 10550 4250 50  0000 C CNN
F 1 "330" V 10550 4250 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 4250 50  0001 C CNN
F 3 "~" H 10550 4250 50  0001 C CNN
	1    10550 4250
	0    1    1    0   
$EndComp
$Comp
L Device:R R13
U 1 1 6030AE09
P 10550 4150
F 0 "R13" V 10550 4150 50  0000 C CNN
F 1 "330" V 10550 4150 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 4150 50  0001 C CNN
F 3 "~" H 10550 4150 50  0001 C CNN
	1    10550 4150
	0    1    1    0   
$EndComp
$Comp
L Device:R R12
U 1 1 6030ACCD
P 10550 4050
F 0 "R12" V 10550 4050 50  0000 C CNN
F 1 "330" V 10550 4050 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 4050 50  0001 C CNN
F 3 "~" H 10550 4050 50  0001 C CNN
	1    10550 4050
	0    1    1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 6030AA30
P 10550 3950
F 0 "R11" V 10550 3950 50  0000 C CNN
F 1 "330" V 10550 3950 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 3950 50  0001 C CNN
F 3 "~" H 10550 3950 50  0001 C CNN
	1    10550 3950
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 6030A6D7
P 10550 3850
F 0 "R9" V 10550 3850 50  0000 C CNN
F 1 "330" V 10550 3850 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 3850 50  0001 C CNN
F 3 "~" H 10550 3850 50  0001 C CNN
	1    10550 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 6030A49C
P 10550 3750
F 0 "R8" V 10550 3750 50  0000 C CNN
F 1 "330" V 10550 3750 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 3750 50  0001 C CNN
F 3 "~" H 10550 3750 50  0001 C CNN
	1    10550 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 6030A094
P 10550 3650
F 0 "R7" V 10550 3650 50  0000 C CNN
F 1 "330" V 10550 3650 50  0001 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10480 3650 50  0001 C CNN
F 3 "~" H 10550 3650 50  0001 C CNN
	1    10550 3650
	0    1    1    0   
$EndComp
Wire Wire Line
	10750 4250 10700 4250
Text Label 10750 4250 0    50   ~ 0
Qg
Wire Wire Line
	10750 4150 10700 4150
Text Label 10750 4150 0    50   ~ 0
Qf
Wire Wire Line
	10750 4050 10700 4050
Text Label 10750 4050 0    50   ~ 0
Qe
Wire Wire Line
	10750 3950 10700 3950
Text Label 10750 3950 0    50   ~ 0
Qd
Wire Wire Line
	10750 3850 10700 3850
Text Label 10750 3850 0    50   ~ 0
Qc
Wire Wire Line
	10750 3750 10700 3750
Text Label 10750 3750 0    50   ~ 0
Qb
Wire Wire Line
	10750 3650 10700 3650
Text Label 10750 3650 0    50   ~ 0
Qa
$Comp
L 4xxx_IEEE:4511 U5
U 1 1 6030214B
P 9850 3950
F 0 "U5" H 9850 4516 50  0000 C CNN
F 1 "4511" H 9850 4425 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W10.16mm_LongPads" H 9850 3950 50  0001 C CNN
F 3 "" H 9850 3950 50  0001 C CNN
	1    9850 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D3
U 1 1 603A60AC
P 5000 5550
F 0 "D3" V 5039 5433 50  0000 R CNN
F 1 "LED_BLINK" V 4948 5433 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 5000 5550 50  0001 C CNN
F 3 "~" H 5000 5550 50  0001 C CNN
	1    5000 5550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R18
U 1 1 603A689B
P 5000 5200
F 0 "R18" H 5070 5246 50  0000 L CNN
F 1 "330" H 5070 5155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4930 5200 50  0001 C CNN
F 3 "~" H 5000 5200 50  0001 C CNN
	1    5000 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 5350 5000 5400
Text Label 5000 4950 2    50   ~ 0
BLINK
Wire Wire Line
	5000 4950 5000 5050
Text GLabel 5000 5800 2    50   Input ~ 0
GND_5V
Wire Wire Line
	5000 5800 5000 5700
$Comp
L Transistor_BJT:BC548 Q2
U 1 1 603B569C
P 8050 5250
F 0 "Q2" H 8241 5296 50  0000 L CNN
F 1 "BC548" H 8241 5205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8250 5175 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 8050 5250 50  0001 L CNN
	1    8050 5250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q3
U 1 1 603B6689
P 9250 5250
F 0 "Q3" H 9441 5296 50  0000 L CNN
F 1 "BC548" H 9441 5205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 9450 5175 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 9250 5250 50  0001 L CNN
	1    9250 5250
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC548 Q4
U 1 1 603B74A4
P 10450 5250
F 0 "Q4" H 10641 5296 50  0000 L CNN
F 1 "BC548" H 10641 5205 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 10650 5175 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 10450 5250 50  0001 L CNN
	1    10450 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:R R19
U 1 1 603B7BA3
P 7700 5250
F 0 "R19" V 7800 5200 50  0000 L CNN
F 1 "22k" V 7700 5200 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 7630 5250 50  0001 C CNN
F 3 "~" H 7700 5250 50  0001 C CNN
	1    7700 5250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R20
U 1 1 603B8682
P 8900 5250
F 0 "R20" V 9000 5200 50  0000 L CNN
F 1 "22k" V 8900 5200 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 8830 5250 50  0001 C CNN
F 3 "~" H 8900 5250 50  0001 C CNN
	1    8900 5250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R21
U 1 1 603B8C47
P 10100 5250
F 0 "R21" V 10200 5200 50  0000 L CNN
F 1 "22k" V 10100 5200 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 10030 5250 50  0001 C CNN
F 3 "~" H 10100 5250 50  0001 C CNN
	1    10100 5250
	0    -1   -1   0   
$EndComp
Text GLabel 8150 5550 2    50   Input ~ 0
GND_5V
Wire Wire Line
	8150 5550 8150 5450
Text GLabel 9350 5550 2    50   Input ~ 0
GND_5V
Wire Wire Line
	9350 5550 9350 5450
Text GLabel 10550 5550 2    50   Input ~ 0
GND_5V
Wire Wire Line
	10550 5550 10550 5450
Wire Wire Line
	8600 2300 8600 2200
Wire Wire Line
	8600 2200 8600 2000
Connection ~ 8600 2200
Text Label 8600 2000 0    50   ~ 0
DIGITO_1
Wire Wire Line
	9800 2300 9800 2200
Wire Wire Line
	9800 2200 9800 2000
Connection ~ 9800 2200
Text Label 9800 2000 0    50   ~ 0
DIGITO_2
Wire Wire Line
	11000 2300 11000 2200
Text Label 11000 2000 2    50   ~ 0
DIGITO_3
Text Label 8150 4950 0    50   ~ 0
DIGITO_1
Wire Wire Line
	8150 4950 8150 5050
Text Label 9350 4950 0    50   ~ 0
DIGITO_2
Wire Wire Line
	9350 4950 9350 5050
Text Label 10550 4950 0    50   ~ 0
DIGITO_3
Wire Wire Line
	10550 4950 10550 5050
$Comp
L Connector:Barrel_Jack_Switch J4
U 1 1 603EAF57
P 950 3000
F 0 "J4" H 1007 3317 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 1007 3226 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 1000 2960 50  0001 C CNN
F 3 "~" H 1000 2960 50  0001 C CNN
	1    950  3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1000 2350 1000 2550
Wire Wire Line
	1000 2550 1500 2550
Connection ~ 1500 2550
Wire Wire Line
	1250 3000 1250 3050
Wire Wire Line
	1500 2550 1500 3050
Wire Wire Line
	1500 3050 1250 3050
Connection ~ 1250 3050
Wire Wire Line
	1250 3050 1250 3100
Wire Wire Line
	1250 2900 1250 2600
Wire Wire Line
	1250 2600 1050 2600
Wire Wire Line
	1050 2600 1050 2250
$Comp
L Diode:1N4007 D4
U 1 1 60404969
P 1300 2250
F 0 "D4" H 1200 2450 50  0000 C CNN
F 1 "1N4007" H 1300 2350 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 1300 2075 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 1300 2250 50  0001 C CNN
	1    1300 2250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1150 2250 1050 2250
Connection ~ 1050 2250
Wire Wire Line
	1450 2250 1500 2250
Connection ~ 1500 2250
$Comp
L Device:LED D5
U 1 1 604119FF
P 2900 2800
F 0 "D5" V 2939 2682 50  0000 R CNN
F 1 "LED_ENCENDIDO" V 2848 2682 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 2900 2800 50  0001 C CNN
F 3 "~" H 2900 2800 50  0001 C CNN
	1    2900 2800
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R22
U 1 1 604123AE
P 2900 2450
F 0 "R22" H 2970 2496 50  0000 L CNN
F 1 "330" H 2970 2405 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2830 2450 50  0001 C CNN
F 3 "~" H 2900 2450 50  0001 C CNN
	1    2900 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 2300 2900 2250
Connection ~ 2900 2250
Wire Wire Line
	2900 2250 2450 2250
Wire Wire Line
	2900 2650 2900 2600
Text GLabel 3050 3050 2    50   Input ~ 0
GND_5V
Wire Notes Line
	550  3450 3750 3450
Wire Notes Line
	3750 1600 550  1600
Wire Notes Line
	550  1600 550  3450
Wire Notes Line
	3750 1600 3750 3450
Text Notes 550  1550 0    50   ~ 0
Alimentacion
Wire Notes Line
	3800 1600 3800 5950
Wire Notes Line
	3800 5950 7200 5950
Wire Notes Line
	7200 5950 7200 1600
Wire Notes Line
	7200 1600 3800 1600
Text Notes 3800 1550 0    50   ~ 0
Control
Wire Notes Line
	7300 1600 7300 5950
Wire Notes Line
	11200 5950 11200 1600
Wire Notes Line
	11200 1600 7300 1600
Wire Notes Line
	7300 5950 11200 5950
Text Notes 7300 1550 0    50   ~ 0
Control de Digitos
Wire Wire Line
	11000 2000 11000 2200
Connection ~ 11000 2200
NoConn ~ 11000 2900
NoConn ~ 9800 2900
NoConn ~ 8600 2900
Text Label 7550 5150 2    50   ~ 0
D1
Text Label 8750 5150 2    50   ~ 0
D2
Text Label 9950 5150 2    50   ~ 0
D3
Wire Wire Line
	7550 5150 7550 5250
Wire Wire Line
	8750 5150 8750 5250
Wire Wire Line
	9950 5150 9950 5250
$Comp
L Connector:Conn_01x03_Male J5
U 1 1 604A7947
P 900 4200
F 0 "J5" H 1100 4500 50  0000 C CNN
F 1 "PROGRAMACION" H 1150 4400 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 900 4200 50  0001 C CNN
F 3 "~" H 900 4200 50  0001 C CNN
	1    900  4200
	1    0    0    -1  
$EndComp
Text Label 1500 4200 0    50   ~ 0
MCLR
Wire Wire Line
	1500 4200 1100 4200
Text Label 1500 4100 0    50   ~ 0
RESET
Wire Wire Line
	1500 4100 1100 4100
Text Label 1500 4300 0    50   ~ 0
PICKIT
Wire Wire Line
	1500 4300 1100 4300
$Comp
L Connector:Conn_01x05_Male J6
U 1 1 604C40B3
P 900 4800
F 0 "J6" H 1150 4400 50  0000 R CNN
F 1 "PICKIT 3" H 1200 4500 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 900 4800 50  0001 C CNN
F 3 "~" H 900 4800 50  0001 C CNN
	1    900  4800
	1    0    0    1   
$EndComp
Text Label 1250 5000 0    50   ~ 0
PICKIT
Wire Wire Line
	1250 5000 1100 5000
Text GLabel 1250 4900 2    50   Input ~ 0
5V
Wire Wire Line
	1250 4900 1100 4900
Text GLabel 1250 4800 2    50   Input ~ 0
GND_5V
Wire Wire Line
	1250 4800 1100 4800
Text Label 1250 4700 0    50   ~ 0
PGD
Wire Wire Line
	1250 4700 1100 4700
Text Label 1250 4600 0    50   ~ 0
PGC
Wire Wire Line
	1250 4600 1100 4600
Text Label 1700 4700 2    50   ~ 0
PGD
Text Label 1750 4700 0    50   ~ 0
D3
Wire Wire Line
	1750 4700 1700 4700
Text Label 1700 4600 2    50   ~ 0
PGC
Text Label 1750 4600 0    50   ~ 0
D2
Wire Wire Line
	1750 4600 1700 4600
Wire Notes Line
	550  3800 550  5100
Wire Notes Line
	550  5100 1900 5100
Wire Notes Line
	1900 5100 1900 3800
Wire Notes Line
	1900 3800 550  3800
Text Notes 550  3750 0    50   ~ 0
Programacion
Wire Wire Line
	9850 4300 9850 4350
Wire Wire Line
	9850 4350 9950 4350
$Comp
L power:GND #PWR0102
U 1 1 6051ABC3
P 2750 3050
F 0 "#PWR0102" H 2750 2800 50  0001 C CNN
F 1 "GND" H 2755 2877 50  0000 C CNN
F 2 "" H 2750 3050 50  0001 C CNN
F 3 "" H 2750 3050 50  0001 C CNN
	1    2750 3050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60529075
P 3350 1850
F 0 "#FLG0101" H 3350 1925 50  0001 C CNN
F 1 "PWR_FLAG" H 3350 2023 50  0000 C CNN
F 2 "" H 3350 1850 50  0001 C CNN
F 3 "~" H 3350 1850 50  0001 C CNN
	1    3350 1850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0103
U 1 1 60529C08
P 3350 1850
F 0 "#PWR0103" H 3350 1700 50  0001 C CNN
F 1 "VCC" H 3368 2023 50  0000 C CNN
F 2 "" H 3350 1850 50  0001 C CNN
F 3 "" H 3350 1850 50  0001 C CNN
	1    3350 1850
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 6052A303
P 3750 1850
F 0 "#FLG0102" H 3750 1925 50  0001 C CNN
F 1 "PWR_FLAG" H 3750 2023 50  0000 C CNN
F 2 "" H 3750 1850 50  0001 C CNN
F 3 "~" H 3750 1850 50  0001 C CNN
	1    3750 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 6052ABA9
P 3750 1850
F 0 "#PWR0104" H 3750 1600 50  0001 C CNN
F 1 "GND" H 3755 1677 50  0000 C CNN
F 2 "" H 3750 1850 50  0001 C CNN
F 3 "" H 3750 1850 50  0001 C CNN
	1    3750 1850
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 60514AF5
P 1500 2000
F 0 "#PWR0101" H 1500 1850 50  0001 C CNN
F 1 "VCC" H 1517 2173 50  0000 C CNN
F 2 "" H 1500 2000 50  0001 C CNN
F 3 "" H 1500 2000 50  0001 C CNN
	1    1500 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2000 1500 2250
Wire Wire Line
	3050 3050 2900 3050
Wire Wire Line
	2900 3050 2900 2950
Wire Wire Line
	2900 3050 2750 3050
Connection ~ 2900 3050
Text Label 6850 2800 0    50   ~ 0
BUZZER
Wire Wire Line
	6850 2800 6800 2800
$Comp
L Device:Buzzer BZ1
U 1 1 605F114C
P 6400 5050
F 0 "BZ1" H 6552 5079 50  0000 L CNN
F 1 "Buzzer" H 6552 4988 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 6375 5150 50  0001 C CNN
F 3 "~" V 6375 5150 50  0001 C CNN
	1    6400 5050
	1    0    0    -1  
$EndComp
Text GLabel 6300 5300 2    50   Input ~ 0
GND_5V
Wire Wire Line
	6300 5300 6300 5150
Text Label 6250 4950 2    50   ~ 0
BUZZER
Wire Wire Line
	6250 4950 6300 4950
$Comp
L Connector:Screw_Terminal_01x03 J7
U 1 1 6032E310
P 800 2250
F 0 "J7" H 800 2000 50  0000 C CNN
F 1 "Entrada Alimentacion" V 900 2250 50  0000 C CNN
F 2 "Borneras con tornillos:bornera_tornillos_1x03" H 800 2250 50  0001 C CNN
F 3 "~" H 800 2250 50  0001 C CNN
	1    800  2250
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x02_Male J3
U 1 1 603304AF
P 1100 1700
F 0 "J3" V 1150 1850 50  0000 R CNN
F 1 "Habilitacion 5v" V 1050 1900 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 1100 1700 50  0001 C CNN
F 3 "~" H 1100 1700 50  0001 C CNN
	1    1100 1700
	0    -1   1    0   
$EndComp
Wire Wire Line
	1100 1900 1100 2150
Wire Wire Line
	1100 2150 1000 2150
Text GLabel 1200 2000 2    50   Input ~ 0
5V
Wire Wire Line
	1200 2000 1200 1900
$EndSCHEMATC

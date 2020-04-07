EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "AVRISP mkII mod-Vcc"
Date "2020-02-26"
Rev "0.1"
Comp "Osamu Aoki "
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:USB_B J1
U 1 1 5E56519A
P 3950 2100
F 0 "J1" H 4007 2567 50  0000 C CNN
F 1 "USB_B" H 4007 2476 50  0000 C CNN
F 2 "" H 4100 2050 50  0001 C CNN
F 3 " ~" H 4100 2050 50  0001 C CNN
	1    3950 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 5E566340
P 5400 1900
F 0 "F1" V 5175 1900 50  0000 C CNN
F 1 "Polyfuse" V 5266 1900 50  0000 C CNN
F 2 "" H 5450 1700 50  0001 L CNN
F 3 "~" H 5400 1900 50  0001 C CNN
	1    5400 1900
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x03_Odd_Even J2
U 1 1 5E577C2F
P 4850 4150
F 0 "J2" H 4900 4467 50  0000 C CNN
F 1 "Conn_02x03 BTM" H 4900 4376 50  0000 C CNN
F 2 "" H 4850 4150 50  0001 C CNN
F 3 "~" H 4850 4150 50  0001 C CNN
	1    4850 4150
	-1   0    0    -1  
$EndComp
Text Notes 4100 1600 0    50   ~ 0
PIN 1 is left most pin from\nback of USB B conector\nConnect directly from conector
Wire Wire Line
	4250 1900 5250 1900
Wire Wire Line
	5550 1900 6100 1900
Wire Wire Line
	7150 2000 4400 2000
Wire Wire Line
	4550 4250 4350 4250
Wire Wire Line
	4350 4250 4350 4650
Wire Wire Line
	4350 4650 5450 4650
Wire Wire Line
	5450 4650 5450 3400
$Comp
L Connector:Conn_01x05_Female J3
U 1 1 5E57DE1B
P 7350 2000
F 0 "J3" H 7378 2026 50  0000 L CNN
F 1 "Conn_01x05_Female" H 6700 1400 50  0000 L CNN
F 2 "" H 7350 2000 50  0001 C CNN
F 3 "~" H 7350 2000 50  0001 C CNN
	1    7350 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 3100 6300 3100
Wire Wire Line
	6300 3100 6300 2100
Wire Wire Line
	6300 2100 7150 2100
Wire Wire Line
	6100 1900 6100 2650
Wire Wire Line
	6100 2650 4800 2650
Wire Wire Line
	4800 2650 4800 3100
Wire Wire Line
	4800 3100 5150 3100
Connection ~ 6100 1900
Wire Wire Line
	6100 1900 7150 1900
Text Notes 6500 1600 0    50   ~ 0
Use short pin to\nselect operation mode
$Comp
L Connector:Conn_01x02_Male J4
U 1 1 5E57FD71
P 7750 1950
F 0 "J4" H 7858 2131 50  0000 C CNN
F 1 "Conn_01x02_Male" H 7950 1300 50  0000 C CNN
F 2 "" H 7750 1950 50  0001 C CNN
F 3 "~" H 7750 1950 50  0001 C CNN
	1    7750 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 1950 8150 1950
Wire Wire Line
	8150 1950 8150 2050
Wire Wire Line
	8150 2050 7950 2050
Text Notes 7500 1700 0    50   ~ 0
Provide VCC=5V for 2-3 to AVR\nProvide VCC=3.3V for 3-4 to AVR\nVTG (sense) for open or \n         1-2 or 4-5 (AVR powered externally) 
$Comp
L Regulator_Linear:LF33_TO220 U1
U 1 1 5E56C1FF
P 5450 3100
F 0 "U1" H 5450 3342 50  0000 C CNN
F 1 "LDO 3.3V TO220" H 5450 3251 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 5450 3325 50  0001 C CIN
F 3 "" H 5450 3050 50  0001 C CNN
	1    5450 3100
	1    0    0    -1  
$EndComp
Text Notes 4750 3200 0    50   ~ 0
Really PIN#2
Text Notes 5700 3200 0    50   ~ 0
Really PIN#1
Text Notes 5500 3450 0    50   ~ 0
Really PIN#3
Wire Wire Line
	4400 4050 4550 4050
Wire Wire Line
	4400 2000 4400 4050
Text Notes 5650 4350 0    50   ~ 0
PIN2 is VTG or VCC\nPIN6 is GND\nBottom view of PCB\nConnect from back of PCB\nusing 2 inside corner pins
$EndSCHEMATC

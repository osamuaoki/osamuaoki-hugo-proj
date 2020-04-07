EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "LED Lantern 12V"
Date "2020-02-11"
Rev "0.1"
Comp "Osamu Aoki"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector:Barrel_Jack_Switch J1
U 1 1 5E398B39
P 2950 3550
F 0 "J1" H 3007 3867 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 3007 3776 50  0000 C CNN
F 2 "" H 3000 3510 50  0001 C CNN
F 3 "~" H 3000 3510 50  0001 C CNN
	1    2950 3550
	1    0    0    -1  
$EndComp
$Comp
L Device:Battery BT1
U 1 1 5E399557
P 3600 3350
F 0 "BT1" H 3708 3396 50  0000 L CNN
F 1 "Battery (12V)" H 3708 3305 50  0000 L CNN
F 2 "" V 3600 3410 50  0001 C CNN
F 3 "~" V 3600 3410 50  0001 C CNN
	1    3600 3350
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW1
U 1 1 5E39E464
P 4800 3150
F 0 "SW1" H 4800 3385 50  0000 C CNN
F 1 "SW_SPST" H 4800 3294 50  0000 C CNN
F 2 "" H 4800 3150 50  0001 C CNN
F 3 "" H 4800 3150 50  0001 C CNN
	1    4800 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_Dual_ACA D1
U 1 1 5E39F581
P 4800 4100
F 0 "D1" V 4846 3890 50  0000 R CNN
F 1 "LED_Dual_ACA" V 4755 3890 50  0000 R CNN
F 2 "" H 4800 4100 50  0001 C CNN
F 3 "~" H 4800 4100 50  0001 C CNN
	1    4800 4100
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5E3A0617
P 4700 3650
F 0 "R1" H 4550 3696 50  0000 C CNN
F 1 "1M" H 4550 3605 50  0000 C CNN
F 2 "" V 4630 3650 50  0001 C CNN
F 3 "~" H 4700 3650 50  0001 C CNN
	1    4700 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5E3A0D5D
P 4900 3650
F 0 "R2" H 4970 3696 50  0000 L CNN
F 1 "20K" H 4970 3605 50  0000 L CNN
F 2 "" V 4830 3650 50  0001 C CNN
F 3 "~" H 4900 3650 50  0001 C CNN
	1    4900 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_Series D3
U 1 1 5E3AFD5B
P 6450 4250
F 0 "D3" H 6450 4530 50  0000 C CNN
F 1 "LED_Series" H 6450 4439 50  0000 C CNN
F 2 "" H 6350 4250 50  0001 C CNN
F 3 "~" H 6350 4250 50  0001 C CNN
	1    6450 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D2
U 1 1 5E3B0549
P 6000 4250
F 0 "D2" H 6000 4530 50  0000 C CNN
F 1 "LED_Series" H 6000 4439 50  0000 C CNN
F 2 "" H 5900 4250 50  0001 C CNN
F 3 "~" H 5900 4250 50  0001 C CNN
	1    6000 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D4
U 1 1 5E3B054F
P 6950 4250
F 0 "D4" H 6950 4530 50  0000 C CNN
F 1 "LED_Series" H 6950 4439 50  0000 C CNN
F 2 "" H 6850 4250 50  0001 C CNN
F 3 "~" H 6850 4250 50  0001 C CNN
	1    6950 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D5
U 1 1 5E3B2131
P 7500 4250
F 0 "D5" H 7500 4530 50  0000 C CNN
F 1 "LED_Series" H 7500 4439 50  0000 C CNN
F 2 "" H 7400 4250 50  0001 C CNN
F 3 "~" H 7400 4250 50  0001 C CNN
	1    7500 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5E3E5189
P 6000 3850
F 0 "R3" H 6070 3896 50  0000 L CNN
F 1 "R" H 6070 3805 50  0000 L CNN
F 2 "" V 5930 3850 50  0001 C CNN
F 3 "~" H 6000 3850 50  0001 C CNN
	1    6000 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E3E62CB
P 6450 3850
F 0 "R4" H 6520 3896 50  0000 L CNN
F 1 "R" H 6520 3805 50  0000 L CNN
F 2 "" V 6380 3850 50  0001 C CNN
F 3 "~" H 6450 3850 50  0001 C CNN
	1    6450 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5E3E6695
P 6950 3850
F 0 "R5" H 7020 3896 50  0000 L CNN
F 1 "R" H 7020 3805 50  0000 L CNN
F 2 "" V 6880 3850 50  0001 C CNN
F 3 "~" H 6950 3850 50  0001 C CNN
	1    6950 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5E3E6749
P 7500 3850
F 0 "R6" H 7570 3896 50  0000 L CNN
F 1 "R" H 7570 3805 50  0000 L CNN
F 2 "" V 7430 3850 50  0001 C CNN
F 3 "~" H 7500 3850 50  0001 C CNN
	1    7500 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 3700 6950 3700
Wire Wire Line
	6950 3700 6450 3700
Connection ~ 6950 3700
Wire Wire Line
	6450 3700 6000 3700
Connection ~ 6450 3700
$Comp
L power:GNDPWR #PWR03
U 1 1 5E3EA009
P 6000 4500
F 0 "#PWR03" H 6000 4300 50  0001 C CNN
F 1 "GNDPWR" H 6004 4346 50  0000 C CNN
F 2 "" H 6000 4450 50  0001 C CNN
F 3 "" H 6000 4450 50  0001 C CNN
	1    6000 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR04
U 1 1 5E3EA88C
P 6450 4500
F 0 "#PWR04" H 6450 4300 50  0001 C CNN
F 1 "GNDPWR" H 6454 4346 50  0000 C CNN
F 2 "" H 6450 4450 50  0001 C CNN
F 3 "" H 6450 4450 50  0001 C CNN
	1    6450 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR05
U 1 1 5E3EACD4
P 6950 4500
F 0 "#PWR05" H 6950 4300 50  0001 C CNN
F 1 "GNDPWR" H 6954 4346 50  0000 C CNN
F 2 "" H 6950 4450 50  0001 C CNN
F 3 "" H 6950 4450 50  0001 C CNN
	1    6950 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR06
U 1 1 5E3EB21C
P 7500 4500
F 0 "#PWR06" H 7500 4300 50  0001 C CNN
F 1 "GNDPWR" H 7504 4346 50  0000 C CNN
F 2 "" H 7500 4450 50  0001 C CNN
F 3 "" H 7500 4450 50  0001 C CNN
	1    7500 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR02
U 1 1 5E3EB4C4
P 4800 4400
F 0 "#PWR02" H 4800 4200 50  0001 C CNN
F 1 "GNDPWR" H 4804 4246 50  0000 C CNN
F 2 "" H 4800 4350 50  0001 C CNN
F 3 "" H 4800 4350 50  0001 C CNN
	1    4800 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR01
U 1 1 5E3EC5CA
P 3250 3650
F 0 "#PWR01" H 3250 3450 50  0001 C CNN
F 1 "GNDPWR" H 3254 3496 50  0000 C CNN
F 2 "" H 3250 3600 50  0001 C CNN
F 3 "" H 3250 3600 50  0001 C CNN
	1    3250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 3550 3600 3550
Wire Wire Line
	3250 3450 3400 3450
Wire Wire Line
	3400 3450 3400 3150
Wire Wire Line
	3400 3150 3600 3150
Wire Wire Line
	3600 3150 4600 3150
Wire Wire Line
	4600 3100 4600 3150
Wire Wire Line
	4600 3500 4700 3500
Connection ~ 3600 3150
Connection ~ 4600 3150
Wire Wire Line
	5000 3150 5000 3500
Wire Wire Line
	5000 3500 4900 3500
Wire Wire Line
	6950 3150 6950 3700
Connection ~ 5000 3150
$Comp
L Device:LED_Series D7
U 1 1 5E405BB6
P 8550 4250
F 0 "D7" H 8550 4530 50  0000 C CNN
F 1 "LED_Series" H 8550 4439 50  0000 C CNN
F 2 "" H 8450 4250 50  0001 C CNN
F 3 "~" H 8450 4250 50  0001 C CNN
	1    8550 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D6
U 1 1 5E405BBC
P 8100 4250
F 0 "D6" H 8100 4530 50  0000 C CNN
F 1 "LED_Series" H 8100 4439 50  0000 C CNN
F 2 "" H 8000 4250 50  0001 C CNN
F 3 "~" H 8000 4250 50  0001 C CNN
	1    8100 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D8
U 1 1 5E405BC2
P 9050 4250
F 0 "D8" H 9050 4530 50  0000 C CNN
F 1 "LED_Series" H 9050 4439 50  0000 C CNN
F 2 "" H 8950 4250 50  0001 C CNN
F 3 "~" H 8950 4250 50  0001 C CNN
	1    9050 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED_Series D9
U 1 1 5E405BC8
P 9600 4250
F 0 "D9" H 9600 4530 50  0000 C CNN
F 1 "LED_Series" H 9600 4439 50  0000 C CNN
F 2 "" H 9500 4250 50  0001 C CNN
F 3 "~" H 9500 4250 50  0001 C CNN
	1    9600 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R7
U 1 1 5E405BCE
P 8100 3850
F 0 "R7" H 8170 3896 50  0000 L CNN
F 1 "R" H 8170 3805 50  0000 L CNN
F 2 "" V 8030 3850 50  0001 C CNN
F 3 "~" H 8100 3850 50  0001 C CNN
	1    8100 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R8
U 1 1 5E405BD4
P 8550 3850
F 0 "R8" H 8620 3896 50  0000 L CNN
F 1 "R" H 8620 3805 50  0000 L CNN
F 2 "" V 8480 3850 50  0001 C CNN
F 3 "~" H 8550 3850 50  0001 C CNN
	1    8550 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5E405BDA
P 9050 3850
F 0 "R9" H 9120 3896 50  0000 L CNN
F 1 "R" H 9120 3805 50  0000 L CNN
F 2 "" V 8980 3850 50  0001 C CNN
F 3 "~" H 9050 3850 50  0001 C CNN
	1    9050 3850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R10
U 1 1 5E405BE0
P 9600 3850
F 0 "R10" H 9670 3896 50  0000 L CNN
F 1 "R" H 9670 3805 50  0000 L CNN
F 2 "" V 9530 3850 50  0001 C CNN
F 3 "~" H 9600 3850 50  0001 C CNN
	1    9600 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 3700 9050 3700
Wire Wire Line
	9050 3700 8550 3700
Connection ~ 9050 3700
Wire Wire Line
	8550 3700 8100 3700
Connection ~ 8550 3700
$Comp
L power:GNDPWR #PWR07
U 1 1 5E405BEB
P 8100 4500
F 0 "#PWR07" H 8100 4300 50  0001 C CNN
F 1 "GNDPWR" H 8104 4346 50  0000 C CNN
F 2 "" H 8100 4450 50  0001 C CNN
F 3 "" H 8100 4450 50  0001 C CNN
	1    8100 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR08
U 1 1 5E405BF1
P 8550 4500
F 0 "#PWR08" H 8550 4300 50  0001 C CNN
F 1 "GNDPWR" H 8554 4346 50  0000 C CNN
F 2 "" H 8550 4450 50  0001 C CNN
F 3 "" H 8550 4450 50  0001 C CNN
	1    8550 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR09
U 1 1 5E405BF7
P 9050 4500
F 0 "#PWR09" H 9050 4300 50  0001 C CNN
F 1 "GNDPWR" H 9054 4346 50  0000 C CNN
F 2 "" H 9050 4450 50  0001 C CNN
F 3 "" H 9050 4450 50  0001 C CNN
	1    9050 4500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR010
U 1 1 5E405BFD
P 9600 4500
F 0 "#PWR010" H 9600 4300 50  0001 C CNN
F 1 "GNDPWR" H 9604 4346 50  0000 C CNN
F 2 "" H 9600 4450 50  0001 C CNN
F 3 "" H 9600 4450 50  0001 C CNN
	1    9600 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 3150 9050 3700
Wire Wire Line
	5000 3150 6950 3150
Connection ~ 6950 3150
Wire Wire Line
	6950 3150 9050 3150
Text Notes 4500 4300 0    50   ~ 0
BLUE
Text Notes 5000 4300 0    50   ~ 0
RED
Wire Wire Line
	4600 3150 4600 3500
$EndSCHEMATC

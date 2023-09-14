*** Settings ***
Library     tenma_72_2710.py
Library     Process
Library     String

*** Variables ***

${PORT_NAME}	/dev/serial/by-id/usb-Nuvoton_USB_Virtual_COM_E6614C311B888B35-if00
${MODEL}	VERSION ==> TENMA 72-2710 V6.8 SN:03265065
${ON}		True
${OFF}		False
${A}		1.5
${mA}		1500
${V}		6.5
${mV}		6500

*** Test Cases ***

Test model version
	# run this process tenma-control/tenma_72_2710.py -v ${PORT_NAME}, and store the print output in result
	${result} =	Run Process	python3	tenma_72_2710.py	-v	${PORT_NAME}
	# Get substring is used to ignore the last character, which is '\n' in this case 
	${result1} =	Get Substring	 ${result.stdout}   0	-1
	Should Be Equal	${result1}	${MODEL}
	
Disable output
	Run Process	python3	tenma_72_2710.py	--off	${PORT_NAME}
	${result} =	Run Process	python3	tenma_72_2710.py	-s	${PORT_NAME}
	Should Be Equal	${result.stdout}	${OFF}
	
Enable output
	Run Process	python3	tenma_72_2710.py	--on	${PORT_NAME}
	${result} =	Run Process	python3	tenma_72_2710.py	-s	${PORT_NAME}
	Should Be Equal	${result.stdout}	${ON}

Set current
	Run Process	python3	tenma_72_2710.py	-sc	${mA}	${PORT_NAME}
	${result} =	Run Process	python3	tenma_72_2710.py	-gc	${PORT_NAME}
	Should Be Equal	${result.stdout}	${A}
	
Set Voltage
	Run Process	python3	tenma_72_2710.py	-sv	${mV}	${PORT_NAME}
	${result} =	Run Process	python3	tenma_72_2710.py	-gv	${PORT_NAME}
	Should Be Equal	${result.stdout}	${V}


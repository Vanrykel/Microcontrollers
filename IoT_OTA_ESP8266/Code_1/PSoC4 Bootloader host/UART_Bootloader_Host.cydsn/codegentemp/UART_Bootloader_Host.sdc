# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\guido\Desktop\AN68272_2\UART Bootloader Host\UART_Bootloader_Host.cydsn\UART_Bootloader_Host.cyprj
# Date: Thu, 16 Nov 2017 14:57:26 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 53 105} -nominal_period 2166.6666666666665 [list [get_pins {ClockBlock/udb_div_0}]]


# Component constraints for C:\Users\guido\Desktop\AN68272_2\UART Bootloader Host\UART_Bootloader_Host.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\guido\Desktop\AN68272_2\UART Bootloader Host\UART_Bootloader_Host.cydsn\UART_Bootloader_Host.cyprj
# Date: Thu, 16 Nov 2017 14:57:24 GMT
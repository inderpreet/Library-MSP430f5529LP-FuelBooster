################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
USB_API/USB_CDC_API/UsbCdc.obj: E:/Inderpreet/Sandbox/MSP430_CC/Design/CCS5/simpleUsbBackchannel/USB_API/USB_CDC_API/UsbCdc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv5/tools/compiler/msp430_4.2.1/bin/cl430" -vmspx --abi=eabi -Ooff -g --include_path="C:/ti/ccsv5/ccs_base/msp430/include" --include_path="E:/Inderpreet/Sandbox/MSP430_CC/Design/CCS5/simpleUsbBackchannel" --include_path="E:/Inderpreet/Sandbox/MSP430_CC/Design/CCS5/simpleUsbBackchannel/driverlib/MSP430F5xx_6xx" --include_path="E:/Inderpreet/Sandbox/MSP430_CC/Design/CCS5/simpleUsbBackchannel/USB_config" --include_path="C:/ti/ccsv5/tools/compiler/msp430_4.2.1/include" --advice:power=all --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --preproc_with_compile --preproc_dependency="USB_API/USB_CDC_API/UsbCdc.pp" --obj_directory="USB_API/USB_CDC_API" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



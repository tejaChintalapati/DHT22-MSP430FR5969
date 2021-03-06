################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Source/DHT22.obj: ../Source/DHT22.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/DHT22.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/WDTInitialisation.obj: ../Source/WDTInitialisation.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/WDTInitialisation.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/clockInitialisation.obj: ../Source/clockInitialisation.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/clockInitialisation.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/mainApp.obj: ../Source/mainApp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/mainApp.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/pinInitialisation.obj: ../Source/pinInitialisation.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/pinInitialisation.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/portInitialisation.obj: ../Source/portInitialisation.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/portInitialisation.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Source/timerInitialisation.obj: ../Source/timerInitialisation.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/bin/cl430" -vmspx --abi=eabi --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/CCS/DHT22_LPM/driverlib/MSP430FR5xx_6xx" --include_path="D:/CCS/DHT22_LPM/Source" --include_path="C:/ti/msp430/MSPWare_2_40_00_37/iqmathlib/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-msp430_4.4.6/include" --advice:power="1,2,3,5,6,7,8,9,10,11,12,13,14" --advice:hw_config=all -g --define=__MSP430FR5969__ --define=_MPU_ENABLE --display_error_number --diag_wrap=off --diag_warning=225 --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --printf_support=full --preproc_with_compile --preproc_dependency="Source/timerInitialisation.pp" --obj_directory="Source" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



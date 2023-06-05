# 初试STM32Cube

## CMSIS/Device/

固件包/Drivers/CMSIS/Device/ST/STM32f1xx/Include/stm32f1xx.h：所有F1系列顶层头文件，通过条件编译包含某个芯片头文件，定义通用枚举类型，定义通用宏定义。

固件包/Drivers/CMSIS/Device/ST/STM32f1xx/Include/stm32f103xe.h：包含中断编号定义（枚举），芯片外设的地址映射和数据结构，外设寄存器声明和位定义，访问外设寄存器的宏定义。

固件包/Drivers/CMSIS/Device/ST/STM32f1xx/Include/system_stm32f103xe.h：定义系统初始化函数，系统始终更新函数。

固件包/Drivers/CMSIS/Device/ST/STM32f1xx/Source/Templates/arm/startup_stm32f103xe.s：启动文件。

## CMSIS/Include/

固件包/Drivers/CMSIS/Include/：
- cmsis_armcc.h：AC5编译器用
- cmsis_armclang.h：AC6编译器用
- cmsis_compiler.h：上两个编译器共用
- cmsis_version.h：版本
- core_cm3.h：M系列芯片用到
- mpu_armv7.h：内存保护


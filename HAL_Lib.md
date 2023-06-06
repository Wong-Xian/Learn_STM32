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

## HAL库框架结构 STM32Cube/Drivers/STM32F1xx_HAL_Driver/

- HAL 库文件夹结构
  - Inc .h
  - Src .c
- HAL 库文件介绍
  - hal.h：HAL库初始化、系统滴答、HAL 库延时等函数。
  - hal_conf.h：HAL 库用户配置文件，用于裁剪 HAL 库、配置晶振参数等。
  - hal_cortex.h：内核通用函数定义和声明，是对 core_cm3.h 文件中函数的再次封装。
  - hal_xxx.h 和 hal_xxx_ex.h：某外设的驱动源码、扩展（特殊）功能的驱动源码。
  - ll_ppp.h：LL库驱动源码。
- API 函数和变量命名规则

## 如何使用 HAL 库

### 4.1 基于 CMSIS 应用程序文件描述

CMSIS 文件夹下 Device 和 Include 文件夹下共11个文件。均为必须文件。

设备驱动层，HAL 库和 LL 库。对于要用到的外设，均为必须文件。

用户程序文件，main 文件，芯片初始化文件，HAL 库初始化文件。非必须。

### 4.2 HAL 库的用户配置文件

- 裁剪 HAL 库外设驱动源码

在 stm32f1xx_hal_conf.h 文件中屏蔽对应的宏，使得对应外设文件不参与编译。

- 设置外部高速晶振频率

在 stm32f1xx_hal_conf.h 文件中修改 HSE_VALUE 的值。

内部高速晶振是 HSI_VALUE。

- 设置外部低速晶振频率

在 stm32f1xx_hal_conf.h 文件中修改 LSE_VALUE 的值。


### 4.3 stm32f1xx_hal.c 文件

最关心： HAL_init 函数
# Africa's Talking Eris v1 Dev Kit HC-SR04 Sample

## TLDR; 

> To get **up and running quickly** with this sample, follow the steps below:

1. Hook the HC-SR04 Sensor to `PB10` {`trigger`} and `PB11` {`echo`} pins on the board

2. Flash `./Dist/ultrasonic.bin` in to your dev kit. 

3. Open Serial to view data


> For a detailed write up, read below

## Pinout Configuration

- See overrall config as shown below 
![PinoutConfig](Static/ConfigOverview.png) 

- Set `PB10` to `GPIOOutput` as shown
![GPIOTriggerPinConfig](Static/GPIOOutputConfig.png)

- Set `PB11` to `GPIOInput` as shown
![GPIOEchoPinConfig](Static/GPIOInputConfig.png)

- Set `HSE` to `Crystal/Ceramic Resonator` and **disable** `LSE` as shown
![ClockConfig](Static/ClockConfig.png) 

- Under timer config set `Clock Source` to `Internal Clock` for `TIM1`.
- Set prescaler value to `72 - 1` and ARR to `0xffff - 1`.
![TimerConfig](Static/TimerConfig.png) 

- Set serial mode to `Asynchronous` for both  `USART1` and `USART2` and **ensure `gloabl interrupt` is enabled under `NVIC Settings`** 
![UARTConfig](Static/UARTConfig.png) 

## Clock Configuration 
- See below clock configuration.
    - Toggle `PLL` and `PLLCLK`
    - Set input frequency to `8Mhz`

- You might want to set the multiplier `PLLMul` to **11 or above** then click `Resolve Clock Issues` 
![SysClockConfig](Static/SysClockConfig.png)

## Project Management 
- Under Project Manager ensure `Generate peripheral initialization...` is checked 
![CodeGenerationConfig](Static/ProjectMgrConfigCodeGen.png) 

- Then inside `Advanced Settings` Set USART driver to `LL`  
![USARTDriverConfig](Static/ProjectMrgUSARTDriverConfig.png)


**SAVE AND GENERATE PROJECT**

## Library Config

- Inside `./Core/Inc/main.h` ensure you have the following under `Private defines` .

```c 
#define TRIGGER_PIN GPIO_PIN_10  

#define TRIGGER_PORT GPIOB 

#define ECHO_PIN GPIO_PIN_11 

#define ECHO_PORT GPIOB
```

## Important Others 

- Note that the line shown below is commented under `./Core/Src/syscalls.c` 

```c 
extern int __io_putchar(int ch) __attribute__((weak)); 
``` 

- Also note that an IRQ handler is required for USART1; see `./Core/Src/stm32f1xx_it.c`.

- Note the **differences** under `./Core/{*}/usart.{*}` 

- Note **custom implementation of µSeconds delay** inside `./Core/{*}/main.{*}` 
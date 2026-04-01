#ifndef DEVICE_NAME
#define DEVICE_NAME "ELRS 2400RX DD"
#endif

// This requires the inductor to be fitted to the SX1280, see datasheet.
#define USE_HARDWARE_DCDC

// Pins ordered by physical layout of UFQFN32, do not re-order.

// PA0, PA1, PA2, PA3 = flexible.
// PA0 = ADC1 IN5, TIM2_CH1
// PA1 = ADC1 IN6, TIM2_CH2
#define GPIO_PIN_RX_ENABLE          PA0
#define GPIO_PIN_RX_ENABLE_2        PA1

// PA2 = ADC1 IN7, TIM2_CH3, UART2_RX
// PA3 = ADC1 IN8, TIM2_CH4, UART2_TX
//#define GPIO_PIN_DEBUG_RX           PA3
//#define GPIO_PIN_DEBUG_TX           PA2

#define GPIO_PIN_NSS                PA4

#define GPIO_PIN_SCK                PA5
#define GPIO_PIN_MISO               PA6
#define GPIO_PIN_MOSI               PA7

// EXTI0
#define GPIO_PIN_DIO1               PB0
// EXTI1
#define GPIO_PIN_DIO1_2             PB1

// Use PA8 for RGBLED or PA enable

//#define GPIO_PIN_LED_WS2812         PA8
//#define GPIO_PIN_LED_WS2812_FAST    PA_8
#define GPIO_PIN_PA_ENABLE          PA8

// UART1 on default pins
#define GPIO_PIN_RCSIGNAL_TX        PA9
#define GPIO_PIN_RCSIGNAL_RX        PA10

#define SERIAL_UART_INSTANCE        1
#define PIN_SERIAL_RX               PA9
#define PIN_SERIAL_TX               PA10

// PA11 + PA12 can be used for FDCAN or USB
// PA13 + PA14 + PB3 for SWDIO, SWCLK, SWO

// NucleoL432 has a RED LED on PB3, which is also SWO
#define GPIO_PIN_LED_RED            PB3

// On the NucleoL432 this involves removing SB2 and soldering a wire to the pad that connects to the L4 MCU
// as it is not available on a header pin or connector.
#define GPIO_PIN_NSS_2              PA15

// Using seperate RST signals to avoid a known issue when the NRESET signals of two SX1280 are connected to each other.
// To free a pin if needed a 1k + 100nf LC filter can be put in front of each of the SX1280's NRESET pins and then the 
// RST net should contain the L432 + 1k + 1k
#define GPIO_PIN_RST                PB4
#define GPIO_PIN_RST_2              PB5

// Use a single-pin per PA, check truth table of PA - RFX2401C Control Logic is suitable if RXEN has a pull-up.
// NOTE: On the NucleoL432 SB16 and SB18 must be removed to use these pins!
// or could use PB6 and PB7 as I2C SCL/SDA (respectively) when not using a Power Amplifiers
#define GPIO_PIN_TX_ENABLE          PB6
#define GPIO_PIN_TX_ENABLE_2        PB7

// PH3 can be used for a button, but there's compilation errors currently.
//#define GPIO_PIN_BUTTON             PH3

// EXTI14 (NucleoL432 D8 with SB6 installed, SB5 removed, SB4 removed)
#define GPIO_PIN_BUSY_2             PC14
// EXTI15 (NucleoL432 D7 with SB8 installed, SB7 removed)
#define GPIO_PIN_BUSY               PC15

// Output Power - use default SX1280
#define POWER_OUTPUT_FIXED          13 //MAX power for 2400 RXes that doesn't have PA is 12.5dbm

#pragma once

#include <stdint.h>

#define D0	(uint8_t)(44)
#define D1	(uint8_t)(43)
#define D2	(uint8_t)(42)
#define D3	(uint8_t)(41)
#define D4	(uint8_t)(40)
#define D5	(uint8_t)(39)
#define D6	(uint8_t)(38)
#define D7	(uint8_t)(37)
#define D8	(uint8_t)(36)
#define D9	(uint8_t)(26)
#define D10	(uint8_t)(21)
#define D11	(uint8_t)(18)
#define D12	(uint8_t)(17)
#define D13	(uint8_t)(0)
#define D14	(uint8_t)(35)
#define D15	(uint8_t)(34)
#define D16	(uint8_t)(33)

#define A0	(uint8_t)(8)
#define A1	(uint8_t)(9)
#define A2	(uint8_t)(10)
#define A3	(uint8_t)(11)
#define A4	(uint8_t)(12)
#define A5	(uint8_t)(13)
#define A6	(uint8_t)(16)

#define SD	D8
#define SC	D7

#define MO	D4
#define MI	D5
#define MC	D6
#define SS	D10

#define TX	D0
#define RX	D1

#define P0	D2
#define P1	D3

#define T0	A0
#define T1	A1
#define T2	A2
#define T3	A3
#define T4	A4
#define T5	A5

#define LEDR	(uint8_t)(34)
#define LEDG	(uint8_t)(33)
#define LEDB	(uint8_t)(35)
#define GPKEY	(uint8_t)(0)
#define BT	(uint8_t)(0)

#define EXTERNAL_NUM_INTERRUPTS 46
#define NUM_DIGITAL_PINS        48
#define NUM_ANALOG_INPUTS       20

#define analogInputToDigitalPin(p)  (((p)<20)?(esp32_adc2gpio[(p)]):-1)
#define digitalPinToInterrupt(p)    (((p)<48)?(p):-1)
#define digitalPinHasPWM(p)         (p < 46)
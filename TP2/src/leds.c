/************************************************************************************************
Copyright (c) 2025, Agustin Jesus Vazquez <vazqueza193@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file leds.c
 ** @brief Definición de la biblioteca para el control de LEDs
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */
/** @brief Mascara para apagar todos los LEDs */
#define ALL_LEDS_OFF 0x0000
/** @brief Mascara para prender todos los LEDs */
#define ALL_LEDS_ON 0xFFFF
/** @brief Diferencia entre el numero de led y el numero de bit */
#define LEDS_TO_BIT_OFFSET 1
/** @brief Constante con el primer bit en uno para generar una mascara */
#define LED_ON 1
/** @brief Constante que representa el primer led */
#define FIRST_LED 1
/** @brief Constante que representa el ultimo led */
#define LAST_LED 16

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
/** @brief Variable privada para almacenar la direccion del puerto de salida */
static uint16_t* port_address;
/* === Private function declarations =========================================================== */
/**
 * @brief Funcion privada para convertir el numero de un led en una mascara de bits
 *
 * @param led Numero de led para el que se desea generar la mascara de bits
 * @return uint16_t Mascara de bits con 1 en la posicion correspondiente al led
 */
static uint16_t LedToMask(uint8_t led);

/**
 * @brief Funcion privada para verificar los limites de los leds
 *
 * @param led Numero de led a verificar
 * @return bool Devuelve TRUE cuando el led supera uno de los limites y FALSE en caso de que este en
 * el rango
 */
static bool IsLedOutOfBound(uint8_t led);
/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
static uint16_t LedToMask(uint8_t led)
{
  return (LED_ON << (led - LEDS_TO_BIT_OFFSET));
}
/* === Public function implementation ========================================================== */

// @test Con la inicializacion todos los LEDs quedan apagados
void LedsInit(uint16_t* direccion)
{
  port_address = direccion;
  turnOffAllLeds();
}

bool IsLedOutOfBound(uint8_t led)
{
  return (led < FIRST_LED || led > LAST_LED);
}

void LedsTurnOnSingle(uint8_t led)
{
  if(IsLedOutOfBound(led))
  {
    return;
  }
  *port_address |= LedToMask(led);
}

void LedsTurnOffSingle(uint8_t led)
{
  if(IsLedOutOfBound(led))
  {
    return;
  }
  *port_address &= ~LedToMask(led);
}

void turnOnAllLeds()
{
  *port_address = ALL_LEDS_ON;
}

void turnOffAllLeds()
{
  *port_address = ALL_LEDS_OFF;
}

bool isLedOn(uint8_t led)
{
  if(IsLedOutOfBound(led))
  {
    return false;
  }
  return (*port_address & LedToMask(led)) != 0;
}

bool isLedOff(uint8_t led)
{
  return !isLedOn(led);
}

/* === End of documentation ==================================================================== */

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

#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Declaración de la biblioteca para el control de LEDs
 **/

/* === Headers files inclusions ================================================================ */

#include <stdbool.h>
#include <stdint.h>

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C"
{
#endif

  /* === Public macros definitions ===============================================================
   */

  /* === Public data type declarations ===========================================================
   */

  /* === Public variable declarations ============================================================
   */

  /* === Public function declarations ============================================================
   */

  /**
   * @brief Función para inicializar
   *
   * @return int Valor de retorno, cero si esta todo bien, negativo si hay un error
   */
  void LedsInit(uint16_t* direccion);

  /**
   * @brief Función para encender un led especifico
   *
   * @param led numero de led a encender. Rango de 1 a 16.
   * @return void
   */
  void LedsTurnOnSingle(uint8_t led);

  /**
   * @brief Función para apagar un led especifico
   *
   * @param led numero de led a encender. Rango de 1 a 16.
   * @return void
   */
  void LedsTurnOffSingle(uint8_t led);

  /**
   * @brief Función para prender todos leds
   *
   * @param void
   * @return void
   */
  void turnOnAllLeds();

  /**
   * @brief Función para apagar todos leds
   *
   * @param void
   * @return void
   */
  void turnOffAllLeds();

  /**
   * @brief Función para verificar el estado de un led encendido
   *
   * @param led Numero de led a verificar. Rango de 1 a 16.
   * @return bool Devuelve TRUE cuando esta encendido y FALSE cuando esta apagado
   */
  bool isLedOn(uint8_t led);

  /**
   * @brief Función para verificar el estado de un led apagado
   *
   * @param led Numero de led a verificar. Rango de 1 a 16.
   * @return bool Devuelve TRUE cuando esta encendido y FALSE cuando esta apagado
   */
  bool isLedOff(uint8_t led);

  /* === End of documentation ====================================================================
   */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */

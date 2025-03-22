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

/** @file test_leds.c
 ** @brief Pruebas unitarias de la biblioteca de
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"
#include "unity.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */
static uint16_t ledsVirtuales;
/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

// @test Con la inicializacion todos los LEDs quedan apagados
void setUp()
{
  LedsInit(&ledsVirtuales);
}

// @test Con la inicialización todos los LEDs quedan apagados
void test_todos_los_leds_inician_apagados(void)
{
  uint16_t ledsVirtuales = 0xFFFF;

  LedsInit(&ledsVirtuales);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// @test Prender un led individual
void test_prender_led_individual(void)
{
  LedsTurnOnSingle(4);
  TEST_ASSERT_EQUAL_HEX16(0x0008, ledsVirtuales);
}

// @test Apagar un led individual
void test_apagar_led_individual(void)
{
  LedsTurnOnSingle(4);
  LedsTurnOffSingle(4);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// @test Prender y apagar multiples leds
void test_prender_y_apagar_algunos_leds(void)
{
  LedsTurnOnSingle(4);
  LedsTurnOnSingle(6);
  LedsTurnOffSingle(4);
  LedsTurnOffSingle(8);
  TEST_ASSERT_EQUAL_HEX16(0x0020, ledsVirtuales);
}

// @test Prender todos los LEDs de una vez
void test_prender_todos_los_leds_de_una_vez(void)
{
  turnOnAllLeds();
  TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

// @test Apagar todos los LEDs de una vez
void test_apagar_todos_los_leds_de_una_vez(void)
{
  turnOnAllLeds();
  turnOffAllLeds();
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

// @test Consultar el estado de un LED que esta encendido
void test_consultar_el_estado_de_un_led_encendido(void)
{
  LedsTurnOnSingle(4);
  TEST_ASSERT_EQUAL(true, isLedOn(4));
}

// @test Consultar el estado de un LED que esta apagado
void test_consultar_el_estado_de_un_led_apagado(void)
{
  LedsTurnOnSingle(4);
  LedsTurnOffSingle(4);
  TEST_ASSERT_EQUAL(true, isLedOff(4));
}

/*------------------------------------------------------*/

// @test Revisar limite inferior de los parametros
void test_revisar_limite_inferior(void)
{
  LedsTurnOnSingle(1);
  TEST_ASSERT_EQUAL_HEX16(0x0001, ledsVirtuales);
}

// @test Revisar limite superior de los parametros
void test_revisar_limite_superior(void)
{
  LedsTurnOnSingle(16);
  TEST_ASSERT_EQUAL_HEX16(0x8000, ledsVirtuales);
}

/*------------------------------------------------------*/

// @test Revisar parametros fuera de los limites
void test_revisar_fuera_limite_inferior(void)
{
  LedsTurnOnSingle(-1);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
  LedsTurnOnSingle(0);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
  LedsTurnOnSingle(17);
  TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

/* === End of documentation ==================================================================== */

/************************************************************************************************
Copyright (c) 2023, Esteban Volentini <evolentini@herrera.unt.edu.ar>

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

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

// @test Con la inicializacion todos los LEDs quedan apagados
void test_todos_los_leds_inician_apagados(void) {

    uint16_t leds_virtuales = 0xFFFF;

    LedsInit(&leds_virtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuales);

}

// @test Prender un led individual

void test_prender_led_individual(void) {

    uint16_t leds_virtuales = 0xFFFF;

    LedsInit(&leds_virtuales);
    LedsTurnOnSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuales);

}

// @test Apagar un led individual

void test_apagar_led_individual(void) {

    uint16_t leds_virtuales = 0xFFFF;

    LedsInit(&leds_virtuales);
    LedsTurnOnSingle(4);
    LedsTurnOffSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuales);

}

// @test Prender y apagar multiples leds

void test_prender_y_apagar_algunos_leds(void) {

    uint16_t leds_virtuales = 0xFFFF;

    LedsInit(&leds_virtuales);
    LedsTurnOnSingle(4);
    LedsTurnOnSingle(6);

    LedsTurnOffSingle(4);
    LedsTurnOffSingle(8);
    
    TEST_ASSERT_EQUAL_HEX16(0x0010, leds_virtuales);

}

/* === End of documentation ==================================================================== */
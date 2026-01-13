/* Copyright 2024 RarePotato8DE
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once


// ENCODER
#define ENCODER_A_PINS { GP29 }
#define ENCODER_B_PINS { GP28 }
#define ENCODER_RESOLUTION 4

// OLED - SIMPLES
#define OLED_DISPLAY_128X64
#define OLED_DRIVER SSD1306
#define I2C1_SCL_PIN GP27
#define I2C1_SDA_PIN GP26
#define OLED_TIMEOUT 0

// DEBOUNCE
#define DEBOUNCE 5

#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#define VIAL_KEYBOARD_UID {0x38, 0x9A, 0xC4, 0x78, 0xC1, 0x20, 0x60, 0x62}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }



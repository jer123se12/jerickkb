/*
Copyright 2021 Zach White

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Jerick
#define PRODUCT         minikb
#define DESCRIPTION     "Jerick's super tiny kb"

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 10

/* key matrix pins */
#define MATRIX_ROW_PINS { E6, D7, D0, D4 }
#define MATRIX_COL_PINS {F4,F5,F6,F7,B1,B3,B2,B6,B5,B4}  
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
#define QMK_KEYS_PER_SCAN 40
#define USB_POLLING_INTERVAL_MS 1
#define FORCE_NKRO
#define AUDIO_PIN C6
#define RGB_DI_PIN D3
#define RGBLED_NUM 0
#define RGBLIGHT_DEFAULT_SAT 12

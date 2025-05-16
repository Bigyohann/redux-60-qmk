/*
Copyright 2025 YANG

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

#include <avr/io.h>
#include "quantum.h"
#include "via.h"

#include "ec_matrix.h"
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    if (*command_id == 0xFD) {
        if (data[1] == 0xA3) { //get matrix adc and key
            /* FD 03 00 xx xx xx xx xx ... xx xx xx xx xx yy yy ...
               FD 03 10 xx xx xx xx xx ... xx xx xx xx xx yy yy ...
               ...
               FD 03 40 xx xx xx xx xx ... xx xx xx xx xx yy yy ...
               */
            static uint8_t row = 0;
            //send one row a time
            {
                data[2] = (row<<4);
                for (uint8_t col=0; col<MATRIX_COLS;col++) {
                    data[3+col] = ec_key_value[row][col];
                }
                //matrix[row] 从末尾开始，31是低位，30是高位，如果大于16位，就继续写到29
                data[31] = matrix_get_row(row);
                data[30] = matrix_get_row(row)>>8;
            }
            if (++row >= MATRIX_ROWS) row = 0;
        }
    }
}

//after set layout command
void via_set_layout_options_after(void)
{
    //layout 选项里有用来存储配置的。
    user_config_init();
}


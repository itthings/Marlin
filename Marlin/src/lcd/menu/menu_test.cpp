/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

//
// LED Menu
//

#include "../../inc/MarlinConfigPre.h"
#include "../../feature/leds/leds.h"
#if BOTH(HAS_LCD_MENU, TEST_FEATURE)

#include "menu_item.h"


#ifdef USER_SCRIPT_DONE
  #define _DONE_SCRIPT "\n" USER_SCRIPT_DONE
#else
  #define _DONE_SCRIPT ""
#endif




   static void _calibrate() {
    PGM_P cal = PSTR("M190 40\nG28\nG33\nG28\nG29 P1\nG29 P3\nG29 F 10.0 \nG29 S0\nG29 A\nM500");
    //PGM_P home = PSTR("G28");
    //PGM_P d_cal = PSTR("G33 V3");
    //PGM_P level = PSTR("G29 P0 V4\nG29 P1 V4\nG29 P3 V4\nG29 S1 V4\nG29 T0 V4\nG29 T1 V4\nG29 A\nG29 F 10.0");
    //PGM_P fin_msg = PSTR("M117 Caibration Complete\nM118 A1 action:Calibration complete, stow probe.");
    //PGM_P save_eeprom_ = PSTR("M500");

    leds.set_red();

   // const screenFunc_t prev_screen = ui.currentScreen;
         // LCD_MESSAGEPGM(MSG_MANUAL_DEPLOY_TOUCHMI);
          //ui.return_to_status();

          //TERN_(HOST_PROMPT_SUPPORT, host_prompt_do(PROMPT_USER_CONTINUE, PSTR("Deploy TouchMI"), CONTINUE_STR));
          //wa/it_for_user_response();
          //ui.reset_status();
          //ui.goto_screen(prev_screen);

    //tidy this mess up, I'm sure theres a better way..
    //queue.process_subcommands_now_P(home);
    //queue.process_subcommands_now_P(d_cal);
    //queue.process_subcommands_now_P(level);
    //queue.process_subcommands_now_P(save_eeprom_);
    //queue.process_subcommands_now_P(fin_msg);
    queue.inject_P(cal);
    leds.set_green();
    
  }
 void menu_test() {

      START_MENU();
      PGM_P const msg = GET_TEXT(MSG_CALIBRATE);
      BACK_ITEM(MSG_TEST);
      //SUBMENU_P(msg, []{ _menu_temp_filament_op(PAUSE_MODE_CHANGE_FILAMENT, 0); });

      ACTION_ITEM(MSG_CALIBRATE, _calibrate);

      END_MENU();
    }
#endif // HAS_LCD_MENU && LED_CONTROL_MENU

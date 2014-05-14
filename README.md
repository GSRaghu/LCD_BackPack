LCD_BackPack
============
Command for lcd back pack  v1
Note: the symbol ‘_’ [under score] in the following command are space. ’c’ for column and ‘r’ for row.
To clear the screen:$_clear_/n
Example : Serial.println(“$ clear /n”);

For setting the cursor at first row and first column is :$_home_/n
Example : Serial.println(“$ home /n”);

To set the cursor at required position:$_set_cursor_c,r_/n
Example :Serial.print(“$ set cursor 0,1 /n”);
Means set the cursor position to 0th column i.e,first column and second row in the display.
To access 11th column type ‘a’ or ‘A’ and so on,
Example :Serial.print(“$ set cursor a,1 /n”);//11th coloumn and second row
                 Serial.print(“$ set cursor A,1 /n”);//11th coloumn and second row
                 Serial.print(“$ set cursor f,0 /n”);//16th coloumn and first row.
To print characters on display:$_print_16 character of user_/n
Example : Serial.println(“$ print hi hello world /n”);

To display cursor on screen:$_cursor_on_/n
Example : Serial.println(“$ cursor on /n”);

To hide cursor:$_nocursor_/n
Example : Serial.println(“$ nocursor /n”);

For blinking the cursor position:$_blink_/n
Example : Serial.println(“$ blink /n”);

No cursor blinking :$_noblink_/n
Example : Serial.println(“$ noblink /n”);

To hide the character on the screen:$_nodisplay_/n
Example : Serial.println(“$ nodisplay /n”);

To restore the character on to screen after nodisplay command:$_display_on_/n
Example : Serial.println(“$ display on /n”);


For scrolling the display left:$_sdl_scroll_display_left_/n
Example : Serial.println(“$ sdl scroll display left  /n”);
Or  
Serial.println(“$ sdl /n”);

For scrolling the display right:$_sdr_scroll_display_right_/n
Example : Serial.println(“$ sdr scroll display right /n”);
Or 
Serial.println(“$ sdr /n”);

For setting the direction of the character entering in to the lcd:
Left  to right:$_ltr_left_to_right_/n
Example : Serial.println(“$ ltr left to right /n”);
Or 
 Serial.println(“$ ltr /n”);


Right to left:$_rtl_right_to_left_/n
Example : Serial.println(“$ rtl right to left /n”);
Or 
 Serial.println(“$ rtl /n”);


For setting the baud rate:$_baud_rate_1200_/n
                                             :$_baud_rate_2400_/n 
                                             :$_baud_rate_4800_/n
                                             :$_baud_rate_9600_/n
Example : Serial.println(“$ baud rate 9600 /n”);//default baud rate is 9600bps


For turning  the auto scroll on:$_auto_scroll_/n
Example : Serial.println(“$ auto scroll /n”);


For turning the auto scroll off:$_noauto_scroll_/n
Example : Serial.println(“$ noauto scroll /n”);

Command for turning on the led backlight:$_back_light_on_/n
Example : Serial.println(“$ back light on /n”);

Command for turning off the led backlight:$_back_light_off_/n
Example : Serial.println(“$ back light off /n”);

Command for sending variable 
Example : int x=10;
          Serial.print("$ num ");
          Serial.print(x);
          Serial.print("/n");



# AVR-LCD-4-bit
AVR program to interface LCD in 4 bit mode

LCD 4 bit :
- To initialize character lcd in 4 bit mode we send value hex 0x20 to command register of lcd.
- 0x20 tells the lcd controller that we want to communicate in 4-bit mode. 
- If our character lcd has 2 rows we will send 0x28 instead of 0x20. 
- 0x20 tells the lcd controller that we want 4 bit communication and character size is between 5×7 dot matrix.
- 4-bit mode make use of only just four data pins D4-D5-D6-D7.
- In 4-bit mode character is displayed on lcd in two pulse signals.
- First the higher four nibbles of a character are sent to the lcd with an enable stroke.
- Than the lower four nibbles are send with enable stroke.

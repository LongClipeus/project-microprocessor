/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "Keypad.h"
#include "LedMatrix.h"

void ScanMatrixKeypad(char *StringSend, int length) {
	int Count_1 = 0x00, Count_2 = 0x00;
	char CapsLock = 0x00, Digital = 0x00;
	while(Count_1 < length) {
		for(for_i = 0; for_i < 3; ++for_i) {
			if(for_i == 0x0) {						/*Keypad_1, _2, _3 ==> 0 1 0 ==> quét cột Keypad_2*/
				PORTDbits.RD0 ^= 1;	
				PORTDbits.RD1 ^= 1;	
			}
		    else if(for_i == 0x1) {					/*Keypad_1, _2, _3 ==> 0 0 1 ==> quét cột Keypad_3*/
		    	PORTDbits.RD1 ^= 1;	
		    	PORTDbits.RD2 ^= 1;	
		    }
			else {									/*Keypad_1, _2, _3 ==> 1 0 0 ==> quét cột Keypad_1*/
		    	PORTDbits.RD0 ^= 1;	
		    	PORTDbits.RD2 ^= 1;	
		    }
		    
		    if(PORTDbits.RD3 == 1) {				/*Quét hàng Keypad_A*/
		    	if(for_i == 0x0) {					/*(2) được nhấn*/
		    		while(PORTDbits.RD3 == 1);
					StringSend[Count_1] = 0x62 - CapsLock - Digital;		/*B/2*/
					++Count_1;
				}
				else if(for_i == 0x1) {				/*(3) được nhấn*/
					while(PORTDbits.RD3 == 1);
					StringSend[Count_1] = 0x63 - CapsLock - Digital;		/*C/3*/
					++Count_1;
				}
				else {								/*(1) được nhấn*/
					while(PORTDbits.RD3 == 1);
					StringSend[Count_1] = 0x61 - CapsLock - Digital;		/*A/1*/
					++Count_1;
				}
		    }
		    else if(PORTDbits.RD4 == 1) {			/*Quét hàng Keypad_B*/
		    	if(for_i == 0x0) {					/*(5) được nhấn*/
		    		while(PORTDbits.RD4 == 1);
					StringSend[Count_1] = 0x65 - CapsLock - Digital;		/*E/5*/
					++Count_1;
				}
				else if(for_i == 0x1) {				/*(6) được nhấn*/
					while(PORTDbits.RD4 == 1);
					StringSend[Count_1] = 0x66 - CapsLock - Digital;		/*F/6*/
					++Count_1;
				}
				else {								/*(4) được nhấn*/
					while(PORTDbits.RD4 == 1);
					StringSend[Count_1] = 0x64 - CapsLock - Digital;		/*D/4*/
					++Count_1;
				}
		    }
		    else if(PORTDbits.RD5 == 1) {			/*Quét hàng Keypad_C*/
		    	if(for_i == 0x0) {					/*(8) được nhấn*/
		    		while(PORTDbits.RD5 == 1);
					StringSend[Count_1] = 0x68 - CapsLock - Digital;		/*H/8*/
					++Count_1;
				}
				else if(for_i == 0x1) {				/*(9) được nhấn*/
					while(PORTDbits.RD5 == 1);
					StringSend[Count_1] = 0x69 - CapsLock - Digital;		/*I/9*/
					++Count_1;
				}
				else {								/*(7) được nhấn*/
					while(PORTDbits.RD5 == 1);
					StringSend[Count_1] = 0x67 - CapsLock - Digital;		/*G/7*/
					++Count_1;
				}
		    }
		    else if(PORTDbits.RD6 == 1) {			/*Quét hàng Keypad_D*/
		    	if(for_i == 0x0) {					/*Caps Lock được nhấn*/
		    		while(PORTDbits.RD6 == 1);
					if(CapsLock == 0x00) {
						State ^= 0x08;				/*Bật bit biểu thị Caps Lock*/
						CapsLock = 0x20;
						Digital = 0x00;				/*Không thể vừa bật Caps Lock vừa bật Digital được*/
						LedState(State);
						State ^= 0x08;				/*Xóa bit biểu thị Caps Lock*/
					}
					else {
						CapsLock = 0x00;
						LedState(State);
					}
				}
				else if(for_i == 0x1) {				/*Digital được nhấn*/
					while(PORTDbits.RD6 == 1);
						if(Digital == 0x00) {
							State ^= 0x04;			/*Bật bit biểu thị Digital*/
							Digital = 0x30;
							CapsLock = 0x00;		/*Không thể vừa bật Digital vừa bật Caps Lock được*/
							LedState(State);
							State ^= 0x04;			/*Xóa bit biểu thị Digital*/
						}
						else {
							Digital = 0x00;
							LedState(State);
						}
				}
				else {								/*(0) được nhấn*/
					while(PORTDbits.RD6 == 1);
					if(Digital == 0x00)
						StringSend[Count_1] = 0x6A - CapsLock;		/*J/0*/
					else
						StringSend[Count_1] = 0x6A - CapsLock - 0x3B;		/*J/0*/
					++Count_1;
				}
		    }		    
		}
	}
}
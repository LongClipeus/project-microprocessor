/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"

void ScanMatrixKeypad(char *StringSend, int length);










// char ScanMatrixKeypad() {
// 	/*Thiết lập thông số ban đầu*/
// 	PORTDbits.RD2 = 0;
// 	for(for_i = 0; for_i < 7; ++for_i) { 
// 		PORTDbits.RD1 = 0;  PORTDbits.RD1 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
// 	}
// 	/*End Thiết lập thông số ban đầu*/
// 	while(1) {
// 		PORTDbits.RD2 ^= 1;							/*logic 1*/
// 		PORTDbits.RD1 = 0;  PORTDbits.RD1 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
// 		PORTDbits.RD2 ^= 1;							/*logic 0*/
// 		for_i = 0x0;
// 		do {
// 			PORTDbits.RD0 = 1;	PORTDbits.RD0 = 0;		/*Chốt led ==> Quét cột thứ for_i*/

// 			/*kiem tra*/
// 			if(PORTDbits.RD3 == 1) {
// 				/*Q, W, E, R, T, Y, U, count*/
// 				if(for_i == 0x0) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x71;				/*Q*/
// 				}
// 				else if(for_i == 0x1) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x77;				/*W*/
// 				}
// 				else if(for_i == 0x2) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x65;				/*E*/
// 				}
// 				else if(for_i == 0x3) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x72;				/*R*/
// 				}
// 				else if(for_i == 0x4) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x74;				/*T*/
// 				}
// 				else if(for_i == 0x5) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x79;				/*Y*/
// 				}
// 				else if(for_i == 0x6) {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x75;				/*U*/
// 				}
// 				else {
// 					while(PORTDbits.RD3 == 1);
// 					return 0x69;				/*count*/
// 				}
// 			}
// 			else if(PORTDbits.RD4 == 1) {
// 				if(for_i == 0x0)
// 					return 0x61;				/*A*/
// 				else if(for_i == 0x1)
// 					return 0x73;				/*S*/
// 				else if(for_i == 0x2)
// 					return 0x64;				/*D*/
// 				else if(for_i == 0x3)
// 					return 0x66;				/*F*/
// 				else if(for_i == 0x4)
// 					return 0x67;				/*G*/
// 				else if(for_i == 0x5)
// 					return 0x68;				/*H*/
// 				else if(for_i == 0x6)
// 					return 0x6A;				/*J*/
// 				else
// 					return 0x6B;				/*K*/
// 			}
// 			else if(PORTDbits.RD5 == 1) {
// 				if(for_i == 0x0)
// 					return 0x7A;				/*Z*/
// 				else if(for_i == 0x1)
// 					return 0x78;				/*X*/
// 				else if(for_i == 0x2)
// 					return 0x63;				/*C*/
// 				else if(for_i == 0x3)
// 					return 0x76;				/*V*/
// 				else if(for_i == 0x4)
// 					return 0x62;				/*B*/
// 				else if(for_i == 0x5)
// 					return 0x6E;				/*N*/
// 				else if(for_i == 0x6)
// 					return 0x6D;				/*M*/
// 				else
// 					return 0x6C;				/*L*/
// 			}
// 			else if(PORTDbits.RD6 == 1) {
// 				if(for_i == 0x0)
// 					return 0x3;					/*Caps Lock*/
// 				else if(for_i == 0x1)
// 					return 0x2;					/*Digital*/
// 				else if(for_i == 0x2)
// 					return 0x1;					/*On/Off*/
// 				else if(for_i == 0x3)
// 					return 0x0;					/*Reset*/
// 				/*else if(for_i == 0x4)
// 					return 0x74;*/
// 				else if(for_i == 0x5)
// 					return 0xD;					/*Enter*/
// 				else if(for_i == 0x6)
// 					return 0x70;				/*P*/
// 				else
// 					return 0x6F;				/*O*/
// 			}

// 			PORTDbits.RD1 = 0;  PORTDbits.RD1 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
// 			__delay_ms(400);
// 			++for_i;
// 		}while(for_i < 8);
// 	}
// }

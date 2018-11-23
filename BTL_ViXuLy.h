/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include <xc.h>
#include <pic.h>


// CONFIG1
#pragma config FOSC = EXTRC_CLKOUT                      // Oscillator Selection bits (RC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, RC on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF                               // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF                              // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON                               // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF                                 // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF                                // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON                               // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON       							// Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       						// Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        						// Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   						// Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        						// Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

/*************************************************************************************************************/
#define _XTAL_FREQ 8000000L     /*Khai báo tần số hoạt động: 1MHz  */

/* Chớp led **************************************************************************************************/
#define FlashLed 10				/*Thời gian sáng khi chớp led*/

/* Hiển thị nhiệt độ *****************************************************************************************/
#define NumberFlashLed1 5		/*Số lần nháy chớp tắt ứng với nhiệt độ >= 40oC*/
#define Time1 100				/*Thời gian hiển thị nhiệt độ ứng với nhiệt độ < 40oC*/

/* Welcome ***************************************************************************************************/
#define SpeedWelcom 1			/*Tốc độ chạy chữ Welcome*/
#define LoopWelcom 1			/*Số lần lặp lại chạy chữ Welcome*/

/* Chat ******************************************************************************************************/
#define NumberReadText 10		/*Số ký tự tối đa có thể nhận từ một chuỗi gửi từ máy tính*/
#define TimeReadText 100		/*Thời gian hiển thị chữ khi nhận được một chuỗi gửi đến từ máy tính*/
#define SpeedReadText 1			/*Tốc độ chạy chữ khi có một string từ máy tính gửi tới*/
#define LoopReadText 1			/*Số lần lặp lại hiển thị chữ được gửi đến từ máy tính*/

#define IST_NumberText 6		/*Số ký tự tối đa có thể gửi đi từ MPG13*/
#define TimeSendText 100		/*Thời gian hiển thị chữ khi gửi một chuỗi từ MPG13*/
#define SpeedSendText 1			/*Tốc độ chạy chữ khi gửi một chuỗi từ MPG13*/
#define LoopSendText 1			/*Số lần lặp lại hiển thị chữ khi gửi một chuỗi từ MPG13*/

/* Khai báo biến toàn cục*************************************************************************************/
int scanRowLed, scanColLed, scanSpeedLed, scanFont , for_i, x, y;
unsigned int adc_lm35;
char D, bitFontDS1, posC, posD, State;


/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "LedMatrix.h"
#include "Librarie.h"
#include "Keypad.h"
#include "UART.h"

void main(void) {
    Establish();					/*Khởi tạo thông số ban đầu*/
    char c[4];
    char Comment[] = "Comment: ";
    while(1) {
    	if(RCIF != '\0') {
    		UART_Write_Text(Comment, sizeof(Comment) - 1);
    		UART_Read_Text(c, sizeof(c));
    	}
    	else
    		ShowTemperature();			/*Hiển thị nhiệt độ*/
    }
    return;
}

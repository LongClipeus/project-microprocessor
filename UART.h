/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "LedMatrix.h"

char UART_Init(const long int baudrate);
void UART_Write_Text(char *text, int length);
void UART_Write(char data);
void UART_Read_Text(char *Output, int length);
char UART_Read();
char UART_Data_Ready();
char UART_TX_Empty();


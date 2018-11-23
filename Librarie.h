/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "UART.h"

void interrupt ISR(void);
void ADCinit (void);
void Establish();
void Timer0_ms(int t);
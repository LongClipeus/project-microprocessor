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

// Khỏi tạo các thông số ban đầu
void Establish() {
    /*=== Thiết lập chân input, output và các thông số ban đầu ===*/
    ANSEL = 0x0; ANSELH = 0x0;          /* su dung o che do Digital */
    TRISCbits.TRISC0 = 0; TRISCbits.TRISC1 = 0; TRISCbits.TRISC2 = 0; TRISCbits.TRISC3 = 0; TRISCbits.TRISC4 = 0; TRISCbits.TRISC5 = 0; /*Các chân output RC*/
    TRISDbits.TRISD0 = 0; TRISDbits.TRISD1 = 0; TRISDbits.TRISD2 = 0; TRISDbits.TRISD7 = 0;                      /*Các chân output RD*/
    TRISDbits.TRISD3 = 1; TRISDbits.TRISD4 = 1; TRISDbits.TRISD5 = 1; TRISDbits.TRISD6 = 1; /*Các chân input RD*/
    
    /*Reset led báo trạng thái khởi động (có tác dụng trong trường hợp reset lại MPG13*/
    State = 0x00;
    LedState(State);

    /*Bật led báo trạng thái khởi động*/
    State = 0x01;
    LedState(State);

    TRISAbits.TRISA0 = 1;
    PORTDbits.RD0 = 1; PORTDbits.RD1 = 0; PORTDbits.RD2 = 0;
    PORTC = 0x00;

    /*=== Thiết lập thông số ngắt ===*/
    INTCONbits.GIE = 1;         /*Bit cho phép ngắt tổng (ngắt toàn cục)*/
    INTCONbits.INTE = 1;        /*Cờ cho phép ngắt ngoài ở chân RB0*/
    INTCONbits.INTF = 0;        /*Tắt cờ ngắt*/
    OPTION_REGbits.INTEDG = 1;  /*Chọn cảnh ngắt. Tức là khi chuyển mức logic từ 1 -> 0 hay mức logic từ 0 -> 1 sẽ ngắt ==> Xảy ra ngắt khi có tín hiệu cạnh lên ở PORTB*/
    TRISBbits.TRISB0 = 1;       /*Chân RB0 là chân input*/

    /*=== Thiết lập thông số timer ===*/
    OPTION_REGbits.T0CS = 0;                   /*timer 0 làm việc ở chế độ timer và hoạt động với nguồn xung internal clock và xung này bằng xung mà VDK đang dùng chia cho 4 ( FOCS/4)*/
    OPTION_REGbits.PSA = 0;     /*Bit là PSA quy định bộ chia tần prescaler được sử dụng cho bộ timer0*/
    OPTION_REGbits.PS2 = 0;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS0 = 1;
    /*==> d = 1:16*/
    //INTCONbits.T0IE = 0;        /*Bit không cho phép thực hiện ngắt đối với timer0*/
    TMR0 = 5;                  /*Khởi tạo giá trị ban đầu*/

    /***************************************************/
    ANSELbits.ANS0 = 1;
    ADCON0 = 0b01000001;
    ADCON1bits.ADFM = 1;
    
    /***************************************************/
    resetLed();                 /*Tắt hết các led matrix (có tác dụng trong trường hợp reset lại MPG13)*/
    UART_Init(9600);
    ADCinit();

    /*Hiển thị lời chào*/
    char Welcome[] = "Group 13 chao ban";
    ChangeTheFont(Welcome, sizeof(Welcome) - 1);
    ShowRunLetter(Welcome, sizeof(Welcome) - 1, SpeedWelcom, LoopWelcom);

    /*Tắt led báo trạng thái khởi động*/
    State = 0x00;
    LedState(State);
}

void interrupt ISR(void) {
    if(INTCONbits.INTF) {                   /*Xuất hiện ngắt*/
        /*Bật led báo trạng thái ngắt*/
        State ^= 0x02;
        LedState(State);

        INTCONbits.INTF = 0;                /*Xóa cờ ngắt*/
        resetLed();                         /*Tắt hết các led matrix đang sáng (nếu có)*/
        char output[IST_NumberText];
        ScanMatrixKeypad(output, IST_NumberText);       /*Quét keypad cho đến khi nhập đủ IST_NumberText ký tự*/
        UART_Write_Text(output, IST_NumberText);        /*Gửi chuỗi vừa nhập đến máy tính*/
        UART_Write(13);

        /*Hiển thị kết quả đã gửi sau khi gửi thành công (Thực ra chưa có lệnh kiểm tra gửi thành công và trong code này mặc định là gửi thành công)*/
        ChangeTheFont(output, IST_NumberText);
        if(IST_NumberText < 6)
            ShowLetter(output, IST_NumberText, TimeSendText);
        else
            ShowRunLetter(output, IST_NumberText, SpeedSendText, LoopSendText);

        /*Xóa led báo trạng thái ngắt*/
        State ^= 0x02;
        LedState(State);
    }
}

void ADCinit (void) {   
    /*chon tan so clock cho bo adc*/
    ADCON0bits.ADCS1 = 0, ADCON0bits.ADCS0 = 1;
    /*chon kenh ADC*/
    ADCON0bits.CHS0 = 0, ADCON0bits.CHS1 = 0, ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS3 = 0;
    /*chon cach luu data*/
    ADCON1bits.ADFM = 1;
    /*cap nguon cho khoi adc*/
    ADCON0bits.ADON = 1;
}


void Timer0_ms(int t) {
    while(--t) {
        TMR0 = 5;                  /*Khởi tạo giá trị ban đầu*/
        INTCONbits.TMR0IF = 0;        /*Xóa cờ tràn*/
        while(!INTCONbits.TMR0IF);
    }
}
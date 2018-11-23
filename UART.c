/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "UART.h"
#include "LedMatrix.h"

/**
 * Hàm khởi tạo modul UART
 * Tham số truyền vào là tốc độ baud, tốc độ baud thông dụng nhất là 9600 tức là trong 1s Pic truyền được 9600bit trong đó 1bit start, 8bit data, 1 bit stop (không có bit parity-chẵn lẻ)
 */
char UART_Init(const long int baudrate) {
	unsigned int x = (_XTAL_FREQ - baudrate*64)/(baudrate*64);	/*SPBRG for Low Baud Rate*/
	if(x > 255) {													/*If High Baud Rage Required*/
		x = (_XTAL_FREQ - baudrate*16)/(baudrate*16);			/*SPBRG for High Baud Rate*/
		BRGH = 1;												/*Chọn chế độ baund rate: BRGH = 1: Tốc độ cao (bất đồng bộ)*/
	}
	if(x < 256) {
		SPBRG = x;												/*Khởi tạo baund rate: ở thanh ghi SPBRG*/

		/*Cho phép quá trình truyền thông không đồng bộ bằng cách thiết lập SPEN = 1; SYNC = 0;*/
		SYNC = 0;												/*Truyền chế độ bất đồng bộ*/
		SPEN = 1;												/*Cho phép cỏng nối tiếp*/

		TX9 = 0;												/*Hoạt động với chế độ 8 bit*/
		TRISC7 = 1;												/*As Prescribed in Datasheet*/
		TRISC6 = 1;												/*As Prescribed in Datasheet*/
		CREN = 1;												/*Cho phep nhận liên tục*/
		TXEN = 1;												/*Cho phép truyền dữ liệu => dữ liệu từ thanh ghi TXREG đưa vào thanh ghi TSR đồng thời baund rate tác động đến TSR*/
		RCIE = 1;
	  	return 1;												/*Returns 1 to indicate Successful Completion*/
	}
	return 0;													/*Returns 0 to indicate UART initialization failed*/
}

char UART_TX_Empty() {
	return TRMT;
}

char UART_Data_Ready() {	/*ham kiem tra xem trong thanh ghi co noi dung hay khong*/
	return RCIF;
}

/**
 * Quá trình nhận dữ liệu bao gồm:
 * 1. Khởi tạo baund rate: ở thanh ghi SPBRG. Cho phép quá trình truyền thông không đồng bộ bằng cách thiết lập SPEN = 1; SYNC = 0;
 * 2. Cho phép ngắt quá trình nhận dữ liệu CREN = 1;
 * 3. Cho phép ngắt toàn cục: CIE = 1; PEIE = 1;
 * 4. Xử lý các phần khác của chương trình khi có ngắt xảy ra thì xử lý dữ liệu.
 */
char UART_Read() {				/*đọc từng ký tự từ bàn phím*/ 
	while(!RCIF);				/*cờ báo thanh ghi Re empty hay full*/
	return RCREG;				/*trả về nội dung của thanh ghi RCREG. Thanh ghi RCREG: Dùng để lưu dữ liệu từ ngoài vào.*/
}

void UART_Read_Text(char *Output, int length) {
	State ^= 0x10;					/*Bật bit biểu thị MPG13 đang gửi data đến máy tính*/
	LedState(State);
	for(for_i = 0; for_i < length; ++for_i) {
		Output[for_i] = UART_Read();
	}
	ChangeTheFont(Output, length);
	if(length < 6)
		ShowLetter(Output, length, TimeReadText);
	else
		ShowRunLetter(Output, length, SpeedReadText, LoopReadText);
	State ^= 0x10;					/*Xóa bit biểu thị MPG13 đang gửi data đến máy tính*/
	LedState(State);
	resetLed();
}

/**
 * Quá trình gửi dữ liệu bao gồm:
 * 1. Khởi tạo baund rate: ở thanh ghi SPBRG. Cho phép quá trình truyền thông không đồng bộ bằng cách thiết lập SPEN = 1; SYNC = 0;
 * 2. Cho phép truyền dữ liệu bằng cách thiết lập bit TXEN = 1;
 * 3. Khi cần truyền dữ liệu thì cần set dữ liệu đó lên TXREG.
 */
void UART_Write(char data) {	/*TRMT = 1: Thanh ghi TSR trống; TRMT = 0: Thanh ghi TSR có dữ liệu*/
	while(!TRMT);	/*TRMT dùng để báo trạng thái thanh ghi TSR. TRMT = 1: không có dữ liệu trong thanh ghi TSR; TRMT = 0: có dữ liệu trong thanh ghi TSR*/
	TXREG = data;					/*Dữ liệu cần truyền được đặt vào thanh ghi TXREG (Dữ liệu là 1byte)*/
}

void UART_Write_Text(char *text, int length) {
  for(for_i = 0; for_i < length; ++for_i) {
	  UART_Write(text[for_i]);
  }
}

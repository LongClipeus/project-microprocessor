/**
 * Author:  Group 13
 * Class:   94736
 * Created on June 12, 2017, 5:45 PM
 */

#include "BTL_ViXuLy.h"
#include "LedMatrix.h"
#include "Librarie.h"


const char FontD[] =   {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

const char FontC[][8] ={{0x7E, 0x85, 0x89, 0x91, 0x7E, 0x00, 0x00, 0x00},  /*0*/
						{0x00, 0x21, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00},  /*1*/
						{0x43, 0x85, 0x89, 0x91, 0x61, 0x00, 0x00, 0x00},  /*2*/
						{0x82, 0x81, 0x91, 0xA9, 0xC6, 0x00, 0x00, 0x00},  /*3*/
						{0x18, 0x28, 0x48, 0xFF, 0x08, 0x00, 0x00, 0x00},  /*4*/
						{0xF2, 0x91, 0x91, 0x91, 0x8E, 0x00, 0x00, 0x00},  /*5*/
						{0x3E, 0x51, 0x91, 0x91, 0x0E, 0x00, 0x00, 0x00},  /*6*/
						{0x80, 0x80, 0x8F, 0x90, 0xE0, 0x00, 0x00, 0x00},  /*7*/
						{0x6E, 0x91, 0x91, 0x91, 0x6E, 0x00, 0x00, 0x00},  /*8*/
						{0x60, 0x91, 0x91, 0x92, 0x7C, 0x00, 0x00, 0x00},  /*9*/

						{0x7F, 0x90, 0x90, 0x90, 0x7F, 0x00, 0x00, 0x00},  /*A ==> 10*/
						{0xFF, 0x91, 0x91, 0x91, 0x6E, 0x00, 0x00, 0x00},  /*B ==> 11*/
						{0x7E, 0x81, 0x81, 0x81, 0x42, 0x00, 0x00, 0x00},  /*C ==> 12*/
						{0xFF, 0x81, 0x81, 0x42, 0x3C, 0x00, 0x00, 0x00},  /*D ==> 13*/
						{0xFF, 0x91, 0x91, 0x91, 0x81, 0x00, 0x00, 0x00},  /*E ==> 14*/
						{0xFF, 0x90, 0x90, 0x90, 0x80, 0x00, 0x00, 0x00},  /*F ==> 15*/
						{0x7E, 0x81, 0x89, 0x8F, 0x08, 0x00, 0x00, 0x00},  /*G ==> 16*/
						{0xFF, 0x10, 0x10, 0x10, 0xFF, 0x00, 0x00, 0x00},  /*H ==> 17*/
						{0x81, 0x81, 0xFF, 0x81, 0x81, 0x00, 0x00, 0x00},  /*I ==> 18*/
						{0x82, 0x81, 0xFE, 0x80, 0x80, 0x00, 0x00, 0x00},  /*J ==> 19*/
						{0xFF, 0x18, 0x24, 0x42, 0x81, 0x00, 0x00, 0x00},  /*K ==> 20*/
						{0xFF, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00},  /*L ==> 21*/
						{0xFF, 0x20, 0x10, 0x20, 0xFF, 0x00, 0x00, 0x00},  /*M ==> 22*/
						{0xFF, 0x20, 0x10, 0x08, 0xFF, 0x00, 0x00, 0x00},  /*N ==> 23*/
						{0x7E, 0x81, 0x81, 0x81, 0x7E, 0x00, 0x00, 0x00},  /*O ==> 24*/
						{0xFF, 0x90, 0x90, 0x90, 0x60, 0x00, 0x00, 0x00},  /*P ==> 25*/
						{0x7E, 0x81, 0x85, 0x82, 0x7D, 0x00, 0x00, 0x00},  /*Q ==> 26*/
						{0xFF, 0x98, 0x94, 0x92, 0x61, 0x00, 0x00, 0x00},  /*R ==> 27*/
						{0x62, 0x91, 0x91, 0x91, 0x4E, 0x00, 0x00, 0x00},  /*S ==> 28*/
						{0x80, 0x80, 0xFF, 0x80, 0x80, 0x00, 0x00, 0x00},  /*T ==> 29*/
						{0xFE, 0x01, 0x01, 0x01, 0xFE, 0x00, 0x00, 0x00},  /*U ==> 30*/
						{0xFC, 0x02, 0x01, 0x02, 0xFC, 0x00, 0x00, 0x00},  /*V ==> 31*/
						{0xFF, 0x04, 0x08, 0x04, 0xFF, 0x00, 0x00, 0x00},  /*W ==> 32*/
						{0xC7, 0x28, 0x10, 0x28, 0xC7, 0x00, 0x00, 0x00},  /*X ==> 33*/
						{0xE0, 0x10, 0x0F, 0x10, 0xE0, 0x00, 0x00, 0x00},  /*Y ==> 34*/
						{0x87, 0x89, 0x91, 0xA1, 0xC1, 0x00, 0x00, 0x00},  /*Z ==> 35*/

						{0x02, 0x15, 0x15, 0x15, 0x0F, 0x00, 0x00, 0x00},  /*a ==> 36*/
						{0xFF, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00, 0x00},  /*b ==> 37*/
						{0x0E, 0x11, 0x11, 0x11, 0x02, 0x00, 0x00, 0x00},  /*c ==> 38*/
						{0x0E, 0x11, 0x11, 0x0A, 0xFF, 0x00, 0x00, 0x00},  /*d ==> 39*/
						{0x0E, 0x15, 0x15, 0x15, 0x0C, 0x00, 0x00, 0x00},  /*e ==> 40*/
						{0x08, 0x3F, 0x48, 0x40, 0x20, 0x00, 0x00, 0x00},  /*f ==> 41*/
						{0x18, 0x25, 0x25, 0x25, 0x3E, 0x00, 0x00, 0x00},  /*g ==> 42*/
						{0x7F, 0x04, 0x08, 0x08, 0x07, 0x00, 0x00, 0x00},  /*h ==> 43*/
						{0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x00, 0x00},  /*i ==> 44*/
						{0x00, 0x02, 0x01, 0x11, 0x5E, 0x00, 0x00, 0x00},  /*j ==> 45*/
						{0x00, 0x7F, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00},  /*k ==> 46*/
						{0x00, 0x41, 0x7F, 0x01, 0x00, 0x00, 0x00, 0x00},  /*l ==> 47*/
						{0x1F, 0x10, 0x08, 0x10, 0x0F, 0x00, 0x00, 0x00},  /*m ==> 48*/
						{0x1F, 0x08, 0x10, 0x10, 0x0F, 0x00, 0x00, 0x00},  /*n ==> 49*/
						{0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, 0x00, 0x00},  /*o ==> 50*/
						{0x3F, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00},  /*p ==> 51*/
						{0x18, 0x24, 0x24, 0x3F, 0x00, 0x00, 0x00, 0x00},  /*q ==> 52*/
						{0x1F, 0x08, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00},  /*r ==> 53*/
						{0x09, 0x15, 0x15, 0x12, 0x00, 0x00, 0x00, 0x00},  /*s ==> 54*/
						{0x10, 0x7E, 0x11, 0x01, 0x02, 0x00, 0x00, 0x00},  /*t ==> 55*/
						{0x1E, 0x01, 0x01, 0x02, 0x1F, 0x00, 0x00, 0x00},  /*u ==> 56*/
						{0x1C, 0x02, 0x01, 0x02, 0x1C, 0x00, 0x00, 0x00},  /*v ==> 57*/
						{0x1E, 0x01, 0x02, 0x01, 0x1E, 0x00, 0x00, 0x00},  /*w ==> 58*/
						{0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00, 0x00},  /*x ==> 59*/
						{0x18, 0x05, 0x05, 0x05, 0x1E, 0x00, 0x00, 0x00},  /*y ==> 60*/
						{0x11, 0x13, 0x15, 0x19, 0x11, 0x00, 0x00, 0x00},  /*z ==> 61*/

						{0x70, 0x88, 0x88, 0x88, 0x70, 0x00, 0x00, 0x00},  /*oC ==> 62*/
						{0xFF, 0xA9, 0x91, 0xA9, 0xFF, 0x00, 0x00, 0x00},  /*[x] ==> 63*/

						{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}   /*null == > 64*/
};

/**
 * resetLed:    Tắt hết tất cả các led của led matrix
 */
void resetLed() {
	PORTCbits.RC2 = 0;
	PORTCbits.RC3 = 0;
	for(scanColLed = 0; scanColLed <32; ++scanColLed) {
		PORTCbits.RC1 = 0;  PORTCbits.RC1 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
	}
	PORTCbits.RC0 = 1;	PORTCbits.RC0 = 0;			/*Chốt led ==> led matrix tắt*/
}

/**
 * @param X:            Số hàng chục của nhiệt độ cần hiển thị
 * @param Y:            Số hàng đơn vị của nhiệt độ cần hiển thị
 * ShowTemperature():   Hiển thị nhiệt độ X, Y được truyền vào
 */
void ShowTemperature() {
	/*Tính nhiệt độ*/
	ADCON0bits.GO_nDONE = 1;
    while(ADCON0bits.GO_nDONE);
    adc_lm35 = (ADRESH<<8) + ADRESL;
    adc_lm35 = (5000.0f/1023*adc_lm35)/10;
    x = adc_lm35/10;
    y = adc_lm35 - x*10;

	char Temperature[5];
	Temperature[0] = 64;
    Temperature[1] = (char)x;
    Temperature[2] = (char)y;
    Temperature[3] = 62;
    Temperature[4] = 12;
	if(x > 3)
		FlickerLed(Temperature, 5, NumberFlashLed1);
	else
		ShowLetter(Temperature, 5, Time1);
}

/**
 * @param StringShow:   Chuối truyền vào cần hiển thị
 * @param length:       Độ dài của chuỗi StringShow
 * @param cycleShow:    Số lần chớp (tắt)
 * FlickerLed():        Hiển thị hớp tắt chuỗi StringShow được truyền vào
 */
void FlickerLed(char *StringShow, int length, int number) {
	for(for_i = 0; for_i < number; ++for_i) {
		ShowLetter(StringShow, length, FlashLed);
	    resetLed();
	    Timer0_ms(300);
	}
	resetLed();
}

/**
 * @param StringShow:   Chuỗi truyền vào cần chuyển đổi
 * @param length:       Độ dài chuỗi cần chuyển đổi
 * ChangeTheFont():     Chuyển đổi chuỗi truyền vào về dạng số tương ứng của ký tự đó trong bảng mã FontC
 */
void ChangeTheFont(char *StringShow, int length) {
	/*chuyển đổi chuỗi cần hiển thị thành số tương ứng trong bảng FontC*/
	for(for_i = 0; for_i < length; ++for_i) {
		if(47 < StringShow[for_i] && StringShow[for_i] < 58)
			StringShow[for_i] -= 48;
		else if(64 < StringShow[for_i] && StringShow[for_i] < 91)
			StringShow[for_i] -= 55;
		else if(96 < StringShow[for_i] && StringShow[for_i] < 123)
			StringShow[for_i] -= 61;
		else if(StringShow[for_i] == 32)
			StringShow[for_i] = 64;
		else
			StringShow[for_i] = 63;
	}
}

/**
 * @param StringShow:   Chuỗi truyền vào cần hiển thị
 * @param length:       Độ dài chuỗi StringShow truyền vào
 * @param cycle_speed:  Tốc độ hoặc chu kỳ cần hiển thị chuỗi StringShow
 * @param number:       Số lần chạy chữ ứng với trường hợp length của chuỗi StringShow > 5
 * ShowLed():           Hàm quyết định hiển thị chuỗi StringShow theo dạng chạy chữ hay dạng hiển thị bình thường
 */
void ShowLed(char *StringShow, int length, int cycle_speed, int number) {
	if(length < 6)
		ShowLetter(StringShow, length, cycle_speed);
	else
		ShowRunLetter(StringShow, length, cycle_speed, number);
}

/**
 * @param StringShow:   Chuỗi truyền vào cần hiển thị
 * @param length:       Độ dài chuỗi được truyền vào
 * @param cycleShow:    Thời gian hiển thị chuỗi StringShow, được tính bằng số vòng lặp for
 * ShowLetter():        Hiển thị chuỗi StringShow trong một khoảng thời gian là số (cycleShow) vòng lặp for
 */
void ShowLetter(char *StringShow, int length, int cycleShow) {
	for(scanSpeedLed = 0; scanSpeedLed < cycleShow; ++scanSpeedLed) {
		posC = 0x80;
		/*Quét 8 hàng*/
		for(scanRowLed = 0; scanRowLed < 8; ++scanRowLed) {
			/*lấy font vào chân D*/
			D = FontD[scanRowLed];
			posD =  0x80;
			/*Quét 32 cột*/
			for(scanColLed = 0; scanColLed < 32; ++scanColLed) {
				if(scanColLed > 23) {
					PORTCbits.RC2 = ((D & posD) ? 1 : 0);  /*Lay bit dua vao chan DS0 hay còn gọi là láy bit vào chân D*/
	                posD >>= 1;
				}
				/*set font vàn chân C*/
				if(scanColLed < 6)
					bitFontDS1 = FontC[StringShow[0]][scanColLed];
				else if(length > 1 && scanColLed < 12)
					bitFontDS1 = FontC[StringShow[1]][scanColLed - 6];
				else if(length > 2 && scanColLed < 18)
					bitFontDS1 = FontC[StringShow[2]][scanColLed - 12];
				else if(length > 3 && scanColLed < 24)
					bitFontDS1 = FontC[StringShow[3]][scanColLed - 18];
				else if(length == 5 && scanColLed < 30)
					bitFontDS1 = FontC[StringShow[4]][scanColLed - 24];
				else
					bitFontDS1 = FontC[64][0];
				PORTCbits.RC3 = ((bitFontDS1 & posC) ? 1 : 0);  /*Lay bit dua vao chan DS1 hay còn gọi là lấy bit vào chân C*/
	            PORTCbits.RC1 = 0;  PORTCbits.RC1 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
			}
			PORTCbits.RC0 = 1;	PORTCbits.RC0 = 0;			/*Chốt led ==> led matrix sáng*/
			posC >>= 1;										/*quét 8 hàng led*/
		}
	}
	resetLed();
}

/**
 * @param StringShow:   Chuỗi truyền vào cần hiển thị
 * @param length:       Độ dài chuỗi truyền vào
 * @param SpeedLed:     Tốc độ chạy chữ
 * @param number:       Số lần lặp lại chạy chữ
 * ShowRunLetter():     Hiển thị chạy chữ chuỗi StringShow được truyền vòa với tốc độ là SpeedLed và với số lần lặp lại là number
 */
void ShowRunLetter(char *StringShow, int length, int SpeedLed, int number) {
	int tmp1, tmp2, loop = 0;
	scanFont = 0;
	while(loop < number) {
		for(scanSpeedLed = 0; scanSpeedLed < SpeedLed; ++scanSpeedLed) {
			posC = 0x80;
			/*Quét 8 hàng*/
			for(scanRowLed = 0; scanRowLed < 8; ++scanRowLed) {
				/*lấy font vào chân D*/
				D = FontD[scanRowLed];
				posD =  0x80;
				/*Quét 32 cột*/
				for(scanColLed = 0; scanColLed < 32; ++scanColLed) {
					if(scanColLed > 23) {
						PORTCbits.RC2 = ((D & posD) ? 1 : 0);  /*Lay bit dua vao chan DS0 hay còn gọi là láy bit vào chân D*/
		                posD >>= 1;
					}
					/*lấy font null*/
					if(scanColLed < (32 - scanFont) || scanColLed > (31 + (length<<3) - scanFont)) {		/*if(scanColLed < (32 - scanFont) || scanColLed > (32 + 6*length - scanFont))*/
						bitFontDS1 = FontC[64][0];
					}
					/*lấy font chữ*/
					else {
						tmp1 = (scanColLed + scanFont - 32);
						tmp2 = tmp1 & 0x07;				/*tmp2 = tmp1 % 8;*/
						tmp1 >>= 3;						/*tmp1 /= 8;*/
						bitFontDS1 = FontC[StringShow[tmp1]][tmp2];
					}
					PORTCbits.RC3 = ((bitFontDS1 & posC) ? 1 : 0);		/*Lay bit dua vao chan DS1 hay còn gọi là lấy bit vào chân C*/
		            PORTCbits.RC1 = 0;  PORTCbits.RC1 = 1;      		/*Đẩy bit đưa vào bộ nhớ đệm*/
				}
				PORTCbits.RC0 = 1;	PORTCbits.RC0 = 0;					/*Chốt led ==> led matrix sáng*/
				posC >>= 1;												/*quét 8 hàng led*/
			}
		}
		if(scanFont > (32 + (length<<3) )) {
			scanFont = 0;
			++loop;
		}
		else
			++scanFont;
	}
	resetLed();
}

void LedState(char StringShow) {
	posC = 0x80;
	int for_j;
    for(for_j = 0; for_j < 8; ++for_j) {
        PORTDbits.RD7 = ((StringShow & posC) ? 1 : 0);  /*Lay bit dua vao chan DS0 hay còn gọi là láy bit vào chân D*/
        posC >>= 1;
        PORTCbits.RC5 = 0;  PORTCbits.RC5 = 1;      /*Đẩy bit đưa vào bộ nhớ đệm*/
    }
    PORTCbits.RC4 = 1;  PORTCbits.RC4 = 0;      /*Chốt led ==> led báo khởi động sáng*/

}
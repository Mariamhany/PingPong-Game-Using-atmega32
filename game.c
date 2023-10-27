/*
 * game.c
 *
 *  Created on: Oct 27, 2023
 *      Author: HP
 */

#include <util/delay.h>
#include"DIO.h"
#include "lcd.h"
#include"game.h"

u8 ballrow = 1, ballcol = 1;
u8 p1row = 1, p2row = 1;
u8 direction = lefttoright;

void Charinit() {
	u8 padel1[] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
	u8 padel2[] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10 };
	u8 ball[] = { 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, 0x00 };
	LCD_storeCustomChar(ball, 0);
	LCD_storeCustomChar(padel1, 1);
	LCD_storeCustomChar(padel2, 2);

	LCD_displayCustomChar(1, p1row, 0);
	LCD_displayCustomChar(2, p2row, 19);

}
void changeBallcol(void) {
	if (ballrow == 4) {
		ballrow = 3;
	} else if (ballrow == 0) {
		ballrow = 1;
	}
	if (ballcol == 19) {
		direction = righttoleft;
	} else if (ballcol == 0) {
		direction = lefttoright;
	}
	LCD_displayCustomChar(0, ballrow, ballcol);
	_delay_ms(100);
	LCD_ClearGrid(ballrow, ballcol);
	if (direction == righttoleft) {
		ballcol--;
	} else if (direction == lefttoright) {
		ballcol++;
	}

}
void changeBallrow() {
	if (DIO_GetPinValue(PORTD_ID, ball_up) == 0) {
		_delay_ms(3);
		while (DIO_GetPinValue(PORTD_ID, ball_up) == 0)
			;
		// LCD_ClearGrid(ballrow,ballcol);
		ballrow--;
		if (ballrow == 0) {
			ballrow = 1;
		}
	}
	if (DIO_GetPinValue(PORTD_ID, ball_down) == 0) {
		_delay_ms(3);
		while (DIO_GetPinValue(PORTD_ID, ball_down) == 0);
		//LCD_ClearGrid(ballrow,19);
		ballrow++;
		if (ballrow == 4) {
			ballrow = 3;
		}
	}
	LCD_displayCustomChar(0, ballrow, ballcol);

}

void movePlayer() {
	if (direction == lefttoright) {
		if (DIO_GetPinValue(PORTD_ID, Padel2_up) == 0) {
			_delay_ms(20);
			while (DIO_GetPinValue(PORTD_ID, Padel2_up) == 0);
			LCD_ClearGrid(p2row, 19);
			p2row--;
			if (p2row == 0) {
				p2row = 1;
			}

		}
		if (DIO_GetPinValue(PORTD_ID, Padel2_down) == 0) {
			_delay_ms(20);
			while (DIO_GetPinValue(PORTD_ID, Padel2_down) == 0)	;
			LCD_ClearGrid(p2row, 19);
			p2row++;
			if (p2row == 4) {
				p2row = 3;
			}
		}

	} //direction
	else if (direction == righttoleft) {

		if (DIO_GetPinValue(PORTD_ID, Padel1_up) == 0) {
			_delay_ms(20);
			while (DIO_GetPinValue(PORTD_ID, Padel1_up) == 0)	;

			LCD_ClearGrid(p1row, 0);
			p1row--;
			if (p1row == 0) {
				p1row = 1;
			}
		}
		if (DIO_GetPinValue(PORTD_ID, Padel1_down) == 0) {
			_delay_ms(20);
			while (DIO_GetPinValue(PORTD_ID, Padel1_down) == 0)	;
			LCD_ClearGrid(p1row, 0);
			p1row++;
			if (p1row == 4) {
				p1row = 3;
			}
		}

	} //elseif

} //function

u8 Scorecalc(u8 *p1score, u8 *p2score) {
	u8 score_flag = 0;
	if (ballcol == 19) {
		if (ballrow != p2row) {
			(*p1score)++;
			score_flag = 1;

		}

	} else if (ballcol == 0) {
		if (ballrow != p1row) {
			(*p2score)++;
			score_flag = 1;
		}

	}
	return score_flag;
}



#include <util/delay.h>
#include"DIO.h"
#include "lcd.h"
#include"game.h"
extern u8 p1row , p2row;
int main() {

	DIO_init();
	LCD_init();
	Charinit();

	u8 score1 = 0, score2 = 0;
	LCD_GotoRowColumn(0, 0);
	LCD_writeString("player1:");
	LCD_GotoRowColumn(0, 8);
	LCD_integertoString(score1);
	LCD_writeString(" player2:");
	LCD_GotoRowColumn(0, 18);
	LCD_integertoString(score2);
	while (1) {
		changeBallcol();
		LCD_displayCustomChar(1, p1row, 0);
		LCD_displayCustomChar(2, p2row, 19);

		//displaying scores
		if (Scorecalc(&score1, &score2) == 1) {
			LCD_GotoRowColumn(0, 0);
			LCD_writeString("player1:");
			LCD_GotoRowColumn(0, 8);
			LCD_integertoString(score1);
			LCD_writeString(" player2:");
			LCD_GotoRowColumn(0, 18);
			LCD_integertoString(score2);
		}

		movePlayer();
		changeBallrow();

	}
	return 0;

}

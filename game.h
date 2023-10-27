/*
 * game.h
 *
 *  Created on: Oct 27, 2023
 *      Author: HP
 */

#ifndef GAME_H_
#define GAME_H_

#include <util/delay.h>
#include"DIO.h"
#include "lcd.h"



#define ball_up   PIN3_ID
#define ball_down PIN5_ID

#define Padel1_up   PIN3_ID
#define Padel1_down PIN5_ID
#define Padel2_up   PIN6_ID
#define Padel2_down PIN7_ID

#define lefttoright 1
#define righttoleft 0


void Charinit();
void changeBallcol(void);
void changeBallrow();
void movePlayer();
u8 Scorecalc(u8 *p1score, u8 *p2score) ;

#endif /* GAME_H_ */

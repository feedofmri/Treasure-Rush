
//  Project: Treasure Rush
//
//  Author: Md. Rubayet Islam, Adel Mohammad Zahid, Saleh Mahmud Sami
//
//  Version: 1.0
//
//x=280     y=633

#define screenWidth 1280;
#define screenHight 720;
#define Jumplimit 200;

#include <iostream>
#include "header\iGraphics.h"
#include "header\variables.h"
#include "header\loadImage.h"

#include "bitmap_loader.h"

using namespace std;

int mposx, mposy;
boolean musicOn = true;
boolean iSstand = true;
boolean jump = false;
boolean jumpUp = false;
boolean R = false;
boolean L = false;
boolean attack = false;
boolean coinTimer = false;
boolean screenTimer = false;
boolean screenTimer2 = false;
boolean gameOver = false;
boolean missionOver = false;
boolean settingsBtn = false;
boolean settingsBool = false;
boolean coinBool = false;
boolean gemBool = false;
boolean iSrun = false;
boolean Exit = false;
boolean lifedecay = false;
boolean mission1loading = false;
boolean NamePlate = false;
int x = 0;
int y = 0;
int fireY = 180;
int fireX = 2000;
int dx = 10;
int dy = 10;
int r = 255;
int g = 255;
int b = 255;
int T;
int forest;
int iceland;
int desert;
int volcano;

int fire;
int countcoll;
int countcoin = 0;
int coinindex = 0;
int totalcoin = 0;
int counter = 0;
int lindex = 0;
int counter2 = 0;
int mission1counter = 0;
int mission2counter = 0;

int lifeindex = 20;
char initScore[10000000];
char finalScore[10000000];
char initcoin[10000000];
int totalScore = 0;
int gameScore = 0;

void funcGameOver();
void funcMissionOver();

void drawHomePage();
void drawHscorePage();
void drawInstructPage();
void drawMission1Page();
void drawMission2Page();
void drawMission3Page();
void drawMission4Page();
void drawCreditPage();
void drawMapPage();
void drawScreen();
void collision();

void coincollision(int i);
void fireballcollision();
void Run();
void showcoin();


void scoreCounter();
void drawScore();


void startButtonClickHandler();
void creditButtonClickHandler();
void mapButtonClickHandler();
void instructButtonClickHandler();
void hscoreButtonClickHandler();

void mission1ButtonClickHandler();
void mission2ButtonClickHandler();
void mission3ButtonClickHandler();
void mission4ButtonClickHandler();

void backButtonClickHandler();


void GameOver();


//__________________________________________________________________________________SCORING_________________________________________________________________

bool play_ground = false;
char str1[40];
bool take_name = false;
int len = 0;
bool high_score_page = false;
void showChar()
{
iSetColor(0, 0, 0);
iRectangle(476, 301, 324, 50);
iText(578, 325, str1, GLUT_BITMAP_HELVETICA_18);

}
typedef struct Player Player;

struct Player{
char name[30];
int score = 0;
Player()
{
;
}
Player(char *_name, int _score)
{
strcpy(name, _name);
score = _score;
}
};
typedef struct sorting
{
char ch[30];
int sc;
} sorts;

void sort_stru(sorting o1[], int cnt)
{
for (int i = 0; i < cnt; i++)
{
for (int j = i + 1; j < cnt; j++)
{
if (o1[i].sc < o1[j].sc)
{
sorting temp = o1[i];
o1[i] = o1[j];
o1[j] = temp;
}
}
}
}
Player o1;
void high_page_sorting(){
FILE *fp = fopen("high_score.txt", "a");
fprintf(fp, "%s %d\n", o1.name, o1.score);
fclose(fp);
}
void showing_score_page(){
int z;
FILE *fp = fopen("high_score.txt", "r");
char chs[30];
int cnt = 0;
while (fscanf(fp, "%s%d", &chs, &z) != EOF)
{
cnt++;
}
sorts o2[100];
fclose(fp);
fp = fopen("high_score.txt", "r");
for (int i = 0; i < cnt; i++)
{
fscanf(fp, "%s%d", &chs, &z);
strcpy(o2[i].ch, chs);
o2[i].sc = z;
}
fclose(fp);
fp = fopen("high_score.txt", "r");
sort_stru(o2, cnt);
int x = cnt;
if (cnt>7){
x = 7;
}
for (int i = 0; i <x; i++)
{
char name[2][30];
fprintf(fp, "%s %d\n", o2[i].ch, o2[i].sc);
sprintf(name[0], "%s", o2[i].ch);
sprintf(name[1], "%d", o2[i].sc);
iSetColor(255, 255, 0);
iText(251, 460 - 50 * i, name[0], GLUT_BITMAP_TIMES_ROMAN_24);
iText(603, 460 - 50 * i, name[1], GLUT_BITMAP_TIMES_ROMAN_24);
}
fclose(fp);
}
char point[1000];
void showing_score(){

iShowBMP2(975, 720, "bci\\scoring.bmp", 0);
iShowBMP2(1000, 745, "bci\\s1.bmp", 0);
iSetColor(0, 0, 0);
iText(1125, 755, ":", GLUT_BITMAP_TIMES_ROMAN_24);
sprintf_s(point, "%d", o1.score);
iText(1142, 755, point, GLUT_BITMAP_TIMES_ROMAN_24);
}
void takeinput(unsigned char key){
if (key == 'p'){
exit(0);
}
if (key == '\r'){
strcpy(o1.name, str1);
NamePlate = false;

}
else if (key == '\b'){
if (len <= 0){
len = 0;
}
else
len--;
str1[len] = '\0';
}
else{
str1[len] = key;
len++;
if (len > 15){
len = 15;
}str1[len] = '\0';
}
}
//_________________________________________________________________________________Scoring end______________________________________________________________

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if (loadingScreen == 1)
	{
		iShowImage(0, 0, 1280, 720, load[lindex]);

	}
	else if (mission1loading)
	{
		iShowImage(0, 0, 1280, 720,M1load[MLindex]);
	}
	else if (homePage == 1)
	{
		drawHomePage();
	}
	else if (mapPage == 1)
	{
		drawMapPage();
	}
	else if (hscorePage == 1)
	{
		drawHscorePage();
	}
	else if (instructPage == 1)
	{
		drawInstructPage();
	}
	else if (mission1Page == 1 && !mission1loading)
	{
			drawMission1Page();
	}
	else if (mission2Page == 1)
	{
		drawMission2Page();
	}
	else if (mission3Page == 1)
	{
		drawMission3Page();
	}
	else if (mission4Page == 1)
	{
		drawMission4Page();
	}
	else if (creditPage == 1)
	{
		drawCreditPage();
	}

	if (!mission1loading && mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1){
		iShowImage(1160, 630, 60, 59, settingsbtn);
	}
	if (!mission1loading && NamePlate && mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1){
		iShowImage(314, 120, 652, 480, NameEntrance);
		showChar();
	}
	if (settingsBool && mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1){
		iShowImage(314, 120, 650, 480, settings);
	}
	if (gameOver && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && !Exit)
	{
		iShowImage(314, 120, 652, 480, gameover);

		//shows total score after gameover
		iSetColor(255, 255, 255);
		sprintf_s(finalScore, "%d", totalScore);
		iText(620, 348, finalScore, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 255, 255);
		sprintf_s(initcoin, "%d", totalcoin);
		iText(772, 348, initcoin, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (missionOver && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1))
	{ 
		iShowImage(314, 120, 652, 480, missionover);
	}





	if (attack)
	{
		if (R)
		{
			if (level)
			{
				iShowImage(herindexX, herindexY, 150, 111, attack1R[attackindx]);
			}
		}
		else
		{
			if (level)
			{
				iShowImage(herindexX, herindexY, 150, 111, attack1L[attackindx]);
			}
		}
	}

	else if (jump)
	{
		if (level && (!gameOver))
		{
			if (jumpUp)
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, jumpup1[jindex]);
			}
			else
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, jumpdown1[jindex]);
			}
		}
		else
		{
			if (jumpUp)
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, herjumpup[jindex]);
			}
			else
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, herjumpDown[jindex]);
			}
		}

		if (L)
		{
			if (jumpUp)
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, herjumpupL[jindex]);
			}
			else
			{
				iShowImage(herindexX, herindexY + hercordinatej, 150, 111, herjumDownL[jindex]);
			}
		}
	}
	else
	{
		if (!iSstand)
		{
			if (level && (!gameOver) && (!Exit))
			{
				iShowBMP2(herindexX, herindexY, run1_location[index], 0);
				if (!iSrun)
				{
					iSstand = true;
				}

			}
		}
		else
		{
			if (level && (!gameOver)&& (!mission1loading))
			{
				iShowBMP2(herindexX, herindexY, herstand1_location, 0);
			}
		}
		if (L)
		{
			if (level && (!gameOver))
			{
				iShowImage(herindexX, herindexY, 150, 111, herstand102[0]);
			}
		}
	}

}




/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//**************************************ipassiveMouse****************************//
void iPassiveMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d     y=%d\n", mx, my);

		if (homePage == 1 && (mx >= 860 && mx <= 1150) && (my >= 525 && my <= 612))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			mapButtonClickHandler();
		}
		else if (homePage == 1 && (mx >= 860 && mx <= 1150) && (my >= 375 && my <= 470))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			instructButtonClickHandler();
		}
		else if (homePage == 1 && (mx >= 860 && mx <= 1150) && (my >= 238 && my <= 330))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			hscoreButtonClickHandler();
		}
		else if (homePage == 1 && (mx >= 860 && mx <= 1150) && (my >= 99 && my <= 193))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			creditButtonClickHandler();
		}

		else if (homePage == 1 && (mx >= 59 && mx <= 161) && (my >= 77 && my <= 164))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			if (musicOn)
			{
				musicOn = false;
				PlaySound(0, 0, 0);
			}
			else
			{
				musicOn = true;
				PlaySound("music\\bgmusic.wav", NULL, SND_LOOP | SND_ASYNC);
			}
		}
		else if (homePage == 0 && !(mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && (mx >= 77 && mx <= 258) && (my >= 606 && my <= 666))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			backButtonClickHandler();
		}


		else if (mapPage == 1 && (mx >= 160 && mx <= 477) && (my >= 286 && my <= 455))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			musicOn = false;
			Exit = false;
			mission1ButtonClickHandler();
		}
		else if (mapPage == 1 && mission1Com == 1 && (mx >= 315 && mx <= 590) && (my >= 115 && my <= 250))
		{
			Exit = false;
			mission2ButtonClickHandler();
		}
		else if (mapPage == 1 && mission2Com == 1 && (mx >= 160 && mx <= 477) && (my >= 286 && my <= 455))
		{
			Exit = false;
			mission3ButtonClickHandler();
		}
		else if (mapPage == 1 && mission3Com == 1 && (mx >= 160 && mx <= 477) && (my >= 286 && my <= 455))
		{
			Exit = false;
			mission4ButtonClickHandler();
		}

		else if (loadingScreen == 1 && loadtohome == 1)
		{
			loadingScreen = 0;
			homePage = 1;
		}

		else if (gameOver && mission1Page == 1 && (mx >= 572 && mx <= 625) && (my >= 192 && my <= 246))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			lifeindex = 20;
			herindexX = 0;
			drawMission1Page();
			coinTimer = false;
			screenTimer = false;
			iSrun = false;
			gameOver = false;
		}
		else if (gameOver && (mx >= 657 && mx <= 713) && (my >= 194 && my <= 244))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			lifeindex = 20;
			herindexX = 0;
			x = 0;
			iSstand = false;
			iSrun = false;
			gameOver = false;
			Exit = true;
			mission1counter = 0;
			mission1Page = 0;
			mission2Page = 0;
			mission3Page = 0;
			mission4Page = 0;
			mapButtonClickHandler();
		}
		else if (missionOver && mission1Page == 1 && (mx >= 572 && mx <= 625) && (my >= 192 && my <= 246))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			herindexX = 0;
			x = 0;
			iSstand = false;
			iSrun = false;
			gameOver = false;
			mission1counter = 0;
			mission1Page = 0;
			mission2Page = 0;
			mission3Page = 0;
			mission4Page = 0;
			mapButtonClickHandler();
			
		}
		else if (missionOver && (mx >= 657 && mx <= 713) && (my >= 194 && my <= 244))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			iSstand = false;
			iSrun = false;
			gameOver = false;

		}
		//settingsBool && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1)
		else if ((mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && (mx >= 1168 && mx <= 1212) && (my >= 636 && my <= 681))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			settingsBool = true;
			coinTimer = false;
			screenTimer = false;
			Exit = true;
			
		}
		else if (settingsBool && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && (mx >= 550 && mx <= 725) && (my >= 435 && my <= 495))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			settingsBool = false;
			coinTimer = false;
			screenTimer = true;
			iSrun = true;
			Exit = false;
			
		}
		else if (settingsBool && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && (mx >= 535 && mx <= 743) && (my >= 325 && my <= 395))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			lifeindex = 20;
			coincount = 0;
			gemcount = 0;
			gameScore = 0;
			settingsBool = false;
			drawMission1Page();
			gameOver = false;
			mission1counter = 0;
			herindexX = 0;
			herindexY = 110;
			x = 0;
			y = 0;
			coinTimer = false;
			iSrun = false;
			screenTimer = false;
			screenTimer2 = false;
			iSstand = false;
			Exit = false;
			stoneindex = 0;
			Stone1x = 500;
			Stone1y = 100;
			fireX = 3000;
		}
		else if (settingsBool && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1) && (mx >= 550 && mx <= 733) && (my >= 215 && my <= 280))
		{
			mciSendString("play click.wav", NULL, 0, NULL);
			lifeindex = 20;
			gameScore = 0;
			coincount = 0;
			gemcount = 0;
			settingsBool = false;
			herindexX = 0;
			herindexY = 110;
			fireX = 3000;
			x = 0;
			y = 0;
            coinTimer = false;
			iSrun = false;
			screenTimer = false;
			screenTimer2 = false;
			iSstand = false;
			stoneindex = 0;
			Stone1x = 500;
			Stone1y = 100;
			gameOver = false;
			Exit = true;
			mission1counter = 0;
			mission1Page = 0;
			mission2Page = 0;
			mission3Page = 0;
			mission4Page = 0;
			mapButtonClickHandler();
		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/



void iKeyboard(unsigned char key)
{
		
	if (NamePlate){
		takeinput(key);
	}

	if (!gameOver && !NamePlate && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1))
	{
	if (key == 's')
	{
		screenTimer = true;
        coinTimer = true;
		y -= 10;
	}
	else if (key == 'd')
	{
		screenTimer = true;
        coinTimer = true;
		x += 10;
	}
	
	else if (key == 'a')
	{
		screenTimer = true;
        coinTimer = true;
		if (!attack)
		{
			attack = true;
		}
		else
		{
			attack = false;
		}

	}
	else if (key == 'j')
	{
		screenTimer = true;
        coinTimer = true;
		if (!jump && !gameOver)
		{
			jump = true;
			jumpUp = true;
			iSrun = false;

		}

	}
}
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (!gameOver && (mission1Page == 1 || mission2Page == 1 || mission3Page == 1 || mission4Page == 1)){
		if (key == GLUT_KEY_RIGHT)
		{

			if (!screenTimer && (level == 1) && !NamePlate)
			{
				screenTimer = true;
                coinTimer = true;
			}
			/*if (GameOver && (mission1Page != 0))
			{
				GameOver = false;
			} */

			if (jump)
			{
				iSstand = false;
				iSrun = false;
			}
			else if (!gameOver && !NamePlate)
			{
				iSrun = true;
				iSstand = false;
			}
		}
		if (key == GLUT_KEY_LEFT)
		{
			screenTimer = true;
            coinTimer = true;
			if (level2)
			{
				L = true;
				R = false;
				if (herindexX >= 1)
				{
					herindexX -= dx;
				}
				else
				{
					herindexX = 1;
				}

				if (level)
				{
					if (index2<5)
					{
						index2++;
					}
					else
					{
						index2 = 0;
					}
				}
				iSstand = false;
			}

		}

		if (key == GLUT_KEY_UP)
		{
			/* if (!screenTimer2 && (level2 == 1))
			{
			screenTimer2 = true;
			}
			if (herindexY + 145 >= 800)
			{
			herindexY = 800 - 145;
			}
			else
			{
			herindexY += 10;
			}
			*/
		}
		if (key == GLUT_KEY_DOWN)
		{
			/* if (herindexY <= 156)
			{
				herindexY = 156;
			}
			else{
				herindexY -= 10;
			}
			*/
		}
	}

}


void scoreCounter(){
	if (mission1Page == 1 && screenTimer){
		gameScore = gameScore + 1;
		if (coinBool){
			coincount++;
			gameScore = gameScore + 10;
			coinBool = false;
		}
		if (gemBool){
			gemcount++;
			gameScore = gameScore + 40;
			gemBool = false;
		}

		totalScore = gameScore;
		totalcoin = coincount;
	}
}


void drawScore(){
	if (mission1Page == 1){

		iSetColor(0, 0, 0);
		sprintf_s(initScore, "%d", gameScore);
		iText(120, 650, initScore, GLUT_BITMAP_TIMES_ROMAN_24);

		/*iSetColor(255, 204, 203);
		iFilledRectangle(840, 460, 100, 50);
		iSetColor(255, 0, 0);
		iText(865, 495, "Score", GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(point, "%d", score);
		iText(875, 466, "Point", GLUT_BITMAP_TIMES_ROMAN_24);*/
	}
}
/*void drawcollcoin(){
	if (mission1Page == 1){

		iSetColor(0, 0, 0);
		sprintf_s(initcoin, "%d", coincount);
		iText(120, 650, initcoin, GLUT_BITMAP_TIMES_ROMAN_24);

		/*iSetColor(255, 204, 203);
		iFilledRectangle(840, 460, 100, 50);
		iSetColor(255, 0, 0);
		iText(865, 495, "Score", GLUT_BITMAP_TIMES_ROMAN_24);

		sprintf_s(point, "%d", score);
		iText(875, 466, "Point", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}
*/



void Run()
{

	if (iSrun)
	{
		if (index <=6)
		{
			index++;
		}
		else
		{
			index = 0;
		}

	}
}
void loadM1page()
{
	if (mission1loading)
	{
		if (MLindex<=10)
		{
			MLindex++;
			
			
		}
		else
		{
			mission1loading = false;
			NamePlate = true;
			MLindex = 0;
		}
	 

	}
}

void loadchage()
{
	if (loadingScreen)
	{
		if (lindex<11)
		{
			lindex++;
			if (lindex == 10){
				loadtohome = 1;
			}
		}
		else if (lindex == 11)
		{
			lindex = 10;
		}

	}
}
void change()
{
	if (jump)
	{
		if (jumpUp)
		{
			if (level)
			{
				if (jindex<4)
				{
					jindex++;
				}
				else
				{
					jindex = 0;
				}
				herindexX += 30;
				hercordinatej += 50;


				if (hercordinatej >= jumplimit)
				{
					jumpUp = false;

				}
			}
			else if (level3)
			{
				if (R)
				{
					herindexX += 20;
					hercordinatej += 10;
				}
				else if (L)
				{
					hercordinatej += 5;
					herindexX -= 5;
				}
				if (hercordinatej >= jumplimit)
				{
					jumpUp = false;

				}
			}

		}
		else
		{
			if (level)
			{
				if (jindex<6)
				{
					jindex++;
				}
				else
				{
					jindex = 0;
				}

				hercordinatej -= 50;
				herindexX += 30;
				if (hercordinatej <0)
				{
					jump = false;
					iSrun = true;
					hercordinatej = 0;

				}

			}
		}
	}
}


void attackf()
{
	if (attack)
	{
		if (R)
		{
			if (level)
			{
				if (attackindx < 18)
				{
					attackindx++;
					herindexX += 4;
				}
				else
				{
					attackindx = 0;
					attack = false;
				}
			}
			else if (level2)
			{
				if (attackindx < 15)
				{
					attackindx++;
					herindexX -= 1;

				}
				else
				{
					attackindx = 0;
				}
			}

		}
		else
		{
			if (level)
			{
				if (attackindx < 18)
				{
					attackindx++;
					herindexX -= 4;

				}
				else
				{
					attackindx = 0;
					attack = false;
				}
			}
			else if (level2)
			{
				if (attackindx < 15)
				{
					attackindx++;
					herindexX -= 1;

				}
				else
				{
					attackindx = 0;
				}
			}


		}
	}
}

void collision()
{

	if ((herindexX + 150 >= Stone1x && herindexX <= Stone1x + 100) && ((herindexY + hercordinatej) <= Stone1y + 45))
	{

		gameOver = true;
		funcGameOver();
	}
}
void coincollision(int i)
{
	if ((herindexX + 150 >= c[i].coincorX && herindexX <= c[i].coincorX + 50) && ((herindexY + hercordinatej) >= c[i].coincorY))
	{
		mciSendString("play coin.wav",NULL,0,NULL);
		c[i].coll = true;
		coinBool = true;
	}
}
void fireballcollision()
{
	if ((herindexX + 150 >= fireX && herindexX <= fireX + 100) && ((herindexY + hercordinatej) <= fireY + 45) && (((herindexY + hercordinatej) + 111) >= fireY))
	{
		fireX = 3000;
		lifedecay = true;
	}
}


void funcGameOver()
{
	o1.score = totalScore;
	high_page_sorting();
	coincount = 0;
	gemcount = 0;
	gameScore = 0;
	coincount = 0;
	gemcount = 0;
	iSrun = false;
	mission1counter = 0;
	herindexX = 0;
	herindexY = 110;
	x = 0;
	y = 0;
	fireY = 180;
	fireX = 2000;
    coinTimer = false;
	screenTimer = false;
	screenTimer2 = false;
	iSstand = false;
	stoneindex = 0;
	Stone1x = 500;
	Stone1y = 100;

}
void funcMissionOver()
{
	iSrun = false;
	mission1counter = 0;
	x = 0;
	y = 0;
	fireY = 180;
	fireX = 2000;
	herindexX = 0;
	herindexY = 110;
    coinTimer = false;
	screenTimer = false;
	screenTimer2 = false;
	iSstand = false;
	stoneindex = 0;
	Stone1x = 500;
	Stone1y = 100;
}


void mapButtonClickHandler()
{
	homePage = 0;
	mapPage = 1;
	mission1Page = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 0;
	creditPage = 0;
}
void mission1ButtonClickHandler()
{
	mapPage = 0;
	mission1Page = 1;
	mission1loading = true;
	level = 1;
	level2 = 0;
	homePage = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 0;
	creditPage = 0;
}
void mission2ButtonClickHandler()
{
	mapPage = 0;
	mission2Page = 1;
	level2 = 1;
	level = 0;
	homePage = 0;
	mission1Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 0;
	creditPage = 0;
}
void mission3ButtonClickHandler()
{
	mapPage = 0;
	mission3Page = 1;
}
void mission4ButtonClickHandler()
{
	mapPage = 0;
	mission4Page = 1;
}

void instructButtonClickHandler(){
	homePage = 0;
	mapPage = 0;
	mission1Page = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 1;
	hscorePage = 0;
	creditPage = 0;
}
void hscoreButtonClickHandler(){
	homePage = 0;
	mapPage = 0;
	mission1Page = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 1;
	creditPage = 0;
}
void creditButtonClickHandler()
{
	homePage = 0;
	mapPage = 0;
	mission1Page = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 0;
	creditPage = 1;
}
void backButtonClickHandler()
{
	homePage = 1;
	mapPage = 0;
	mission1Page = 0;
	mission2Page = 0;
	mission3Page = 0;
	mission4Page = 0;
	instructPage = 0;
	hscorePage = 0;
	creditPage = 0;
}

void drawLife()
{
	if (lifedecay)
	{
		lifeindex--;
		lifedecay = false;
	}
	if (lifeindex<=0)
	{
		funcGameOver();
	}
	else{
		iShowBMP2(340, 639, life[lifeindex], 0);
	}
}

void drawScreen()
{
	if (screenTimer)
	{
		x -= dx;

		if ((!jump) && (Stone1x == 0) && herindexX >= 300)
		{
			while (herindexX != 50)
			{
				herindexX -= dx;
			}
		}

		if (Stone1x>0)
		{
			Stone1x -= 10;
		}
		else{
			Stone1x = 1280;
			stoneindex = rand() % 5;

		}
		if (fireX>0)
		{
			fireX -= 30;
		}
		else
		{
			fireX = 3000;
			fireY = 180 + (rand() % 150);


		}fireballcollision();

	}
	else if (screenTimer2)
	{
		y -= dy;
	}
	
	collision();

}

void drawHomePage()
{
	if (musicOn){
		iSetColor(128, 128, 128);
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\home.bmp", 0);
	}
	else if (!musicOn){
		iSetColor(128, 128, 128);
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\home_soundoff.bmp", 0);
	}

}
void drawMapPage()
{
	iSstand = false;
	iSrun = false;
	if (mission3Com)
	{
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\map\\map4.bmp", 0);
	}
	else if (mission2Com)
	{
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\map\\map3.bmp", 0);
	}
	else if (mission1Com)
	{
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\map\\map2.bmp", 0);
	}
	else
	{
		iFilledRectangle(0, 0, 1280, 720);
		iShowBMP2(0, 0, "image\\map\\map1.bmp", 0);
	}

}

void drawMission1Page()
{
	iShowImage(x, 0, 3972, 720, forest);
	iShowImage(x + 3972, 0, 3972, 720, forest);
	iShowImage(Stone1x, Stone1y, 150, 120, stoneImage[stoneindex]);
	iShowImage(fireX, fireY, 150, 48, fire);
	iShowImage(50, 629, 193, 60, scorecard);
	showcoin();
	drawLife();
	drawScore();

	if (x < -3972)
	{
		x = 0;

	}

}
void showcoin()
{

	if (!gameOver && coinTimer)
	{
		for (int i = 0; i < 10; i++)
		{

			coincollision(i);
			c[i].coincorX -= 0.03;
			if (!(c[i].coll))
			{
				iShowBMP2(c[i].coincorX, c[i].coincorY, coinImage_location[i], 0);
			}

		}


	}
}
void drawMission2Page()
{
	iShowImage(0, y, 1280, 4862, iceland);
	if (y <= -4140)
	{
		screenTimer2 = false;
	}

}
void drawMission3Page()
{
	iFilledRectangle(0, 0, 1280, 720);
	iShowBMP2(0, 0, "image\\mission1\\102.bmp", 0);

}
void drawMission4Page()
{
	iFilledRectangle(0, 0, 1280, 720);
	iShowBMP2(0, 0, "image\\mission1\\102.bmp", 0);

}

void drawHscorePage(){
	iFilledRectangle(0, 0, 1280, 720);
	iShowBMP2(0, 0, "image\\highscore.bmp", 0);
	showing_score_page();

}
void drawInstructPage(){
	iFilledRectangle(0, 0, 1280, 720);
	iShowBMP2(0, 0, "image\\instruction.bmp", 0);
}

void drawCreditPage()
{
	iFilledRectangle(0, 0, 1280, 720);
	iShowBMP2(0, 0, "image\\credits.bmp", 0);
}
void fixing_coing_(){
	for (int i = 0; i < 10; i++)
	if (c[i].coincorX <= 0){
		if (c[i].coll){
			c[i].coll = false;
		}
		c[i].coincorX = 1280 + (rand() % 300) + (i + 1 * 40);
	}
}


void GameOver(){

	iSetColor(128, 128, 128);
	iFilledRectangle(0, 0, 1280, 720);
	//add  game over image
	//add back button
	homePage = 2;

}


int main()
{
	iSetTimer(500, loadchage);
	iSetTimer(150, attackf);
	iSetTimer(50, change);
	iSetTimer(50, drawScreen);
	iSetTimer(50, Run);
	iSetTimer(100, scoreCounter);
	iSetTimer(100, fixing_coing_);
	iSetTimer(500, loadM1page);
	iInitialize(1280, 720, "Treasure Rush");

	forest = iLoadImage("image\\mission1\\forest.png");
	iceland = iLoadImage("image\\mission2\\iceland.png");
	fire = iLoadImage("image\\items\\firball.png");

	loadImage();\
	///updated see the documentations
	if (musicOn)
	{
		PlaySound("music\\bgmusic.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iStart();

	return 0;
}


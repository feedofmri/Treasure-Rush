#ifndef VARIABLES_H_INCLUDED
#define VARIABLES_H_INCLUDED


#define SCREEN_WIDTH 1280
#define SCREEN_HIGHT 720

typedef struct
{
	int coincorX;
	int coincorY;
	bool coll;
}coins;
coins c[10];

char run1_location[14][40] = { "image\\character\\RU\\run0.bmp", "image\\character\\RU\\run1.bmp", "image\\character\\RU\\run2.bmp", "image\\character\\RU\\run3.bmp", "image\\character\\RU\\run4.bmp", "image\\character\\RU\\run5.bmp", "image\\character\\RU\\run6.bmp", "image\\character\\RU\\run0.bmp", "image\\character\\RU\\run1.bmp", "image\\character\\RU\\run2.bmp", "image\\character\\RU\\run3.bmp", "image\\character\\RU\\run4.bmp", "image\\character\\RU\\run5.bmp", "image\\character\\RU\\run6.bmp" };
int MLindex = 0;
int index2 = 0;
int index = 0;
int jindex = 0;
int herindexX = 0;
int herindexY = 140;
int attackindx = 0;
int hercordinatej = 0;
char mission1loadimg[12][40] = { "image\\mission1\\loading\\M2_1.bmp", "image\\mission1\\loading\\M2_1.bmp", "image\\mission1\\loading\\M2_2.bmp", "image\\mission1\\loading\\M2_2.bmp", "image\\mission1\\loading\\M2_3.bmp", "image\\mission1\\loading\\M2_3.bmp", "image\\mission1\\loading\\M2_4.bmp", "image\\mission1\\loading\\M2_4.bmp", "image\\mission1\\loading\\M2_5.bmp", "image\\mission1\\loading\\M2_5.bmp", "image\\mission1\\loading\\M2_6.bmp", "image\\mission1\\loading\\M2_6.bmp"};
char jumpup1_location[7][40] = { "image\\character\\JUM\\jum0.png", "image\\character\\JUM\\jum1.png", "image\\character\\JUM\\jum2.png", "image\\character\\JUM\\jum3.png", "image\\character\\JUM\\jum4.png", "image\\character\\JUM\\jum4.png", "image\\character\\JUM\\jum4.png" };
char jumpdown1_location[7][40] = { "image\\character\\JUM\\jum4.png", "image\\character\\JUM\\jum4.png", "image\\character\\JUM\\jum5.png", "image\\character\\JUM\\jum2.png", "image\\character\\JUM\\jum1.png", "image\\character\\JUM\\jum6.png", "image\\character\\JUM\\jum0.png" };
char attack1R_location[19][40] = { "image\\character\\kick-00.bmp", "image\\character\\kick-01.bmp", "image\\character\\kick-02.bmp", "image\\character\\kick-03.bmp", "image\\character\\kick-04.bmp", "image\\character\\kick-05.bmp", "image\\character\\kick-06.bmp", "image\\character\\kick-07.bmp", "image\\punch-01.bmp", "image\\punch-02.bmp", "image\\punch-03.bmp", "image\\punch-04.bmp", "image\\punch-05.bmp", "image\\punch-06.bmp", "image\\punch-07.bmp", "image\\punch-08.bmp", "image\\punch-09.bmp", "image\\punch-10.bmp", "image\\punch-11.bmp" };
char attack1L_location[19][40] = { "image\\character\\kick-001.bmp", "image\\character\\kick-002.bmp", "image\\character\\kick-003.bmp", "image\\character\\kick-004.bmp", "image\\character\\kick-005.bmp", "image\\character\\kick-006.bmp", "image\\character\\kick-007.bmp", "image\\character\\kick-008.bmp", "image\\punch-001.bmp", "image\\punch-002.bmp", "image\\punch-003.bmp", "image\\punch-004.bmp", "image\\punch-005.bmp", "image\\punch-006.bmp", "image\\punch-007.bmp", "image\\punch-008.bmp", "image\\punch-009.bmp", "image\\punch-010.bmp", "image\\punch-011.bmp" };
char herstand1_location[40] = { "image\\character\\wa0.bmp" };
char herstand102_location[40] = { "image\\character\\wa0.png" };
char herstand2_location[40] = { "image\\character\\4003.bmp" };
char herstand3_location[40] = { "image\\character\\4013.bmp" };
char herjumpup_location[3][40] = { "image\\character\\409.bmp", "image\\character\\409.bmp", "image\\character\\409.bmp" };
char herjumpDown_location[3][40] = { "image\\character\\411.bmp", "image\\character\\412.bmp", "image\\character\\412.bmp" };
char herjumpupL_location[3][40] = { "image\\character\\420.bmp", "image\\character\\420.bmp", "image\\character\\420.bmp" };
char herjumpDownL_location[3][40] = { "image\\character\\421.bmp", "image\\character\\422.bmp", "image\\character\\422.bmp" };
char attackR_location[16][40] = { "image\\character\\attack1-00.bmp", "image\\character\\attack1-01.bmp", "image\\character\\attack1-02.bmp", "image\\character\\attack1-03.bmp", "image\\character\\attack1-04.bmp", "image\\character\\attack1-05.bmp", "image\\character\\attack1-06.bmp", "image\\character\\attack1-07.bmp", "image\\character\\attack1-08.bmp", "image\\character\\attack1-09.bmp", "image\\character\\attack1-10.bmp", "image\\character\\attack1-11.bmp", "image\\character\\attack1-12.bmp", "image\\character\\attack1-13.bmp", "image\\character\\attack1-14.bmp", "image\\character\\attack1-15.bmp" };
char attackL_location[16][40] = { "image\\character\\attack2-00.bmp", "image\\character\\attack2-01.bmp", "image\\character\\attack2-02.bmp", "image\\character\\attack2-03.bmp", "image\\character\\attack2-04.bmp", "image\\character\\attack2-05.bmp", "image\\character\\attack2-06.bmp", "image\\character\\attack2-07.bmp", "image\\character\\attack2-08.bmp", "image\\character\\attack2-09.bmp", "image\\character\\attack2-10.bmp", "image\\character\\attack2-11.bmp", "image\\character\\attack2-12.bmp", "image\\character\\attack2-13.bmp", "image\\character\\attack2-14.bmp", "image\\character\\attack2-15.bmp" };
char load_location[12][40] = { "image\\loading\\loading.bmp", "image\\loading\\loading.bmp", "image\\loading\\loading.bmp", "image\\loading\\loading.bmp", "image\\loading\\loading2.bmp", "image\\loading\\loading3.bmp", "image\\loading\\loading4.bmp", "image\\loading\\loading5.bmp", "image\\loading\\loading6.bmp", "image\\loading\\loading7.bmp", "image\\loading\\loading8.bmp", "image\\loading\\loading9.bmp" };
char stoneImage_location[5][30] = { "image\\stone\\Stone 1.png", "image\\stone\\Stone 2.png", "image\\stone\\Stone 3.png", "image\\stone\\Stone 4.png", "image\\stone\\Stone 5.png" };
char coinImage_location[10][30] = { "image\\items\\coin.bmp", "image\\items\\coin2.bmp", "image\\items\\coin2.bmp", "image\\items\\coin2.bmp", "image\\items\\coin2.bmp", "image\\items\\coin.bmp", "image\\items\\coin2.bmp", "image\\items\\coin.bmp", "image\\items\\coin.bmp", "image\\items\\coin2.bmp" };
char life[21][40] = { "image\\life\\life1.bmp", "image\\life\\life2.bmp", "image\\life\\life3.bmp", "image\\life\\life4.bmp", "image\\life\\life5.bmp", "image\\life\\life6.bmp", "image\\life\\life7.bmp", "image\\life\\life8.bmp", "image\\life\\life9.bmp", "image\\life\\life10.bmp", "image\\life\\life11.bmp", "image\\life\\life12.bmp", "image\\life\\life13.bmp", "image\\life\\life14.bmp", "image\\life\\life15.bmp", "image\\life\\life16.bmp", "image\\life\\life17.bmp", "image\\life\\life18.bmp", "image\\life\\life19.bmp", "image\\life\\life20.bmp", "image\\life\\life20.bmp" };
int newcoin1 = iLoadImage("image\\items\\coin.bmp");
int newcoin2 = iLoadImage("image\\items\\coin2.bmp");
int jumpup1[7];
int jumpdown1[7];
int attack1R[19];
int attack1L[19];
int herstand1[1];
int herstand102[1];
int herstand2[1];
int herstand3[1];
int herjumpup[3];
int herjumpDown[3];
int herjumpupL[3];
int herjumDownL[3];
int attackR[16];
int attackL[16];
int load[12];
int stoneImage[5];
int run1[7];
int run102[7];
int M1load[12];

int gameover;
int missionover;
int settings;
int settingsbtn;
int NameEntrance;
int scorecard;
int life1;
int life2;
int life3;
int life4;

int homePage = 0;
int mapPage = 0;
int mission1Page = 0;
int mission2Page = 0;
int mission3Page = 0;
int mission4Page = 0;
int instructPage = 0;
int hscorePage = 0;
int creditPage = 0;
int startButtonClick = 0;
int loadingScreen = 1;
int level = 0;
int level2 = 0;
int level3 = 0;
int jumplimit = 200;
int mission1Com = 0;
int mission2Com = 0;
int mission3Com = 0;
int loadtohome = 0;
float Stone1x = 500, Stone1y = 100;
int coinX = 0;
int coinY = 165;
int coincount = 0;
int gemcount = 0;
int newcoin1X = 100;
int newcoin1Y = 300;
int newcoin2X = 1000;
int newcoin2Y = 300;
int lifeX = (rand() % 1000 + 450);
int lifeY = 300;
int shildX = (rand() % 1000 + 450);
int shildY = 300;
int stoneindex;

#endif // !VARIABLES_H_INCLUDED

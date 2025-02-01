#pragma once
//#include "define.h"

//scene
#define SCENEID this
#define ISNOTDESTROY 0
#define ISDESTROYINGAME ISNOTDESTROY + 1
#define ISDESTROYOUTGAME ISDESTROYINGAME + 1
#define ISDESTROYINGAMESHOT ISDESTROYOUTGAME + 1

#define DIFFICULTYSCENE 10
#define LEVEL1 1			//1
#define LEVEL2 LEVEL1 + 1	//2
#define LEVEL3 LEVEL2 + 1	//3






//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//
//	//	//entity

//map
#define MAPPATH "../../../res/map.png"
#define MAPPOS sf::Vector2f(0.f,0.f)
#define SPRITESCALEMAP sf::Vector2i(1, 1)

//player
#define PLAYERUP 1*9
#define BOTPATH "../../../res/player_tilemap.png" 
#define PLAYERVELOCITYX 600.f 
#define PLAYERVELOCITYY 600.f 
#define PLAYERVELOCITY sf::Vector2f(PLAYERVELOCITYX, PLAYERVELOCITYY)
#define TIMEPLAYERSHOOT 1
#define TIMEPLAYERSWAP 10
//type (0 = player,1 = enemie)
#define TYPEPLAYER SHOTTYPEPLAYER


//ball
#define SHOTPATH "../../../res/bullet_tilemap.png" 
#define SHOTVELOCITYX 700.f 
#define SHOTVELOCITYY 0.f 
#define SHOTVELOCITY sf::Vector2f(SHOTVELOCITYX, SHOTVELOCITYY)
//type (0 = player,1 = enemie)
#define SHOTTYPEPLAYER 0
#define SHOTTYPEENEMY 1

//ball volt
#define VOLTBALLPATH "../../../res/bulletvolt_tilemap.png" 
#define VOLTBALLVELOCITYX 500.f 
#define VOLTBALLVELOCITYY 500.f 
#define VOLTBALLVELOCITY sf::Vector2f(VOLTBALLVELOCITYX, VOLTBALLVELOCITYY)

//ball light
#define LIGHTBALLPATH "../../../res/bulletlight_tilemap.png" 
#define LIGHTBALLVELOCITYX 700.f 
#define LIGHTBALLVELOCITYY 0.f 
#define LIGHTBALLVELOCITY sf::Vector2f(LIGHTBALLVELOCITYX, LIGHTBALLVELOCITYY)

//ball shadow
#define SHADOWBALLPATH "../../../res/bulletshadow_tilemap.png" 
#define SHADOWBALLVELOCITYX 700.f 
#define SHADOWBALLVELOCITYY 0.f 
#define SHADOWBALLVELOCITY sf::Vector2f(SHADOWBALLVELOCITYX, SHADOWBALLVELOCITYY)

//ball roc
#define ROCBALLPATH "../../../res/bulletroc_tilemap.png" 
#define ROCBALLVELOCITYX 400.f 
#define ROCBALLVELOCITYY 0.f 
#define ROCBALLVELOCITY sf::Vector2f(ROCBALLVELOCITYX, ROCBALLVELOCITYY)

//ball multi
#define MULTIBALLPATH "../../../res/bulletmulti_tilemap.png" 
#define MULTIBALLVELOCITYX 400.f 
#define MULTIBALLVELOCITYY 0.f 
#define MULTIBALLVELOCITY sf::Vector2f(MULTIBALLVELOCITYX, MULTIBALLVELOCITYY)
#define DUPLICATIONMULTIBALL 3
#define DUPLICATIONVELOCITY 200.f 



//rat
#define RATUP 1*1
#define RATPATH "../../../res/rat_tilemap.png" 
#define RATVELOCITYX 200.f 
#define RATVELOCITYY 0.f 
#define RATVELOCITY sf::Vector2f(RATVELOCITYX, RATVELOCITYY)


//aureon
#define AUREONUP 1*1
#define AUREONPATH "../../../res/aureon_tilemap.Png" 
#define AUREONVELOCITYX 100.f 
#define AUREONVELOCITYY 0.f 
#define AUREONVELOCITY sf::Vector2f(AUREONVELOCITYX, AUREONVELOCITYY)
#define TIMEAUREON 25
//type : 1 ennemi / 0 joueur
#define TYPEAUREON SHOTTYPEENEMY


//skarnaugh
#define SKARNAUGHUP 1*3
#define SKARNAUGHPATH "../../../res/skarnaugh_tilemap.Png"
#define SKARNAUGHVELOCITYX 50.f 
#define SKARNAUGHVELOCITYY 0.f 
#define SKARNAUGHVELOCITY sf::Vector2f(SKARNAUGHVELOCITYX, SKARNAUGHVELOCITYY)
#define TIMESKARNAUGH 45

//ghost
#define GHOSTUP 1*1
#define GHOSTPATH "../../../res/ghost_tilemap.png" 
#define GHOSTVELOCITYX 300.f 
#define GHOSTVELOCITYY 0.f 
#define GHOSTVELOCITY sf::Vector2f(GHOSTVELOCITYX, GHOSTVELOCITYY)
#define TIMEGHOSTHIDDEN 10

//scarabe
#define SCARABEUP 1*5
#define SCARABEPATH "../../../res/scarabe_tilemap.png" 
#define SCARABEVELOCITYX 50.f 
#define SCARABEVELOCITYY 0.f 
#define SCARABEVELOCITY sf::Vector2f(SCARABEVELOCITYX, SCARABEVELOCITYY)

//luciole
#define LUCIOLEUP 1*1
#define LUCIOLEPATHLIGHT "../../../res/luciolelight_tilemap.png" 
#define LUCIOLEPATHSHADOW "../../../res/lucioleshadow_tilemap.png" 
#define LUCIOLEVELOCITYX 75.f 
#define LUCIOLEVELOCITYY 0.f 
#define LUCIOLEVELOCITY sf::Vector2f(LUCIOLEVELOCITYX, LUCIOLEVELOCITYY)
#define TIMELUCIOLE 40
//type : 1 ennemi / 0 joueur
#define TYPELUCIOLE SHOTTYPEENEMY

//scarabe
#define BLOBUP 1*1
#define BLOBPATH "../../../res/blob_tilemap.png" 
#define BLOBVELOCITYX 100.f 
#define BLOBVELOCITYY 0.f 
#define BLOBVELOCITY sf::Vector2f(BLOBVELOCITYX, BLOBVELOCITYY)
#define TIMEBLOB 20
#define BLOBDUPLICATEVELOCITY sf::Vector2f(100.f,100.f)



//COLLISION
#define COLLIDEMAP -1
#define COLLIDESHOT 0
#define COLLIDELIGHTBALL COLLIDESHOT + 1	//1
#define COLLIDESHADOWBALL COLLIDELIGHTBALL+1//2
#define COLLIDEVOLTBALL COLLIDESHADOWBALL +1//3
#define COLLIDEROCBALL COLLIDEVOLTBALL + 1	//4
#define COLLIDEMULTIBALL COLLIDEROCBALL + 1	//5
#define COLLIDEPLAYER COLLIDEMULTIBALL + 1	//6
#define COLLIDERAT COLLIDEPLAYER + 1		//7
#define COLLIDEAUREON COLLIDERAT + 1		//8
#define COLLIDESKARNAUGH COLLIDEAUREON + 1	//9
#define COLLIDEGHOST COLLIDESKARNAUGH + 1	//10
#define COLLIDESCARABE COLLIDEGHOST + 1		//11
#define COLLIDELUCIOLE COLLIDESCARABE + 1	//12
#define COLLIDEBLOB COLLIDELUCIOLE + 1		//13

//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//



//shooter
#define DECISECONDE 0.1f
#define TIMESHOOT 20
#define TIMESWAP 60

//sprite manager
#define SPRITESIZEDEFAULT sf::Vector2i(16, 16)
#define SPRITESCALEDEFAULT sf::Vector2i(5, 5)
#define ANIMATIONTIME 0.2f
#define ISNOTENTITY 0
#define ISENTITY ISNOTENTITY + 1
#define FIRSTINDEX 0
/*#define SECONDEINDEX FIRSTINDEX + 1
#define THIRDINDEX SECONDEINDEX + 1*/


//score
#define SCOREDEFAULT 0
#define SCORESHOT 10
#define SCOREPLAYER 0
#define SCOREENEMY 10


//text
#define SCORE 0
#define LIFE SCORE + 1
#define DIFFICULTY LIFE + 1



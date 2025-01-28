#pragma once

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

//player
#define PLAYERUP 1*3
#define PLAYERPATH "../../../res/player_tilemap.png" 
#define PLAYERVELOCITYX 600.f 
#define PLAYERVELOCITYY 600.f 
#define PLAYERVELOCITY sf::Vector2f::Vector2(PLAYERVELOCITYX, PLAYERVELOCITYY)
#define TIMEPLAYERSHOOT 1
#define TIMEPLAYERSWAP 10
//type (0 = player,1 = enemie)
#define TYPEPLAYER SHOTTYPEPLAYER


//shot
#define SHOTPATH "../../../res/bullet_tilemap.png" 
#define SHOTVELOCITYX 700.f 
#define SHOTVELOCITYY 0.f 
#define SHOTVELOCITY sf::Vector2f::Vector2(SHOTVELOCITYX, SHOTVELOCITYY)
//type (0 = player,1 = enemie)
#define SHOTTYPEPLAYER 0
#define SHOTTYPEENEMY 1


//rat
#define RATUP 1*1
#define RATPATH "../../../res/rat_tilemap.png" 
#define RATVELOCITYX 200.f 
#define RATVELOCITYY 0.f 
#define RATVELOCITY sf::Vector2f::Vector2(RATVELOCITYX, RATVELOCITYY)


//aureon
#define AUREONUP 1*1
#define AUREONPATH "../../../res/aureon_tilemap.Png" 
#define AUREONVELOCITYX 100.f 
#define AUREONVELOCITYY 0.f 
#define AUREONVELOCITY sf::Vector2f::Vector2(AUREONVELOCITYX, AUREONVELOCITYY)
#define TIMEAUREON 15
//type : 1 ennemi / 0 joueur
#define TYPEAUREON SHOTTYPEENEMY


//skarnaugh
#define SKARNAUGHUP 1*3
#define SKARNAUGHPATH "../../../res/skarnaugh_tilemap.Png"
#define SKARNAUGHVELOCITYX 50.f 
#define SKARNAUGHVELOCITYY 0.f 
#define SKARNAUGHVELOCITY sf::Vector2f::Vector2(SKARNAUGHVELOCITYX, SKARNAUGHVELOCITYY)
#define TIMESKARNAUGH 45

//ghost
#define GHOSTUP 1*1
#define GHOSTPATH "../../../res/ghost_tilemap.png" 
#define GHOSTVELOCITYX 300.f 
#define GHOSTVELOCITYY 0.f 
#define GHOSTVELOCITY sf::Vector2f::Vector2(GHOSTVELOCITYX, GHOSTVELOCITYY)
#define TIMEGHOSTHIDDEN 10

//scarabe
#define SCARABEUP 1*5
#define SCARABEPATH "../../../res/scarabe_tilemap.png" 
#define SCARABEVELOCITYX 50.f 
#define SCARABEVELOCITYY 0.f 
#define SCARABEVELOCITY sf::Vector2f::Vector2(SCARABEVELOCITYX, SCARABEVELOCITYY)



//COLLISION
#define COLLIDEMAP -1
#define COLLIDESHOT 0
#define COLLIDEPLAYER COLLIDESHOT + 1		//1
#define COLLIDERAT COLLIDEPLAYER + 1		//2
#define COLLIDEAUREON COLLIDERAT + 1		//3
#define COLLIDESKARNAUGH COLLIDEAUREON + 1	//4
#define COLLIDEGHOST COLLIDESKARNAUGH + 1	//5
#define COLLIDESCARABE COLLIDEGHOST + 1		//6

//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//	//



//shooter
#define DECISECONDE 0.1f
#define TIMESHOOT 20
#define TIMESWAP 60


//score
#define SCOREDEFAULT 0
#define SCORESHOT 10
#define SCOREPLAYER 0
#define SCOREENEMY 10


//text
#define SCORE 0
#define LIFE SCORE + 1
#define DIFFICULTY LIFE + 1



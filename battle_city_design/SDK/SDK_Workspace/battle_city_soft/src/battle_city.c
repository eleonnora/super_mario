
#include "battle_city.h"
#include "map.h"
#include "xparameters.h"
#include "xil_io.h"
#include "xio.h"

/*
* GENERATED BY BC_MEM_PACKER
* DATE: Wed Jul 08 21:00:48 2015
*/


// ***** 8x8 IMAGES *****

#define IMG_8x8_01_A                    0x0100
#define IMG_8x8_02_B                    0x0110
#define IMG_8x8_03_V                    0x0120
#define IMG_8x8_04_G                    0x0130
#define IMG_8x8_05_D                    0x0140
#define IMG_8x8_06_DJ                   0x0150
#define IMG_8x8_07_E                    0x0160
#define IMG_8x8_08_ZH                   0x0170
#define IMG_8x8_09_Z                    0x0180
#define IMG_8x8_10_I                    0x0190
#define IMG_8x8_11_J                    0x01A0
#define IMG_8x8_12_K                    0x01B0
#define IMG_8x8_13_L                    0x01C0
#define IMG_8x8_14_LJ                   0x01D0
#define IMG_8x8_15_M                    0x01E0
#define IMG_8x8_16_N                    0x01F0
#define IMG_8x8_17_NJ                   0x0200
#define IMG_8x8_18_O                    0x0210
#define IMG_8x8_19_P                    0x0220
#define IMG_8x8_20_R                    0x0230
#define IMG_8x8_21_S                    0x0240
#define IMG_8x8_22_T                    0x0250
#define IMG_8x8_23_TJ                   0x0260
#define IMG_8x8_24_U                    0x0270
#define IMG_8x8_25_F                    0x0280
#define IMG_8x8_26_H                    0x0290
#define IMG_8x8_27_C                    0x02A0
#define IMG_8x8_28_CH                   0x02B0
#define IMG_8x8_29_DZH                  0x02C0
#define IMG_8x8_30_SH                   0x02D0
#define IMG_8x8_31_NUM_0                0x02E0
#define IMG_8x8_32_NUM_1                0x02F0
#define IMG_8x8_33_NUM_2                0x0300
#define IMG_8x8_34_NUM_3                0x0310
#define IMG_8x8_35_NUM_4                0x0320
#define IMG_8x8_36_NUM_5                0x0330
#define IMG_8x8_37_NUM_6                0x0340
#define IMG_8x8_38_NUM_7                0x0350
#define IMG_8x8_39_NUM_8                0x0360
#define IMG_8x8_40_NUM_9                0x0370
#define IMG_8x8_41_DOTS                 0x0380
#define IMG_8x8_42_FULLSTOP             0x0390
#define IMG_8x8_BLANK                   0x03A0
#define IMG_8x8_BRICK                   0x03B0
#define IMG_8x8_GRASS                   0x03C0
#define IMG_8x8_ICE                     0x03D0
#define IMG_8x8_IRON                    0x03E0
#define IMG_8x8_LIVES_REMAINING_ICON    0x03F0
#define IMG_8x8_NULL                    0x0400
#define IMG_8x8_TANKS_REMAINING_ICON    0x0410
#define IMG_8x8_WATER                   0x0420


// ***** 16x16 IMAGES *****

#define IMG_16x16_BASE_ALIVE            0x0430
#define IMG_16x16_BASE_DEAD             0x0470
#define IMG_16x16_BONUS_BOMB            0x04B0
#define IMG_16x16_BONUS_GUN             0x04F0
#define IMG_16x16_BONUS_SHELL           0x0530
#define IMG_16x16_BONUS_SHOVEL          0x0570
#define IMG_16x16_BONUS_STAR            0x05B0
#define IMG_16x16_BONUS_TANK            0x05F0
#define IMG_16x16_BONUS_TIME            0x0630
#define IMG_16x16_BULLET                0x0670
#define IMG_16x16_ENEMY_TANK1           0x06B0
#define IMG_16x16_ENEMY_TANK2           0x06F0
#define IMG_16x16_ENEMY_TANK3           0x0730
#define IMG_16x16_ENEMY_TANK4           0x0770
#define IMG_16x16_EXPLOSION             0x07B0
#define IMG_16x16_FLAG                  0x07F0
#define IMG_16x16_MAIN_TANK             0x0830


// ***** MAP *****

#define MAP_BASE_ADDRESS                0x0870
#define MAP_X							8
#define MAP_Y							4
#define MAP_W							64
#define MAP_H							56

#define REGS_BASE_ADDRESS               ( MAP_BASE_ADDRESS + MAP_WIDTH * MAP_HEIGHT )


#define BTN_DOWN( b )                   ( !( b & 0x01 ) )
#define BTN_UP( b )                     ( !( b & 0x10 ) )
#define BTN_LEFT( b )                   ( !( b & 0x02 ) )
#define BTN_RIGHT( b )                  ( !( b & 0x08 ) )
#define BTN_SHOOT( b )                  ( !( b & 0x04 ) )


#define TANK1_REG_L                     8
#define TANK1_REG_H                     9
#define BULLET1_REG_L                   6
#define BULLET1_REG_H                   7
#define TANK_AI_REG_L                   4
#define TANK_AI_REG_H                   5
#define BULLET_AI_REG_L                 2
#define BULLET_AI_REG_H                 3
#define BASE_REG_L						0
#define BASE_REG_H						1

#define BULLET_STEP_DURATION            5
#define BULLET_EXPLOSION_DURATION       5

#define BASE_X		                    311
#define BASE_Y						    463


typedef enum {
    _TERM       = 0,
    _A          = IMG_8x8_01_A,
    _B          = IMG_8x8_02_B,
    _V          = IMG_8x8_03_V,
    _G          = IMG_8x8_04_G,
    _D          = IMG_8x8_05_D,
    _DJ         = IMG_8x8_06_DJ,
    _E          = IMG_8x8_07_E,
    _ZH         = IMG_8x8_08_ZH,
    _Z          = IMG_8x8_09_Z,
    _I          = IMG_8x8_10_I,
    _J          = IMG_8x8_11_J,
    _K          = IMG_8x8_12_K,
    _L          = IMG_8x8_13_L,
    _LJ         = IMG_8x8_14_LJ,
    _M          = IMG_8x8_15_M,
    _N          = IMG_8x8_16_N,
    _NJ         = IMG_8x8_17_NJ,
    _O          = IMG_8x8_18_O,
    _P          = IMG_8x8_19_P,
    _R          = IMG_8x8_20_R,
    _S          = IMG_8x8_21_S,
    _T          = IMG_8x8_22_T,
    _TJ         = IMG_8x8_23_TJ,
    _U          = IMG_8x8_24_U,
    _F          = IMG_8x8_25_F,
    _H          = IMG_8x8_26_H,
    _C          = IMG_8x8_27_C,
    _CH         = IMG_8x8_28_CH,
    _DZH        = IMG_8x8_29_DZH,
    _SH         = IMG_8x8_30_SH,
    _0          = IMG_8x8_31_NUM_0,
    _1          = IMG_8x8_32_NUM_1,
    _2          = IMG_8x8_33_NUM_2,
    _3          = IMG_8x8_34_NUM_3,
    _4          = IMG_8x8_35_NUM_4,
    _5          = IMG_8x8_36_NUM_5,
    _6          = IMG_8x8_37_NUM_6,
    _7          = IMG_8x8_38_NUM_7,
    _8          = IMG_8x8_39_NUM_8,
    _9          = IMG_8x8_40_NUM_9,
    _DOTS       = IMG_8x8_41_DOTS,
    _FULLSTOP   = IMG_8x8_42_FULLSTOP,
    _SPACE      = IMG_8x8_BLANK
} characters_t;

typedef enum {
	RES_NONE,
	RES_VICTORY,
	RES_LOSS
} game_result_t;

typedef enum {
    b_false,
    b_true
} bool_t;

typedef enum {
    DIR_UP,
    DIR_LEFT,
    DIR_DOWN,
    DIR_RIGHT
} direction_t;

typedef struct {
    unsigned int    x;
    unsigned int    y;
    direction_t     dir;

    bool_t          enabled;
    unsigned int    time;
    bool_t          explosion;

    unsigned int    reg_l;
    unsigned int    reg_h;
} bullet_t;

typedef struct {
    unsigned int    x;
    unsigned int    y;
    direction_t     dir;
    unsigned int    type;

    bool_t          destroyed;

    bullet_t        bullet;

    unsigned int	reg_l;
    unsigned int	reg_h;
} tank_t;


tank_t tank1 = {
    ( MAP_X + MAP_W / 2 - 1 ) * 8,	// x
    ( MAP_Y + MAP_H - 5 ) * 8,		// y
    DIR_RIGHT,              		// dir
    IMG_16x16_MAIN_TANK,  			// type

    b_false,                		// destroyed

    {
        0,                  		// bullet.x
        0,                  		// bullet.y
        DIR_RIGHT,           		// bullet.dir

        b_false,            		// bullet.enabled
        0,                  		// bullet.time
        b_false,            		// bullet.explosion

        BULLET1_REG_L,      		// bullet.reg_l
        BULLET1_REG_H       		// bullet.reg_h
    },

    TANK1_REG_L,            		// reg_l
    TANK1_REG_H             		// reg_h
};

tank_t tank_ai = {
    MAP_X * 8,						// x
    MAP_Y * 8,						// y
    DIR_RIGHT,              		// dir
    IMG_16x16_ENEMY_TANK4,  		// type

    b_false,                		// destroyed

    {
        0,                  		// bullet.x
        0,                  		// bullet.y
        DIR_RIGHT,           		// bullet.dir

        b_false,            		// bullet.enabled
        0,                  		// bullet.time
        b_false,            		// bullet.explosion

        BULLET_AI_REG_L,      		// bullet.reg_l
        BULLET_AI_REG_H       		// bullet.reg_h
    },

    TANK_AI_REG_L,            		// reg_l
    TANK_AI_REG_H             		// reg_h
};

unsigned int	game_time;
unsigned char	game_result;


unsigned int rand_lfsr113( void )
{
	static unsigned int z1 = 12345, z2 = 12345, z3 = 12345, z4 = 12345;
	unsigned int b;

	b  = ( ( z1 << 6 ) ^ z1 ) >> 13;
	z1 = ( ( z1 & 4294967294U ) << 18 ) ^ b;
	b  = ( ( z2 << 2 ) ^ z2 ) >> 27;
	z2 = ( ( z2 & 4294967288U ) << 2) ^ b;
	b  = ( ( z3 << 13) ^ z3 ) >> 21;
	z3 = ( ( z3 & 4294967280U ) << 7 ) ^ b;
	b  = ( ( z4 << 3 ) ^ z4 ) >> 12;
	z4 = ( ( z4 & 4294967168U ) << 13 ) ^ b;

	return ( z1 ^ z2 ^ z3 ^ z4 );
}

static void draw_string( unsigned int x, unsigned int y, unsigned int * text )
{
    int i;
    
    i = 0;

    while( text[ i ] != _TERM ) {
        Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( MAP_BASE_ADDRESS + y * MAP_WIDTH + x + i ), text[ i ] );
        i++;
    }
}

static void map_update( map_entry_t * map )
{
    unsigned int i;

    for( i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++ ) {
        if( map[ i ].update ) {
            map[ i ].update = 0;

            Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( MAP_BASE_ADDRESS + i ), ( (unsigned int)map[ i ].z << 24 ) | ( (unsigned int)map[ i ].rot << 16 ) | (unsigned int)map[ i ].ptr );
        }
    }
}

static void map_reset( map_entry_t * map )
{
    unsigned int i;

    for( i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++ ) {
        Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( MAP_BASE_ADDRESS + i ), ( (unsigned int)map[ i ].z << 24 ) | ( (unsigned int)map[ i ].rot << 16 ) | (unsigned int)map[ i ].ptr );
    }

    for( i = 0; i <= 20; i += 2 ) {
    	Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + i ), (unsigned int)0x0F000000 );
    }
}

static void tank_spawn( tank_t * tank )
{
	Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + tank->reg_l ), (unsigned int)0x8F000000 | ( (unsigned int)tank->dir << 16 ) | tank->type );
	Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + tank->reg_h ), ( tank->y << 16 ) | tank->x );
}

static bool_t tank_move( map_entry_t * map, tank_t * tank, direction_t dir )
{
    unsigned int    x;
    unsigned int    y;
    map_entry_t *   tl;
    map_entry_t *   tc;
    map_entry_t *   tr;
    map_entry_t *   cl;
	map_entry_t *   cc;
	map_entry_t *   cr;
	map_entry_t *   bl;
	map_entry_t *   bc;
	map_entry_t *   br;

    if( tank->x > ( MAP_X + MAP_W ) * 8 - 16 ||
        tank->y > ( MAP_Y + MAP_H ) * 8 - 16 ) {
        return b_false;
    }

    x = tank->x;
    y = tank->y;

    // Make sure that coordinates will stay within map boundaries after moving.
    if( dir == DIR_LEFT ) {
        if( x > MAP_X * 8 )
        	x--;
    } else if( dir == DIR_RIGHT ) {
        if( x < ( MAP_X + MAP_W ) * 8 - 16 )
        	x++;
    } else if( dir == DIR_UP ) {
        if( y > MAP_Y * 8 )
            y--;
    } else if( dir == DIR_DOWN ) {
        if( y < ( MAP_Y + MAP_H ) * 8 - 16 )
        	y++;
    }

    tl = &map[ ( y / 8 ) * MAP_WIDTH + ( x / 8 ) ];
	tc = &map[ ( y / 8 ) * MAP_WIDTH + ( ( x + 7 ) / 8 ) ];
	tr = &map[ ( y / 8 ) * MAP_WIDTH + ( ( x + 15 ) / 8 ) ];
	cl = &map[ ( ( y + 7 ) / 8 ) * MAP_WIDTH + ( x / 8 ) ];
	cc = &map[ ( ( y + 7 ) / 8 ) * MAP_WIDTH + ( ( x + 7 ) / 8 ) ];
	cr = &map[ ( ( y + 7 ) / 8 ) * MAP_WIDTH + ( ( x + 15 ) / 8 ) ];
	bl = &map[ ( ( y + 15 ) / 8 ) * MAP_WIDTH + ( x / 8 ) ];
	bc = &map[ ( ( y + 15 ) / 8 ) * MAP_WIDTH + ( ( x + 7 ) / 8 ) ];
	br = &map[ ( ( y + 15 ) / 8 ) * MAP_WIDTH + ( ( x + 15 ) / 8 ) ];

    if( tank->x != x || tank->y != y ) {
        // Tank can move if water, iron or brick wall isn't ahead.
        if( tl->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
			tc->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
			tr->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
			cl->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
			cc->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
			cr->ptr != IMG_8x8_BRICK && tl->ptr != IMG_8x8_IRON && tl->ptr != IMG_8x8_WATER &&
        	bl->ptr != IMG_8x8_BRICK && tr->ptr != IMG_8x8_IRON && tr->ptr != IMG_8x8_WATER &&
        	bc->ptr != IMG_8x8_BRICK && bl->ptr != IMG_8x8_IRON && bl->ptr != IMG_8x8_WATER &&
        	br->ptr != IMG_8x8_BRICK && br->ptr != IMG_8x8_IRON && br->ptr != IMG_8x8_WATER) {

            tank->x = x;
            tank->y = y;

            if( tank->dir != dir ) {
                tank->dir = dir;

                Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + tank->reg_l ), (unsigned int)0x8F000000 | ( (unsigned int)tank->dir << 16 ) | tank->type );
            }

            Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + tank->reg_h ), ( tank->y << 16 ) | tank->x );

            return b_true;
        }
    }

    return b_false;
}

static void tank_fire( map_entry_t * map, tank_t * tank )
{
    bullet_t * blt;

    if( tank->bullet.enabled ) {
    	return;
    }

    blt = 0;

    if( tank->dir == DIR_LEFT ) {
        if( tank->x > MAP_X * 8 - 16 ) {
            blt = &tank->bullet;

            blt->x = tank->x - 8;
            blt->y = tank->y;
        }
    } else if( tank->dir == DIR_RIGHT ) {
        if( tank->x < ( MAP_X + MAP_W ) * 8 - 16 ) {
            blt = &tank->bullet;

            blt->x = tank->x + 8;
            blt->y = tank->y;
        }
    } else if( tank->dir == DIR_UP ) {
        if( tank->y > MAP_Y * 8 + 16 ) {
            blt = &tank->bullet;

            blt->x = tank->x;
            blt->y = tank->y - 8;
        }
    } else if( tank->dir == DIR_DOWN ) {
        if( tank->y < ( MAP_Y + MAP_H ) * 8 - 16 ) {
            blt = &tank->bullet;

            blt->x = tank->x;
            blt->y = tank->y + 8;
        }
    }

    if( blt ) {
    	blt->enabled = b_true;
        blt->dir = tank->dir;
        blt->explosion = b_false;
        blt->time = game_time;

        Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), (unsigned int)0x8F000000 | ( (unsigned int)blt->dir << 16 ) | (unsigned int)IMG_16x16_BULLET );
        Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
    }
}

static bool_t hitbox( unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int w, unsigned int h )
{
	return ( x1 >= x2 && x1 <= x2 + w && y1 >= y2 && y1 <= y2 + h ) ? b_true : b_false;
}

static void process_bullet( map_entry_t * map, bullet_t * blt )
{
    unsigned int    x;
    unsigned int    y;
    map_entry_t *   tl;
    map_entry_t *   tr;
   	map_entry_t *   bl;
   	map_entry_t *   br;


	if( !blt->enabled ) {
		return;
	}

    if( blt->explosion ) {
        if( game_time > blt->time + BULLET_EXPLOSION_DURATION ) {
            blt->enabled = b_false;
            Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), 0x0F000000 );
        }
    } else {
        if( game_time > blt->time + BULLET_STEP_DURATION ) {
            blt->time = game_time;

            x = blt->x;
            y = blt->y;

            // Make sure that coordinates will stay within map boundaries after moving.
            if( blt->dir == DIR_LEFT ) {
                if( x > MAP_X * 8 )
                    x--;
            } else if( blt->dir == DIR_RIGHT ) {
                if( x < ( MAP_X + MAP_W ) * 8 - 16 )
                    x++;
            } else if( blt->dir == DIR_UP ) {
                if( y > MAP_Y * 8 )
                    y--;
            } else if( blt->dir == DIR_DOWN ) {
                if( y < ( MAP_Y + MAP_H ) * 8 - 16 )
                    y++;
            }

            tl = &map[ ( ( y + 4 ) / 8 ) * MAP_WIDTH + ( ( x + 4 ) / 8 ) ];
			tr = &map[ ( ( y + 4 ) / 8 ) * MAP_WIDTH + ( ( x + 11 ) / 8 ) ];
			bl = &map[ ( ( y + 11 ) / 8 ) * MAP_WIDTH + ( ( x + 4 ) / 8 ) ];
			br = &map[ ( ( y + 11 ) / 8 ) * MAP_WIDTH + ( ( x + 15 ) / 8 ) ];

            if( blt->x != x || blt->y != y ) {
            	if( blt == &tank1.bullet ) {
					if( hitbox( x, y, tank_ai.x, tank_ai.y, 16, 16 ) == b_true ) {
						game_result = RES_VICTORY;
						return;
					} else if ( hitbox( x, y, BASE_X, BASE_Y, 16, 16 ) == b_true ) {
						game_result = RES_LOSS;
						return;
					}
            	} else {
					if( hitbox( x, y, tank1.x, tank1.y, 16, 16 ) == b_true ) {
						game_result = RES_LOSS;
						return;
					}
            	}

                if( tl->ptr == IMG_8x8_BRICK || tl->ptr == IMG_8x8_IRON ) {
                	if( tl->ptr == IMG_8x8_BRICK ) {
                		tl->ptr = IMG_8x8_NULL;
                    	tl->update = b_true;
                	}

                    blt->explosion = b_true;
                    blt->time = game_time;

                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), (unsigned int)0x8F000000 | (unsigned int)IMG_16x16_EXPLOSION );
                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
                } else if( tr->ptr == IMG_8x8_BRICK || tr->ptr == IMG_8x8_IRON ) {
                	if( tr->ptr == IMG_8x8_BRICK ) {
                		tr->ptr = IMG_8x8_NULL;
                    	tr->update = b_true;
                	}

                    blt->explosion = b_true;
                    blt->time = game_time;

                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), (unsigned int)0x8F000000 | (unsigned int)IMG_16x16_EXPLOSION );
                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
                } else if( bl->ptr == IMG_8x8_BRICK || bl->ptr == IMG_8x8_IRON ) {
                	if( bl->ptr == IMG_8x8_BRICK ) {
                		bl->ptr = IMG_8x8_NULL;
                    	bl->update = b_true;
                	}

                    blt->explosion = b_true;
                    blt->time = game_time;

                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), (unsigned int)0x8F000000 | (unsigned int)IMG_16x16_EXPLOSION );
                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
                } else if( br->ptr == IMG_8x8_BRICK || br->ptr == IMG_8x8_IRON ) {
                	if( br->ptr == IMG_8x8_BRICK ) {
                		br->ptr = IMG_8x8_NULL;
                    	br->update = b_true;
                	}

                    blt->explosion = b_true;
                    blt->time = game_time;

                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), (unsigned int)0x8F000000 | (unsigned int)IMG_16x16_EXPLOSION );
                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
                }
                 else {
                    blt->x = x;
                    blt->y = y;

                    Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_h ), ( blt->y << 16 ) | blt->x );
                }
            } else {
                blt->enabled = b_false;
                Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + blt->reg_l ), 0x0F000000 );
            }
        }
    }
}

static void process_ai( tank_t * tank, unsigned int * ai_dir )
{
	unsigned int	tmp_dir;
	bool_t			turn;
	bool_t			fire;
	unsigned int	i;

	if( game_time % 300 == 0 ) {
		turn = b_true;
	} else {
		turn = b_false;
	}

	if( turn == b_true ) {
		do {
			while( tmp_dir == *ai_dir ) {
				tmp_dir = rand_lfsr113( ) % 4;
			}

			*ai_dir = tmp_dir;
		} while( tank_move( map1, &tank_ai, *ai_dir ) == b_false );
	} else {
		while( tank_move( map1, &tank_ai, *ai_dir ) == b_false ) {
			while( tmp_dir == *ai_dir ) {
				tmp_dir = rand_lfsr113( ) % 4;
			}

			*ai_dir = tmp_dir;
		}
	}

	i = 0;
	fire = b_false;

	if( *ai_dir == DIR_DOWN ) {
		while( tank->y / 8 + i < MAP_Y + MAP_H ) {
			if( map1[ ( tank->y / 8 + i ) * MAP_WIDTH + tank->x / 8 ].ptr == IMG_8x8_BRICK ||
				map1[ ( tank->y / 8 + i ) * MAP_WIDTH + tank->x / 8 ].ptr == IMG_8x8_IRON ) {
				break;
			} else if( hitbox( tank->x, tank->y + i * 8, tank1.x, tank1.y, 16, 16 ) == b_true ) {
				fire = b_true;
				break;
			}

			i++;
		}
	} else if( *ai_dir == DIR_UP ) {
		while( tank->y / 8 - i > MAP_Y ) {
			if( map1[ ( tank->y / 8 - i ) * MAP_WIDTH + tank->x / 8 ].ptr == IMG_8x8_BRICK ||
				map1[ ( tank->y / 8 - i ) * MAP_WIDTH + tank->x / 8 ].ptr == IMG_8x8_IRON ) {
				fire = b_false;
				break;
			} else if( hitbox( tank->x, tank->y - i * 8, tank1.x, tank1.y, 16, 16 ) == b_true ) {
				fire = b_true;
				break;
			}

			i++;
		}
	}  else if( *ai_dir == DIR_RIGHT ) {
		while( tank->x / 8 + i < MAP_X + MAP_W ) {
			if( map1[ ( tank->y / 8 ) * MAP_WIDTH + tank->x / 8 + i ].ptr == IMG_8x8_BRICK ||
				map1[ ( tank->y / 8 ) * MAP_WIDTH + tank->x / 8 + i ].ptr == IMG_8x8_IRON ) {
				break;
			} else if( hitbox( tank->x + i * 8, tank->y, tank1.x, tank1.y, 16, 16 ) == b_true ) {
				fire = b_true;
				break;
			}

			i++;
		}
	} else if( *ai_dir == DIR_LEFT ) {
		while( tank->x / 8 - i > MAP_X ) {
			if( map1[ ( tank->y / 8 ) * MAP_WIDTH + tank->x / 8 - 1 ].ptr == IMG_8x8_BRICK ||
				map1[ ( tank->y / 8 ) * MAP_WIDTH + tank->x / 8 - 1 ].ptr == IMG_8x8_IRON ) {
				break;
			} else if( hitbox( tank->x - i * 8, tank->y, tank1.x, tank1.y, 16, 16 ) == b_true ) {
				fire = b_true;
				break;
			}

			i++;
		}
	}

	if( fire == b_true ) {
		tank_fire( map1, tank );
	}
}

static void base_spawn( void )
{
	Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + BASE_REG_L ), (unsigned int)0x8F000000 | ( (unsigned int)DIR_UP << 16 ) | (unsigned int)IMG_16x16_BASE_ALIVE );
	Xil_Out32( XPAR_BATTLE_CITY_PERIPH_0_BASEADDR + 4 * ( REGS_BASE_ADDRESS + BASE_REG_H ), ( (unsigned int)( ( MAP_Y + MAP_H - 2 ) * 8 ) << 16 ) | (unsigned int)( ( MAP_X + MAP_W / 2 - 1 ) * 8 ) );
}

void battle_city( void )
{

	unsigned int buttons;
	unsigned int ai_dir;
    unsigned int title[ 10 ] = { _B, _E, _T, _L, _SPACE, _S, _I, _T, _I, _TERM };
    unsigned int game_victory[ 7 ] = { _P, _O, _B, _E, _D, _A, _TERM };
    unsigned int game_loss[ 6 ] = { _P, _O, _R, _A, _Z, _TERM };
label:
    game_time = 0;
    game_result = RES_NONE;
    ai_dir = DIR_RIGHT;

    map_reset( map1 );

    draw_string( 35, 1, title );

    tank_spawn( &tank1 );
    tank_spawn( &tank_ai );

    base_spawn( );

    while( 1 ) {
    	if( game_time % 14 == 0 ) {
            buttons = XIo_In32( XPAR_IO_PERIPH_BASEADDR );

			if( BTN_UP( buttons ) ) {
				tank_move( map1, &tank1, DIR_UP );
			} else if( BTN_DOWN( buttons ) ) {
				tank_move( map1, &tank1, DIR_DOWN );
			}  else if( BTN_LEFT( buttons ) ) {
				tank_move( map1, &tank1, DIR_LEFT );
			} else if( BTN_RIGHT( buttons ) ) {
				tank_move( map1, &tank1, DIR_RIGHT );
			} else if( BTN_SHOOT( buttons ) ) {
				tank_fire( map1, &tank1 );
			}

			process_ai( &tank_ai, &ai_dir );
    	}

    	process_bullet( map1, &tank_ai.bullet );
    	process_bullet( map1, &tank1.bullet );
        map_update( map1 );

        if( game_result == RES_VICTORY ) {
        	draw_string( 1, 4, game_victory );
        	goto label;
        } else if( game_result == RES_LOSS ) {
        	draw_string( 1, 4, game_loss );
        	goto label;
        }

        game_time++;
    }
}

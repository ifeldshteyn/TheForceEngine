#pragma once
//////////////////////////////////////////////////////////////////////
// Wall
// Dark Forces Derived Renderer - Wall functions
//////////////////////////////////////////////////////////////////////
#include <TFE_System/types.h>
#include <TFE_Jedi/Math/core_math.h>

using namespace TFE_Jedi;

struct TextureData;
struct Allocator;
struct RSector;

enum WallDrawFlags
{
	WDF_MIDDLE = 0,
	WDF_TOP = 1,
	WDF_BOT = 2,
	WDF_TOP_AND_BOT = 3,
};

enum WallFlags1
{
	WF1_ADJ_MID_TEX          = FLAG_BIT(0),	// the mid texture is rendered even with adjoin (maskwall)
	WF1_ILLUM_SIGN           = FLAG_BIT(1), // render a sign.
	WF1_FLIP_HORIZ           = FLAG_BIT(2),	// flip texture horizontally.
	WF1_CHANGE_WALL_LIGHT    = FLAG_BIT(3),	// elevator can change wall light
	WF1_TEX_ANCHORED         = FLAG_BIT(4),
	WF1_WALL_MORPHS          = FLAG_BIT(5),
	WF1_SCROLL_TOP_TEX       = FLAG_BIT(6),	// elevator can scroll various textures
	WF1_SCROLL_MID_TEX       = FLAG_BIT(7),
	WF1_SCROLL_BOT_TEX       = FLAG_BIT(8),
	WF1_SCROLL_SIGN_TEX      = FLAG_BIT(9),
	WF1_HIDE_ON_MAP          = FLAG_BIT(10),
	WF1_SHOW_NORMAL_ON_MAP   = FLAG_BIT(11),
	WF1_SIGN_ANCHORED        = FLAG_BIT(12),
	WF1_DAMAGE_WALL          = FLAG_BIT(13), // wall damages player
	WF1_SHOW_AS_LEDGE_ON_MAP = FLAG_BIT(14),
	WF1_SHOW_AS_DOOR_ON_MAP  = FLAG_BIT(15),
};

// WallFlags2 used internally.

enum WallFlags3
{
	WF3_ALWAYS_WALK         = FLAG_BIT(0),
	WF3_SOLID_WALL          = FLAG_BIT(1),
	WF3_PLAYER_WALK_ONLY    = FLAG_BIT(2),	// players can walk through but not enemies.
	WF3_CANNOT_FIRE_THROUGH = FLAG_BIT(3),	// cannot fire through the wall.
};

struct RWall
{
	s32 id;
	JBool seen;
	s32 visible;
	RSector* sector;
	RSector* nextSector;
	RWall* mirrorWall;
	s32 drawFlags;			// see WallDrawFlags
	s32 mirror;				// original mirror id.

	// Vertices (worldspace)
	vec2_fixed* w0;
	vec2_fixed* w1;

	// Vertices (viewspace).
	vec2_fixed* v0;
	vec2_fixed* v1;

	// Textures - pointer-to-pointer so that pointers can be changed by texture animation.
	TextureData* topTex;
	TextureData* midTex;
	TextureData* botTex;
	TextureData** signTex;

	// Wall length in texels.
	fixed16_16 texelLength;

	// Wall heights in texels.
	fixed16_16 topTexelHeight;
	fixed16_16 midTexelHeight;
	fixed16_16 botTexelHeight;

	// Texture Offsets
	vec2_fixed topOffset;
	vec2_fixed midOffset;
	vec2_fixed botOffset;
	vec2_fixed signOffset;

	// Direction and length.
	vec2_fixed wallDir;
	fixed16_16 length;
	// Collision frame, to avoid checking a wall multiple times in the same collision query.
	s32 collisionFrame;

	// Update Frame
	s32 drawFrame;
	
	// INF
	Allocator* infLink;
		
	// Flags
	u32 flags1;
	u32 flags2;
	u32 flags3;

	// Original position 0, used for rotating walls.
	vec2_fixed worldPos0;

	// Lighting
	fixed16_16 wallLight;

	// Wall angle.
	angle14_32 angle;
};

namespace TFE_Jedi
{
	void wall_setupAdjoinDrawFlags(RWall* wall);
	void wall_computeTexelHeights(RWall* wall);
	fixed16_16 wall_computeDirectionVector(RWall* wall);

	void wall_getOpeningHeightRange(RWall* wall, fixed16_16* topRes, fixed16_16* botRes);
}
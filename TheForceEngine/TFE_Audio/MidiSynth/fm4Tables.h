#pragma once
#include <TFE_System/types.h>

namespace TFE_Audio
{
#pragma pack(push)
#pragma pack(1)
	struct TimbreBankOp
	{
		u8 waveEnable;
		u8 level;
		u8 attackDelay;
		u8 sustainRelease;
		u8 waveSelect;
	};
	struct TimbreBank
	{
		union
		{
			struct
			{
				TimbreBankOp op1;
				TimbreBankOp op2;
				u8 feedback;
				u8 centerLevel;
			};
			u8 data[12];
		};
	};
#pragma pack(pop)

	struct fmVelocityAdjust
	{
		s32 offset;
		s32 div;
		s32 mask;
	};

	static TimbreBank s_timbreBanksRight[256] =
	{
		{ /*op1*/0x12, 0xA3, 0x00, 0xCD, 0x30, /*op2*/0x12, 0x8E, 0x4E, 0x8A, 0xF8, /*shared*/0x0E, 0x23 },
		//...
	};
	static TimbreBank s_timbreBanksLeft[256] =
	{
		{ /*op1*/0x12, 0xA6, 0x00, 0xCD, 0x30, /*op2*/0x12, 0x8E, 0x4E, 0x8A, 0xF8, /*shared*/0x0C, 0x23 },
		//...
	};

	static s32 s_fmPitch[256] =
	{
		0x0102, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107, 0x0108,
		0x0109, 0x010A, 0x010B, 0x010C, 0x010D, 0x010E, 0x010F, 0x0110,
		// ...
	};
	static s32 s_fmVelocityMapping[64] =
	{
		0x00, 0x04, 0x07, 0x0b, //... to 0x3f
	};
	static u8 s_fmVoicePitchRight[16] =
	{
		0x2d, 0x29, 0x0d, 0x2d, 0x0d, 0x05, 0x0d, 0x25, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	static u8 s_fmVoicePitchLeft[16] =
	{
		0x05, 0x09, 0x0D, 0x05, 0x01, 0x05, 0x05, 0x09, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	};
	static u8 s_fmTone[] =
	{
		0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0,
		0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0,
		// ...
	};
	static u8 s_fmKeyPitch[128] =
	{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
		0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04,
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
		0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
		0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
	};

	static s32 s_fmPortToRegMappingOp1[] =
	{
		0x00, 0x01, 0x02, 0x08,
		// ...
	};

	static s32 s_fmPortToRegMappingOp2[] =
	{
		0x03, 0x04, 0x05, 0x0b,
		// ...
	};
		
	static fmVelocityAdjust s_fmBankAdjust[28] =
	{
		{ 0x06, 0x00, 0x3f },
		{ 0x09, 0x03, 0xf8 },
		{ 0x06, 0x06, 0xc0 },
		// ...
	};
};
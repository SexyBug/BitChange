#include "cipher.h"

//#include "BitChange.h"
#define SIZE 3000

//
//int main()
//{
//	int i;
//	u8 key[32], iv[16];
//	u32 z[SIZE], LFSR_S[16], FSM_R[2], BRC_X[4];
//	u32 message[125], mslength, mac32, mac64[2], mac128[4];
//	u32 short_message[13], short_mslength;
//
//	memset(key, 0x00, 32);
//	memset(iv, 0x00, 16);
//	memset(z, 0x00, SIZE*sizeof(u32));
//	memset(LFSR_S, 0x00, 16*sizeof(u32));
//	memset(FSM_R, 0x00, 2*sizeof(u32));
//	memset(BRC_X, 0x00, 4*sizeof(u32));
//
//	for (i = 0; i < 32; i++)key[i] = 0x00;
//	for (i = 0; i < 16; i++)iv[i] = 0x00;
//
//	//for (i = 0; i < 32; i++)key[i] = 0xff;
//	//for (i = 0; i < 16; i++)iv[i] = 0xff;
//
//	Initialization(key, iv, LFSR_S, FSM_R, BRC_X);
//	GenerateKeystream(z, SIZE, LFSR_S, FSM_R, BRC_X);
//
//	for (i = 0; i < 20; i++) {
//		printf("%08x,", z[i]);
//		if (((i + 1) % 5) == 0)printf("\n");
//	}
//	printf("\n");
//	printf("%08x\n", z[1999]);
//
//
//	memset(message, 0x0, 125);
//	memset(short_message, 0x0, 13);
//	mslength = 125;
//	short_mslength = 12;
//	mac32 = 0;
//
//	mac64[0] = 0;
//	mac64[1] = 0;
//
//	mac128[0] = 0;
//	mac128[1] = 0;
//	mac128[2] = 0;
//	mac128[3] = 0;
//
//	for(i = 0; i < 12; i++) short_message[i] = 0x00000000;
//	short_message[12] = 0x0000 << 16;
//	Mac_generation32(short_message, short_mslength * 32 + 16, &mac32, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation64(short_message, short_mslength * 32 + 16, mac64, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation128(short_message, short_mslength * 32 + 16, mac128, key, iv, LFSR_S, FSM_R, BRC_X);
//
//	printf("The 32-bit mac for short meaage is %08x\n", mac32);
//	printf("The 64-bit mac for short meaage is %08x %08x\n", mac64[0], mac64[1]);
//	printf("The 128-bit mac for short meaage is %08x %08x %08x %08x\n", mac128[0], mac128[1], mac128[2], mac128[3]);
//
//	printf("-----------------------------\n");
//
//	for (i = 0; i < 125; i++)message[i] = 0x11111111;
//	Mac_generation32(message, mslength * 32, &mac32, key, iv, LFSR_S, FSM_R, BRC_X);
////	Mac_generation32_old(message, mslength * 32, &mac32, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation64(message, mslength * 32, mac64, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation128(message, mslength * 32, mac128, key, iv, LFSR_S, FSM_R, BRC_X);
//
//	printf("The 32-bit mac is %08x\n", mac32);
//	printf("The 64-bit mac is %08x %08x\n", mac64[0], mac64[1]);
//	printf("The 128-bit mac is %08x %08x %08x %08x\n", mac128[0], mac128[1], mac128[2], mac128[3]);
//
//	/*for (i = 0; i < 12; i++)short_message[i] = 0x00000000;
//	short_message[12] = 0x0000 << 16;
//	Mac_generation32(short_message, short_mslength * 32 + 16, &mac32, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation64(short_message, short_mslength * 32 + 16, mac64, key, iv, LFSR_S, FSM_R, BRC_X);
//	Mac_generation128(short_message, short_mslength * 32 + 16, mac128, key, iv, LFSR_S, FSM_R, BRC_X);
//
//	printf("The 32-bit mac for short meaage is %08x\n", mac32);
//	printf("The 64-bit mac for short meaage is %08x %08x\n", mac64[0], mac64[1]);
//	printf("The 128-bit mac for short meaage is %08x %08x %08x %08x\n", mac128[0], mac128[1], mac128[2], mac128[3]);*/
//
//	return(0);
//}

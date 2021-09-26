#include "random.h"

//#define u8 unsigned char
//#define u32 unsigned int

/* the s-boxes */
u8 S0[256] = {
	0x3e, 0x72, 0x5b, 0x47, 0xca, 0xe0, 0x00, 0x33, 0x04, 0xd1, 0x54, 0x98, 0x09, 0xb9, 0x6d, 0xcb,
	0x7b, 0x1b, 0xf9, 0x32, 0xaf, 0x9d, 0x6a, 0xa5, 0xb8, 0x2d, 0xfc, 0x1d, 0x08, 0x53, 0x03, 0x90,
	0x4d, 0x4e, 0x84, 0x99, 0xe4, 0xce, 0xd9, 0x91, 0xdd, 0xb6, 0x85, 0x48, 0x8b, 0x29, 0x6e, 0xac,
	0xcd, 0xc1, 0xf8, 0x1e, 0x73, 0x43, 0x69, 0xc6, 0xb5, 0xbd, 0xfd, 0x39, 0x63, 0x20, 0xd4, 0x38,
	0x76, 0x7d, 0xb2, 0xa7, 0xcf, 0xed, 0x57, 0xc5, 0xf3, 0x2c, 0xbb, 0x14, 0x21, 0x06, 0x55, 0x9b,
	0xe3, 0xef, 0x5e, 0x31, 0x4f, 0x7f, 0x5a, 0xa4, 0x0d, 0x82, 0x51, 0x49, 0x5f, 0xba, 0x58, 0x1c,
	0x4a, 0x16, 0xd5, 0x17, 0xa8, 0x92, 0x24, 0x1f, 0x8c, 0xff, 0xd8, 0xae, 0x2e, 0x01, 0xd3, 0xad,
	0x3b, 0x4b, 0xda, 0x46, 0xeb, 0xc9, 0xde, 0x9a, 0x8f, 0x87, 0xd7, 0x3a, 0x80, 0x6f, 0x2f, 0xc8,
	0xb1, 0xb4, 0x37, 0xf7, 0x0a, 0x22, 0x13, 0x28, 0x7c, 0xcc, 0x3c, 0x89, 0xc7, 0xc3, 0x96, 0x56,
	0x07, 0xbf, 0x7e, 0xf0, 0x0b, 0x2b, 0x97, 0x52, 0x35, 0x41, 0x79, 0x61, 0xa6, 0x4c, 0x10, 0xfe,
	0xbc, 0x26, 0x95, 0x88, 0x8a, 0xb0, 0xa3, 0xfb, 0xc0, 0x18, 0x94, 0xf2, 0xe1, 0xe5, 0xe9, 0x5d,
	0xd0, 0xdc, 0x11, 0x66, 0x64, 0x5c, 0xec, 0x59, 0x42, 0x75, 0x12, 0xf5, 0x74, 0x9c, 0xaa, 0x23,
	0x0e, 0x86, 0xab, 0xbe, 0x2a, 0x02, 0xe7, 0x67, 0xe6, 0x44, 0xa2, 0x6c, 0xc2, 0x93, 0x9f, 0xf1,
	0xf6, 0xfa, 0x36, 0xd2, 0x50, 0x68, 0x9e, 0x62, 0x71, 0x15, 0x3d, 0xd6, 0x40, 0xc4, 0xe2, 0x0f,
	0x8e, 0x83, 0x77, 0x6b, 0x25, 0x05, 0x3f, 0x0c, 0x30, 0xea, 0x70, 0xb7, 0xa1, 0xe8, 0xa9, 0x65,
	0x8d, 0x27, 0x1a, 0xdb, 0x81, 0xb3, 0xa0, 0xf4, 0x45, 0x7a, 0x19, 0xdf, 0xee, 0x78, 0x34, 0x60
};
u8 S1[256] = {
	0x55, 0xc2, 0x63, 0x71, 0x3b, 0xc8, 0x47, 0x86, 0x9f, 0x3c, 0xda, 0x5b, 0x29, 0xaa, 0xfd, 0x77,
	0x8c, 0xc5, 0x94, 0x0c, 0xa6, 0x1a, 0x13, 0x00, 0xe3, 0xa8, 0x16, 0x72, 0x40, 0xf9, 0xf8, 0x42,
	0x44, 0x26, 0x68, 0x96, 0x81, 0xd9, 0x45, 0x3e, 0x10, 0x76, 0xc6, 0xa7, 0x8b, 0x39, 0x43, 0xe1,
	0x3a, 0xb5, 0x56, 0x2a, 0xc0, 0x6d, 0xb3, 0x05, 0x22, 0x66, 0xbf, 0xdc, 0x0b, 0xfa, 0x62, 0x48,
	0xdd, 0x20, 0x11, 0x06, 0x36, 0xc9, 0xc1, 0xcf, 0xf6, 0x27, 0x52, 0xbb, 0x69, 0xf5, 0xd4, 0x87,
	0x7f, 0x84, 0x4c, 0xd2, 0x9c, 0x57, 0xa4, 0xbc, 0x4f, 0x9a, 0xdf, 0xfe, 0xd6, 0x8d, 0x7a, 0xeb,
	0x2b, 0x53, 0xd8, 0x5c, 0xa1, 0x14, 0x17, 0xfb, 0x23, 0xd5, 0x7d, 0x30, 0x67, 0x73, 0x08, 0x09,
	0xee, 0xb7, 0x70, 0x3f, 0x61, 0xb2, 0x19, 0x8e, 0x4e, 0xe5, 0x4b, 0x93, 0x8f, 0x5d, 0xdb, 0xa9,
	0xad, 0xf1, 0xae, 0x2e, 0xcb, 0x0d, 0xfc, 0xf4, 0x2d, 0x46, 0x6e, 0x1d, 0x97, 0xe8, 0xd1, 0xe9,
	0x4d, 0x37, 0xa5, 0x75, 0x5e, 0x83, 0x9e, 0xab, 0x82, 0x9d, 0xb9, 0x1c, 0xe0, 0xcd, 0x49, 0x89,
	0x01, 0xb6, 0xbd, 0x58, 0x24, 0xa2, 0x5f, 0x38, 0x78, 0x99, 0x15, 0x90, 0x50, 0xb8, 0x95, 0xe4,
	0xd0, 0x91, 0xc7, 0xce, 0xed, 0x0f, 0xb4, 0x6f, 0xa0, 0xcc, 0xf0, 0x02, 0x4a, 0x79, 0xc3, 0xde,
	0xa3, 0xef, 0xea, 0x51, 0xe6, 0x6b, 0x18, 0xec, 0x1b, 0x2c, 0x80, 0xf7, 0x74, 0xe7, 0xff, 0x21,
	0x5a, 0x6a, 0x54, 0x1e, 0x41, 0x31, 0x92, 0x35, 0xc4, 0x33, 0x07, 0x0a, 0xba, 0x7e, 0x0e, 0x34,
	0x88, 0xb1, 0x98, 0x7c, 0xf3, 0x3d, 0x60, 0x6c, 0x7b, 0xca, 0xd3, 0x1f, 0x32, 0x65, 0x04, 0x28,
	0x64, 0xbe, 0x85, 0x9b, 0x2f, 0x59, 0x8a, 0xd7, 0xb0, 0x25, 0xac, 0xaf, 0x12, 0x03, 0xe2, 0xf2
};

/* the constants D */
u32 EK_d[16] = {
	0x64, 0x43, 0x7b, 0x2a, 0x11, 0x05, 0x51, 0x42,
	0x1a, 0x31, 0x18, 0x66, 0x14, 0x2e, 0x01, 0x5c
};

u32 EK_d_32[16] = {
	0x64, 0x43, 0x7a, 0x2a, 0x11, 0x05, 0x51, 0x42,
	0x1a, 0x31, 0x18, 0x66, 0x14, 0x2e, 0x01, 0x5c
};

u32 EK_d_64[16] = {
	0x65, 0x43, 0x7b, 0x2a, 0x11, 0x05, 0x51, 0x42,
	0x1a, 0x31, 0x18, 0x66, 0x14, 0x2e, 0x01, 0x5c
};

u32 EK_d_128[16] = {
	0x65, 0x43, 0x7a, 0x2a, 0x11, 0x05, 0x51, 0x42,
	0x1a, 0x31, 0x18, 0x66, 0x14, 0x2e, 0x01, 0x5c
};

/* c = a + b mod (2^31 ¨C 1) */
u32 AddM(u32 a, u32 b)
{
	u32 c = a + b;
	return (c & 0x7FFFFFFF) + (c >> 31);
}


/* LFSR with initialization mode */
#define MulByPow2(x, k) ((((x) << k) | ((x) >> (31 - k))) & 0x7FFFFFFF)
void LFSRWithInitialisationMode(u32 u, u32 *LFSR_S)
{
	u32 f, v;
	f = LFSR_S[0];
	v = MulByPow2(LFSR_S[0], 8);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[4], 20);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[10], 21);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[13], 17);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[15], 15);
	f = AddM(f, v);
	f = AddM(f, u);

	/* update the LFSR state */
	LFSR_S[0] = LFSR_S[1];
	LFSR_S[1] = LFSR_S[2];
	LFSR_S[2] = LFSR_S[3];
	LFSR_S[3] = LFSR_S[4];
	LFSR_S[4] = LFSR_S[5];
	LFSR_S[5] = LFSR_S[6];
	LFSR_S[6] = LFSR_S[7];
	LFSR_S[7] = LFSR_S[8];
	LFSR_S[8] = LFSR_S[9];
	LFSR_S[9] = LFSR_S[10];
	LFSR_S[10] = LFSR_S[11];
	LFSR_S[11] = LFSR_S[12];
	LFSR_S[12] = LFSR_S[13];
	LFSR_S[13] = LFSR_S[14];
	LFSR_S[14] = LFSR_S[15];
	LFSR_S[15] = f;
}


/* LFSR with work mode */
void LFSRWithWorkMode(u32 *LFSR_S)
{
	u32 f, v;
	f = LFSR_S[0];
	v = MulByPow2(LFSR_S[0], 8);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[4], 20);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[10], 21);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[13], 17);
	f = AddM(f, v);
	v = MulByPow2(LFSR_S[15], 15);
	f = AddM(f, v);
	/* update the state */
	LFSR_S[0] = LFSR_S[1];
	LFSR_S[1] = LFSR_S[2];
	LFSR_S[2] = LFSR_S[3];
	LFSR_S[3] = LFSR_S[4];
	LFSR_S[4] = LFSR_S[5];
	LFSR_S[5] = LFSR_S[6];
	LFSR_S[6] = LFSR_S[7];
	LFSR_S[7] = LFSR_S[8];
	LFSR_S[8] = LFSR_S[9];
	LFSR_S[9] = LFSR_S[10];
	LFSR_S[10] = LFSR_S[11];
	LFSR_S[11] = LFSR_S[12];
	LFSR_S[12] = LFSR_S[13];
	LFSR_S[13] = LFSR_S[14];
	LFSR_S[14] = LFSR_S[15];
	LFSR_S[15] = f;
}

/* BitReorganization */
void BitReorganization(u32 *BRC_X, u32 *LFSR_S)
{
	BRC_X[0] = ((LFSR_S[15] & 0x7FFF8000) << 1) | (LFSR_S[14] & 0xFFFF);
	BRC_X[1] = ((LFSR_S[11] & 0xFFFF) << 16) | (LFSR_S[9] >> 15);
	BRC_X[2] = ((LFSR_S[7] & 0xFFFF) << 16) | (LFSR_S[5] >> 15);
	BRC_X[3] = ((LFSR_S[2] & 0xFFFF) << 16) | (LFSR_S[0] >> 15);
}

#define ROT(a, k) (((a) << k) | ((a) >> (32 - k)))
/* L1 */
u32 L1(u32 X)
{
	return (X ^ ROT(X, 2) ^ ROT(X, 10) ^ ROT(X, 18) ^ ROT(X, 24));
}


/* L2 */
u32 L2(u32 X)
{
	return (X ^ ROT(X, 8) ^ ROT(X, 14) ^ ROT(X, 22) ^ ROT(X, 30));
}
#define MAKEU32(a, b, c, d) (((u32)(a) << 24) | ((u32)(b) << 16)| ((u32)(c) << 8) | ((u32)(d)))
/* F */
u32 F(u32 *F_R, u32 *BRC_X)
{
	u32 W, W1, W2, u, v;
	W = (BRC_X[0] ^ F_R[0]) + F_R[1];
	W1 = F_R[0] + BRC_X[1];
	W2 = F_R[1] ^ BRC_X[2];
	u = L1((W1 << 16) | (W2 >> 16));
	v = L2((W2 << 16) | (W1 >> 16));
	F_R[0] = MAKEU32(S0[u >> 24], S1[(u >> 16) & 0xFF],
		S0[(u >> 8) & 0xFF], S1[u & 0xFF]);
	F_R[1] = MAKEU32(S0[v >> 24], S1[(v >> 16) & 0xFF],
		S0[(v >> 8) & 0xFF], S1[v & 0xFF]);
	return W;
}

#define MAKEU31(a, b, c, d) (((u32)(a) << 23) | ((u32)(b) << 16) | ((u32)(c) << 8) | (u32)(d))

/* initialize */
void Initialization(u8* k, u8* iv, u32 *LFSR_S, u32 *F_R, u32 *BRC_X)
{
	u32 w, nCount;

	/* expand key */
	LFSR_S[0] = MAKEU31(k[0], EK_d[0], k[16], k[24]);
	LFSR_S[1] = MAKEU31(k[1], EK_d[1], k[17], k[25]);
	LFSR_S[2] = MAKEU31(k[2], EK_d[2], k[18], k[26]);
	LFSR_S[3] = MAKEU31(k[3], EK_d[3], k[19], k[27]);
	LFSR_S[4] = MAKEU31(k[4], EK_d[4], k[20], k[28]);
	LFSR_S[5] = MAKEU31(k[5], EK_d[5], k[21], k[29]);
	LFSR_S[6] = MAKEU31(k[6], EK_d[6], k[22], k[30]);
	LFSR_S[7] = MAKEU31(k[7], EK_d[7], iv[0], iv[8]);
	LFSR_S[8] = MAKEU31(k[8], EK_d[8], iv[1], iv[9]);
	LFSR_S[9] = MAKEU31(k[9], EK_d[9], iv[2], iv[10]);
	LFSR_S[10] = MAKEU31(k[10], EK_d[10], iv[3], iv[11]);
	LFSR_S[11] = MAKEU31(k[11], EK_d[11], iv[4], iv[12]);
	LFSR_S[12] = MAKEU31(k[12], EK_d[12], iv[5], iv[13]);
	LFSR_S[13] = MAKEU31(k[13], EK_d[13], iv[6], iv[14]);
	LFSR_S[14] = MAKEU31(k[14], EK_d[14], iv[7], iv[15]);
	LFSR_S[15] = MAKEU31(k[15], EK_d[15], k[23], k[31]);

	/* set F_R1 and F_R2 to zero */
	F_R[0] = 0x0;
	F_R[1] = 0x0;
	nCount = 32;
	while (nCount > 0)
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X);
		LFSRWithInitialisationMode(w >> 1, LFSR_S);
		nCount--;
	}
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X); /* discard the output of F */
		LFSRWithWorkMode(LFSR_S);
	}



}

void Initialization_32(u8* k, u8* iv, u32 *LFSR_S, u32 *F_R, u32 *BRC_X)
{
	u32 w, nCount;

	memset(LFSR_S, 0x00, 16 * sizeof(u32));
	memset(F_R, 0x00, 2 * sizeof(u32));
	memset(BRC_X, 0x00, 4 * sizeof(u32));

	/* expand key */
	LFSR_S[0] = MAKEU31(k[0], EK_d_32[0], k[16], k[24]);
	LFSR_S[1] = MAKEU31(k[1], EK_d_32[1], k[17], k[25]);
	LFSR_S[2] = MAKEU31(k[2], EK_d_32[2], k[18], k[26]);
	LFSR_S[3] = MAKEU31(k[3], EK_d_32[3], k[19], k[27]);
	LFSR_S[4] = MAKEU31(k[4], EK_d_32[4], k[20], k[28]);
	LFSR_S[5] = MAKEU31(k[5], EK_d_32[5], k[21], k[29]);
	LFSR_S[6] = MAKEU31(k[6], EK_d_32[6], k[22], k[30]);
	LFSR_S[7] = MAKEU31(k[7], EK_d_32[7], iv[0], iv[8]);
	LFSR_S[8] = MAKEU31(k[8], EK_d_32[8], iv[1], iv[9]);
	LFSR_S[9] = MAKEU31(k[9], EK_d_32[9], iv[2], iv[10]);
	LFSR_S[10] = MAKEU31(k[10], EK_d_32[10], iv[3], iv[11]);
	LFSR_S[11] = MAKEU31(k[11], EK_d_32[11], iv[4], iv[12]);
	LFSR_S[12] = MAKEU31(k[12], EK_d_32[12], iv[5], iv[13]);
	LFSR_S[13] = MAKEU31(k[13], EK_d_32[13], iv[6], iv[14]);
	LFSR_S[14] = MAKEU31(k[14], EK_d_32[14], iv[7], iv[15]);
	LFSR_S[15] = MAKEU31(k[15], EK_d_32[15], k[23], k[31]);

	/*for (w = 0; w < 16; w++)printf("%08x,",LFSR_S[w]);
	printf("\n");*/

	/* set F_R1 and F_R2 to zero */
	F_R[0] = 0x0;
	F_R[1] = 0x0;
	nCount = 32;
	while (nCount > 0)
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X);
		LFSRWithInitialisationMode(w >> 1, LFSR_S);
		nCount--;
	}
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X); /* discard the output of F */
		LFSRWithWorkMode(LFSR_S);
	}
	/*printf("The state after initialization is \n");
	for (w = 0; w < 16; w++)printf("%08x,", LFSR_S[w]);
	printf("\n");*/

}

void Initialization_64(u8* k, u8* iv, u32 *LFSR_S, u32 *F_R, u32 *BRC_X)
{
	u32 w, nCount;

	memset(LFSR_S, 0x00, 16 * sizeof(u32));
	memset(F_R, 0x00, 2 * sizeof(u32));
	memset(BRC_X, 0x00, 4 * sizeof(u32));

	/* expand key */
	LFSR_S[0] = MAKEU31(k[0], EK_d_64[0], k[16], k[24]);
	LFSR_S[1] = MAKEU31(k[1], EK_d_64[1], k[17], k[25]);
	LFSR_S[2] = MAKEU31(k[2], EK_d_64[2], k[18], k[26]);
	LFSR_S[3] = MAKEU31(k[3], EK_d_64[3], k[19], k[27]);
	LFSR_S[4] = MAKEU31(k[4], EK_d_64[4], k[20], k[28]);
	LFSR_S[5] = MAKEU31(k[5], EK_d_64[5], k[21], k[29]);
	LFSR_S[6] = MAKEU31(k[6], EK_d_64[6], k[22], k[30]);
	LFSR_S[7] = MAKEU31(k[7], EK_d_64[7], iv[0], iv[8]);
	LFSR_S[8] = MAKEU31(k[8], EK_d_64[8], iv[1], iv[9]);
	LFSR_S[9] = MAKEU31(k[9], EK_d_64[9], iv[2], iv[10]);
	LFSR_S[10] = MAKEU31(k[10], EK_d_64[10], iv[3], iv[11]);
	LFSR_S[11] = MAKEU31(k[11], EK_d_64[11], iv[4], iv[12]);
	LFSR_S[12] = MAKEU31(k[12], EK_d_64[12], iv[5], iv[13]);
	LFSR_S[13] = MAKEU31(k[13], EK_d_64[13], iv[6], iv[14]);
	LFSR_S[14] = MAKEU31(k[14], EK_d_64[14], iv[7], iv[15]);
	LFSR_S[15] = MAKEU31(k[15], EK_d_64[15], k[23], k[31]);

	/* set F_R1 and F_R2 to zero */
	F_R[0] = 0x0;
	F_R[1] = 0x0;
	nCount = 32;
	while (nCount > 0)
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X);
		LFSRWithInitialisationMode(w >> 1, LFSR_S);
		nCount--;
	}
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X); /* discard the output of F */
		LFSRWithWorkMode(LFSR_S);
	}
}

void Initialization_128(u8* k, u8* iv, u32 *LFSR_S, u32 *F_R, u32 *BRC_X)
{
	u32 w, nCount;

	memset(LFSR_S, 0x00, 16 * sizeof(u32));
	memset(F_R, 0x00, 2 * sizeof(u32));
	memset(BRC_X, 0x00, 4 * sizeof(u32));

	/* expand key */
	LFSR_S[0] = MAKEU31(k[0], EK_d_128[0], k[16], k[24]);
	LFSR_S[1] = MAKEU31(k[1], EK_d_128[1], k[17], k[25]);
	LFSR_S[2] = MAKEU31(k[2], EK_d_128[2], k[18], k[26]);
	LFSR_S[3] = MAKEU31(k[3], EK_d_128[3], k[19], k[27]);
	LFSR_S[4] = MAKEU31(k[4], EK_d_128[4], k[20], k[28]);
	LFSR_S[5] = MAKEU31(k[5], EK_d_128[5], k[21], k[29]);
	LFSR_S[6] = MAKEU31(k[6], EK_d_128[6], k[22], k[30]);
	LFSR_S[7] = MAKEU31(k[7], EK_d_128[7], iv[0], iv[8]);
	LFSR_S[8] = MAKEU31(k[8], EK_d_128[8], iv[1], iv[9]);
	LFSR_S[9] = MAKEU31(k[9], EK_d_128[9], iv[2], iv[10]);
	LFSR_S[10] = MAKEU31(k[10], EK_d_128[10], iv[3], iv[11]);
	LFSR_S[11] = MAKEU31(k[11], EK_d_128[11], iv[4], iv[12]);
	LFSR_S[12] = MAKEU31(k[12], EK_d_128[12], iv[5], iv[13]);
	LFSR_S[13] = MAKEU31(k[13], EK_d_128[13], iv[6], iv[14]);
	LFSR_S[14] = MAKEU31(k[14], EK_d_128[14], iv[7], iv[15]);
	LFSR_S[15] = MAKEU31(k[15], EK_d_128[15], k[23], k[31]);

	/* set F_R1 and F_R2 to zero */
	F_R[0] = 0x0;
	F_R[1] = 0x0;
	nCount = 32;
	while (nCount > 0)
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X);
		LFSRWithInitialisationMode(w >> 1, LFSR_S);
		nCount--;
	}
	{
		BitReorganization(BRC_X, LFSR_S);
		w = F(F_R, BRC_X); /* discard the output of F */
		LFSRWithWorkMode(LFSR_S);
	}
}

void GenerateKeystream(u32* Keystream, int KeystreamLen, u32 *LFSR_S, u32 *F_R, u32 *BRC_X)
{
	int i;
	u32 w;

	for (i = 0; i < KeystreamLen; i++)
	{
		BitReorganization(BRC_X, LFSR_S);
		Keystream[i] = F(F_R, BRC_X) ^ BRC_X[3];
		LFSRWithWorkMode(LFSR_S);
	}
}


u32 Get_word32(u32 *data, u32 i)
{
	u32 word, ti;

	word = 0;
	ti = i & 0x1f;

	if (ti == 0)word = data[i / 32];
	else{
		word = ((data[i / 32] << ti) | data[i / 32 + 1] >> (32 - ti));
	}
	return word;
}



u8 get_bit(u32 *data, u32 i)
{
	return (data[i / 32] & (1 << (31 - (i & 0x1f)))) ? 1 : 0;
}



void Mac_generation32(u32 *message, u32 mslength, u32 *mac, u8 *key, u8 *iv, u32 *LFSR_S, u32 *FSM_R, u32 *BRC_X)
{
	u32 N = 0, L = 0, T = 0, i;
	u32 *keystr;
	clock_t start, finish;
	double duration, speed;
	unsigned long ii;

	N = mslength + 64;
	L = (N + 31) / 32;


	keystr = NULL;
	keystr = (u32 *)calloc(L, sizeof(u32));
	if (keystr == NULL){
		printf("error in calloc in Mac_generation32\n");
	}

	Initialization_32(key, iv, LFSR_S, FSM_R, BRC_X);
	GenerateKeystream(keystr, L, LFSR_S, FSM_R, BRC_X);


	T = keystr[0];
	for (i = 0; i < mslength; i++){
		if (get_bit(message, i)){
			T ^= Get_word32(keystr + 1, i);
		}
	}

	T ^= Get_word32(keystr + 1, mslength);
	*mac = T;

	free(keystr);
}

void Mac_generation32_old(u32 *message, u32 mslength, u32 *mac, u8 *key, u8 *iv, u32 *LFSR_S, u32 *FSM_R, u32 *BRC_X)
{
	u32 N = 0, L = 0, T = 0, i;
	u32 *keystr;
	clock_t start, finish;
	double duration, speed;
	unsigned long ii;

	N = mslength + 64;
	L = (N + 31) / 32;


	keystr = NULL;
	keystr = (u32 *)calloc(L, sizeof(u32));
	if (keystr == NULL){
		printf("error in calloc in Mac_generation32\n");
	}

	Initialization_32(key, iv, LFSR_S, FSM_R, BRC_X);
	GenerateKeystream(keystr, L, LFSR_S, FSM_R, BRC_X);

	start = clock();
	for (ii = 0; ii < 4000000; ii++){
		T = 0;
		for (i = 0; i < mslength; i++){
			if (get_bit(message, i)){
				T ^= Get_word32(keystr, i);
			}
		}
		T ^= Get_word32(keystr, mslength);
		*mac = T ^ keystr[L - 1];
	}

	finish = clock();
	duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
	speed = duration*3.4 * 1000 * 1000 * 1000 / (((double)ii) * 4 * mslength);  /* 3.4*1000*1000*1000 indicates a 3.4GHz CPU */

	/*print out the speed*/
	printf("\n\nThe encryption takes %4.20f seconds.\nThe encryption speed is %3.20f cycles/byte \n", duration, speed);
	free(keystr);
}

void Mac_generation64(u32 *message, u32 mslength, u32 *mac, u8 *key, u8 *iv, u32 *LFSR_S, u32 *FSM_R, u32 *BRC_X)
{
	u32 N = 0, L = 0, T[2], i;
	u32 *keystr;

	T[0] = 0;
	T[1] = 0;

	N = mslength + 64 * 2;
	L = (N + 31) / 32;


	keystr = NULL;
	keystr = (u32 *)calloc(L, sizeof(u32));
	if (keystr == NULL){
		printf("error in calloc in Mac_generation64\n");
	}


	Initialization_64(key, iv, LFSR_S, FSM_R, BRC_X);
	GenerateKeystream(keystr, L, LFSR_S, FSM_R, BRC_X);

	T[0] = keystr[0];
	T[1] = keystr[1];
	for (i = 0; i < mslength; i++){
		if (get_bit(message, i)){
			T[0] ^= Get_word32(keystr + 2, i);
			T[1] ^= Get_word32(keystr + 2 + 1, i);
		}
	}

	T[0] ^= Get_word32(keystr + 2, mslength);
	T[1] ^= Get_word32(keystr + 2 + 1, mslength);

	mac[0] = T[0];
	mac[1] = T[1];
	free(keystr);
}


void Mac_generation128(u32 *message, u32 mslength, u32 *mac, u8 *key, u8 *iv, u32 *LFSR_S, u32 *FSM_R, u32 *BRC_X)
{
	u32 N = 0, L = 0, T[4], i;
	u32 *keystr;

	T[0] = 0;
	T[1] = 0;
	T[2] = 0;
	T[3] = 0;

	N = mslength + 64 * 4;
	L = (N + 31) / 32;


	keystr = NULL;
	keystr = (u32 *)calloc(L, sizeof(u32));
	if (keystr == NULL){
		printf("error in calloc in Mac_generation128\n");
	}


	Initialization_128(key, iv, LFSR_S, FSM_R, BRC_X);
	GenerateKeystream(keystr, L, LFSR_S, FSM_R, BRC_X);

	T[0] = keystr[0];
	T[1] = keystr[1];
	T[2] = keystr[2];
	T[3] = keystr[3];
	for (i = 0; i < mslength; i++){
		if (get_bit(message, i)){
			T[0] ^= Get_word32(keystr + 4, i);
			T[1] ^= Get_word32(keystr + 4 + 1, i);
			T[2] ^= Get_word32(keystr + 4 + 2, i);
			T[3] ^= Get_word32(keystr + 4 + 3, i);
		}
	}


	T[0] ^= Get_word32(keystr + 4, mslength);
	T[1] ^= Get_word32(keystr + 4 + 1, mslength);
	T[2] ^= Get_word32(keystr + 4 + 2, mslength);
	T[3] ^= Get_word32(keystr + 4 + 3, mslength);

	mac[0] = T[0];
	mac[1] = T[1];
	mac[2] = T[2];
	mac[3] = T[3];

	free(keystr);
}

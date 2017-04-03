#ifndef _STDTYPES_INC_H
#define _STDTYPES_INC_H
#include <stdint.h>
#endif
#ifndef _PSX_TYPES_H
#define _PSX_TYPES_H

struct TCB {
	long status;
	long mode;
	unsigned long reg[40];
	long system[6];
};

struct EXEC {
	unsigned long pc0;
	unsigned long gp0;
	unsigned long t_addr;
	unsigned long t_size;
	unsigned long d_addr;
	unsigned long d_size;
	unsigned long b_addr;
	unsigned long b_size;
	unsigned long s_addr;
	unsigned long s_size;
	unsigned long sp;
	unsigned long fp;
	unsigned long gp;
	unsigned long ret;
	unsigned long base;
};

struct DIRENTRY {
	char name[20];
	long attr;
	long size;
	struct DIRENTRY* next;
	long head;
	char system[4];
};

struct MATRIX {
	short m[3][3];
	long t[3];
};

struct VECTOR {
	long vx;
	long vy;
	long vz;
	long pad;
};

struct SVECTOR {
	short vx;
	short vy;
	short vz;
	short pad;
};

struct CVECTOR {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char cd;
};

struct DVECTOR {
	short vx;
	short vy;
};

struct RVECTOR {
	struct SVECTOR v;
	unsigned char uv[2];
	unsigned short pad;
	struct CVECTOR c;
	struct DVECTOR sxy;
	unsigned long sz;
};

struct CRVECTOR3 {
	struct RVECTOR r01;
	struct RVECTOR r12;
	struct RVECTOR r20;
	struct RVECTOR* r0;
	struct RVECTOR* r1;
	struct RVECTOR* r2;
	unsigned long* rtn;
};

struct CRVECTOR4 {
	struct RVECTOR r01;
	struct RVECTOR r02;
	struct RVECTOR r31;
	struct RVECTOR r32;
	struct RVECTOR rc;
	struct RVECTOR *r0;
	struct RVECTOR* r1;
	struct RVECTOR* r2;
	struct RVECTOR* r3;
	unsigned long * rtn;
};

struct RECT {
	short x;
	short y;
	short w;
	short h;
};

struct DR_ENV {
	unsigned long tag;
	unsigned long code[];
};

#endif 
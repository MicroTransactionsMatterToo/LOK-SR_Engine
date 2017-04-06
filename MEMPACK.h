// Copyrgith Ennis Massey 6/04/17
//
// Created by Ennis Massey on 6/04/17.
//

#ifndef KAINRECONSTRUCTION_MEMPACK_H
#define KAINRECONSTRUCTION_MEMPACK_H

typedef struct MemHeader {
    unsigned short magicNumber;
    unsigned char memStatus;
    unsigned char memType;
    unsigned long memSize;
} MemHeader;

#endif //KAINRECONSTRUCTION_MEMPACK_H

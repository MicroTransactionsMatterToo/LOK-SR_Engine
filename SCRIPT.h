// Copyrgith Ennis Massey 4/04/17
//
// Created by Ennis Massey on 4/04/17.
//

#ifndef KAINRECONSTRUCTION_SCRIPT_H
#define KAINRECONSTRUCTION_SCRIPT_H


typedef struct ScriptPCode {
    unsigned short sizeOfPcodeStream;
    unsigned short conditionBits;
    double data;
} ScriptPCode;

#endif //KAINRECONSTRUCTION_SCRIPT_H

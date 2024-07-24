//
// Created by Naman Anand on 24/07/24.
//

#ifndef RUBIKCUBE_H
#define RUBIKCUBE_H
#include <bits/stdc++.h>

using namespace std;

class RubikCube
{
public:
    enum class COLOR
    {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE
    {
        U,
        UPRIME,
        U2,
        L,
        LPRIME,
        L2,
        F,
        FPRIME,
        F2,
        R,
        RPRIME,
        R2,
        B,
        BPRIME,
        B2,
        D,
        DPRIME,
        D2,
    };

    enum class FACE
    {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    void print();

    vector<MOVE> randomShuffleCube(unsigned times);

    virtual bool isSolved() = 0;

    static char getColorLetter(COLOR color);

    virtual COLOR getColor(FACE face, unsigned row, unsigned col) = 0;

    static string getMove(MOVE move);

    RubikCube &move(MOVE step);

    RubikCube &invert(MOVE step);

    virtual RubikCube &u() = 0;
    virtual RubikCube &uPrime() = 0;
    virtual RubikCube &u2() = 0;

    virtual RubikCube &l() = 0;
    virtual RubikCube &lPrime() = 0;
    virtual RubikCube &l2() = 0;

    virtual RubikCube &f() = 0;
    virtual RubikCube &fPrime() = 0;
    virtual RubikCube &f2() = 0;

    virtual RubikCube &r() = 0;
    virtual RubikCube &rPrime() = 0;
    virtual RubikCube &r2() = 0;

    virtual RubikCube &b() = 0;
    virtual RubikCube &bPrime() = 0;
    virtual RubikCube &b2() = 0;

    virtual RubikCube &d() = 0;
    virtual RubikCube &dPrime() = 0;
    virtual RubikCube &d2() = 0;
};

#endif //RUBIKCUBE_H

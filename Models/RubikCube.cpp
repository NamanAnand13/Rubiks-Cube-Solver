//
// Created by Naman Anand on 24/07/24.
//

#include "RubikCube.h"

char RubikCube::getColorLetter(COLOR color)
{
    switch (color)
    {
    case COLOR::RED:
        return 'R';

    case COLOR::GREEN:
        return 'G';

    case COLOR::BLUE:
        return 'B';

    case COLOR::WHITE:
        return 'W';

    case COLOR::ORANGE:
        return 'O';

    case COLOR::YELLOW:
        return 'Y';
    }
}

void RubikCube::print()
{
    cout << "Rubik Cube : \n\n";

    // UP
    for (int row = 0; row < 3; row++)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << " ";
        }
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::UP, row, col)) << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int row = 0; row < 3; row++)
    {
        // LEFT
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::LEFT, row, col)) << ' ';
        }
        cout << ' ';
        // FRONT
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::FRONT, row, col)) << ' ';
        }
        cout << ' ';
        // RIGHT
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << ' ';
        }
        cout << ' ';
        // BACK
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::BACK, row, col)) << ' ';
        }
        cout << ' ';
        cout << endl;
    }

    cout << endl;
    // DOWN
    for (int row = 0; row < 3; row++)
    {
        for (int i = 0; i < 7; i++)
        {
            cout << " ";
        }
        for (int col = 0; col < 3; col++)
        {
            cout << getColorLetter(getColor(FACE::DOWN, row, col)) << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

string RubikCube::getMove(MOVE move)
{
    switch (move)
    {
    case MOVE::L:
        return "L";
    case MOVE::LPRIME:
        return "L'";
    case MOVE::L2:
        return "L2";
    case MOVE::R:
        return "R";
    case MOVE::RPRIME:
        return "R'";
    case MOVE::R2:
        return "R2";
    case MOVE::U:
        return "U";
    case MOVE::UPRIME:
        return "U'";
    case MOVE::U2:
        return "U2";
    case MOVE::D:
        return "D";
    case MOVE::DPRIME:
        return "D'";
    case MOVE::D2:
        return "D2";
    case MOVE::F:
        return "F";
    case MOVE::FPRIME:
        return "F'";
    case MOVE::F2:
        return "F2";
    case MOVE::B:
        return "B";
    case MOVE::BPRIME:
        return "B'";
    case MOVE::B2:
        return "B2";
    }
}

RubikCube &RubikCube::move(MOVE ind)
{
    switch (ind)
    {
    case MOVE::L:
        return this->l();
    case MOVE::LPRIME:
        return this->lPrime();
    case MOVE::L2:
        return this->l2();
    case MOVE::R:
        return this->r();
    case MOVE::RPRIME:
        return this->rPrime();
    case MOVE::R2:
        return this->r2();
    case MOVE::U:
        return this->u();
    case MOVE::UPRIME:
        return this->uPrime();
    case MOVE::U2:
        return this->u2();
    case MOVE::D:
        return this->d();
    case MOVE::DPRIME:
        return this->dPrime();
    case MOVE::D2:
        return this->d2();
    case MOVE::F:
        return this->f();
    case MOVE::FPRIME:
        return this->fPrime();
    case MOVE::F2:
        return this->f2();
    case MOVE::B:
        return this->b();
    case MOVE::BPRIME:
        return this->bPrime();
    case MOVE::B2:
        return this->b2();
    }
}

vector<RubikCube::MOVE> RubikCube::randomShuffleCube(unsigned times)
{
    vector<MOVE> moves;
    srand(time(0));
    for (int i = 0; i < times; i++)
    {
        int randMove = (rand() % 18);
        // A Cast operator is a unary operator which forces one data type to be converted into another data type.
        moves.push_back(static_cast<MOVE>(randMove));
        this->move(static_cast<MOVE>(randMove)); // static_cast is a compile-time cast.
    }
    return moves;
}

RubikCube &RubikCube::invert(MOVE ind)
{
    switch (ind)
    {
    case MOVE::L:
        return this->lPrime();
    case MOVE::LPRIME:
        return this->l();
    case MOVE::L2:
        return this->l2();
    case MOVE::R:
        return this->rPrime();
    case MOVE::RPRIME:
        return this->r();
    case MOVE::R2:
        return this->r2();
    case MOVE::U:
        return this->uPrime();
    case MOVE::UPRIME:
        return this->u();
    case MOVE::U2:
        return this->u2();
    case MOVE::D:
        return this->dPrime();
    case MOVE::DPRIME:
        return this->d();
    case MOVE::D2:
        return this->d2();
    case MOVE::F:
        return this->fPrime();
    case MOVE::FPRIME:
        return this->f();
    case MOVE::F2:
        return this->f2();
    case MOVE::B:
        return this->bPrime();
    case MOVE::BPRIME:
        return this->b();
    case MOVE::B2:
        return this->b2();
    }
}
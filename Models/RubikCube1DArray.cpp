//
// Created by Naman Anand on 24/07/24.
//
#include "RubikCube.h"

class RubikCube1DArray : public RubikCube
{
private:
    static inline int getIndex(int face, int row, int col)
    {
        return ((face * 9) + (row * 3) + col);
    }

    void rotateFace(int face)
    {
        char temp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = cube[getIndex(face, i, j)];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cube[getIndex(face, j, 2 - i)] = temp[i][j];
            }
        }
    }

public:
    char cube[54];

    RubikCube1DArray()
    {
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    cube[face * 9 + row * 3 + col] = getColorLetter(COLOR(face));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) override
    {
        char color = cube[getIndex(int(face), row, col)];
        switch (color)
        {
        case 'W':
            return COLOR::WHITE;
        case 'G':
            return COLOR::GREEN;
        case 'R':
            return COLOR::RED;
        case 'B':
            return COLOR::BLUE;
        case 'O':
            return COLOR::ORANGE;
        case 'Y':
            return COLOR::YELLOW;
        }
    }

    bool isSolved()
    {
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (this->cube[getIndex(face, row, col)] == getColorLetter(COLOR(face)))
                        continue;
                    return false;
                }
            }
        }
        return true;
    }

    RubikCube& u() override
    {
        this->rotateFace(0);

        char temp_arr[3];
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(3, 0, 2 - i)] = temp_arr[i];

        return *this;
    }

    RubikCube& uPrime() override
    {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubikCube& u2() override
    {
        this->u();
        this->u();

        return *this;
    }

    RubikCube& l() override
    {
        this->rotateFace(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(0, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(2, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube& lPrime() override
    {
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubikCube& l2() override
    {
        this->l();
        this->l();

        return *this;
    }

    RubikCube& f() override
    {
        this->rotateFace(2);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(0, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(3, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube& fPrime() override
    {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubikCube& f2() override
    {
        this->f();
        this->f();

        return *this;
    }

    RubikCube& r() override
    {
        this->rotateFace(3);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(0, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(4, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube& rPrime() override
    {
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubikCube& r2() override
    {
        this->r();
        this->r();

        return *this;
    }

    RubikCube& b() override
    {
        this->rotateFace(4);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(0, 0, 2 - i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(1, i, 0)] = temp_arr[i];

        return *this;
    }

    RubikCube& bPrime() override
    {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubikCube& b2() override
    {
        this->b();
        this->b();

        return *this;
    }

    RubikCube& d() override
    {
        this->rotateFace(5);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++)
            temp_arr[i] = cube[getIndex(2, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
        for (int i = 0; i < 3; i++)
            cube[getIndex(3, 2, i)] = temp_arr[i];

        return *this;
    }

    RubikCube& dPrime() override
    {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubikCube& d2() override
    {
        this->d();
        this->d();

        return *this;
    }

    RubikCube1DArray& operator=(RubikCube1DArray& state)
    {
        for (int i = 0; i < 54; i++)
        {
            cube[i] = state.cube[i];
        }
        return *this;
    }

    bool operator==(RubikCube1DArray& state)
    {
        for (int i = 0; i < 54; i++)
        {
            if (cube[i] != state.cube[i])return false;
        }
        return true;
    }
};

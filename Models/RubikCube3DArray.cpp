//
// Created by Naman Anand on 24/07/24.
//

#include "RubikCube.h"

class RubikCube3DArray : public RubikCube
{
private:
    void rotateFace(int face)
    {
        char temp[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp[i][j] = cube[face][i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cube[face][j][2 - i] = temp[i][j];
            }
        }
    }

public:
    char cube[6][3][3];

    RubikCube3DArray()
    {
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    cube[face][row][col] = getColorLetter(COLOR(face));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) override
    {
        char color = cube[int(face)][row][col];
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
                    if (this->cube[face][row][col] == getColorLetter(COLOR(face)))
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

        char temp[3] = {};
        for (int i = 0; i < 3; i++)
            temp[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[3][0][2 - i] = temp[i];

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

        char temp[3] = {};
        for (int i = 0; i < 3; i++)
            temp[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++)
            cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++)
            cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++)
            cube[2][i][0] = temp[i];

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
        rotateFace(2);
        char temp[3];
        for (int i = 0; i < 3; i++)
            temp[i] = cube[0][2][i]; // copied 2nd row of top to temp
        // Update
        for (int i = 0; i < 3; i++)
            cube[0][2][i] = cube[1][2 - i][2]; // update 2nd row of top to 2nd col of left
        for (int i = 0; i < 3; i++)
            cube[1][i][2] = cube[5][0][i]; // update 2nd col of left to 1st row of down
        for (int i = 0; i < 3; i++)
            cube[5][0][i] = cube[3][2 - i][0]; // update 1st row of down to 1st col of right
        for (int i = 0; i < 3; i++)
            cube[3][i][0] = temp[i]; // update 1st col of right to 2nd row of top
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

        char temp[3] = {};
        for (int i = 0; i < 3; i++)
            temp[i] = cube[0][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[0][2 - i][2] = cube[2][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[2][2 - i][2] = cube[5][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[5][2 - i][2] = cube[4][i][0];
        for (int i = 0; i < 3; i++)
            cube[4][i][0] = temp[i];

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

        char temp[3] = {};
        for (int i = 0; i < 3; i++)
            temp[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++)
            cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++)
            cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++)
            cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++)
            cube[1][i][0] = temp[i];

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

        char temp[3] = {};
        for (int i = 0; i < 3; i++)
            temp[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++)
            cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++)
            cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++)
            cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++)
            cube[3][2][i] = temp[i];

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

    bool operator==(RubikCube3DArray& state)
    {
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    if (state.cube[face][row][col] != cube[face][row][col])return false;
                }
            }
        }
        return true;
    }

    RubikCube3DArray& operator=(const RubikCube3DArray& state)
    {
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    cube[face][row][col] = state.cube[face][row][col];
                }
            }
        }
        return *this;
    }
};

struct Hash3D
{
    size_t operator()(const RubikCube3DArray& state) const
    {
        string s;
        for (int face = 0; face < 6; face++)
        {
            for (int row = 0; row < 3; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    s += state.cube[face][row][col];
                }
            }
        }
        return hash<string>()(s);
    }
};

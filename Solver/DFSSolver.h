//
// Created by Naman Anand on 25/07/24.
//

#ifndef DFSSOLVER_H
#define DFSSOLVER_H
#include <vector>

#include "../Models/RubikCube.h"

template <typename T, typename H>
class DFSSolver
{
private:
    int maxDepth;
    vector<RubikCube::MOVE> moves;

    bool dfs(int dep)
    {
        if (rubikCube.isSolved()) return true;
        if (dep > maxDepth)return false;

        for (int i = 0; i < 18; i++)
        {
            rubikCube.move(RubikCube::MOVE(i));
            moves.push_back(RubikCube::MOVE(i));
            if (dfs(dep + 1))return true;
            moves.pop_back();
            rubikCube.invert(RubikCube::MOVE(i));
        }
        return false;
    }

public:
    T rubikCube;

    DFSSolver(T _rubikCube, int _maxDepth)
    {
        rubikCube = _rubikCube;
        maxDepth = _maxDepth;
    }

    std::vector<RubikCube::MOVE> solve()
    {
        dfs(1);
        return moves;
    }
};

#endif //DFSSOLVER_H

//
// Created by Naman Anand on 25/07/24.
//

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H

#include <vector>

#include "DFSSolver.h"
#include "../Models/RubikCube.h"

template <typename T, typename H>
class IDDFSSolver
{
private:
    std::vector<RubikCube::MOVE> moves;

public:
    T rubikCube;
    int maxDepth;

    IDDFSSolver(T _rubikCube, int _maxDepth)
    {
        rubikCube = _rubikCube;
        maxDepth = _maxDepth;
    }

    vector<RubikCube::MOVE> solve()
    {
        for (int i = 1; i <= maxDepth; i++)
        {
            DFSSolver<T, H> DFSSolver(rubikCube, i);
            moves = DFSSolver.solve();
            if (DFSSolver.rubikCube.isSolved())
            {
                rubikCube = DFSSolver.rubikCube;
                break;
            }
        }
        return moves;
    }
};


#endif //IDDFSSOLVER_H

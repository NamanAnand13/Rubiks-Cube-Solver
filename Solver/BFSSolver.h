//
// Created by Naman Anand on 25/07/24.
//

#ifndef BFSSOLVER_H
#define BFSSOLVER_H
#include <bits/stdc++.h>
#include "../Models/RubikCube.h"

template <typename T, typename H>
class BFSSolver
{
private:
    vector<RubikCube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, RubikCube::MOVE, H> step;

    T bfs()
    {
        queue<T> q;
        q.push(rubikCube);
        visited[rubikCube] = true;
        long long i = 0;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << i++ << " ";
            if (node.isSolved())
                return node;
            for (int i = 0; i < 18; i++)
            {
                RubikCube::MOVE currMove = RubikCube::MOVE(i);
                node.move(currMove);
                if (!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                    step[node] = currMove;
                }
                node.invert(currMove);
            }
        }
        return rubikCube;
    }

public:
    T rubikCube;

    BFSSolver(T _rubikCube)
    {
        rubikCube = _rubikCube;
    }

    vector<RubikCube::MOVE> solve()
    {
        T solvedCube = bfs();
        // assert(solvedCube.isSolved());
        //The expression inside the assert statement is evaluated, and if the expression evaluates to false,
        //an AssertionError (or similar) is thrown, and the program may terminate
        T currCube = solvedCube;
        while (!(currCube == rubikCube))
        {
            RubikCube::MOVE move = step[currCube];
            moves.push_back(move);
            currCube.invert(move);
        }
        rubikCube = solvedCube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif //BFSSOLVER_H

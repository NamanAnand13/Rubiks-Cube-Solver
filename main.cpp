#include <iostream>
#include "Models/RubikCube3DArray.cpp"
#include "Models/RubikCube1DArray.cpp"
#include "Solver/BFSSolver.h"
#include "Solver/DFSSolver.h"
#include "Solver/IDDFSSolver.h"

int main()
{
    // std::cout << "Hello, World!" << std::endl;
    // RubikCube3DArray object3DArray;
    // RubikCube1DArray object1dArray;
    // object3DArray.print();
    // object1dArray.print();
    // object1dArray.rotateFace(0);
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    //
    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    objectBitboard.u();
    // object3DArray.u();
    // object1dArray.u();
    //    objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();

    //    objectBitboard.l();
    // object3DArray.l();
    // object1dArray.l();
    //    objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();
    //
    //    objectBitboard.f();
    // object3DArray.f();
    // object1dArray.f();
    //    objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();
    //
    //    objectBitboard.r();
    // object3DArray.r();
    // object1dArray.r();
    //    objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();
    //
    //    objectBitboard.b();
    //    object3DArray.b();
    //    object1dArray.b();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.d();
    //    object3DArray.d();
    //    object1dArray.d();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    //
    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    objectBitboard.dPrime();
    //    object3DArray.dPrime();
    //    object1dArray.dPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.bPrime();
    //    object3DArray.bPrime();
    //    object1dArray.bPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.rPrime();
    //    object3DArray.rPrime();
    //    object1dArray.rPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.fPrime();
    //    object3DArray.fPrime();
    //    object1dArray.fPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.lPrime();
    //    object3DArray.lPrime();
    //    object1dArray.lPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.uPrime();
    //    object3DArray.uPrime();
    //    object1dArray.uPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";

    // Create two Cubes ------------------------------------------------------------------------------------------

    // RubikCube3DArray cube1;
    // RubikCube3DArray cube2;

    // RubikCube1DArray cube1;
    // RubikCube1DArray cube2;

    //    RubiksCubeBitboard cube1;
    //    RubiksCubeBitboard cube2;


    //  Equality and assignment of cubes --------------------------------------------------------------------------

    //     if(cube1 == cube2) cout << "Is equal\n";
    //     else cout << "Not Equal\n";
    // //
    //     cube1.randomShuffleCube(1);
    // //
    //     if(cube1 == cube2) cout << "Is equal\n";
    //     else cout << "Not Equal\n";
    // //
    //     cube2 = cube1;
    // //
    //     if(cube1 == cube2) cout << "Is equal\n";
    //     else cout << "Not Equal\n";


    //  Unordered_map of Cubes  ------------------------------------------------------------------------------------


    // unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

    //    unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

    //    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
    //
    //    mp1[cube1] = true;
    //    cube2.randomShuffleCube(8);
    //    if (mp1[cube1]) cout << "Cube1 is present\n";
    //    else cout << "Cube1 is not present\n";
    //
    //    if (mp1[cube2]) cout << "Cube2 is present\n";
    //    else cout << "Cube2 is not present\n";
    //

    // DFS Solver Testing __________________________________________________________________________________________
    // RubikCube3DArray cube;
    // cube.print();

    // vector<RubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    // for (auto move : shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();

    // DFSSolver<RubikCube3DArray, Hash3D> dfsSolver(cube, 10);
    // dfsSolver.solve();
    // vector<RubikCube::MOVE> solve_moves = dfsSolver.solve();

    // DFSSolver<>
    // for (auto move : solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubikCube.print();
    // cube.print();


    //BFS Solver -----------------------------------------------------------------------------------------------------
    // RubikCube1DArray cube;
    // cube.print();
    //
    // vector<RubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(20);
    // for (auto move : shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    // //
    // BFSSolver<RubikCube1DArray, Hash1D> bfsSolver(cube);
    // vector<RubikCube::MOVE> solve_moves = bfsSolver.solve();
    // //
    // for (auto move : solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubikCube.print();

    // IDDFS Solver ----------------------------------------------------------------------------------------------------
    RubikCube1DArray cube;
    cube.print();

    vector<RubikCube::MOVE> shuffle_moves = cube.randomShuffleCube(8);
    for (auto move : shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    IDDFSSolver<RubikCube1DArray, Hash1D> iddfsSolver(cube, 10);
    vector<RubikCube::MOVE> solve_moves = iddfsSolver.solve();

    for (auto move : solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubikCube.print();

    // IDA* SOLVER ---------------------------------------------------------------------------------------------------
    //    RubiksCubeBitboard cube;
    //    cube.print();
    //
    //    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    //    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    //    cout << "\n";
    //    cube.print();
    //
    //    IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube);
    //    vector<RubiksCube::MOVE> solve_moves = idAstarSolver.solve();
    //    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    //    cout << "\n";
    //    idAstarSolver.rubiksCube.print();

    // CornerPatternDatabase Testing ---------------------------------------------------------------------------------

    //    CornerPatternDatabase cornerDB;
    //    RubiksCubeBitboard cube;
    //    cube.print();
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cornerDB.setNumMoves(cube, 5);
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cube.randomShuffleCube(1);
    //    cube.print();
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    //    cornerDB.setNumMoves(cube, 6);
    //
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";
    return 0;
}

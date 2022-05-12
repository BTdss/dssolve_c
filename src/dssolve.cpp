#include "dssolve.h"
#include <complex>
#include <Eigen/Sparse>
#include <Eigen/SparseLU>
#include <vector>
#include <iostream>


typedef std::complex<double> cdouble;
typedef Eigen::Triplet<cdouble> T;
void solve(cmplx *values, unsigned int *rows, unsigned int *cols, cmplx *b, unsigned int size)
{
    auto n = size;
    Eigen::SparseMatrix<cdouble> M(n, n);
    std::vector<T> triplets;
    triplets.reserve(n);
    Eigen::VectorXcd c(n);
    Eigen::VectorXcd x(n);
    Eigen::SparseLU<Eigen::SparseMatrix<cdouble>> solver;
    double real, imag;
    cdouble value;
    unsigned int row, col;

    for (unsigned int i = 0; i < n; i++)
    {
        real = (values + i)->real; 
        imag = (values + i)->imag;
        value = cdouble(real, imag);
        row = *(rows + i);
        col = *(cols + i);
        triplets.push_back(T(row, col, value));

        real = (values + i)->real; 
        imag = (values + i)->imag;
        value = cdouble(real, imag);
        c[i] = value;
    }

    M.setFromTriplets(triplets.begin(), triplets.end());

    // solver.compute(M);
    // x = solver.solve(c);

    for (unsigned int i = 0; i < n; i++)
    {
        real = x[i].real(); 
        imag = x[i].imag();
        (b + i)->real = real;
        (b + i)->imag = imag;
    }
}
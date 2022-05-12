#include "dssolve.h"
#include <complex>
#include <Eigen/Sparse>
#include <Eigen/SparseLU>
#include <vector>
#include <iostream>

typedef std::complex<double> cdouble;
typedef Eigen::Triplet<cdouble> T;

void solve(cmplx values[], unsigned int rows[], unsigned int cols[], unsigned int n_value, cmplx b[], unsigned int size)
{
    Eigen::SparseMatrix<cdouble> A(size, size);
    A.reserve(n_value);

    std::vector<T> triplets;
    triplets.reserve(n_value);

    Eigen::VectorXcd b_(size);
    Eigen::VectorXcd x(size);

    Eigen::SparseLU<Eigen::SparseMatrix<cdouble>> solver;

    double real, imag;
    cdouble value;
    unsigned int row, col, i;

    for (i = 0; i < n_value; i++)
    {
        real = (values + i)->real;
        imag = (values + i)->imag;
        value = cdouble(real, imag);
        row = *(rows + i);
        col = *(cols + i);
        triplets.push_back(T(row, col, value));
    }

    for (i = 0; i < size; i++)
    {

        real = (b + i)->real;
        imag = (b + i)->imag;
        value = cdouble(real, imag);
        b_[i] = value;
    }

    A.setFromTriplets(triplets.begin(), triplets.end());

    solver.compute(A);
    x = solver.solve(b_);

    for (unsigned int i = 0; i < size; i++)
    {
        real = x[i].real();
        imag = x[i].imag();
        (b + i)->real = real;
        (b + i)->imag = imag;
    }
}
/******************************************************
Title:			matrix.cpp
Author:			Jeong Yang
Date Created:	2/15/2018
Class:			CSCI 335 Spring 2018
Professor:		Ioannis Stamos
Purpose:		Assignment #1
Description:	Implementation file for the Matrix Class
******************************************************/
#ifndef __MATRIX_CPP_
#define __MATRIX_CPP_

#include "matrix.h"
using namespace linear_algebra_project;

//big five
//default constructor
template<typename Object>
Matrix<Object>::Matrix(){

    num_rows_ = 0;
    num_columns_ = 0;
    array_ = nullptr;
}

//Copy Constructor , new matrix is a deep copy of another
template<typename Object>
Matrix<Object>::Matrix(const Matrix<Object>& rhs){

    num_rows_ = 0;
    num_columns_ = 0;
    array_ = nullptr;

    //deep copy of this
    *this = rhs;
}

//Copy Assignment, this becomes a deep copy of rhs
template<typename Object>
Matrix<Object>& Matrix<Object>::operator=(const Matrix<Object>& rhs){

    if(num_rows_ > 0){
    Clear();
  }
    num_rows_ = rhs.num_rows_;
    num_columns_ = rhs.num_columns_;

    array_ = new Object*[num_rows_];
    for(unsigned int i = 0; i < num_rows_ ; i++){

        array_[i] = new Object[num_columns_];
    }

    //filling array appropriately
    for(unsigned int i = 0; i < num_rows_; i++){

        for(unsigned int j = 0; j < num_columns_; j++){

            array_[i][j] = rhs.array_[i][j];
        }
    }
    return *this;
}

//Move constructor , new matrix takes new data and empties it
template<typename Object>
Matrix<Object>::Matrix(Matrix<Object>&& rhs){

    num_rows_ = 0;
    num_columns_ = 0;
    array_ = nullptr;

    //Shallow copy , no deep
    *this = std::move(rhs);
}

//Move Assignment, new matrix takes rhs data and empties it
template<typename Object>
Matrix<Object>& Matrix<Object>::operator=(Matrix<Object>&& rhs){


    //Shallow copy
    num_rows_ = rhs.num_rows_;
    num_columns_ = rhs.num_columns_;
    array_ = rhs.array_;

    //empties rhs
    rhs.num_rows_ = 0;
    rhs.num_columns_ = 0;
    rhs.array_ = nullptr;

    return *this;
}


//destructor
template<typename Object>
Matrix<Object>::~Matrix(){

    if(array_ != nullptr){
      Clear();
    }
}

//Clear is called by only the destructor , sets the matrix empty and point
//current array to nullptr
template<typename Object>
void Matrix<Object>::Clear(){

    for(unsigned int i = 0; i < num_rows_; i++){

        delete[] array_[i];
    }

    delete[] array_;
    num_rows_ = 0;
    num_columns_ = 0;
    array_ = nullptr;

}

//ReadMatrix, Matrix is filled with user input
template<typename Object>
void Matrix<Object>::ReadMatrix(){

    Clear();

    size_t Rows;
    size_t Columns;

    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> Rows;

    std::cout << "Enter the number of columns for the matrix: ";
    std::cin >> Columns;

    std::cout << std::endl;


    num_rows_ = Rows;
    num_columns_ = Columns;

    array_ = new Object*[num_rows_];
    //initializing
    for(unsigned int i = 0; i < Rows; i++){

        array_[i] = new Object[num_columns_];
    }
    //filling
    Object InputValue;
    for(unsigned int i = 0; i < num_rows_; i++){

        for(unsigned int j = 0; j < num_columns_; j++){

            std::cin >> InputValue;
            array_[i][j] = InputValue;
        }
    }
}

//Returning the copy of the vector
template<typename Object>
std::vector<Object> Matrix<Object>::operator[](int row) const{


    std::vector<Object> os;
    for(unsigned int i = 0; i < NumCols(); i++){

        os.push_back(array_[row-1][i]);
    }

    return os;
}
//operator + for two matrices
template<typename Object>
Matrix<Object> Matrix<Object>::operator+(const Matrix<Object>& b_matrix){

    Matrix<Object> MyMatrix(*this);

    for(unsigned int i = 0; i < num_rows_; i++){
        for(unsigned int j = 0; j < num_columns_; j++){

            MyMatrix.array_[i][j] = MyMatrix.array_[i][j] + b_matrix.array_[i][j];

        }
    }
    return MyMatrix;
}




#endif

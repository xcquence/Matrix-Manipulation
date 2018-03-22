// A simple basic implementation of a Matrix class

#ifndef TEACH_CSCI335_MATRIX_H_
#define TEACH_CSCI335_MATRIX_H_

#include <iostream>


// Make it a habit to use namespaces for your code.
namespace linear_algebra_project {

// Templated implementation of Matrix
// Sample usage:
//   Matrix<int> a;
//   a.ReadMatrix();
//   cout << a_matrix.NumRows() << endl;
//   cout << a_matrix.NumCols() << endl;
//   cout << a;
//   Matrix<int> b;
//   b.ReadMatrix();
//   cout << a + b;
template <typename Object>
class Matrix {
 public:
  Matrix();
  Matrix(const Matrix &rhs);
  Matrix& operator=(const Matrix &rhs);
  Matrix(Matrix &&rhs);
  Matrix& operator=(Matrix &&rhs);
  ~Matrix();


  void ReadMatrix();
  // @row: an index to a row of the matrix.
  // @returns the row as a vector of items. No error checking.
  // const version.
  std::vector<Object>  operator[](int row) const;



  Matrix operator+(const Matrix &b_matrix);
  //Operator + for two matrices dealing with string.
  Matrix operator+(const Object &an_object){

    std::string str(an_object);
    Matrix<Object> MyMatrix(*this);

    for(unsigned int i = 0; i < num_rows_; i++ ){

        for(unsigned int j = 0; j < num_columns_; j++){

            MyMatrix.array_[i][j] = MyMatrix.array_[i][j] + str;
        }
    }
    return MyMatrix;
  }

 // @returns number of rows.
  size_t NumRows() const { return num_rows_; }
  // @returns number of columns.
  size_t NumCols() const { return num_columns_; }
  //Getters for row and Columns
  Object& getRowsandColumns(int row, int column) const {
      return array_[row][column];
  }

 // Overloading the << operator. Handles the inserstion operator
 friend std::ostream &operator<<(std::ostream &out, const Matrix &a_matrix) {



   for(unsigned int i = 0; i < a_matrix.NumRows(); i++){

      for(unsigned int j = 0; j < a_matrix.NumCols(); j++){

          out << a_matrix.getRowsandColumns(i,j) << " " ;

      }
      out << std::endl;
   }

   return out;
 }

 //additional helper functions to destruct matrix called by destructor
 void Clear();

 private:
 size_t num_columns_;
 size_t num_rows_;
 Object **array_;

};

}  // namespace linear_algebra_project

#include "matrix.cpp"
#endif  // TEACH_CSCI335_MATRIX_H

#include "assignment/matrix2d.hpp"

namespace assignment {

  Matrix2x2 matrix_multiply(const Matrix2x2& left, const Matrix2x2& right) {

    Matrix2x2 res;

    // вычисляем значения на первой строке
    res[0][0] = left[0][0] * right[0][0] + left[0][1] * right[1][0];
    res[0][1] = left[0][0] * right[0][1] + left[0][1] * right[1][1];

    // вычисляем значения на второй строке
    res[1][0] = left[1][0] * right[0][0] + left[1][1] * right[1][0];
    res[1][1] = left[1][0] * right[0][1] + left[1][1] * right[1][1];

    return res;
  }

  Matrix2x2 matrix_power(Matrix2x2 matrix, int power) {

    if (power <= 2) {
      Matrix2x2 res;
      res = IdentityMatrix;
      if (power == 2){
        return matrix_multiply(res, res);
      }// единичная матрица
      return res;
    }
    if (power % 2 == 1){
      return matrix_multiply(matrix_power(matrix, power - 1),matrix);
    }
    return matrix_multiply(matrix_power(matrix, power/2), matrix_power(matrix,power / 2));
    /*while (power != 0) {


    }*/
  }

}  // namespace assignment
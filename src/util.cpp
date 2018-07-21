#include <util.h>
#include <stdio.h>

double** computeTransformationMatrix(double angle, double l)
{
  double** t = new double*[4];
  double s = sin(angle);
  double c = cos(angle);
  for (int i = 0; i < 4; ++i) {
    t[i] = new double[4];
  }
  t[0][0] = c;
  t[0][1] = -s;
  t[1][0] = s;
  t[1][1] = c;
  t[2][2] = 1;
  t[3][3] = 1;
  t[0][3] = c*l;
  t[1][3] = s*l;
  return t;
}

double* matrixVector(double** a, double* b)
{
  double* res = new double[4];
  for (int i = 0; i < 4; ++i) {
    for (int k = 0; k < 4; ++k) {
      res[i] += a[i][k] * b[k];      
    }
  }
  return res;
}

double** multiplyMatrices(double** a, double** b)
{
  double** res = new double*[4];
  for (int i = 0; i < 4; ++i) {
    res[i] = new double[4];
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        res[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return res;
}

void printMatrix(double** a)
{
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      printf("%1.4f\t", a[i][j]);
    }
    printf("\n");
  }
}


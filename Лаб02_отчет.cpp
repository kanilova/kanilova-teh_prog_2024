#include "Лаб02"

int main() {

  // Демонстрация работы с векторами
  double *data1 = new double[3];
  double *data2 = new double[3];

  for (int i = 0; i < 3; i++) {
    data1[i] = i + 1;
    data2[i] = (i + 1) * 2;
  }
  vect v1(3, data1);
  vect v2(3, data2);

  cout << "vectors:" << endl;
  v1.print();
  v2.print();

  vect v3 = v1 + v2;
  vect v4 = v1 - v2;
  vect v5 = -v1;
  double scalar_product = v1 * v2;
  vect v6 = v1 * 3.0;
  vect v7 = 2.0 * v2;

  cout << "After operations:" << endl;
  v3.print();
  v4.print();
  v5.print();
  cout << "Scalar product of v1 and v2: " << scalar_product << endl; // v1 * v2
  v6.print();
  v7.print();

  // Демонстрация работы с матрицами

  double **data3 = new double *[3];
  double **data4 = new double *[3];

  for (int i = 0; i < 3; i++) {
    data3[i] = new double[3];
    data4[i] = new double[3];
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      data3[i][j] = i + j + 1;
      data4[i][j] = (i + j + 1) * 2;
    }
  }

  matr m1(3, data3);
  matr m2(3, data4);

  cout << "matrices:" << endl;
  m1.print();
  m2.print();

  matr m3 = m1 + m2;
  matr m4 = m1 - m2;
  matr m5 = -m1;
  matr m6 = m1 * m2;
  matr m7 = m1 * 3.0;
  matr m8 = 2.0 * m2;
  vect mv = m1 * v1;

  cout << "After operations:" << endl;
  m3.print();
  m4.print();
  m5.print();
  m6.print();
  m7.print();
  m8.print();
  mv.print();

  cout << "Vectors total: " << vect::getCount() << endl;
  cout << "Matrices total: " << matr::getCount() << endl;

  for (int i = 0; i < 3; i++) {
      delete[] data3[i];
      delete[] data4[i];
  }

  delete[] data3;
  delete[] data4;
  delete[] data1;
  delete[] data2;

  return 0;
}

#include <iostream>
using namespace std;

class matr;

class vect {
private:
  int dim;          // размерность
  double *b;        // динамический массив
  int num;          // номер объекта
  static int count; // количество объектов класса

public:
  // Конструкторы
  vect(int dim) : dim(dim), num(count++) {
    b = new double[dim];
    cout << "Vector constructor called for object " << num << endl;
  }

  vect(int dim, const double *values) : dim(dim), num(count++) {
    b = new double[dim];
    for (int i = 0; i < dim; i++) {
      b[i] = values[i];
    }
    cout << "Vector constructor with values called for object " << num << endl;
  }

  // Конструктор копирования
  vect(const vect &other) : dim(other.dim), num(count++) {
    b = new double[dim];
    cout << "Vector copy constructor called for object " << num << endl;
  }

  // Деструктор
  ~vect() {
    delete[] b;
    cout << "Vector destructor called for object " << num << endl;
  }

  friend class matr;

  // Операторы
  vect operator+(const vect &other);   // v + v
  vect operator-(const vect &other);   // v - v
  vect operator-();                    // -v
  double operator*(const vect &other); // v * v (scalar)
  vect operator*(double k);            // k * v
  vect &operator=(const vect &other);  // v = v

  // Дружественные функции
  friend vect operator*(double k, vect &v); // k * v

  // Статический метод для получения количества объектов
  static int getCount() { return count; }

  // Метод для печати вектора
  void print() const {
    cout << "Vector " << num << ": (";
    for (int i = 0; i < dim; i++) {
      cout << b[i];
      if (i < dim - 1)
        cout << ", ";
    }
    cout << ")" << endl;
  }
};

int vect::count = 0; // Инициализация статической переменной

class matr {
private:
  int dim;          // размерность
  double **b;       // двумерный динамический массив
  int num;          // номер объекта
  static int count; // количество объектов класса

public:
  // Конструктор
  matr(int dim) : dim(dim), num(count++) {
    b = new double *[dim];
    for (int i = 0; i < dim; i++) {
      b[i] = new double[dim];
    }
    cout << "Matrix constructor called for object " << num << endl;
  }

  matr(int dim, const double *const *values) : dim(dim), num(count++) {
    b = new double *[dim];
    for (int i = 0; i < dim; ++i) {
      b[i] = new double[dim];
      for (int j = 0; j < dim; ++j) {
        b[i][j] = values[i][j];
      }
    }
    cout << "Matrix constructor with values called for object " << num << endl;
  }

  // Конструктор копирования
  matr(const matr &other) : dim(other.dim), num(count++) {
    b = new double *[dim];
    for (int i = 0; i < dim; i++) {
      b[i] = new double[dim];
      // Копирование данных из другого объекта
      for (int j = 0; j < dim; j++) {
        b[i][j] = other.b[i][j];
      }
    }
    cout << "Matrix copy constructor called for object " << num << endl;
  }

  // Деструктор
  ~matr() {
    for (int i = 0; i < dim; i++) {
      delete[] b[i];
    }
    delete[] b;
    cout << "Matrix destructor called for object " << num << endl;
  }

  // Операторы
  matr operator+(const matr &other);  // m + m
  matr operator-(const matr &other);  // m - m
  matr operator-();                   // -m
  matr operator*(const matr &other);  // m * m
  matr operator*(double k);           // k * m
  matr &operator=(const matr &other); // m = m
  vect operator*(const vect &v);      // m * v

  // Дружественные функции
  friend matr operator*(double k, matr &m); // k * m

  // Статический метод для получения количества объектов
  static int getCount() { return count; }

  // Метод для печати матрицы
  void print() const {
    cout << "Matrix " << num << ":" << endl;
    for (int i = 0; i < dim; i++) {
      cout << "| ";
      for (int j = 0; j < dim; j++) {
        cout << b[i][j];
        if (j < dim - 1)
          cout << ", ";
      }
      cout << " |" << endl;
    }
  }
};

int matr::count = 0; // Инициализация статической переменной

vect operator*(double k, vect &v) {
  return v * k; // Используем уже определенный оператор умножения в классе vect
}

matr operator*(double k, matr &m) {
  return m * k; // Используем уже определенный оператор умножения в классе matr
}

// Оператор сложения векторов
vect vect::operator+(const vect &other) {
  if (dim != other.dim)
    exit(1);
  vect result(dim);
  for (int i = 0; i < dim; i++) {
    result.b[i] = b[i] + other.b[i];
  }
  return result;
}

// Оператор вычитания векторов
vect vect::operator-(const vect &other) {
  if (dim != other.dim)
    exit(1);
  vect result(dim);
  for (int i = 0; i < dim; i++) {
    result.b[i] = b[i] - other.b[i];
  }
  return result;
}

// Унарный оператор минус (смена знака вектора)
vect vect::operator-() {
  vect result(dim);
  for (int i = 0; i < dim; i++) {
    result.b[i] = -b[i];
  }
  return result;
}

// Оператор скалярного произведения векторов
double vect::operator*(const vect &other) {
  if (dim != other.dim)
    exit(1);
  double result = 0.0;
  for (int i = 0; i < dim; i++) {
    result += b[i] * other.b[i];
  }
  return result;
}

// Оператор умножения вектора на скаляр
vect vect::operator*(double k) {
  vect result(dim);
  for (int i = 0; i < dim; i++) {
    result.b[i] = b[i] * k;
  }
  return result;
}

// Оператор присваивания
vect &vect::operator=(const vect &other) {
  if (this != &other) { // Защита от самоприсваивания
    if (dim != other.dim) {
      delete[] b; // Освобождаем старую память
      dim = other.dim;
      b = new double[dim]; // Выделяем память для нового размера
    }
    for (int i = 0; i < dim; i++) {
      b[i] = other.b[i];
    }
  }
  return *this;
}

// Оператор сложения матриц
matr matr::operator+(const matr &other) {
  matr result(dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      result.b[i][j] = b[i][j] + other.b[i][j];
    }
  }
  return result;
}

// Оператор вычитания матриц
matr matr::operator-(const matr &other) {
  matr result(dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      result.b[i][j] = b[i][j] - other.b[i][j];
    }
  }
  return result;
}

// Унарный оператор минус (смена знака всех элементов матрицы)
matr matr::operator-() {
  matr result(dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      result.b[i][j] = -b[i][j];
    }
  }
  return result;
}

// Оператор умножения матриц
matr matr::operator*(const matr &other) {
  matr result(dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      result.b[i][j] = 0;
      for (int k = 0; k < dim; k++) {
        result.b[i][j] += b[i][k] * other.b[k][j];
      }
    }
  }
  return result;
}

// Оператор умножения матрицы на скаляр
matr matr::operator*(double k) {
  matr result(dim);
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      result.b[i][j] = b[i][j] * k;
    }
  }
  return result;
}

// Оператор присваивания
matr &matr::operator=(const matr &other) {
  if (this == &other) {
    return *this;
  }

  // Очищаем текущую матрицу
  for (int i = 0; i < dim; i++) {
    delete[] b[i];
  }
  delete[] b;

  // Копируем размерность и данные из другой матрицы
  dim = other.dim;
  b = new double *[dim];
  for (int i = 0; i < dim; i++) {
    b[i] = new double[dim];
    for (int j = 0; j < dim; j++) {
      b[i][j] = other.b[i][j];
    }
  }
  return *this;
}

// Оператор умножения матрицы на вектор
vect matr::operator*(const vect &v) {
  vect result(dim);
  for (int i = 0; i < dim; i++) {
    result.b[i] = 0;
    for (int j = 0; j < dim; j++) {
      result.b[i] += b[i][j] * v.b[j];
    }
  }
  return result;
}
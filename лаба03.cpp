#include <iostream>
#include <cmath>
using namespace std;

class point {
public:
    int x;
    int y;
    char z[100][100];
private:
    void  izobr();
    void  ubr();
    void  peredvin();
    void  pover();
};
class line : public point {

public:
    void izobr() {
        cout << "#";
    }
    void ubr() {
        cout << " ";
    }
    void peredvin(int x) {
        for (int i = 0;i < x;i++) {
            cout << " ";
        }
        cout << "#";
    }
    void pover() {
        cout << "Линия повернута" << endl;
    }
};
int s;
char square[5][5];

class kvad : public line {
public:
    void izobr() {
        const int size = 5;
        s = size;
        // Заполняем матрицу символами квадрата
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                    square[i][j] = '#';
                }
                else {
                    square[i][j] = ' ';
                }
            }
        }

        // Выводим на экран квадрат, представленный матрицей
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }


    }
    void ubr() {

        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                square[i][j] = ' ';
            }
        }
        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                cout << square[i][j];
            }
            cout << endl;
        }

    }
    void peredvin(int x) {
        const int size = 5;
        if (square[0][0] == ' ') {
            ubr();
        }
        else {
            // Заполняем матрицу символами квадрата
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                        square[i][j] = '#';
                    }
                    else {
                        square[i][j] = ' ';
                    }
                }
            }

            // Выводим на экран квадрат, представленный матрицей
            for (int i = 0; i < size; i++) {
                for (int i = 0;i < x;i++) {
                    cout << " ";
                }
                for (int j = 0; j < size; j++) {
                    cout << square[i][j] << " ";
                }
                cout << endl;
            }


        }



    };
    void pover() {
        cout << "Квадрат повернут" << endl;
    }
};

class romb : public point {
public:
    void izobr() {
        int n = 5; // размер стороны ромба
        int i, j;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }

        for (i = n - 1; i >= 1; i--) {
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    void ubr() {
        int n = 5; // размер стороны ромба
        int i, j;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                std::cout << " ";
            }
            std::cout << std::endl;
        }

        for (i = n - 1; i >= 1; i--) {
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    void peredvin(int x) {
       
        int n = 5; // размер стороны ромба
        int i, j;
       
        for (i = 1; i <= n; i++) {
           
            for (int i = 0;i < x;i++) {
                cout << " ";
            }
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
           
            for (j = 1; j <= 2 * i - 1; j++) {

                std::cout << "*";
            }

            std::cout << std::endl;
        }

        for (i = n - 1; i >= 1; i--) {
            for (int i = 0;i < x;i++) {
                cout << " ";
            }
            for (j = 1; j <= n - i; j++) {
                std::cout << " ";
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    void pover() {
        cout << "Ромб повернут" << endl;
    }
};

class prim : public point {
public:
    void izobr() {
        int rows = 5;
        int cols = 10;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    std::cout << "* ";
                }
                else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
    void ubr() {

        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                square[i][j] = ' ';
            }
        }
        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                cout << square[i][j];
            }
            cout << endl;
        }
    }
    void peredvin(int x) {
        int rows = 5;
        int cols = 10;

        for (int i = 0; i < rows; i++) {
            for (int i = 0;i < x;i++) {
                cout << " ";
            }
            for (int j = 0; j < cols; j++) {
               
                if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                    std::cout << "* ";
                }
                else {
                    std::cout << "  ";
                }
            }
            std::cout << std::endl;
        }
    }
    void pover() {
        cout << "прямоугольник повернута" << endl;
    }
};

class par : public virtual kvad {
public:
    void izobr() {
        int height = 5;
        int width = 10;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            for (int k = 0; k < width; k++) {
                cout << "*";
            }
            cout << endl;
        }

    }
    void ubr() {
        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                square[i][j] = ' ';
            }
        }
        for (int i = 0;i < s;i++) {
            for (int j = 0;j < s;j++) {
                cout << square[i][j];
            }
            cout << endl;
        }

    }
    void peredvin(int x) {
        int height = 5;
        int width = 10;

        for (int i = 0; i < height; i++) {
            for (int i = 0;i < x;i++) {
                cout << " ";
            }
            for (int j = 0; j < i; j++) {
                cout << " ";
            }
            for (int k = 0; k < width; k++) {
                cout << "*";
            }
            cout << endl;
        }


    }
    void pover() {
        cout << "параллелепипед повернут" << endl;
    }
};

int main()
{
    point p;
    line l;
    kvad k;
    romb r;
    prim m;
    par a;
    k.izobr();
    k.peredvin(7);
    r.izobr();
    r.ubr();
    r.peredvin(7);
    m.izobr();
    m.peredvin(7);
    a.peredvin(7);

}


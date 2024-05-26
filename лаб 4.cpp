#include <iostream>
using namespace std;
#include <vector>
#include <fstream>// для записи и чтения файла
#include <string>
#include<Windows.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    vector <string>  cars;
    ofstream mark("cars.txt",ios::app);
    ifstream klass("cars.txt");
    int g;
   
    string s;
  

    for (;;) {
        while (getline(klass, s)) {
            cars.push_back(s);
        }
        string ad;

        cout << "press y or n" << endl;
        cin >> ad;
        if (ad == "n") {
            break;
        }
        else {

            int a;
            cout << endl;
            cout << "введите команду:\n1-добавить значение\n2-удалить значение\n3-поменять значение\n4-найти\n5-вывести бд" << endl;
            cin >> a;
            if (a == 1) {
                cout << endl;
                string n;
                cout << "введите знач" << endl;
                cin >> n;
                mark << n << endl;
                cars.push_back(n);

            }
            else if (a == 2) {
                ofstream mark2("cars.txt");

                cout << endl;
                cout << "выберите строку" << endl;
                cin >> g;

                cars.erase(cars.begin() + g - 1);
                for (int i = 0;i < cars.size();i++) {
                    mark2 << cars[i] << endl;
                }

            }
            else if (a == 3) {
                ofstream mark2("cars.txt");

                cout << endl;
                cout << "выберите стрроку чтобы поменять значение" << endl;
                cin >> g;
                string nazvanie;
                cin >> nazvanie;
                cars[g - 1] = nazvanie;
                for (int i = 0;i < cars.size();i++) {
                    mark2 << cars[i] << endl;
                }

            }
            else if (a == 4) {
                cout << endl;
                cout << "введите строку чтобы найти" << endl;
                cin >> g;
                cout << cars[g - 1] << endl;
            }
            else if (a == 5) {
                cout << endl;
                for (int i = 0;i < cars.size();i++) {
                    cout << cars[i] << endl;
                }
            }
        }
    }
}
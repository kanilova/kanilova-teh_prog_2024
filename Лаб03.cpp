#include <iostream>
using namespace std;
class point{
    public: 
    virtual void  izobr()=0;
    virtual void  ubr()=0;
    virtual void  peredvin()=0;
    virtual void  pover()=0;
};
class line: public point {
    public:
    void izobr(){
        cout<<"Линия нарисованна"<<endl;
    }
    void ubr(){
        cout<<"Линия удалена"<<endl;
    }
    void peredvin(){
        cout<<"Линия передвинута"<<endl;
    }
    void pover(){
        cout<<"Линия повернута"<<endl;
    }
};

class kvad: public point {
    public:
    void izobr(){
        cout<<"Квадрат нарисованн"<<endl;
    }
    void ubr(){
        cout<<"Квадрат удален"<<endl;
    }
    void peredvin(){
        cout<<"Квадрат передвинут"<<endl;
    }
    void pover(){
        cout<<"Квадрат повернут"<<endl;
    }
};

class romb: public point {
    public:
    void izobr(){
        cout<<"Ромб нарисованн"<<endl;
    }
    void ubr(){
        cout<<"Ромб удален"<<endl;
    }
    void peredvin(){
        cout<<"Ромб передвинут"<<endl;
    }
    void pover(){
        cout<<"Ромб повернут"<<endl;
    }
};

class prim: public point {
    public:
    void izobr(){
        cout<<" прямоугольник нарисованн"<<endl;
    }
    void ubr(){
        cout<<"прямоугольник удалена"<<endl;
    }
    void peredvin(){
        cout<<"прямоугольник передвинута"<<endl;
    }
    void pover(){
        cout<<"прямоугольник повернута"<<endl;
    }
};

class par: public virtual kvad{
    public:
    void izobr(){
        cout<<"параллелепипед нарисованн"<<endl;
    }
    void ubr(){
        cout<<"параллелепипед удален"<<endl;
    }
    void peredvin(){
        cout<<"параллелепипед передвинут"<<endl;
    }
    void pover(){
        cout<<"параллелепипед повернут"<<endl;
    }
};

int main()
{
  line leo;
  leo.izobr();
  leo.ubr();
  leo.peredvin();
  leo.pover();
  
  kvad kar;
  kar.izobr();
  kar.ubr();
  kar.peredvin();
  kar.pover();
  
  romb rom;
  rom.izobr();
  rom.ubr();
  rom.peredvin();
  rom.pover();
  
  prim prom;
  prom.izobr();
  prom.ubr();
  prom.peredvin();
  prom.pover();
  
  par ptr;
  ptr.izobr();
  ptr.ubr();
  ptr.peredvin();
  ptr.pover();
}

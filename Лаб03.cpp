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
        cout<<"Квадрат нарисованна"<<endl;
    }
    void ubr(){
        cout<<"Квадрат удалена"<<endl;
    }
    void peredvin(){
        cout<<"Квадрат передвинута"<<endl;
    }
    void pover(){
        cout<<"Квадрат повернута"<<endl;
    }
};

class romb: public point {
    public:
    void izobr(){
        cout<<" нарисованна"<<endl;
    }
    void ubr(){
        cout<<"К удалена"<<endl;
    }
    void peredvin(){
        cout<<"т передвинута"<<endl;
    }
    void pover(){
        cout<<" повернута"<<endl;
    }
};

class prim: public point {
    public:
    void izobr(){
        cout<<" нарисованна"<<endl;
    }
    void ubr(){
        cout<<"К удалена"<<endl;
    }
    void peredvin(){
        cout<<"т передвинута"<<endl;
    }
    void pover(){
        cout<<" повернута"<<endl;
    }
};

class par: public virtual kvad{
    public:
    void izobr(){
        cout<<"пар нарисованна"<<endl;
    }
    void ubr(){
        cout<<"пар удалена"<<endl;
    }
    void peredvin(){
        cout<<"пар передвинута"<<endl;
    }
    void pover(){
        cout<<"пар повернута"<<endl;
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

#include <bits/stdc++.h>
using namespace std;

class Hero{
    //properties are by default private
    public: //public,private or protected
    char *name;
    int health;
    char level;
    static int time; //shared among all objects, belongs to class, no need to make object to access
    static int random(){ //static function can only access static variable
        return time;
    }
    int n;
    Hero(){}
    Hero(int n){ //constructor
        this->n=n;
        cout<<"Constructor called"<<endl;
    }
    Hero(int n,int type){ //constructor overloading
        this->n=n;
        this->type=type;
    }
    //copy constructor
    Hero(Hero &temp){
        this->health=temp.health;
        cout<<"Copy constructor called"<<endl;
    }
    //default copy constructor does shallow copy, shared memory for pointers such as name in this case

    //copy constructor for deep copy
    Hero(Hero &temp, char *name){
        char *ch=new char[strlen(temp.name)+1]; //new memory allocated haha
        this->name=ch;
    }
    ~Hero(){ //destructor is going to be called when memory is about to be deallocated
        cout<<"Destructor bhai called"<<endl;
    }
    //destructor is automatically called for static allocation, dynamic one must be deleted manually
    private:
    int type;
    public:
    void settype(int n){
        this->type=n; //this keyword is optional
    }
};

int Hero::time = 89;// This line is necessary for the static variable

int main(){
    cout<<Hero::time<<endl; //accessing static variable
    cout<<Hero::random()<<endl; //accessing static function
    //object created
    Hero ramesh(2);
    cout<<"size: "<<sizeof(ramesh)<<endl;
    ramesh.health=79;
    ramesh.level='X';
    ramesh.settype(1);
    Hero *adi = new Hero(2); //dynamic allocation of class
    adi->health=100;
    adi->level='A';
    adi->settype(2);
    Hero suresh;
    suresh.health=90;
    Hero ritesh(suresh); //copy
    cout<<"Ritesh "<<ritesh.health<<endl;
    Hero rishi;
    Hero arno=rishi; //copy assignment operator, just copy values, similar to copying each attribute one by one using = operator
    delete adi;
    return 0;
}
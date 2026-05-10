#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Person{
protected:
    string firstName;
    string lastName;
    int age;
    string gender;
public:
    Person():age(0) {}
    Person(string f,string l,int a,string g):firstName(f),lastName(l),age(a),gender(g) {}

    void SetData(string f,string l,int a,string g) {
        firstName=f;
        lastName=l;
        age=a;
        gender=g;
    }

    virtual string getFatherName() const {return "不详";}
    virtual string getMotherName() const {return "不详";}

    virtual void Display() {
        cout<<left
            <<setw(8)<<(firstName+lastName)  
            <<setw(6)<<age
            <<setw(6)<<gender
            <<setw(8)<<getFatherName()
            <<setw(8)<<getMotherName()<<endl;
    }
    int getAge() const {return age;}
    string getFullName() const {return firstName+lastName;}

    virtual ~Person()=default;
};

class Father:virtual public Person {
public:
    Father():Person(){}
    Father(string f,string l,int a,string g):Person(f,l,a,g){}
};

class Mother:virtual public Person {
public:
    Mother():Person() {}
    Mother(string f,string l,int a,string g):Person(f,l,a,g) {}
};

class Child:public Father,public Mother{
private:
    string fatherName;
    string motherName;
public:
    Child():Person() {}
    Child(string f,string l,int a,string g,string fa,string mo):Person(f,l,a,g), fatherName(fa), motherName(mo) {}

    void SetData(string f,string l,int a,string g,string fa,string mo) {
        Person::SetData(f,l,a,g);
        fatherName=fa;
        motherName=mo;
    }
    
    string getFatherName() const override {return fatherName;}
    string getMotherName() const override {return motherName;}
};

bool compare(const Person* p1,const Person* p2) {
    return p1->getAge()>p2->getAge();
}

int main() {
    Person* people[6];

    people[0]=new Father("王","军",49,"男");
    people[1]=new Mother("李","丽",47,"女");
    people[2]=new Father("张","语",35,"男");
    people[3]=new Mother("刘","美",32,"女");
    people[4]=new Child("王","仪",17,"女","王军","李丽");
    people[5]=new Child("张","芊",5,"女","张语","刘美");

    sort(people,people+6,compare);

   cout<<left
   		<<setw(8)<<"姓名"
        <<setw(6)<<"年龄"
        <<setw(6)<<"性别"
        <<setw(8)<<"父亲"
        <<setw(8)<<"母亲"<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(int i=0;i<6;++i) {
        people[i]->Display();
    }

    for(int i=0;i<6;++i) {
        delete people[i];
    }

    return 0;
}

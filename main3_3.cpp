#include <iostream>
#include <cstring>
using namespace std;

class CProcess;

class CStudent {
private:
    char Name[20];   
    int Degree;      
    char Level[7];   
public:
    CStudent(const char* name, int degree);
    friend class CProcess;
};

class CProcess {
public:
    void Transform(CStudent &s);
    void Display(CStudent &s);
};

CStudent::CStudent(const char* name, int degree) {
    strcpy(Name,name);
    Degree=degree;
    Level[0]='\0';
}

void CProcess::Transform(CStudent &s) {
    if (s.Degree>=90) {
        strcpy(s.Level,"优秀");} 
	else if (s.Degree>=80) {
        strcpy(s.Level,"良好");} 
	else if (s.Degree>=70) {
        strcpy(s.Level,"中等");} 
	else if (s.Degree>=60) {
        strcpy(s.Level,"及格");} 
	else {
        strcpy(s.Level,"不及格");}
}

void CProcess::Display(CStudent &s) {
    cout<<s.Name<<"\t"<<s.Degree<<"\t"<<s.Level<<endl;
}

int main() {
    cout<<"姓名\t成绩\t等级"<<endl;

    CStudent stu1("Mary",78);
    CStudent stu2("Jack",93);
    CStudent stu3("Mike",54);
    CStudent stu4("John",88);

    CProcess proc;

    proc.Transform(stu1);
    proc.Display(stu1);

    proc.Transform(stu2);
    proc.Display(stu2);

    proc.Transform(stu3);
    proc.Display(stu3);

    proc.Transform(stu4);
    proc.Display(stu4);

    return 0;
}

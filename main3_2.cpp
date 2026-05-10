#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class CStudent{
	public:
		CStudent();
		CStudent(string,int);
		friend void Display(const CStudent &stu); 
	private:
		string Name;
		int Degree;
};
CStudent::CStudent(){
	Name="";
	Degree=0;
}
CStudent::CStudent(string name,int degree){
	Name=name;
	Degree=degree;
}
void Display(const CStudent &stu){
	cout<<stu.Name<<"\t"<<stu.Degree<<"\t";
	if(stu.Degree>=90){
		cout<<"优秀"<<endl;
	}
	else if(stu.Degree>=80&&stu.Degree<=89){
		cout<<"良好"<<endl;
	}
	else if(stu.Degree>=70&&stu.Degree<=79){
		cout<<"中等"<<endl;
	}
	else if(stu.Degree>=60&&stu.Degree<=69){
		cout<<"及格"<<endl;
	}
	else if(stu.Degree<60){
		cout<<"不及格"<<endl;
	}
}
int main(int argc, char *argv[]) {
	int i;
	CStudent stu1[4]={
			CStudent("Mary",78),
			CStudent("Jack",93),
			CStudent("Mike",54),
			CStudent("John",88)
	};
	
	cout<<"姓名\t成绩\t等级"<<endl; 
	for(i=0;i<4;i++){
		Display(stu1[i]);
	}
	return 0;
}

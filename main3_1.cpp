#include <iostream>
#include <iomanip>   
#include <algorithm> 
#include <string>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class CStudent{
	public:
		CStudent();
		CStudent(string,string,int,int,int);
		void SetData();
		void Display();
		double Average(); 
		static int getNum();
		static void showClassSize();      
		friend void sortStu(CStudent[], int);
    	friend void totalScore(CStudent[], int);
	private:
		int DegChi,DegMath,DegEng;
		string Name,No;
		static int Num;
		int rank;
};

int CStudent::Num=0;
 
CStudent::CStudent(){
    No="";
    Name="";
    DegChi=0;
    DegMath=0;
    DegEng=0;
    Num++; 
}

CStudent::CStudent(string no,string name,int chi,int math,int eng){
    No=no;
    Name=name;
    DegChi =chi;
    DegMath =math;
    DegEng =eng;
    Num++;
}

void CStudent::SetData() {
    cout<<"请输入学号："; 
	cin>>No;
    cout<<"请输入姓名："; 
	cin>>Name;
    cout<<"请输入语文成绩："; 
	cin>>DegChi;
    cout<<"请输入数学成绩："; 
	cin>>DegMath;
    cout<<"请输入英语成绩："; 
	cin>>DegEng;
}
void CStudent::Display() {
    cout<<setw(10)<<No
        <<setw(10)<<Name
        <<setw(8)<<DegChi
        <<setw(8)<<DegMath
        <<setw(8)<<DegEng
        <<setw(10)<<Average()
        <<setw(8)<<rank<<endl;
}

double CStudent::Average() {
    return (DegChi+DegMath+DegEng)/3.0; 
}

int CStudent::getNum() {
    return Num;
}

void CStudent::showClassSize() {
    cout<<"\n	==================== 班级信息 ====================	"<<endl;
    cout<<"班级总学生人数："<<Num<<"人"<<endl<<endl;
}

bool compare(CStudent a,CStudent b) {
    return a.Average()>b.Average();
}

void sortStu(CStudent stu[], int n) {
	int i;
    sort(stu,stu+n,compare); 
    for (i=0;i<n;i++) {
        stu[i].rank=i+1; 
    }
}

void totalScore(CStudent stu[], int n) {
	int i;
    double sumChi=0, sumMath=0, sumEng=0, sumAve=0;
    for (i=0;i<n;i++) {
        sumChi+=stu[i].DegChi;
        sumMath+=stu[i].DegMath;
        sumEng+=stu[i].DegEng;
        sumAve+=stu[i].Average();
    }
    cout<<fixed <<setprecision(2); 
    cout<<setw(10)<<"总评"
        <<setw(10)<<""
        <<setw(8)<<sumChi/n
        <<setw(8)<<sumMath/n
        <<setw(8)<<sumEng/n
        <<setw(10)<<sumAve/n<<endl;
}

int main(int argc, char** argv) {
	int i;
	CStudent stu[6] ={
        CStudent("0181109","Phillise",90,90,90),
        CStudent("0181119","Jack",85,85,85),
        CStudent("0181123","Mary",80,85,75),
        CStudent("0181213","Jerry",75,70,80),
        CStudent("0181111","Mike",75,65,70),
        CStudent("0181221","Tom",65,60,55)
    };
    int n=CStudent::getNum(); 
    sortStu(stu,n);            
	CStudent::showClassSize();
	
    cout<<setw(10)<<"学号"
        <<setw(10)<<"姓名"
        <<setw(8)<<"语文"
        <<setw(8)<<"数学"
        <<setw(8)<<"英语"
        <<setw(10)<<"平均分"
        <<setw(8)<<"名次"<<endl;

    for(i=0; i<n;i++) {
        stu[i].Display();
    }

    totalScore(stu, n);
	return 0;
}

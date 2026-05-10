#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Vector{
	public:
		Vector(); //默认构造函数 
		Vector(int a,int b);//带参数构造函数 
		void display();
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		Vector Add(const Vector &ob2);
		Vector Sub(const Vector &ob2);
		int Mult(const Vector &ob2);
	private:
		int x,y;
};

Vector::Vector():x(-1),y(1){
} //默认构造函数
 
Vector::Vector(int a, int b){
	x=a;
	y=b;
}//带参数构造函数 

void Vector::display(){
	cout<<"("<<x<<","<<y<<")"<<endl;
}//输出数据成员函数
 
Vector Vector::Add(const Vector &ob2){
	Vector jieguo;
	jieguo.x=x+ob2.x;
	jieguo.y=y+ob2.y;
	return jieguo;
}

Vector Vector::Sub(const Vector &ob2){
	Vector jieguo;
	jieguo.x=x-ob2.x;
	jieguo.y=y-ob2.y;
	return jieguo;
}

int Vector::Mult(const Vector &ob2){
	return x*ob2.x+y*ob2.y;
}

int main(int argc, char** argv) {
	Vector ob1;
	cout<<"矢量初始化为";
	ob1.display(); //打印初始化后的矢量 
	
	Vector ob2(3,5);//带参数构造函数 
	cout<<"第二个矢量为";
	ob2.display();
	 
	Vector add=ob1.Add(ob2);
    cout<<"相加结果为：";
    add.display();

    Vector sub=ob1.Sub(ob2);
    cout<<"相减结果为：";
    sub.display();

	int cheng=ob1.Mult(ob2);
    cout<<"点乘结果为："<<cheng<<endl;
	return 0;
	
}

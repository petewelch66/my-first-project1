#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Vector{
	public:
		Vector(); //默认构造函数 
		Vector(int a,int b);//带参数构造函数 
		void display();
		int getX(){
			return x;}
		int getY(){
			return y;}
		Vector Add(const Vector &ob2);
		Vector Sub(const Vector &ob2);
		int Mult(const Vector &ob2);
	private:
		int x,y;
};
Vector::Vector():x(-1),y(1){} //默认构造函数
Vector::Vector(int a, int b){
	x=a;
	y=b;}//带参数构造函数 

void Vector::display(){
	cout<<"("<<x<<","<<y<<")"<<endl;}//输出数据成员函数
 
Vector Vector::Add(const Vector &ob2){
	Vector jieguo;
	jieguo.x=x+ob2.x;
	jieguo.y=y+ob2.y;
	return jieguo;}
Vector Vector::Sub(const Vector &ob2){
	Vector jieguo;
	jieguo.x=x-ob2.x;
	jieguo.y=y-ob2.y;
	return jieguo;}
int Vector::Mult(const Vector &ob2){
	return x*ob2.x+y*ob2.y;}

class Matrix{
	public:
	Matrix(Vector xv1,Vector xv2,Vector xv3,Vector xv4);
	void display();
	int get1(){
		return lefttop;}
	int get2(){
		return righttop;}
	int get3(){
		return leftbottom;}
	int get4(){
		return rightbottom;}
	Vector GetVector(int i,int j);
	Matrix Add(const Matrix &ob2);
	Matrix Sub(const Matrix &ob2);
	private:
		Vector lefttop,righttop;leftbottom,rightbottom;
};

Matrix::Matrix(Vector xv1,Vector xv2,Vector xv3,Vector xv4):v1(xv1),v2(xv2),v3(xv3),v4(xv4){
	lefttop=v1;
	righttop=v2;
	leftbottom=v3;
	rightbottom=v4;
}

void Matrix::display(){
	cout<<" |"<<lefttop<<"  "<<righttop<<"|"<<endl;
	cout<<" |"<<leftbottom<<"  "<<rightbottom<<"|"<<endl;
}

Vector Matrix::GetVector(int i,int j){
	if (i==1&&j==1){
		return 
	}
}
int main(int argc, char** argv) {
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

class Vector {
public:
    Vector(); // 默认构造函数 
    Vector(int dimension); // 仅指定维度（分量初始化为0）
    Vector(int dimension, const vector<int>& vals); // 指定维度+分量数组
    void display() const; // 打印函数（加const）
    int getfenliang(int index) const; // 得到分量（加const）
    
    Vector Add(const Vector &ob2) const; // 加const
    Vector Sub(const Vector &ob2) const; // 加const
    int Mult(const Vector &ob2) const; // 加const

private:
    int dim;
    vector<int> fenliang;
};

Vector::Vector():dim(1),fenliang({-1}) {}

Vector::Vector(int dimension):dim(dimension) {
    if (dimension<=0) {
        cout<<"维度必须为正整数，已重置为1维"<< endl;
        dim=1; 
    }
    fenliang.resize(dim, 0); 
}

Vector::Vector(int dimension,const vector<int>& vals):dim(dimension) {
    if (dimension<=0) {
        cout << "维度必须为正整数，已重置为1维" <<endl;
        dim=1;
        fenliang.assign(1, -1); 
        return;
    }
    if (vals.size() != dimension) {
        cout<<"分量数量与维度不匹配(维度"<<dimension<< "，分量数："<<vals.size()<< "），已初始化为0"<<endl;
        fenliang.resize(dim, 0);
        return;
    }
    fenliang=vals;
}

void Vector::display()const {
    cout<<"(";
    for(int i = 0;i<dim;++i) {
        cout<<fenliang[i];
        if (i!=dim - 1) {
            cout<<",";
        }
    }
    cout<<")"<<endl;
}

int Vector::getfenliang(int index) const {
    if (index < 0 || index >= dim) {
        cout<<"索引"<<index<<"超出维度范围（维度：" << dim << "）"<<endl;
        return -1; // 返回非法值，不访问越界内存
    }
    return fenliang[index];
}

Vector Vector::Add(const Vector &ob2) const {
    if (dim!=ob2.dim) {
        cout<<"加法失败：矢量1维度="<<dim<<"，矢量2维度="<<ob2.dim<<endl;
        return Vector(); // 返回默认1维向量，避免错误运算
    }
    vector<int> jieguo;
    for (int i=0;i<dim;++i) {
        jieguo.push_back(fenliang[i]+ob2.fenliang[i]);
    }
    return Vector(dim, jieguo);
}

Vector Vector::Sub(const Vector &ob2) const {
    if (dim!= ob2.dim) {
        cout<<"减法失败：矢量1维度="<<dim<<"，矢量2维度="<<ob2.dim<<endl;
        return Vector();
    }
    vector<int> jieguo;
    for (int i=0; i<dim;++i) {
        jieguo.push_back(fenliang[i]-ob2.fenliang[i]);
    }
    return Vector(dim,jieguo);
}

int Vector::Mult(const Vector &ob2) const {
    if (dim!=ob2.dim) {
        cout<<"点乘失败：矢量1维度="<<dim<<"，矢量2维度="<<ob2.dim<<endl;
        return -1; 
    }
    int sum = 0;
    for (int i=0; i<dim;++i) {
        sum+=fenliang[i]*ob2.fenliang[i];
    }
    return sum;
}

int main(int argc, char** argv) {
    Vector ob1;
    cout<<"矢量ob1初始化为：";
    ob1.display(); 

    vector<int> vals;
    vals.push_back(1);
    vals.push_back(2);
    vals.push_back(3);
    Vector ob2(3,vals); 
    cout<<"矢量ob2为：";
    ob2.display();
    
    Vector add = ob1.Add(ob2);
    cout<<"ob1 + ob2 结果为：";
    add.display(); 

    Vector sub = ob1.Sub(ob2);
    cout<<"ob1 - ob2 结果为：";
    sub.display(); 

    int cheng = ob1.Mult(ob2);
    cout<<"ob1 · ob2 结果为："<<cheng<<endl;

    cout<< "\n--- 维度相同的运算测试 ---"<<endl;
    Vector ob3(3,{4,5,6});
    Vector ob4(3,{7,8,9});
    cout<<"矢量ob3为：";
    ob3.display();
    cout<<"矢量ob4为：";
    ob4.display();
    
    Vector add2 = ob3.Add(ob4);
    cout<<"ob3+ob4 = ";
    add2.display();
    
    Vector sub2 = ob3.Sub(ob4);
    cout<< "ob3-ob4 = ";
    sub2.display(); 
    
    int mult2 = ob3.Mult(ob4);
    cout<< "ob3*ob4 = "<<mult2<<endl; 

    return 0;
}


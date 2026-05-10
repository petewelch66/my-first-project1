#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class BaseString {
protected:
    char Data[50];         
    unsigned int Length;    
public:
    BaseString();
    BaseString(const char*str);
    virtual ~BaseString();
    unsigned int GetLength() const;
    virtual void Display() const;
    char* GetData();
    const char* GetData() const;
    void Input();
};

class ReString:virtual public BaseString {
public:
    ReString();
    ReString(const char*str);
    ~ReString() override;
    void Inverse(); 
};

class CopyString:virtual protected BaseString {
public:
    CopyString();
    CopyString(const char*str);
    ~CopyString() override;
    void Copy(const CopyString& ob); 

    void Display() const {BaseString::Display();}
    unsigned int GetLength() const {return BaseString::GetLength();}
    const char* GetData() const {return BaseString::GetData();}
};

class CmpString:virtual private BaseString {
public:
    CmpString();
    CmpString(const char* str);
    ~CmpString() override;
    int Compare(const CmpString& ob) const; 

    void Display() const {BaseString::Display();}
    unsigned int GetLength() const {return BaseString::GetLength();}
    const char* GetData() const {return BaseString::GetData();}
};

class NewString:public ReString,public CopyString,public CmpString{
public:
    NewString();
    NewString(const char* str);
    ~NewString() override;
    void Display() const override {
        ReString::Display();
    }
};

BaseString::BaseString():Length(1) {
    Data[0]='\0';
    cout<<"[构造] BaseString 默认构造函数调用"<<endl;
}

BaseString::BaseString(const char* str) {
    strncpy(Data,str,sizeof(Data)-1);
    Data[sizeof(Data)-1]='\0';
    Length=strlen(Data)+1;
    cout<<"[构造] BaseString 带参构造函数调用"<<endl;
}

BaseString::~BaseString() {
    cout<<"[析构] BaseString 析构函数调用"<<endl;
}

unsigned int BaseString::GetLength() const {
    return Length;
}

void BaseString::Display() const {
    cout<<"字符串内容："<<Data<<" | 长度(含'\\0')："<<Length<<endl;
}

char* BaseString::GetData() {
    return Data;
}

const char* BaseString::GetData() const {
    return Data;
}

void BaseString::Input() {
    cout<<"请输入字符串：";
    cin.getline(Data,sizeof(Data));
    Length=strlen(Data)+1;
}

ReString::ReString():BaseString() {
    cout<<"[构造] ReString 默认构造函数调用"<<endl;
}

ReString::ReString(const char* str):BaseString(str) {
    cout<<"[构造] ReString 带参构造函数调用"<<endl;
}

ReString::~ReString() {
    cout<<"[析构] ReString 析构函数调用"<<endl;
}

void ReString::Inverse() {
    unsigned int len=Length-1; 
    for (unsigned int i=0;i<len/2;++i) {
        char temp=Data[i];
        Data[i]=Data[len-1-i];
        Data[len-1-i]=temp;
    }
}

CopyString::CopyString():BaseString() {
    cout<<"[构造] CopyString 默认构造函数调用"<<endl;
}

CopyString::CopyString(const char* str):BaseString(str) {
    cout<<"[构造] CopyString 带参构造函数调用"<<endl;
}

CopyString::~CopyString() {
    cout<<"[析构] CopyString 析构函数调用"<<endl;
}

void CopyString::Copy(const CopyString& ob) {
    strncpy(Data,ob.Data,sizeof(Data)-1);
    Data[sizeof(Data)-1]='\0';
    Length=ob.Length;
}

CmpString::CmpString():BaseString() {
    cout<<"[构造] CmpString 默认构造函数调用"<<endl;
}

CmpString::CmpString(const char* str) : BaseString(str) {
    cout<<"[构造] CmpString 带参构造函数调用"<<endl;
}

CmpString::~CmpString() {
    cout<<"[析构] CmpString 析构函数调用"<<endl;
}

int CmpString::Compare(const CmpString& ob) const {
    unsigned int len1=GetLength();
    unsigned int len2=ob.GetLength();
    if (len1>len2) return 1;
    else if (len1==len2) return 0;
    else return -1;
}

NewString::NewString() : BaseString(), ReString(), CopyString(), CmpString() {
    cout<<"[构造] NewString 默认构造函数调用"<<endl;
}

NewString::NewString(const char* str) : BaseString(str), ReString(str), CopyString(str), CmpString(str) {
    cout<<"[构造] NewString 带参构造函数调用"<<endl;
}

NewString::~NewString() {
    cout<<"[析构] NewString 析构函数调用"<<endl;
}

int main() {
    cout<<"===== 测试 BaseString ====="<<endl;
    BaseString bs("HelloWorld");
    bs.Display();
    cout<<"字符串长度："<<bs.GetLength()<<endl;
    cout<<"输入新字符串："<<endl;
    bs.Input();
    bs.Display();

    cout<<"\n===== 测试 ReString（字符串倒置） ====="<<endl;
    ReString rs("ABCDE");
    cout<<"倒置前：";
    rs.Display();
    rs.Inverse();
    cout<<"倒置后：";
    rs.Display();

    cout<<"\n===== 测试 CopyString（对象拷贝） ====="<<endl;
    CopyString cs1("CopyTest123");
    CopyString cs2;
    cout<<"cs1 原始内容：";
    cs1.Display();
    cs2.Copy(cs1);
    cout<<"cs2 拷贝后内容：";
    cs2.Display();

    cout<<"\n===== 测试 CmpString（长度比较） ====="<<endl;
    CmpString cmp1("Apple");
    CmpString cmp2("Banana");
    CmpString cmp3("CherryPie");
    cout<<"cmp1："; cmp1.Display();
    cout<<"cmp2："; cmp2.Display();
    cout<<"cmp3："; cmp3.Display();
    cout<<"cmp1 vs cmp2："<<cmp1.Compare(cmp2)<<endl;  
    cout<<"cmp3 vs cmp1："<<cmp3.Compare(cmp1)<<endl;  
    cout<<"cmp1 vs cmp1："<<cmp1.Compare(cmp1)<<endl;  

    cout<<"\n===== 测试 NewString（多重继承） ====="<<endl;
    cout<<"=== 构造/析构顺序验证 ==="<<endl;
    NewString ns("MultiInheritTest");
    cout<<"=== 二义性解决方法验证 ==="<<endl;
    cout<<"方法1：虚继承，直接调用Display()：";
    ns.Display();
    cout<<"方法2：类名限定（ReString::Display()）：";
    ns.ReString::Display();
    cout<<"方法3：直接指定基类（BaseString::Display()）：";
    ns.BaseString::Display();

    cout<<"\n=== NewString 功能测试 ==="<<endl;
    cout<<"倒置前：";
    ns.Display();
    ns.Inverse(); 
    cout<<"倒置后：";
    ns.Display();

    NewString ns2;
    ns2.Copy(ns); 
    cout<<"ns2拷贝ns后：";
    ns2.Display();
    cout<<"ns vs ns2："<<ns.Compare(ns2)<<endl; 

    return 0;
}

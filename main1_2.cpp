#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string xiangcheng(string x, string y) {
    
    reverse(x.begin(),x.end()); //数字反转，方便进位 
    reverse(y.begin(),y.end());
    
    string res(x.size()+y.size(),'0');  //结果字符串，全部填0 
    
    for (int i=0;i<x.size();i++) { //逐位相乘 
        for (int j=0; j<y.size();j++) {
            int sum=(x[i]-'0')*(y[j]-'0')+(res[i+j]-'0'); //将字符变成真正的数字，两者相乘加原来位置上的数 
            res[i+j]=sum%10+'0';   // 当前位
            res[i+j+1]+=sum/10;     // 进位
        }
    }
    
    while(res.length()>1 && res[res.length()-1]=='0') {
        res=res.substr(0,res.length()-1); //去掉多余的0 
    }
    
    reverse(res.begin(),res.end()); //将数字再次反转 
    return res;
}

int main() {
    string a, b;
    cout<<"输入第一个数：";
    cin>>a;
    cout<<"输入第二个数：";
    cin>>b;
    cout<<"结果："<<xiangcheng(a, b)<<endl;
    return 0;
}

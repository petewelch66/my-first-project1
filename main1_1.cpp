#include <iostream>
#include <cstdlib>  //随机数 
#include <ctime>    //获取时间 

using namespace std;

int main() {
   
    srand(time(0)); //生成随机数 
    
    int correct = 0;   
    int a,b,c,answer;
    char ysf;       
    int userAnswer;       
    
    clock_t start = clock();  //开始计时 
    cout << "===== 四则运算测验（共3题）=====" << endl;

    for (int i =1; i<=3; ++i) {
        a = rand()%30+1;
        b = rand()%30+1;
        c = rand()% 4; //随机加减乘除 

        switch (c) {
            case 0:
                ysf='+';
                answer=a+b;
                break;
            case 1:
                ysf='-';
                answer=a-b;
                break;
            case 2:
                ysf= '*';
                answer=a*b;
                break;
            case 3:
                ysf='/';
                answer=a;
                a=a*b; //整除，防止出现小数 
                break;
        }

        cout<<"\n第"<<i<<"题："<<a<<" "<<ysf<< " "<<b<<" = ";
        cin>>userAnswer;

        if (userAnswer==answer) {
            cout<<"回答正确！"<<endl;
            correct++;} 
		else 
		{
            cout<<"回答错误，正确答案是："<<answer<<endl;
        }
    }

    clock_t end=clock(); //停止计时 
    double time=(end-start)*1.0/CLOCKS_PER_SEC; //时间差转换成秒 

    cout<<"\n总题数：3"<<endl;
    cout<<"答对："<<correct<<endl;
    cout<<"正确率："<<correct*100.0/3<<"%"<<endl; //转换成百分比 
    cout<<"用时："<<time<<" 秒"<<endl;

    return 0;
}

#include<iostream>
using namespace std;
float calc(float a,float b,char op){
    float result;
    switch(op){
    case '+':
        result=a+b;
        break;
    case '-':
        result=a-b;
        break;
    case '*':
        result=a*b;
        break;
    case '/':
        result=a/b;
        break;
    default:
        result=0.0;
        break;
    }
    return result;
}
int main(){
    cout<<"**********BASIC CALULATOR**********"<<endl;
    float x,y;
    char oper;
    cout<<"Enter two operands:"<<endl;
    cin>>x>>y;
    cout<<"Enter operation:"<<endl;
    cin>>oper;
    if((oper=='+'||oper=='-'||oper=='*'||oper=='/')&&!(oper=='/'&&y==0)){
        float result=calc(x,y,oper);
        cout<<endl<<x<<oper<<y<<"="<<result;
    }
    else if(oper=='/'&&y==0){
        cout<<"Division by zero";
    }
    else{
        cout<<"Invalid operation";
    }
    cout<<endl<<endl<<"**********End**********";
}

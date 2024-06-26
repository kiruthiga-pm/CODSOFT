#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int random_no = rand() % 10;
    int n,turn=0;
    cout<<"*******************"<<endl;
    cout<<"RANDOM NUMBER GUESS"<<endl;
    cout<<"*******************"<<endl;
    cout<<"guess a number between 0 to 9"<<endl<<endl;
    do{
       cout<<"Enter your number: "<<endl;
       cin>>n;
       if(n==random_no){
            cout<<"_____________________"<<endl;
            cout<<"you found at "<<turn<<" turn"<<endl;
            cout<<"YOUR GUESS IS CORRECT"<<endl;
            cout<<"_____________________"<<endl;
       }
       else if(n<random_no){
            cout<<"guess is too low"<<endl;
            turn++;
       }
       else if(n>random_no){
            cout<<"guess is too high"<<endl;
            turn++;
       }
    }while(n!=random_no);
}

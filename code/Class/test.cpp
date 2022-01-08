//
// Created by tsandl on 05/01/2022.
//

//
// Created by tsandl on 05/01/2022.
//

#include<iostream>
using namespace std;
struct node1{
    int a;
    int b;
};
class node2{
public:
    int a;
    int b;
    node2(){}
    node2(int number1,int number2):a(number1),b(number2){}
};
void printStruct(node1 n){
    cout<<"the following is struct node1"<<endl;
    cout<<n.a<<"    "<<n.b<<endl;
}
void printClass(node2 n){
    cout<<"the following is class node2"<<endl;
    cout<<n.a<<"    "<<n.b<<endl;
}
int main(){
    node1 n1;
    n1.a = 1;
    n1.b = 2;
    printStruct(n1);
    node2 n2;
    n2.a = 3;
    n2.b = 4;
    printClass(n2);
    node2 n3 = node2(5,6);
    cout<<"testing......."<<endl;
    cout<<n3.a<<"  "<<n3.b<<endl;
    return 0;
}
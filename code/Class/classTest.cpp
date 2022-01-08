//
// Created by tsandl on 05/01/2022.
//

#include<iostream>
using namespace std;
struct node1{
    int a;
    int b;
};
void printClass(node1 n){
    cout<<"the following is struct node1"<<endl;
    cout<<n.a<<"    "<<n.b<<endl;
}

int main(){
    node1 n1;
    n1.a = 1;
    n1.b = 2;
    printClass(n1);

    return 0;
}
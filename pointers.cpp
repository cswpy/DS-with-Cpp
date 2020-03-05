//An experiment of pointers
#include<iostream>
using namespace std;
int main()
{
void print(int,int, int, int*, int*);

int A = 1;
int B = 2;
int C = 3;
int *P1, *P2;
P1=&A;
P2=&C;
print(A,B,C,P1,P2);
*P1=(*P2)++;
print(A,B,C,P1,P2);
P1=P2;
print(A,B,C,P1,P2);
P2=&B;
print(A,B,C,P1,P2);
*P1-=*P2;
print(A,B,C,P1,P2);
++*P2;
print(A,B,C,P1,P2);
*P1*=*P2;
print(A,B,C,P1,P2);
A=++*P2**P1;
print(A,B,C,P1,P2);
P1=&A;
print(A,B,C,P1,P2);
*P2=*P1/=*P2;
print(A,B,C,P1,P2);
return 0;
}

void print(int A,int B, int C, int* P1, int* P2){
    cout<<"A is "<<A<<endl;;
    cout<<"B is "<<B<<endl;
    cout<<"C is "<<C<<endl;
    cout<<"Pointer P1 is "<<*P1<<endl;
    cout<<"Pointer P2 is "<<*P2<<endl;
    cout<<"--------------"<<endl;
}
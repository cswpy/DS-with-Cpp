//An i,plementation to implement two-dimension matrix in C++
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int **tabulate, numRows, numCols;
    cin>>numRows;
    cin>>numCols;
    tabulate = new int*[numRows];
    for(int i=0;i<numRows;i++){
        tabulate[i] = new int[numCols];
    }
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            tabulate[i][j] = rand()%101;
            cout<<tabulate[i][j]<<"\t|\t";
        }
        cout<<endl;
    }
    for(int i=0;i<numRows;i++){
        delete [] tabulate[i];
    }
    delete [] tabulate;
    return EXIT_SUCCESS;
}
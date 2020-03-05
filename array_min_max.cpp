//Randomly generate an array and find the min and max

#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    void findMinMax(int[], int, int*, int*);
    
    int size;
    int min=99;
    int max=0;
    cin>>size;
    int *nums;
    nums = new int[size];
    for(int i=0; i<size; i++){
        nums[i]=(rand()%100);
    }
    cout<<"The randomly generated array of size "<<size<<" is:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    cout<<"--------------------"<<endl;
    findMinMax(nums,size, &min, &max);
    cout<<"Max: "<<max<<endl<<"Min: "<<min<<endl;
    delete []nums;
    return 0;
}

void findMinMax(int array[],int size, int *min, int *max){
    for(int i=0;i<size;i++){
        if(array[i]>*max){
            *max = array[i];
        }
        if(array[i]<*min){
            *min = array[i];
        }
    }
}
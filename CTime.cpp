//An self-desined implementation of class CTime to record time, @author: Phillip Wang

#include<iostream>
#include<cstdlib>
using namespace std;

class CTime {
    friend ostream& operator << (ostream &os1, const CTime &ct);
    friend istream& operator >> (istream &is1, CTime &ct);
    private:
        int hours;
        int minutes;
    
    public:    
    CTime(){
        hours = 0;
        minutes = 0;
    }

    CTime(int newHour, int newMin){
        hours = newHour;
        minutes = newMin;
    }

    void inputTime(int newHour, int newMin){
        this->hours = newHour;
        this->minutes = newMin;
    }

    void printTime(){
        cout<<this->hours<<"H:"<<this->minutes<<"M"<<endl;
    }

    int setHours(int newHour){
        if(newHour<24 and newHour>=0){
            this->hours = newHour;
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }
        
    }
    
    int getHours(){
        return this->hours;
    }
    
    int getMinutes(){
        return this->minutes;
    }

    int setMinutes(int newMin){
        if(newMin<60 && newMin>=0){
            this->minutes = newMin;
            return EXIT_SUCCESS;
        }
        else
        {
            return EXIT_FAILURE;
        }
        
    }

    CTime operator + (CTime const &ct2) {
        CTime ct;
        int carry=0;
        carry = (this->minutes+ct2.minutes)/60;
        ct.setMinutes((this->minutes+ct2.minutes)%60);
        ct.setHours(this->hours+ct2.hours+carry);
        return ct;
    }

    CTime operator - (CTime const &ct2){
        CTime ct;
        int borrow=0;
        if(ct.setMinutes(this->minutes-ct2.minutes)==1){
            ct.setMinutes(this->minutes-ct2.minutes+60);
            borrow = 1;
        }
        
        if(ct.setHours(this->hours-ct2.hours-borrow)==1){
            ct.setHours(this->hours-ct2.hours-borrow+24);
        }
        return ct;
    }

    ~CTime(){
        cout<<"Destructor: "<<hours<<" : "<<minutes<<endl;
    }
};

ostream& operator << (ostream &os1, const CTime &ct){
    os1 << ct.hours << "H:" << ct.minutes << "M"<<endl;
    return os1;
}

istream& operator >> (istream &is1, CTime &ct){
    cout<<"Input the hour: ";
    is1>>ct.hours;
    cout<<"Input the minutes: ";
    is1>>ct.minutes;
    return is1;
}


int main()
{
    cout<<"Start of the main function:"<<endl;

   CTime t1;
    // CTime t1;
    // CTime t2(2,25);
    // cin>>t1;
    // CTime t3 = t1+t2;
    // CTime t4 = t2-t1;
    // cout<<"Addition: "<<t3;
    // cout<<"Subtraction: "<<t4;

    // CTime *array = new CTime[5];
    // for(int i=0; i<5; i++){
    //     array[i] = CTime(rand()%23, rand()%59);
    //     array[i].printTime();
    // }

    int arraySize;
    cout<<"The size of array:";
    cin>>arraySize;
    CTime *array1 = new CTime[arraySize];
    for(int i=i; i<arraySize; i++){
        array1[i] = CTime(rand()%23, rand()%59);
        array1[i].printTime();
    }

    cout<<"End of the main function."<<endl;

    return 0;
}
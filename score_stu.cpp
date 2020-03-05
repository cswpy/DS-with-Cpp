//A simplified student scoring system that computes relevant stats.

#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    void deallocate(int **matrix, int);
    void fillData(int **matrix, int, int);
    void displayData(int **matrix, int, int);
    int avgScore4oneStud(int **matrix, int, int);
    int avgScore4oneCourse(int **matrix, int, int);
    void avgScore4allStud(int **matrix, int, int);
    void avgScore4allCourse(int **matrix, int, int);
    void minScoreinOneCourse(int **matrix, int, int);
    void minScoreinAllCourse(int **matrix, int, int);
    
    int numStud, numCourse;
    cout<<"Input the number of students and number of courses: "<<endl;
    cin>>numStud>>numCourse;
    cout<<numStud<<" students enrolled in "<<numCourse<<" classes."<<endl;
    int **scoreMatrix;
    scoreMatrix = new int* [numStud];
    for(int i=0;i<numStud;i++){
        scoreMatrix[i] = new int [numCourse];
    }
    int stuid=1,courseid=1;

    fillData(scoreMatrix,numStud, numCourse);
    displayData(scoreMatrix,numStud, numCourse);
    cout<<"------------------"<<endl;
    cout<<"Average score for Student["<<stuid<<"] is: "<< avgScore4oneStud(scoreMatrix, stuid, numCourse)<<endl;
    cout<<"------------------"<<endl;
    cout<<"Average score for Course["<<courseid<<"] is: "<<avgScore4oneCourse(scoreMatrix,1,numStud)<<endl;
    cout<<"------------------"<<endl;
    avgScore4allStud(scoreMatrix,numStud,numCourse);
    cout<<"------------------"<<endl;
    avgScore4allCourse(scoreMatrix,numStud,numCourse);
    cout<<"------------------"<<endl;
    minScoreinAllCourse(scoreMatrix,numStud,numCourse);
    deallocate(scoreMatrix,numStud);
    return 0;
}

void deallocate(int **matrix, int numRow){
    for(int i=0;i<numRow;i++){
            delete [] matrix[i];
    }
    delete []matrix;
}

void fillData(int **matrix, int numRows, int numCols){
    for(int i=0;i<numRows;i++){
        for(int j=0;j<numCols;j++){
            matrix[i][j]=rand()%101;
        }
    }
}

void displayData(int **matrix, int numRows, int numCols){
    for(int i=0;i<numRows;i++){
        cout<<"Score for student["<<i<<"]: ";
        for(int j=0;j<numCols;j++){
            cout<< matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int avgScore4oneStud(int **matrix, int stuid, int numCourse){
    int sum=0;
    int avg;
    for(int i=0;i<numCourse;i++){
        sum+=matrix[stuid][i];
    }
    avg = sum/numCourse;
    return avg;
}

int avgScore4oneCourse(int **matrix, int courseid, int numStud){
    int sum=0;
    int avg;
    for(int j=0;j<numStud;j++){
        sum+=matrix[j][courseid];
    }
    avg = sum/numStud;
    return avg;
}

void avgScore4allStud(int **matrix, int numStud, int numCourse){
    cout<<"Displaying average scores for each students:"<<endl;
    for(int i=0;i<numStud;i++){
        int score;
        score = avgScore4oneStud(matrix, i, numCourse);
        cout<<"Avg score of student["<<i<<"] is: "<<score<<endl;
    }
}

void avgScore4allCourse(int **matrix, int numStud, int numCourse){
    cout<<"Displaying average scores for each courses:"<<endl;
    for(int i=0;i<numCourse;i++){
        int score;
        score = avgScore4oneCourse(matrix, i, numStud);
        cout<<"Avg score of course["<<i<<"] is: "<<score<<endl;
    }
}

void minScoreinOneCourse(int **matrix, int numStud, int courseid){
    int min=100;
    for(int i=0;i<numStud;i++){
        if(matrix[i][courseid]<min){
            min=matrix[i][courseid];
        }
    }
    cout<<"Min score for Course["<<courseid<<"] is: "<<min<<endl;
}

void minScoreinAllCourse(int **matrix, int numStud, int numCourse){
    cout<<"Displaying min scores for all courses:"<<endl;
    for(int j=0;j<numCourse;j++){
        minScoreinOneCourse(matrix,numStud,j);
    }
    cout<<"------------------"<<endl;
}

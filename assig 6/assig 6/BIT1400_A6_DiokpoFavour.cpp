
/*
 * BIT1400
 * Assignment 6 - Movie Statistics
 * the program calculates movie statistics, so as to practice dynamic arrays, pointers and functions.
 * Favour Diokpo 101021610
 * 7/April/2017
 *
 * COMMENT:
 * I used Xcode when programming becuase I have a MacBook that is why i have my main returning an int
 * value, sorry for the inconvinence.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int * createArray(int surveyNumber);
void printArray(int* surveyArray, int surveyNumber);
void arraySort(int* surveyArray, int surveyNumber);
double average(int* surveyArray, int surveyNumber);
int median(int* surveyArray, int surveyNumber);
int mode(int* surveyArray, int surveyNumber);


int main() {
    srand(time(NULL));
    cout << "how many students where surveyed? " << endl;
    cout << "select a number from 1-100 "<<endl;
    int studentSurveyed, medianValue, modeValue;
    double averageValue;
    cin >> studentSurveyed;
    
    //error checking
    while ((studentSurveyed < 0) || (studentSurveyed > 100)){
        cout << "Error the number you enterd is not in the parameters please retry" << endl;
        cout << "How many students where surveyed? " << endl;
        cin >> studentSurveyed;
    }
    
    //calling user entry fuction
    int * surveyArray = createArray(studentSurveyed);
    
    //printing unsorted array
    cout<<"\nThe number of movies watched per student:"<<endl;
    cout<<"_________________________________________"<<endl;
    printArray(surveyArray, studentSurveyed);
    
    //printing out sorted array
    cout<<"\nThe number of movies watched per student SORTED:"<<endl;
    cout<<"__________________________________________________"<<endl;
    arraySort(surveyArray, studentSurveyed);
    
    //finding average
    averageValue = average(surveyArray, studentSurveyed);
   cout<<"\nThe Average is " << averageValue;
    
   //finding median
    medianValue = median(surveyArray, studentSurveyed);
    cout << "\nThe median is " << medianValue;
    
    //finding mode
    modeValue = mode(surveyArray, studentSurveyed);
    cout << "\nThe mode is " << modeValue;
    
    cout<<endl;
    
    delete [] surveyArray;
    surveyArray = 0;
    return 0;
}


/*----------------------------------------------------------------------------------------------------/
 * Function: createArray
 * Description: reads the value from the users and puts in a dynamic array
 * Parameter: surveryNumber: passed by value
 * Return: the address of array
 *----------------------------------------------------------------------------------------------------*/

int * createArray(int surveyNumber){
    
    int * entryArray = new int[surveyNumber];
    int entry = 0;
    int moviewatched = 0;
    
    cout<<"\n1. Manual Entry of movies watched"<<endl;
    cout<<"2. Random Entry of movies watched"<<endl;
    cin>>entry;
    
    if(entry == 1){
        for (int i = 0; i < surveyNumber ; i++) {
            cout<<"How many movies did each student watch"<<endl;
            cin>>moviewatched;
            entryArray[i] = moviewatched;
        }
    }
    else if(entry == 2){
        for (int j = 0; j < surveyNumber ; j++) {
            entryArray[j] = rand() % 10+1;
        }
    }
    
    
    return entryArray;
}



/*----------------------------------------------------------------------------------------------------/
 * Function: printArray
 * Description: displays the array
 * Parameter: surveyArray = array passed by address
              surveyNumber = passed by value
 * Return: nothing
 *----------------------------------------------------------------------------------------------------*/
void printArray(int* surveyArray, int surveyNumber){
    for (int i = 0; i < surveyNumber; i++) {
        cout << surveyArray[i] << " ";
    }
    cout << endl;
}


/*----------------------------------------------------------------------------------------------------/
 * Function: arraySort
 * Description: sorts the array
 * Parameter: surveyArray = array passed by address
              surveyNumber = passed by value
 * Return: nothing
 *----------------------------------------------------------------------------------------------------*/
void arraySort(int* surveyArray, int surveyNumber){
    int startScan, minIndex, minValue;
    
    for (startScan = 0; startScan < (surveyNumber - 1); startScan++){
        minIndex = startScan;
        minValue = surveyArray[startScan];
        for(int index = startScan + 1; index < surveyNumber; index++){
            if (surveyArray[index] < minValue){
                minValue = surveyArray[index];
                minIndex = index;
            } }
        surveyArray[minIndex] = surveyArray[startScan];
        surveyArray[startScan] = minValue;
    }
    
    printArray(surveyArray, surveyNumber);
}


/*----------------------------------------------------------------------------------------------------/
 * Function: average
 * Description: calculates average
 * Parameter: surveyArray = array passed by address
              surveyNumber = passed by value
 * Return: double value
 *----------------------------------------------------------------------------------------------------*/
double average(int* surveyArray, int surveyNumber){
    int total = 0;
    double average = 0;
    
    for (int i = 0; i < surveyNumber; i++) {
        total += surveyArray[i];
    }
    average = total/surveyNumber;
    return average;
}


/*----------------------------------------------------------------------------------------------------/
 * Function: median
 * Description: calculates median
 * Parameter: surveyArray = array passed by address
              surveyNumber = passed by value
 * Return: int value
 *----------------------------------------------------------------------------------------------------*/
int median(int* surveyArray, int surveyNumber){
    int median;
    if(surveyNumber % 2 == 0){
        median = ( surveyArray[ surveyNumber / 2 ] + surveyArray[ (surveyNumber / 2) - 1 ] ) / 2.0;
    }
    else{
        median = surveyArray[ (surveyNumber/2) + 1 ];
    }
    return median;
}


/*----------------------------------------------------------------------------------------------------/
 * Function: mode
 * Description: calculates mode
 * Parameter: surveyArray = array passed by address
              surveyNumber = passed by value
 * Return: int value
 *
 *some parts of this functions code are not mine, I took the basic knowledge from this website, but i changed it to suit my code better    
 * link --> http://xoax.net/cpp/ref/cpp_examples/incl/mean_med_mod_array/
 *----------------------------------------------------------------------------------------------------*/
int mode(int * surveyArray, int surveyNumber) {
    
    int* repetition = new int[surveyNumber];
    for (int i = 0; i < surveyNumber; ++i) {
        repetition[i] = 0;
        int j = 0;
        bool bFound = false;
        while ((j < i) && (surveyArray[i] != surveyArray[j])) {
            if (surveyArray[i] != surveyArray[j]) {
                ++j;
            }
        }
        ++(repetition[j]);
    }
    int maxRepeat = 0;
    for (int i = 1; i < surveyNumber; ++i) {
        if (repetition[i] > repetition[maxRepeat]) {
            maxRepeat = i;
        }
    }
    delete [] repetition;
    return surveyArray[maxRepeat];
}


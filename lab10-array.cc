//      Name: Brayden Birt
//      Date: 03/29/23
// File name: lab10.cc


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

//Prototypes
int smallestIndex(const double data[]);
int largestIndex(const double data[]);

int main() {
    double price[6];
    string parts[6];

    ifstream insPrice;//open and check fail for first file
    insPrice.open("data1.txt");
    if (insPrice.fail())
    {
        cout << "Error: file 1" << endl;
        exit(0);
    }//load array
    for (size_t i = 0;i < 6; i++){
        insPrice >> price[i];
    }
    insPrice.close();//close file

    ifstream insParts;//open and check fail for second file
    insParts.open("data2.txt");
    if (insParts.fail())
    {
        cout << "Error: file 2" << endl;
        exit(0);
    }//load array
    for (size_t i = 0;i < 6; i++){
        insParts >> parts[i];
    }
    insParts.close();//close file

    cout << "The name of the most expensive part is " << parts[largestIndex(price)] << " ($" << fixed << setprecision(2) << price[largestIndex(price)] << ")" << endl;
    cout << "The name of the least expensive part is " << parts[smallestIndex(price)] << " ($" << fixed << setprecision(2) << price[smallestIndex(price)] << ")" << endl;



    return 0;
}

int smallestIndex(const double price[]){
    int min = price[0];
    int minIndex = 0;
    for (size_t i = 0; i < 6; i++) {
        if (price[i] < min) {
            min = price[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int largestIndex(const double price[]){
    int max = price[0];
    int maxIndex = 0;
    for (size_t i = 0; i < 6; i++) {
        if (price[i] > max) {
            max = price[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}
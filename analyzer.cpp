//Partner: Mattias Castilla
#include <iostream>
#include "StringData.h"
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

//Linear Search algorithm
int LinearSearch(vector<string> container, int numbersSize, const string& key){
    int i;
    //For loop cycles through the vector until the key is found
    for(i = 0; i < numbersSize; ++i){
        if(container[i] == key){
            return i;
        }
    }

    return -1;
}

//Binary Search algorithm
int BinarySearch(vector<string> container, int numbersSize, const string& key){
    int mid;
    int low;
    int high;

    low = 0;
    high = numbersSize -1;

//while loop adjusts low/high bounds of search until the key is found
    while (high >= low) {
        mid = (high + low) / 2;
        if(container[mid] < key){
            low = mid+1;
        }
        else if (container[mid] > key){
            high = mid -1;
        }
        else{
            return mid;
        }
    }


    return -1;
}

//main method to execute the methods, tracks time as well
int main(){
    vector<string> data_set = getStringData();
    int DATA_SIZE = 17576;
    std::cout << "Finding not_here\n";

    auto start = std::chrono::system_clock::now();
    cout << "Linear search index: " << LinearSearch(data_set, DATA_SIZE, "not_here");
    auto finish = std::chrono::system_clock::now();
    auto duration = duration_cast<seconds>(finish-start);
    cout << " Time: " << duration.count() << " seconds";

    auto start2 = std::chrono::system_clock::now();
    cout << "\nBinary search index: " << BinarySearch(data_set, DATA_SIZE, "not_here");
    auto finish2 = std::chrono::system_clock::now();
    auto duration2 = duration_cast<seconds>(finish2-start2);
    cout << " Time: " << duration2.count() << " seconds";

    return 0;
}
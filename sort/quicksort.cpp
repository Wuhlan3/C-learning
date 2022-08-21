#include<iostream>
#include<vector>
using namespace std;

void partition(vector<int> & arr, int start, int end){
    if(start >= end)
        return;
    int pivot = arr[start];
    int i = start;
    int j = end;
    while(i < j){
        while(i < j && arr[j] > pivot)
            j--;
        arr[i] = arr[j];
        while(i < j && arr[i] < pivot)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    partition(arr, start, i - 1);
    partition(arr, i+1, end);
}

void quickSort(vector<int> &arr){
    partition(arr, 0, arr.size() - 1);
}

void print(vector<int> & arr){
    for(int i = 0; i < (int)arr.size(); i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2, 5, 7, 1, 0, 3, 4, 9, 8, 6};
    //0, 1, 2, 7, 5, 3, 4, 9, 8, 6
    quickSort(arr);
    print(arr);
}
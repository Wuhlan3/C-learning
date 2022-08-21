#include<iostream>
#include<vector>
using namespace std;

//从start开始调整堆
void max_heapify(vector<int> & arr, int start, int end){
    int dad = start;
    int son = start * 2 + 1;
    while(son <= end){
        //看左子节点大还是右子节点大，找大的那个
        if(son + 1 <= end && arr[son+1]>arr[son]){
            son = son + 1;
        }
        //如果父亲最大，就不用调整
        if(arr[son]<arr[dad]){
            return;
        }else{
            swap(arr[son], arr[dad]);
            dad = son;
            son = dad *2 + 1;
        }
    }
    return;
}

void heapSort(vector<int> & arr){
    int size = arr.size();
    //建堆
    for(int i= size/2-1; i>=0; i--){
        max_heapify(arr, i, size-1);
    }
    //取出堆顶后，调整堆
    for (int i = size - 1; i > 0; i --){
        swap(arr[i], arr[0]);
        max_heapify(arr, 0, i - 1);
    }
}

void print(vector<int> & arr){
    for(int i = 0; i < (int)arr.size(); i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2, 5, 7, 1, 0, 3, 4, 9, 8, 6};
    heapSort(arr);
    print(arr);
}
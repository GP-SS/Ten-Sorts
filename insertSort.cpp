#include <iostream>
#include <vector>
using namespace std;

//插入排序demo

void insertSort(vector<int>& arr) {
    int len = arr.size();
    for(int i = 1; i < len; i++) {
        //定义指针首先指向第二个元素，该元素是首个需要判断是否需要插入的元素
        int key = arr[i];//定义变量key保存需要插入的元素，为了后续的找到插入位置后的插入，因为i前面的若干元素若比arr[i]大，则会向右移动（即覆盖arr[i]的值）
        int j = i - 1;//定义指针j指向i的前一个元素
        //接着对i之前的每一个元素，都跟arr[i]比较，如果比arr[i]大，则需要右移，直到找到正确的插入位置
        while(j >= 0 && key < arr[j]) { //j>=0的目的是，移动到了数组的头，即遍历完了arr[i]之前所有的元素
            arr[j+1] = arr[j];//将arr[j]右边的值用arr[j]覆盖
            j--;//j向左移动
        }
        //当j<=或者key >= arr[j]的时候，表示已经找到了正确需要插入的位置
        arr[j+1] = key;
    }
}

int main() {

    vector<int> vec = {5,6,2,1,4,9,7,8,0,3};
    cout << "Before sorted :" << endl;
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    insertSort(vec);

    cout << "After sorted :" << endl;
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
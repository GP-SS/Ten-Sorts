#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//快速排序demo

void quickSort(vector<int>& arr, int left, int right) {
    if(left >= right) {
        return;
    }
    int i = left, j = right;
    int base = arr[left];//取最左边的数作为基准数
    while(i < j) {
        //指针i和指针j分别从数组的左右两端开始往中间遍历

        //指针j从右向左开始遍历，直到找到一个比基准数小的数为止，跳出循环
        while(arr[j] >= base && i < j) {
            j--;
        }
        //i从左向右开始遍历，直到找到一个比基准数大的数为止，跳出循环
        while(arr[i] <= base && i < j) {
            i++;
        }
        //经过以上的循环，此时的arr[i]和arr[j]分别是大于和小于基准数base的数
        if(i < j) {
            // //如果i指针还在j的左边,即大于基准数的元素还在基准数的左边，小于基准数的数还在基准数的右边，那么将arr[i]和arr[j]两个数交换 
            // int temp = arr[i];
            // arr[i] = arr[j];
            // arr[j] = temp;
            swap(arr[i], arr[j]);//也可以调用库函数swap进行交换，此时需要包含头文件#include <algorithm>
        }
    }
    //当i>=j，即i和j相遇或者i移动到j的右边之后，将基准数归位
    arr[left] = arr[i];
    arr[i] = base;

    //递归左右子区间
    quickSort(arr, left, i - 1);//因为i处的已经时基准数，不需要再进行排序
    quickSort(arr, i + 1, right);
}

int main() {
    vector<int> vec = {5,6,2,1,4,9,7,8,0,3};
    cout << "Before sorted :" << endl;
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    int left = 0, right = vec.size() - 1;
    quickSort(vec, left, right);

    cout << "After sorted :" << endl;
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}
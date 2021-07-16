#include <iostream>
#include <vector>
#include <algorithm>

//#include <bits/stdc++.h>//gcc环境下的万能头文件，在vs环境下行不通
using namespace std;

//归并排序demo

void merge(vector<int>&, int, int, vector<int>&);

//先用递归的方式将原数组进行分治，即从中间划分成左右两个子数组，继续递归划分，直到每个数组最多含有两个元素为止
void mergeSort(vector<int>& arr, int left, int right, vector<int>& res) {
    //区间右端点减去区间左端点为1，表示此时的数组包含两个元素；如1-0=1，表示包含arr[0]和arr[1]两个元素
    if((right - left) == 1) {
        //对这两个元素进行从小到大排序
        if(arr[left] > arr[right]) {
            //此处的交换也可以调用库函数swap()进行交换，不过需要包含头文件#include <algorithm>
            // int temp = arr[left];
            // arr[left] = arr[right];
            // arr[right] = temp;

            swap(arr[left], arr[right]);
        }
        return;
    }
    //区间右端点减去区间左端点为0，表示此时的数组仅有1个元素，不需要再进行排序，直接返回
    else if((right - left) == 0) {
        return;
    }
    else {
        //对左右子区间进行递归
        mergeSort(arr, left, (right - left + 1) / 2 + left, res);//左区间
        mergeSort(arr, (right - left + 1) / 2 + left + 1, right, res);//右区间

        //再对左右有序子区间的元素进行合并排序
        merge(arr, left, right, res);

        //最后将res数组中的元素写入arr中
        //for(int i = left; i < (right - left + 1); ++i) {
        for(int i = left; i <= right; ++i) {
            arr[i] = res[i];
        }         
    }
}

//对左右有序子数组进行合并操作，成为最终的有序数组
void merge(vector<int>& arr, int left, int right, vector<int>& res) {
    int left_index = left;//左区间的起始索引
    int left_len = (right - left + 1) / 2 + 1;//左区间元素个数
    int right_index = left_index + left_len;//右区间的起始索引
    int res_index = left;//最终数组的起始索引
    
    //当左右有序数组的索引都没有到各自数组的末尾时，分别从左右数组的起始位置开始比较左右两个数组中的元素值，将较小者存入最终数组中，然后将索引加1
    //while(left_index < left_len && right_index < right + 1) {
    while(left_index < left + left_len && right_index < right + 1) {//注意此处的区间端点结束条件left_index < left + left_len，
                                                                    //不能写成了left_index < left_len，因为左区间不一定都是从索引0开始
        if(arr[left_index] <= arr[right_index]) {
            res[res_index++] = arr[left_index++];
        }
        else {
            res[res_index++] = arr[right_index++];
        }
    }
    //当左右子数组的其中一个遍历完之后，将另外一个数组的剩余元素直接存放在res数组之后
    while(left_index < left + left_len) {
        //此时表示右子数组已经遍历完毕，且存放在了res数组中，此时需要将左数组剩余元素继续存入res的后续部分
        res[res_index++] = arr[left_index++];
    }
    while(right_index < right + 1) {
        res[res_index++] = arr[right_index++];
    }
}

int main() {

    vector<int> vec = { 1,5,9,6,8,0,3,4,2,7 };

	int right = vec.size() - 1;
	vector<int> res(right + 1);
	mergeSort(vec, 0, right, res);

	cout << "归并排序之后的数组：" << endl;
	for (auto i : vec) {
		//范围for语句，遍历数组vec中的每个元素，此时元素为i
		cout << i << " ";
	}
	cout << endl;
    system("pause");
    return 0;
}
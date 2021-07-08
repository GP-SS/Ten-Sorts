#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//堆排序demo

//调整大顶堆
void heapAdjust(vector<int>& arr, int i, int len) {
    int temp = arr[i];//先取出当前元素，当前的元素arr[i]作为父节点，其子节点的下标分别是2i+1和2i+2
    for(int k = i * 2 + 1; k < len; k = k * 2 + 1) {//从i结点的左子结点开始，也就是2i+1处开始

        //如果左子结点小于右子结点，k指向右子结点，此语句的作用是找到左右子节点中的较大者
        if((k + 1 < len) && (arr[k] < arr[k+1])){//k+1<len保证k+1下标没有超过数组正常的范围，防止越界访问
            k++;
        }

        if(arr[k] > temp) {//如果较大子节点大于父节点，将子节点值赋给父节点（不用进行交换）
            arr[i] = arr[k];//将子节点的额值赋给父节点
            i = k;//？？？为了后序更改arr[k]处的值
        }

        else {
            break;
        }
    }
    arr[i] = temp;//将temp值放到最终的位置
}

void heapSort(vector<int>& arr) {
    //1、构建大顶堆
    for(int i = arr.size() / 2 - 1; i >= 0; i--) {
        //i的初始值为 size/2 - 1，即第一个

        //从第一个非叶子结点"从下至上、从左至右"调整结构
        heapAdjust(arr, i, arr.size());
    }
    //2、调整堆结构+交换堆顶元素和末尾元素
    for(int j = arr.size() - 1; j > 0; j--) {
        swap(arr[0], arr[j]);
        heapAdjust(arr, 0, j);
    }
}


int main() {
	//自定义一个无序的数组，按要求从小到大排列
	vector<int> vec = { 1,5,9,6,8,0,3,4,2,7 };
	//插入之前打印输出原数组
	cout << "堆排序之前的数组：" << endl;
	for (auto i : vec) {
		//范围for语句，遍历数组vec中的每个元素，此时元素为i
		cout << i << " ";
	}
	cout << endl;
	cout << "------------------------------------" << endl;

    heapSort(vec);

    cout << "堆排序之后的数组：" << endl;
	for (auto i : vec) {
		//范围for语句，遍历数组vec中的每个元素，此时元素为i
		cout << i << " ";
	}
	cout << endl;

    system("pause");
    return 0;
}
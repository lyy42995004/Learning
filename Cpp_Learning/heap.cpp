#include <iostream>
#include <vector>
using namespace std;

// 向下调整，维护大根堆
void adjustDown(vector<int>& nums, int parent) {
    int n = nums.size();
    int child = 2*parent + 1;
    while (child < n) {
        // 找出大的，进行交换
        if (child + 1 < n && nums[child+1] > nums[child]) {
            child = child + 1;
        }

        if (nums[parent] < nums[child]) {
            swap(nums[parent], nums[child]);
            parent = child;
            child = 2*parent + 1;
        } else {
            break;
        }
    }
}

// 构建大根堆
void buildHeap(vector<int>& nums) {
    int n = nums.size();
    // 从最后一个非叶子结点开始调整
    for (int i = n/2 - 1; i >= 0; --i) {
        adjustDown(nums, i);
    }
}

int main() {
    vector<int> nums = {3, 5, 1, 2, 4, 6};
    buildHeap(nums);

    cout << "建堆后的结果：" << endl;
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}

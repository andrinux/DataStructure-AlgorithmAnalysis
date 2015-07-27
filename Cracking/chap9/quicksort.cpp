#include <iostream>
#include <vector>
#include <cmath>

void quick_sort(std::vector<int>& v);
void quick_sort(std::vector<int>& v, int low, int high);
int partition(std::vector<int>& v, int low, int high);
void swap(std::vector<int>& v, int a, int b);

void quick_sort(std::vector<int>& v, int low, int high) {
    if (low >= high) return;
    int p = partition(v, low, high);
    quick_sort(v, low, p);
    quick_sort(v, p+1, high);
}

int partition(std::vector<int>& v, int low, int high) {
    int p = rand()%(high-low) + low;
    int pivot = v[p];
    int left = low;
    int right = high;
    while (1) {
        while (v[left] < pivot && left < high) left++;
        if (left == high) break;//all elements are smaller than p
        while (v[right] > pivot && right > low) right--;
        if (right == low) break;//all elements are bigger than p
        if (left == right) break;//end up at pivot
        swap(v, left, right);
    }
    return left;
}

void swap(std::vector<int>& v, int a, int b) {
    int tmp = v[a];
    v[a] = v[b];
    v[b] = tmp;
}


int main() {
    std::vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(6);
    v.push_back(7);
    v.push_back(1);
    v.push_back(9);
    v.push_back(0);
    v.push_back(8);
    v.push_back(5);
    v.push_back(3);
    
    std::cout<<"\nBefore quick sort:\n    ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] <<" ";
    }
    fflush(NULL);
    quick_sort(v, 0, v.size()-1);
    
    std::cout<<"\nAfter quick sort:\n    ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] <<" ";
    }
    std::cout<<"\n\n";
    
    return 0;
}

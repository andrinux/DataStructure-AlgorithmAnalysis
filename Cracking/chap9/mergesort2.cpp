#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> sortedVector;
    int i = 0;
    int j = 0;
    while(sortedVector.size() < v1.size()+v2.size()) {
        if(v1[i]<v2[j]) {
            sortedVector.push_back(v1[i]);
            i++;
            if(i == v1.size()) {
                for (int k = j; k < v2.size(); k++) {
                    sortedVector.push_back(v2[k]);
                }
                return sortedVector;
            }
        } else {
            sortedVector.push_back(v2[j]);
            j++;
            if(j == v2.size()) {
                for (int k = i; k < v1.size(); k++) {
                    sortedVector.push_back(v1[k]);
                }
                return sortedVector;
            }
        }
    }
    return sortedVector;
}


vector<int> mergeSort(vector<int>& v, int l, int h) {
    if(l==h) {
        vector<int> tmp_v;
        tmp_v.push_back(v[l]);
        return tmp_v;
    }
    else {
        int m = (l+h)/2;
        vector<int> v1 = mergeSort(v, l, m);
        vector<int> v2 = mergeSort(v, m+1, h);
        return merge(v1, v2);
    }
}

void print_vector(vector<int> & v) {
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
}


int main() {
    vector<int> v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    v.push_back(8);
    v.push_back(66);
    v.push_back(34);
    v.push_back(22);
    v.push_back(35);
    
    print_vector(v);
    
    vector<int> sortedV;
    sortedV = mergeSort(v, 0, v.size()-1);
    
    print_vector(sortedV);
    
    return 0;
}

//The code uses the vector and sort functions, which are part of the <vector> and <algorithm> libraries, respectively. 
//You need to include these libraries at the beginning of your code.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); ) {
        int count = 1;
        for(int j = i + 1; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        ans.push_back(count);
        i += count;
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size() - 1; i++) {
        if(ans[i] == ans[i+1])
            return false;
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};   //unique element is present ie. 3
    //vector<int> arr = {1, 2, 2, 1, 3, 1, 3};    //unique element is not present as no. of occ(3) = 2
    bool result = uniqueOccurrences(arr);
    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}

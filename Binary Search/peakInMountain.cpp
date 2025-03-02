#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
  
    int find_peak(vector<int>& v) {
	int s = 0, e = v.size() - 1;
	// int mid=(s + e) / 2;
	while (s < e)
	{
		int mid = (s + e) / 2;
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
	}
	return s;
    }
    // int peakIndexInMountainArray(vector<int>& arr) {
    //     return find_peak(arr);
    // }
};
int main(){
    vector<int> arr = {3,4,5,9,8,7,6,5,5,5,5,5,1};
    Solution obj;
    //obj.find_peak(arr);
	// int p = obj.peakIndexInMountainArray(arr);
	int p = obj.find_peak(arr);
    cout << "Pivot/Peak element = "<<arr[p]<<" is found at index - " << p <<endl;

}

 
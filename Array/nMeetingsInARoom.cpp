#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxMeetings(int n, int start[], int end[]) {
    // Using pair ds
    vector<pair<int, int>> timing;
    for(int i=0; i<n; i++){
        timing.push_back({end[i], start[i]});      //We want a vector<pairs> to be sorted acc to end-time hence we push it first in the pair
    }
    sort(timing.begin(), timing.end());     //Sort Lexicographically (col wise: compare 1st el of each row, if its same then comp 2nd and sort in increasing order)
    int count=0;
    int lastMeet = -1;
    for(int i=0; i<n; i++){
        int startTime = timing[i].second;
        int endTime = timing[i].first;
        if(startTime > lastMeet){
            lastMeet = endTime;
            count++;
        }
    }
    return count;
}
int maxMeetings2(int n, int start[], int end[]) {
    //Using vector ds
    vector<vector<int>> timing;
    for(int i=0; i<n; i++){
        timing.push_back({end[i], start[i]});
    }
    sort(timing.begin(), timing.end());     //Sort Lexicographically
    for(int i=0; i<timing.size(); i++){
        for(int j=0; j<timing[0].size(); j++){
            cout<<timing[i][j]<<" ";
        }
        cout<<endl;
    }
    int count=0;
    int lastMeet = -1;
    for(int i=0; i<n; i++){
        int startTime = timing[i][1];
        int endTime = timing[i][0];
        if(startTime > lastMeet){
            lastMeet = endTime;
            count++;
        }
    }
    return count;
}
int main() {
    int n1 = 6;
    int start1[] = {1, 3, 0, 5, 8, 5};
    int end1[]   = {2, 4, 6, 7, 9, 9};
    cout << "Maximum meetings: " << maxMeetings2(n1, start1, end1) << endl;

    int n2 = 3;
    int start2[] = {10, 12, 20};
    int end2[] = {20, 25, 30};
    // cout << "Maximum meetings: " << maxMeetings(n2, start2, end2) << endl;

    return 0;
}

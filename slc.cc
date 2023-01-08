#include "slc.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std; 

SLC::SLC(std::string s)
    : Building{s}
{
    cups = 4;
    
    moves.emplace_back(-3);
    moves.emplace_back(-2);
    moves.emplace_back(-1);
    moves.emplace_back(+1);
    moves.emplace_back(+2);
    moves.emplace_back(+3);
    moves.emplace_back(10);
    moves.emplace_back(0);
    
    probs.emplace_back(3);
    probs.emplace_back(4);
    probs.emplace_back(4);
    probs.emplace_back(3);
    probs.emplace_back(4);
    probs.emplace_back(4);
    probs.emplace_back(1);
    probs.emplace_back(1);
    
}

std::string SLC::getName() {
    return name;
}

void SLC::addCup(int a){
    cups = cups + a;
}

int SLC::generate(vector<int> arr, vector<int> freq) {
    srand(time(NULL));  
    
    int n = arr.size();
    int prefix[n], i;
    prefix[0] = freq[0];
    for (i = 1; i < n; ++i)
        prefix[i] = prefix[i - 1] + freq[i];

    // prefix[n-1] is sum of all frequencies.
    // Generate a random number with
    // value from 1 to this sum
    int r = (rand() % prefix[n - 1]) + 1;

    // Find index of ceiling of r in prefix arrat
    int l = 0;
    int h = n-1;
    int mid;
    while (l < h)
    {
        mid = l + ((h - l) >> 1); // Same as mid = (l+h)/2
        (r > prefix[mid]) ? (l = mid + 1) : (h = mid);
    }
    int indexc =  (prefix[l] >= r) ? l : -1;



    int x = arr[indexc];
    return x;
  

}

int SLC::draw() {
    if (cups > 0) {
        int rim = -11;
        vector<int> arr;
        arr.push_back(rim); 
        arr.push_back(11); 
        
        vector<int> freq;
        freq.push_back(1); 
        freq.push_back(99); 
        
        int x = generate(arr, freq);
        
        if (x == rim) {
            --cups;
            return rim;
        } else {
            int x = generate(moves, probs);
            return x;
        }
    } else {
        int x = generate(moves, probs);
        return x;
    }
}













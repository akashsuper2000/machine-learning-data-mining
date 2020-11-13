#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<string> > data = {
    {"Laptop", "Printer", "Tablet", "Headset"},
    {"Printer", "Monitor", "Tablet"},
    {"Laptop", "Printer", "Tablet", "Headset"},
    {"Laptop", "Monitor", "Tablet", "Headset"},
    {"Printer", "Monitor", "Tablet", "Headset"},
    {"Printer", "Tablet", "Headset"},
    {"Monitor", "Tablet"},
    {"Laptop", "Printer", "Monitor"},
    {"Laptop", "Tablet", "Headset"},
    {"Printer", "Tablet"}
  };

  map<vector<string>, int> freq[4];

  for(auto row: data){
    sort(row.begin(), row.end());
    for(int i = 0; i<row.size(); i++){
      freq[1][{row[i]}]++;
      for(int j = i+1; j<row.size(); j++){
        freq[2][{row[i], row[j]}]++;
        for(int k = j+1; k<row.size(); k++){
          freq[3][{row[i], row[j], row[k]}]++;
        }
      }
    }
  }

  int min_samples = 4;
  cout<<"All frequencies: \n";
  for(int i = 1; i<=3; i++){
    for(auto e: freq[i]){
      for(auto word: e.first){
        cout<<word<<' ';
      }
      cout<<" :  "<<e.second<<endl;
    }
    cout<<endl;
  }

  cout<<"Combinations with frequency greater than or equal to min_samples (4): \n";
  for(int i = 2; i<=3; i++){
    for(auto e: freq[i]){
      if(e.second < min_samples) continue;
      for(auto word: e.first){
        cout<<word<<' ';
      }
      cout<<" :  "<<e.second<<endl;
    }
    cout<<endl;
  }
}
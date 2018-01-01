#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Test(const vector<string> x, const string targetString, string current, vector<int> track){
    if(current==targetString)
        return track;
    for(int i=0;i<x.size();i++){
        string copy=current;
        copy+=x[i];
        if(copy==targetString.substr(0,copy.size())){
            track.push_back(i);
            current+=x[i];
            return Test(x,targetString,current,track);
        }
    }
    while(true){
        string remove=x[track.back()];
        current.erase(current.length()-remove.length());
        track.pop_back();
        for(int i=0;i<x.size();i++){
            if(x[i]==remove){
                continue;
            }
            string copy=current;
            copy+=x[i];
            if(copy==targetString.substr(0,copy.size())){
                track.push_back(i);
                current+=x[i];
                return Test(x,targetString,current,track);
            }
        }
    }
}

int main() {
    int size;
    string targetString,copy,string1;
    vector<string> strings;
    vector<int> result,print;
    cout << "Enter a string of symbols: "<<endl;;
    cin>>targetString;
    cout << "Enter the size of the elements set:"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter the string of each set: ";
        cin>>string1;
        strings.push_back(string1);
    }
    print=Test(strings,targetString,copy,result);
    for(int j=0;j<print.size();j++)
        cout<<print[j];
    cout<<endl;
    return 0;
}




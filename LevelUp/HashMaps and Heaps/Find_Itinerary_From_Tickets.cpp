#include<bits/stdc++.h>
using namespace std;

void getItinerary(string currentCity, unordered_map<string, string>& intercityMap, string& itinerary){
    
    if(intercityMap.find(currentCity) == intercityMap.end()){
        return;
    }

    string nextCity = intercityMap[currentCity];
    itinerary.append(" -> ");
    itinerary.append(nextCity);
    getItinerary(nextCity, intercityMap, itinerary);

}

int main(){

    int n;
    cin>>n;

    string rootCity;
    unordered_map<string,bool> rootCityMap;
    unordered_map<string,string> intercityMap;

    while(n--){

        string source, destination;
        cin>>source>>destination;

        intercityMap[source] = destination;
    }

    for(auto p : intercityMap){
        
        string source = p.first;
        string destination = p.second;

        rootCityMap[destination] = false;

        if(rootCityMap.find(source) == rootCityMap.end()){
            rootCityMap[source] = true;
        }
    }

    for(auto p : rootCityMap){
        if(p.second == true){
            rootCity = p.first;
        }
    }

    string ans = rootCity;
    getItinerary(rootCity, intercityMap, ans);

    ans.append(".");
    cout << ans << "\n";
}
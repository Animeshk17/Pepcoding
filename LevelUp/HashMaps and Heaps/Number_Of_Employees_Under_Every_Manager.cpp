#include<bits/stdc++.h>
using namespace std;

int getNumberOfSubordinates(string employee, unordered_map<string,vector<string>>& managerToDirectReportsMap, unordered_map<string,int>& result){
    
    if(managerToDirectReportsMap.find(employee) == managerToDirectReportsMap.end()){
        result[employee] = 0;
        return 0;
    }

    vector<string> directReports = managerToDirectReportsMap[employee];
    
    int numberOfSubordinates = directReports.size();
    
    for(string directReport : directReports){
        numberOfSubordinates += getNumberOfSubordinates(directReport, managerToDirectReportsMap,result);
    }

    result[employee] = numberOfSubordinates;
    return numberOfSubordinates;
}

int main(){
    
    int n;
    cin>>n;

    string ceo;
    unordered_map<string,vector<string>> managerToDirectReportsMap;

    while(n--){

        string employee, manager;
        cin>>employee>>manager;
                
        if(manager != employee){
            managerToDirectReportsMap[manager].push_back(employee);
        }else{
            ceo = manager;
        }
    
    }

    unordered_map<string, int> result;
    getNumberOfSubordinates(ceo, managerToDirectReportsMap, result);

    for(auto p : result){
        cout << p.first << " " << p.second << "\n";
    }

}

//This code gives correct result but the Order of Output is different than the accepted answer
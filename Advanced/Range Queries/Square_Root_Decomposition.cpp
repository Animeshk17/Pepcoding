#include<bits/stdc++.h>
using namespace std;

class Query{
    public:
    int startIndex;
    int endIndex;

    Query(int startIndex, int endIndex){
        this->startIndex = startIndex;
        this->endIndex = endIndex;
    }
};

void takeArrayInput(int* a, int n){
    for(int i = 0; i<n; i++) cin>>a[i];
}

void takeQueriesInput(vector<Query>& queries, int q){
    int start,end;
    for(int i = 0; i<q; i++){
        cin>>start>>end;
        Query q(start,end);
        queries.push_back(q);
    }
}

bool isStart(int i, int len){
    return (i%len==0);
}

int* sqrtDecompositionArray(int* a, int n){

    int len = ceil(sqrt(n));
    int* sqrtArray = new int[len];
    memset(sqrtArray,INT_MAX,sizeof(sqrtArray));

    for(int i = 0; i<n; i++){
        int sqrtArrayIndex = i/len;
        sqrtArray[sqrtArrayIndex] = min(sqrtArray[sqrtArrayIndex],a[i]);
    }
    

    return sqrtArray;
}

void doRangeQueries(int* a, int n, vector<Query>& queries, int q){

    int* sqrtArray = sqrtDecompositionArray(a,n);
    int sqrtLen = ceil(sqrt(n));

    for(Query qry : queries){
        
        int startIndex = qry.startIndex;
        int endIndex = qry.endIndex;
        int minValue = INT_MAX;
        int i = startIndex;

        while(i<=endIndex){
            if(isStart(i,n) && endIndex >= (i+sqrtLen)){
                minValue = min(minValue,a[i/sqrtLen]);
                i+=sqrtLen;
            }else{
                int iter;
                for(iter = i; iter <= min(i+sqrtLen-1,endIndex); iter++) minValue = min(minValue,a[iter]);
                i = iter;
            }
        }
        cout << minValue << '\n';
    }

}

int main(){
    
    int n;
    cin>>n;

    int* a = new int[n];
    takeArrayInput(a,n);

    int q;
    cin>>q;

    vector<Query> queries;
    takeQueriesInput(queries,q);

    doRangeQueries(a,n,queries,q);

    return 0;
}

/* This solution is giving wrong answer on 2 test cases on Pepcoding's website. This is because the test cases are wrong. In one of them 
   despite taking n as 100 there are 101 elements given which results in wrong answer */
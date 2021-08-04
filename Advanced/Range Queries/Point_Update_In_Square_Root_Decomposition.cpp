#include<bits/stdc++.h>
using namespace std;

class Query{
    public:
    char action;
    int startIndex;
    int endIndex;
    int increment;

    Query(char action, int startIndex, int endIndex){
        this->action = action;
        this->startIndex = startIndex;
        this->endIndex = endIndex;
        this->increment = endIndex;
    }
};

void takeArrayInput(int* a, int n){
    for(int i = 0; i<n; i++) cin>>a[i];
}


void takeQueriesInput(vector<Query>& queries, int q){
    char action;
    int startIndex,endIndex;

    for(int i = 0; i<q; i++){
        
        cin>>action>>startIndex>>endIndex;
        Query q(action,startIndex,endIndex);
        queries.push_back(q);
    }
}

int* sqrtDecompositionArray(int* a, int n){

    int len = ceil(sqrt(n));
    int* sqrtArray = new int[len];
    for(int i = 0; i<len; i++) sqrtArray[i] = 0;

    for(int i = 0; i<n; i++){
        int sqrtArrayIndex = i/len;
        sqrtArray[sqrtArrayIndex] += a[i];
    }


    return sqrtArray;
}

bool isStart(int i, int len){
    return (i%len==0);
}

void doRangeQueries(int* a, int n, vector<Query>& queries, int q){

    int* sqrtArray = sqrtDecompositionArray(a,n);
    int sqrtLen = ceil(sqrt(n));

    for(Query qry : queries){

        char action = qry.action;
        int startIndex = qry.startIndex;
        int endIndex = qry.endIndex;
        int rangeSum = 0;

        if(action=='f'){

            int i = startIndex;

            while(i<=endIndex){

                if(isStart(i,n) && endIndex >= (i+sqrtLen)){
                    rangeSum += sqrtArray[i/sqrtLen];
                    i+=sqrtLen;
                }else{
                    int iter;
                    for(iter = i; iter <= min(i+sqrtLen-1,endIndex); iter++){
                        rangeSum += a[iter];
                    }
                    i = iter;
                }

            }

            cout << rangeSum << '\n';
        }

        if(action=='u'){

            int d = qry.increment;
            int i = qry.startIndex;

            a[i] += d;
            sqrtArray[i/sqrtLen] += d;
            
        }
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
    

}

#include <bits/stdc++.h>
using namespace std;

class Pair{
    public:
    int x;
    int y;

    Pair(){

    }

    Pair(int x, int y){
        this->x = x;
        this->y = y;
    }
};

Pair extendedEuclidean(int a, int b){ //pair.x contains x and pair.y contains y
    if(b==0) return Pair(1,0);

    Pair nextLevel = extendedEuclidean(b,a%b);

    Pair ans;
    ans.x = nextLevel.y;
    ans.y = nextLevel.x - (a/b) * nextLevel.y;
    return ans;

}

int main()
{
    int a, b;
    cin >> a >> b;

    Pair soln = extendedEuclidean(a,b);

    cout << soln.x << " " << soln.y << endl;
}














/*
This algorithm is used to find integral solutions of the equation: ax + by = gcd(a,b)

By reversing the steps in the Euclidean algorithm, it is possible to find these integers x and y. 
The whole idea is to start with the GCD and recursively work our way backwards. 
This can be done by treating the numbers as variables until we end up with an expression that is a linear combination of our initial numbers. 

Read More at: https://brilliant.org/wiki/extended-euclidean-algorithm/#
*/
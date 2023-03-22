//
// Created by cxt2004 on 2023/3/16.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <unordered_set>
#include <vector>

const int N = 10000;
const int K = 8500;
const int M = 200000;
using namespace std;
unordered_set<unsigned> table;
vector<unsigned> searchTable;
unsigned genRandomUnsigned() {
    return rand() % RAND_MAX;
}

int main() {
    ofstream foutG("gen");
    foutG << N << ' ' << K << ' ' << M << '\n';
    ofstream fout1("avl_input");
    ofstream fout2("spl_input");
    for(int i = 0; i < N; i++) {
        unsigned k = genRandomUnsigned();
        unsigned v = genRandomUnsigned();
        while(table.find(k) != table.end())
            k = genRandomUnsigned();
        fout1 <<"-i " << k << " " <<v <<'\n';
        fout2 <<"-i " << k << " " <<v <<'\n';

        table.insert(k);
    }
    int tmp = 0;
    for(auto it : table) {
        searchTable.push_back(it);
        if(++tmp > K) break;
    }
    for(tmp = 0; tmp <= M; tmp++) {
        fout1 << "-s " <<searchTable[tmp % K] << '\n';
        fout2 << "-s " <<searchTable[tmp % K] << '\n';

    }
}
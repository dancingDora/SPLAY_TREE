#include <iostream>
#include "SplayTree.h"
#include "Avl.h"
#include <algorithm>
#include<Windows.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <fstream>

using std::cout;

std::ifstream fin1("avl_input");
std::ifstream fin2("spl_input");
std::ifstream fin("gen");
int main() {
    int n,k,m;
    fin >>n >> k >> m;
    cout << "N = " << n << '\n';
    cout << "K = " << k << '\n';
    cout << "M = " << m << '\n';
    AVL<> avl;
    double time = 0;
    double counts = 0;
    LARGE_INTEGER nFreq;
    LARGE_INTEGER nBeginTime;
    LARGE_INTEGER nEndTime;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);
  //  clock_t avlStart = clock();
    string command;
    unsigned l, r;
    {//test for avl tree
        while(fin1 >> command) {
            if(command == "-i") {
                fin1 >> l >> r;
                avl.insert(l, r);
            }
            else if(command == "-s") {
                fin1 >> l;
                avl.search(l);
            }
        }
    }
    QueryPerformanceCounter(&nEndTime);//停止计时
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s

    // clock_t avlEnd = clock();
  //  double avlRes = static_cast<double>(avlEnd - avlStart);
    cout <<"AVL树 时间 ： " << time* 1000 << "ms"<<'\n';
    SplayTree<> spt;
    QueryPerformanceFrequency(&nFreq);
    QueryPerformanceCounter(&nBeginTime);
    {//test for avl tree

        while(fin2 >> command) {
            if(command == "-i") {
                fin2 >> l >> r;
                spt.insert(l, r);
            }
            else if(command == "-s") {
                fin2 >> l;
                spt.search(l);
            }
        }
    }
    QueryPerformanceCounter(&nEndTime);//停止计时
    time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s
    cout <<"Splay 树 时间 ： " << time* 1000 << "ms"<<'\n';
    return 0;
}

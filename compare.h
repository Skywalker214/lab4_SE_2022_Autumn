#include<iostream>
#include<cstring>
#include<vector>
#include<dirent.h>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include"input.h"
#include"output.h"
using namespace std;

class Compare
{
public:
    Input* input;
    
    Compare(Input* i);
    void make_testcase();
    void judge(string file1, string file2);
    void clean_testcase();
};
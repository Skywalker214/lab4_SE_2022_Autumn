#include<iostream>
#include<cstring>
#include<vector>
#include<dirent.h>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Output
{
public:
    string file1;
    string file2;
    bool flag;
    
    Output(string f1,string f2,bool f);
    void write_back();
};
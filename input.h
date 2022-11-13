#include<iostream>
#include<cstring>
#include<vector>
#include<dirent.h>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Input
{
public:
    string path;
    vector<string> file;
    string format;

    Input();
    void input_path();
    void get_file();
};
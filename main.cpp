// /home/simon/SoftwareEngineering/input/
#include"compare.h"
int main()
{
    Input input;
    Compare compare(&input);
    compare.make_testcase();
    for(int i=0;i<compare.input->file.size();i++)
    {
        for(int j=i+1;j<compare.input->file.size();j++)
        {
            compare.judge(compare.input->file[i],compare.input->file[j]);
        }
    }
    compare.clean_testcase();
}
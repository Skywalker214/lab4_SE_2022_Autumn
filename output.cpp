#include"output.h"
Output::Output(string f1,string f2,bool f)
{
    file1=f1.substr(f1.find("input"),f1.length()-f1.find("input"));
    file2=f2.substr(f2.find("input"),f2.length()-f2.find("input"));
    flag=f;
}
void Output::write_back()
{
    if(flag)
    {
        bool flag_=0;
        ifstream temp("output/equal.csv", ios::in);
        if(temp.is_open())
            flag_=1;
        temp.close();
        ofstream equal("output/equal.csv", ios::app);
        if(!flag_)
            equal<<"file1"<<","<<"file2"<<endl;
        equal<<file1<<","<<file2<<endl;
        equal.close();
    }
    else
    {
        bool flag_=0;
        ifstream temp("output/inequal.csv", ios::in);
        if(temp.is_open())
            flag_=1;
        temp.close();
        ofstream inequal("output/inequal.csv", ios::app);
        if(!flag_)
            inequal<<"file1"<<","<<"file2"<<endl;
        inequal<<file1<<","<<file2<<endl;
        inequal.close();
    }
}
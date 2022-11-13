#include"compare.h"
#define num_of_input 10
Compare::Compare(Input* i)
{
    input=i;
}
void Compare::make_testcase()
{
    ifstream f(input->format, ios::in);
    vector<string> format;
    while (!f.fail())
    {
        string temp;
        f >> temp;
        format.push_back(temp);
    }
    f.close();
    srand(time(0));
    for (int j = 0; j < num_of_input; j++)
    {
        string temp = input->path + "/" + "testcase" + to_string(j) + ".txt";
        ofstream testcase(temp, ios::out);
        for (int i = 0; i < format.size()-1; i++)
        {
            switch (format[i][0])
            {
            case 'i':
            {
                int a, b;
                string sa, sb;
                sa = format[i].substr(4, format[i].find(",") - 4);
                sb = format[i].substr(format[i].find(",") + 1, format[i].find(")") - format[i].find(",") - 1);
                a = stoi(sa);
                b = stoi(sb);
                int temp = (rand() % (b - a + 1)) + a;
                testcase << temp << " ";
                break;
            }
            case 'c':
            {
                char temp = (rand() % ('z' - 'a' + 1)) + 'a';
                testcase << temp << " ";
                break;
            }
            case 's':
            {
                int a, b;
                string sa, sb;
                sa = format[i].substr(7, format[i].find(",") - 4);
                sb = format[i].substr(format[i].find(",") + 1, format[i].find(")") - format[i].find(",") - 1);
                a = stoi(sa);
                b = stoi(sb);
                int len = (rand() % (b - a + 1)) + a;
                string temp;
                for (int k = 0; k < len; k++)
                {
                    char t = (rand() % ('z' - 'a' + 1)) + 'a';
                    temp += t;
                }
                testcase << temp << " ";
                break;
            }
            }
        }
        testcase.close();
    }
}

void Compare::judge(string file1, string file2)
{
    string cmd="cd "+input->path;
    system(cmd.c_str());
    string cmd1,cmd2;
    cmd1="g++ -o a.out "+file1;
    cmd2="g++ -o b.out "+file2;
    system(cmd1.c_str());
    system(cmd2.c_str());
    for(int i=0;i<num_of_input;i++)
    {
        string input_file=input->path + "/" + "testcase" + to_string(i) + ".txt";
        cmd1="./a.out <"+input_file+" >output_file1";
        cmd2="./b.out <"+input_file+" >output_file2";
        system(cmd1.c_str());
        system(cmd2.c_str());
        system("diff output_file1 output_file2 >result");
        ifstream f("result", ios::in);
        bool flag=0;
        char c;
        f>>c;
        if(!f.eof())
        {
            flag=1;
        }
        f.close();
        if(flag)
        {
            Output o(file1,file2,0);
            o.write_back();
            system("rm output_file1");
            system("rm output_file2");
            system("rm result");
            system("rm a.out");
            system("rm b.out");
            return;
        }
        system("rm output_file1");
        system("rm output_file2");
        system("rm result");
    }
    Output o(file1,file2,1);
    o.write_back();
    system("rm a.out");
    system("rm b.out");
}

void Compare::clean_testcase()
{
    for(int i=0;i<num_of_input;i++)
    {
        string input_file=input->path + "/" + "testcase" + to_string(i) + ".txt";
        string cmd="rm "+input_file;
        system(cmd.c_str());
    }
}
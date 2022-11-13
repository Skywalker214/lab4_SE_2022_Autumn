#include"input.h"
void Input::input_path()
{
    cout<<"请输入您要比较的文件夹路径：";
    cin>>path;
}
void Input::get_file()
{
    //char dir_name[100];
    //strcpy(dir_name, path.c_str());
    DIR* dir;
    dir = opendir(path.c_str());
    struct dirent* ptr;
    while ((ptr = readdir(dir)) != NULL)
    {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)
        {
            continue;
        }
        if (strcmp(ptr->d_name, "stdin_format.txt") == 0)
        {
            continue;
        }
       //string temp=ptr->d_name;
       string temp=path+"/"+ptr->d_name;
       file.push_back(temp);
    }
    //format="stdin_format.txt";
    format=path+"/"+"stdin_format.txt";
}
Input::Input()
{
    input_path();
    get_file();
}
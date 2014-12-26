#include <cstdlib>
#include <windows.h>
#include <memory.h>
#include <iostream>
#include <fstream>

using namespace std;

long double fibbonocci[1477];

int main(int argc, char *argv[])
{
    fibbonocci[0]=1;
    fibbonocci[1]=1;
    int first=0;
    char *save;
    cout<<"Fibbonocci's Sequence--Enter 0 To Quit:"<<endl;
    cout<<"How many of the first numbers would you like to see (1476 max): ";
    cin>>first;
    if(first>1476||first<=0){return 0;}
    cout<<"Name the file that you want to save to: ";
    cin>>save;
    system("CLS");
    ofstream file(save);
    file<<"Fibbonocci\'s Sequence:\n";
    file<<"First "<<first;
    file<<" Numbers\n=====================\n";
    file<<fibbonocci[0]<<"\n"<<fibbonocci[1]<<"\n";
    int x=2;
    for(x;x<first;x++)
    {
        fibbonocci[x]=(fibbonocci[x-1]+fibbonocci[x-2]);
        file<<fibbonocci[x]<<"\n";
        fibbonocci[x-2]=0;
        file.flush();
    }
    file.close();
    return 1;
}

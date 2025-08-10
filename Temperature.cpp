#include <iostream>
using namespace std;

class rainfall_data
{
    int rainfall[3][7];
    
public:
    void input()
    {
        cout<<"--- Input the temperature data (degree C) for 3  cities over 7 Day ---\n\n";
        for(int i=0;i<3;i++)  //input
        {
            cout<<"City"<<i+1<<":\n";
            for(int j=0;j<7;j++)
            {
                cout<<"Day"<<j+1<<":";
                cin>>rainfall[i][j];
            }
            cout<<"\n";
        }
    }
    void display()
    {
        cout<<"\nTemperature Data (in degree C):\n";
        cout<<"___________________________________________\n";
        cout<<"      ";  //top row
        for(int i=0;i<7;i++)
        {
            cout<<"|"<<"Day"<<i+1<<"\t";
        }
        cout<<"|Average|";
        cout<<"\n";
        
        int a;
        float avg;
        for(int i=0;i<3;i++) //display
        {
            a=0;
              cout<<"City"<<i+1<<":";
            for(int j=0;j<7;j++)
            {
                cout<<"|"<<rainfall[i][j]<<"    \t";
                a+=rainfall[i][j];
            }
                avg=a/7;
                cout<<"|"<<avg<<"\t |";
                cout<<"\n";
        }
        cout<<"___________________________________________\n";
    }
};

int main()
{
    rainfall_data data;
    data.input();
    data.display();
    return 0;
}


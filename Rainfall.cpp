#include <iostream>
using namespace std;

class rainfall_data
{
	int rainfall[3][4];
	
public:
	void input()
	{
		cout<<"--- Input the rainfall data (in mm) for 3  cities over 4 months ---\n\n";
		for(int i=0;i<3;i++)  //input
        {
			cout<<"City"<<i+1<<":\n";
		    for(int j=0;j<4;j++)
		    {
			    cout<<"Month"<<j+1<<":";
			    cin>>rainfall[i][j];
		    }
		    cout<<"\n";
	    }
	}
	void display()
	{
	    cout<<"\nRainfall Data (in mm):\n";
	    cout<<"___________________________________________\n";
		cout<<"      ";  //top row
        for(int i=0;i<4;i++)
        {
		    cout<<"|"<<"Month"<<i+1;
	    }
	    cout<<"|Average|";
	    cout<<"\n";
		
        int a;
        float avg;
        for(int i=0;i<3;i++) //display
        {
	    	a=0;
	  	    cout<<"City"<<i+1<<":";
		    for(int j=0;j<4;j++)
		    {
				cout<<"|"<<rainfall[i][j]<<"    ";
		        a+=rainfall[i][j];
		    }
			    avg=a/4;
		    	cout<<"|"<<avg<<"\t  |";
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


#include<iostream>
using namespace std;

int main()
{
    int m,i,j,temp,key;
    cout<<"Enter number of scores: ";
    cin>>m;
    int p1[m], p2[m];
    cout<<"Enter scores for Player 1:\n";
    for (i=0; i<m; i++) 
    {
        cout<<"Score "<<i+1<<": ";
        cin>>p1[i];
    }
    cout<<"Enter scores for Player 2:\n";
    for (i=0; i<m; i++) 
    {
        cout<<"Score "<<i+1<<": ";
        cin>>p2[i];
    }
    
    cout<<"\nBubble Sort :\n\n";
    for (i=0; i<m; i++)
    {
        for (j=0; j<m-i-1; j++)
        {
            if (p1[j]>p1[j+1])
            {
                cout<<"The number "<<p1[j]<<" is replaced by "<<p1[j+1]<<" Level up!\n";
                temp = p1[j];
                p1[j] = p1[j+1];
                p1[j+1] = temp;
            }
        }
    }
    cout<<"\nScores of player 1 are :";
    for (i=0;i<m;i++)
    {
        cout<<p1[i]<<"  ";    
    }
    cout<<"\n\n";
    for (i=0; i<m; i++)
    {
        for (j=0; j<m-i-1; j++)
        {
            if (p2[j]>p2[j+1])
            {
                cout<<"The number "<<p1[j]<<" is replaced by "<<p1[j+1]<<" Level up!\n";
                temp = p2[j];
                p2[j] = p2[j+1];
                p2[j+1] = temp;
            }
        }
    }
    cout<<"\nScores of player 2 are :";
    for (i=0;i<m;i++)
    {
        cout<<p2[i]<<"  ";    
    }
    return 0;
}    

#include <iostream>
using namespace std;

int main()
{
    //Input number of items, their values and weights
    int nItems;
    cout << "Enter the number of items available:";
    cin >> nItems;

    int Prices[nItems]; 
    float Weight[nItems]; 
    float PtoW[nItems];
    cout <<"Enter price and weight of each item separated by a space:"<<endl;

    for (int i=0; i<nItems; i++)
    {
        cin >> Prices[i] >>Weight[i];
        PtoW[i] = Prices[i]/Weight[i];
        cout << PtoW[i];
    }

    //BUBBLE SORT: Arragne Items in all arrays based on their P/W in descending order
    int flag=0;
    for (int i=0; i<nItems-1; i++)
    {
        for (int j=0; j<nItems-1-i; j++)
        {
            if (PtoW[j] < PtoW[j+1])
            {
                float temp = PtoW[j];
                PtoW[j] = PtoW[j+1];
                PtoW[j+1] = temp;

                int temp = Prices[j];
                Prices[j] = Prices[j+1];
                Prices[j+1] = temp;

                float temp = Weight[j];
                Weight[j] = Weight[j+1];
                Weight[j+1] = temp;

                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }

    //Maximizing the value of the knapsack weighing W
    int W;

    cout << "Enter weight of the knapsack:";
    cin >> W;

    int i=0, TotalP = 0, remainW = W;

    while (remainW >0)
    {
        remainW = remainW - Weight[i];
        TotalP = TotalP + Prices[i];

        if (remainW <0)
        {
            TotalP = TotalP + remainW * (PtoW[i]);
        }
        i++;
    }

    cout << "Total value of knapsack is "<<TotalP;


}
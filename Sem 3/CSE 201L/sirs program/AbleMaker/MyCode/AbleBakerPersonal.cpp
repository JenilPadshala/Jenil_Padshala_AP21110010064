#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
using namespace std;

int main()
{
    /*ABLE's Service Distribution Table*/
    cout << endl
         << endl
         << "ABLE's Service Distribution Table" << endl
         << endl;
    cout << "Service Time\tProbability\tCumulative Probability\tRandom Digits" << endl;
    cout << "2\t\t0.20\t\t\t0.20\t\t01-20" << endl;
    cout << "3\t\t0.30\t\t\t0.50\t\t21-50" << endl;
    cout << "4\t\t0.30\t\t\t0.80\t\t51-80" << endl;
    cout << "5\t\t0.20\t\t\t1.00\t\t81-100" << endl;
    cout << "-----------------------------------------------------------------";

    /*BAKER's Service Distribution Table*/
    cout << endl
         << endl
         << "BAKER's Service Distribution Table" << endl
         << endl;
    cout << "Service Time\tProbability\tCumulative Probability\tRandom Digits" << endl;
    cout << "4\t\t0.20\t\t\t0.20\t\t01-20" << endl;
    cout << "5\t\t0.30\t\t\t0.50\t\t21-50" << endl;
    cout << "6\t\t0.30\t\t\t0.80\t\t51-80" << endl;
    cout << "7\t\t0.20\t\t\t1.00\t\t81-100" << endl;
    cout << "-----------------------------------------------------------------";

    cout << "SIMULATION STARTS" << endl
         << endl;

    srand((unsigned)time(NULL));
    int time, n, id = 0, stA = 0, stB = 0, st1, st2;
    float twt = 0,awt, ttt = 0, att;
    struct caller
    {
        int idNo;      // Caller id no.
        int at;        // Arrival time
        int ft;        // Finish time
        int st;        // Service time
        int rst;       // Remaining service time
        int tt;        // Total time
        int wt;        // Waiting time
        string server; // Server who attended the caller
        struct caller *next;
    };

    struct caller *waiting = NULL;
    struct caller *waitingE = NULL;
    struct caller *attended = NULL;
    struct caller *attendedE = NULL;
    struct caller *temp, *temp1, *temp2;

    for (time = 0; time < 200; time++)
    {
        n = rand() % 100;
        cout << endl<<endl<<"Time " << time<<endl;

        /*Customer arrives probability = 50%*/
        if (n < 50)
        {
            cout << "Customer " << id + 1 << " arrived"<<endl;

            temp = new (caller);
            temp->idNo = ++id;
            temp->at = time;
            temp->st = 0;
            temp->rst = 0;
            temp->tt = 0;
            temp->wt = 0;
            temp->ft = 0;
            temp->server = "NONE";
            temp->next = NULL;
            /*Adding caller to the waiting list*/
            if (waiting == NULL)
            {
                waiting = temp;
                waitingE = temp;
            }
            else if (waiting != NULL)
            {
                waitingE->next = temp;
                waitingE = temp;
            }
        }
        /*Going thru the waiting list*/
        if (waiting != NULL)
        {
            /*If Able is free*/
            if (stA == 0)
            {
                cout << "ABLE is free" << endl;
                temp1 = waiting;
                waiting = waiting->next;
                n = rand() % 100;
                if (n < 20)
                    st1 = 2;
                else if (n < 50)
                    st1 = 3;
                else if (n < 80)
                    st1 = 4;
                else if (n < 100)
                    st1 = 5;
                cout << "ABLE's Serivce Time: " << st1 << endl;
                temp1->st = st1;
                temp1->rst = st1;
                temp1->server = "ABLE";
                stA = 1;
            }
            /*Else if BAKER is free*/
            else if (stB == 0)
            {
                cout << "BAKER is free" << endl;
                temp2 = waiting;
                waiting = waiting->next;
                n = rand() % 100;
                if (n < 20)
                    st2 = 4;
                else if (n < 50)
                    st2 = 5;
                else if (n < 80)
                    st2 = 6;
                else if (n < 100)
                    st2 = 7;
                cout << "BAKERS's Serivce Time: " << st1 << endl;
                temp2->st = st2;
                temp2->rst = st2;
                temp2->server = "BAKER";
                stB = 1;
            }
        }
        /*If ABLE is not free*/
        if (stA == 1)
        {
            temp1->rst -= 1; // reduce service time by 1
            if (temp1->rst == 0)
            {
                stA = 0;
                temp1->ft = time;
                temp1->tt = temp1->ft - temp1->at;
                /*Add the caller to attended list*/
                if (attended == NULL)
                {
                    attended = temp1;
                    attendedE = temp1;
                }
                else
                {
                    attendedE->next = temp1;
                    attendedE = temp1;
                }
                cout << "ABLE got free" << endl;
            }
        }
        if (stA == 1)
            cout << "ABLE is busy"<<endl;
        

        if (stB == 1)
        {
            temp2->rst -= 1; // reduce service time by 1
            if (temp2->rst == 0)
            {
                stB = 0;
                temp2->ft = time;
                temp2->tt = temp2->ft - temp2->at;
                /*Add the caller to attended list*/
                if (attended == NULL)
                {
                    attended = temp2;
                    attendedE = temp2;
                }
                else
                {
                    attendedE->next = temp2;
                    attendedE = temp2;
                }
                cout << "BAKER got free" << endl;
            }
        }
        if (stB == 1)
            cout << "BAKER is busy"<<endl;
        /*adding wait time to all customers in waiting*/
        temp = waiting;
        while (temp!=NULL)
        {
            temp->wt+=1;
            temp = temp->next;
        }
        getch();
    }

    cout <<"END OF THE SIMULATION"<<endl<<endl;
    /*Caluculating avg waiting time and avg turnaround time*/
    temp = attended;
    while (temp != NULL)
    {
        twt += temp->wt;
        ttt += temp->tt;
        temp = temp->next;
    }

    awt = twt/float(id);
    att = ttt/float(id);
    cout <<"Average Waiting Time: "<<awt<<endl;
    cout <<"Average Turn-around Time: "<<att<<endl;
    cout <<"***************************************";
}
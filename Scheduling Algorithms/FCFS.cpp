///  ~~~~~Bismillah'hir Rah'maanir Rahim~~~~~  ///

/*  "  Allah(SWT) blesses with knowledge whom he wants. "   */
/*  " Indeed with Hardship, comes Ease. "    */


///         Originator : Sabrina Mostafa
///         Dept. Of CSE
///         International Islamic University Chittagong




#include<bits/stdc++.h>
using namespace std ;

#define   FastRead      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define   ULL               unsigned long long
#define   LL                  long long
#define   ST                  string
#define   F                    first
#define   S                    second
#define   PB                 push_back
#define   MP                make_pair
#define   pi                   acos(-1.0)
#define   NL                 "\n"
#define    _                    " "

#define YES cout << "YES"<< endl ;
#define NO cout << "NO" << endl ;
#define Yes cout << "Yes" << endl ;
#define No cout << "No" << endl ;
#define yes cout << "yes" << endl ;
#define no cout << "no" << endl ;


int dx4 [ ] = {-1,   0,   0,  +1} ;
int dy4 [ ] = { 0,  -1,  +1,  0} ;
int dx [ ] = {-1,  -1,  -1,   0,   0,  +1,  +1,  +1} ;
int dy [ ] = {-1,   0,  +1,  -1,  +1,  -1,   0,  +1} ;




/*
First Come First Serve (FCFS) Scheduling Algorithm :
        -> FIFO
        -> MODEL : Non-preemptive (fully completion of one task before new task)
*/

int main ()
{

    int process_no, i, j ;
    float t_tat=0, t_wt=0 ; ;

    cout<<"How many processes? : " ;
    cin>>process_no ;

    int Process[process_no+2], Arrival_time[process_no+2], Brust_Time[process_no+2] ;
    int Completion_Time[process_no+2], TurnAround_Time[process_no+2], Waiting_Time[process_no+2] ;

    cout<<"Enter Process Sequence : " ;
    for(i=1; i<=process_no; i++)
        cin>>Process[i] ;

    cout<<"Enter Arrival Time : " ;
    for(i=1; i<=process_no; i++)
        cin>>Arrival_time[i] ;

    cout<<"Enter Brust Time : " ;
    for(i=1; i<=process_no; i++)
        cin>>Brust_Time[i] ;

    for(i=1; i<=process_no; i++)
    {
        for(j=i+1; j<=process_no; j++)
        {
            if(Arrival_time[i]>Arrival_time[j])
            {
                swap(Process[i], Process[j]) ;
                swap(Arrival_time[i], Arrival_time[j]) ;
                swap(Brust_Time[i], Brust_Time[j]) ;
            }
        }
    }

    Completion_Time[0] = 0 ;
    for(i=1; i<=process_no; i++)
    {
        int Idle_Time = 0 ;
        if(Completion_Time[i-1]<Arrival_time[i])
        {
            Idle_Time = Arrival_time[i] - Completion_Time[i-1] ;
        }

        Completion_Time[i] = Completion_Time[i-1] + Brust_Time[i] + Idle_Time ;

        TurnAround_Time[i] = Completion_Time[i] - Arrival_time[i] ;                     // process ta system e jotkkhn sthayi chilo
        t_tat += TurnAround_Time[i] ;

        Waiting_Time[i] = TurnAround_Time[i] - Brust_Time[i] ;
        t_wt += Waiting_Time[i] ;
    }

    for(i=1; i<=process_no; i++)
        cout<<"Completion Time["<<i<<"] = "<<Completion_Time[i]<<endl ;
    cout<<endl ;

    cout<<"Process No\t\tArrival Time\t\t  Brust Time\t\tTurnAround Time\t\tWaiting Time \n" ;
    for(i=1; i<=process_no; i++)
        cout<<"    P["<<Process[i]<<"]\t\t\t"<<Arrival_time[i]<<"\t\t\t"<<Brust_Time[i]<<"\t\t\t"<<TurnAround_Time[i]<<"\t\t\t"<<Waiting_Time[i]<<endl ;
    cout<<endl ;


    float avg_tat = t_tat/process_no ;
    float avg_wt = t_wt/process_no ;
    cout<<"\nAvarage TurnAroung Time : "<<avg_tat<<endl ;
    cout<<"AvarageWaiting Time : "<<avg_wt<<endl ;


    return 0 ;
}

/*
Sample :
How many processes? : 4
Enter Process Sequence : 1 2 3 4
Enter Arrival Time : 0 1 5 6
Enter Brust Time : 2 2 3 4
*/

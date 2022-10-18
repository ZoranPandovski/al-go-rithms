
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()

struct Process {
    int arrival_time,burst_time,completetion_time,turn_around_time,waiting_time,idx;

    Process() {}

    Process(int arrival_time,int burst_time,int idx) {
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->idx = idx;
    }
};

int main() {
    
    int n;
    cin>>n;

    vector<Process>processes,final_processes(n);

    for(int i=0;i<n;i++) {
        int arrival_time,burst_time;
        cin>>arrival_time>>burst_time;
        processes.push_back(Process(arrival_time,burst_time,i));
    }

    sort(all(processes),[&](Process &u,Process &v) {
        return u.arrival_time < v.arrival_time;
    });

    int tme = 1e9;
    int TQ = 2;
    queue<Process>ready_queue;
    vector<bool>vis(n);

    for(auto u:processes) tme = min(tme,u.arrival_time);

    for(int i=0;i<n;i++) {
        if(processes[i].arrival_time == tme) {
            vis[i] = true;
            ready_queue.push(processes[i]);
        }
    }

    while(!ready_queue.empty()) {
        auto s = ready_queue.front();
        ready_queue.pop();

        if(s.burst_time <= TQ) {
            s.completetion_time = tme + s.burst_time;
            s.turn_around_time = s.completetion_time - s.arrival_time;
            s.waiting_time = s.turn_around_time - processes[s.idx].burst_time;
            final_processes[s.idx] = s;
            tme += s.burst_time;
            s.burst_time = 0;
        }
        else {
            s.burst_time -= TQ;
            tme += TQ;
        }

        for(int i=0;i<n;i++) {
            if(!vis[i] and tme>=processes[i].arrival_time) {
                ready_queue.push(processes[i]);
                vis[i] = true;
            }
        }

        if(s.burst_time) {
            ready_queue.push(s);
        }

        if(ready_queue.empty()) {
            for(int i=0;i<n;i++) {
                if(!vis[i]) tme = min(tme,processes[i].arrival_time);
            }

            for(int i=0;i<n;i++) {
                if(!vis[i] and tme == processes[i].arrival_time) {
                    vis[i] = true;
                    ready_queue.push(processes[i]);
                }
            }
        }
    }

    for(auto u:final_processes) {
        cout<<u.arrival_time<<' '<<u.burst_time<<' '<<u.completetion_time<<' '<<u.turn_around_time<<' '<<u.waiting_time<<"\n";
    }

    return 0;
}

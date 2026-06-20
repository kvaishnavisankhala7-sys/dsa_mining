#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct MiningZone {
    string name;
    int profit;
};

struct Inventory {
    int id;
    string mineral;
};

struct Equipment {
    string id;
    string status;
};

class SmartMiningPlatform {
private:

    queue<string> alerts;

    vector<MiningZone> zones;

    vector<Inventory> inventory = {
        {1001,"Coal"},
        {1002,"Iron Ore"},
        {1003,"Copper"},
        {1004,"Gold"},
        {1005,"Limestone"}
    };

    vector<Equipment> equipments = {
        {"EX01","Active"},
        {"EX02","Maintenance"},
        {"EX03","Active"},
        {"EX04","Failure"}
    };

    vector<vector<int>> graph;

public:

    SmartMiningPlatform() {

        zones.push_back({"North Mine",95});
        zones.push_back({"South Mine",70});
        zones.push_back({"East Mine",88});
        zones.push_back({"West Mine",60});

        alerts.push("Gas Leakage Alert");
        alerts.push("Machine Failure Alert");
        alerts.push("Low Oxygen Warning");

        graph.resize(6);

        graph[0]={1,2};
        graph[1]={0,3};
        graph[2]={0,4};
        graph[3]={1,5};
        graph[4]={2};
        graph[5]={3};
    }

    // QUEUE

    void processEvents() {

        int choice;

        do {

            cout<<"\n--- Event Processing System ---\n";
            cout<<"1. Add Alert\n";
            cout<<"2. Process Alert\n";
            cout<<"3. Display Alerts\n";
            cout<<"4. Back\n";
            cout<<"Enter Choice: ";
            cin>>choice;

            cin.ignore();

            switch(choice) {

                case 1: {
                    string alert;
                    cout<<"Enter Alert: ";
                    getline(cin,alert);
                    alerts.push(alert);
                    break;
                }

                case 2:
                    if(alerts.empty())
                        cout<<"No Alerts Pending\n";
                    else {
                        cout<<"Processing: "<<alerts.front()<<endl;
                        alerts.pop();
                    }
                    break;

                case 3: {

                    queue<string> temp = alerts;

                    if(temp.empty()) {
                        cout<<"No Alerts\n";
                    }

                    while(!temp.empty()) {
                        cout<<temp.front()<<endl;
                        temp.pop();
                    }

                    break;
                }
            }

        } while(choice!=4);
    }

    // HEAP SORT

    void rankZones() {

        vector<MiningZone> temp = zones;

        make_heap(temp.begin(),temp.end(),
        [](MiningZone a, MiningZone b){
            return a.profit < b.profit;
        });

        sort_heap(temp.begin(),temp.end(),
        [](MiningZone a, MiningZone b){
            return a.profit < b.profit;
        });

        cout<<"\n--- Extraction Ranking ---\n";

        for(int i=temp.size()-1;i>=0;i--) {

            cout<<temp[i].name
                <<" Profit: "
                <<temp[i].profit
                <<endl;
        }
    }

    // BINARY SEARCH

    void searchInventory() {

        int id;


        cout<<"\nValid IDs: 1001 - 1005\n";
        cout<<"Enter Mineral ID: ";
        cin>>id;

        vector<int> ids;

        for(auto item : inventory)
            ids.push_back(item.id);

        int left=0;
        int right=ids.size()-1;

        bool found=false;

        while(left<=right) {

            int mid=(left+right)/2;

            if(ids[mid]==id) {

                cout<<"Mineral Found: "
                    <<inventory[mid].mineral
                    <<endl;

                found=true;
                break;
            }

            else if(ids[mid]<id)
                left=mid+1;

            else
                right=mid-1;
        }

        if(!found)
            cout<<"Mineral Not Found\n";
    }

    // BFS

    void evacuationPlanning() {

        vector<bool> visited(graph.size(),false);

        queue<int> q;

        q.push(0);
        visited[0]=true;

        cout<<"\nFastest Evacuation Route: ";

        while(!q.empty()) {

            int node=q.front();
            q.pop();

            string tunnelNames[] = {
    "Main Entrance",
    "North Tunnel",
    "South Tunnel",
    "Safety Exit A",
    "Safety Exit B",
    "Emergency Exit"
};

cout << tunnelNames[node] << endl;

            for(int neighbour : graph[node]) {

                if(!visited[neighbour]) {

                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }

        cout<<endl;
    }

    // DFS

    void DFS(int node, vector<bool>& visited) {

        visited[node]=true;

        string tunnelNames[] = {
    "Main Entrance",
    "North Tunnel",
    "South Tunnel",
    "Safety Exit A",
    "Safety Exit B",
    "Emergency Exit"
};

cout << tunnelNames[node] << endl;

        for(int neighbour : graph[node]) {

            if(!visited[neighbour])
                DFS(neighbour,visited);
        }
    }

    void tunnelInvestigation() {

        vector<bool> visited(graph.size(),false);

        cout<<"\nTunnel Investigation Path: ";

        DFS(0,visited);

        cout<<endl;
    }

    // EQUIPMENT

    void equipmentMonitoring() {

        cout<<"\n--- Equipment Monitoring ---\n";

        for(auto e : equipments) {

            cout<<e.id
                <<" - "
                <<e.status
                <<endl;
        }
    }

    // DASHBOARD

    void safetyDashboard() {

        cout<<"\n--- Safety Dashboard ---\n";

        cout<<"Pending Alerts: "
            <<alerts.size()
            <<endl;

        cout<<"Emergency Status: Active Monitoring\n";
    }

    // ANALYTICS

    void analytics() {

        cout<<"\n--- Operational Analytics ---\n";

        cout<<"Total Inventory Items: "
            <<inventory.size()
            <<endl;

        cout<<"Total Equipment: "
            <<equipments.size()
            <<endl;

        cout<<"Pending Alerts: "
            <<alerts.size()
            <<endl;

        MiningZone best = zones[0];

        for(auto z : zones) {

            if(z.profit > best.profit)
                best=z;
        }

        cout<<"Most Profitable Zone: "
            <<best.name
            <<" ("
            <<best.profit
            <<")\n";
    }
};

int main() {

    SmartMiningPlatform mine;

    int choice;

    do {

        cout<<"\n";
        cout<<"=================================\n";
        cout<<"SMART MINING OPERATIONS PLATFORM\n";
        cout<<"=================================\n";

        cout<<"1. Manage Alerts\n";
        cout<<"2. Rank Mining Areas\n";
        cout<<"3. Search Minerals\n";
        cout<<"4. Find Emergency Route\n";
        cout<<"5. Explore Tunnels\n";
        cout<<"6. Check Equipment Status\n";
        cout<<"7. Safety Dashboard\n";
        cout<<"8. View Reports\n";
        cout<<"9. Exit\n";

        cout<<"Enter Choice: ";
        cin>>choice;

        switch(choice) {

            case 1:
                mine.processEvents();
                break;

            case 2:
                mine.rankZones();
                break;

            case 3:
                mine.searchInventory();
                break;

            case 4:
                mine.evacuationPlanning();
                break;

            case 5:
                mine.tunnelInvestigation();
                break;

            case 6:
                mine.equipmentMonitoring();
                break;

            case 7:
                mine.safetyDashboard();
                break;

            case 8:
                mine.analytics();
                break;
        }

    } while(choice!=9);

    cout<<"\nProject Exited Successfully\n";

    return 0;
} 
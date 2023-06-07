#include <iostream>
#include <set>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    set<int> solved_teams;
    for (int i = 0; i < m; i++) {
        int ci;
        cin >> ci;
        for (int j = 0; j < ci; j++) {
            int team;
            cin >> team;
            solved_teams.insert(team);
        }
    }
    cout << solved_teams.size() << endl;
    return 0;
}
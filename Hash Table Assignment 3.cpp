#include <iostream>
#include <string>
using namespace std;

// Simple hash function for IP addresses (string -> int)
int hashIP(const string& ip) {
    int hash = 0;
    for (char c : ip) {
        hash += (int)c;  // sum ASCII values
    }
    return hash;
}

int main() {
    int s, r;

    cout << "Enter number of servers: ";
    cin >> s;

    cout << "Enter number of requests: ";
    cin >> r;

    // Condition: requests must not exceed servers
    if (r > s) {
        cout << "Error: Number of requests cannot be more than number of servers.\n";
        return 0;
    }

    string* requests = new string[r];   // store all IP requests
    string* servers = new string[s];    // hash table representing servers

    // Initialize servers as empty
    for (int i = 0; i < s; i++) {
        servers[i] = "";
    }

    cout << "\nEnter " << r << " IP addresses:\n";
    for (int i = 0; i < r; i++) {
        cout << "Request " << i + 1 << ": ";
        cin >> requests[i];
    }

    cout << "\n--- Load Balancer Assignment (with Linear Probing) ---\n";
    for (int i = 0; i < r; i++) {
        string ip = requests[i];
        int hash_val = hashIP(ip);
        int serverID = hash_val % s;

        // Collision handling with linear probing
        if (servers[serverID] == "") {
            servers[serverID] = ip;
        } else {
            int new_pos = (serverID + 1) % s;
            while (servers[new_pos] != "" && new_pos != serverID) {
                new_pos = (new_pos + 1) % s;
            }
            servers[new_pos] = ip;
            serverID = new_pos;
        }

        cout << "IP " << ip 
             << " is assigned to Server " << serverID + 1 << "\n";
    }

    cout << "\n--- Final Server Status ---\n";
    for (int i = 0; i < s; i++) {
        if (servers[i] == "")
            cout << "Server " << i + 1 << ": [empty]\n";
        else
            cout << "Server " << i + 1 << ": IP " << servers[i] << "\n";
    }

    delete[] requests;
    delete[] servers;

    return 0;
}


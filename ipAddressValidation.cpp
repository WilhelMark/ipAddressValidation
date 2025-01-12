#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Function for obtaining a separate part of the IP address (octomet)
string get_address_part(const string& ip, int part) {
    stringstream ss(ip);
    string token;
    int count = 0;

    // Divide the line by points
    while (getline(ss, token, '.')) {
        if (count == part) {
            return token; // Return the desired octet
        }
        count++;
    }
    return ""; // If not found octet
}
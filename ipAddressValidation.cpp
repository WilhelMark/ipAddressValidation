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

// Function for checking the correctness of octomet
bool is_valid_octet(const string& octet) {
    //Check the length of the octomet
    if (octet.length() == 0 || octet.length() > 3) {
        return false;
    }

    // Check the presence of leading zeros
    if (octet.length() > 1 && octet[0] == '0') {
        return false;
    }

    // We check that all characters are numbers
    for (char c : octet) {
        if (c < '0' || c > '9') {
            return false;
        }
    }

    // We convert the line into the number and check the range
    int value = stoi(octet);
    return value >= 0 && value <= 255;
}

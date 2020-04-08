#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
    string input, nameTemp;
    int numGifters, moneyTemp, numPeople, moneySpent;
    map<string, int> peopleMoney;
    vector<string> names;
    bool print = false;
    
    // group consists of several lines
    while (getline(cin, input)){
        if(print){
            cout << endl;
        }
        // the number of people in the group
        stringstream ss(input);
        ss >> numGifters;
        ss.clear();
        // a list of the names of each person in the group
        getline(cin, input);
        ss.str(input);
        for (int i = 0; i < numGifters; i++){
            ss >> nameTemp;
            peopleMoney.insert(make_pair(nameTemp, 0));
            names.push_back(nameTemp);
        }
        ss.clear();
        // a line for each person in the group consisting of
        //  name of the person
        //  the amount of money spent on gifts
        //  the number of people to whom gifts are given
        //  the names of those to whom gifts are given
        for (int i = 0; i < numGifters; i++){
            getline(cin, input);
            ss.str(input);
            ss >> nameTemp >> moneyTemp >> numPeople;
            moneySpent = (numPeople == 0) ? 0 : moneyTemp/numPeople;
            peopleMoney[nameTemp] = peopleMoney[nameTemp] - moneySpent*numPeople;
            for (int i = 0; i < numPeople; i++){
                ss >> nameTemp;
                peopleMoney[nameTemp] = peopleMoney[nameTemp]+moneySpent;
            }
            ss.clear();
        }
        for (int i = 0; i < numGifters; i++){
            cout << names[i] << " " << peopleMoney[names[i]] << endl;
        }
        names.clear();
        peopleMoney.clear();
        print = true;
    }

    return EXIT_SUCCESS;
}
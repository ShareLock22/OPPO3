#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Sea.h"
#include "FIsh.h"

using namespace std;

void load_txt(vector<Sea>& data, istream& ist)
{
    while (!ist.eof())
    {
        Sea d = Sea::load_txt(ist);
        data.push_back(d);
    }
}

void print_data(vector<Sea>& data, ofstream& ost)
{
    for (int i = 0; i < data.size(); i++)
    {
        data[i].print_txt(ost);
        cout << endl;
    }
}

int main()
{
    vector <Sea> data;
    ifstream in("ist.txt");
    ofstream ost("ost.txt");
    load_txt(data, in);
    print_data(data, ost);
    return 0;
}

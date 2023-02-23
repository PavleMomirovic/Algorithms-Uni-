#include<iostream>
#include<fstream>
#include"Event.h"
#include <vector>
#include<algorithm>
using namespace std;

bool compareEvents(Event a, Event b) {
    if (a.GetStart() < b.GetStart()) return true;
    else return false;
}
void Solve(vector<Event> events,int n)
{
    sort(events.begin(), events.end(), compareEvents);
    vector<Event> output;

    output.push_back(events[0]);

    for (int i = 1; i < events.size(); i++)
    {
        if (events[i].GetStart() >= output[output.size() - 1].GetEnd())
        {
            output.push_back(events[i]);
        }
    }

    for (Event event : output)
    {
        cout << "Event: " << event.GetStart() << " " << event.GetEnd() << endl;
    }
}

int main() {


	//reading the file:

	vector<Event> events;
    char s[10];
    int a, b;

    ifstream input_file("C://Users//pajap//source//repos//IntervalScheduling//IntervalScheduling//data1-intervals.txt");

    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"<< endl;
        exit(0);
    }
    input_file >> s >>s;

    while (input_file >> a >> b) {
        Event e(a, b);
        events.push_back(e);
    }

    //pritning intervals for testing purposes
    /*for (Event e : events) {
        cout << "S: " << e.GetStart() << " F: " << e.GetEnd() << endl;
    }*/

    Solve(events, events.size());


	return 0;
}
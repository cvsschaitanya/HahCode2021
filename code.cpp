#include <bits/stdc++.h>

using namespace std;

struct street
{
    int start, end;
    string name;
    int L;
};
map<string, street> streetmap;

struct intersection
{
    int id;
    vector<string> In, Out;
};
map<int, intersection*> intermap;

typedef vector<string> Car;

vector<street> streets;

int main()
{
    ifstream fin("a.txt");
    int D, I, S, V, F;
    fin >> D >> I >> S >> V >> F;
    streets = vector<street>(S);
    for (int i = 0; i < S; ++i)
    {
        fin >> streets[i].start >> streets[i].end >> streets[i].name >> streets[i].L;
        streetmap[streets[i].name] = streets[i];
        if(intermap[streets[i].start]==NULL){
            intermap[streets[i].start] = new intersection;
            intermap[streets[i].start]->idstreets[i].start;
            intermap[streets[i].start]->Out.push_back(streets[i].name);
        }
        else{
            intermap[streets[i].start]->Out.push_back(streets[i].name);
        }
        
        if(intermap[streets[i].end]==NULL){
            intermap[streets[i].end] = new intersection;
            intermap[streets[i].end]->idstreets[i].end;
            intermap[streets[i].end]->In.push_back(streets[i].name);
        }
        else{
            intermap[streets[i].end]->In.push_back(streets[i].name);
        }
    }
    int n;
    string str;
    Car car;
    for (int i = 0; i < V; ++i)
    {
        fin >> n;
        car.clear();
        for (int j = 0; j < n; ++j)
        {
            fin >> str;
            car.push_back(str);
        }
    }

    
}
#include <bits/stdc++.h>

using namespace std;

struct Street
{
    int start, end;
    string name;
    int L;
    int initCars;

    // bool operator<(Street s2)
    // {
    //     return this->initCars < s2->initCars;
    // }
};
map<string, Street> streetmap;

struct intersection
{
    int id;
    vector<string> In, Out;
};
map<int, intersection *> intermap;

typedef vector<string> Car;

bool carsOrder(string streetname1, string streetname2)
{
    return streetmap[streetname1].initCars > streetmap[streetname2].initCars;
}

int main()
{
    ifstream fin("f.txt");
    ofstream fout("F.txt");

    int D, I, S, V, F;
    fin >> D >> I >> S >> V >> F;
    Street street;
    for (int i = 0; i < S; ++i)
    {
        fin >> street.start >> street.end >> street.name >> street.L;
        street.initCars = 0;
        streetmap[street.name] = street;
        if (intermap[street.start] == NULL)
        {
            intermap[street.start] = new intersection;
            intermap[street.start]->id = street.start;
            intermap[street.start]->Out.push_back(street.name);
        }
        else
        {
            intermap[street.start]->Out.push_back(street.name);
        }

        if (intermap[street.end] == NULL)
        {
            intermap[street.end] = new intersection;
            intermap[street.end]->id = street.end;
            intermap[street.end]->In.push_back(street.name);
        }
        else
        {
            intermap[street.end]->In.push_back(street.name);
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
            if (j == 0)
            {
                streetmap[str].initCars++;
            }
            car.push_back(str);
        }
    }

    fout << intermap.size() << endl;
    for (auto p : intermap)
    {
        intersection *I = p.second;
        string resultStreet;
        int maxCars = INT_MIN;
        // for (string streetname : I->In)
        // {
        //     if (streetmap[streetname].initCars > maxCars)
        //     {
        //         maxCars = streetmap[streetname].initCars;
        //         resultStreet = streetname;
        //     }
        // }

        vector<string> inStreets = I->In;
        std::sort(inStreets.begin(), inStreets.end(), carsOrder);

        while (!inStreets.empty() && streetmap[inStreets.back()].initCars == 0)
        {
            inStreets.pop_back();
        }

        fout << I->id << endl;

        if (inStreets.empty())
        {
            fout << I->In.size() << endl;
            for (string streetname : I->In)
            {
                fout << streetname << ' ' << 1 << endl;
            }
            continue;
        }

        fout << inStreets.size() << endl;

        for (string streetname : inStreets)
        {
            fout << streetname << ' ' << streetmap[streetname].initCars << endl;
        }
    }
}
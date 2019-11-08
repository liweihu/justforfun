#include <iostream>
#include <functional>
#include <list>
#include <map>

using namespace std;

struct billionaire {
    string name;
    double dollars;
    string country;
};

int main(){
    list<billionaire> billionaires {
        {"Bill Gates", 86.0, "USA"},
        {"Warren Buffet", 75.3, "USA"},
        {"Jeff Bezos", 72.9, "USA"},
        {"Jack Ma", 70.2, "China"},
        {"Amanic Bean", 66.6, "Spain"},
        {"KKop Sha", 62.0, "USA"},
        {"Tony Ma", 56.0, "China"}
    };

    map<string, pair<const billionaire, size_t>> m;

    for( const auto &b : billionaires){
        auto [iterator, success] = m.try_emplace(b.country, b, 1);

        if(!success)
            iterator->second.second += 1;
    }

    for( const auto &[key, value] : m ){
        const auto & [b, count] = value;

        cout<< b.country << " : "<< count << " billionaires. Richest is " <<b.name<< " with " << b.dollars << "B$\n";
    }
}

#include <iostream>
#include <map>

using namespace std;

template<typename T>
void print(const T &t){
    cout << "Race placement:\n";
    for(const auto &[placement, driver] : t) {
        cout << placement << " : " << driver << "\n";
    }
}

int main(){
    map<int, string> race_placement {
        {1, "huliwei1"}, {2, "huliwei2"},
        {3, "huliwei3"}, {4, "huliwei4"},
        {5, "huliwei3"}, {6, "huliwei4"},
        {7, "huliwei3"}, {8, "huliwei4"}};

    print(race_placement);

    {
        auto a(race_placement.extract(3));
        auto b(race_placement.extract(6));

        swap(a.key(), b.key());

        print(race_placement);

        race_placement.insert(move(a));
        race_placement.insert(move(b));

        print(race_placement);
    }
}

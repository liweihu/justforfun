#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cassert>

using namespace std;

void insert_sorted(vector<string> &v, const string &word){
    const auto insert_pos(lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}

void sorted_vector(){
    vector<string> v{"hello", "allen", "zz", "konl", "uoun"};

    assert(false == is_sorted(begin(v), end(v)));
    sort(begin(v), end(v));
    assert(true == is_sorted(begin(v), end(v)));

    insert_sorted(v, "ppoo");
    insert_sorted(v, "bop");

    for(const auto &w : v){
        cout << w << " ";
    }
    cout << endl;
}

void del01(){
    vector<int> v {1,2,3,2,5,2,6,2,4,8};

    {
        const auto new_end(remove(begin(v), end(v), 2));

        cout << "New End: " << endl;
        v.erase(new_end, end(v));
    }

    for(auto i: v){
        cout << i << ", ";
    }

    cout << '\n';

    {
        const auto odd([](int i){ return i%2 != 0; });
        v.erase(remove_if( begin(v), end(v), odd), end(v));
    }

    // v.shrink_to_fit();

    for(auto i:v){
        cout <<i <<", ";
    }

    cout<<'\n';
}

template<typename T>
void quick_remove_at(std::vector<T> &v, std::size_t idx){
    if(idx < v.size()){
        v.at(idx) = std::move(v.back());
        v.pop_back();
    }
}

// attention for the second typename
template<typename T>
void quick_remove_at(std::vector<T> &v, typename std::vector<T>::iterator it){
    if(it != std::end(v)){
        *it = std::move(v.back());
        v.pop_back();
    }
}

void del02() {
   vector<int> v{100, 200, 300, 400, 50};
   quick_remove_at(v, 2);
   for(auto i : v){
       cout << i << ", ";
   }

   cout << endl;

   quick_remove_at(v, std::find(std::begin(v), std::end(v), 400));

   for( auto i: v){
       cout << i << ", ";
   }
   cout << endl;
}

int main() {
    // del01();
    // del02();
    sorted_vector();
}

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v ){
    for(int i=0; i<v.size(); i++) {
        cout << v[i] <<' ';
    }
    cout<<endl;
}

int main() {
    vector<int> v;
    vector<int> v2;

    v.resize(5,0);
    v2.resize(6,0);

    for(int i=0; i<5; i++){
        cin >> v[i];
    }

    print_vector(v);

    cout<<endl;

    v.insert(v.begin()+2, 99);

    print_vector(v);

    v.erase(v.begin() +4);

    print_vector(v);

    v.resize(6, 0);

    print_vector(v);

    v.assign(v.size(), 1);

    print_vector(v);
    cout<<endl;

    v.swap(v2);

    cout<< "v: ";
    print_vector(v);

    cout<< "v2: ";
    print_vector(v2);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU {
    public:
    unordered_map<ll  , ll>parent;
    unordered_map<ll , ll>size;

    DSU(int size){
        for(int i = 1; i <= size; i ++){
            parent[i] = i;
            this->size[i] = 1;
        }
    }

    ll find(ll num){
        while(num != parent[num]){
            parent[num] = parent[parent[num]];
            num = parent[num];
        }
        return num;
    }

    bool unify(ll node1 , ll node2){
        ll parent1 = this->find(node1);
        ll parent2 = this->find(node2);

        if(parent1 == parent2){
            return false;
        }

        if(size[parent2] > size[parent1]){
            ll temp = parent1;
            parent1 = parent2;
            parent2 = temp;
        }

        size[parent1] += size[parent2];
        parent[parent2] = parent1;

        return true;
    }

    bool is_connected(ll node1 , ll node2){
        return find(node1) == find(node2);
    }
};
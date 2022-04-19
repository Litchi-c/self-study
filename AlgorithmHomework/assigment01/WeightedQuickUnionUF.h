//
// Created by sugar on 4/18/22.
//

#ifndef ASSIGMENT01_WEIGHTEDQUICKUNIONUF_H
#define ASSIGMENT01_WEIGHTEDQUICKUNIONUF_H
#include <vector>
using std::vector;
class WeightedQuickUnionUF{
private:
    vector<int> id_;
    int n_;
public:
    explicit WeightedQuickUnionUF(int num):n_{num}{
        id_.resize(n_);
        for (int i = 0; i < id_.size(); i++){
            id_[i] = i;
        }
    }
    int root(int i){
        // O(N)
        while(i != id_[i]) {
            id_[i] = id_[id_[i]];
            i = id_[i];
        }
        return i;
    }
    bool connected(int p, int q){
        // O(N)
        return root(p) == root(q);
    }
    void UFunion(int p, int q){
        // O(2N)
        int i = root(p);
        int j = root(q);
        id_[i] = j;
    }
#endif //ASSIGMENT01_WEIGHTEDQUICKUNIONUF_H

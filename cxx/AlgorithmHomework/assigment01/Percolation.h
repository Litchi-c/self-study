//
// Created by sugar on 2022/4/30.
//

#ifndef ASSIGMENT01_PERCOLATION_H
#define ASSIGMENT01_PERCOLATION_H

#include <cassert>
#include "WeightedQuickUnionUF.h"
#include "Random.h"

/* ASSUME:  1 is close
 *          0 is open
 * */


class Percolation {
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation(int n):size_(n){
        assert(n > 0);
        int (*TwoDArray)[size_][size_] = new int[size_][size_];
        TwoDArray_ = TwoDArray;
        for (int i = 0; i < size_; i++){
            for (int j = 0; j < size_; j++){
                TwoDArray[i][j] = 1;
            }
        }
    }

    // opens the site (row, col) if it is not open already
    void open(int row, int col){
        if (TwoDArray_ != nullptr)
            TwoDArray_[row][col] = 0;
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col){
        if (TwoDArray_ != nullptr)
            return TwoDArray_[row][col] == 0;
    }

    // is the site (row, col) full?
    bool isFull(int row, int col);

    // returns the number of open sites
    int numberOfOpenSites();

    // does the system percolate?
    bool percolates();

private:
    int size_;
    int *TwoDArray_;


};


#endif //ASSIGMENT01_PERCOLATION_H

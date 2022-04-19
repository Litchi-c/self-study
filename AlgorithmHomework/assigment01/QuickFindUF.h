#ifndef ASSIGMENT01_QUICKFINDUF_H
#define ASSIGMENT01_QUICKFINDUF_H
#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

class QuickFindUF{
		friend std::ostream& operator<<(std::ostream &os,QuickFindUF &uf);		
public:
	  explicit QuickFindUF(int num): n_(num){
				// O(N)
				assert(n_ >= 0);
				for (int i = 0; i < n_; ++i){
						id_.emplace_back(i);
				}		
		}
		
		bool connected(int p, int q){
				// O(1)
				return id_[p] == id_[q];
		}

		void UFunion(int p, int q){
				// O(N)
				int pid = id_[p];
				int qid = id_[q];
// 如果不先保存pid与qid的值，这里会有一个小bug
// 如果 循环写成
// loop:
//     if id[i] == id[q]
//				id[i] == id[p]
// 当id[i] 是 id[q] 时，会导致与q相同的值无法被修改了
				for (int i = 0; i < id_.size(); ++i){
						if (id_[i] == pid)
								id_[i] = qid;
				}
		}

private:
		int n_  = 0;
		std::vector<int> id_;
};


std::ostream &operator<<(std::ostream& os, QuickFindUF &uf){
		for (int i = 0; i < uf.id_.size(); ++i){
				os << uf.id_[i] << " ";
		}
		os << std::endl;
		return os;
}
#endif ASSIGMENT01_QUICKFINDUF_H

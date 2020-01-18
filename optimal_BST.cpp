//optimal binary search tree
//input: probabilities p[] and q[],and size n
//return: expected cost table e and root
using namespace std;
#include<iostream>

float INFOF = 1000;

struct bst_sol {
	float** e;
	int** root;
};
typedef bst_sol* bstsolptr;

bstsolptr optimal_BST(float* p, float* q, int n) {
	//e:expected cost table
	float** e = (float**)malloc(sizeof(float*) * n);
	for (int i = 0;i < n;i++) 
		e[i] = (float*)malloc(sizeof(float) * n);
	//root:to record the roots of optimal BST
	int** root=(int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++)
		root[i] = (int*)malloc(sizeof(int) * n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			e[i][j] = INFOF;
			root[i][j] = n;
		}
	}
	//w:the sum of probalities from i to j
	float** w = (float**)malloc(sizeof(float*) * n);
	for (int i = 0;i < n;i++)
		w[i] = (float*)malloc(sizeof(float) * n);
	for (int i = 0;i < n;i++) {
		for (int j = i;j < n;j++) {
			w[i][j] = 0;
			for (int k = i;k <= j;k++)
				w[i][j] = w[i][j]+p[k] + q[k];
			w[i][j] = w[i][j] + q[j + 1];
		}
	}
	float tempe = 0;
	for (int d = 0;d < n;d++) {//the difference between the beginning and ending of subproblem
		for (int i = 0;i < n-d;i++) {//the beginning of the subproblem
			int j = i + d;
			for (int r = i;r <= j;r++) {
				if (i == j)
					tempe = w[i][j];
				else if (r == i)
					tempe = e[r + 1][j] + w[i][j];
				else if (r == j)
					tempe = e[i][r - 1] + w[i][j];
				else
					tempe = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (tempe < e[i][j]) {
					e[i][j] = tempe;
					root[i][j] = r;
				}
			}
		}
	}
	bst_sol* sol = new bst_sol;
	sol->e = e;
	sol->root = root;
	return sol;
}

void trackroots(int** root,int i,int j) {
	if(i == j-1||i==j)
		return;
	else {
		int r = root[i][j];
		cout << r << endl;//return these roots, which has left and right child
		trackroots(root, i, r - 1);
		trackroots(root, r + 1, j);
	}
}

//test
int main() {
	const int n = 6;
	const int s[n] = { 1,2,3,4,5,6 };//key set
	float p[n] = { 0.1,0.2,0.2,0.1,0.1,0.05 }; 
	float q[n+1] = { 0.04,0.01,0.05,0.02,0.02,0.07,0.04 };
	bst_sol* sol = optimal_BST(p, q, n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << sol->e[i][j] << "   ";
		}
		cout << endl;
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << sol->root[i][j] << "   ";
		}
		cout << endl;
	}
	trackroots(sol->root,0,n-1);
}

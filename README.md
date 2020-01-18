# optimal-binary-search-tree

input: probabilities p[] and q[],and size of keys set: n

return: expected cost table e and root

subproblem: for i to j

recursive equation:


	e[i,j]=	0	j=i-1

		min{e[i,r-1]+e[r+1,j]+w(i,j)}	i<=j,1<=r<=j
and

		w(i,j)=sum(pk)+sum(ql)	i<=k<=j,i-1<=l<=j
    
e[i,j] means the expected search cost of key[i] to key[j]

w[i,j] comes when a subproblem yields, and the depth of each keys in the subproblem will be +1, so add the sum of all the relative probabilities with the left child's e[i,r-1] and the right child's e[r+1,j], we can get the e[i,j].

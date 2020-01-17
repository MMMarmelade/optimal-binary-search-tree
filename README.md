# optimal-binary-search-tree

input: probabilities p[] and q[],and size of keys set: n

return: expected cost table e and root

subproblem: for i to j

recursive equation:


e[i,j]=	0	j=i-1

		min{e[i,r-1]+e[r+1,j]+w(i,j)}	i<=j,1<=r<=j
    
		w(i,j)=sum(pk)+sum(ql)	i<=k<=j,i-1<=l<=j
    
e[i,j] means the expected search cost of key[i] to key[j]

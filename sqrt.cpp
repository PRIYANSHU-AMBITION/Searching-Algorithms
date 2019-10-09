int Solution::sqrt(int A) {
   if(A == 0 or A == 1) return A;
    int l = 0, r = A;
    int ans;
    while(l <= r){
        int m = (l + r) / 2;
        if(m*m <= A){
            l = m + 1;
            ans = m;
        }else{
            r = m - 1;
        }
    }
    return ans;
}


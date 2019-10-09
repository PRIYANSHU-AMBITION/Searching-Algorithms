int search2(const vector<int> &A, int l, int h, int key)
{
    if (l > h) return -1;
    int mid = (l+h)/2;
    if (A[mid] == key) return mid;
    /* If arr[l...mid] is sorted */
    if (A[l] <= A[mid]) {
        /* As this subarray is sorted, we can quickly
           check if key lies in half or other half */
        if (key >= A[l] && key <= A[mid])
           return search2(A, l, mid-1, key);
 
        return search2(A, mid+1, h, key);
    }
    /* If arr[l..mid] is not sorted, then arr[mid... r]
       must be sorted*/
    if (key >= A[mid] && key <= A[h])
        return search2(A, mid+1, h, key);
 
    return search2(A, l, mid-1, key);
}
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int i = search2(A, 0, n-1, B);
    return i;
}

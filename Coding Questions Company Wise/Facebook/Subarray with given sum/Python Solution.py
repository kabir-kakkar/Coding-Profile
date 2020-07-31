def subArraySum (arr, n, sum):
    curr_sum = arr[0]
    start = 0
    
    i = 1
    while i <= n:
        while curr_sum > sum and start < i-1:
            curr_sum = curr_sum - arr[start]
            start += 1
        if curr_sum == sum:
            print ("%d %d"%(start+1, i)) 
            return 1
        if i<n:
            curr_sum += arr[i]
        i+=1
    print("-1")
    return 0

if __name__ == "__main__":
    t=int(input())
    
    for i in range(t):
        ns=list(map(int,input().split(" ")))
        n=ns[0]
        s=ns[1]
        arr=[]
        arr=[int(item) for item in input().split()]
        subArraySum (arr, n, s)
    

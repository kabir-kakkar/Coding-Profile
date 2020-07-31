
def is_k_palin(string, k):
    r = string[::-1]
    
    m = len(string)
    n = m
    
    T = [[0] * (n + 1) for _ in range(m + 1)] 
    
    for i in range (m+1):
        
        for j in range (n+1):
            
            if not i : 
                T[i][j] = j 
                
            elif not j : 
                T[i][j] = i 
                
            elif (string[i - 1] == r[j - 1]):
                
                T[i][j] = T[i-1][j-1]
                
            else:
                
                T[i][j] = 1 + min(T[i-1][j], T[i][j-1])
    
    print (T[m][n])
    return (T[m][n] <= k * 2)

 
if __name__=='__main__':
    t = int(input())
    for i in range(t):
        arr = input().strip().split()
        string = arr[0]
        n = int(arr[1])
        print(is_k_palin(string, n))
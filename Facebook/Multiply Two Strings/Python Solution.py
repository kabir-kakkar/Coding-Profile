#User function Template for python3

def multiply(str1, str2):
    return str(int(str1)*int(str2))



#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(multiply( a.strip() , b.strip() ))

# } Driver Code Ends
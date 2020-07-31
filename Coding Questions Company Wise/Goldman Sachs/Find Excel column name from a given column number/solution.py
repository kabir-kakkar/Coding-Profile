def printString(n): 
  
    string = ["\0"] * 50
  
    i = 0
  
    while n > 0: 
        # Find remainder 
        rem = n % 26
  
        if rem == 0: 
            string[i] = 'Z'
            n = (n // 26) - 1
        else: 
            string[i] = chr((rem - 1) + ord('A')) 
            n = n // 26
        i += 1
       
    # Declaring the end of string with '/0'    
    string[i] = '\0'
  
    # Reverse the string and print result 
    string = string[::-1] 
    print ("".join(string))

# MAIN
t = int (input())
while (t > 0):
    n = int(input())
    printString(n)
    t = t-1
    
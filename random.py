# Python3 program to distinct
# permutations of the string
 
# Returns true if str[curr] does not
# matches with any of the characters
# after str[start]
def shouldSwap(string, start, curr):
 
    for i in range(start, curr):
        if string[i] == string[curr]:
            return 0
    return 1
 
# Prints all distinct permutations
# in str[0..n-1]
def findPermutations(string, index, n):
 
    if index >= n:
        print(''.join(string))
        return
 
    for i in range(index, n):
 
        # Proceed further for str[i] only
        # if it doesn't match with any of
        # the characters after str[index]
        check = shouldSwap(string, index, i)
        if check:
            string[index], string[i] = string[i], string[index]
            findPermutations(string, index + 1, n)
            string[index], string[i] = string[i], string[index]
 
# Driver code
if __name__ == "__main__":
 
    string = list("ABCA")
    n = len(string)
    findPermutations(string, 0, n)
     

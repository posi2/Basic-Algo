def subsequence( sub, index, array):
    '''Find all possible subset of the array'''
    if index >= len(array): 
        # This is the base case
        result.append(sub) #store subset in the final array
        return
    print("this is height", index, sub)
    
    subsequence( sub, index + 1, array) #exclude present value of the index
    subsequence( sub + [array[index]], index + 1, array) #include present value of the index
    return
# time complexity : O(2**n)
#Note : here for every recursive call we have use + (extend) to add element not append because append update in the same list whereas extend create new list which is required at every recursive level
array = [1,2,3]
result = []
subsequence([], 0, array)
print(result)

# python comments are done using hash 

def getMinimumOperations(arr):
    operations = 0

    while not isSorted(arr):
        max_element, max_index = findMaxUnsorted(arr)
        x, y = findXandY(arr, max_element)
        arr[max_index] = x
        arr.append(y)
        operations += 1

    return operations

def isSorted(arr):
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

def findMaxUnsorted(arr):
    max_element = -1
    max_index = -1
    for i in range(len(arr)):
        if arr[i] > max_element:
            max_element = arr[i]
            max_index = i
    return max_element, max_index

def findXandY(arr, target):
    for i in range(len(arr)):
        for j in range(i + 1, len(arr)):
            if arr[i] + arr[j] == target:
                return arr[i], arr[j]

# Example usage:
arr = [13, 4, 3]
result = getMinimumOperations(arr)
print(result)  # Output should be 2

""" Defination of Peak : Element >= neighbouring elements
    We check the neighborhood iin a similar way like we used to do while calculating maxima in 11th 12th 
    Let the array be : A = [1|3|5|6|8|3|2] As we can see A[3] = 6 , A[4] = 8, A[5] = 3 
    Thus 8 >= 3 and 8 >= 6 implies A[4] is a peak.
"""


# Naive Algorithm (Simply traversing the array)

def peakFinder(x):
    peaks = {}
    if x[0] >= x[1]:
        peaks[0] = x[0]

    if x[-1] >= x[-2]:
        peaks[len(x) - 1] = x[-1]


    for i in range(1, len(x) - 1):
        if x[i] >= x[i - 1] and x[i] >= x[i + 1]:
             peaks[i] = x[i]

    return peaks

nums = [3, 1, 4, 2, 5]
peaks = peakFinder(nums)
print(peaks)

""" Time Complexity Analysis : One Traversal is required, thus time complexity is O(n)
"""

# Efficient Approach : Divide and Conquer 

""" Algorithm :
a = [|1|2|......|n/2 - 1|n/2|n/2 + 1|......|n-1|n|]
Step 1 : if a[n/2] < a[n/2 - 1] then look at left side i.e [1, n/2 -1]
Step 2 : Else if a[n/2] < a[n/2 + 1] then look at right side i.e [n/2 + 1, n]
Step 3 : Else a[n/2] is the peak
Time Complexity : T(n) = T(n/2) + O(1) = O(1)+.......+O(1) {log n times (base 2)} = O(log 2)
"""

def peak1D(x):

    l = 0
    h = len(x) - 1
    mid = (l + h) // 2
   
    if (len(x) >= 2 and x[mid] < x[mid +1]):
        return peak1D(x[mid+1:])

    elif(len(x) >= 2 and x[mid] < x[mid - 1]):
        return peak1D(x[:mid])

    else:
        return mid                        # Write x[mid] if you want the value or else write mid to use peak1D() for peak2D()


def peak2D(x):
    r, c = x.shape
    mid_c = c // 2

    max_index = peak1D(x[:, mid_c])

    if(c >= 2 and x[max_index][mid_c] < x[max_index][mid_c + 1]):
        return peak2D(x[:, mid_c + 1:])

    elif (c >= 2 and x[max_index][mid_c] < x[max_index][mid_c - 1]):
        return peak2D(x[:, :mid_c])

    else:
        return x[max_index, mid_c]


import numpy as np

a = np.array([[0, 11, 20], [3, 6, 10]])
print(peak2D(a))

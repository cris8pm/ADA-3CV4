#Perez Marcelo Cristopher - 3CV4
# Python3 code to demonstrate Divide and
# Conquer Algorithm

# Function to find the maximum no.
# in a given array.
import time
import random
inicio = time.time()

def DAC_Max(a, index, l):
	max = -1
	if(l - 1 == 0):
		return arr[index]
	if (index >= l - 2):
		if (a[index] > a[index + 1]):
			return a[index]
		else:
			return a[index + 1]

	# Logic to find the Maximum element
	# in the given array.
	max = DAC_Max(a, index + 1, l)

	if (a[index] > max):
		return a[index]
	else:
		return max

# Function to find the minimum no.
# in a given array.


def DAC_Min(a, index, l):
	min = 0
	if(l - 1 == 0):
		return arr[index]
	if (index >= l - 2):
		if (a[index] < a[index + 1]):
			return a[index]
		else:
			return a[index + 1]

	# Logic to find the Minimum element
	# in the given array.
	min = DAC_Min(a, index + 1, l)

	if (a[index] < min):
		return a[index]
	else:
		return min


# Driver Code
if __name__ == '__main__':

	# Defining the variables
	min, max = 0, -1

	# Initializing the array
	array=[]
	
	for _ in range(100):
	    rand_num = random.randint(0,10000)
	    array.append(rand_num)

	# Recursion - DAC_Max function called
	max = DAC_Max(array, 0, 100)

	# Recursion - DAC_Max function called
	min = DAC_Min(array, 0, 100)
	print("The minimum number in a given array is : ", min)
	print("The maximum number in a given array is : ", max)
	
fin = time.time()
print("The elapsed time is: ", fin-inicio)
    
    

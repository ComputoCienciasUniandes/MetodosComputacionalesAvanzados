# Compute the number of seconds since the day you were born

n = (36*12 + 10) * 30 * 24 * 3600
print(n)

# Compute the value for the golden ratio number $(1+\sqrt{5})/2$

import math
n = (1+math.sqrt(5))/2
print(n)

#Define a list with the integers from 1 to 10 and use slicing print the second half of the list.

a = [1,2,3,4,5,6,7,8,9,10]
print(a[5:])

#Build a list with 100 repetitions of the sequence 1, -1 (i.e. [1,-1,1,-1,1,-1,...])

a = [1,-1]
a = 100*a
print(a)

#Build a list that contains a 1 surrounded by 15 zeroes on the left and the right.
a = 15*[0] + [1] + 15*[0]
print(a)

#Compute the median of the following list
a = [21, 48, 79, 60, 77,  15, 43, 90,  5,  49, 
    15, 52, 20, 70, 55,  
    4, 86, 49, 87, 59]

a.sort()
n = len(a)
print(a[n//2])

# Create a dictionary with the integers 0 to 4 as keys and the vowels (a, e, i, o u) as values.

a = {0:'a', 1:'e', 2:'i', 3:'o', 4:'u'}
print(a)


# Use the following dictionary of dictionaries to create a new dictionary that has the same keys and the values correspond to the total number of hours used in all activities.

activities = {
    'Monday': {'study':4, 'sleep':8, 'party':0},
    'Tuesday': {'study':8, 'sleep':4, 'party':0},
    'Wednesday': {'study':8, 'sleep':4, 'party':0},
    'Thursday': {'study':4, 'sleep':4, 'party':4},
    'Friday': {'study':1, 'sleep':4, 'party':8},
}

new = {}

for k in activities.keys():
    suma = 0
    for l in activities[k].keys():
        suma = suma + activities[k][l]
    new[k] = suma
print(new)

# Write a for cycle that prints the sequence: 5, 4, 3, 2, 1, 0.

for i in range(5,-1,-1):
    print(i)

# Use random.random() and a for cycle to compute the sum of 100 random numbers.

import random
suma = 0
for i in range(100):
    suma += random.random()

print(suma)

# Use the results from the previous exercise to compute the standard deviation of a list of 1000 numbers where each number is itself the sum of N=100 random numbers. What is the answer if N=200? N=300?

n_in_list = 1000
N = 300
lista = []

for i in range(n_in_list):
    suma = 0
    for i in range(N):
        suma += random.random()
    lista.append(suma)

suma = 0
for i in range(n_in_list):
    suma += lista[i]

promedio = suma/len(lista)

suma = 0
for i in range(n_in_list):
    suma += (lista[i] - promedio)**2

stddev = math.sqrt(suma/(len(lista) - 1))

print(N, promedio, stddev, math.sqrt(N/12)) # See https://en.wikipedia.org/wiki/Irwin-Hall_distribution


#Compute how many times, on average, do you have to throw a die (with only six faces) in order to reach reach a minimum of 100 points. In this game you start with 0 points, you throw the die and add the number you get to the total account. Use the results of random.random() to implement the die throw.

n_games = 10000
n_try = []
for i in range(n_games):
    n = 0
    points = 0
    while(points < 100):
        i = (random.random()*6)//1 + 1
        points += i
        n += 1
    n_try.append(n)
    

suma = 0
for i in range(n_games):
    suma += n_try[i]

promedio = suma/len(n_try)
print(promedio)


# Define a function distance that takes as arguments two lists a,b and computes the Euclidean distance between the two:

def distance(a,b):
    n = len(a)
    d = 0.0
    for i in range(n):
        d += (a[i] -b[i])**2
    d = math.sqrt(d)
    return d

print(distance([0,0], [1,1]))
print(distance([1,5], [2,2]))
print(distance([0,1,2], [2,3,4]))

# Redefine the class Circle to include a new method called perimeter that returns the value of the circle's perimeter.

class Circle:
    def __init__(self, radius):
        self.radius = radius #all attributes must be preceded by "self."
    def area(self):
        import math
        return math.pi * self.radius * self.radius
    def perimeter(self):
        import math
        return 2.0  * math.pi * self.radius


#Define the class Vector3D to represent vectors in 3D. The class must have

#Three attributes: x, y, and z, to store the coordinates.

#A method called dot that computes the dot product

class Vector3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def dot(self, v):
        return self.x  * v.x + self.y * v.y + self.z * v.z

v = Vector3D(2, 0, 1)
w = Vector3D(1, -1, 3)
print(v.dot(w))


# Import the module random and use the function shuffle to shuffle the contents of a list that has the integers from 0 to 9. Print the list before and after shuffling. Use random.shuffle? to read the documentation string for that function.

import random

a = list(range(10))
print(a)
random.shuffle(a)
print(a)

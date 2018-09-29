L = list(map(int,input().split(',')))
L.sort()
print("cpaw{", end="")
for l in L:
    print(l, end="")
print("}")
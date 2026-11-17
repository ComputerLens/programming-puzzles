x = float("nan")
y = x + 1
s = set()

s.add(x)
s.add(x)
s.add(y)

print("size           :", len(s))
print("has x          :", x in s)
print("has stored y   :", y in s)
print("has fresh x + 1:", (x + 1) in s)

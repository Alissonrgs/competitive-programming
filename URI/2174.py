n = int(input())

v = {}
for i in range(n):
    v[input()] = True

print("Falta(m)", 151 - len(v), "pomekon(s).")

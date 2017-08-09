n = int(input())

player = {'total': [0, 0, 0], 'successful': [0, 0, 0]}
for i in range(n):
    input()
    total = list(map(int, input().split()))
    successful = list(map(int, input().split()))
    for j in range(3):
        player['total'][j] += total[j]
        player['successful'][j] += successful[j]

saque = 100.0 * player['successful'][0] / player['total'][0]
bloqueio = 100.0 * player['successful'][1] / player['total'][1] 
ataque = 100.0 * player['successful'][2] / player['total'][2]

print("Pontos de Saque: {:.2f} %.".format(saque))
print("Pontos de Bloqueio: {:.2f} %.".format(bloqueio))
print("Pontos de Ataque: {:.2f} %.".format(ataque))

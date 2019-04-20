import random


for i in range(0, 100):
    for number in range(6, 12):
        if bool(random.getrandbits(1)):
            print('{}'.format(number), end='')
        else:
            print('{}'.format(-number), end='')
        if number != 11:
            print(',', end='')
        else:
            print('\n', end='')

def gcd(a, b):
    while b:
        a, b = b, a%b
    return a

t = int(input())
i = 1
while (i<=t):
    a = input()
    N = int(a.split()[0])
    L = int(a.split()[1])
    inp = input()
    j = 0
    cipher = []
    inp_str = inp.split()
    inp_str2 = inp_str.copy()
    inp_str2.reverse()
    dis = []
    index = -1
    leading_same = -1
    number = 0
    while (j < L-1):
        a1 = int(inp_str[j])
        b1 = int(inp_str[j+1])
        c = int(gcd(a1,b1))
        if a1 == b1:
            if j==0:
                leading_same = a1
                cipher.append(-1)
                number+=1
            if a1 != leading_same and j!=0:
                tmp  = int(c/cipher[-1])
                cipher.append(tmp)
                if not (tmp in dis):
                    dis.append(tmp)
            else:
                cipher.append(-1)
                number+=1
            if j == L -2:
                tmp = int(c/cipher[-1])
                cipher.append(tmp)
                if not (tmp in dis):
                    dis.append(tmp)
        else:
            if j == 0:
                cipher.append(int(a1/c))
                if not (int(a1/c) in dis):
                    dis.append(int(a1/c))
            cipher.append(c)
            if not (c in dis):
                dis.append(c)
            if j == L-2:
                cipher.append(int(b1/c))
                if not (int(b1/c) in dis):
                    dis.append(int(b1/c))
        j+=1
    j = 0
    while j < L -1:
        a1 = int(inp_str2[j])
        b1 = int(inp_str2[j+1])
        c = int(gcd(a1,b1))
        if a1 == b1:
            if a1 == leading_same and a1 != -1:
                # 3  2|3 2 3 2
                # 6 6 6 6 15
              #(2)3 2 3 2|3
                # 6 6 6 15
              #(3)2 3 2|3
                #if j-1>=0 and int(inp_str2[j-1])!=a1:
                tmp2 = int(gcd(int(inp_str2[j-1]), int(inp_str2[j]))) # 3
                tmp1 = int(c/tmp2) # 2
                if (tmp2 != tmp1):
                    if not (tmp1 in dis):
                        dis.append(tmp1)
                    if not (tmp2 in dis):
                        dis.append(tmp2)
                    break
        j+=1
    for index,v in enumerate(cipher):
        if v == -1:
            if number % 2 == 0: # even
                cipher[index] = tmp2
            else:
                cipher[index] = tmp1
            number-=1

    dis.sort()
    convert = {}
    j = 0
    while j < len(dis):
        convert[dis[j]] = j
        j+=1
    print_out = []
    # print(convert)
    # print(dis)
    # print(cipher)
    for m in cipher:
        print_out.append(chr(65+convert[int(m)]))
    print('Case #{}: {}'.format(i,''.join(str(m) for m in print_out)))
    i+=1


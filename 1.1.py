'''
1.1

Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?
'''

def has_unique_chars(str):
    return len(set(str)) == len(str)


def has_unique_chars(str):
    for i, a in enumerate(str):
        for j in range(i + 1, len(str)):
            if a == str[j]:
                return False
    
    return True


if __name__ == '__main__':
    print('axab: %s' % has_unique_chars('axab'))
    print('axb: %s' % has_unique_chars('axb'))

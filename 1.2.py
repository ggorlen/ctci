'''
1.2 

Check Permutation: 
Given two strings, write a method to decide if one is a permutation of the other.
'''

from collections import Counter


def is_permutation(s1, s2):
    return Counter(s1) == Counter(s2)


if __name__ == '__main__':
    print('Should be true: %s' % is_permutation('owl', 'low'))
    print('Should be false: %s' % is_permutation('lwl', 'low'))

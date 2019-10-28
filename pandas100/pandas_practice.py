import pandas as pd
import numpy as np

print(pd.__version__)

def create_series():
    # from list
    tmp_list = [1,2,3,4,5]
    s1 = pd.Series(tmp_list)
    print('create a series from list ', s1)

    # from Ndarray
    n = np.random.randn(5)
    index = ['a', 'b', 'c', 'd', 'e']
    s2 = pd.Series(n, index=index)
    print('create a series form Ndarray', s2)

    # from dict
    d = {'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5}
    s3 = pd.Series(d)
    print('create a series from dict/n', s3)

    return s1, s2, s3

def modify(s1, s2):
    print('before ', s1)
    s1.index = ['A', 'B', 'C', 'E', 'F']
    print('after ', s1)
    print('append ----')
    s4 = s1.append(s3)
    print('after append s1: ', s1, 's4: ', s4)



if __name__=='__main__':
    s1, s2, s3 = create_series()
    modify(s1, s3)

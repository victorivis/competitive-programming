"""
https://leetcode.com/problems/combinations/description/?envType=study-plan-v2&envId=top-interview-150
"""

import copy

class Solution(object):
    
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        lista = list(range(1, k+1))
        matriz = [lista]
        print(lista)
        def perm(matriz, lista, limite, pos):
            if pos+1 < len(lista):
                proximo = lista[pos+1]
            else:
                proximo = limite+1

            if lista[pos] < proximo-1:
                lista[pos]+=1
                matriz.append(copy.copy(lista))
                perm(matriz, lista, limite, pos)
                lista[pos]-=1
            
            if pos>0:
                perm(matriz, lista, limite, pos-1)
        perm(matriz, lista, n, k-1)

        return matriz
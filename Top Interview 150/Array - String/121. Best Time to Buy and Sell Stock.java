/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
    public int maxProfit(int[] prices) {
        int tamanho = prices.length;
		
		int[] maior = new int[tamanho];
		int[] menor = new int[tamanho];
		
		menor[0] = prices[0];
		maior[tamanho-1] = prices[tamanho-1]; 
		
		for(int i=1; i<tamanho; i++){
		    menor[i] = Math.min(menor[i-1], prices[i]);
		    maior[tamanho-i-1] = Math.max(menor[tamanho-i-1], prices[tamanho-i-1]);
		}
		
		int diferenca=0;
		for(int i=1; i<tamanho; i++){
		    diferenca = Math.max(maior[i] - menor[i-1], diferenca);
		}

        return diferenca;
    }
}
import java.util.*;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;
        int minVal = Integer.MAX_VALUE;
        Map<Integer, Integer> balance = new TreeMap<>();
        
        // Build balance map and track global minimum
        for (int i = 0; i < n; i++) {
            balance.put(basket1[i], balance.getOrDefault(basket1[i], 0) + 1);
            balance.put(basket2[i], balance.getOrDefault(basket2[i], 0) - 1);
            minVal = Math.min(minVal, Math.min(basket1[i], basket2[i]));
        }
        
        // Collect all surplus values that need swapping
        List<Integer> transfers = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : balance.entrySet()) {
            int val = e.getKey(), bal = e.getValue();
            if ((bal & 1) != 0) {
                return -1;  // impossible to balance
            }
            for (int k = 0; k < Math.abs(bal) / 2; k++) {
                transfers.add(val);
            }
        }
        
        // Sort so we can pair smallest surpluses first
        Collections.sort(transfers);
        
        long cost = 0;
        int m = transfers.size();
        // Only need half of them, pairing smallest with itself or via global min swap
        for (int i = 0; i < m / 2; i++) {
            cost += Math.min(transfers.get(i), 2 * minVal);
        }
        
        return cost;
    }
}

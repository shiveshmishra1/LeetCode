import java.util.HashSet;
import java.util.Set;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> allPossibleOr     = new HashSet<>();
        Set<Integer> orEndingAtPrev    = new HashSet<>();
        Set<Integer> orEndingHere      = new HashSet<>();

        for (int a : arr) {
            // reuse the orEndingHere set
            orEndingHere.clear();
            // start new subarray at 'a'
            orEndingHere.add(a);
            // extend all previous ORs by 'a'
            for (int prev : orEndingAtPrev) {
                orEndingHere.add(prev | a);
            }
            // merge into global set
            allPossibleOr.addAll(orEndingHere);
            // prepare for next iteration by copying current into prev
            orEndingAtPrev.clear();
            orEndingAtPrev.addAll(orEndingHere);
        }

        return allPossibleOr.size();
    }
}

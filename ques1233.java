import java.util.*;

class Solution {
    class TrieNode {
        boolean wordEnd = false;
        Map<String, TrieNode> child = new HashMap<>();
    }

    // Insert folder into the Trie
    private void trieInsert(String folder, TrieNode curr) {
        int i = 1;
        while (i < folder.length()) {
            StringBuilder name = new StringBuilder();
            while (i < folder.length() && folder.charAt(i) != '/') { // Extract folder name
                name.append(folder.charAt(i));
                i++;
            }

            if (curr.wordEnd) return; // Stop if a parent folder already exists

            String nameStr = name.toString();
            if (!curr.child.containsKey(nameStr)) // Create a new node if the path doesn't exist
                curr.child.put(nameStr, new TrieNode());
            
            curr = curr.child.get(nameStr);
            i++;
        }
        curr.wordEnd = true;
    }

    // Traverse the Trie to collect results
    private void searchTrie(TrieNode curr, List<String> res, String path) {
        if (curr == null) return;
        if (curr.wordEnd) {
            res.add(path.substring(0, path.length() - 1)); // Remove trailing '/'
            return;
        }

        for (Map.Entry<String, TrieNode> entry : curr.child.entrySet()) {
            searchTrie(entry.getValue(), res, path + entry.getKey() + "/");
        }
    }

    public List<String> removeSubfolders(String[] folders) {
        TrieNode root = new TrieNode();

        // Insert all folders into the Trie
        for (String folder : folders)
            trieInsert(folder, root);
        
        List<String> res = new ArrayList<>(); // Stores result
        searchTrie(root, res, "/");
        return res;
    }
}

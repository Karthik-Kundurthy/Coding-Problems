class Trie:
    class Node:
        def __init__(self, x):
            self.val = x
            # each lowercase alphabet letter, with last node not being None signalling that it is inserted word
            self.children = [None] * 27

    def __init__(self):
        # empty root
        self.root = self.Node("")
        
        
        # mapping of letters to indices
        self.lookup = {}
        alphabet = list("abcdefghijklmnopqrstuvwxyz")
        for i in range(26):
            self.lookup[alphabet[i]] = i
        

    def insert(self, word: str) -> None:
        
        curr = self.root
        # print("curr", curr)
        letters = list(word)
        # print("letters", letters)
        
        for letter in letters:
            # lookup
            idx = self.lookup[letter]
            if curr.children[idx] is None:
                node = self.Node(curr.val + letter)
                # print(node.val)
                curr.children[idx] = node
                curr = node
            else:
                curr = curr.children[idx]
        
        # print(self.root.children)
        
        # signal insertion
        # print(curr.val)
        curr.children[26] = self.Node(curr.val)
        # print(curr.children[25], curr.children[26].val)
        
        

    def search(self, word: str) -> bool:
        curr = self.root
        # print("curr", curr)
        letters = list(word)
        
        # check that prefix exists
        for letter in letters:
            # lookup
            idx = self.lookup[letter]
            if curr.children[idx] is None:
                return False
            else:
                curr = curr.children[idx]
        
        # print(curr.val)
        if curr.children[26] is None:
            return False
        return curr.children[26].val == curr.val
        

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        # print("curr", curr)
        letters = list(prefix)
        
        # check that prefix exists
        for letter in letters:
            # lookup
            idx = self.lookup[letter]
            if curr.children[idx] is None:
                return False
            else:
                curr = curr.children[idx]
        
        return True
        

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
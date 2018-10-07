-- Tree DS
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show)

-- Pre-order traversal
preorder :: Tree a -> [a]
preorder Empty = []
preorder (Node a l r) = [a] ++ (preorder l) ++ (preorder r)

-- In-order traversal
inorder :: Tree a -> [a]
inorder Empty = []
inorder (Node a l r) = (inorder l) ++ [a] ++ (inorder r)

-- Post-order traversal
postorder :: Tree a -> [a]
postorder Empty = []
postorder (Node a l r) = (postorder l) ++ (postorder r) ++ [a]

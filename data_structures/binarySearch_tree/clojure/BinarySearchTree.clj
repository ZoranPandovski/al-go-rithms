(ns Algorithms.BinarySearchTree)

(defrecord BinarySearchTree [val left right path])

(defn populate-parents
  "Return t with the parent field filled in"
  ([tree] (populate-parents tree []))
  ([tree path]
     (cond (leaf? tree) (BinarySearchTree. (:val tree) nil nil path)
           (= (:left tree) nil) (BinarySearchTree. (:val tree)
                                                   nil
                                                   (populate-parents (:right tree) (conj path :right))
                                                   path)
           (= (:right tree) nil) (BinarySearchTree. (:val tree)
                                                    (populate-parents (:left tree) (conj path :left))
                                                    nil
                                                    path)
           :else (BinarySearchTree. (:val tree)
                                    (populate-parents (:left tree) (conj path :left))
                                    (populate-parents (:right tree) (conj path :right))
                                    path))))

(defn walk-tree-inorder [t node-fn]
  "Visit each node of the tree in order, calling node-fn on each"
  (when t
    (do (walk-tree-inorder (:left t) node-fn)
        (node-fn t)
        (walk-tree-inorder (:right t) node-fn))))

(defn walk-tree-preorder [t node-fn]
    "Visit each node of the tree in preorder, calling node-fn on each"
  (when t
    (do (node-fn t)
        (walk-tree-preorder (:left t) node-fn)
        (walk-tree-preorder (:right t) node-fn))))

(defn walk-tree-postorder [t node-fn]
      "Visit each node of the tree in postorder, calling node-fn on each"
  (when t
    (do (walk-tree-postorder (:left t) node-fn)
        (walk-tree-postorder (:right t) node-fn)
        (node-fn t))))

(defn print-tree [t walk-fn]
  "Print each value in the tree, with the order determined by walk-fn"
  (walk-fn t #(println (:val %))))

(defn search [t val]
  "Return the node that contains val"
  (if (or (= t nil) (= (:val t) val))
    (loop [tree t]
      (let [branch (if (< (:val tree) val)
                     (:left tree)
                     (:right tree))]
        (recur branch)))))

(defn minimum [t]
  "Return the node contailing the smallest value"
  (if (= (:left t) nil)
    t
    (recur (:left t))))

(defn maximum [t]
  "Return the node contailing the largest value"
  (if (= (:right t) nil)
    t
    (recur (:right t))))

(defn leaf? [t]
  "True if t is a leaf node, false otherwise"
  (and (= (:left t) nil)
       (= (:right t) nil)))

(defn successor [t]
  (minimum (:right t)))

(defn follow-directions
  "Return the node from tree arrived at by following the directions in path"
  ([tree path] (if (not (seq path))
                 nil
                 (follow-directions tree (rest path) ((first path) tree))))
  ([tree path acc] (if (not (seq path))
                     acc
                     (follow-directions tree (rest path) ((first path) tree)))))
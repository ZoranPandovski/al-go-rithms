# AVL-Tree
이진 탐색 트리가 한 쪽으로 쏠려 있다면, 최악의 경우 원하는 자료를 찾기 위해 루트 노드부터 리프 노드까지 모두 탐색을 해야 한다. 이러한 단점을 보완하기 위해 AVL 트리가 고안되었다. AVL 트리는 이진 탐색 트리이면서, 동시에 균형을 유지하고 있다. 즉, 모든 노드의 왼쪽, 오른쪽 서브 트리의 높이 차이가 1 이하이다. 

![그림2](https://user-images.githubusercontent.com/63658525/99893569-7c90ab00-2cc4-11eb-9278-81f562a8690c.png)

위 사진은 AVL 트리의 예시이다. 트리에 적혀 있는 숫자들은 balance factor이다. Balance factor는 
hL-hR로 정의되며, hL은 왼쪽 서브 트리의 높이, hR은 오른쪽 서브 트리의 높이이다. 주어진 트리가 AVL 트리인지는, balance factor를 통해 확인할 수 있다. 만약 balance factor가 -1, 0 또는 1이라면, 이 트리는 AVL 트리이다. 

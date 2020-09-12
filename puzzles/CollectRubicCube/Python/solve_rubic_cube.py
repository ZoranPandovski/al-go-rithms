import numpy as np

lst = open('RubikData.txt','r').read().split('\n')
Front = lst[0:3]
Left = lst[4:7]
Right = lst[8:11]
Up = lst[12:15]
Down = lst[16:19]
Back = lst[20:23]
Rubik = [Front, Left, Right, Up, Down, Back]
for i in Rubik:
    for j in range(len(i)):
        i[j] = list(i[j])
Front = np.array(Front)
Left = np.array(Left)
Right = np.array(Right)
Up = np.array(Up)
Down = np.array(Down)
Back = np.array(Back)

def turn_front_cl(Front, Left, Right, Up, Down, Back):
    first = Up[2]
    second = Right[:,0]
    second = np.flip(second, 0)
    third = Down[0]
    forth = Left[:,2]
    forth = np.flip(forth, 0)
    Up = np.delete(Up, 2, 0)
    Up = np.insert(Up, 2, forth, 0)
    Right = np.delete(Right, 0, 1)
    Right = np.insert(Right, 0, first, 1)
    Down = np.delete(Down, 0, 0)
    Down = np.insert(Down, 0, second, 0)
    Left = np.delete(Left, 2, 1)
    Left = np.insert(Left, 2, third, 1)

    main1, main2, main3 = Front[:,0], Front[:,1], Front[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Front = []
    Front.append(main1)
    Front.append(main2)
    Front.append(main3)
    Front = np.array(Front)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_front_cl(Front, Left, Right, Up, Down, Back)

def turn_front_ant(Front, Left, Right, Up, Down, Back):
    first = Up[2]
    first = np.flip(first, 0)
    second = Right[:,0]
    third = Down[0]
    third = np.flip(third, 0)
    forth = Left[:,2]
    Up = np.delete(Up, 2, 0)
    Up = np.insert(Up, 2, second, 0)
    Right = np.delete(Right, 0, 1)
    Right = np.insert(Right, 0, third, 1)
    Down = np.delete(Down, 0, 0)
    Down = np.insert(Down, 0, forth, 0)
    Left = np.delete(Left, 2, 1)
    Left = np.insert(Left, 2, first, 1)

    main1, main2, main3 = Front[:,2], Front[:,1], Front[:,0]
    Front = []
    Front.append(main1)
    Front.append(main2)
    Front.append(main3)
    Front = np.array(Front)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_front_ant(Front, Left, Right, Up, Down, Back)

def turn_left_cl(Front, Left, Right, Up, Down, Back):
    first = Up[:,0]
    second = Front[:,0]
    third = Down[:,0]
    third = np.flip(third, 0)
    forth = Back[:,2]
    forth = np.flip(forth, 0)
    Up = np.delete(Up, 0, 1)
    Up = np.insert(Up, 0, forth, 1)
    Front = np.delete(Front, 0, 1)
    Front = np.insert(Front, 0, first, 1)
    Down = np.delete(Down, 0, 1)
    Down = np.insert(Down, 0, second, 1)
    Back = np.delete(Back, 2, 1)
    Back = np.insert(Back, 2, third, 1)

    main1, main2, main3 = Left[:,0], Left[:,1], Left[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Left = []
    Left.append(main1)
    Left.append(main2)
    Left.append(main3)
    Left = np.array(Left)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_left_cl(Front, Left, Right, Up, Down, Back)


def turn_left_ant(Front, Left, Right, Up, Down, Back):
    first = Up[:,0]
    first = np.flip(first, 0)
    second = Front[:,0]
    third = Down[:,0]
    forth = Back[:,2]
    forth = np.flip(forth, 0)
    Up = np.delete(Up, 0, 1)
    Up = np.insert(Up, 0, second, 1)
    Front = np.delete(Front, 0, 1)
    Front = np.insert(Front, 0, third, 1)
    Down = np.delete(Down, 0, 1)
    Down = np.insert(Down, 0, forth, 1)
    Back = np.delete(Back, 2, 1)
    Back = np.insert(Back, 2, first, 1)

    main1, main2, main3 = Left[:,2], Left[:,1], Left[:,0]
    Left = []
    Left.append(main1)
    Left.append(main2)
    Left.append(main3)
    Left = np.array(Left)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_left_ant(Front, Left, Right, Up, Down, Back)

def turn_right_cl(Front, Left, Right, Up, Down, Back):
    first = Up[:,2]
    first = np.flip(first, 0)
    second = Back[:,0]
    second = np.flip(second, 0)
    third = Down[:,2]
    forth = Front[:,2]
    Up = np.delete(Up, 2, 1)
    Up = np.insert(Up, 2, forth, 1)
    Back = np.delete(Back, 0, 1)
    Back = np.insert(Back, 0, first, 1)
    Down = np.delete(Down, 2, 1)
    Down = np.insert(Down, 2, second, 1)
    Front = np.delete(Front, 2, 1)
    Front = np.insert(Front, 2, third, 1)

    main1, main2, main3 = Right[:,0], Right[:,1], Right[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Right = []
    Right.append(main1)
    Right.append(main2)
    Right.append(main3)
    Right = np.array(Right)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_right_cl(Front, Left, Right, Up, Down, Back)

def turn_right_ant(Front, Left, Right, Up, Down, Back):
    first = Up[:,2]
    second = Back[:,0]
    second = np.flip(second, 0)
    third = Down[:,2]
    third = np.flip(third, 0)
    forth = Front[:,2]
    Up = np.delete(Up, 2, 1)
    Up = np.insert(Up, 2, second, 1)
    Back = np.delete(Back, 0, 1)
    Back = np.insert(Back, 0, third, 1)
    Down = np.delete(Down, 2, 1)
    Down = np.insert(Down, 2, forth, 1)
    Front = np.delete(Front, 2, 1)
    Front = np.insert(Front, 2, first, 1)

    main1, main2, main3 = Right[:,2], Right[:,1], Right[:,0]
    Right = []
    Right.append(main1)
    Right.append(main2)
    Right.append(main3)
    Right = np.array(Right)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_right_ant(Front, Left, Right, Up, Down, Back)

def turn_up_cl(Front, Left, Right, Up, Down, Back):
    first = Back[0]
    second = Right[0]
    third = Front[0]
    forth = Left[0]
    Back = np.delete(Back, 0, 0)
    Back = np.insert(Back, 0, forth, 0)
    Right = np.delete(Right, 0, 0)
    Right = np.insert(Right, 0, first, 0)
    Front = np.delete(Front, 0, 0)
    Front = np.insert(Front, 0, second, 0)
    Left = np.delete(Left, 0, 0)
    Left = np.insert(Left, 0, third, 0)

    main1, main2, main3 = Up[:,0], Up[:,1], Up[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Up = []
    Up.append(main1)
    Up.append(main2)
    Up.append(main3)
    Up = np.array(Up)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_up_cl(Front, Left, Right, Up, Down, Back)

def turn_up_ant(Front, Left, Right, Up, Down, Back):
    first = Back[0]
    second = Right[0]
    third = Front[0]
    forth = Left[0]
    Back = np.delete(Back, 0, 0)
    Back = np.insert(Back, 0, second, 0)
    Right = np.delete(Right, 0, 0)
    Right = np.insert(Right, 0, third, 0)
    Front = np.delete(Front, 0, 0)
    Front = np.insert(Front, 0, forth, 0)
    Left = np.delete(Left, 0, 0)
    Left = np.insert(Left, 0, first, 0)

    main1, main2, main3 = Up[:,2], Up[:,1], Up[:,0]
    Up = []
    Up.append(main1)
    Up.append(main2)
    Up.append(main3)
    Up = np.array(Up)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_up_ant(Front, Left, Right, Up, Down, Back)

def turn_down_cl(Front, Left, Right, Up, Down, Back):
    first = Front[2]
    second = Right[2]
    third = Back[2]
    forth = Left[2]
    Front = np.delete(Front, 2, 0)
    Front = np.insert(Front, 2, forth, 0)
    Right = np.delete(Right, 2, 0)
    Right = np.insert(Right, 2, first, 0)
    Back = np.delete(Back, 2, 0)
    Back = np.insert(Back, 2, second, 0)
    Left = np.delete(Left, 2, 0)
    Left = np.insert(Left, 2, third, 0)

    main1, main2, main3 = Down[:,0], Down[:,1], Down[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Down = []
    Down.append(main1)
    Down.append(main2)
    Down.append(main3)
    Down = np.array(Down)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_down_cl(Front, Left, Right, Up, Down, Back)

def turn_down_ant(Front, Left, Right, Up, Down, Back):
    first = Front[2]
    second = Right[2]
    third = Back[2]
    forth = Left[2]
    Front = np.delete(Front, 2, 0)
    Front = np.insert(Front, 2, second, 0)
    Right = np.delete(Right, 2, 0)
    Right = np.insert(Right, 2, third, 0)
    Back = np.delete(Back, 2, 0)
    Back = np.insert(Back, 2, forth, 0)
    Left = np.delete(Left, 2, 0)
    Left = np.insert(Left, 2, first, 0)

    main1, main2, main3 = Down[:,2], Down[:,1], Down[:,0]
    Down = []
    Down.append(main1)
    Down.append(main2)
    Down.append(main3)
    Down = np.array(Down)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_down_ant(Front, Left, Right, Up, Down, Back)

def turn_back_cl(Front, Left, Right, Up, Down, Back):
    first = Up[0]
    first = np.flip(first, 0)
    second = Left[:,0]
    third = Down[2]
    third = np.flip(third, 0)
    forth = Right[:,2]
    Up = np.delete(Up, 0, 0)
    Up = np.insert(Up, 0, forth, 0)
    Left = np.delete(Left, 0, 1)
    Left = np.insert(Left, 0, first, 1)
    Down = np.delete(Down, 2, 0)
    Down = np.insert(Down, 2, second, 0)
    Right = np.delete(Right, 2, 1)
    Right = np.insert(Right, 2, third, 1)

    main1, main2, main3 = Back[:,0], Back[:,1], Back[:,2]
    main1, main2, main3 = np.flip(main1, 0), np.flip(main2, 0), np.flip(main3, 0)
    Back = []
    Back.append(main1)
    Back.append(main2)
    Back.append(main3)
    Back = np.array(Back)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_back_cl(Front, Left, Right, Up, Down, Back)

def turn_back_ant(Front, Left, Right, Up, Down, Back):
    first = Up[0]
    second = Left[:,0]
    second = np.flip(second, 0)
    third = Down[2]
    forth = Right[:,2]
    forth = np.flip(forth, 0)
    Up = np.delete(Up, 0, 0)
    Up = np.insert(Up, 0, second, 0)
    Left = np.delete(Left, 0, 1)
    Left = np.insert(Left, 0, third, 1)
    Down = np.delete(Down, 2, 0)
    Down = np.insert(Down, 2, forth, 0)
    Right = np.delete(Right, 2, 1)
    Right = np.insert(Right, 2, first, 1)

    main1, main2, main3 = Back[:,2], Back[:,1], Back[:,0]
    Back = []
    Back.append(main1)
    Back.append(main2)
    Back.append(main3)
    Back = np.array(Back)
    return Front, Left, Right, Up, Down, Back

#Front, Left, Right, Up, Down, Back = turn_back_ant(Front, Left, Right, Up, Down, Back)

class Queue:
    def __init__(self):
        self.items = []

    def empty(self):
        return len(self.items) == 0

    def pushBack(self, item):
        self.items.append(item)

    def popFront(self):
        if self.empty():
            raise Exception("Queue: 'popFront' applied to empty container")
        return self.items.pop(0)

    def size(self):
        return len(self.items)

class GraphVertex:
    def __init__(self, vertexId):
        self.Id = vertexId
        self.Neighbors = []

    def getId(self):
        return self.Id

    def addNeighbor(self, Vertex):
        self.Neighbors.append(Vertex)

    def getNeighbors(self):
        return self.Neighbors

class Graph:
    def __init__(self):
        self.Vertices = []

    def addVertex(self, Vertex):
        self.Vertices.append(Vertex)

    def getVertex(self, aVertex):
        assert aVertex in self

        key = aVertex.getId()
        return self.Vertices[key]

    def addEdge(self, fromVert, toVert):
        if fromVert not in self:
            self.addVertex(fromVert)
        if toVert not in self:
            self.addVertex(toVert)
        fromVert.addNeighbor(toVert)
        toVert.addNeighbor(fromVert)

    def __contains__(self, aVertex):
        return aVertex.getId() in self.Vertices

    def __iter__(self):
        return iter(self.Vertices.values())

    def __getitem__(self, vertex):
        return self.getVertex(vertex)

def Done(Rubik):
    blue = np.array([['B', 'B', 'B'], ['B', 'B', 'B'], ['B', 'B', 'B']])
    yellow = np.array([['Y', 'Y', 'Y'], ['Y', 'Y', 'Y'], ['Y', 'Y', 'Y']])
    white = np.array([['W', 'W', 'W'], ['W', 'W', 'W'], ['W', 'W', 'W']])
    red = np.array([['R', 'R', 'R'], ['R', 'R', 'R'], ['R', 'R', 'R']])
    green = np.array([['G', 'G', 'G'], ['G', 'G', 'G'], ['G', 'G', 'G']])
    orange = np.array([['O', 'O', 'O'], ['O', 'O', 'O'], ['O', 'O', 'O']])
    if any((x == blue).all() for x in Rubik) and any((x1 == yellow).all() for x1 in Rubik) and any((x2 == white).all() for x2 in Rubik) and any((x3 == red).all() for x3 in Rubik) and any((x4 == green).all() for x4 in Rubik) and any((x5 == orange).all() for x5 in Rubik):
        return True
    else:
        return False

g = Graph()
Rubik = [Front.tolist(), Left.tolist(), Right.tolist(), Up.tolist(), Down.tolist(), Back.tolist()]
vertex = GraphVertex(Rubik)
g.addVertex(vertex)

def finding_way(Front, Left, Right, Up, Down, Back, g):

    q = Queue()
    q.pushBack((Front, Left, Right, Up, Down, Back))
    BadBank = []
    a = 0
    while not q.empty():
        Tuple = q.popFront()
        Front, Left, Right, Up, Down, Back = Tuple[0], Tuple[1], Tuple[2], Tuple[3], Tuple[4], Tuple[5]
        Rubik = np.array([Front, Left, Right, Up, Down, Back])
        if Done(Rubik):
            break
        copy_Front, copy_Left, copy_Right, copy_Up, copy_Down, copy_Back = Front, Left, Right, Up, Down, Back
        if [copy_Front.tolist(), copy_Left.tolist(), copy_Right.tolist(), copy_Up.tolist(), copy_Down.tolist(), copy_Back.tolist()] not in BadBank:
            BadBank.append([copy_Front.tolist(), copy_Left.tolist(), copy_Right.tolist(), copy_Up.tolist(), copy_Down.tolist(), copy_Back.tolist()])
        else:
            continue
        vertex1 = GraphVertex([copy_Front.tolist(), copy_Left.tolist(), copy_Right.tolist(), copy_Up.tolist(), copy_Down.tolist(), copy_Back.tolist()])

        f11, f12, f13, f14, f15, f16 = turn_front_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((f11, f12, f13, f14, f15, f16))
        vertex2 = GraphVertex([f11.tolist(), f12.tolist(), f13.tolist(), f14.tolist(), f15.tolist(), f16.tolist()])
        g.addEdge(vertex1, vertex2)

        f21, f22, f23, f24, f25, f26 = turn_front_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((f21, f22, f23, f24, f25, f26))
        vertex2 = GraphVertex([f21.tolist(), f22.tolist(), f23.tolist(), f24.tolist(), f25.tolist(), f26.tolist()])
        g.addEdge(vertex1, vertex2)

        l11, l12, l13, l14, l15, l16 = turn_left_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((l11, l12, l13, l14, l15, l16))
        vertex2 = GraphVertex([l11.tolist(), l12.tolist(), l13.tolist(), l14.tolist(), l15.tolist(), l16.tolist()])
        g.addEdge(vertex1, vertex2)

        l21, l22, l23, l24, l25, l26 = turn_left_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((l21, l22, l23, l24, l25, l26))
        vertex2 = GraphVertex([l21.tolist(), l22.tolist(), l23.tolist(), l24.tolist(), l25.tolist(), l26.tolist()])
        g.addEdge(vertex1, vertex2)

        r11, r12, r13, r14, r15, r16 = turn_right_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((r11, r12, r13, r14, r15, r16))
        vertex2 = GraphVertex([r11.tolist(), r12.tolist(), r13.tolist(), r14.tolist(), r15.tolist(), r16.tolist()])
        g.addEdge(vertex1, vertex2)

        r21, r22, r23, r24, r25, r26 = turn_right_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((r21, r22, r23, r24, r25, r26))
        vertex2 = GraphVertex([r21.tolist(), r22.tolist(), r23.tolist(), r24.tolist(), r25.tolist(), r26.tolist()])
        g.addEdge(vertex1, vertex2)

        u11, u12, u13, u14, u15, u16 = turn_up_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((u11, u12, u13, u14, u15, u16))
        vertex2 = GraphVertex([u11.tolist(), u12.tolist(), u13.tolist(), u14.tolist(), u15.tolist(), u16.tolist()])
        g.addEdge(vertex1, vertex2)

        u21, u22, u23, u24, u25, u26 = turn_up_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((u21, u22, u23, u24, u25, u26))
        vertex2 = GraphVertex([u21.tolist(), u22.tolist(), u23.tolist(), u24.tolist(), u25.tolist(), u26.tolist()])
        g.addEdge(vertex1, vertex2)

        d11, d12, d13, d14, d15, d16 = turn_down_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((d11, d12, d13, d14, d15, d16))
        vertex2 = GraphVertex([d11.tolist(), d12.tolist(), d13.tolist(), d14.tolist(), d15.tolist(), d16.tolist()])
        g.addEdge(vertex1, vertex2)

        d21, d22, d23, d24, d25, d26 = turn_down_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((d21, d22, d23, d24, d25, d26))
        vertex2 = GraphVertex([d21.tolist(), d22.tolist(), d23.tolist(), d24.tolist(), d25.tolist(), d26.tolist()])
        g.addEdge(vertex1, vertex2)

        b11, b12, b13, b14, b15, b16 = turn_back_cl(Front, Left, Right, Up, Down, Back)
        q.pushBack((b11, b12, b13, b14, b15, b16))
        vertex2 = GraphVertex([b11.tolist(), b12.tolist(), b13.tolist(), b14.tolist(), b15.tolist(), b16.tolist()])
        g.addEdge(vertex1, vertex2)

        b21, b22, b23, b24, b25, b26 = turn_back_ant(Front, Left, Right, Up, Down, Back)
        q.pushBack((b21, b22, b23, b24, b25, b26))
        vertex2 = GraphVertex([b21.tolist(), b22.tolist(), b23.tolist(), b24.tolist(), b25.tolist(), b26.tolist()])
        g.addEdge(vertex1, vertex2)

        a+=1

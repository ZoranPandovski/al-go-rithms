package pratica06;
public class Pratica06 {
    public static void main(String[] args) throws Exception{
        JGrafo grafo1 = new JGrafo(9);
        grafo1.insereAresta(1, 2, 5); //(A, B, 5) 
        grafo1.insereAresta(1, 8, 10); //(A, H, 10)
        grafo1.insereAresta(1, 4, 10); //(A, D, 10)
        grafo1.insereAresta(1, 5, 5); //(A, E, 5)
        grafo1.insereAresta(1, 7, 10); //(A, G, 10)
        grafo1.insereAresta(2, 8, 5); //(B, H, 8)
        grafo1.insereAresta(2, 0, 10); //(B, K, 10)
        grafo1.insereAresta(2, 6, 5); //(B, F, 5)
        grafo1.insereAresta(3, 4, 5); //(C, D, 5
        grafo1.insereAresta(3, 5, 10); //(C, E, 10)
        grafo1.insereAresta(3, 7, 5); //(C, G, 5)
        grafo1.insereAresta(4, 5, 5); //(D, E, 5)
        grafo1.insereAresta(4, 7, 10); //(D, G, 10)
        grafo1.insereAresta(5, 0, 10); //(E, K, 10)
        grafo1.insereAresta(6, 7, 15); //(F, G, 15)
        grafo1.insereAresta(8, 0, 20); //(H, K, 20)
        

        JGrafo grafo2 = new JGrafo(8);
        grafo2.insereAresta(1, 2, 8);
        grafo2.insereAresta(1, 3, 2);
        grafo2.insereAresta(1, 7, 9);
        grafo2.insereAresta(2, 3, 3);
        grafo2.insereAresta(2, 4, 2);
        grafo2.insereAresta(2, 5, 7);
        grafo2.insereAresta(2, 6, 5);
        grafo2.insereAresta(2, 0, 6);
        grafo2.insereAresta(3, 7, 6);
        grafo2.insereAresta(3, 4, 9);
        grafo2.insereAresta(4, 7, 2);
        grafo2.insereAresta(4, 5, 6);
        grafo2.insereAresta(5, 7, 4);
        grafo2.insereAresta(5, 6, 5);
        grafo2.insereAresta(6, 7, 6);
        grafo2.insereAresta(6, 0, 4);
        grafo2.insereAresta(0, 7, 3);
        
        JAgm arvre1 = new JAgm(grafo1);
        arvre1.obterAgm(1);
        JAgm arvre2 = new JAgm(grafo2);
        arvre2.obterAgm(1);
        System.out.println(arvre1.getPesoTotal());
        System.out.println(arvre2.getPesoTotal());
    }
    
}

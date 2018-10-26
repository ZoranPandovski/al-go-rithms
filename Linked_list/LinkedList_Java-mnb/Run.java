public class Run{

    public static void main(String args[]){

        LinkList mylist = new LinkList();

        mylist.insert(10);
        mylist.insert(20);
        mylist.insert(30);
        mylist.display();

        Node retur = mylist.find(2);
        System.out.println(retur.item);

        mylist.delete(2);
        mylist.display();

        mylist.delete(2);
        mylist.display();
    }
}
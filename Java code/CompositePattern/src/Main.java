public class Main {
    public static void main(String[] args){
        Composite root = new Composite("root");
        root.add(new Leaf("Leaf A"));
        root.add(new Leaf("Leaf B"));
        root.display(0);

        System.out.println("*************************************");

        Composite comp = new Composite("Composite X");
        comp.add(new Leaf("Leaf XA"));
        comp.add(new Leaf("Leaf XB"));
        root.add(comp);
        root.display(1);

        System.out.println("*************************************");

        Composite comp2 = new Composite("Composite XY");
        comp2.add(new Leaf("Leaf XYA"));
        comp2.add(new Leaf("Leaf XYB"));
        comp.add(comp2);
        root.add(new Leaf("Leaf C"));
        root.display(2);

        System.out.println("*************************************");

        Leaf leaf = new Leaf("Leaf D");
        root.add(leaf);
        root.display(3);

        System.out.println("*************************************");

        root.remove(leaf);
        root.display(4);

    }
}

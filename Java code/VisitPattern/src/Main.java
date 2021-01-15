public class Main {
    public static void main(String[] args){
        ObjectStructure o =new ObjectStructure();
        o.attach(new ConcreteElementA());
        o.attach(new ConcreteElementB());

        ConcreteVisitorA va = new ConcreteVisitorA();
        ConcreteVisitorB vb = new ConcreteVisitorB();

        o.accept(va);
        o.accept(vb);
    }
}

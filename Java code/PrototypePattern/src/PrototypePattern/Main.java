package PrototypePattern;

public class Main {
    public static void main(String[] args){
        ConcretePrototypeA p1 = new ConcretePrototypeA("test A");
        ConcretePrototypeA c1 = (ConcretePrototypeA) p1.Clone();

        System.out.println("Cloned: "+ c1.getID());

        ConcretePrototypeB p2 = new ConcretePrototypeB("test B");
        ConcretePrototypeB c2 = (ConcretePrototypeB) p2.Clone();

        System.out.println("Cloned: "+ c2.getID());
    }
}

public abstract class Visitor {
    public void visitConcreteElementA(ConcreteElementA concreteElementA){
        System.out.println(concreteElementA.getClass().toString() + "被" + this.getClass().toString() + "访问");
    }
    public void visitConcreteElementB(ConcreteElementB concreteElementB){
        System.out.println(concreteElementB.getClass().toString() + "被" + this.getClass().toString() + "访问");
    }
}

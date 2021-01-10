public abstract class AbstractClass {
    /*
    * @author wsh-nie
    *
    * 抽象行为放到子类中去实现
    * */
    public abstract void primitiveOperationA();
    public abstract void primitiveOperationB();

    /*
    * 模板方法，给出了逻辑骨架，而逻辑的组成是一些相应的抽象操作，它们都推迟到子类实现
    * */
    public void templateMethod(){
        primitiveOperationA();
        primitiveOperationB();
        System.out.println("");
    }
}

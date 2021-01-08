public class Main {
    public static void main(String[] args){
        ConcreteComponent component = new ConcreteComponent();//实例化具体对象
        ConcreteDecoratorA decoratorA = new ConcreteDecoratorA();//实例化具体装饰对象A
        ConcreteDecoratorB decoratorB = new ConcreteDecoratorB();//实例化具体装饰对象B

        decoratorA.setComponent(component);// decoratorA.component = new ConcreteComponent()
        decoratorB.setComponent(decoratorA);// decoratorB.component = new ConcreteDecoratorA()
        decoratorB.operation();
        /* *
         * 1. decoratorB 先执行super.operation(), 由于通过setComponent方法设置其component为对象decoratorA
         * 即调用decoratorA.operation();
         * 2. decoratorA.operation()同样需要先执行其父类的operation方法，由于通过setComponent方法设置其component
         * 为对象component，即先执行component.operation()，输出“具体对象的操作”;
         * 3. 然后依此执行decoratorA.operation()剩下部分，输出“具体装饰对象A的操作State A”；
         * 4. 然后再执行decoratorB.operation()剩下部分，输出“具体装饰对象B的操作state B”。
         *
         * 即：
         *
         * 首先用ConcreteComponent实例化对象component；
         * 然后用ConcreteDecoratorA的实例化对象decoratorA来包装component；
         * 再用ConcreteDecoratorB的对象decoratorB来包装decoratorA，最终执行decoratorB的operation()
         **/
    }
}

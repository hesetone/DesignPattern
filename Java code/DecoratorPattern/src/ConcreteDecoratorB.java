public class ConcreteDecoratorB extends Decorator{

    /* *
     * @author wsh-nie
     * 具体装饰类B，继承装饰类，重载操作方法
     * */

    @Override
    public void operation(){
        super.operation();
        addBehavior();
        System.out.println("具体装饰对象B的操作");
    }

    // 独有方法，区别于其他具体装饰
    private void addBehavior(){
        System.out.println("ConcreteDecorator Behavior");
    }
}

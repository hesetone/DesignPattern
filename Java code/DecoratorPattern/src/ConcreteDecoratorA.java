public class ConcreteDecoratorA extends Decorator{

    /* *
     * @author wsh-nie
     * 具体装饰类A，继承装饰类，重载操作方法给接口类增加职责
     * 重载操作方法时，先调用父类对象的方法，如果父类已初始化component属性，则先执行父类对象的操作方法。
     * */

    //独有属性，区别于其他装饰
    private String addedState;

    @Override
    public void operation(){
        /*
        * 首先运行原Component的operation方法，再执行本类的功能，相当于对原Component进行了装饰。
        * */
        super.operation();
        addedState = "State A";
        System.out.println("具体装饰对象A的操作" + addedState);
    }
}

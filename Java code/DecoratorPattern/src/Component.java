public abstract class Component {
    /* *
     * @author wsh-nie
     * Abstract class
     * 定义一个对象接口，负责给子类的对象动态地添加职责
     *
     * Decorator 类继承该类，聚合关系
     * ConcreteComponent 类也继承该类
     *
     * 两个类的操作方法不同方式重载
     * */
    public abstract void operation();
}

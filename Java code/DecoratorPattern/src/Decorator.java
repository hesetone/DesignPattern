public class Decorator extends Component {
    /*
    * @author wsh-nie
    * 装饰抽象类，继承Component，从外类来拓展Component类的功能
    * 通过setComponent方法来初始化component对象，然后调用该对象的操作方法
    * */
    protected Component component;

    public void setComponent(Component component){
        /*
        * 初始化component，通过该函数来包装ConcreteComponent对象，可进行多层包装
        * */
        this.component = component;
    }

    @Override
    public void operation(){
        /*
        * override operation，实际执行component.operation();
        * */
        if(component != null){
            component.operation();
        }
    }
}

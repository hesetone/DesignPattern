public class ConcreteComponent extends Component{

    /*
    * @author wsh-nie
    * 定义具体的对象，通过Decorator类来装饰该对象
    * */
    @Override
    public void operation(){
        System.out.println("具体对象的操作");
    }
}

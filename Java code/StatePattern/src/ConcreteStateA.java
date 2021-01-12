public class ConcreteStateA extends State{
    public void Handle(Context context){
        /*
        * @author wsh-nie
        * 当外部事件发生，影响状态变化
        * */
        context.setState(new ConcreteStateB());
    }
}

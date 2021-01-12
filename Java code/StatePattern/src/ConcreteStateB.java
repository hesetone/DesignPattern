public class ConcreteStateB extends State{
    public void Handle(Context context){
        context.setState(new ConcreteStateA());
    }
}

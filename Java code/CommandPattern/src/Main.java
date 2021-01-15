public class Main {
    public static void main(String[] args){
        Command c = new ConcreteCommand(new Receiver());

        Invoker i = new Invoker();

        i.setCommand(c);
        i.executeCommand();
    }
}

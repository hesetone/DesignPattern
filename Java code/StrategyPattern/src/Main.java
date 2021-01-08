public class Main {
    public static void main(String[] args){
        Context context;

        context = new Context(new ConcreteStrategyA());
        context.contextInterFace();

        context = new Context(new ConcreteStrategyB());
        context.contextInterFace();

        context = new Context(new ConcreteStrategyC());
        context.contextInterFace();
    }
}

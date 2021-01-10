public class Main {
    public static void main(String[] args){
        Director director = new Director();
        Builder builder1 = new ConcreteBuilderA();
        Builder builder2 = new ConcreteBuilderB();

        director.construct(builder1);
        Product product1 = builder1.getResult();
        product1.show();

        director.construct(builder2);
        Product product2 = builder2.getResult();
        product2.show();
    }
}
